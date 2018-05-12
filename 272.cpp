#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	char s;
	string str = "";
	bool isFirst = true;
	while((scanf("%c", &s)) !=EOF ){
		if(s=='"'){
			if(isFirst){
				isFirst = false;
				str += "``";
			}
			else{
				str += "''";
				isFirst = true;
			}
		}
		else{
			str += s;
		}
	}
	cout<<str;
	return 0;
}
