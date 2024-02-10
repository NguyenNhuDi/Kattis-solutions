#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define fe(x,y) for(auto & x : y)
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    FOR(i,0,n){
        int x; cin >> x;

        int y = 0;
        int m = 1;

        FOR(i,0,8){
            int nBit = (x ^ y) & m;
            y |= nBit << 1;
            m = m << 1;

        }

        y = y >> 1;

        cout << y << " ";
    }
    cout << endl;
    return 0;
}