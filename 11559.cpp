#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    int N,B,H,W,p,ans,cap;
    while(scanf("%d %d %d %d",&N,&B,&H,&W) != EOF){
        ans = B + 1;
        
        for(int i = 0;i < H;++i){
            scanf("%d",&p);
            cap = 0;
            
            for(int j = 0,x;j < W;++j){
                scanf("%d",&x);
                cap = max(cap,x);
            }
            
            if(cap >= N) ans = min(ans,N * p);
        }
        
        if(ans == B+1) 
            printf("stay home\n");
        else 
            printf("%d\n",ans);
    }
    
    return 0;
}