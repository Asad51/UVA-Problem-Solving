#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		int n, p;
		cin>>n>>p;
		int h[p];
		for(int i=0; i<p; i++){
			cin>>h[i];
		}
		int days = 0;
		for (int i=1; i<=n; i++){
            if (i%7 == 6 || i%7==0) { 
                i++; 
                continue;
            }
            for (int j=0; j<p; j++){
                if (i%h[j] == 0) {
                    days++;
                    break;
                }
            }
        }
        cout<<days<<endl;
	}
	return 0;
}
