#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;
};


Node * head;

Node * getnode(int);
void createList(int[],int);
void Display(Node *);
int countNode(Node *);
int countOccurance(Node *,int);

int main(){
    int arr[] = {2,6,7,3,9,14,45};
    // int arr[] = {2,6,7,3,9,14};


    int size = sizeof(arr)/sizeof(arr[0]);

    createList(arr,size);
    Display(head);

    return 0;
}

void createList(int arr[],int n){

    if(n<=0){
        head = nullptr;
        return;
    }

    Node * last = getnode(arr[0]);
    head = last;

    for(int i = 1; i < n; i++){
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

int countNode(Node * t){
    int count = 0;
    while (t)
    {   
        count++;
        t=t->next;
    }
    
    return count;
}

void Display(Node * t){
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