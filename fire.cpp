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

#define vc vector<char>
#define vvc vector<vc>
#define FIRE true
#define DUDE false

int sizeX, sizeY;
vector<pii> moves = {{1,0},{-1,0},{0,1},{0,-1}};


bool dInRange(int x, int y){return (x >= 0 && x <= sizeX + 1) && (y >= 0 && y <= sizeY + 1);}
bool fInRange(int x, int y){return (x >= 1 && x <= sizeX) && (y >= 1 && y <= sizeY);}

// pass out by reference so that we dont have to copy upon return
queue<pii> solve(queue<pii> & q, vvc & grid, bool isFire){
    queue<pii> out;
    while(!q.empty()){
        int cX = q.front().f, cY = q.front().s;
        q.pop();

        fe(dir,moves){
            int nX = dir.f + cX, nY = dir.s + cY;

            if(isFire){
                if(fInRange(nX, nY)){
                    if(grid[nX][nY] == '.' || grid[nX][nY] == '@'){
                        grid[nX][nY] = '*'; //we burning stuff today
                        out.push({nX, nY});
                    }
                }
            }
            else{
                if(dInRange(nX, nY)){
                    if(grid[nX][nY] == '.'){
                        grid[nX][nY] = '@'; // run little dude
                        out.push({nX, nY});
                    }
                }
            }

        }
    }
    return out;
}

queue<pii> dudesLeft(queue<pii> & q, vvc & grid){
    queue<pii> out;
    while(!q.empty()){
        pii t = q.front(); q.pop();
        if(grid[t.f][t.s] != '*') out.push(t);
    }

    return out;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases; cin >> cases;

    FOR(_,0,cases){
        cin >> sizeY >> sizeX;
        vvc grid(sizeX+2, vc(sizeY+2, '.')); // room so the dude can excape

        FOR(x,1,sizeX+1) FOR(y,1,sizeY+1) cin >> grid[x][y];

            
        queue<pii> dudes;
        queue<pii> fires;

        FOR(x,0,sizeX+2){
            FOR(y,0,sizeY+2){
                if(grid[x][y] == '@') dudes.push({x,y});
                if(grid[x][y] == '*') fires.push({x,y});
            }
        }

        int time = 0;
        bool valid = false;

        while(!dudes.empty() || !fires.empty()){

            dudes = solve(dudes,grid, DUDE);
            fires = solve(fires, grid, FIRE);

            //check if bro made it to the edges
            FOR(i,0,sizeX+2) if(grid[i][0] == '@' || grid[i][sizeY+1] == '@') valid = true;
            FOR(i,0,sizeY+2) if(grid[0][i] == '@' || grid[sizeX+1][i] == '@') valid = true;

        
            dudes = dudesLeft(dudes,grid);
            time++;
            if(valid) break;
        }


        if(valid) cout << time << endl;
        else cout << "IMPOSSIBLE" << endl;

    }

    return 0;
}