#include <iostream>
using namespace std;

class Node {
    public :
        int data;
        Node * next;  

        Node(int data){
            this->data = data;
            next = nullptr;
        }
};

class Queue{
    private : 
        Node * Front;
        Node * Rear;
    
    public :
        Queue();
        ~Queue();

        void Enqueue(int);
        int Dequeue();
        bool IsEmpty();
        bool IsFull(Node *);
        void Display();
};

int main(){

    Queue Qu = Queue();

    Qu.Enqueue(10);
    Qu.Enqueue(20);
    Qu.Enqueue(30);
    Qu.Enqueue(40);
    Qu.Enqueue(50);

    cout << "\n== QUEUE ==\n";
    Qu.Display();


    Qu.Dequeue();
    Qu.Display();

        Qu.Dequeue();
    Qu.Display();

        Qu.Dequeue();
    Qu.Display();

        Qu.Dequeue();
    Qu.Display();

        Qu.Dequeue();
    Qu.Display();

        Qu.Dequeue();

    return 0;
}

Queue :: Queue(){
    Front = nullptr;
    Rear = nullptr;
}

Queue :: ~Queue(){
    Node * temp;
    while(Front != nullptr){
        temp = Front;
        Front = Front->next;

        delete temp;
    }

}


int Queue :: Dequeue(){
    if(IsEmpty()){
        cout << "Queue UNDERFLOW!\n";
        return -1;
    }

    Node * temp = Front;
    int x = temp->data;

    // single node
    if(Rear == Front){
        Front = nullptr;
        Rear = nullptr;
    }else{
        Front = Front->next;
    }


    delete temp;
    return x;
}

void Queue :: Enqueue(int x){

    Node * p = new Node(x);

    if(IsFull(p)){
        cout << "Queue OVERFLOW!\n";
        delete p;
        return;
    }

    if(Rear==nullptr){
        Rear = p;
    }else{
        Rear->next = p;
        Rear = p;
    }
    

    if(Front == nullptr){
        Front = p;
    }

}

bool Queue :: IsEmpty(){
    return Front == nullptr;
}

bool Queue :: IsFull(Node * t){
    return t == nullptr;
}

void Queue :: Display(){
    if(IsEmpty()){
        cout << "Queue is Empty!\n";
        return;
    }

    Node * temp = Front;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp =  temp->next;
    }

    cout << "\n";
}