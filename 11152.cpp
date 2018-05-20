
#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int a, b, c;
	while(cin>>a>>b>>c){
		double s, r, R;
		double roses, violets, sunflowers;
		s = (a+b+c)/2.0;
		double p = (s-a)*(s-b)*(s-c);
		r = sqrt(p/s);
		roses = PI*r*r;
		violets = sqrt(p*s);
		R = a*b*c/(4.0*violets);
		sunflowers = PI*R*R - violets;
		violets -= roses;
		printf("%.4lf %.4lf %.4lf\n", sunflowers, violets, roses);
	}
	return 0;
}
