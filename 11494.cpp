#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int x1, x2, y1, y2;
	while(cin>>x1>>y1>>x2>>y2){
		if(!x1 && !y1 && !x2 && !y2)
			break;
		int dr = abs(x1-x2), dc = abs(y1-y2);
		if(!dr && !dc)
			cout<<0<<"\n";
		else if(x1==x2 || y1==y2 || dr==dc)
			cout<<1<<"\n";
		else
			cout<<2<<"\n";
	}
	return 0;
}
