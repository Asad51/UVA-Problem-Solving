#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef long double lld;

int main(int argc, char const *argv[]) {
  lli p, a, b, c, d, n;
  lld price, big, small, decline, lg_decline;

  while(cin>>p>>a>>b>>c>>d>>n){
    big = 0;
    lg_decline = 0;
    small = 1000001;
    lld priceList[n];
    for(lli i=1; i<=n; i++){
      priceList[i-1] = p * ( sin ( a * i + b ) + cos( c * i + d ) + 2 );
      //printf("%Lf\n",priceList[i-1] );
      if(priceList[i-1]>big){
        big = priceList[i-1];
      }

      decline = big - priceList[i-1];
      if(decline>lg_decline){
        lg_decline = decline;
      }
    }

    if(lg_decline==0){
      printf("%.2Lf\n", lg_decline );
    }
    else{
      printf("%.6Lf\n", lg_decline );
    }
  }
  return 0;
}
