#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;
};

Node *head;

Node * getnode(int);
void BuildList(int[],int);
void Display(Node *);
void InsertXafterY(Node *,int,int);

void InsertXafterY(Node * h,int y, int x){
    Node * p = getnode(x);

    if(h==nullptr){
        head = p;
        return;
    }

    while (h->next != nullptr && h->data != y)
    {
        h = h->next;
    }

    if(h->data != y){
        cout << "Y not found! Please Provide Exsistance Element!" << endl;
        delete p;
        return;
    }

    p->next = h->next;
    h->next = p;
    
}

int main(){

    int arr[] = {2,89,3,41,3,4,62};
    int size = sizeof(arr)/sizeof(arr[0]);

    BuildList(arr,size);
    Display(head);

    InsertXafterY(head,100,100);
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

    for(int i = 1; i < n ; i++){
        last->next = getnode(arr[i]);
        last = last->next;
    }
}

Node * getnode(int x ){
    Node * temp = new Node;
    temp->data = x;
    temp->next = nullptr;

    return temp;
}

void Display(Node * t){
    while (t)
    {
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << "\n";
}