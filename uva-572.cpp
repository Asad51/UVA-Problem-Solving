#include <iostream>
#include <cstdio>
using namespace std;

class OilDeposit{
    int m, n;
    char oil[101][101];
    int s;
public: 
    OilDeposit(int m, int n){
        this->n = n;
        this->m = m;
        s = 0;
    }

    void getInput(){
        for(int i = 0; i < m; i++){
            scanf("%s", oil[i]);
        }
    }

    void solveGrid(int x, int y){
        if(x > 0 && oil[x - 1][y] == '@'){
            oil[x - 1][y] = '*';
            solveGrid(x - 1, y);
        }

        if(x < m - 1 && oil[x + 1][y] == '@'){
            oil[x + 1][y] = '*';
            solveGrid(x + 1, y);
        }

        if(y > 0 && oil[x][y - 1] == '@'){
            oil[x][y - 1] = '*';
            solveGrid(x, y - 1);
        }

        if(y < n - 1 && oil[x][y + 1] == '@'){
            oil[x][y + 1] = '*';
            solveGrid(x, y + 1);
        }

        if(y > 0 && x > 0 && oil[x - 1][y - 1] == '@'){
            oil[x - 1][y - 1] = '*';
            solveGrid(x - 1, y - 1);
        }

        if(y > 0 && x < m - 1 && oil[x + 1][y - 1] == '@'){
            oil[x + 1][y - 1] = '*';
            solveGrid(x + 1, y - 1);
        }

        if(y < n - 1 && x > 0 && oil[x - 1][y + 1] == '@'){
            oil[x - 1][y + 1] = '*';
            solveGrid(x - 1, y + 1);
        }

        if(y < n - 1 && x < m - 1 && oil[x + 1][y + 1] == '@'){
            oil[x + 1][y + 1] = '*';
            solveGrid(x + 1, y + 1);
        }
    }

    void solve(){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(oil[i][j] == '@')
                {
                    solveGrid(i, j);
                    s++;
                }
            }
        }

        printf("%d\n", s);
    }
};

int main() {
    int m, n;
    while(scanf("%d %d", &m, &n) && m){
        OilDeposit od(m, n);
        od.getInput();
        od.solve();
    }
    return 0;
}