#include <bits/stdc++.h>
using namespace std;

bool isDifferent(int n, int m){
	int a[10] = {0}, i=0;
	while(n){
		a[i++] = n%10;
		n /= 10;
	}
	while(m){
		a[i++] = m%10;
		m /=10;
	}
	sort(a, a+10);
	if(n==1283){
		for(int j=0; j<10; j++){
			cout<<a[j]<<" ";
		}
	}
	for(int j=1; j<10; j++){
		if(a[j]==a[j-1])
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int n, cs = 0;
	while(cin>>n && n){
		int cnt = 0, a=1234;
		if(cs)
			cout<<"\n";
		while(n*a < 98766){
			if(isDifferent(a, a*n)){
				//cout<<n*a<<" / "<<a<<" = "<<n<<"\n";
				printf("%05d / %05d = %d\n", n*a, a, n );
				cnt++;
			}
			a++;
		}
		if(!cnt)
			cout<<"There are no solutions for "<<n<<".\n";
		cs++;
	}

	return 0;
}