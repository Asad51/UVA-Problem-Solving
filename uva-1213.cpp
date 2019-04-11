#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long int lli;

int n, k, p = 0;
int primes[200] = {0};
lli solution[1121][15];

int max(int a, int b)
{
	return (a > b) ? a : b;
}

void solve(int primes[])
{
	int dp[p + 1][1121];
	for (int i = 0; i < 1121; i++)
	{
		for (int j = 0; j < 15; j++)
			solution[i][j] = 0;
	}
	solution[0][0] = 1;
	for (int i = 0; i <= p; i++)
	{
		for (int j = 1120; j >= 0; j--)
		{
			if (!i || !j)
			{
				dp[i][j] = 0;
			}
			else if (primes[i - 1] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				if ((primes[i - 1] + dp[i - 1][j - primes[i - 1]]) == j)
				{
					int tmp = j - primes[i - 1];
					for (int k = 0; k < 14; k++)
					{
						if (solution[tmp][k])
							solution[j][k + 1] += solution[tmp][k];
					}
				}
				dp[i][j] = max(dp[i - 1][j], primes[i - 1] + dp[i - 1][j - primes[i - 1]]);
			}
		}
	}
}

bool isPrime(int n)
{
	if (n <= 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	for (int i = 2; i <= 1120; i++)
	{
		if (isPrime(i))
		{
			primes[p++] = i;
		}
	}

	solve(primes);

	while (scanf("%d %d", &n, &k) && n && k)
	{
		printf("%Ld\n", solution[n][k]);
	}
	return 0;
}
