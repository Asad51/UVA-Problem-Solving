#include <iostream>
#include <cstdio>

char grid[101][101];
int n;

void solveGrid(int x, int y){
    if(x > 0 && (grid[x - 1][y] == '@' || grid[x - 1][y] == 'x')){
        grid[x - 1][y] = '.';
        solveGrid(x - 1, y);
    }

    if(x < n - 1 && (grid[x + 1][y] == '@' || grid[x + 1][y] == 'x')){
        grid[x + 1][y] = '.';
        solveGrid(x + 1, y);
    }

    if(y > 0 && (grid[x][y - 1] == '@' || grid[x][y - 1] == 'x')){
        grid[x][y - 1] = '.';
        solveGrid(x, y - 1);
    }

    if(y < n - 1 && (grid[x][y + 1] == '@' || grid[x][y + 1] == 'x')){
        grid[x][y + 1] = '.';
        solveGrid(x, y + 1);
    }

    if(y > 0 && x > 0 && (grid[x - 1][y - 1] == '@' || grid[x - 1][y - 1] == 'x')){
        grid[x - 1][y - 1] = '.';
        solveGrid(x - 1, y - 1);
    }

    if(y > 0 && x < n - 1 && (grid[x + 1][y - 1] == '@' || grid[x + 1][y - 1] == 'x')){
        grid[x + 1][y - 1] = '.';
        solveGrid(x + 1, y - 1);
    }

    if(y < n - 1 && x > 0 && (grid[x - 1][y + 1] == '@' || grid[x - 1][y + 1] == 'x')){
        grid[x - 1][y + 1] = '.';
        solveGrid(x - 1, y + 1);
    }

    if(y < n - 1 && x < n - 1 && (grid[x + 1][y + 1] == '@' || grid[x + 1][y + 1] == 'x')){
        grid[x + 1][y + 1] = '.';
        solveGrid(x + 1, y + 1);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    int cs = 0;
    while(t--){
        scanf("%d", &n);
        getchar();
        for(int i = 0; i < n; i++){
            scanf("%s", grid[i]);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'x'){
                    grid[i][j] = '.';
                    solveGrid(i, j);
                    cnt++;
                }
            }
        }
        printf("Case %d: %d\n", ++cs, cnt);
    }
    return 0;
}