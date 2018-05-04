#include "bits/stdc++.h"
using namespace std;

#define sz 5

class Backtrack
{
	bool isPossible;
	int mark[sz];
public:
	Backtrack(){
		isPossible = false;
		for(int i=0; i<sz; i++)
			mark[i] = 0;
	}

	bool checkResult(){
		return isPossible;
	}

	int evaluteOpr(int a, int b, char opr){
		int res ;
		if(opr=='+')
			res = a + b;
		else if(opr=='-')
			res = a - b;
		else if(opr=='*')
			res = a * b;
		return res;
	}

	void solveExprn(int a[sz], int row, int res){
		char opr[sz] = {'+', '-', '*'};
		if(row>=sz){
			if(res==23)
				isPossible = true;
			return;
		}
		for(int i=0; i<sz; i++){
			if(!mark[i]){
				mark[i] = 1;
				solveExprn(a, row + 1, res + a[i]);
				solveExprn(a, row + 1, res - a[i]);
				solveExprn(a, row + 1, res * a[i]);
				mark[i] = 0;
			}
		}
	}

	void checkAllComb(int a[sz]){
		for(int i=0; i<sz; i++){
			mark[i] = 1;
			solveExprn(a, 1, a[i]);
			mark[i] = 0;
		}
	}
	
};

int main(int argc, char const *argv[])
{
	int a[sz];
	while(true){
		bool isZero = true;
		for(int i=0; i<sz; i++){
			cin>>a[i];
			if(isZero && a[i]!=0)
				isZero = false;
		}

		if(isZero)
			break;

		Backtrack b;
		b.checkAllComb(a);
		if(b.checkResult())
			cout<<"Possible\n";
		else
			cout<<"Impossible\n";
		
	}

	return 0;
}