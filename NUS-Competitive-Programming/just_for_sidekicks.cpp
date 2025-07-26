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
typedef vector<ll> vl;
typedef vector<vl> vvl;

ll sum(vl & tree, int x){
    ll out = 0;
    while(x > 0){
        out += tree[x];
        x -= x & -x; //flip last bit
    }
    return out;
}

void update(vl & tree, int x, ll value){
    while(x < tree.size()){
        tree[x] += value;
        x += x & -x; //add last bit
    }
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, q; cin >> n >> q;

    vvl trees(7, vl(n+1, 0));
    vl prices(7);

    FOR(i,1,7) cin >> prices[i];

    string inpoo; cin >> inpoo;

    vi gems(n+1, 0); // vector that hold the types

    FOR(i, 0, inpoo.size()){
        int type = inpoo[i] - '0';
        gems[i+1] = type;
        
        update(trees[type], i+1, 1);
    }

    FOR(i, 0, q){
        int op; cin >> op;

        if (op == 1){
            int index, type; cin >> index >> type;

            int cType = gems[index];

            update(trees[cType], index, -1);
            update(trees[type], index, 1);

            gems[index] = type;

        }
        else if (op == 2){
            int type; ll value; cin >> type >> value;

            prices[type] = value;

        }
        else{
            int l, r; cin >> l >> r;
            ll out = 0;
            FOR(i,1,7) out += (sum(trees[i], r) - sum(trees[i], l - 1)) * prices[i];
            cout << out << endl;
        }


    }

    return 0;
}