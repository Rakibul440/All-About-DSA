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
pair <Node *,Node *> findMiddleNode(Node *);

int main(){
    // int arr[] = {2,6,7,3,9,14,45};
    int arr[] = {2,6,7,3,9,14};


    int size = sizeof(arr)/sizeof(arr[0]);

    createList(arr,size);
    Display(head);

    pair <Node *,Node *> middleNode = findMiddleNode(head);

    if(middleNode.second != nullptr){
        cout << "Two middle node found : " << "\n"
        << "1. Address : " << middleNode.first << " Data : " << middleNode.first->data << "\n"
        << "2. Address : " << middleNode.second << " Data : " << middleNode.second->data << "\n";
    }
    else{
        cout << "The Middle node is : " << "\n"
        << "Address : " << middleNode.first << " Data : " << middleNode.first->data << "\n";
    };

    return 0;
}

pair <Node *,Node *> findMiddleNode(Node * t){

    int totalNode = countNode(t);
    cout << "Total Node : " << totalNode << endl;

    int i = 0;
    while (i != (totalNode - 1 )/2)
    {
        i++;
        t = t->next;
    }
    

    if(totalNode % 2 == 0){
        return {t,t->next};
    }

    return {t,nullptr};
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