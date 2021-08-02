#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;


struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



class Solution{
  public:
    int size(Node*head)
    {
        return head==NULL?0:size(head->next)+1;
    }
    Node* reverse(Node*head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        Node*temp=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
    bool isPalindrome(Node *head)
    {
        int s=size(head);
        Node*temp=head;
        int mid=0;
        if(s%2==0)
        {
            mid=s/2-1;
        }
        else
        mid=s/2;
        for(int i=0;i<mid;i++)
        {
            temp=temp->next;
        }
        Node*ptr=temp->next;
        temp->next=NULL;
        ptr=reverse(ptr);
        temp=head;
        while(ptr!=NULL && temp!=NULL)
        {
            if(temp->data!=ptr->data)
            {
                return false;
            }
            temp=temp->next;
            ptr=ptr->next;
        }
        return true;
    }
};

int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}