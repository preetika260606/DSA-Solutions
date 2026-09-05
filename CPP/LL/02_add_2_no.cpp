#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode (int x):val(x),next(nullptr){}
};

ListNode* addTwoNumber(ListNode * l1,ListNode * l2){
    ListNode * dummy =new ListNode(0);
    ListNode * curr=dummy;
    int carry=0;

    while(l1!=nullptr || l2!=nullptr || carry!=0){
        int sum=carry;
        if(l1!=nullptr){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=nullptr){
            sum+=l2->val;
            l2=l2->next;
        }
        carry=sum/10;
        curr->next=new ListNode(sum%10);
        curr=curr->next;
    }
    return dummy->next;
}
int main(){

    int n1,n2;
    cin>>n1;

    ListNode * l1=new ListNode(0);
    ListNode *curr=l1;

    for(int i=0;i<n1;i++){
        int x;
        cin>>x;
        curr->next=new ListNode(x);
        curr=curr->next;
    }

    cin>>n2;

    ListNode * l2=new ListNode(0);
    curr=l2;

    for(int i=0;i<n2;i++){
        int x;
        cin>>x;
        curr->next=new ListNode(x);
        curr=curr->next;
    }
    ListNode * res=addTwoNumber(l1->next,l2->next);
    while(res!=nullptr){
        cout<<res->val<<" ";
        res=res->next;
    }
    return 0;
    

}