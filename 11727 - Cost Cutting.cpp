#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	for(int i=1; i<=T; i++){
		int nums[3];
		for(int j=0; j<3; j++){
			cin>>nums[j];
		}
		sort(nums, nums + 3);
		cout<<"Case "<<i<<": "<<nums[1]<<endl;
	}
	return 0;
}
