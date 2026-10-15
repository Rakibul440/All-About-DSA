#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Stack {
    int size;
    int Top;
    char * S;
};

Stack * mystack = new Stack;

void push(Stack *,char);
pair<bool,char> pop(Stack *);  // return ifUnderflow happend or not and popped character
void DisplayStack(Stack);
bool isEmpty(Stack);

bool isParenthesisBalanced(char []);
int main(){

    char exp[] = "((A+B)*(C-D))";

    mystack->size = strlen(exp);
    mystack->Top = -1;

    bool result = isParenthesisBalanced(exp);

    if(result){
        cout << "Parenthesis is Balanced!" << endl;
    }else{
        cout << "Parenthesis is not Balanced!" << endl;
    }

    return 0;
}

bool isParenthesisBalanced(char exp[]){
    pair<bool,char> result;
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '('){
            push(mystack,exp[i]);
            DisplayStack(*mystack);
        }
        else if(exp[i] == ')'){
            result = pop(mystack);
            if(result.first){
                return false;
            }
        }
    }

    DisplayStack(*mystack);


    return isEmpty(*mystack) ? true : false;
}

void push(Stack *st,char ch){
    if(st->Top == st->size - 1){
        cout << "STACK OVERFLOW!";
        return;
    }

    st->Top++;
    st->S[st->Top] = ch;
}

pair<bool,char> pop(Stack *st){
    pair<bool,char> y;
    if(st->Top == -1){
        cout << "STACK UNDERFLOW" << endl;
        return { true,'\0'} ;
    }

    char ch = st->S[st->Top];
    st->S[st->Top] == '\0';
    st->Top--;

    return {false,ch};
}

bool isEmpty(Stack st){
    return st.Top == -1;
}

void DisplayStack(Stack st){
    cout << "\n== STACK ==\n";

    for(int i = st.Top ; i >= 0; i--){
        cout << st.S[i] << endl;
    }
}