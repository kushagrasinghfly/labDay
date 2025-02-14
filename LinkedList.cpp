#include<iostream>

using namespace std;

class node
{
    public:
        int item;
        node *next;
};

class SLL
{
    private:
        node *start;
    public:
        SLL();
        void insertAtBeg(int);
        void insertAtEnd(int);
        void insertAtIndex(int,int);
        void deleteFront();
        void deleteRear();
        void deleteAtIndex(int);
};

SLL::SLL()
{
    start=nullptr;
}

void SLL::insertAtBeg(int data)
{
    node *naya= new node;
    naya->item=data;
    naya->next=start;
    start=naya;
}
void SLL::insertAtEnd(int data)
{
    node *naya=new node;
    naya->item=data;
    naya->next=nullptr;
    if(start==nullptr)
        start=naya;
    else
    {
        node *temp=start;
        node *temp=start;
        while(temp->next!=nullptr)
            temp=temp->next;
        temp->next=naya;
    }
}
void SLL::insertAtIndex(int idx,int data)
{
    node *naya=new node;
    naya->item=data;
    naya->next=nullptr;
    node *temp=start;
    for(int i=2;i<idx;i++)
        temp=temp->next;
    naya->next=temp->next;
    temp->next=naya;
    
}
void SLL::deleteFront()
{
    if(start!=nullptr)
    {
        node *lol=start;
        start=start->next;
        delete lol;
    }
}
void SLL::deleteRear()
{
    node *temp=start;
    while(temp->next->next!=nullptr)
        temp=temp->next;
    node *lol=temp->next;
    temp->next=nullptr;
    delete lol;
}
void SLL::deleteAtIndex(int idx)
{
    node *temp=start;
    for(int i=1;i<idx;i++)
        temp=temp->next;
    
}
