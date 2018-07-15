#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n) && n){
		bitset<32> s(n), s1, s2;
		long a = 0, b = 0;
		for(int i=0, j = 0; i<32; i++){
			if(s[i]==1){
				j++;
				if(j%2==1){
					s2[i] = 0; 
					s1[i] = 1;
				}
				else{
					s2[i] = 1;
					s1[i] = 0;
				}
			}
		}
		for(int i=0; i<32; i++){
			a += s1[i]*pow(2, i);
			b += s2[i]*pow(2, i);
		}
		cout<<a<<" "<<b<<"\n";
	}
	return 0;
}
