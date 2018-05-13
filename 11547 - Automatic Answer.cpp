#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long int tmp = (n * 63 + 7492) * 5 - 498;
		cout<<abs((tmp / 10)%10)<<endl;
	}
	return 0;
}