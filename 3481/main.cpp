#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
struct node
{
    node *left, *right; 
    int k; 
    int p;  
    int r; 
    node(int a, int b, int c) : left(0), right(0), k(a), p(b), r(c) {}
};
void rightRotate(node *&a)
{
    node *b = a->left;
    a->left = b->right;
    b->right = a;
    a = b;
}
void leftRotate(node *&a)
{
    node *b = a->right;
    a->right = b->left;
    b->left = a;
    a = b;
}
void insertTreap(node *&root, int k, int p)
{
    if (!root)
        root = new node(k, p, rand());
    else if (p <= root->p)
    {
        insertTreap(root->left, k, p);
        if (root->left->r < root->r)
            rightRotate(root);
    }
    else
    {
        insertTreap(root->right, k, p);
        if (root->right->r < root->r)
            leftRotate(root);
    }
}
void deleteTreap(node *&root, int p)
{
    if (p == root->p)
    {
        if (!root->right)
            root = root->left;
        else if (!root->left)
            root = root->right;
        else
        {
            if (root->left->r < root->right->r)
            {
                rightRotate(root);
                deleteTreap(root->right, p);
            }
            else
            {
                leftRotate(root);
                deleteTreap(root->left, p);
            }
        }
    }
    else if (p < root->p)
        deleteTreap(root->left, p);
    else
        deleteTreap(root->right, p);
}
void findMax(node *&root)
{
    node *t = root;
    while (t->right)
        t = t->right;
    printf("%d\n", t->k);
    deleteTreap(root, t->p);
}
void findMin(node *&root)
{
    node *t = root;
    while (t->left)
        t = t->left;
    printf("%d\n", t->k);
    deleteTreap(root, t->p);
}
int main()
{
    srand(time(0));
    node *root = NULL;
    int r;
    while (scanf("%d", &r) && r)
    {
        switch (r)
        {
        case 1:
            int k, p;
            scanf("%d%d", &k, &p);
            insertTreap(root, k, p);
            break;
        case 2:
            if (root == NULL)
            {
                printf("0\n");
                break;
            }
            findMax(root);
            break;
        case 3:
            if (root == NULL)
            {
                printf("0\n");
                break;
            }
            findMin(root);
            break;
        }
    }
    return 0;
}
