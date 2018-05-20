#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
    //freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    char key[] = {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
                  'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', 92,
                  'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', 39,
                  'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'
                 };
    int n = strlen(key);
    char ch;
    int c = 0;
    while(scanf("%c", &ch) != EOF)
    {
        if(ch==' ' || ch == '\n')
            printf("%c", ch);
        else
        {
            for(int j=0; j<n; j++)
            {
                if(ch==key[j])
                {
                    ch = key[j-1];
                    break;
                }
            }
            printf("%c", ch);
        }
    }

    return 0;
}
