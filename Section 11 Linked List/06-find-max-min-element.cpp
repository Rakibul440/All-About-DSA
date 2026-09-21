#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data ;
    Node *next;
};

Node * head;

Node * getnode(int);
void BuildList(int[],int);
void Display(Node *);
pair<int,int> findMaxMin(Node *);

int main(){

    int arr[] = {2,8,34,92,-5,1,6,5,7,-1};

    int size = sizeof(arr)/sizeof(arr[0]);

    BuildList(arr,size);
    Display(head);

    pair<int,int> result = findMaxMin(head);

    cout << "Maximum Element is : "  << result.first << " & "
         << "Minimum Element is : " << result.second << endl;

    return 0;
}

pair<int,int> findMaxMin(Node *h){
    pair<int,int> maxMin = {INT32_MIN,INT32_MAX};

    while (h)
    {
        if(h->data > maxMin.first){
            maxMin.first = h->data;
        }

        if(h->data < maxMin.second){
            maxMin.second = h->data;
        }

        h = h->next;
    }

    return maxMin;
}

void BuildList(int arr[],int n){
    if(n<=0){
        head = NULL;
        return;
    }

    Node * last = getnode(arr[0]);
    head = last;

    for(int i = 1 ; i < n ; i++){
        last->next = getnode(arr[i]);
        last = last->next;
    }
}

Node * getnode(int x){
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;

    return temp;
}

void Display(Node *h){
    while (h)
    {
        cout << h->data << " -> " ;
        h = h->next;
    }
    cout << "\n";
}