#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); 
	///freopen("out.txt", "w", stdout);
	string song[16] = {"Happy", "birthday", "to", "you", "Happy", 
					"birthday", "to", "you", "Happy", "birthday", "to", 
					"Rujia", "Happy", "birthday", "to", "you"
				  };
	int n;
	cin>>n;
	string names[n];
	getchar();
	for(int i=0; i<n; i++){
		getline(cin, names[i]);
	}
	int t = ceil(n/16.0);
	for(int i=0, j=0, k = 0; k<16*t; k++){
		cout<<names[j]<<": "<<song[i]<<"\n";
		i++; j++;
		if(j==n)
			j = 0;
		if(i==16)
			i = 0;
	}
	return 0;
}
