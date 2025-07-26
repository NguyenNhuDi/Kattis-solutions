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
#include<cstring>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = a; i >= b; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define fe(x,y) for(auto & x : y)
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07
#define f first
#define s second

using namespace std;

typedef vector<pair<int,int>> vp;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<char> vc;
typedef vector<pi> vpi;

bool sortNode2(pi a, pi b){
    return a.f > b.f || a.f == b.f && a.s < b.s;
}

bool sortNode(pi a, pi b){
    return a.f < b.f || a.f == b.f && a.s < b.s;
}


int lis(vi & nodes){


    if (nodes.size() == 0) return 0;

    vi lis = {nodes[0]};

    FOR(i,1, nodes.size()){

        int cPos = nodes[i];

        if(cPos >= lis.back()){
            lis.push_back(cPos);
        }
        else{
            int pos = upper_bound(lis.begin(), lis.end(), nodes[i]) - lis.begin();
            lis[pos] = nodes[i];

        }
    }
    return lis.size();

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, xH, yH, xW, yW; cin >> n >> xH >> yH >> xW >> yW;
    pi home = {xH, yH};
    pi work = {xW, yW};
    vpi nodes(n); FOR(i,0,n) cin >> nodes[i].f >> nodes[i].s;

    vi nodesY;

    if(home.f > work.f) swap(home, work);
    
    // if home is below work
    if(home.s < work.s){
        sort(nodes.begin(), nodes.end(), sortNode);

        FOR(i,0,n){

            pi cNode = nodes[i];
            if(cNode.f >= home.f && cNode.f <= work.f && cNode.s >= home.s && cNode.s <= work.s) nodesY.push_back(cNode.s);
        }
        cout << lis(nodesY) << endl;


    }
    // if work is below home
    else{
        sort(nodes.begin(), nodes.end(), sortNode2);

        FOR(i,0,n){
            pi cNode = nodes[i];
            if(cNode.f >= home.f && cNode.f <= work.f && cNode.s >= work.s && cNode.s <= home.s) nodesY.push_back(cNode.s);
        }
        cout << lis(nodesY) << endl;


    }
    return 0;
}