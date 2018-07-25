#include <bits/stdc++.h>
using namespace std;

char calculateGrade(int total){
	if(total<60)
		return 'F';
	if(total>=90)
		return 'A';
	if(total<90 && total>=80)
		return 'B';
	if(total<80 && total>=70)
		return 'C';
	return 'D';
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	for(int cs = 1; cs<=t; cs++){
		int t1, t2, f, a, ct1, ct2, ct3, ct_min = 0, ct_avg, total = 0;
		scanf("%d %d %d %d %d %d %d", &t1, &t2, &f, &a, &ct1, &ct2, &ct3);
		total = t1 + t2 + f + a;
		ct_avg = ct1 + ct2 + ct3;
		ct_min = min(min(ct1, ct2), ct3);
		ct_avg -= ct_min;
		ct_avg /= 2;
		total += ct_avg;
		printf("Case %d: %c\n", cs, calculateGrade(total));
	}
	return 0;
}
