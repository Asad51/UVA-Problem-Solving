#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		int n, mx = 0;
		cin>>n;
		while(n--){
			int s;
			cin>>s;
			if(mx<s)
				mx = s;
		}
		cout<<"Case "<<i<<": "<<mx<<"\n";
	}
	return 0;
}
