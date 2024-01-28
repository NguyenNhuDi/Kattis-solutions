#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<climits>
#include<queue>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b)for(int i = b; i >= a; i--)
#define SIZE(x) x.size()

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;

    cin >> input;

    set<char> all;

    FOR(i,0,SIZE(input)){
        

        if(!all.count(input[i])){
            all.insert(input[i]);
        }
        else{
            cout << 0 << endl;
            return 0;
        }
    }

    cout << 1 << endl;

    return 0;
}
