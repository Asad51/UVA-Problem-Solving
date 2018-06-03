#include <bits/stdc++.h>
using namespace std;

int modulo(string year, int mod){
	int sz = year.size();
	int c = 0, i;
    for(i = 0; i<sz; i++)
    {
        c = ((year[i]-'0') + c * 10) % mod;
    }
    
    return c;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
	string year; 
	int cs=0;
	while(cin>>year){
		bool leap = false, flag = false;
		if(cs!=0)
			printf("\n");

		if((modulo(year, 4)==0 && modulo(year, 100)!=0) || modulo(year, 400)==0){
			leap = true;
			flag = true;
			printf("This is leap year.\n");
		}

		if(modulo(year, 15)==0){
			flag = true;
			printf("This is huluculu festival year.\n");
		}

		if(leap && modulo(year, 55)==0){
			printf("This is bulukulu festival year.\n");
		}
		if(!flag){
			printf("This is an ordinary year.\n");
		}
		cs++;
	}
	return 0;
}
