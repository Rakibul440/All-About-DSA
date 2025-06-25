#include <iostream>
using namespace std;

int fun(int n){
    if(n > 100){
        return n - 10;
    }
    else{
        fun(fun(n+11));
    }
}

int main(int argc, char const *argv[])
{
    
    int result = fun(95);
    printf("%d",result);
    return 0;

}
