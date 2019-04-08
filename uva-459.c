#include <stdio.h>

int check[27], adj[27][27];

void solve(int n, int i){
    check[i] = 1;
    for(int j = 0; j < n; j++){
        if(!check[j] && adj[i][j]){
            solve(n, j);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    getchar();
    while(t--){
        char st[3];
        int n, u, v, s = 0;
        gets(st);
        n = st[0] - 'A' + 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                adj[i][j] = 0;
            check[i] = 0;
        }
        int i = 0;
        while(gets(st)){
            if (st[0] == '\0')
			    break;
		    u = st[0] - 'A';
            v = st[1] - 'A';
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        for(int i = 0; i < n; i++){
            if(!check[i]){
                solve(n, i);
                s++;
            }
        }
        printf("%d\n", s);
        if (t){
		    printf("\n");
        }
    }
    return 0;
}