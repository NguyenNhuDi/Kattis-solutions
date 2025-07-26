#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;

    set<string> all;

    string temp;
    while(cin >> input){

        temp = input;
        for(int i = 0; i < temp.length(); i++){
            temp[i] = tolower(temp[i]);
        }

        if(all.count(temp)){
            cout << ".";
        }
        else{
            cout << input;
        }

        all.insert(temp);
        cout << " ";


    }
    
    return 0;
}
