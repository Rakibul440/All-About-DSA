#include <iostream>
using namespace std;


struct Node{
    int data;
    Node * next;
};

Node * head ;

Node * getnode(int);
void BuildList(int[],int);
void Display(Node *);
void deleteFirst(Node *);

void deleteFirst(Node *h){
    if(!h){
        cout << "No node exist!";
        return;
    }
    head = h->next;
    delete(h);
}


int main(){

    int arr[] = {3,89,1,6,76,7};
    int size = sizeof(arr)/sizeof(arr[0]);

    BuildList(arr,size);
    Display(head);

    deleteFirst(head);
    Display(head);

    deleteFirst(head);
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

    for(int i = 1 ; i < n ; i++){
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
    while (t)
    {
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << "\n";
}