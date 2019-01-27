#include<bits/stdc++.h>
using namespace std;

struct node
{
    int b, h;
    node *left, *right;
};

node* create_node(int k)
{
    node *x = (node *)malloc(sizeof(node));
    x->b = k;
    x->h = rand();
    x->left = x->right = NULL;

    return x;
}

void split(node *T, node **L, node **R, int x)
{
    node *TL;
    node *TR;

    if(T == NULL)
    {
        *L = *R = NULL;
    }
    else if(T->b < x)
    {
        split(T->right, &TL, &TR, x);

        T->right = TL;
        *L = T;
        *R = TR;
    }
    else
    {
        split(T->left, &TL, &TR, x);

        T->left = TR;
        *R = T;
        *L = TL;
    }
}

void print(node *T)
{
    if(T == NULL)
        return;

    print (T->left);
    cout<< T->b <<endl;
    print(T->right);
}

int main()
{
    node *T = create_node(3);

    cout<<"Printing Tree : "<<endl;
    print(T);

    node *L, *R;
    split(T, &L, &R, 4);
    cout<<"Printing L : "<<endl;
    print(L);
    cout<<"Printing R : "<<endl;
    print(R);

    return 0;
}
