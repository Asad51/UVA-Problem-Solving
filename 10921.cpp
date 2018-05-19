#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s = "22233344455566677778889999";
	string ph;
	while(getline(cin, ph)){
		for(int i=0; i<ph.size(); i++){
			if(ph[i]=='-' || ph[i]=='0' || ph[i] == '1')
				continue;
			else
			{
				int j = ph[i]-65;
				ph[i] = s[j];
			}
		}
		cout<<ph<<"\n";
	}
	return 0;
}
