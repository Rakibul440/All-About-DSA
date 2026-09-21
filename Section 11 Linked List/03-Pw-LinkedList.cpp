#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

Node * getnode(int x){
    Node * temp = new Node;

    temp->data = x;
    temp->next = NULL;

    return temp;
};

Node * Build123(){
    Node 
    *temp1,
    *temp2,
    *temp3;

    temp1 = getnode(1);
    temp2 = getnode(2);
    temp3 = getnode(3);

    temp1->next = temp2;
    temp2->next = temp3;

    return temp1;
}

void BuildList(int arr[],int n){

    if(n <= 0){
        return;
    }

    Node *last = getnode(arr[0]);
    head = last;

    for(int i = 1; i < n ; i++){
        last->next = getnode(arr[i]);
        last = last->next;
    }
}

void display(Node *h){
    while (h)
    {
        cout << h->data << "->";
        h = h->next;
    }
    cout << "\n";
}


int main(){

    int arr[] = {2,9,6,3,7,3,6,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    // head =  Build123();

    BuildList(arr,size);
    display(head);

    return 0;
}