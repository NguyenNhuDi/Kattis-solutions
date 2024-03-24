#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
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
#define ll long long
#define vl vector<ll>
#define vvl vector<vl>
struct edge{
    int end;
    int color;
    ll cost;
};

#define ve vector<edge>
#define vve vector<ve>


struct state{
    int colors;
    int cNode;
    ll traveled;
};

//can represent a color with 1, 10, 100. That way theres a diff between RO and RG
int convert(char c){
    if(c == 'R') return 1;
    else if(c == 'O') return 1 << 1;
    else if(c == 'Y') return 1 << 2;
    else if(c == 'G') return 1 << 3;
    else if(c == 'B') return 1 << 4;
    else if(c == 'I') return 1 << 5;
    else return 1 << 6;
}

ll nodes, edges;

bool sCompare(state a, state b){
    if(a.traveled == b.traveled){
        if(a.colors == b.colors){
            return a.cNode < b.cNode;
        }

        return a.colors < b.colors;
    }

    return a.traveled < b.traveled;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> nodes >> edges;

    vve aL(nodes+1);

    FOR(i,0,edges){
        int l, r; ll d; char color; cin >> l >> r >> d >> color;
        int c = convert(color);

        aL[l].push_back({r, c, d});
        aL[r].push_back({l, c, d});
    }

    vvl dist(1<<7, vl(nodes+1, LONG_LONG_MAX));
    // cost to to collect this many colors
    dist[0][1] = 0;

    set<state, decltype(&sCompare)> q(&sCompare);
    state s; s.cNode = 1; s.traveled = 0; s.colors = 0;
    q.insert(s);

    while(!q.empty()){
        state cState = *q.begin();

        int cNode = cState.cNode;
        int cColor = cState.colors;
        ll cDist = cState.traveled;

        q.erase(q.begin()); // queue pop

        for(edge &e : aL[cNode]){
            int next = e.end;
            ll cost = e.cost;
            int color = e.color;

            int nColor = color | cColor; // 10 | 1 = 11 (we have RO in this case)


            if(dist[nColor][next] > dist[cColor][cNode] + cost){
                q.erase({nColor, next, dist[nColor][next]}); //erase the one already in the queue
                dist[nColor][next] = dist[cColor][cNode] + cost;
                q.insert({nColor, next, dist[nColor][next]});
            }

        }

    }

    cout << dist[127][1] << endl;

    return 0;
}