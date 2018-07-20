#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    while(cin>>n){
    	if(!n)
    		break;
    	int x = 0, y = 0;
    	//cout<<cbrt(n)<<endl;
    	for(int i=1; i<=sqrt(n); i++){
    		float tmp = cbrt(n + i*i*i);
    		//cout<<tmp<<" ";
    		if(tmp == int(tmp)){
    			x = tmp;
    			y = i;
    			break;
    		}
    	}
    	if(x && y)
    		cout<<x<<" "<<y<<"\n";
    	else
    		cout<<"No solution\n";
    }
	return 0;
}
	