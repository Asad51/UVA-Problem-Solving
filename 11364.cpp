#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int mx=-1, mn=100, x;
		while(n--){
			cin>>x;
			mx = max(mx, x);
			mn = min(mn, x);
		}
		cout<<2*(mx-mn)<<"\n";
	}
	return 0;
}