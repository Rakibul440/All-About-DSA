#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head;

Node * getnode(int);
void BuildList(int[],int);
void Display(Node *);
void InsertEnd(int,Node *);

void InsertEnd(int x, Node *h){
    Node *p = getnode(x);

    // if empty add to head pointer
    if(h==NULL){
        head = p;
        return;
    }

    while (h && h->next != NULL)
    {
        h = h->next;
    }

    h->next = p;
    
};


int main(){

    int arr[] = {2,8,34,92,10,23};

    int size = sizeof(arr)/sizeof(arr[0]);

    BuildList(arr,size);
    Display(head);

    InsertEnd(100,head);
    Display(head);


    return 0;
}


Node * getnode(int x){
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;

    return temp;
}

void BuildList(int arr[],int n){
    if(n<=0){
        head = NULL;
        return;
    }

    Node * last = getnode(arr[0]);
    head = last;

    for(int i = 1 ; i < n; i++){
        last->next = getnode(arr[i]);
        last = last->next;
    }
    
}


void Display(Node *h){
    while (h)
    {
        cout << h->data << " -> " ;
        h = h->next;
    }
    cout << "\n";

}