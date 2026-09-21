#include <iostream>
using namespace std;

// struct Node {
//     int data;
//     Node *next;
// };

class Node {
    public :
    int data;
    Node *next;
};

class LinkedList{

    Node *first;

    public :

    LinkedList(int A[], int n){
        create(A,n);
        display();
    }

    void create(int[], int);
    void display();
};

void LinkedList ::create(int A[],int n){

    if(n==0){
        first = NULL;
        return;
    }

    Node *temp, *last;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < n ; i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        
        last->next = temp;

       last = temp;
    }
}

void LinkedList :: display(){
    Node *t = first;
    while(t != NULL){
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << "NULL";
}

int main(){
    int A[] = {1,8,6,3,9,7,1};
    int n = sizeof(A)/sizeof(int);
    LinkedList list = LinkedList(A,n);

    cout << "\n----------------\n";
    list.display();
    return 0;
}