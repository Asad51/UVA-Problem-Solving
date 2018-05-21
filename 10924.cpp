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

int main() {
    //freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);

	int primes[2001] = {0};
	for(int i=1; i<=2000; i++){
		if(isPrime(i))
			primes[i] = 1;
	}

	map<char, int>lets;
	for(int i=0; i<26; i++){
		lets.insert(make_pair('a'+i, i+1));
		lets.insert(make_pair('A'+i, i+27));
	}

	char s[25];
	while(scanf("%s", s) != EOF){
		int sum = 0;
		for(int i=0; i<strlen(s); i++){
			sum += lets[s[i]];
		}
		if(isPrime(sum))
			cout<<"It is a prime word.\n";
		else
			cout<<"It is not a prime word.\n";
	}

    return 0;
}