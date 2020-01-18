#include <stdio.h>
#include <math.h>
#include "TaylorFuncs.h"
#include <string.h>

void t_sin(mode1Res *res, long double x, long double accruracy, long long n)
{
	long double referenceResult = sin(x);
	long double result = x;
	long double delta = 0;
	long double buff = x;
	for (long long i = 2; i <= n; i++)
	{

		buff *= (-1) * (x * x) / ((2 * i - 2) * (2 * i - 1));

		result += buff;

		delta = fabs(referenceResult - result);

		if (delta < accruracy)
		{
			n = i;
			break;
		}
	}

	(*res) = {
		referenceResult,
		result,
		delta,
		n
	};
}

void t_sin(mode2Res *res, long double x, long long NMax)
{
	long double referenceResult = sin(x);
	long double result = x;
	long double results[26];
	results[1] = x;
	long double delta;
	long double deltas[26];
	deltas[1] = fabs(x - referenceResult);
	long double buff = x;
	for (long long i = 2; i <= NMax; i++)
	{
		buff *= (-1) * (x * x) / ((2 * i - 2) * (2 * i - 1));

		result += buff;

		results[i] = result;
		delta = fabs(referenceResult - result);
		deltas[i] = delta;
	}

	res->referenceResult = referenceResult;
	res->NMax = NMax;
	memcpy(res->results, results, (NMax + 1) * sizeof(long double));
	memcpy(res->deltas, deltas, (NMax + 1) * sizeof(long double));
}

void t_cos(mode1Res* res, long double x, long double accruracy, long long n)
{
	long double referenceResult = cos(x);
	long double result = 1;
	long double delta = 0;
	long double buff = 1;
	for (long long i = 2; i <= n; i++)
	{
		buff *= (-1) * (x * x) / ((2 * i - 3) * (2 * i - 2));

		result += buff;

		delta = fabs(referenceResult - result);

		if (delta < accruracy)
		{
			n = i;
			break;
		}
	}

	(*res) = {
		referenceResult,
		result,
		delta,
		n
	};
}

void t_cos(mode2Res* res, long double x, long long NMax)
{
	long double referenceResult = cos(x);
	long double result = 1;
	long double results[26];
	results[1] = 1;
	long double delta;
	long double deltas[26];
	deltas[1] = 1 - referenceResult;
	long double buff = 1;
	for (long long i = 2; i <= NMax; i++)
	{
		buff *= (-1) * (x * x) / ((2 * i - 3) * (2 * i - 2));

		result += buff;

		results[i] = result;
		delta = fabs(referenceResult - result);
		deltas[i] = delta;
	}

	res->referenceResult = referenceResult;
	res->NMax = NMax;
	memcpy(res->results, results, (NMax + 1) * sizeof(long double));
	memcpy(res->deltas, deltas, (NMax + 1) * sizeof(long double));
}

void t_exp(mode1Res* res, long double x, long double accruracy, long long n)
{
	double referenceResult = exp(x);
	long double buff = 1;
	long double result = 1;
	long double delta = 0;
	for (long long i = 1; i < n; i++)
	{
		buff *= x / i;

		result += buff;

		delta = fabs(referenceResult - result);

		if (delta < accruracy)
		{
			n = i;
			break;
		}

	}

	(*res) = {
		referenceResult,
		result,
		delta,
		n
	};
}

void t_exp(mode2Res* res, long double x, long long NMax)
{
	long double referenceResult = exp(x);
	long double buff = 1;
	long double result = 1;
	long double results[26];
	long double delta;
	long double deltas[26];
	results[1] = 1;
	deltas[1] = fabs(referenceResult - 1);
	long long factorial = 1;
	for (long long i = 1; i < NMax; i++)
	{
		buff *= x / i;

		result += buff;

		results[i+1] = result;
		delta = fabs(referenceResult - result);
		deltas[i+1] = delta;
	}

	res->referenceResult = referenceResult;
	res->NMax = NMax;
	memcpy(res->results, results, (NMax+1) * sizeof(long double));
	memcpy(res->deltas, deltas, (NMax+1) * sizeof(long double));
}

void t_arctg(mode1Res* res, long double x, long double accruracy, long long n)
{
	long double referenceResult = atan(x);
	long double result = 0;
	long double delta = 0;
	for (long long i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
			result -= pow(x, 2 * i - 1) / (2 * i - 1);
		else
			result += pow(x, 2 * i - 1) / (2 * i - 1);

		delta = fabs(referenceResult - result);

		if (delta < accruracy)
		{
			n = i;
			break;
		}
	}

	(*res) = {
		referenceResult,
		result,
		delta,
		n
	};
}

void t_arctg(mode2Res* res, long double x, long long NMax)
{
	long double referenceResult = sin(x);
	long double result = 0;
	long double results[26];
	long double deltas[26];
	long double delta;
	for (long long i = 1; i <= NMax; i++)
	{
		if (i % 2 == 0)
			result -= pow(x, 2 * i - 1) / (2 * i - 1);
		else
			result += pow(x, 2 * i - 1) / (2 * i - 1);
		results[i] = result;
		delta = fabs(referenceResult - result);
		deltas[i] = delta;
	}

	res->referenceResult = referenceResult;
	res->NMax = NMax;
	memcpy(res->results, results, (NMax + 1) * sizeof(long double));
	memcpy(res->deltas, deltas, (NMax + 1) * sizeof(long double));
}