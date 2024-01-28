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
    int used;
};

typedef vector<node> vn;

int gRoot(int x, vn & arr){

    if(arr[x].root == x) return x;

    return gRoot(arr[x].root, arr);

}

void join(int x, int y, vn & arr){
    int rX = gRoot(x, arr), rY = gRoot(y, arr);

    if(rX == rY) return;

    if(rX < rY){
        arr[rX].size += arr[rY].size;
        arr[rX].used += arr[rY].used;
        arr[rY].root = arr[rX].root;
    }
    else{
        arr[rY].size += arr[rX].size;
        arr[rY].used += arr[rX].used;
        arr[rX].root = arr[rY].root;
    }

}

int isSpace(int x, vn & arr){
    int rX = gRoot(x, arr);

    if(++arr[rX].used <= arr[rX].size) return 1;

    arr[rX].used--;
    return 0;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c; cin >> n >> c;

    vn uf(c+1);

    FORE(i,1,c){
        uf[i].root = i;
        uf[i].size = 1;
        uf[i].used = 0;
    }

    FOR(i,0,n){
        int l, r; cin >> l >> r;

        join(l, r, uf);

        string out = isSpace(l, uf) ? "LADICA" : "SMECE";

        cout << out << endl;

    }

    return 0;
}
