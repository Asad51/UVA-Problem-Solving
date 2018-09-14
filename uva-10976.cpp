#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int k;
	while(cin>>k){
		int x, y = k;
		double a;
		int cnt = 0;
		vector<pair<int, int> >nums;
		do{
			y++;
			a = (double)(k*y)/(double)(y-k);
			x = a;
			if(a - (int)a == 0.0){
				nums.push_back(make_pair(x, y));
				cnt++;
			}
			//cout<<x<<y<<endl;
		} while(y <= 2*k);
		printf("%d\n", cnt);
		for(int i = 0; i < nums.size(); i++){
			printf("1/%d = 1/%d + 1/%d\n", k, nums[i].first, nums[i].second);
		}
		nums.clear();
	}
	return 0;
}
