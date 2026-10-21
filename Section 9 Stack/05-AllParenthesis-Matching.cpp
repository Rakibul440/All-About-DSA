#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
        stack<char> st;

        for(int i = 0; s[i] != '\0' ; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                switch (s[i]) {
                    case ')' :
                        if (st.empty()){
                            return false;
                        } 
                        else if(st.top() == '('){
                            st.pop();
                            break;
                        }
                        else{
                            return false;
                        }
                    case '}' :
                        if (st.empty()){
                            return false;
                        }
                        else if(st.top() == '{'){
                            st.pop();
                            break;
                        }
                        else{
                            return false;
                        }
                    case ']' :
                        if (st.empty()){
                            return false;
                        }
                        else if(st.top() == '['){
                            st.pop();
                            break;
                        }
                        else{
                            return false;
                        }
                }
            }
        }

        return st.empty() ? true : false;
    }

int main(){

    string str = "[]{}(())[]";

    if(isValid(str)){
        cout << "BALANCED" << endl;
    }else {
        cout << "NOT BALANCED" << endl;
    }

    return 0;
}