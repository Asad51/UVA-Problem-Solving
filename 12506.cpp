#include <stdio.h>
#define MAX_CHILD 26
#define MAX_CHAR 1000001

struct TrieNode
{
    int personCount;
    TrieNode *nodes[MAX_CHILD];
    TrieNode()
    {
        personCount = 1;
        for (int i = 0; i < MAX_CHILD; i++)
            nodes[i] = nullptr;
    }
};

class Trie
{
    TrieNode *rootNode;

public:
    Trie()
    {
        rootNode = new TrieNode();
    }

    void insertName(char name[MAX_CHAR])
    {
        TrieNode *tmp = rootNode;
        int i = 0;
        while (name[i])
        {
            int index = name[i++] - 'a';
            if (!tmp->nodes[index])
                tmp->nodes[index] = new TrieNode();
            else
                tmp->nodes[index]->personCount++;
            tmp = tmp->nodes[index];
        }
    }

    int numberOfPrefix(TrieNode *root)
    {
        int totalCharacterUsed = 0;
        for (int i = 0; i < MAX_CHILD; i++)
        {
            if (!root->nodes[i])
                continue;
            if (root->nodes[i]->personCount == 1)
                totalCharacterUsed++;
            else
            {
                totalCharacterUsed += root->nodes[i]->personCount + numberOfPrefix(root->nodes[i]);
            }
        }
        return totalCharacterUsed;
    }

    int findTotalCharacterUsed()
    {
        return numberOfPrefix(rootNode);
    }

    ~Trie()
    {
        delete (rootNode);
    }
};

int main(int argc, char const *argv[])
{
    //freopen("in.txt", "r", stdin);
    int t, n;
    char name[MAX_CHAR];
    scanf("%d", &t);
    while (t--)
    {
        Trie *trie = new Trie();
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", name);
            trie->insertName(name);
        }
        printf("%d\n", trie->findTotalCharacterUsed());
        delete (trie);
    }
    return 0;
}
