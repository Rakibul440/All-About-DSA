#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Stack{
    int size;
    int Top;
    char * S;
};

bool isEmpty(Stack);
bool isFull(Stack);
void push(Stack *,char);
char pop(Stack *);

int precedence(char);
bool isOperator(char);
char * InfixToPostfix(Stack *,char *infix);

int main(){

    char infix[] = "a+b*c-d/e";

    Stack *st = new Stack;
    st->size = strlen(infix);
    st->Top = -1;
    st->S = new char[st->size];

    char *result = InfixToPostfix(st,infix);

    cout << infix << " to --> " ;
    for(int i = 0 ; result[i] != '\0'; i++){
        cout << result[i] ;
    }

    delete(result); 
    return 0;
}

char * InfixToPostfix(Stack *st,char *infix){
    char *postfix = new char[strlen(infix)+1];

    int i = 0,j=0;

    while (infix[i] != '\0'){
       if(isOperator(infix[i])){
            if(precedence(infix[i]) <= precedence(st->S[st->Top])){
                postfix[j++] = st->S[st->Top];
                pop(st);

            }
            else if(precedence(infix[i]) > precedence(st->S[st->Top])){
                push(st,infix[i++]);
            }
       }else{
        postfix[j++] = infix[i++];
       }
    }

    while (!isEmpty(*st))
    {
        postfix[j++] = pop(st);
    }
    
    
    postfix[j] = '\0';

    // cout << postfix << endl;
    return postfix;
    
}

bool isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return true;
    }

    return false;
}

int precedence(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }else if(ch == '*' || ch == '/'){
        return 2;
    }else {
        return 0;
    }
}

char pop(Stack *st){
    if(isEmpty(*st)){
        cout << "STACK UNDERFLOW!\n";
        return '\0';
    }

    char ch = st->S[st->Top];
    st->S[st->Top] = '\0';
    st->Top--;

    return ch;
}

void push(Stack *st,char ch){
    if(isFull(*st)) {
        cout << "STACK OVERFLOW!\n";
        return ;
    }
    st->Top++;
    st->S[st->Top] = ch;
}


bool isEmpty(Stack st){
    return st.Top == -1;
}

bool isFull(Stack st){
    return st.Top == st.size - 1;
}