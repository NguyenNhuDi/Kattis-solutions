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

typedef vector<bool> vb;
typedef vector<pii> vpi;

struct node{
    int pX, pY;
    int cost;

    bool operator < (const node & a) const{return cost > a.cost;} // make into a min priority queue
};
 

typedef priority_queue<node> pqn;

vpi moves = {
    {0,-1}, //N
    {1,-1}, //NE
    {1,0}, //E
    {1,1}, //SE
    {0,1}, //S
    {-1,1}, //SW
    {-1,0}, //W
    {-1,-1}, //NW
    };

int xSize, ySize;

bool inRange(int pX, int pY){
    return (0 <= pX && pX < xSize) && (0 <= pY && pY < ySize);
}


int dist[1000][1000];
node q[1001 * 1001];


void solve(int sX, int sY, int eX, int eY, vector<vi> & grid){
    int h = 0, t = 0;
    memset(dist, -1, sizeof(dist));
    int out = -1;

    node sNode; sNode.pX = sX; sNode.pY = sY; sNode.cost = 0;
    q[t++] = sNode;

    dist[sX][sY] = 0;

    int counter = 0;
    
    while(h < t){
        FOR(i,h,t){
            int cX = q[i].pX, cY = q[i].pY, cC = q[i].cost;
            pii dir = moves[grid[cX][cY]];

            int nX = cX + dir.s, nY = cY + dir.f;
            if(inRange(nX, nY) && dist[nX][nY] == -1){
                sNode.pX = nX; sNode.pY = nY; sNode.cost = cC;
                dist[nX][nY] = cC;
                q[t++] = sNode;
            }
        }

        int cT = t;
        while(h < cT){
            int cX = q[h].pX, cY = q[h].pY, cC = q[h].cost + 1;

            FOR(i,0,8){
                pii dir = moves[i];
                int nX = cX + dir.s, nY = cY + dir.f;
                if(inRange(nX, nY) && dist[nX][nY] == -1){
                    sNode.pX = nX; sNode.pY = nY; sNode.cost = cC;
                    dist[nX][nY] = cC;
                    q[t++] = sNode;
                }
            }
            h++;
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> xSize >> ySize;
    vector<vi> grid(xSize, vi(ySize));

    FOR(i,0,xSize){
        string inpoo; cin >> inpoo;
        FOR(j, 0, ySize) grid[i][j] = inpoo[j] - '0';
    }

    int n; cin >> n;
    FOR(i,0,n){
        int sX, sY, eX, eY; cin >> sX >> sY >> eX >> eY;

        sX -= 1; sY -=1; eX -=1; eY -=1;

        solve(sX, sY, eX, eY, grid);
        cout << dist[eX][eY] << endl;
    }

    return 0;
}