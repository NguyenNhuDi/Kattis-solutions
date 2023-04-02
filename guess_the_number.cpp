#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<climits>
#include<queue>
#include<map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()

using namespace std;

typedef vector<int> vi;


int main(){

    int counter = 0;

    string input;

    int currGuess = 500;
    int l = 1;
    int r = 1000;
    while(counter < 11){
        cout << currGuess << endl;
        cout << flush;

        cin >> input;

        if(input == "lower"){
            r = currGuess;
            currGuess = (r+l)/2;
            
        }
        else if(input == "higher"){
            l = currGuess;
            currGuess = (r+l+1)/2;
            
        }
        else{
            break;
        }
        counter++;
    }


    return 0;
}
