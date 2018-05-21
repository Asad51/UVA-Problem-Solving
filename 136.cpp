#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

/*bool isUgly(int num){
    while(num % 2 == 0)
        num/=2;
    while(num % 3 == 0)
        num/=3;
    while(num % 5 == 0)
        num/=5;
    return (num == 1) ? true : false;
}
*/
int main()
{
    //freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    vector<lli>ugly;
    lli l2 = 0, l3 = 0, l5 = 0;
    ugly.push_back(1);
    for (int i = 0; i<1499; ++i)
    {
        ugly.push_back(min(min(ugly[l2]*2, ugly[l3]*3), ugly[l5]*5));
        if (ugly[i+1] == ugly[l2]*2) 
           ++l2;

        if (ugly[i+1] == ugly[l3]*3) 
            ++l3;
    
        if (ugly[i+1] == ugly[l5]*5) 
            ++l5;  
    }
    cout<<"The 1500'th ugly number is "<<ugly[1499]<<".\n";
    return 0;
}

