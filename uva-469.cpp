#include <iostream>
#include <cstdio>
#include <cstring>

class WaterLand{
    int n, m, cnt;
    int sx, sy;
    char map[100][100];
public:
    WaterLand(){
        n = 0;
        cnt = 0;
    }

    void getInput(){
        while (gets(map[n])) {
            if (map[n][0] != 'L' && map[n][0] != 'W')
                break;
            n++;
	    }
        m = strlen(map[0]);
    }

    void solveMap(int x, int y){
        map[x][y] = 'P';
        cnt++;
        if(x > 0 && map[x - 1][y] == 'W')
            solveMap(x - 1, y);

        if(x < n - 1 && map[x + 1][y] == 'W' )
            solveMap(x + 1, y);

        if(y > 0 && map[x][y - 1] == 'W')
            solveMap(x, y - 1);

        if(y < m - 1 && map[x][y + 1] == 'W')
            solveMap(x, y + 1);

        if(y > 0 && x > 0 && map[x - 1][y - 1] == 'W')
            solveMap(x - 1, y - 1);

        if(y > 0 && x < n - 1 && map[x + 1][y - 1] == 'W')
            solveMap(x + 1, y - 1);

        if(y < m - 1 && x > 0 && map[x - 1][y + 1] == 'W')
            solveMap(x - 1, y + 1);

        if(y < m - 1 && x < n - 1 && map[x + 1][y + 1] == 'W')
            solveMap(x + 1, y + 1);
    }

    void solve(){
        int i;
        while (map[n][0] != '\0') {
		    i = sx = sy = cnt = 0;
		    while (map[n][i] != ' ') {
			    sx = sx*10 + map[n][i] - '0';
			    i++;
		    }
		    i++;
		    while (map[n][i] != '\0') {
			    sy = sy*10 + map[n][i] - '0';
			    i++;
		    }

            for(int j = 0; j < n; j++){
                for(int k = 0; k < m; k++){
                    if(map[j][k] == 'P')
                        map[j][k] = 'W';
                }
            }

		    solveMap(sx - 1, sy - 1);
		    printf("%d\n", cnt);
		    if (!gets(map[n]))
			    break;
	    }
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
        if(t)
            printf("\n");
    }
    return 0;
}
