#include <bits/stdc++.h>
using namespace std;

bool isAnagrams(string a, string b){
	if(a.size() != b.size())
		return false;
	for(int i=0; i<a.size(); i++){
		if(a[i]>='A' && a[i]<='Z')
			a[i] = a[i] + 32;
		if(b[i]>='A' && b[i]<='Z')
			b[i] = b[i] + 32;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if(a==b)
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	string s;
	vector<string> words, ans;
	while(getline(cin, s)){
		if(s=="#")
			break;
		int n = s.size();
		string t = "";
		for(int i = 0; i<n; i++){
			if(s[i]==' ' && t != ""){
				words.push_back(t);
				t = "";
				continue;
			}
			if(s[i]!=' ')
				t += s[i];
		}
		if(t != "")
			words.push_back(t);
	}

	int mark[words.size()] = {0};
	for(int i=0; i<words.size(); i++){
		if(mark[i])
			continue;
		bool isAnagram = false;
		for(int j=0; j<words.size(); j++){
			if(i != j && !mark[j] && isAnagrams(words[i], words[j])){
				mark[i] = 1;
				mark[j] = 1;
				isAnagram = true;
			}
		}
		if(!isAnagram)
			ans.push_back(words[i]);
	}
	sort(ans.begin(), ans.end());
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<"\n";
	return 0;
}
