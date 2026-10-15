#include <iostream>
using namespace std;

struct Stack {
    int size;
    int Top;
    int * S;
};

void push(Stack * , int);
int pop(Stack *);
int peek(Stack ,int);  // element of a giving position -- same as kth elements from behind of an array;
bool isEmpty(Stack);
bool isFull(Stack);
void DisplayStack(Stack,int);

int main(){

    Stack *st = new Stack;
    st->size = 10;
    st->Top = -1;
    st->S = new int[st->size]; // Stack

    push(st,100);
    push(st,200);
    push(st,300);
    push(st,400);

    cout << "\n== STACK ==\n";
    DisplayStack(*st,st->Top);


    // Find 3th Element of this stack means -- 200;
    int st_3th_El = peek(*st,3);
    cout << "3rd elments of this stack is : " << st_3th_El << endl;


    int  el1 = pop(st);
    int  el2 = pop(st);
    int  el3 = pop(st);


    cout << "\n== STACK ==\n";
    DisplayStack(*st,st->Top);

    cout << "DELETED ELEMENTS ARE : " << 
        el1 << "," << el2 << "," << el3 << endl;

    return 0;
}

void push(Stack * st, int data){
    if(isFull(*st)){
        cout << "STACK OVERFLOW!\n";
        return ;
    }
    st->Top++;
    st->S[st->Top] = data;
}

int pop(Stack * st){
    int data;
    if(isEmpty(*st)){
        cout << "STACK UNDERFLOW!\n";
        return -1;
    }

    data = st->S[st->Top];
    st->S[st->Top] = -1 ;
    st->Top--;

    return data;
}

int peek(Stack st,int pos){
    if(isEmpty(st)){
        cout << "STACK IS EMPTY!\n";
        return -1;
    }

    int data ;

    return st.S[st.Top - pos + 1];
}

bool isEmpty(Stack st){
    if(st.Top == -1){
        return true;
    }

    return false;
}

bool isFull(Stack st){
    if(st.Top == st.size - 1){
        return true;
    }

    return false;
}

void DisplayStack(Stack st, int top){
    if(top >= 0){
        cout << st.S[top] << endl;
        DisplayStack(st,top - 1);
    }
}