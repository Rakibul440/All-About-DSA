#include <iostream>
using namespace std;

// Functions 
int *Numbers(int n);
void Create(int A[], int n);
void Display(struct Node *p);

struct Node {
    int data;
    struct Node *next;
};

struct Node *first = NULL;

int main(){
    cout << "How Many Numbers You want to store ?? ";
    int n ;
    cin >> n;
    int *num = Numbers(n);


    Create(num,n);
    Display(first);

    delete[] num;
    return 0;
}

void Create(int A[],int n){
    struct Node *t, *last;

    first = new Node;
    first->data = A[0];
    first->next = NULL;

    last = first;
    
    for(int i = 1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;

        last->next = t;

        last = t;
    }
}

void Display(struct Node *p){
    while(p!=NULL){
        cout << p->data << " ";
        p = p->next;
    }
}

int *Numbers(int n){

    int *your_numbers = new int[n],i;

    for (i = 0; i < n; i++){
        cout << "Enter Number " << i+1 << " : ";
        cin >> your_numbers[i];
    }

    return your_numbers;
}

