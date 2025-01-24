#include<bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;
    Tree(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

void print(Tree *root)
{
    if(root==NULL) return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);

}

Tree *linked_list(Tree* root)
{
    if(root==NULL)
        return NULL;
    Tree* left=linked_list(root->left);
    Tree* right=linked_list(root->right);
    root->left=right;
    root->right=left;
    return root;
}

int main()
{
    Tree *root=NULL;
    int n;
    cin>>n;
    root=new Tree(n);
    queue<Tree*>q;
    q.push(root);
    while(!q.empty()){
        Tree *present=q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Tree *n1=NULL,*n2=NULL;
        if(x!=-1) n1=new Tree(x);
        if(y!=-1) n2=new Tree(y);
        present->left=n1;
        present->right=n2;
        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }
    print(root);
    root = linked_list(root);
    cout<<endl<<endl;
    print(root);
}
/**

1
2 3
4 5 6 7
-1 -1 -1 -1 -1 -1 -1 -1

*/
