#include <iostream>

using namespace std;


int main(){
    int input;

    cin >> input;

    if (input <= 99){
        cout << "99\n";
        return 0;
    }

    int remainder = input % 100;

    if (remainder >= 49){
        input += (99 - remainder);
    }
    else{
        input -= (remainder + 1);
    }


    cout << input << endl;

    return 0;

}
