#include <iostream>
#include <cstdio>
using namespace std;

class Square{
    int n;
    int sq[11][11];
public:
    Square(int n){
        this->n = n;
    }

    void getInput(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                scanf("%d", &sq[i][j]);
        }
    }

    void solve(){
        int cnt = 0;
        for(int i = 0; i < n/2; i++){
            if(cnt)
                printf(" ");
            int sum = 0;
            for(int j = i; j < n - i; j++){
                sum += sq[j][i];
                sum += sq[j][n - 1 - i];
            }
            for(int j = i + 1; j < n - i - 1; j++){
                sum += sq[i][j];
                sum += sq[n - 1 - i][j];
            }
            printf("%d", sum);
            cnt++;
        }

        if(n % 2 == 1){
            if(cnt)
                printf(" ");
            printf("%d\n", sq[n/2][n/2]);
        }
        else
            printf("\n");
    }
};

int main() {
    int n, cs = 0;
    while(scanf("%d", &n) && n){
        Square square(n);
        square.getInput();
        printf("Case %d: ", ++cs);
        square.solve();
    }
    return 0;
}