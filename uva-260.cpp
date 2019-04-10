#include <iostream>
#include <cstdio>
using namespace std;

char grid[201][201];
int check[201] [201], n;

int isWin;

void whoWins(int x, int y){
    if(x == n - 1 || isWin){
        isWin = 1;
        return;
    }
    check[x][y] = 1;
    if(x > 0 && grid[x - 1][y] == 'b' && !check[x - 1][y]){  
        whoWins(x - 1, y);
    }

    if(x < n - 1 && grid[x + 1][y] == 'b' && !check[x + 1][y]){
        whoWins(x + 1, y);
    }

    if(y > 0 && grid[x][y - 1] == 'b' && !check[x][y - 1]){
        whoWins(x, y - 1);
    }

    if(y < n - 1 && grid[x][y + 1] == 'b' && !check[x][y + 1]){
        whoWins(x, y + 1);
    }

    if(y > 0 && x > 0 && grid[x - 1][y - 1] == 'b' && !check[x - 1][y - 1]){
        whoWins(x - 1, y - 1);
    }

    if(y < n - 1 && x < n - 1 && grid[x + 1][y + 1] == 'b' && !check[x + 1][y + 1]){
        whoWins(x + 1, y + 1);
    }
}

int main() {
    int cs = 0;
    while(scanf("%d", &n) && n){
        getchar();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                check[i][j] = 0;
            scanf("%s", grid[i]);
        }

        isWin = 0;
        for(int j = 0; j < n; j++){
            if(grid[0][j] == 'b'){
                whoWins(0, j);
            }
        }

        printf("%d ", ++cs);
        if(isWin)
            printf("B\n");
        else
            printf("W\n");
    }
}