#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	///freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long double n, p;
    while(scanf("%Lf %Lf", &n, &p) != EOF){
    	printf("%.0Lf\n", pow(p, 1/n) );
    }
	return 0;
}
	