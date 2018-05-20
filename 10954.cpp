#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int n, m;
	while(cin>>n){
		if(!n)
			break;
		priority_queue<int>q;
		for(int i=0; i<n; i++){
			cin>>m;
			q.push(-m);
		}
		long long sum = 0;
		
		while(q.size()>1){
			int p1 = -q.top();
			q.pop();
			int p2 = -q.top(); 
			q.pop();
			int p3 = p1 + p2;
			sum += p3;
			q.push(-p3);
		}
		cout<<sum<<"\n";
	}
	return 0;
}
	