#include <bits/stdc++.h>
using namespace std;

string toUpper(string s){
	for(int i=0; i<s.size(); i++){
		if(s[i]>='a' && s[i]<='z')
			s[i] = s[i] - 32;
	}
	return s;
}

string toLower(string s){
	for(int i=0; i<s.size(); i++){
		if(s[i]>='A' && s[i]<='Z')
			s[i] = s[i] + 32;
	}
	return s;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	set<string> ignore;
	string word, title;
	multimap<string, string> results;
	map<string, string>::iterator it;
	while(cin>>word){
		if(word=="::")
			break;
		ignore.insert(word);
	}
	//getchar();
	getchar();
	while(getline(cin, title)){
		title = toLower(title);
		for(int i=0; i<title.size(); i++){
			if(title[i]==' ')
				continue;
			int j = i;
			string t = "";
			while(j<title.size() && title[j]!=' '){
				t += title[j];
				j++;
			}
			if(!ignore.count(t)){				
				t = toUpper(t);
				string tmp = title;
				tmp.replace(i, t.size(), t);
				results.insert(make_pair(t, tmp));
			}
			i = j;
		}
	}

	for(it = results.begin(); it!=results.end(); ++it)
		cout<< it->second <<"\n";
	
	return 0;
}
