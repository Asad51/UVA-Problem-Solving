#include <cstdio>

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

class Queue
{
    int siz;
    Node *front, *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
        siz = 0;
    }

    void push(int n)
    {
        Node *newNode = new Node(n);
        if (front == NULL)
        {
            front = newNode;
            back = newNode;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
        siz++;
    }

    void pop()
    {
        if (front == NULL)
        {
            return;
        }
        Node *tmp = front->next;
        delete (front);
        front = tmp;
        siz--;
    }

    int top()
    {
        if (!siz)
        {
            return -1;
        }
        return front->val;
    }

    int size()
    {
        return siz;
    }

    bool empty()
    {
        if (!siz)
            return true;
        return false;
    }
};

class Solution
{
    int n, m, street[201][201], guard[201];

public:
    Solution(int n, int m)
    {
        this->n = n;
        this->m = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                street[i][j] = 0;
            guard[i] = 0;
        }
    }

    int min(int a, int b)
    {
        return (a > b) ? b : a;
    }

    void getInput()
    {
        int x, y;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &y);
            street[x][y] = street[y][x] = 1;
        }
    }

    void solve()
    {
        int a, b, ans = 0;
        bool isBipartite;
        Queue q;
        for (int i = 0; i < n; i++)
        {
            if (!guard[i])
            {
                isBipartite = true;
                q.push(i);
                guard[i] = 1;
                a = 1;
                b = 0;
                while (!q.empty())
                {
                    int j = q.top();
                    q.pop();
                    for (int v = 0; v < n; v++)
                    {
                        if (street[j][v])
                        {
                            if (!guard[v])
                            {
                                guard[v] = 3 - guard[j];
                                if (guard[v] == 1)
                                    a++;
                                else
                                    b++;
                                q.push(v);
                            }
                            else if (guard[j] == guard[v])
                                isBipartite = false;
                        }
                    }
                }
                if (isBipartite)
                    if (b)
                        ans += min(a, b);
                    else
                        ans += a;
            }
        }
        if (ans)
            printf("%d\n", ans);
        else
            printf("-1\n");
    }
};

int main(int argc, char const *argv[])
{
    freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        Solution s(n, m);
        s.getInput();
        s.solve();
    }
    return 0;
}
