#include <iostream>
using namespace std;

class Node{
    public :
    int data;
    Node *next;
};

class LinkedList{
    Node *first;

    public :
    LinkedList(){
        // first = NULL;
    }

    void create(int[],int);
    void display();
    void Rdisplay(Node *p);
    void RPrint(){
        Rdisplay(first);
    }   
};

void LinkedList :: create(int A[], int n){
    if(n == 0){
        first = NULL;
        return ;
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
    Node *temp = first;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void LinkedList :: Rdisplay(Node *p){
    if(p != NULL){
        cout << p->data << " -> ";
        Rdisplay(p->next);
    }else {

        cout << "NULL" << endl;
    }

}

int main(){

    int A[5] = {10,20,30,40,50};
    int n = sizeof(A)/sizeof(int);

    LinkedList lt1;
    lt1.create(A,n);
    lt1.display();
    cout << "\n------\n";
    lt1.RPrint();


    return 0;
}