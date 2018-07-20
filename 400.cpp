#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	///freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int n;
	while(cin>>n){
		vector<string> filenames(n);
		char s[60];
		int width = 0;

		for(int i=0; i<n; i++){
			scanf("%s", s);
			int sz = strlen(s);
			filenames[i] = s;
			width = max(width, sz);
		}

		int col = 1, tmp = width, row;
		while(tmp+width+2<60){
			tmp += width + 2;
			col++;
		}
		row = ceil((double)n/(double)col);
		sort(filenames.begin(), filenames.end());
		//for(int i=0; i<filenames.size(); i++)
			//cout<<filenames[i]<<" ";
		for(int i=0; i<60; i++){
			cout<<"-";
		}
		cout<<"\n";
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++){
				int index = i + j*row;
				if(index>=filenames.size()){
					cout<<"\n";
					break;
				}
				cout<<filenames[index];
				for(int k = filenames[index].size(); k<width; k++)
					cout<<" ";
				if(j==col-1)
					cout<<"\n";
				else
					cout<<"  ";
			}
		}
		filenames.clear();
	}
	return 0;
}
