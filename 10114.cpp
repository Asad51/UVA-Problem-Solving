
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int month, numOfDep;
    float payment, amount;
    while(cin>>month>>payment>>amount>>numOfDep && month>=0){
    	float dep[month+1] = {0.0}, carValue = payment + amount;
    	for(int i=0; i<numOfDep; i++){
    		int m;
    		float d;
    		cin>>m>>d;
    		dep[m] = d;
    	}
    	float prev = 0.0;
    	for(int i=0; i<=month; i++){
    		if(dep[i]==0.0)
    			dep[i] = prev;
    		else
    			prev = dep[i];
    	}
    	int ans = 0;
    	float am = amount, pay = amount/(float)month;
    	//cout<<carValue<<endl;
    	for(int i=0; i<=month; i++){
    		if(i!=0)
    			am = am - pay;
    		carValue = carValue - carValue*dep[i];
    		if(am<carValue){
    			ans = i;
    			break;
    		}
    	}
    	if(ans==1)
    		cout<<1<<" month\n";
    	else
    		cout<<ans<<" months\n";
    	//cout<<am<<" "<<carValue<<endl;
    }
    
	return 0;
}