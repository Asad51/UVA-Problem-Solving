#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
	if(n==2)
		return true;
	if(n==1 || n%2==0)
		return false;
	for(int i=3; i<=sqrt(n); i++){
		if(n%i==0)
			return false;
	}
	return true;
}

bool isDigitPrime(int n){
	int d = 0;
	while(n){
		d += n%10;
		n /= 10;
	}
	return isPrime(d);
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	vector<int> primes;
	primes.push_back(2);
	int i;
	for(i=3; i<=1000000; i++){
		if(i%2==0)
			continue;
		if(isPrime(i) && isDigitPrime(i)){
			primes.push_back(i);
		}
	}
	int n;
	scanf("%d", &n);
	while(n--){
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		int c = 0;
		int l = lower_bound(primes.begin(), primes.end(), t1) - primes.begin();
		int u = upper_bound(primes.begin(), primes.end(), t2) - primes.begin();
		printf("%d\n", u-l);
	}
	return 0;
}
