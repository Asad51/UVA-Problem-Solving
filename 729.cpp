#include "bits/stdc++.h"
using namespace std;

class Backtrack
{
	int n, h;
	string bits;
	vector<string>allBits;
public:
	Backtrack(int nn, int hh){
		n = nn;
		h = hh;
		bits = "";
		for(int i=0; i<n; i++)
			bits = bits + '0';
		allBits.clear();
	}

	void printBits(){
		sort(allBits.begin(), allBits.end());
		for(int i=0; i<allBits.size(); i++)
			cout<<allBits[i]<<"\n";
	}

	void generateBits(int pos, int count){
		if(count==h){
			allBits.push_back(bits);
			return;
		}
		if(pos<0){
			return;
		}
		bits[pos] = '1';
		generateBits(pos-1, count+1);
		bits[pos] = '0';
		generateBits(pos-1, count);
	}
};

int main(int argc, char const *argv[])
{	
	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		int N, H;
		cin>>N>>H;
		Backtrack b(N, H);
		b.generateBits(N-1, 0);
		b.printBits();
		if(i!=t)
			cout<<"\n";
	}
	return 0;
}
