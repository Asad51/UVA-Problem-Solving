#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	int m, n;
	cin>>t;
	while(t--){
		cin>>m>>n;
		cout<<(m/3)*(n/3)<<endl;
	}
	return 0;
}