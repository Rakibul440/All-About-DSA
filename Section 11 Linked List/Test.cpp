#include <iostream>
using namespace std;

/*----------creating node structure---------*/
struct Node{
    int data;
    struct Node *next;
};

/*--------creating libked list------------*/
void Create(){
    struct Node *ptr; // declear 'struct node' type pointer which is pointing on 'Node'
    ptr = new Node; // set pointer as Node structure

    //accessing node's data through pointer;
    ptr->data = 10;
    ptr->next = NULL;
}

int main(){
    int A[] = {2,3,4,6,96,7,9,8,5,3,7};
    return 0;
}