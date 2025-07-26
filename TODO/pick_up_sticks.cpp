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

vi topo(vi & outs, vector<vi> & adj_list){
    vi zeros;
    FOR(i,0,outs.size()){
        if(outs[i] == 0) zeros.push_back(i);
    }

    vi order;

    while(zeros.size()){
        int cIndex = zeros.back();
        order.push_back(cIndex);
        zeros.pop_back();

        fe(n, adj_list[cIndex]){
            if (--outs[n] == 0) zeros.push_back(n);
        }
    }

    return order;
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    vector<vi> adj_list(n);
    vi outs(n,0);

    FOR(i,0,m){
        int l, r; cin >> l >> r;
        adj_list[--r].push_back(--l);
        outs[l]++;
    }

    vi order = topo(outs, adj_list);

    if (order.size() != n) cout << "IMPOSSIBLE" << endl;
    else FORD(i, n-1, 0) cout << order[i] + 1 << endl;
    

    return 0;
}