#include "bits/stdc++.h"
using namespace std;

#define SIZE 8

class nQueens{
	int pos[SIZE];
	int max_sum;
public:
	nQueens(){
		for(int i=0; i<SIZE; i++)
			pos[i] = 0;
		max_sum = 0;
	}

	int max(int a, int b){
		if(a>b)
			return a;
		return b;
	}

	bool isSafe(int board[SIZE][SIZE], int row, int col){
		//checking left side of same row
		for(int i=col-1; i>=0; i--){
			if(board[row][i]==-1)
				return false;
		}

		//checking left side upper diagonal
		for(int i = row - 1, j = col -1 ; i>=0 && j>=0; i--, j--){
			if(board[i][j]==-1)
				return false;
		}

		//checking left side lower diagonal
		for(int i = row + 1, j = col -1 ; i<SIZE && j>=0; i++, j--){
			if(board[i][j]==-1)
				return false;
		}

		return true;
	}

	void printSum(){
		cout<<setw(5)<<max_sum<<"\n";
	}

	void solveQueens(int board[SIZE][SIZE], int col){
		if(col>=SIZE){
			int sum = 0;
			for(int i=0; i<SIZE; i++){
				sum += pos[i];
			}
			//cout<<sum<<"\n";
			max_sum = max(max_sum, sum);
			return;
		}
		for(int i=0; i<SIZE; i++){
			if(isSafe(board, i, col)){
				pos[col] = board[i][col];
				board[i][col] = -1;
				solveQueens(board, col + 1);
				board[i][col] = pos[col];
			}
		}	
	}
};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    int board[SIZE][SIZE];
    int dt;
    cin>>dt;
    
    for(int i=0; i<dt; i++){
    	for(int j = 0; j<SIZE; j++){
    		for(int k=0; k<SIZE; k++){
    			cin>>board[j][k];
    		}
    	}
    	nQueens nq;
    	nq.solveQueens(board, 0);
    	nq.printSum();
    }
	return 0;
}