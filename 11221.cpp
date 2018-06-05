#include <bits/stdc++.h>
using namespace std;

bool isMagic(string s, int n){
	string s1 = "", s2="", s3="", s4="";
	if(s.size()==1)
		return true;
	for(int j=0; j<n; j++)
		s1 += s[j];

	for(int j=s.size()-1; j>=s.size()-n; j--)
			s2 += s[j];
	if(s1!=s2)
		return false;

	for(int j=0; j<s.size(); j = j + n)
		s3 += s[j];
	if(s1!=s3)
		return false;

	for(int j=s.size()-1; j>=n-1; j = j-n)
		s4 += s[j];
	if(s1!=s4)
		return false;
	return true;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	//getchar();
	getchar();
	
	for(int i=1; i<=t; i++){
		char line[10002];
		gets(line);
		string s="";
		for(int j=0; j<strlen(line); j++){
			if(line[j]>='a' && line[j]<='z')
				s += line[j];
		}
		int sz = s.size();
		//cout<<sz<<endl;
		if((float)sqrt(sz)-(int)sqrt(sz)!=0.0){
			printf("Case #%d:\nNo magic :(\n", i);
			continue;
		}
		int n = sqrt(sz);
		if(isMagic(s, n)){
			printf("Case #%d:\n%d\n", i, n);
		}
		else
			printf("Case #%d:\nNo magic :(\n", i);
	}
	return 0;
}
