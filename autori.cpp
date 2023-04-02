#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;

    cin >> input;

    cout <<input[0];

    bool flag = false;
    for(const auto & x : input){
        if(flag){
            cout << x;
            flag = false;
        }

        if(x == '-'){
            flag = true;
        }
    }
    cout << "\n";
    

    return 0;
}
