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
    ListNode* merge(ListNode* h1, ListNode* h2){
        if(h1==NULL && h2==NULL) return NULL;
        if(h1==NULL) return h2;
        if(h2==NULL) return h1;

        ListNode* res=new ListNode(0);
        ListNode* temp=res;
        while (h1 && h2) {
            if (h1->val <= h2->val) {
                temp->next = h1;
                h1 = h1->next;
            } else {
                temp->next = h2;
                h2 = h2->next;
            }
            temp = temp->next;
        }

        // Attach remaining nodes from either list
        if (h1) temp->next = h1;
        if (h2) temp->next = h2;
        return res->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        //important step
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* left=head;
        ListNode* right=slow;
        ListNode* temp=right->next;
        right->next=NULL;
        right=temp;
        ListNode* h1=sortList(left);
        ListNode* h2=sortList(right);

        //merge 2 sorted linked list
        return merge(h1, h2);
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
        cout << ob.sort(head) << endl;
    }
    return 0;
}
