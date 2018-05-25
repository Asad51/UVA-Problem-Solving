#include <bits/stdc++.h>
using namespace std;

int getDays(string date){
	//int month[12] = {}
	int days = 0, tmp = 0, j = 1;
	vector<int>d;
	for(int i=date.size()-1; i>=0; i--){
		if(date[i]!='/'){
			tmp += (date[i]-48)*j;
			j *= 10;
		}
		if(date[i]=='/' || i==0){
			d.push_back(tmp);
			tmp = 0;
			j = 1;
		}
	}
	///cout<<d[2]<<" "<<d[1]<<" "<<d[0]<<endl;
	days = d[0]*365 + d[1]*30 + d[2];
	d.clear();
	return days;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); 
	//freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		string current, birth;
		cin>>current>>birth;
		int c = getDays(current);
		int b = getDays(birth);
		//cout<<c<<" "<<b<<endl;
		int age = (c-b);
		if(age<0)
			cout<<"Case #"<<i<<": Invalid birth date\n";
		else if(age>=131*365)
			cout<<"Case #"<<i<<": Check birth date\n";
		else
			cout<<"Case #"<<i<<": "<<age/365<<"\n";
		//if(i==412 || i==761)
			//cout<<current<<" "<<birth<<endl;
	}
	return 0;
}
