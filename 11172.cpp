#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, t;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a>b)
			cout<<">\n";
		else if(b>a)
			cout<<"<\n";
		else
			cout<<"=\n";
	}
	return 0;
}