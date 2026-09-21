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
int SumOfNodes(Node *);


int main(){
    int arr[] = {1,9,3,34,93,72,100,8};
    int size = sizeof(arr)/sizeof(arr[0]);

    BuildList(arr,size);
    Display(head);

    int totalsum = SumOfNodes(head);

    cout << "Total sum of all nodes is : " << totalsum << endl;

    return 0;
}

int SumOfNodes(Node *t){
    int sum = 0;
    while (t)
    {
        sum += t->data;
        t = t->next;
    }
    
    return sum;
}

void BuildList(int arr[],int n){
    if(n<=0){
        return;
    }

    Node *last = getnode(arr[0]) ; //first node;
    head = last;

    for(int i = 1; i < n ; i++){
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
        h = h->next;
    }
    cout << "\n";
}