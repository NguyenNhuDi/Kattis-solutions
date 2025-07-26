//Head Guard
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
#define FORD(i,a,b) for(int i = a; i >= b; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    while(cin >> input){

        int counter = 0;
        char prevC = '1';
        for(const auto & c : input){

            if(prevC != c && prevC != '1'){
                cout << counter << prevC;
                counter = 1;
            }
            else{
                counter++;
            }

            prevC = c;
        }
        cout << counter << prevC;
        cout << endl;

    }
    return 0;
}
