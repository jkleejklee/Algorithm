#include <cstdio>
#include <cstring>
using namespace std;
struct node
{
    char name[31];  
    node *left, *right; 
    int cnt;    
    node() : left(0), right(0), cnt(1) {}
};
int n; 
void insert(node *&root, char *s)
{
    if (!root)
    {
        root = new node();
        strcpy(root->name, s);
    }
    else if (strcmp(s, root->name) == 0)
        (root->cnt)++;
    else if (strcmp(s, root->name) < 0)
        insert(root->left, s);
    else
        insert(root->right, s);
}
void inorder(node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%s %.4f\n", root->name, root->cnt * 100.0 / n);
        inorder(root->right);
    }
}
int main()
{
    char s[31];
    node *root = NULL;
    while (gets(s))
    {
        insert(root, s);
        n++;
    }
    inorder(root);
    return 0;
}
