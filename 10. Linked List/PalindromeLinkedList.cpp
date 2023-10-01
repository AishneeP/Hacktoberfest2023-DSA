#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode* next;
    
    ListNode(int x){
        val = x;
        next = NULL;
    }
};

void printList(ListNode* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* prev=NULL;

        while(temp!=NULL){
            ListNode* nxt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxt;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        //edge case when the linked list has 0 or 1 node
        if(head==NULL || head->next==NULL) return true;

        //find the length of the linked list to check palindrome accordingly
        int len=0;
        ListNode* temp=head;
        // while(temp!=NULL){
        //     len++;
        //     temp=temp->next;
        // }

        //get the middle of the linked list
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        //reverse the right LinkedList
        ListNode* check;
        // if(len%2==0) check=reverse(slow);
        // else check=reverse(slow->next);
        check=reverse(slow);

        //start checking
        ListNode* start=head;
        if(head==NULL) return false;
        while(start!=slow){
            if(start->val!=check->val) return false;
            start=start->next;
            check=check->next;
        }

        return true;
    }
};

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        cout << ob.isPalindrome(head) << endl;
    }
    return 0;
}
