#ifndef LIST_H
#define LIST_H

#include <utility>

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

        static void push_back(Node * &, int);
        static void push_front(Node * &,int);
        static void push(Node * &,int,int); // insert after perticular key
        static int pop(Node * &, int); // pop particular value node
        static int pop_back(Node * &);
        static int pop_front(Node * &);
        static std::pair<Node *,int> search(Node *,int);
        static void Display(Node *);
};

#endif