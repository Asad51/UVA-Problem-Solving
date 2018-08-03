#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	map<string, string>dict;
	string s, ew, fw, sw;
	while(getline(cin, s)){
		if(s.size()==0)
			break;
		stringstream ss(s);
		ss >> ew >> fw;
		//cout<<ew<<fw<<endl;
		dict.insert(make_pair(fw, ew));
	}
	while(cin>>sw){
		if(dict[sw]=="")
			cout<<"eh\n";
		else
			cout<<dict[sw]<<"\n";
	}
	return 0;
}
