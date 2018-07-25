#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int cs = 1, total;
	while(scanf("%d", &total) && total>=0){
		int problemCreated[12];
		int problemRequired[12];
		for(int i=0; i<12; i++){
			scanf("%d", &problemCreated[i]);
		}
		for(int i=0; i<12; i++){
			scanf("%d", &problemRequired[i]);
		}

		printf("Case %d:\n", cs);
		for(int i=0; i<12; i++){
			if(total>=problemRequired[i]){
				printf("No problem! :D\n");
				total -= problemRequired[i];
			}
			else
				printf("No problem. :(\n");
			total += problemCreated[i];
		}
		cs++;
	}
	return 0;
}
