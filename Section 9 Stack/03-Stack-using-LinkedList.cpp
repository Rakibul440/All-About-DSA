#include <iostream>
using namespace std;

struct Stack {
    int data;
    Stack * next;
};

// push() function  --> insertBegin()  [So that we can insert at O(1)];
// pop() function   --> deleteFirst()  [So that we can delete at O(1)];
// isEmpty() function --> Head is NULL;
// DisplayStack() --> Normal Display(); [As we insert at first so top of the stack is first element]
// Top --> Head
Stack * Top = nullptr;

void push(int);
Stack * pop(Stack * &);
bool isEmpty(Stack *);
void DisplayStack(Stack *);

int main(){

    Stack *st;

    push(100);
    push(200);
    push(300);
    push(400);
    
    DisplayStack(Top);

    Stack * popped1 = pop(Top);
    Stack * popped2 = pop(Top);

    cout << "POPPED OUT : " << popped1->data << endl;
    cout << "POPPED OUT : " << popped2->data << endl;


    DisplayStack(Top);

    delete popped1;
    delete popped2;
    return 0;
}

void push(int data){
    Stack * p = new Stack;
    p->data = data;
    p->next = Top;
    Top = p;
}

Stack * pop(Stack * &top){
    if(isEmpty(top)){
        cout << "STACK UNDERFLOW!" << endl;
        return nullptr;
    }

    Stack * q = top;

    if(top->next == nullptr){
        top = nullptr;
        return q;
    }

    top = q->next;

    return q ;
}

bool isEmpty(Stack *top){
    if(top == nullptr){
        return true;
    }

    return false;
}

void DisplayStack(Stack * top){
    if(top == nullptr){
        cout << "NO ELEMENTS IN THE STACK!";
        return;
    }
    cout << "\n== STACK ==\n";
    while (top != nullptr){
        cout << top->data << endl;
        top = top->next;
    }
    
}