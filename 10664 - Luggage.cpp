#include <bits/stdc++.h>
using namespace std;

class luggage{
    bool isPossible;
    int total;
    int n;
public:
    luggage(int t, int nn){
        isPossible = false;
        total = t;
        n = nn;
    }

    bool checkResult(){
        return isPossible;
    }

    void isEqualBooots(vector<int>& suitcases, int i, int sum){
        if(i>=n || isPossible || 2*sum>total)
            return;
        if(2*sum==total)
        {
            isPossible = true;
            return;
        }

        isEqualBooots(suitcases, i+1, sum+suitcases[i]);
        isEqualBooots(suitcases, i+1, sum);
    }
};

vector<int> split(string s){
    int n = 0, j = 1;
    vector<int>res;
    int sz = s.size();
    for(int i=sz-1; i>=0; i--){
        if(s[i]!=' '){
            int a = j*(s[i] - 48);
            n += a;
            j *= 10;
        }
        if(!i || s[i]==' '){
            res.push_back(n);
            n = 0;
            j = 1;
        }
    }
    return res;
}

int main(int argc, char const *argv[]) {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int m;
    cin>>m;
    string s;
    vector<int>nums;
    getchar();
    while(m--){
        //scanf("%[^\n]s\n", &s );
        getline(cin, s);
        nums = split(s);
        int total = 0;
        for(int i=0; i<nums.size(); i++){
            total += nums[i];
            //cout<<nums[i]<<" ";
        }
        //cout<<endl;
        luggage l(total, nums.size());
        l.isEqualBooots(nums, 0, 0);
        if(l.checkResult())
            cout<<"YES\n";
        else
            cout<<"NO\n";
        nums.clear();
    }
    return 0;
}
