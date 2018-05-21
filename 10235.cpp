#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
	if(n==2)
		return true;
	if(n%2==0)
		return false;
	for(int i=3; i<=sqrt(n); i += 2){
		if(n%i==0)
			return false;
	}
	return true;
}

int rev(int n){
	int sum = 0;
	while(n){
		sum *= 10;
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	///freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);

	int primes[1000001] = {0};
	for(int i=2; i<=1000000; i++){
		if(isPrime(i))
			primes[i] = 1;
	}

	int n;
	while(scanf("%d", &n) != EOF){
		int p1 = rev(n);
		//cout<<p1<<endl;
		if(primes[n] && n != p1 && primes[p1])
			cout<<n<<" is emirp.\n";
		else if(primes[n])
			cout<<n<<" is prime.\n";
		else
			cout<<n<<" is not prime.\n";
	}
	return 0;
}
