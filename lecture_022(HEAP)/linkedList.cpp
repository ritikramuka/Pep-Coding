#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node()
    {
        this->data=0;
        this->next=NULL;
    }
    Node(int data,Node* next)
    {
        this->data=data;
        this->next=next;
    }
};

void addLast(Node*& head,Node*& tail,int data)
{
    if(head==NULL)
    {
        head=tail=new Node(data,NULL);
    }
    else
    {
        Node* nn=new Node(data,NULL);
        tail->next=nn;
        tail=nn;
    }
}

void Display(Node* head)
{
    for(Node* i=head;i!=NULL;i=i->next)
    {
        cout<<i->data<<" ";
    }
    cout<<endl;
}

int getSize(Node* head)
{
    int counter=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        counter++;
        temp=temp->next;
    }
    return counter;
}

void addFirst(Node*& head,Node*& tail,int data)
{
    if(head==NULL)
    {
        head=tail=new Node(data,NULL);
    }
    else
    {
        head=new Node(data,head);
        //Node* nn=new Node(data,head);
        //head=nn;
    }
}

int getFirst(Node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        return head->data;
    }
}

int getLast(Node* tail)
{
    if(tail==NULL)
    {
        return 0;
    }
    else
    {
        return tail->data;
    }
}

int getAt(Node* head,int idx)
{
    if(head==NULL)
    {
        return 0;
    }
    int j=0;
    for(Node* i=head;i!=NULL;i=i->next)
    {
        if(j==idx)
        {
            return i->data;
        }
        j++;
    }
    return 0;
}

Node* getNodeAt(Node* head,int idx)
{
    if(head==NULL)
    {
        return NULL;
    }
    int j=0;
    for(Node* i=head;i!=NULL;i=i->next)
    {
        if(j==idx)
        {
            return i;
        }
        j++;
    }
    return NULL;
}

void addAt(Node*& head,Node*& tail,int data,int idx)
{
    int sz=getSize(head);
    if(idx < 0 || idx>sz)
    {
        cout<<"invalid index"<<endl;
    }
    else if(idx==0)
    {
        addFirst(head,tail,data);
    }
    else if(idx==sz)
    {
        addLast(head,tail,data);
    }
    else
    {
        Node*nm1=getNodeAt(head,idx-1);
        nm1->next=new Node(data,nm1->next);
    }
}

void removeFirst(Node*& head,Node*& tail)
{
    if(head==NULL)
    {
    }
    else if(head->next==NULL)
    {
        Node* temp=head;
        head=tail=NULL;
        delete temp;
    }
    else
    {
        Node*temp2=head;
        head=head->next;
        delete temp2;
    }
}

void removeLast(Node*& head,Node*& tail)
{
    if(head==NULL)
    {
        cout<<"EMPTY";
    }
    else if(head->next==NULL)
    {
        Node* temp=head;
        head=tail=NULL;
        delete temp;
    }
    else
    {
        int sz=getSize(head);
        Node* sl=getNodeAt(head,sz-2);

        sl->next=NULL;
        delete tail;
        tail=sl;
    }
}

void removeAt(Node*&head,Node*&tail,int idx)
{
    int sz=getSize(head);
    if(idx<0 || idx>=sz )
    {
        return;
    }
    else if(sz==1)
    {
        removeFirst(head,tail);
    }
    else if(sz==idx-1)
    {
        removeLast(head,tail);
    }
    else
    {
        Node *m1=getNodeAt(head,idx-1);
        Node* n=m1->next;
        Node* p1=n->next;

        m1->next=p1;
        delete n;
    }
}

//n^2
void reverseDI(Node*head,Node*tail)
{
    int li=0;
    int ri=getSize(head)-1;

    while(li<ri)
    {
        Node* left=getNodeAt(head,li);
        Node* right=getNodeAt(head,ri);

        int temp=right->data;
        right->data=left->data;
        left->data=temp;

        li++;
        ri--;        
    }
}

void reversePI(Node*& head,Node*& tail)
{
    Node* prev=NULL;
    Node* curr=head;

    while(curr!=NULL)
    {
        Node* next=curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;
    }

    Node* temp=head;
    head=tail;
    tail=temp;
}

//n
void displayReverseRecursive(Node* head)
{
    if(head->next==NULL)
    {
        cout<<head->data<<" ";
        return;
    }

    displayReverseRecursive(head->next);
    cout<<head->data<<" ";
}

//n
// void reversepointersRecursive(Node* head,Node*& tail)
// {
    
// }

//n
void reverseDR(Node*& left,Node* right,int floor,int& size)
{
    if(right==NULL)
    {
        return;
    }

    size++;
    reverseDR(left,right->next,floor+1,size);

    if(floor>=size/2)
    {
        int temp=right->data;
        right->data=left->data;
        left->data=temp;

        left=left->next;
    }
}

bool IsPalendrome(Node*& head,Node* tail,int floor,int& size)
{
    if(tail==NULL)
    {
        return false;
    }
    size++;
    bool flag=IsPalendrome(head,tail->next,floor+1,size);
    if(floor>=size/2)
    {
        if(head->data!=tail->data || !flag)
        {
            flag=false;
        }
        else
        {
            flag=true;
        }
        head=head->next;
    }
    return flag;
}

void Fold(Node*right,Node*&left,int& s,int f,Node*&tail)
{
    if(right==NULL)
    {
        return;
    }
    s++;
    Fold(right->next,left,s,f+1,tail);
    if(f>s/2)
    {
        Node* temp=left->next;
        left->next=right;
        right->next=temp;
        left=temp;
    }
    else if(f==s/2)
    {
        tail=right;
        tail->next=NULL;
    }
}


//for next two funct. no space no size no recur no getNodeAt

void midNode(Node* head)
{
    
}

int kthfromlast(Node* head,int k)
{

}

int main(int args,char** argv)
{
    Node* head=NULL;
    Node* tail=NULL;


    addAt(head,tail,100,0);
    // removeFirst(head,tail);
    addFirst(head,tail,70);
    // removeLast(head,tail);
    addLast(head,tail,10);
    addLast(head,tail,20);
    addLast(head,tail,30);
    addLast(head,tail,40);
    addLast(head,tail,50);
    addFirst(head,tail,60);;
    addAt(head,tail,1000,8);
    addAt(head,tail,200,3);
    // removeAt(head,tail,3);

    Display(head);
    // reverseDI(head,tail);
    // Display(head);
    // reversePI(head,tail);
    // Display(head);
    // displayReverseRecursive(head);
    Node* left=head;
    Node* right=head;
    int floor=0;
    int size=0;
    // reverseDR(left,right,floor,size);
    // bool flag=IsPalendrome(left,right,floor,size);
    // if(flag==true)
    //     cout<<"palen";
    // else
    //     cout<<"not palen";
    // Display(head);
    Fold(right,left,size,floor,tail);
    addLast(head,tail,17);
    Display(head);    
}