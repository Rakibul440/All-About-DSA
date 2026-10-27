#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX 10

class Queue{
    private : 
        stack<int> s1;
        stack<int> s2;
    public :
        Queue(){};
        ~Queue(){};
        void Enqueue(int);
        int Dequeue();

        void Display();
};

void Queue :: Enqueue(int x){
    s1.push(x);
}

int Queue :: Dequeue(){
    int x = -1;

    if(s2.empty()){
        if(s1.empty()){
            cout << "QUEUE OVERFLOW!\n" << endl;
            return x;
        }else{
            while (!s1.empty())
            {
                int q = s1.top();
                s1.pop();
                s2.push(q);
            }
            
        }
    }

    x = s2.top();
    s2.pop();

    return x;
}

void Queue :: Display(){
    if(s1.empty()){
        cout << "QUEUE IS EMPTY!\n";
        return ;
    }

    while (!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
}

int main(){
    int A[] = {10,20,30,40,50};
    Queue Qu;

    cout << "Enqueue: ";

    int n = sizeof(A) / sizeof(A[0]);

    for (int i = 0; i < n; i++) {
        Qu.Enqueue(A[i]);
        cout << A[i];

        if (i < n - 1) {
            cout << " <- ";
        }
    }

    cout << '\n';


    return 0;
}