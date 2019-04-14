#include <iostream>
#include <cstdio>
#include <cstring>
typedef long long int lli;

lli coins[12] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
lli dp[12][30001];
lli amount;
lli min(lli a, lli b)
{
	return (a < b) ? a : b;
}

lli solve(lli i, lli sum)
{
	if (i >= 11)
	{
		if (sum == amount)
			return 1;
		return 0;
	}
	if (dp[i][sum] != -1)
		return dp[i][sum];
	lli rt1 = 0, rt2 = 0;
	if (sum + coins[i] <= amount)
		rt1 = solve(i, sum + coins[i]);
	rt2 = solve(i + 1, sum);
	return dp[i][sum] = rt1 + rt2;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	double a;
	while (scanf("%lf", &a) && a != 0.00)
	{
		memset(dp, -1, sizeof(dp));
		amount = 10 * a * 10;
		printf("%6.2lf%17Ld\n", a, solve(0, 0));
	}
	return 0;
}
