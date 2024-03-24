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

struct node{
    int root;
    int size;
};

typedef vector<node> vn;

int gRoot(int x, vn & uf){
    if(x == uf[x].root) return x;

    return gRoot(uf[x].root, uf);
}

void join(node x, node y, vn & uf){
    int rX = gRoot(x.root, uf);
    int rY = gRoot(y.root, uf);


    if (rX == rY) return;


    if(rX <= rY){
        uf[rY].root = rX;
        uf[rX].size += uf[rY].size;
    }
    else{
        uf[rX].root = rY;
        uf[rY].size += uf[rX].size;
    }

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;

    vn uf(n+1);

    FOR(i,0,n){
        uf[i].root = i;
        uf[i].size = 1;
    }

    FOR(i, 0, q){
        char op;
        cin >> op;

        if(op == 't'){
            int l, r; cin >> l >> r;

            join(uf[l], uf[r], uf);
        }
        else{
            int x; cin >> x;
            int rX = gRoot(x, uf);

            cout << uf[rX].size << endl;
        }
    }

    return 0;
}
Contact | Syste