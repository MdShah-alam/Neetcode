#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

vector<int>rightSideView(Node *root)
{
    vector<int>v;
    if(root==NULL) return v;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *rightSide=NULL;
        int qlen=q.size();
        for(int i=0;i<qlen;i++){
            Node *node=q.front();
            q.pop();
            if(node!=NULL){
                rightSide=node;
                q.push(node->left);
                q.push(node->right);
            }
        }
        if(rightSide!=NULL)
            v.push_back(rightSide->val);
    }
    return v;
}

int main()
{
    int n;
    cin>>n;
    Node *root=new Node(n);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int x,y;
        cin>>x>>y;
        Node *r1=NULL , *r2=NULL;
        Node *r=q.front();
        q.pop();
        if(x!=-1) r1=new Node(x);
        if(y!=-1) r2=new Node(y);
        if(r1!=NULL) q.push(r1);
        if(r2!=NULL) q.push(r2);
        r->left=r1;
        r->right=r2;
    }
    vector<int>v=rightSideView(root);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;

    return 0;
}/**

1
2 3
6 4 -1 -1
-1 -1 -1 -1

*/
