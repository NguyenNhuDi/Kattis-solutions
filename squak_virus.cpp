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

typedef long long ll;

struct node{
    ll index;
    ll rDot;
    ll tDot;
    vi neighbours;
};


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, l, s, t; cin >> n >> l >> s >> t;

    vector<node> nodes(n);

    FOR(i,0,n){
        nodes[i].index = i;
        nodes[i].rDot = 0;
        nodes[i].tDot = 0;
    }

    FOR(i,0,l){
        ll l, r; cin >> l >> r;

        nodes[l].neighbours.push_back(r);
        nodes[r].neighbours.push_back(l);
    }

    nodes[s].rDot = 1;


    unordered_set<ll> tdNodes{s};
    unordered_set<ll> vNodes{s};


    ll out = 0;

    while(t--){

        vNodes.clear();

        for(auto & x : tdNodes){
            
            ll pRDot = nodes[x].rDot;

            FOR(j,0,nodes[x].neighbours.size()){

                ll nIndex = nodes[x].neighbours[j];

                nodes[nIndex].tDot += nodes[x].rDot;

                if(t == 0) out += nodes[x].rDot;

                vNodes.insert(nIndex);
            }
        }

        for(auto & x: vNodes){
            nodes[x].rDot = nodes[x].tDot;
            nodes[x].tDot = 0;
        }

        tdNodes = vNodes;
    }

    cout << out << endl;

    return 0;
}
