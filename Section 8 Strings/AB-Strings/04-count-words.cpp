#include <iostream>
using namespace std;

int countWords(char []);

int main(){

    char sentence[200] = "Bright minds learn daily,     solve problems, and    build useful skills through steady practice, patience.";

    int noOfwords = countWords(sentence);

    cout << "No of words : " << noOfwords << endl;

    return 0;
}

int countWords(char str[]){

    int count = 1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' && str[i-1] != ' ')
        {
            count++;
        }
        
    }

    return count;
    
}