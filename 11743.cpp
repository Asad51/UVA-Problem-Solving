#include <bits/stdc++.h>
using namespace std;

int digitSum(int n){
	int sum = 0;
	while(n){
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	///freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	while(n--){
		int nums[4];
		for(int i=0; i<4; i++)
			cin>>nums[i];
		int doubled = 0;
		for(int i=0; i<4; i++){
			doubled += digitSum((nums[i]/1000)*2);
			doubled += digitSum(((nums[i]/10)%10)*2);
		}

		int undoubled = 0;
		for(int i=0; i<4; i++){
			undoubled += digitSum(nums[i]%10);
			undoubled += digitSum((nums[i]/100)%10);
		}
		int total = doubled + undoubled;
		if(total%10==0)
			cout<<"Valid\n";
		else
			cout<<"Invalid\n";
	}
	return 0;
}
