#include <iostream>
#include <cstdio>

struct Pair{
    int l;
    int cnt;
};

class FillHole{
    int m, n, k, cnt;
    char map[51][51];
    Pair solution[2501];
public:
    FillHole(int m, int n){
        this->n = n;
        this->m = m;
        for(int i = 0; i < n * m; i++){
            solution[i].l = solution[i].cnt = 0;
        }
        k = 0;
    }

    void getInput(){
        for(int i = 0; i < m; i++){
            scanf("%s", map[i]);
        }
    }

    void solvemap(int x, int y, char ch){
        map[x][y] = '.';
        cnt++;
        if(x > 0 && map[x - 1][y] == ch){
            solvemap(x - 1, y, ch);
        }

        if(x < m - 1 && map[x + 1][y] == ch){
            solvemap(x + 1, y, ch);
        }

        if(y > 0 && map[x][y - 1] == ch){
            solvemap(x, y - 1, ch);
        }

        if(y < n - 1 && map[x][y + 1] == ch){
            solvemap(x, y + 1, ch);
        }

    }

    void solve(){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(map[i][j] != '.'){
                    cnt = 0;
                    int tmp = map[i][j] - 'A';
                    solvemap(i, j, map[i][j]);
                    solution[k].l = tmp;
                    solution[k].cnt = cnt;
                    k++;
                }
            }
        }
        for(int i = 0; i < k; i++){
            for(int j = i + 1; j < k; j++){
                if(solution[j].cnt > solution[i].cnt || (solution[i].cnt == solution[j].cnt && solution[j].l < solution[i].l))
                {
                    Pair tmp = solution[j];
                    solution[j] = solution[i];
                    solution[i] = tmp;
                }
            }
        }

        for(int i = 0; i < k; i++)
            printf("%c %d\n", solution[i].l + 'A', solution[i].cnt);
    }
};

int main() {
    int m, n;
    int cs = 0;
    while(scanf("%d %d", &m, &n) && m && n){
        getchar();
        FillHole fh(m, n);
        fh.getInput();
        printf("Problem %d:\n", ++cs);
        fh.solve();
    }
    return 0;
}
