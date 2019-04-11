#include <stdio.h>
#include <math.h>

int st;

int max(int a, int b){
    return (a > b) ? a : b;
}

int isSquare(int n){
    double a = sqrt(n);
    int b = sqrt(n);
    if(a - b == 0.0)
        return 1;
    return 0;
}

void solve(int n, int i, int cnt, int check[]){
    cnt++;
    for(int k = 1; k <= n; k++){
        if(!check[k]){
            check[k] = i;
            st = max(st, i);
            solve(n, i + 1, cnt, check);
            break;
        }
        else if(isSquare(i + check[k])){
            int tmp = check[k];
            st = max(st, i);
            check[k] = i;
            solve(n, i + 1, cnt, check);
            check[k] = tmp;
            break;
        }
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int check[n + 1];
        for(int i = 0; i <= n; i++)
            check[i] = 0;
        st = -1;
        solve(n, 1, 0, check);
        printf("%d\n", st);
    }
    return 0;
}
