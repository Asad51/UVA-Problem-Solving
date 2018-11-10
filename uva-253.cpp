#include <bits/stdc++.h>
using namespace std;

string rotateEastWest(string s){
	string tmp = s;
	tmp[1] = s[2], tmp[2] = s[4], tmp[3] = s[1], tmp[4] = s[3];
	return tmp;
}

string rotateNorthSouth(string s){
	string tmp = s;
	tmp[0] = s[4], tmp[1] = s[0], tmp[4] = s[5], tmp[5] = s[1];
	return tmp;
}

bool isPainted(string s1, string s2, int rotates){
	if(s1 == s2)
		return true;
	if(rotates > 4)
		return false;
	if(isPainted(s1, rotateNorthSouth(s2), rotates + 1))
		return true;
	if(isPainted(s1, rotateEastWest(s2), rotates + 1))
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	string  s;
	while(cin>>s){
		string s1, s2;
		s1 = s.substr(0, 6);
		s2 = s.substr(6);

		if(isPainted(s1, s2, 0))
			cout<<"TRUE\n";
		else
			cout<<"FALSE\n";
	}
	return 0;
}
	