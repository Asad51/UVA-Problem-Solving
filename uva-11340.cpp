#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	while(n--){
		map<char, int>value;
		char ch;
		int vl, k;
		int total = 0;
		scanf("%d", &k);
		getchar();
		//getchar();
		for(int i=0; i<k; i++){
			scanf("%c %d\n", &ch, &vl);
			value.insert(make_pair(ch, vl));
			//cout<<ch<<" "<<vl<<endl;
		}

		int m;
		scanf("%d", &m);
		getchar();
		//getchar();
		while(m--){
			do{
				scanf("%c", &ch);
				//cout<<ch;
				total += value[ch];
			}while(ch != '\n');
		}
		printf("%d.%02d$\n", total/100, total%100);
	}
	return 0;
}
