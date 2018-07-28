#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const* argn[]){
    int n, m;
    while(scanf("%d", &n)!=EOF){
        m = 0;
        for (int i = 0; i < 32; i += 8) m = (m << 8) | ((n >> i) & 0xff);
            printf("%d converts to %d\n", n, m);
        //bitset<32>b1(n), b2(m);
        //cout<<b1<<" "<<b2<<endl;
    }
    return 0;
}
