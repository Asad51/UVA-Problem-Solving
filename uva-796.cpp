#include <iostream>
#include <cstdio>

class Critical{
    int n;
    int path[201][201], mark[201][201];
public:
    Critical(int n){
        this->n = n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                path[i][j] = mark[i][j] = 0;
        }
    }

    void getInput(){
        int u, v, m;
        for(int j = 0; j < n; j++){
            scanf("%d (%d)", &u, &m);
            for(int i = 0; i < m; i++){
                scanf("%d", &v);
                path[u][v] = path[v][u] = 1;
            }
        }
    }

    void reset(int visited[]){
        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }
    }

    void dfs(int u, int visited[]){
        visited[u] = 1;
        for(int i = 0; i < n; i++)
            if(path[u][i] == 1 && visited[i] != 1)
                dfs(i, visited);
    }

    int getConnectedComponents(int u){
        int cnt = 0;
        int visited[n];
        reset(visited);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, visited);
                cnt++;
            }
        }
        return cnt;
    }

    void solve(){
        int cnt = 0;
        int p = getConnectedComponents(0);
        int solution[201][4] = {{0}}, l = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(path[i][j] && !mark[i][j]){
                    path[i][j] = path[j][i] = 0;
                    mark[i][j] = mark[j][i] = 1;
                    int q = getConnectedComponents(i);
                    if(q > p){
                        cnt++;
                        solution[l][0] = i;
                        solution[l][1] = j;
                        l++;
                    }
                    path[i][j] = path[j][i] = 1;
                }
            }
        }
        printf("%d critical links\n", cnt);
        for(int i = 0; i < l; i++)
            printf("%d - %d\n", solution[i][0], solution[i][1]);
        printf("\n");
    }
};

int main() {
    int n;
    while(scanf("%d", &n) != EOF){
        Critical cl(n);
        cl.getInput();
        cl.solve();
    }
    return 0;
}
