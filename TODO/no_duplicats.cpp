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


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> all;

    string input;

    bool repeated = false;
    while(cin >> input){
        if(all.count(input)){
            cout << "no\n";
            repeated = true;
            break;
        }
        else{
            all.insert(input);
        }
    }

    if(!repeated){
        cout << "yes\n";
    }

    return 0;
}
