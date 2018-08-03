#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	getchar();
	getchar();
	string s;
	while(t--){
		map<string, int> trees;
		map<string, int>::iterator it;
		double avg;
		int total = 0;
		while(getline(cin, s)){
			if(s.size()==0)
				break;
			trees[s]++;
			total++;
		}
		for(it=trees.begin(); it!=trees.end(); ++it){
			avg = 100.0 * ((double)it->second / (double)total);
			cout<< it->first << " ";
			printf("%.4lf\n", avg);
		}
		if(t)
			printf("\n");
	}
	return 0;
}
