#include <iostream>
#include <cstdio>
using namespace std;

class Stars{
    int r, c;
    char grid[101][101];
    int s;
public: 
    Stars(int r, int c){
        this->r = r;
        this->c = c;
        s = 0;
    }

    void getInput(){
        for(int i = 0; i < r; i++){
            scanf("%s", grid[i]);
        }
    }

    void solve(){
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                bool isStarCount = false;
                if(grid[i][j] == '*'){
                    isStarCount = true;
                    if(i > 0 && grid[i - 1][j] == '*'){
                        isStarCount = false;
                    }
                    else if(i < r - 1 && grid[i + 1][j] == '*'){
                        isStarCount = false;
                    }
                    else if(j > 0 && grid[i][j - 1] == '*'){
                        isStarCount = false;
                    }
                    else if(j < c - 1 && grid[i][j + 1] == '*'){
                        isStarCount = false;
                    }
                    else if(j > 0 && i > 0 && grid[i - 1][j - 1] == '*'){
                        isStarCount = false;
                    }
                    else if(j < c - 1 && i > 0 && grid[i - 1][j + 1] == '*'){
                        isStarCount = false;
                    }
                    else if(j > 0 && i < r - 1 && grid[i + 1][j - 1] == '*'){
                        isStarCount = false;
                    }
                    else if(j < c - 1 && i < r - 1 && grid[i + 1][j + 1] == '*'){
                        isStarCount = false;
                    }
                }

                if(isStarCount)
                    s++;
            }
        }

        printf("%d\n", s);
    }
};

int main() {
    int r, c;
    while(scanf("%d %d", &r, &c) && r && c){
        Stars st(r, c);
        st.getInput();
        st.solve();
    }
    return 0;
}
