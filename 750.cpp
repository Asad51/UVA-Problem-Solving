#include "bits/stdc++.h"
using namespace std;

#define SIZE 8

class nQueens{
	int pos[SIZE];
	int r, c;
	int n;
public:
	nQueens(int rw, int cl){
		r = rw;
		c = cl;
		n = 0;
		for(int i=0; i<SIZE; i++)
			pos[i] = 0;
	}

	bool isSafe(int board[SIZE][SIZE], int row, int col){
		//checking left side of same row
		for(int i=col-1; i>=0; i--){
			if(board[row][i])
				return false;
		}

		//checking left side upper diagonal
		for(int i = row - 1, j = col -1 ; i>=0 && j>=0; i--, j--){
			if(board[i][j])
				return false;
		}

		//checking left side lower diagonal
		for(int i = row + 1, j = col -1 ; i<SIZE && j>=0; i++, j--){
			if(board[i][j])
				return false;
		}

		return true;
	}

	void printSolution(){
		if(pos[c]!=r)
			return;
		cout<<setw(2)<<++n<<"      ";
		for(int i=0; i<SIZE; i++){
			if(i!=0)
				cout<<" ";
			cout<<pos[i]+1;
		}
		cout<<"\n";
	}

	void solveQueens(int board[SIZE][SIZE], int col){
		if(col>=SIZE){
			printSolution();
			return;
		}
		for(int i=0; i<SIZE; i++){
			if(isSafe(board, i, col)){
				pos[col] = i;
				board[i][col] = 1;
				solveQueens(board, col + 1);
				board[i][col] = 0;
			}
		}	
	}
};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    int board[SIZE][SIZE] = {
    	{0, 0, 0, 0, 0, 0, 0, 0}, 
    	{0, 0, 0, 0, 0, 0, 0, 0}, 
    	{0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0}
    };
    int r, c;
    int dt;
    cin>>dt;
    
    for(int i=0; i<dt; i++){
    	cin>>r>>c;
    	if(i!=0)
    		cout<<"\n";
    	cout<<"SOLN       COLUMN\n";
		cout<<" #      1 2 3 4 5 6 7 8\n\n";
		nQueens nq(r-1, c-1);
    	nq.solveQueens(board, 0);
    }
	return 0;
}