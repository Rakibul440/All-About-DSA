#include <iostream>
using namespace std;

pair<char,char> CompareStringCaseSensetive(char [], char []);
pair<char,char> CompareString(char [], char []);


int main(){
    char str1[] = "mediCal";
    char str2[] = "mEdical";


    // pair<char,char> results = CompareStringCaseSensetive(str1,str2);
    pair<char,char> results = CompareString(str1,str2);


    if(results.first == results.second) {
        cout << "Both string is same and Equal!";
    }else if(results.first > results.second){
        cout << "First String is Greater!";
    }else{
        cout << "First String is smaller!";
    }

    return 0;
}

pair<char,char> CompareString(char A[], char B[]){
    pair <char,char> lastCharacters ;

    int i = 0,j = 0;


    while (A[i] != '\0' && B[j] != '\0')
    {
        if(A[i] >= 65 && A[i] <= 90 ){
            A[i] += 32;

            if(B[j] >= 65 && B[j] <= 90 ){
                B[j] += 32;

                if(A[i] != B[j]){
                    break;
                }
            }
        }

        i++;
        j++;
    }

    if(A[i] == '\0'){
        lastCharacters.first = 0;
    }else{
        lastCharacters.first = A[i];
    }
    if(B[i] == '\0'){
        lastCharacters.second = 0;
    }else{
        lastCharacters.second = B[j];
    }
    
    return lastCharacters;
}

pair<char,char> CompareStringCaseSensetive(char A[], char B[]){
    bool isSame = true;
    pair <char,char> lastCharacters;
    int i=0,j=0;

    while (A[i]!='\0' && B[j]!='\0')
    {
        if(A[i]!=B[j]){
            isSame = false;
            break;
        }   

        i++;
        j++;
    }

    if(A[i] == '\0'){
        lastCharacters.first = 0;
    }else{
        lastCharacters.first = A[i];
    }
    if(B[i] == '\0'){
        lastCharacters.second = 0;
    }else{
        lastCharacters.second = B[j];
    }

    return {lastCharacters};
}