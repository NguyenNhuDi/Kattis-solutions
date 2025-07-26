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

    // cin >> input;
    int counter = 0;

    while(cin >> input){

        for(const auto & x : input){
            if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U'||
            x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
                counter++;
            }
        }
    }
    cout << counter << endl;
    

    return 0;
}
