#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
    //freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    string s;
    char alpha[] = "A   3  HIL JM O   2TUVWXY5";
    char nums[] = "01SE Z  8 ";
    while(getline(cin, s)){
        bool isMirror = true, isPalindrome = true;
        for(int i=0, j=s.size()-1; i<=j; i++, j--)
        {
            if(s[i] != s[j]){
                isPalindrome = false;
            }
            if(s[i] >= 'A' && s[i] <= 'Z') {
                if(s[j] != alpha[s[i]-'A'])
                    isMirror = false;
            } else {
                if(s[j] != nums[s[i]-'0'])
                    isMirror = false;
            }
        }

        cout<<s;
        if(!isMirror && !isPalindrome)
            cout<<" -- is not a palindrome.\n";
        else if(isPalindrome && isMirror)
            cout<<" -- is a mirrored palindrome.\n";
        else if(isPalindrome)
            cout<<" -- is a regular palindrome.\n";
        else
            cout<<" -- is a mirrored string.\n";
        cout<<"\n";
    }

    return 0;
}
