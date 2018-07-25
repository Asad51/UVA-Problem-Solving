#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	char letters[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', '-', '7', '7', '8', '8', '8', '9', '9', '9', '-'};

	int t, n;
	cin>>t;
	int cs = 0;
	while(t--){
		cin>>n;
		string str, s = "";
		map<string, int>nums;
		map<string, int>::iterator it;
		int k=0;
		for(int i=0; i<n; i++){
			cin>>str;
			for(int j=0; j<str.size(); j++){
				if(str[j]=='-' || str[j]=='Q' || str[j]=='Z')
					continue;
				if(str[j]>='0' && str[j]<='9'){
					s += str[j];
				}
				else{
					int tmp = str[j]-65;
					s += letters[tmp];
				}
				k++;

				if(k==3)
					s += '-';
			}
			nums[s]++;
			s = "";
			k = 0;
		}
		if(cs!=0)
			cout<<"\n";
		int p = 0;
		for(it = nums.begin(); it!=nums.end(); it++){
			if(it->second > 1){
				cout<< it->first <<" "<< it->second <<"\n"; 
				p++;
			}
		}
		if(!p)
			cout<<"No duplicates.\n";
		nums.clear();
		cs++;
	}
	return 0;
}
