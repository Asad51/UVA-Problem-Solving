#include <bits/stdc++.h>
using namespace std;

class Puzzle
{
	char grid[7][7];
	int cx, cy;
public:
	Puzzle(){

	}
	bool getInput(){
		for(int i=0; i<5; i++){
			gets(grid[i]);
			for(int j=0; j<5; j++){
				if(grid[i][j]=='Z')
					return true;
				if(grid[i][j]==' ')
				{
					cx = i;
					cy = j;
				}
			}
			//getchar();
			//getchar();
		}
		/*for(int i=0; i<5; i++){
			for(int j = 0; j<5; j++)
				printf("%c", grid[i][j]);
			printf("\n");
		}
		cout<<cx<<cy<<endl;*/
		return false;
	}

	void swap(int x1, int y1){
		char tmp = grid[cx][cy];
		grid[cx][cy] = grid[x1][y1];
		grid[x1][y1] = tmp;
		cx = x1;
		cy = y1;
	}

	bool movingPosition(){
		char cmd[1001], ch;
		int cnt = 0;
		while (scanf("%c",&ch)){  
            if (ch == '0') 
            	break;  
            if(isalnum(ch))
            	cmd[cnt++] = ch;
        }
        cmd[cnt] = '\0';
		//getchar();
		getchar();
		//cout<<cmd<<endl;
		for(int i=0; cmd[i]; i++){
			//printf("%c\n", cmd[i]);
			if(cmd[i]=='A'){
				if(cx>0){
					swap(cx-1, cy);
				}
				else
					return false;
			}
			else if(cmd[i]=='B'){
				if(cx<4){
					swap(cx+1, cy);
				}
				else
					return false;
			}
			else if(cmd[i]=='L'){
				if(cy>0){
					swap(cx, cy-1);
				}
				else
					return false;
			}
			else if(cmd[i] == 'R'){
				if(cy<4){
					swap(cx, cy+1);
				}
				else
					return false;
			}
			else// if(cmd[i]!='\n')
				return false;
		}
		return true;
	}

	void printFinalConfig(){
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if(j != 0)
					printf(" ");
				printf("%c", grid[i][j]);
			}
			printf("\n");
		}
	}
};

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int cs = 0;
	while(true){
		Puzzle *pz = new  Puzzle();
		bool isEndOfInput = pz->getInput();
		if(isEndOfInput)
			break;
		bool hasFinalConfig = pz->movingPosition();
		if(cs!=0)
			printf("\n");
		printf("Puzzle #%d:\n", ++cs);
		if(hasFinalConfig){
			pz->printFinalConfig();
		}
		else{
			printf("This puzzle has no final configuration.\n");
		}
		delete(pz);
	}
	return 0;
}
