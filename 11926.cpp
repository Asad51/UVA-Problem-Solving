#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	lli m, n;
	while(scanf("%Ld %Ld", &n, &m)){
		if(!n && !m)
			break;
		bool isConflict = false;
		bool isActive[1000000] = {false};

		for(lli i=0; i<n; i++){
			lli s, e;
			scanf("%Ld %Ld", &s, &e);
			if(!isConflict){
				for(lli j = s; j<e; j++){
					if(isActive[j]){
						isConflict = true;
						break;
					}
					else
						isActive[j] = true;
				}
			}
		}

		for(lli i=0; i<m; i++){
			lli s, e, d;
			scanf("%Ld %Ld %Ld", &s, &e, &d);
			if(!isConflict){
				while(s<1000000){
					for(lli j=s; j<e && j<1000000; j++){
						if(isActive[j]){
							isConflict = true;
							break;
						}
						isActive[j] = true;
					}
					s += d;
					e += d;
					if(isConflict)
						break;
				}
			}
		}

		if(isConflict)
			printf("CONFLICT\n");
		else
			printf("NO CONFLICT\n");
	}
	return 0;
}
