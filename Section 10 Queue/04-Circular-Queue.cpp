#include <iostream>
using namespace std;

#define MAX 10;

class Queue{
    private : 
        int size;
        int Front;
        int Rear;
        int * Q;
    public:
        Queue();
        Queue(int);
        ~Queue();

        void Enqueue(int);
        int Dequeue();
        bool IsFull();
        void Display();
};

int main(){

    Queue Qu = Queue();

    // Qu.Dequeue(); // underflow

    for(int i = 0 ; i < 10; i++){
        Qu.Enqueue( (i + 1) *10);
    }

    Qu.Display();

    // Qu.Enqueue(200); // Overflow

    // Circular
    Qu.Dequeue();
    Qu.Dequeue();
    Qu.Dequeue();
    Qu.Display();

    Qu.Enqueue(101);
    Qu.Display();


    return 0;
}

Queue :: Queue(){
    this->size = MAX;
    this->Front = -1;
    this->Rear = -1;
    this->Q = new int[this->size]{};
}

Queue :: Queue(int size){
    this->size = size;
    this->Front = -1;
    this->Rear = -1;
    this->Q = new int[this->size]{};
}

Queue :: ~Queue(){
    delete[] Q;
}

void Queue :: Enqueue(int x){
    if(IsFull()){
        cout << "QUEUE OVERFLOW!\n";
        return;
    }

    Rear = (Rear + 1) % size;  // Circular
    Q[Rear] = x;

    if(Front == -1){
        Front = 0;
    }
}

int Queue :: Dequeue(){
    if(Front == -1){
        cout << "QUEUE UNDERFLOW!\n";
        return -1;
    }

    int x = Q[Front];
    Q[Front] = -1;
    
    if(Rear == Front){
        Rear = Front = -1;
    }else{
        Front = (Front + 1) % size;
    }

    return x;

}


bool Queue :: IsFull(){
    return Front == (Rear + 1) % size;
}
 
void Queue :: Display(){
    // cout << "\n== QUEUE ==\n";
    for (int i = 0; i < size; i++)
    {
        cout << Q[i] << " ";
    }

    cout << "\n";
    
}