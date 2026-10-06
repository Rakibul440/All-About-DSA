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

Node * FindEnd_NthNode(Node *,int);

int main(){
    int arr[] = {2,6,7,3,9,14,45};
    // int arr[] = {2,6,7,3,9,14};


    int size = sizeof(arr)/sizeof(arr[0]);

    createList(arr,size);
    Display(head);

    Node * nth_end_node = FindEnd_NthNode(head,7);

    cout << "Nth Node From End : " << "\n"
    << "Address : " << nth_end_node << " Data : " << nth_end_node->data << "\n";

    return 0;
}

Node * FindEnd_NthNode(Node * t,int n){
    if(!t){
        return nullptr;
    }

    int totalnode = countNode(t);
    int targetIndex = totalnode - n  + 1;

    int i = 1;
    while (i != targetIndex)
    {
        t = t->next;
        i++;
    }
    
    return t;
    
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