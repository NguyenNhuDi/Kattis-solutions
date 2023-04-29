//fyi
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
    cin >> input;

    int count = 0;
    FOR(i,0,3){
        if(input[i] == '5'){
            count++;
        }
    }

    if(count == 3){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}
