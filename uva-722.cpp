#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class WaterLand{
    int n, m, cnt;
    int sx, sy;
    char map[100][100];
public:
    WaterLand(){
        n = m = cnt = sx = sy = 0;
    }

    void getInput(){
        int i;
	    gets(map[0]);
	    for (i=0; map[0][i]!=' '; i++)
		    sx = sx*10 + (map[0][i] - '0');
	    for (i++; map[0][i]; i++)
		    sy = sy*10 + (map[0][i] - '0');
	    while (gets(map[n]) && map[n][0])
		    n++;
        m = strlen(map[0]);
    }

    void solveMap(int x, int y){
        map[x][y] = '1';
        cnt++;
        if(x > 0 && map[x - 1][y] == '0')
            solveMap(x - 1, y);

        if(x < n - 1 && map[x + 1][y] == '0' )
            solveMap(x + 1, y);

        if(y > 0 && map[x][y - 1] == '0')
            solveMap(x, y - 1);

        if(y < m - 1 && map[x][y + 1] == '0')
            solveMap(x, y + 1);
    }

    void solve(){
        solveMap(sx - 1, sy - 1);
        printf("%d\n", cnt);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    getchar();
    while(t--){
        WaterLand wl;
        wl.getInput();
        wl.solve();
        if(t){
            printf("\n");
        }
    }
}
