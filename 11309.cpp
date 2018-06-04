#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int current){
	int h = current/60, m = current%60;
	int num = h*100 + m;
	int tmp = num, sum = 0;
	while(tmp){
		sum = sum*10 + (tmp%10);
		tmp /= 10;
	}
	if(sum==num)
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--){
		int hh, mm, current, next;
		scanf("%d:%d", &hh, &mm);
		current = hh*60 + mm;
		next = current+1;
		while(next){
			if(next==current)
				break;
			if(next>1439)
				next = 0;
			if(isPalindrome(next)){
				printf("%02d:%02d\n", next/60, next%60);
				break;
			}
			next++;
		}
	}
	return 0;
}
