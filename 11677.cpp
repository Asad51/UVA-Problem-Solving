#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int h1, m1, h2, m2;
	while(scanf("%d%d%d%d", &h1, &m1, &h2, &m2)){
		if(!h1 && !h2 && !m1 && !m2)
			break;
		int t1, t2;
		t1 = h1*60 + m1;
		t2 = h2*60 + m2;
		if(t1>t2)
			t2 += 24*60;
		printf("%d\n", t2-t1 );
	}
	return 0;
}
