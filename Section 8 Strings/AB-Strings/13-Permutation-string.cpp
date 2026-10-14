#include <iostream>
using namespace std;

void permutationOfString(char [],int);

int main(){
    char mystring[] = "abc";

    permutationOfString(mystring,0);
    return 0;
}

void permutationOfString(char str[],int k){
    static int A[100] = {0};
    static char Res[100];
    int i;

    if(str[k] == '\0'){
        Res[k] = '\0';
        cout << Res << endl;
    }
    else{

        for(i=0; str[i]!= '\0';i++){
            if(A[i]==0){
                Res[k] = str[i];
                A[i] = 1;
                permutationOfString(str,k+1);
                A[i] = 0;
            }
        }
    }

}