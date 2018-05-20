#include <bits/stdc++.h>
using namespace std;

void printUp(string n, int s){
	for(int i=0; i<n.size(); i++){
		if(i!=0)
			cout<<" ";
		cout<<" ";
		for(int j=0; j<s; j++){
			if(n[i]=='1' || n[i]=='4')
				cout<<" ";
			else
				cout<<"-";
		}
		cout<<" ";
	}
	cout<<"\n";
}

void printFirstHalf(string n, int s){
	for(int k=0; k<s; k++){
		for(int i=0; i<n.size(); i++){
			if(i!=0)
				cout<<" ";
			if(n[i]=='1' || n[i]=='2' || n[i]=='3' || n[i]=='7')
				cout<<" ";
			else
				cout<<"|";
			for(int j=0; j<s; j++){
				cout<<" ";
			}
			if(n[i]=='5' || n[i]=='6')
				cout<<" ";
			else
				cout<<"|";
		}
		cout<<"\n";
	}
}

void printMid(string n, int s){
	for(int i=0; i<n.size(); i++){
		if(i!=0)
			cout<<" ";
		cout<<" ";
		for(int j=0; j<s; j++){
			if(n[i]=='0' || n[i]=='1' || n[i]=='7')
				cout<<" ";
			else
				cout<<"-";
		}
		cout<<" ";
	}
	cout<<"\n";
}

void printSecondHalf(string n, int s){
	for(int k=0; k<s; k++){
		for(int i=0; i<n.size(); i++){
			if(i!=0)
				cout<<" ";
			if(n[i]=='0' || n[i]=='2' || n[i]=='6' || n[i]=='8')
				cout<<"|";
			else
				cout<<" ";
			for(int j=0; j<s; j++){
				cout<<" ";
			}
			if(n[i]=='2')
				cout<<" ";
			else
				cout<<"|";
		}
		cout<<"\n";
	}
}

void printLower(string n, int s){
	for(int i=0; i<n.size(); i++){
		if(i!=0)
			cout<<" ";
		cout<<" ";
		for(int j=0; j<s; j++){
			if(n[i]=='1' || n[i]=='4' || n[i]=='7')
				cout<<" ";
			else
				cout<<"-";
		}
		cout<<" ";
	}
	cout<<"\n";
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int s;
	string n;
	while(cin>>s>>n){
		if(!s && n=="0")
			break;
		printUp(n, s);
		printFirstHalf(n, s);
		printMid(n, s);
		printSecondHalf(n, s);
		printLower(n, s);
		cout<<"\n";
	}
	return 0;
}
