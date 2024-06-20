
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef  unsigned long long hint;

typedef vector<hint> vh;

bool isPrime(hint number){

    if(number % 2 == 0){
        return false;
    }

    for(hint i = 3; i <= sqrt(number) ; i += 2){
        if(number % i == 0){
            return false;
        }
    }

    return true;



}


int main(){
    hint X;

    cin >> X;

    if(isPrime(X)){
        cout << "1";
        return 0;
    }

    uint currNum = 2;
    vh factors;

    while(X != 1){

        hint remainder = X % currNum;

        if(remainder == 0){
            factors.push_back(currNum);
            X /= currNum;
        }
        else{
            if(currNum == 2){
                currNum++;
            }
            else{
                currNum += 2;
            }
        }

    }

    cout << factors.size();

    return 0;
}
