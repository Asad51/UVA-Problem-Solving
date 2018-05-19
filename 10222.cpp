#include <bits/stdc++.h>
using namespace std;

char toLower(char ch){
	if(ch>='A' && ch<='Z')
		return ch-32;
	return ch;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string s;
	char st[47] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 91, 93, 92,
                     'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 59, 39,
                     'z', 'x', 'c', 'v', 'b', 'n', 'm', 44, 46, 47,
                     '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 45, 61} ;
	while(getline(cin, s)){
     	for(int i=0; i<s.size(); i++){
     		for(int j=0; j<47; j++){
     			if(s[i]==' ')
     				break;
     			char ch = toLower(s[i]);
     			if(ch==st[j])
     				s[i] = st[j-2];
     		}
     	}
     	cout<<s<<"\n";
	}
	return 0;
}
	