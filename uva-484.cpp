#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	map<int, int> frequency;
	vector<int>unique;
	while(scanf("%d", &n)!=EOF){
		if(frequency[n]==0)
			unique.push_back(n);
		frequency[n]++;
	}
	for(int i=0; i<unique.size(); i++)
		printf("%d %d\n", unique[i], frequency[unique[i]]);
	return 0;
}
