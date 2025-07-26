//knot knowledge

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
#define fe(x,y) for(const auto & x : y)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    unordered_set<int> c;

    FOR(i,0,n){
        int t; cin >> t;
        c.insert(t);
    }


    FOR(i,0,n-1){
        int t; cin >> t;

        if (c.count(t)){ 
            c.erase(t);
        }
    }

    fe(x,c) cout << x << endl;


    return 0;
}
