#include <iostream>
using namespace std;

#define MAX 10

int Q[MAX];
int Front;
int Rear;

void init();
bool isEmpty();
bool isFull();
void Enqueue(int);
int Dequeue();
void Display();

int main(){

    init();
    Dequeue();
    Enqueue(100);
    Enqueue(200);
    Enqueue(300);
    Enqueue(400);
    Enqueue(500);

    Display();

    Dequeue();
    Dequeue();

    Display();

    return 0;
}

int Dequeue(){
    //  handle underflow
    if(isEmpty()){
        cout << "Queue UNDERFLOW!\n" ;
        return -1;
    }
    int data = Q[Front];
    Q[Front] = -1;

    if(Front ==  Rear){
        Front = Rear = -1;
    }else{
        Front++;
    }

    return data;
}

void Enqueue(int data){
    // handle Overflow
    if(isFull()){
        cout << "Queue is FUll!\n";
        return;
    }

    Rear++;
    Q[Rear] = data;

    // handle first Enqueue
    if(Front == -1){
        Front++;
    }
}

bool isFull(){
    return Rear == MAX - 1;
}

bool isEmpty(){
    return Rear == -1;
}

void init(){
    Front = Rear = -1;
}

void Display(){
    if(isEmpty()){
        cout << "Queue is Empty!\n";
        return;
    }
    cout << "\n== QUEUE ==\n";
    for(int i = 0 ; i <= Rear; i++){
        cout << Q[i] << " ";
    }
}