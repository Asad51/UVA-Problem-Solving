#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
	string a, b;
	while(cin>>a>>b){
		int s1 = a.size(), s2 = b.size();
		char s[s1][s1+s2];
		char ans[s1+s2+3];
		for(int i=0; i<s1+s2+3; i++)
			ans[i] = '0';
		for(int i=0; i<s1; i++){
			for(int j=0; j<s1+s2; j++){
				s[i][j] = '0';
			}
		}

		for(int i=0; i<s1; i++){
			int k = s1+s2-1;
			for(int j=0; j<i; j++){
				s[i][k] = '0';
				k--;
			}
			
			int n, sum, carry = 0;
			for(int j=s2-1; j>=0; j--){
				n = carry;
				int t1 = a[s1-(i+1)] - 48;
				int t2 = b[j] - 48;
				n += t1*t2;
				sum = n%10;
				carry = n/10;
				s[i][k--] = sum+48;
				//cout<<s[i][k];
			}

			s[i][k--] = carry+48;
			for(int j=0; j<=k; j++)
				s[i][k--] = '0';
			//cout<<s[i]<<endl;
		}

		int sum, carry = 0, k = s1+s2+2;
		for(int i=s1+s2-1; i>=0; i--){
			sum = carry;
			for(int j=0; j<s1; j++){
				sum += (s[j][i] - 48);
			}
			char ch = (sum%10) + 48;
			carry = sum/10;
			ans[k--] = ch;
		}

		while(carry){
			char ch = (carry%10) + 48;
			carry /= 10;
			ans[k--] = ch;
		}
		k = 0;
		while(ans[k]=='0'){
			k++;
		}
		if(k>s1+s2+2)
		{
			cout<<0<<"\n";
			continue;
		}
		while(k<=s1+s2+2){
			cout<<ans[k];
			k++;
		}

		cout<<endl;
	}
	return 0;
}
