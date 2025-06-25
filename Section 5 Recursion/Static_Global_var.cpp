#include <iostream>
using namespace std;

int x = 0; // global variable
 
int sum(int n){
    if(n>0) return sum(n-1)+n;
    return 0;
}

int sum_withGlobalVar(int n){
   
    if(n>0) {
        x++;
        return sum_withGlobalVar(n-1) + x;
    }
    return 0;
}

int sum_withStaticVar(int n){
    static int x = 0;
    if(n>0) {
        x++;
        return sum_withStaticVar(n-1) + x;
    }
    return 0;
}


int main(int argc, char const *argv[])
{
    cout << "How many number you want to sum together from 0 : " ;
    int num ;
    cin >> num;

    int result = sum(num);
    cout << "Result is : " << result << endl;

    int result2 = sum_withGlobalVar(5);
    cout << "Result of second function : " << result2 << endl;

    int result3 = sum_withStaticVar(5);
    cout << "Result of second function : " << result3 << endl;

    return 0;
}
