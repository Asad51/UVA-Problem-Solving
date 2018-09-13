#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

class Team{
public:
	string name;
	lli points;
	lli wins;
	lli loses;
	lli ties;
	lli goalDiff;
	lli goalsScored;
	lli goalsAgainst;
	lli played;
	void init(string n){
		name = n;
		points = wins = loses = ties = goalDiff = goalsScored = goalsAgainst = played = 0;
	}
	void updatePointTable(lli ga, lli gb){
		played++;
		if(ga>gb){
			wins++;
			points += 3;
		}
		else if(gb>ga){
			loses++;
		}
		else{
			ties++;
			points++;
		}
		goalDiff += (ga-gb);
		goalsScored += ga;
		goalsAgainst += gb;
	}
};

char toLower(char ch){
	if(ch>='A' && ch<='Z')
		return ch + 32;
	return ch;
}

bool cmpStr(string a, string b){
	for(lli i=0; i<a.size() && b.size(); i++){
		if(toLower(a[i])<toLower(b[i]))
			return true;
		if(toLower(a[i])>toLower(b[i]))
			return false;
	}
	return a.size()<b.size();
}

bool comp(Team a, Team b){
	if(a.points != b.points)
		return a.points > b.points;
	if(a.wins != b.wins)
		return a.wins > b.wins;
	if(a.goalDiff != b.goalDiff)
		return a.goalDiff > b.goalDiff;
	if(a.goalsScored != b.goalsScored)
		return a.goalsScored > b.goalsScored;
	if(a.played != b.played)
		return a.played < b.played;
	return cmpStr(a.name, b.name);
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	lli tc;
	cin>>tc;
	//getchar();
	getchar();
	string tournamentName, name;
	while(tc--){
		getline(cin, tournamentName);
		//cout<<tournamentName<<endl;
		lli n, m;
		cin>>n;
		getchar();
		Team teams[n];
		map<string, lli>index;
		for(lli i=0; i<n; i++){
			getline(cin, name);
			teams[i].init(name);
			index.insert(make_pair(name, i));
			//cout<<name<<endl;
		}
		cin>>m;
		string teamA, teamB, game;
		lli ga, gb;
		getchar();
		for(lli i=0; i<m; i++){
			getline(cin, game);
			//cout<<game<<endl;
			string tmp = "";
			lli tmp1 = 0;
			lli j = 0;

			while(game[j]!='#')
				tmp += game[j++];
			teamA = tmp;
			//cout<<teamA<<endl;
			tmp = "";
			j++;

			while(game[j]!='@'){
				tmp1 = tmp1 * 10 + (game[j++]-48);
			}
			ga = tmp1;
			tmp1 = 0;
			//cout<<ga<<endl;
			j++;
			while(game[j]!='#'){
				tmp1 = tmp1 * 10 + (game[j++]-48);
			}
			gb = tmp1;
			j++;
			//cout<<gb<<endl;
			while(game[j]!='\n' && j<game.size())
				tmp += game[j++];
			teamB = tmp;
			//cout<<teamB<<endl;
			lli a, b;
			a = index[teamA];
			b = index[teamB];
			//cout<<a<<b<<endl;
			teams[a].updatePointTable(ga, gb);
			teams[b].updatePointTable(gb, ga);
		}

		sort(teams, teams + n, comp);
		cout<<tournamentName<<"\n";
        for(lli i = 0; i < n; i++)
        	cout<<i+1<<") "<<teams[i].name <<" "<<teams[i].points<<"p, "<<teams[i].played<<"g ("<<teams[i].wins<<"-"<<teams[i].ties<<"-"<<teams[i].loses<<"), "<<teams[i].goalDiff<<"gd ("<<teams[i].goalsScored<<"-"<<teams[i].goalsAgainst<<")\n";
        if(tc)
        	printf("\n");

	}
	return 0;
}
