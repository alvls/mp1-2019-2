#include <stdio.h>
#include <math.h>
#include "TaylorFuncs.h"
#include <string.h>

void t_sin(mode1Res *res, long double x, long double accruracy, long long n)
{
	long double referenceResult = sin(x);
	long double result = 0;
	long double delta = 0;
	unsigned long long factorial = 1;
	for (long long i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
			result -= pow(x, 2 * i - 1) / factorial;
		else
			result += pow(x, 2 * i - 1) / factorial;

		delta = fabs(referenceResult - result);

		if ((delta < accruracy) || (2 * i + 1 > 21))
		{
			n = i;
			break;
		}
		factorial *= (2 * i) * (2 * i + 1);
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
	long double result = 0;
	long double results[26];
	long double delta;
	long double deltas[26];
	unsigned long long factorial = 1;
	for (long long i = 1; i <= NMax; i++)
	{
		if (i % 2 == 0)
			result -= pow(x, 2 * i - 1) / factorial;
		else
			result += pow(x, 2 * i - 1) / factorial;
		results[i] = result;
		delta = fabs(referenceResult - result);
		deltas[i] = delta;
		if (2 * i + 1 > 21)
		{
			NMax = i;
			break;
		}
		factorial *= (2 * i) * (2 * i + 1);
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
	unsigned long long factorial = 2;
	for (long long i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
			result -= pow(x, 2 * i - 2) / factorial;
		else
			result += pow(x, 2 * i - 2) / factorial;

		delta = fabs(referenceResult - result);

		if ((delta < accruracy) || (2 * i > 21))
		{
			n = i;
			break;
		}

		factorial *= (2 * i - 1) * (2 * i);
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
	unsigned long long factorial = 2;
	for (long long i = 2; i <= NMax; i++)
	{
		if (i % 2 == 0)
			result -= pow(x, 2 * i - 2) / factorial;
		else
			result += pow(x, 2 * i - 2) / factorial;

		results[i] = result;
		delta = fabs(referenceResult - result);
		deltas[i] = delta;
		factorial *= (2*i - 1) * (2 * i);
		if (2 * i > 21)
		{
			NMax = i;
			break;
		}
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
	unsigned long long factorial = 1;
	for (long long i = 1; i <= n; i++)
	{
		buff *= x / i;

		result += buff;

		delta = fabs(referenceResult - result);

		if (delta < accruracy)
		{
			n = i;
			break;
		}

		factorial *= i;
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
	for (long long i = 1; i <= NMax; i++)
	{
		result += pow(x, i) / factorial;

		results[i+1] = result;
		delta = fabs(referenceResult - result);
		deltas[i+1] = delta;
		factorial *= i+1;
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