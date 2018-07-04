#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF){
		vector< vector<int> > nums(1000001);
		int a;
		for(int i=0; i<n; i++){
			scanf("%d", &a);
			nums[a].push_back(i+1);
		}
		for(int i=0; i<m; i++){
			int k, v;
			scanf("%d %d", &k, &v);
			if(nums[v].size()>=k)
				printf("%d\n", nums[v][k-1]);
			else
				printf("0\n");
		}
		nums.clear();
	}
	return 0;
}
