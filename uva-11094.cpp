#include <iostream>
#include <cstdio>
using namespace std;

class Continent{
    int m, n, sx, sy;
    char grid[21][21], ch, c;
    int cnt;
public: 
    Continent(int m, int n){
        this->n = n;
        this->m = m;
    }

    void getInput(){
        for(int i = 0; i < m; i++){
            scanf("%s", grid[i]);
        }
        scanf("%d %d", &sx, &sy);
    }

    void solveGrid(int x, int y){
        grid[x][y] = c;
        cnt++;
        if(!y && grid[x][n - 1] == ch){
            solveGrid(x, n - 1);
        }
        if(y == m - 1 && grid[x][0] == ch)
            solveGrid(x, 0);
        if(x > 0 && grid[x - 1][y] == ch){
            solveGrid(x - 1, y);
        }

        if(x < m - 1 && grid[x + 1][y] == ch){
            solveGrid(x + 1, y);
        }

        if(y > 0 && grid[x][y - 1] == ch){
            solveGrid(x, y - 1);
        }

        if(y < n - 1 && grid[x][y + 1] == ch){
            solveGrid(x, y + 1);
        }
    }

    void solve(){
        int maxContinent = 0;
        ch = grid[sx][sy];
        c = '\0';
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != ch)
                {
                    c = grid[i][j];
                    break;
                }
            }
        }
        if(ch == '\0'){
            printf("%d\n", maxContinent);
            return;
        }
        solveGrid(sx, sy);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == ch)
                {
                    cnt = 0;
                    solveGrid(i, j);
                    maxContinent = max(maxContinent, cnt);
                }
            }
        }
        printf("%d\n", maxContinent);
    }
};

int main() {
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF){
        Continent ct(m, n);
        ct.getInput();
        ct.solve();
    }
    return 0;
}
