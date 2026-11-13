#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node {
    public :
        int data;
        Node * next;

        Node() : data(0),next(nullptr){};
        Node(int data) : data(data),next(nullptr){};
};

class LinkedList{
    private : 
        Node * first;
    public : 
        LinkedList() : first(nullptr){};
        LinkedList(int data) : first(new Node(data)){};
        static void Push_Front(Node * &,int);
        static int Pop_Front(Node * &);
};

void BinSort(vector<int> &A);

void BinSort(vector<int> &A){
    if(A.empty()) return;
    int max = A[0];
    for(int i = 0; i<A.size();i++){
        if(A[i]>max) max = A[i];
    }

    vector<Node *> Bins(max+1,nullptr);
    for(int i = 0;i<A.size();i++){
        LinkedList::Push_Front(Bins[A[i]],A[i]);
    }

    int j = 0;
    for(int i = 0; i<Bins.size();i++){
        while(Bins[i] != nullptr){
            int x = LinkedList::Pop_Front(Bins[i]);
            if(x!=-1){
                A[j++] = x;
            }
        }
    }
}

int main(){

    vector<int> A = {2,4,6,3,7,9,1,0,14,11,2,4,3,9};

    for(int x : A){
        cout << x << " ";
    }
    cout << "\n";

    BinSort(A);

    for(int x : A){
        cout << x << " ";
    }
    cout << "\n";


    return 0;
}

void LinkedList :: Push_Front( Node * &h ,int x){
    Node * temp = new Node(x);
    temp->next = h;
    h = temp;
}

int LinkedList :: Pop_Front(Node * &h){
    if(h==nullptr){
        return -1;
    }
    Node *temp = h;
    int x = temp->data;

    h = h->next;
    delete(temp);

    return x;
}