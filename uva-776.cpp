#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
char map[513][513];
int species[513][513], check[513];

int max(int a, int b){
    return (a > b) ? a: b;
}

void reset(){
    n = m = 0;
    for(int i = 0; i < 513; i++){
        for(int j = 0; j < 513; j++){
            species[i][j] = 0;
            check[j] = 0;
        }
    }
}

void solveMap(int x, int y, char ch, int t){
    species[x][y] = t;
    check[y] = max(check[y], t);
    if(x > 0 && !species[x - 1][y] && map[x - 1][y] == ch)
        solveMap(x - 1, y, ch, t);
    if(x < n - 1 && !species[x + 1][y] && map[x + 1][y] == ch)
        solveMap(x + 1, y, ch, t);
    if(y - 2 >= 0 && !species[x][y - 2] && map[x][y - 2] == ch)
        solveMap(x, y - 2, ch, t);
    if(y + 2 < m && !species[x][y + 2] && map[x][y + 2] == ch)
        solveMap(x, y + 2, ch, t);
    if(x > 0 && y - 2 >= 0 && !species[x - 1][y - 2] && map[x - 1][y - 2] == ch)
        solveMap(x - 1, y - 2, ch, t);
    if(x < n - 1 && y - 2 >= 0 && !species[x + 1][y - 2] && map[x + 1][y - 2] == ch)
        solveMap(x + 1, y - 2, ch, t);
    if(x > 0 && y + 2 < m && !species[x - 1][y + 2] && map[x - 1][y + 2] == ch)
        solveMap(x - 1, y + 2, ch, t);
    if(x < n - 1 && y + 2  < m && !species[x + 1][y + 2] && map[x + 1][y + 2] == ch)
        solveMap(x + 1, y + 2, ch, t);
}

void solve(){
    int t = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!species[i][j] && map[i][j] != ' '){
                species[i][j] = t;
                solveMap(i, j, map[i][j], t);
                t++;
            }
        }
    }
}

void printSolution(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!species[i][j])
                printf(" ");
            else if(check[j] <= 9)
                printf("%d", species[i][j]);
            else if(check[j] <= 99)
                printf("%2d", species[i][j]);
            else if(check[j] <= 999)
                printf("%3d", species[i][j]);
            else if(check[j] <= 9999)
                printf("%4d", species[i][j]);
            else if(check[j] <= 99999)
                printf("%5d", species[i][j]);
            else
                printf("%6d", species[i][j]);
        }
        printf("\n");
    }
    printf("%%\n");
}

int main() {
    reset();
    while(gets(map[n])){
        n++;
        if(map[n - 1][0] == '%'){
            n--;
            m = strlen(map[0]);
            solve();
            printSolution();
            reset();
        }
    }
    m = strlen(map[0]);
    solve();
    printSolution();

    return 0;
}
