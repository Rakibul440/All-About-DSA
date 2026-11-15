// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// class Node{
//     public:
//         int val;
//         Node * next;

//         Node() : val(0),next(nullptr){};
//         Node(int x) : val(x),next(nullptr){};
// };

// class List{
//     Node * first;
//     public :
//         List() : first(nullptr){};
//         List(int x) : first(new Node(x)){};
//         static void push_front(Node *&,int);
//         static int pop_front(Node *&);
// };

// void RedixSort(vector<int> &);

// void RedixSort(vector<int> &A){
//     int max = A[0];
//     for(int i = 1; i < A.size();i++){
//         if(A[i]>max) max = A[i];
//     }

//     vector<Node *> Bins(10,nullptr); // 10 sized Bins

//     int total_digits = 0;
//     if(max==0) total_digits = 1;
//     while (max > 0){
//         total_digits++;
//         max /= 10;
//     }

//     int factor = 1;

//     while(total_digits > 0){

//         for(int i = 0;i<A.size();i++){
//             int pos = (A[i]/factor)%10;
//             List :: push_front(Bins[pos],A[i]);
//         }
//         factor *= 10;

//         int j = 0;

//         for(int i = 0; i < Bins.size();i++){
//             while(Bins[i] != nullptr){
//                 int x = List ::pop_front(Bins[i]);
//                 if(x!=-1){
//                     A[j++] = x;
//                 }
//             }
//         }

//         total_digits--;
//     }
    
// }

// int main(){

//     vector<int> A = {102,99,203,987,159,3000,123,2};
    
//     for(int x : A){
//         cout << x << " ";
//     }
//     cout << "\n";

//     RedixSort(A);

//     for(int x : A){
//         cout << x << " ";
//     }
//     cout << "\n";

//     return 0;
// }

// void List :: push_front(Node * &t, int x){
//     Node * temp = new Node(x);
//     temp->next = t;
//     t = temp;
// }

// int List :: pop_front(Node * &t){
//     if(t == nullptr){
//         return -1;
//     }
//     Node * temp = t;
//     int data = temp->val;
//     t = t->next;
//     delete(temp);

//     return data;
// }


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int x) : val(x), next(nullptr) {}
};

class List {
public:
    static void push_back(Node*&, Node*&, int);
    static int pop_front(Node*&);
};

// Insert at the end to preserve insertion order
void List::push_back(Node*& head, Node*& tail, int x) {
    Node* temp = new Node(x);

    if (head == nullptr) {
        head = tail = temp;
        return;
    }

    tail->next = temp;
    tail = temp;
}

// Remove from the beginning
int List::pop_front(Node*& head) {
    if (head == nullptr) return -1;

    Node* temp = head;
    int data = temp->val;

    head = head->next;

    delete temp;

    return data;
}

void RadixSort(vector<int>& A) {

    if (A.empty()) return;

    int mx = *max_element(A.begin(), A.end());

    // This implementation supports non-negative integers.
    if (mx < 0) return;

    int total_digits = 0;

    if (mx == 0) total_digits = 1;

    while (mx > 0) {
        total_digits++;
        mx /= 10;
    }

    vector<Node*> Bins(10, nullptr);
    vector<Node*> Tails(10, nullptr);

    int factor = 1;

    while (total_digits > 0) {

        // Distribution
        for (int i = 0; i < A.size(); i++) {

            int pos = (A[i] / factor) % 10;

            List::push_back(Bins[pos], Tails[pos], A[i]);
        }

        // Collection
        int j = 0;

        for (int i = 0; i < 10; i++) {

            while (Bins[i] != nullptr) {
                A[j++] = List::pop_front(Bins[i]);
            }

            // Reset tail pointer
            Tails[i] = nullptr;
        }

        factor *= 10;
        total_digits--;
    }
}

int main() {

    vector<int> A = {102, 99, 203, 987, 159, 3000, 123, 2};

    cout << "Before sorting:\n";

    for (int x : A)
        cout << x << " ";

    cout << "\n";

    RadixSort(A);

    cout << "After sorting:\n";

    for (int x : A)
        cout << x << " ";

    cout << "\n";

    return 0;
}