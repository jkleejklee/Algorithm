#include <cstdio>
using namespace std;
struct node
{
    char data[200][200];
    int top;
} * F, *B, f, b;
void push(node *s, char x[])
{
    int i;
    s->top++;
    for (i = 0; x[i]; i++)
        s->data[s->top][i] = x[i];
    s->data[s->top][i] = '\0';
}
void pop(node *s, char URL[])
{
    int i;
    if (s->top)
    {
        for (i = 0; s->data[s->top][i]; i++)
            URL[i] = s->data[s->top][i];
        URL[i++] = '\0';
        s->top--;
    }
}
void visit(char URL[])
{
    push(B, URL);
    F->top = 0;
    scanf("%s", URL);
    puts(URL);
}
void Back(char URL[])
{
    if (!B->top)
        puts("Ignored");
    else
    {
        push(F, URL);
        pop(B, URL);
        puts(URL);
    }
}
void Forward(char URL[])
{
    if (!F->top)
        puts("Ignored");
    else
    {
        push(B, URL);
        pop(F, URL);
        puts(URL);
    }
}
int main()
{
    F = &f;
    B = &b;
    char URL[100] = "http://www.acm.org/";
    char C[10];
    B->top = 0;
    while (scanf("%s", C) && C[0] != 'Q')
    {
        if (C[0] == 'B')
            Back(URL);
        if (C[0] == 'F')
            Forward(URL);
        if (C[0] == 'V')
            visit(URL);
    }
    return 0;
}
