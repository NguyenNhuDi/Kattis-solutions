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
#define pii pair<int,int>
#define f first
#define s second

using namespace std;

int get_root(int x, vi & uf){
    if(x == uf[x]) return x;

    return get_root(uf[x], uf);
}

void join(int x, int y, vi & uf){
    int rX = get_root(x, uf), rY = get_root(y, uf);
    if (rX == rY) return;
    uf[rX] = rY; 
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    vi uf(n+1); FOR(i,0,n+1) uf[i] = i;

    FOR(i,0,m){
        int x, y; cin >> x >> y;
        join(x, y, uf);
    }

    int root = get_root(uf[1], uf);

    FOR(i,2,n+1){
        if(get_root(uf[i], uf) != root){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;


    return 0;
}