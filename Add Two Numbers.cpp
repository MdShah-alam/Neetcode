#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};

ListNode* insert_at_tail(ListNode *head, int val)
{
    ListNode *newNode = new ListNode(val);
    if(head==NULL) return newNode;
    ListNode *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
    return head;
}

void print(ListNode* head)
{
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl<<endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode *dummyHead = new ListNode(0);
    ListNode* current = dummyHead;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry!=0){
        int sum=carry;
        if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        carry = sum/10;
        current->next=new ListNode(sum%10);
        current=current->next;
    }
    return dummyHead->next;
}
int main()
{
    ListNode* head1=NULL;
    ListNode* head2=NULL;
    for(int i=0;i<4;i++){
        int a;
        cin>>a;
        head1=insert_at_tail(head1,a);
    }
    for(int i=0;i<3;i++){
        int a;
        cin>>a;
        head2=insert_at_tail(head2,a);
    }
    print(head1);
    print(head2);


}
