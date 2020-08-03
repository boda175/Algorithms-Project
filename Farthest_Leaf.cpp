#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x;
    node* left;
    node* right;
};

struct solution
{
    int where;
    int height;
};

node *tree[1000];
solution sol[1000];
int n;

void make_tree()
{
    int first,second;
    for(int i=1;i<=n;i++)
    {
        cin>>first;
        if(first!=-1)
        {
            tree[i]->left=tree[first];
        }
        cin>>second;
        if(second!=-1)
        {
            tree[i]->right=tree[second];
        }
    }
}

solution height_where(node *root)
{
    if(root==NULL)
    {
        return {-1,-1};
    }
    if(root->left==NULL && root->right==NULL)
    {
        sol[root->x].height=0;
        sol[root->x].where=root->x;
        return sol[root->x];
    }
    else
    {
        solution first=height_where(root->left);
        solution second=height_where(root->right);
        sol[root->x].height=1+max(first.height,second.height);
        if(first.height>=second.height)
        {
            sol[root->x].where=first.where;
        }
        else
        {
            sol[root->x].where=second.where;
        }
    }
    return sol[root->x];
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        tree[i]=new node();
        tree[i]->x=i;
        tree[i]->left=tree[i]->right=NULL;
    }
    make_tree();
    height_where(tree[1]);
    for(int i=1;i<=n;i++)
    {
        cout<<sol[i].where<<" "<<sol[i].height<<endl;
    }
    return 0;
}
