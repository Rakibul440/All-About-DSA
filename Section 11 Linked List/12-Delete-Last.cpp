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
void deleteLast(Node *);

void deleteLast(Node *h){
    Node * sp = nullptr;

    // case empty node
    if(!h){
        cout << "No node exist!";
        return;
    }

    // case single node
    if(h->next == nullptr){
        head = nullptr;
        delete(h);
        return;
    }

    while (h && h->next != nullptr)
    {   
        sp = h;
        h = h->next;
    }
    
    if(sp!=nullptr) sp->next = nullptr;
    delete(h);
}


int main(){

    int arr[] = {1,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);

    BuildList(arr,size);
    Display(head);

    deleteLast(head);
    Display(head);

    
    deleteLast(head);
    Display(head);

    deleteLast(head);
    Display(head);

    deleteLast(head);
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