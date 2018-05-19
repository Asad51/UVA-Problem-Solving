#include <bits/stdc++.h>
using namespace std;

char toUpper(char ch){
	if(ch>='a' && ch<='z')
		return ch-32;
	return ch;
}

int findDigit(string s){
	int val[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
	int digit = 0;
	for(int i=0; i<s.size(); i++){
		char ch = toUpper(s[i]);
		if(ch>='A' && ch<='Z'){
			int n = ch-65;
			digit += val[n];
		}
	}
	
	while(digit/10){
		int sum = 0;
		while(digit){
			sum += digit%10;
			digit /= 10;
		}
		digit = sum;
	}
	return digit;
}

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	string s1, s2;
	while(getline(cin, s1)){
		getline(cin, s2);
		int n1 = findDigit(s1);
		int n2 = findDigit(s2);
		double love;
		if(n1>n2)
			love = ((double)n2/n1) * 100;
		else
			love = ((double)n1/n2) * 100;
		cout<<setprecision(2)<<fixed<<love<<" "<<'%'<<"\n";
	}
	return 0;
}
