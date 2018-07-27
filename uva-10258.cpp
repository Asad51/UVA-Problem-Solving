#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

struct Programmer
{
	int id;
	int solved;
	lli penalty;
	int subs;
	void init(int ind){
		id = ind;
		solved = 0;
		penalty = 0;
		subs = 0;
	}
	void update(bool isCorrect, lli pen){
		if(isCorrect)
			solved++;
		penalty += pen;
		subs++;
	}
};

bool cmp(Programmer a, Programmer b){
	if(a.solved != b.solved)
		return a.solved > b.solved;
	if(a.penalty != b.penalty)
		return a.penalty < b.penalty;
	return a.id < b.id;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	stringstream ss;
	string s;
	int t;
	getline(cin, s);
	ss.clear();
	ss << s;
	ss >> t;
	getline(cin, s);
	int cs = 0;
	while(t--){
		Programmer ps[101];
		for(int i=0; i<101; i++){
			ps[i].init(i);
		}

		int isSolved[101][10] = {{0}};
		lli pen[101][10] = {{0}};
		
		while(getline(cin, s)){
			if(s.size()<7){
				break;
			}
			int c = 0, p = 0;
			lli tm = 0;
			string a;
			int i = 0;
			ss.clear();
			ss << s;
			ss >> c >> p >> tm >> a;
			lli pn = 0;
			bool isCorrect = false;
			if(a=="C"){
				if(!isSolved[c][p]){
					isSolved[c][p] = 1;
					pen[c][p] += tm;
					pn = pen[c][p];
					isCorrect = true;
				}
			}
			else if(a=="I"){
				pen[c][p] += 20;
			}
			ps[c].update(isCorrect, pn);
		};

		sort(ps, ps+101, cmp);
		if(cs!=0)
			printf("\n");
		for(int i=0; i<101; i++){
			if(ps[i].subs > 0)
				printf("%d %d %Ld\n", ps[i].id, ps[i].solved, ps[i].penalty);
		}
		cs++;
	}
	return 0;
}
