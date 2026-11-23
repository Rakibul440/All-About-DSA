#ifndef LIST_H
#define LIST_H

class Node{
    public:
        int val;
        Node * next;

        Node() : val(0),next(nullptr){};
        Node(int val) : val(val),next(nullptr){};
};

class List{
    Node *head;

    public : 
        List() : head(nullptr){};
        List(int val): head(new Node(val)){};

        void push_back(Node * , int);
        void push_front(Node * &,int);
        void push(Node *,int,int); // insert after perticular key
        int pop(Node * , int); // pop particular value node
        int pop_back(Node *);
        int pop_front(Node * &);
        pair<Node *,int> search(Node *,int);
};

#endif