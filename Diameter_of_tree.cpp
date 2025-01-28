#include<bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;
    Tree(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

void print(Tree *root)
{
    if(root==NULL) return;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

int diameter(Tree *root)
{
    if(root==NULL) return 0;
    return max(diameter(root->left),diameter(root->right))+1;
}

int main()
{
    int n;
    cin>>n;
    Tree *root=new Tree(n);
    queue<Tree*>q;
    q.push(root);
    while(!q.empty()){
        Tree *present=q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Tree *n1=NULL, *n2=NULL;
        if(x!=-1) n1=new Tree(x);
        if(y!=-1) n2=new Tree(y);
        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
        present->left=n1;
        present->right=n2;
    }
    print(root);
    cout<<endl;

    cout<<diameter(root)<<endl;

    return 0;
}

/**

2
5 3
-1 6 8 9
-1 -1 -1 -1 1 -1
-1 -1

*/
