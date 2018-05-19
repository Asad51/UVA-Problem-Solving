#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	cout<<"Lumberjacks:\n";
	while(t--){
		bool in = true;
		bool dec = true;
		int p;
		for(int i=0; i<10; i++){
			int n;
			cin>>n;
			if(!i){
				p = n;
				continue;
			}
			if(n<p || !in)
				in = false;
			if(n>p || !dec)
				dec = false;
			p = n;
		}
		if(!in && !dec)
			cout<<"Unordered\n";
		else
			cout<<"Ordered\n";
	}
	return 0;
}
