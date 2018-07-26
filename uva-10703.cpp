#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
	int w, h, n;
	while(scanf("%d %d %d", &w, &h, &n)){
		if(!w && !h && !n)
			break;
		int mat[h][w];
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++)
				mat[i][j] = 0;
		}
		for(int i=0; i<n; i++){
			int x1, x2, y1, y2, mxx, mnx, mxy, mny;
			cin>>x1>>y1>>x2>>y2;
			mxx = max(x1, x2);
			mnx = min(x1, x2);
			mxy = max(y1, y2);
			mny = min(y1, y2);
			for(int j=mny-1; j<mxy; j++ ){
				for(int k=mnx-1; k<mxx; k++)
					mat[j][k] = 1;
			}
		}

		int c = 0;
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(mat[i][j]==0)
					c++;
				else
					mat[i][j] = 0;
			}
		}
		if(c==0)
			printf("There is no empty spots.\n");
		else if(c==1)
			printf("There is one empty spot.\n");
		else
			printf("There are %d empty spots.\n", c);
	}
	return 0;
}
