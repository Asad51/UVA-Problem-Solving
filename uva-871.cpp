#include <iostream>
#include <cstdio>
#include <cstring>

int cnt, n;
char grid[26][26];

void solveGrid(int x, int y){
    grid[x][y] = '0';
    cnt++;
    if(x > 0 && grid[x - 1][y] == '1')
        solveGrid(x - 1, y);

    if(x < n - 1 && grid[x + 1][y] == '1' )
        solveGrid(x + 1, y);

    if(y > 0 && grid[x][y - 1] == '1')
        solveGrid(x, y - 1);

    if(y < n - 1 && grid[x][y + 1] == '1')
        solveGrid(x, y + 1);

    if(y > 0 && x > 0 && grid[x - 1][y - 1] == '1')
        solveGrid(x - 1, y - 1);

    if(y > 0 && x < n - 1 && grid[x + 1][y - 1] == '1')
        solveGrid(x + 1, y - 1);

    if(y < n - 1 && x > 0 && grid[x - 1][y + 1] == '1')
        solveGrid(x - 1, y + 1);

    if(y < n - 1 && x < n - 1 && grid[x + 1][y + 1] == '1')
        solveGrid(x + 1, y + 1);
}

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    getchar();
    while(t--){
        n = 0;
        gets(grid[n++]);
        while(n < strlen(grid[0])){
            gets(grid[n]);
            n++;
        }
        int maxCnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1')
                {
                    cnt = 0;
                    solveGrid(i, j);
                    if(cnt > maxCnt)
                        maxCnt = cnt;
                }
            }
        }
        printf("%d\n", maxCnt);
        if(t){
            printf("\n");
            getchar();
        }
    }
    return 0;
}
