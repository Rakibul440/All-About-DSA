#include <iostream>
#include "includes/list.h"

using namespace std;

void List :: push_back(Node * &h,int x){
    Node * temp = new Node(x);

    if(h==nullptr){
        h=temp;
        return;
    }

    Node * q = h;
    while(q->next!=nullptr){
        q = q->next;
    }
    q->next = temp;
}

void List :: push_front(Node * &h, int x){
    Node * temp = new Node(x);

    if(h==nullptr){
        h = temp;
        return;
    }

    temp->next = h;
    h = temp;
}

int List :: pop_back(Node * &h){
    int val = -1;

    // if null
    if(h==nullptr) return val;

    // if one node
    Node * temp;
    if(h->next== nullptr){
        temp = h;
        val = temp->val;
        h = nullptr;
        delete(temp);

        return val;
    }

    Node *q,*t=h;

    while(t->next!=nullptr){
        q=t;
        t=t->next;
    }
    temp = t;
    val = temp->val;
    q->next = nullptr;

    delete(temp);
    return val;
}

int List :: pop_front(Node * &h){
    int val = -1;
    if(h==nullptr) return val;

    Node * temp = h;
    h=h->next;
    val = temp->val;

    delete(temp);

    return val;
}

// pair<Node *,int> List :: search(Node * h,int x){

    
//     while(h!=nullptr && h->val != x){
//         h=h->next;
//     }
    
//     if(h==nullptr)return {h,-1};
    
//     return {h,h->val}; 
// }

void List :: Display(Node * t){
    while(t!=nullptr){
        cout << t->val << "->";
        t = t->next;
    }
    cout << "NULL\n";
}
