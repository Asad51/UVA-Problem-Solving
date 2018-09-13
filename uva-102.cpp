#include <bits/stdc++.h>
using namespace std;

long long int mn = INT_MAX;
string s="";

void check(long long int m, string st){
    if(m<mn){
        mn = m;
        s = st;
    }
}

int main(int argc, char const *argv[])
{
	long long int b1, g1, c1, b2, g2, c2, b3, g3, c3; 

	while(cin>>b1>>g1>>c1>>b2>>g2>>c2>>b3>>g3>>c3){
        check(b2 + b3 + c1 + c3 + g1 + g2, "BCG");
        check(b2 + b3 + g1 + g3 + c1 + c2, "BGC");
        check(c2 + c3 + b1 + b3 + g1 + g2, "CBG");
        check(c2 + c3 + g1 + g3 + b1 + b2, "CGB");
        check(g2 + g3 + b1 + b3 + c1 + c2, "GBC");
        check(g2 + g3 + c1 + c3 + b1 + b2, "GCB");
        cout<<s<<" "<<mn<<"\n";
        s = "";
        mn = INT_MAX;
    }
	return 0;
}
	