#include <iostream>
using namespace std;

int binary(int dec_Num);
void Print_All_Binary();

int main(int argc, char const *argv[])
{
    cout << "\n------Convert Decimal To Binary-------\n" << endl;
    int dec_num;
    cout << "Enter a decimal number : ";
    cin >> dec_num;

    int binary_num = binary(dec_num);
    cout << "Binary of "<< dec_num << " is : "<< binary_num ;

    cout << "\n------------------\n" << endl;
    Print_All_Binary();
    return 0;
}

int binary(int dec_num){
    int remainder,pow_10 = 1, binary_num = 0;
    while(dec_num > 0){
        remainder = dec_num % 2;
        dec_num = dec_num / 2;

        binary_num += (remainder * pow_10);
        pow_10 *= 10;
    }
    return binary_num;
}

void Print_All_Binary(){
    for(int i = 0; i<=10;i++){
        cout << i << " : " << binary(i) <<endl;
    }
}