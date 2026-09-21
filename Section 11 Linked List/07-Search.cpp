#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head;

Node * getnode(int);
void BuildList(int[],int);
void Display(Node *);
Node * Search(Node *,int);

int main(){

    int arr[] = {2,8,34,92,10,23};

    int size = sizeof(arr)/sizeof(arr[0]);

    BuildList(arr,size);
    Display(head);

    Node *t  = Search(head,1000);

    if(t) {
        cout << "Found element!\nNode address : " << t << endl;
    }
    else {
        cout << "Not found!" << endl;
    }

    return 0;
}


Node * Search(Node *h,int ele){

    while (h)
    {
        if(h->data == ele){
            return h;
        }
        h = h->next;
    }

    return NULL;
}

Node * getnode(int x){
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;

    return temp;
}

void BuildList(int arr[],int n){
    if(n<=0){
        head = NULL;
        return;
    }

    Node * last = getnode(arr[0]);
    head = last;

    for(int i = 1 ; i < n; i++){
        last->next = getnode(arr[i]);
        last = last->next;
    }
    
}


void Display(Node *h){
    while (h)
    {
        cout << h->data << " add- " << h << " -> " ;
        h = h->next;
    }
    cout << "\n";

}