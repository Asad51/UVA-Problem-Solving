#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	string s;
	while(n--){
		cin>>s;
		int sz = s.size();
		if(s=="1" || s=="4" || s=="78")
			cout<<"+\n";
		else if(s[sz-2]=='3' && s[sz-1]=='5')
			cout<<"-\n";
		else if(s[0]=='9' && s[sz-1]=='4')
			cout<<"*\n";
		else
			cout<<"?\n";
	}
	return 0;
}
