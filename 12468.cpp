#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b;
	while(cin>>a>>b){
		if(a==-1 && b==-1)
			break;
		if(b>a)
			cout<<min(b-a, 100-b+a)<<"\n";
		else
			cout<<min(a-b, 100-a+b)<<"\n";
	}
	return 0;
}
	