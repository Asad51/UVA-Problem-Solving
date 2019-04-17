#include <cstdio>

struct Node
{
    int val;
    Node *next;
    Node *prev;
    Node(int x) : val(x), next(NULL), prev(NULL) {}
};

class Stack
{
    int siz;
    Node *current;

public:
    Stack()
    {
        current = NULL;
        siz = 0;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (current == NULL)
            current = newNode;
        else
        {
            newNode->prev = current;
            current->next = newNode;
            current = newNode;
        }
        siz++;
    }

    void pop()
    {
        Node *tmp = current->prev;
        delete (current);
        current = tmp;
        siz--;
    }

    int top()
    {
        return current->val;
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

class Dominos
{
    int n, m, l, u, v;
    Stack ds[10001];
    int q, cnt, query[10001], check[10001];

public:
    Dominos(int n, int m, int l)
    {
        this->n = n;
        this->m = m;
        this->l = l;
        for (int i = 0; i <= n; i++)
            check[i] = 0;
        cnt = 0;
        for (int i = 0; i <= n; i++)
            ds[i].push(i);
    }

    void getInput()
    {
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            ds[u].push(v);
        }

        for (int i = 0; i < l; i++)
        {
            scanf("%d", &q);
            dfs(q);
        }
        printf("%d\n", cnt);
    }

    void dfs(int u)
    {
        while (!ds[u].empty())
        {
            int v = ds[u].top();
            ds[u].pop();
            if (!check[v])
            {
                check[v] = 1;
                cnt++;
                dfs(v);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int t, m, n, l;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %d", &n, &m, &l);
        Dominos d(n, m, l);
        d.getInput();
    }

    return 0;
}