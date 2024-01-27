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

int sum(vi & tree, int x){
    int out = 0;
    while(x > 0){
        out += tree[x];
        x -= x & -x; //flip last bit
    }
    return out;
}

void update(vi & tree, int x, int value){
    while(x < tree.size()){
        tree[x] += value;
        x += x & -x; //add last bit
    }
}

void build(vi & tree){
    FOR(i,1,tree.size()){
        int pI = i + (i & -i); //parent index
        if(pI < tree.size()){
            tree[pI] += tree[i];
        }
    }
}

void print(vi & tree){
    FOR(i,1,tree.size()) cout << tree[i] << " ";
    cout << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vi tree(n+1,1);

    build(tree);

    unordered_map<int, int> pTracker;

    FOR(i,1,n+1){
        int t; cin >> t;
        pTracker[t] = i;
    }

    int l = 1, r = n;

    FOR(i,1,n+1){
        //odd
        if(i % 2){
            int ans = sum(tree, pTracker[l]) -1;

            update(tree, pTracker[l], -1);
            cout << ans << endl;
            l++;
        }
        //even
        else{
            int ans = sum(tree, n) - sum(tree, pTracker[r]);

            cout << ans << endl;
            update(tree, pTracker[r], -1);
            r--;
        }

    }

    return 0;
}
