#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		int arr[10] = {0};
		int n;
		cin>>n;
		for(int i=1; i<=n; i++){
			int j = i;
			while(j){
				arr[j%10]++;
				j /= 10;
			}
			//cout<<i<<endl;
		}
		for(int i=0; i<=9; i++){
			if(i!=0)
				cout<<" ";
			cout<<arr[i];
		}
		cout<<"\n";
	}
	return 0;
}
