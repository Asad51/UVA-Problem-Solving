#include <stdio.h>

int solution[100][9];
int s = 0;

int abs(int a){
    return (a < 0) ? -a: a;
}

int min(int a, int b){
    return (a < b) ? a: b;
}

int isPromising(int board[9][9], int i, int j){
    for(int k = j; k >= 0; k--){
        if(board[i][k])
            return 0;
    }

    for(int k = i, l = j; k >=0 && l >= 0; k--, l--){
        if(board[k][l])
            return 0;
    }

    for(int k = i, l = j; k < 8 && l >= 0; k++, l--){
        if(board[k][l])
            return 0;
    }
    return 1;
}

void solve(int board[9][9], int j){
    if(j >= 8) {
        for(int j = 0; j < 8; j++){
            for(int i = 0; i < 8; i++){
                if(board[i][j]){
                    solution[s][j] = i + 1;
                    break;
                }
            }
        }
        s++;
        return;
    }

    for(int i = 0; i < 8; i++){
        if(!board[i][j] && isPromising(board, i, j)){
            board[i][j] = 1;
            solve(board, j + 1);
            board[i][j] = 0;
        }
    }
}

int main(void) {
    int board[9][9];
    int arr[9];
    int cz = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = 0;
        }
    }
    solve(board, 0);
    while(scanf("%d", &arr[0]) != EOF){
        for(int i = 1; i < 8; i++){
            scanf("%d", &arr[i]);
        }
        int sum, minSum = 100001;
        for(int i = 0; i < s; i++){
            sum = 0;
            for(int j = 0; j < 8; j++){
                if(solution[i][j] != arr[j]){
                    sum++;
                } 
            }
            minSum = min(sum, minSum);
        }
        printf("Case %d: %d\n", ++cz, minSum);
    }
    return 0;
}
