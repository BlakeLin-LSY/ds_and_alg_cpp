#include <stdio.h>
#include <stdlib.h>
#define M 8
typedef struct node {
    char val;
    struct node *subTree[M];
} NODE;

char buf[255], *str=buf;
NODE *d = NULL;

NODE *makeTree() // generate M-tree from list
{
    int k; NODE *s;
    s = new NODE;
    s->val = *str++;
    for (k=0; k<M; k++)
        s->subTree[k] = NULL;
    if (*str == '(' ) {
        k = 0;
        do {
            str++;
            s->subTree[k] = makeTree();

            if ( *str == ')' ) { str++; break; }
            k = k+1;
        } while (*str != '\0');
    }
    return s;
}

void walkTree (NODE* t) // output list from M-tree
{
    int i;
    if ( t != NULL ) {
        putchar(t->val);

        if (t->subTree[0] == NULL) return;
        putchar('(');

        for (i=0; i<M; i++) {
            walkTree(t->subTree[i]);

            if ( i != M-1 && t->subTree[i+1] != NULL)
                putchar(',');
        }
        putchar(')');
    }
}

int main()
{
    printf("Enter exp:");
    scanf("%s", str);
    d = makeTree();
    walkTree(d);
    putchar('\n');
    return 0;
}