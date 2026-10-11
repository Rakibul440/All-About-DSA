#include <iostream>
using namespace std;

pair <int ,int> countVandC(char []);

int main(){
    // char sentence[20] = "How are you" ;
    char sentence[200] = "Bright minds learn daily, solve problems, and build useful skills through steady practice, patience.";

    pair<int,int> result = countVandC(sentence);

    cout << "No of vowels : " << result.first << "\n"
        << "No of Consonants : " << result.second << endl;

    return 0;
}

pair <int ,int> countVandC(char str[]){
    int coutnV = 0 , countC = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if(
            str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'
        ){
            coutnV++;
        }
        // check if alphabate 
        else if(
            (str[i] >= 65 && str[i] <= 90) ||
            (str[i] >= 97 && str[i] <= 122) 
        ){
            countC++;
        }
    }
    
    return {coutnV,countC};
}