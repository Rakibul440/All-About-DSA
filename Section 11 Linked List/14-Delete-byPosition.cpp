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
void DeleteByPosition(Node * ,int);

// Assumed position start from 1,2.. like array
void DeleteByPosition(Node * t,int pos){
    Node * sp;

    // empty node
    if(!t){
        head = nullptr;
        return;
    }

    // first node - head change
    if(pos == 1){
        head = t->next;
        delete(t);
        return;
    }

    int i = 1;
    while (i != pos && t->next != nullptr)
    {   
        sp = t;
        t = t->next;
        i++;
    }
    
    if(i==pos){
        sp->next = t->next;
        delete(t);
    }else{
        cout << "Invalid Position!\n";
    }
    
}

int main(){
    int arr[] = {2,8,9,74};
    int size = sizeof(arr)/sizeof(arr[0]);

    BuildList(arr,size);
    Display(head);


    DeleteByPosition(head,1);
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