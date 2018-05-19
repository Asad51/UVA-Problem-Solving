#include <bits/stdc++.h>
using namespace std;

long long int sumOfDigits(long long int n){
	long long int sum = 0;
	while(n){
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	long long int n;
	while(cin>>n){
		if(!n)
			break;
		while(n/10){
			n = sumOfDigits(n);
		}
		cout<<n<<endl;
	}
	return 0;
}
