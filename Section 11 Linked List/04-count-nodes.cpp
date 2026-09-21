#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

Node * getnode(int);
void BuildList(int[],int);
void Display(Node *);
int TotalNodes(Node *);

int main(){

    int arr[] = { 2,5,6,3,4,3,9,75,65,42};
    int size = sizeof(arr)/sizeof(arr[0]);

    BuildList(arr,size);
    Display(head);

    int totalnodes = TotalNodes(head);

    cout << "Total nodes in the list is : " << totalnodes << endl;

    return 0;
}

int TotalNodes(Node *h){
    int count = 0;
    while (h)
    {
        count++;
        h=h->next;
    }
    return count;
}

void BuildList(int arr[],int n){
    if(n<=0){
        return;
    }

    Node * last = getnode(arr[0]); //first node
    head = last;

    for(int i = 1; i < n; i++){
        last->next = getnode(arr[i]);
        last = last->next;
    }
    
}

Node * getnode(int x){
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    
    return temp;
}

void Display(Node *h){
    while (h)
    {
        cout << h->data << " -> ";
        h =  h->next;
    }

    cout << "\n";
    
}
