#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int init, c1, c2, c3;
	while(cin>>init>>c1>>c2>>c3){
		if(!init && !c1 && !c2 && !c3)
			break;
		int degree = 360*2;
		if(c1>init)
			degree += 9*(40-c1+init);
		else
			degree += 9*(init-c1);

		degree += 360;
		if(c2>c1)
			degree += 9*(c2-c1);
		else
			degree += 9*(40-c1+c2);

		if(c3>c2)
			degree += 9*(40-c3+c2);
		else
			degree += 9*(c2-c3);

		cout<<degree<<endl;
	}
	return 0;
}