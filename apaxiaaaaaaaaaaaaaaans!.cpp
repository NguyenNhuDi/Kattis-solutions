#include<iostream>
#include<string>

using namespace std;

int main(){

    string input;

    cin >> input;

    string ans;

    for (int i = 0; i < input.size(); i++){

        if(i > 0){
            if(input[i] != input[i - 1]){
                ans.push_back(input[i]);
            }

        }
        else{
            ans.push_back(input[i]);
        }
    }

    for(auto & x : ans){
        cout << x;
    }
    

    return 0;
}
