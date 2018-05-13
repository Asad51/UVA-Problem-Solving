#include <iostream>
using namespace std;

int main() {
	int n, count = 0;
	while (cin>>n) {
		if(!n)
			break;
		count++;
		int sum = 0, num;
		for (int i = 0; i < n; i++) {
			cin>>num;
			if (num > 0)
				sum++;
			else
				sum--;
		}
		cout<<"Case "<<count<<": "<<sum<<endl;
	}
	return 0;
}