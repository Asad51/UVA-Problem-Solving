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
    int n, path[201][201], color[201];
    int a, b;

public:
    Solution(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                path[i][j] = 0;
            color[i] = 0;
        }
    }

    void getInput()
    {
        int p, v;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &p);
            for (int j = 0; j < p; j++)
            {
                scanf("%d", &v);
                if (v > n)
                    continue;
                path[i][v - 1] = 1;
                path[v - 1][i] = 1;
            }
        }
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    void solve()
    {
        int a, b, ans = 0;
        bool isBipartite;
        Queue q;
        for (int i = 0; i < n; i++)
        {
            if (!color[i])
            {
                isBipartite = true;
                q.push(i);
                color[i] = 1;
                a = 1;
                b = 0;
                while (!q.empty())
                {
                    int j = q.top();
                    q.pop();
                    for (int v = 0; v < n; v++)
                    {
                        if (path[j][v])
                        {
                            if (!color[v])
                            {
                                color[v] = 3 - color[j];
                                if (color[v] == 1)
                                    a++;
                                else
                                    b++;
                                q.push(v);
                            }
                            else if (color[j] == color[v])
                                isBipartite = false;
                        }
                    }
                }
                if (isBipartite)
                    ans += max(a, b);
            }
        }

        printf("%d\n", ans);
    }
};

int main(int argc, char const *argv[])
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        Solution s(n);
        s.getInput();
        s.solve();
    }
    return 0;
}
