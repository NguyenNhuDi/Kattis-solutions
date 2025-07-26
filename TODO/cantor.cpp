#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<iomanip>

using namespace std;

bool isIn(double number){
    double temp = number / float(3);
    if(number == 1){
        return true;
    }
    
    for(int i = 0; i < 10; i++){
        temp *= 3;

        int remainder = floor(temp);

        temp -= remainder;

        if(remainder == 1){
            return false;
        }
        else if(temp == 0){
            break;
        }
    }
    return true;

}

int bSearch(vector<int> a, int x){
    int size = a.size();
    int l = 0;
    int r = size - 1;
    int result = -1;
    while(l <= r){
        int m = (l + r) /2;
        if(a[m] <= x){
            l = m + 1;
            result = m;
        }
        else{
            r = m -1;
        }
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input;

    while(input.compare("END")){
        double number = stod(input);

        if(isIn(number)){
            cout << "MEMBER\n";
        }
        else{
            cout <<"NON-MEMBER\n";
        }

        cin >> input;
    }

    return 0;
}
