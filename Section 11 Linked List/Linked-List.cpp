#include <iostream>
using namespace std;

/*--------creating structure node---------*/
struct Node{
    int data;
    struct Node *next; // self referential pointer;
};

// creating a pointer which will be pinting the node;
struct Node *first = NULL; // so now there isn't any node


/*----------Creating NODES(Linked List)---------*/
void Create(int A[], int n){
    
    int i;
    struct Node *t,*last; // 't' for creating node and 'last' for creating last node;
    
    //create A NODE
    first = new Node;
    first->data = A[0];
    first->next = NULL;

    //set that NODE as last NODE
    last = first;

    for(i=1;i<n;i++){
        // creating another NODE
        t = new Node;
        t->data = A[i];
        t->next = NULL;

        // linking last NODE to this NODE
        last->next = t;

        //Now make this node as last NODE
        last = t;
        
    }

}


void Display(struct Node *p);

int main(){
    int A[] = {2,3,4,6,96,7,9,8,5,3,7};
    int n = sizeof(A)/sizeof(int);

    Create(A,n);
    Display(first);
    return 0;
}

void Display(struct Node *p){

    while(p!=NULL){ // checking There is any NODE or Not
        cout << p->data << "->";
        p = p->next; // move the pointer on next Node
    }
    cout << "\n";
}
