#include <iostream>
using namespace std;

#define MAX 100

class Queue{
    private : 
        int size;
        int Front;
        int Rear;
        int * Q;
    public :
        Queue(){
            this->Front = -1;
            this->Rear = -1;
            this->size = MAX;
            this->Q = new int[this->size];
        }

        Queue(int size){
            this->Front = -1;
            this->Rear = -1;
            this->size = size;
            this->Q = new int[this->size];
        }

        bool IsEmpty();
        bool IsFull();
        void Enqueue(int);
        int Dequeue();
        void Display();
};

int main(){

    Queue Qu = Queue(10);
 
    // Qu.Dequeue();
    Qu.Enqueue(10);
    Qu.Enqueue(20);
    Qu.Enqueue(30);

    Qu.Display();

    return 0;
}

int Queue :: Dequeue(){
    if(IsEmpty()){
        cout << "UNDERFLOW!\n";
        return -1;
    }

    int x = Q[Front];
    Q[Front] = -1;
    
    if(Front == Rear){
        Front = Rear = -1; // resetting pointer 
    }else{
        Front++;
    }

    return x;
}

void Queue :: Enqueue(int data){
    if(IsFull()){
        cout << "OVERFLOW!\n";
        return;
    }
    Rear++;
    Q[Rear] = data;

    if(Front == -1){
        Front++;
    }
}


bool Queue :: IsFull(){
    return Rear == size - 1;
}

bool Queue :: IsEmpty(){
    return Rear == -1;
}

void Queue :: Display(){
    if(IsEmpty()){
        cout << "Queue is Empty!\n";
        return;
    }
    cout << "\n== QUEUE ==\n";
    for (int i = 0; i <= Rear; i++)
    {
        cout << Q[i] << " ";
    }

    cout << "\n";
    
}