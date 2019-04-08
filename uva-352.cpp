#include <iostream>
#include <cstdio>
using namespace std;

class WarEdge{
    int n;
    char image[101][101];
    int s;
public: 
    WarEdge(int n){
        this->n = n;
        s = 0;
    }

    void getInput(){
        for(int i = 0; i < n; i++){
            scanf("%s", image[i]);
        }
    }

    void solveGrid(int x, int y){
        if(x > 0 && image[x - 1][y] == '1'){
            image[x - 1][y] = '*';
            solveGrid(x - 1, y);
        }

        if(x < n - 1 && image[x + 1][y] == '1'){
            image[x + 1][y] = '*';
            solveGrid(x + 1, y);
        }

        if(y > 0 && image[x][y - 1] == '1'){
            image[x][y - 1] = '*';
            solveGrid(x, y - 1);
        }

        if(y < n - 1 && image[x][y + 1] == '1'){
            image[x][y + 1] = '*';
            solveGrid(x, y + 1);
        }

        if(y > 0 && x > 0 && image[x - 1][y - 1] == '1'){
            image[x - 1][y - 1] = '*';
            solveGrid(x - 1, y - 1);
        }

        if(y > 0 && x < n - 1 && image[x + 1][y - 1] == '1'){
            image[x + 1][y - 1] = '*';
            solveGrid(x + 1, y - 1);
        }

        if(y < n - 1 && x > 0 && image[x - 1][y + 1] == '1'){
            image[x - 1][y + 1] = '*';
            solveGrid(x - 1, y + 1);
        }

        if(y < n - 1 && x < n - 1 && image[x + 1][y + 1] == '1'){
            image[x + 1][y + 1] = '*';
            solveGrid(x + 1, y + 1);
        }
    }

    void solve(int cs){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(image[i][j] == '1')
                {
                    solveGrid(i, j);
                    s++;
                }
            }
        }

        printf("Image number %d contains %d war eagles.\n", cs, s);
    }
};

int main() {
    int n;
    int cs = 0;
    while(scanf("%d", &n) != EOF){
        WarEdge we(n);
        we.getInput();
        we.solve(++cs);
    }
    return 0;
}