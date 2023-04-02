//Hidden Password
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<queue>
#include<map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>

using namespace std;


bool Search(string arr, char x){
    for(const auto & i : arr){
        if(i == x){
            return true;
        }
    }

    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string passWord, input;
    
    cin >> passWord >> input;

    string pW = passWord;
    int index = 0;

    char expected = passWord[index];
    bool first = true;
    FOR(i,0,SIZE(input)){

        if(Search(pW,input[i])){

            if(input[i] == passWord[index]){
                
                pW[index] = '0';
                index++;
                expected = passWord[index];
                first = false;
            }
            else if(input[i != expected && first]){
                cout << "FAIL\n";
                return 0;
            }
            else if(input[i] != expected){
                
                pW = passWord;
                index = 0;
                expected = passWord[index];
            }
        }
    }

    if(index == SIZE(passWord)){
        cout << "PASS\n";
    }
    else{
        cout << "FAIL\n";
    }


    return 0;
}
