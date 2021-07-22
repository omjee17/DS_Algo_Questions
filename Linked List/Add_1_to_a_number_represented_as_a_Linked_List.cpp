#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


class Solution
{
    public:
    Node*rev(Node*head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        Node*temp=rev(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
    Node* addOne(Node *head) 
    {
        Node*ptr=rev(head);
        int carry=0,sum=0;
        
        Node*temp=ptr;
        carry=(temp->data+1)/10;
        temp->data=(temp->data+1)%10;
        temp=temp->next;
        while(temp!=NULL)
        {
            sum=carry+temp->data;
            temp->data=(sum)%10;
            carry=sum/10;
            temp=temp->next;
        }
        
        if(carry>0)
        {
            head=rev(ptr);
            Node*newNode=new Node(carry);
            newNode->next=head;
            return newNode;
        }
        
        return rev(ptr);
        
    }
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 