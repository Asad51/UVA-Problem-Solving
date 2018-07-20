#include<bits/stdc++.h>
using namespace std;

int main(){
    string wDay[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    string DAY, MTH;
    int T,i,cDay, dayCount;
    int mDay;

    cin>>T;
    while(T--){
        cin>>MTH>>DAY;
        cDay = 0;
        mDay = 0;
        dayCount = 0;

        if(MTH=="FEB"){
            mDay = 28;
        }
        else if(MTH=="APR" || MTH=="JUN" || MTH=="SEP" || MTH=="NOV"){
            mDay = 30;
        }
        else{
            mDay = 31;
        }

        for(i=0; i<7; i++){
            if(DAY==wDay[i]){
                cDay = i;
                break;
            }
        }

        for(i=0; i<mDay; i++){
            if(cDay==5 || cDay==6){
                dayCount++;
            }
            cDay++;
            if(cDay==7){
                cDay = 0;
            }
        }

        cout<<dayCount<<endl;
    }

    return 0;
}
