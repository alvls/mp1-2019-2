#pragma once
struct mode1Res
{
	long double referenceResult;
	long double result;
	long double delta;
	long long n;
};

struct mode2Res
{
	long double referenceResult;
	long long NMax;
	long double* results[26];
	long double* deltas[26];
};

void t_sin(mode1Res *, long double, long double, long long);
void t_sin(mode2Res *, long double, long long);
void t_cos(mode1Res*, long double, long double, long long);
void t_cos(mode2Res* , long double, long long);
void t_exp(mode1Res*, long double, long double, long long);
void t_exp(mode2Res* , long double, long long);
void t_arctg(mode1Res*, long double, long double, long long);
void t_arctg(mode2Res* , long double, long long);