#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int c = 0, x;
	while(scanf("%d", &x) && x >0){
        int times = 0;
        int cur = 1;
        while(cur < x ){
            cur *= 2;
            times += 1;
        }
        printf("Case %d: %d\n", ++c, times);
    }
	return 0;
}
