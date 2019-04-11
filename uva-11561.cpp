#include <iostream>
#include <cstdio>

class Gold{
    int w, h, sx, sy;
    char grid[51][51];
    int check[51][52];
    int cnt, maxCnt;
public:
    Gold(int w, int h){
        this->w = w;
        this->h = h;
        cnt = maxCnt = 0;
    }

    int max(int a, int b){
        return (a > b) ? a: b;
    }

    void getInput(){
        for(int i = 0; i < h; i++){
            gets(grid[i]);
        }
    }

    void solveGrid(int x, int y){
        check[x][y] = 1;
        if(grid[x][y] == 'G'){
            cnt++;
        }
        maxCnt = max(cnt, maxCnt);
        if(grid[x - 1][y] == 'T' || grid[x + 1][y] == 'T' || grid[x][y - 1] == 'T' || grid[x][y + 1] == 'T'){
            return;
        }

        if(x > 0 && grid[x - 1][y] != '#' && !check[x - 1][y] )
            solveGrid(x - 1, y);

        if(x < h - 1 && grid[x + 1][y] != '#' && !check[x + 1][y])
            solveGrid(x + 1, y);

        if(y > 0 && grid[x][y - 1] != '#' && !check[x][y - 1])
            solveGrid(x, y - 1);

        if(y < w - 1 && grid[x][y + 1] != '#' && !check[x][y + 1])
            solveGrid(x, y + 1);
    }

    void reset(){
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                check[i][j] = 0;
            }
        }
        cnt = 0;
    }

    void solve(){
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(grid[i][j] == 'P'){
                    sx = i;
                    sy = j;
                }
            }
        }

        reset();
        solveGrid(sx, sy);

        printf("%d\n", maxCnt);
    }
};

int main() {
    int w, h;
    while(scanf("%d %d", &w, &h) != EOF){
        getchar();
        Gold g(w, h);
        g.getInput();
        g.solve();
    }
    return 0;
}
