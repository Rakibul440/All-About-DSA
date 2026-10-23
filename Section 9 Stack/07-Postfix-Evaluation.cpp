#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int postfixEvaluation(stack<int> &st,char postfix[]){
    int i = 0,val;
    while (postfix[i] != '\0')
    {
        if(postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/'){
            st.push(postfix[i++]- '0');
        }else{
            int x2 = st.top();
            st.pop();
            int x1 = st.top();
            st.pop();

            switch (postfix[i])
            {
            case '+':
                val = x1 + x2;
                st.push(val);
                i++;
                break;
            case '-':
                val = x1 - x2;
                st.push(val);
                i++;
                break;
            case '*':
                val = x1 * x2;
                st.push(val);
                i++;
                break;
            case '/':
                val = x1 / x2;
                st.push(val);
                i++;
                break;
            }

        }
    }

    val = st.top();
    return val;
    
}

int main(){

    char postfix[] = {'7','5','4','*','+','3','-','\0'};
    stack<int> st;

    int result = postfixEvaluation(st,postfix);
    cout << "Result : " << result << endl;

    return  0;
}