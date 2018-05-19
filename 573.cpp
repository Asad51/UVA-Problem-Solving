#include <bits/stdc++.h>
using namespace std;

int main()
{
    double h,u,d,f;
    while(cin>>h>>u>>d>>f)
    {
    	if(!h)
    		break;
        f = f*u/100;
        double ht = 0.0;
        int days = 0;
        while(true)
        {
            days++;
            if(u>0) 
            	ht += u;
            u -= f;

            if(ht>h) 
            	break;
            ht -= d;

            if(ht<0) 
            	break;
        }
        if(ht<0) 
        	cout<<"failure on day "<<days<<endl;
        else 
        	cout<<"success on day "<<days<<endl;
    }
    return 0;
}
