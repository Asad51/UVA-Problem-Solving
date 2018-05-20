#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    long long n;
    cin>>t;
    while(t--) {
        cin>>n;
        long long a, b;
        int c = 0;
        do {
            a = n;
            b = 0;
            while(n) {
                b = b*10 + n%10;
                n /= 10;
            }
            c++;
            n = a + b;
        } while(a != b);
        cout<<c-1<<" "<<a<<"\n";
    }
    return 0;
}
