#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top;

bool isEmpty();
int init();
void push(int);
int pop();

void Display(int top);

int main(){

    init();
    push(100);
    push(200);
    push(300);
    push(400);
    push(500);
    push(600);

    cout << "\n == STACK ==\n";
    Display(top);

    pop();
    pop();
    pop();


    cout << "\n == STACK ==\n";
    Display(top);


    return 0;
}

int pop(){
    int data;
    if(isEmpty()){
        cout << "STACK UNDERFLOW!\n";
        return -1;
    }

    data = stack[top];
    stack[top] = -1;
    top--;

    return data;
}

void push(int data){
    if(top == MAX - 1){
        cout << "STACK OVERFLOW!\n";
        cout << "CAN'T PUSH : " << data << endl;
        return;
    }

    top++;
    stack[top] = data;
}

void Display(int top){
    if(top >= 0){
        cout << stack[top] << endl;
        Display(top - 1);
    }
    
}

int init(){
    top = -1;
}

bool isEmpty(){
    if(top == -1){
        return true;
    }

    return false;
}
