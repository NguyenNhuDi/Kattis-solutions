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
    vector<char> out;

    

    cin >> input; 

    int size = input.size();


    for(int i = 0; i < size; i++){
        out.push_back(input[i]);
        if(input[i] == '<'){
            out.pop_back();
            out.pop_back();
        
        }
    }
    for(const auto & x: out){
        cout << x;
    }
    cout << "\n";

    return 0;
}
