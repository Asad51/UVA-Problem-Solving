#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		//set<string> persons;
		map<string, set<string> >persons;
		string p1, p2;
		while(n--){
			set<string>tmp;
			set<string>::iterator it;
			cin>>p1>>p2;
			persons[p1].insert(p2);
			persons[p2].insert(p1);
			for(it = persons[p1].begin(); it!=persons[p1].end(); ++it){
				tmp.insert(*it);
				persons[p2].insert(*it);
			}
			for(it = persons[p2].begin(); it!=persons[p2].end(); ++it){
				tmp.insert(*it);
				persons[p1].insert(*it);
			}
			cout<<persons[p1].size()<<" "<<persons[p2].size()<<endl;
			cout<<tmp.size()<<"\n";
			tmp.clear();
		}
		persons.clear();
	}
	return 0;
}
