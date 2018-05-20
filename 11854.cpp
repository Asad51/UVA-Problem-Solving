#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int a[3];
	while(cin>>a[0]>>a[1]>>a[2]){
		if(!a[0] && !a[1] && !a[2])
			break;
		sort(a, a + 3);
		if(a[2]*a[2] == (a[0]* a[0] + a[1]*a[1]))
			cout<<"right\n";
		else
			cout<<"wrong\n";
	}
	return 0;
}
 	