#include <iostream>
#include <cstdio>
using namespace std;

char letters[8] = "IEHOVA#";

class Cobble{
    int n, m;
    char cobbles[9][9];
    int solution[8];
    bool isStarted;
public:
    Cobble(int m, int n){
        this->n = n;
        this->m = m;
        for(int i = 0; i < 3; i++)
            solution[i] = 0;
        isStarted = false;
    }

    void getInput(){
        for(int i = 0; i < m; i++){
            scanf("%s", cobbles[i]);
        }
    }

    void printResult(){
        for(int i = 0; i < 7; i++){
            if(i)
                printf(" ");
            if(solution[i] == 1)
                printf("forth");
            else if(solution[i] == 2)
                printf("left");
            else
                printf("right");
        }
        printf("\n");
    }

    void solveCobble(int i, int j, int k){
        if(cobbles[i][j] == '#'){
            printResult();
            return;
        }
        if(i > 0 && cobbles[i - 1][j] == letters[k]){
            solution[k] = 1;
            solveCobble(i - 1, j, k + 1);
        }
        else if(j > 0 && cobbles[i][j - 1] == letters[k]){
            solution[k] = 2;
            solveCobble(i, j - 1, k + 1);
        }
        else if(j < n - 1 && cobbles[i][j + 1]  == letters[k]){
            solution[k] = 3;
            solveCobble(i, j + 1, k + 1);
        }
    }
    
    void solve(){
        for(int i = 0; i < n; i++){
           if(cobbles[m - 1][i] == '@'){
               solveCobble(m - 1, i, 0);
           }
        } 
    }
};

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        Cobble cb(n, m);
        cb.getInput();
        cb.solve();
    }
    return 0;
}
