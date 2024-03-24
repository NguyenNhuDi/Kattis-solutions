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

    int w, p; cin >> w >> p;

    set<int> result;
    vi par(p);

    FOR(i,0,p){
        int t; cin >> t;
        
        par[i] = t;
        result.insert(t);
        result.insert(w-t);
        
    }

    result.insert(w);

    sort(par.begin(), par.end());

    FOR(i,0,p){
        FOR(j,i,p){
            if(i == j) continue;

            // cout << par[j] << " : " << par[i] << endl;

            result.insert(par[j] - par[i]);
        }
    }

    fe(x, result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
