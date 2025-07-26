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
    bool flag = true;
    for(int i = 1; i < 6; i++){
        cin >> input;
    //&& ((input.size()-1) - i) >= 2)
        for(int j = 0; j < input.size(); j++){
            if(input[j] == 'F' && (input.size()  - j) >= 2) {
                if(input[j + 1] == 'B'){
                    if(input[j + 2] == 'I'){
                        cout << i << " ";
                        flag = false;
                    }
                }
            }
        }
    }   
    if(flag){
        cout << "HE GOT AWAY!\n";
    }
    else{
        cout << "\n";
    }

    return 0;
}
