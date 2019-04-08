#include <iostream>
#include <cstdio>
using namespace std;

class Walk{
    int m, n;
    int adj[11][11];
    int check[11], result[11];
public:
    int solution;
    Walk(int m, int n){
        this->m = m;
        this->n = n;
        solution = 0;
        for(int i = 0; i < m; i++){
            check[i] = 0;
            result[i] = 0;
        }
    }

    void getInput(){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++)
                scanf("%d", &adj[i][j]);
        }
    }

    void printSolution(){
        printf("(");
        for(int i = 0; i <= n; i++){
            if(i)
                printf(",");
            printf("%d", (result[i] + 1));
        }
        printf(")\n");
    }

    void solve(int i, int cnt){
        if(cnt == n){
            printSolution();
            solution++;
            return;
        }

        for(int j = 1; j < m; j++){
            if(!check[j] && adj[i][j]){
                check[j] = 1;
                result[cnt + 1] = j;
                solve(j, cnt + 1);
                result[cnt + 1] = 0;
                check[j] = 0;
            }
        }
    }
};

int main() {
    int m, n, g;
    while(scanf("%d %d", &m, &n)){
        Walk w(m, n);
        w.getInput();
        w.solve(0, 0);
        if(!w.solution)
            printf("no walk of length %d\n", n);
        if(scanf("%d", &g) == EOF)
            break;
        else
            printf("\n");
    }
    return 0;
}
