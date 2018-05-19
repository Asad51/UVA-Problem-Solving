#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int h, m;
	while(scanf("%d:%d", &h, &m) == 2) {
		if(h == 0 && m == 0)	
			break;
		double ha = h*30 + m*0.5;
		double ma = m*6;
		double a = abs(ha-ma);
		if(a<0)
			a *= -1;
		if(a>180)
			a = 360-a;
		cout<<setprecision(3)<<fixed<<a<<"\n";
	}
    return 0;
}