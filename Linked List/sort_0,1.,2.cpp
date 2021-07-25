#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
       Node*temp=head;
       int count0=0,count1=0,count2=0;
       while(temp!=NULL)
       {
           if(temp->data==0)
           {
              count0++; 
           }
           else if(temp->data==1)
           {
               count1++;
           }
           else if(temp->data=2)
           {
               count2++;
           }
           temp=temp->next;
       }
       Node*p=new Node(0);
       head=p;
       Node*tail=p;
       while(count0-->1)
       {
          Node*newnode=new Node(0);
          tail->next=newnode;
          tail=newnode;
       }
       while(count1--)
       {
           Node*newnode=new Node(1);
           tail->next=newnode;
           tail=newnode;
       }
       while(count2--)
       {
           Node*newnode=new Node(2);
           tail->next=newnode;
            tail=newnode;
       }
       return head;
        
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  