#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("out.txt", "w", stdout);
	string s;
	map<string, int> value;
	queue<string> str;
	int cnt = 0;
	for(char c='a'; c<='z'; c++)
	{
		string st = string(1, c);
		str.push(st);
		value.insert(make_pair(st, ++cnt));
	}

	while(!str.empty()){
		s = str.front();
		str.pop();

		if(s.size()==5)
			break;
		for(char ch = s[s.size()-1] + 1; ch<='z'; ch++){
			//s += ch;
			value.insert(make_pair(s+ch, ++cnt));
			str.push(s+ch);
		}
	}
	
	while(cin>>s){
		cout<<value[s]<<endl;
	}
	return 0;
}
