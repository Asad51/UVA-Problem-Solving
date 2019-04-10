#include <iostream>
#include <cstdio>
using namespace std;

struct Pair{
    int l;
    int cnt;
};

class Language{
    int h, w;
    int l[27];
    char map[101][101];
    Pair solution[27];
public:
    Language(int h, int w){
        this->h = h;
        this->w = w;
        for(int i = 0; i < 26; i++){
            l[i] = 0;
            solution[i].l = solution[i].cnt = 0;
        }
    }

    void getInput(){
        for(int i = 0; i < h; i++){
            scanf("%s", map[i]);
        }
    }

    void solvemap(int x, int y, char ch){
        map[x][y] = '@';
        if(x > 0 && map[x - 1][y] == ch){
            solvemap(x - 1, y, ch);
        }

        if(x < h - 1 && map[x + 1][y] == ch){
            solvemap(x + 1, y, ch);
        }

        if(y > 0 && map[x][y - 1] == ch){
            solvemap(x, y - 1, ch);
        }

        if(y < w - 1 && map[x][y + 1] == ch){
            solvemap(x, y + 1, ch);
        }
    }

    void solve(){
        int k = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(map[i][j] != '@'){
                    int tmp = map[i][j] - 'a';
                    l[tmp]++;
                    solvemap(i, j, map[i][j]);
                }
            }
        }

        for(int i = 0; i < 26; i++){
            if(l[i])
            {
                solution[k].l = i;
                solution[k].cnt = l[i];
                k++;
            }
        }
        for(int i = 0; i < k; i++){
            for(int j = i + 1; j < k; j++){
                if(solution[j].cnt > solution[i].cnt)
                {
                    Pair tmp = solution[j];
                    solution[j] = solution[i];
                    solution[i] = tmp;
                }
            }
        }

        for(int i = 0; i < k; i++)
            printf("%c: %d\n", solution[i].l + 'a', solution[i].cnt);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        int h, w;
        scanf("%d %d", &h, &w);
        Language lg(h, w);
        lg.getInput();
        printf("World #%d\n", i);
        lg.solve();
    }
    return 0;
}
