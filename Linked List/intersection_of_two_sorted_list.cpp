#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};


Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

Node* findIntersection(Node* head1, Node* head2)
{
    Node*head=NULL,*tail=NULL;
    Node*temp1=head1,*temp2=head2;
    
    map<int,bool>m;
    while(temp1!=NULL)
    {
        m[temp1->data]=true;
        temp1=temp1->next;
    }
    
    while(temp2!=NULL)
    {
        if(m[temp2->data]==true)
        {
            Node*ptr=new Node(temp2->data);
            if(head==NULL)
            {
                head=ptr;
                tail=ptr;
            }
            else
            {
                tail->next=ptr;
                tail=ptr;
            }
            m[temp2->data]=false;
        }
        temp2=temp2->next;
    }
    return head;
}