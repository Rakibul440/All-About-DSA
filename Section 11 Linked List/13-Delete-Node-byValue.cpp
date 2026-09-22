#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
};

Node * head;

Node * getnode(int);
void BuildList(int[],int);
void Display(Node *);
void Delete(Node * ,int);

void Delete(Node *t,int x){
    Node *sp;

    // case empty node
    if(!t){
        cout << "No node exist!";
        return;
    }

    if(t->data == x){
        head = t->next;
        delete(t);
        return;
    }

    while (t->next != nullptr && t->data != x)
    {   
        sp = t;
        t=t->next;
    }
    if(t->data == x){
        sp->next = t->next;
        delete(t);
    }else{
        cout << "Element not found to delete!\n";
    }
    
}

int main(){
    int arr[] = {2,8,9,74};
    int size = sizeof(arr)/sizeof(arr[0]);

    BuildList(arr,size);
    Display(head);

    Delete(head,5);
    Display(head);

    // first node
    Delete(head,2);
    Display(head);

    // not present  node
    Delete(head,5);


    // last node
    Delete(head,74);
    Display(head);

    Delete(head,8);
    Display(head);

    return 0;
}

void BuildList(int arr[],int n){
    if(n<=0){
        head = nullptr;
        return;
    }

    Node * last = getnode(arr[0]);
    head = last;

    for (int i = 1; i < n; i++)
    {
        last->next = getnode(arr[i]);
        last = last->next;
    }
    
}

Node * getnode(int x){
    Node * temp = new Node;
    temp->data = x;
    temp->next = nullptr;

    return temp;
}

void Display(Node *t){
    if(!t){
        cout << "No Node Exist to Display" << endl;
        return;
    }
    while (t)
    {
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << "\n";
}