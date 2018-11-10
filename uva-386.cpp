#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main(int argc, char const *argv[])
{
	lli qubes[201];
	for(lli i=0; i<201; i++)
		qubes[i] = pow(i, 3);

	for(lli i=2; i<201; i++){
		lli sum = 0;
		for(lli j=2; j<i; j++){
			sum += qubes[j];
			lli k = j + 1;
			while((sum + qubes[k] < qubes[i]) ) {
			    sum += qubes[k];
			    lli l = k + 1;
			    while((sum + qubes[l] <= qubes[i]) ){
			        sum += qubes[l];
			        if(sum==qubes[i])
			        	cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<l<<")\n";
			        sum -= qubes[l++];
			    }
			    sum -= qubes[k++];
			}
			sum -= qubes[j];
		}
	}
	return 0;
}
