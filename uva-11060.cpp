#include <iostream>
#include <cstdio>
#include <cstring>

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
        Node *tmp = front->next;
        delete (front);
        front = tmp;
        siz--;
    }

    int top()
    {
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

class Beverages
{
    int n, m, len;
    int inDegree[101];
    char name[101][52];
    int visited[101];
    int path[101][101];

public:
    Beverages(int n)
    {
        this->n = n;
        len = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                path[i][j] = 0;
            visited[i] = inDegree[i] = 0;
        }
    }

    int stringCompare(char st1[], char st2[])
    {
        int i;
        for (i = 0; st1[i] && st2[i]; i++)
        {
            if (st1[i] != st2[i])
                return 0;
        }
        if (st1[i] != st2[i])
            return 0;
        return 1;
    }

    int searchString(char st[])
    {
        for (int i = 0; i < n; i++)
            if (stringCompare(st, name[i]))
                return i;
        return -1;
    }

    void getInput()
    {
        int x, y;
        char name1[52], name2[52];
        for (int i = 0; i < n; i++)
            scanf("%s", name[i]);
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%s %s", name1, name2);
            x = searchString(name1);
            y = searchString(name2);
            path[x][y] = 1;
        }
    }

    void solve(int cs)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (path[i][j])
                {
                    inDegree[j]++;
                }
        }
        printf("Case #%d: ", cs);
        printf("Dilbert should drink beverages in this order: ");
        Queue q;
        for (int i = 0; i < n; i++)
            if (inDegree[i] == 0)
            {
                q.push(i);
                break;
            }
        int t = 0;
        while (true)
        {
            while (!q.empty())
            {
                if (t)
                    printf(" ");
                int i = q.top();
                printf("%s", name[i]);
                visited[i] = 1;
                q.pop();
                for (int j = 0; j < n; j++)
                {
                    if (path[i][j])
                    {
                        path[i][j] = 0;
                        inDegree[j]--;
                    }
                }
                t++;
            }
            for (int j = 0; j < n; j++)
            {
                if (inDegree[j] == 0 && !visited[j])
                {
                    q.push(j);
                    break;
                }
            }
            if (q.empty())
                break;
        }
        printf(".\n\n");
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m, cs = 0;
    while (scanf("%d", &n) != EOF)
    {
        Beverages b(n);
        b.getInput();
        b.solve(++cs);
    }
    return 0;
}
