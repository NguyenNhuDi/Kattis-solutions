#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07
#define pii pair<int,int>
#define f first
#define s second

using namespace std;

#define rad d * M_PI / 180

#define inRange(x, y) 0 <= x && x <= 200 && 0 <= y && y <= 300

inline bool dfs(vvi & grid){

    // fe(row, grid){
    //     fe(elem, row)
    //         cout << elem << "";
    //     cout << endl;
    // }

    stack<pii> s;
    
    FOR(i,0,201)
        s.push({i, 0});
    
    vector<vector<bool>> visited(201, vector<bool>(301, false));

    while (!s.empty()){
        int cX = s.top().f;
        int cY = s.top().s;
        s.pop();

        if(inRange(cX, cY) && visited[cX][cY])
            continue;

        visited[cX][cY] = true;

        //destination reached
        if (cY == 300) return true;
        
        //check left neightbour
        int l = cX -1;

        if(inRange(l, cY) && !visited[l][cY] && grid[cY][l] != 1)
            s.push({l, cY});

        // check right neighbour
        int r = cX + 1;
        if(inRange(r, cY) && !visited[r][cY] && grid[cY][r] != 1)
            s.push({r, cY});

        // check top neighbour
        int t = cY + 1;
        if(inRange(cX, t) && !visited[cX][t] && grid[t][cX] != 1)
            s.push({cX, t});

        // check bottom neighbour
        int b = cY + 1;
        if(inRange(cX, b) && !visited[cX][b] && grid[b][cX] != 1)
            s.push({cX, b});

    }

    return false;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<vvi> grids;

    // building the grids
    vvi cGrid(301, vi(201, 0));
    FOR(i,0,n){
        int x, y; double r; cin >> x >> y >> r;

        for(double d = 0; d <= 360; d +=0.1){
            int xPos = x + static_cast<int>(floor(r * cos(rad)));
            int yPos = y + static_cast<int>(floor(r * sin(rad)));

            if(inRange(xPos, yPos))
                cGrid[yPos][xPos] = 1;

            xPos = x + static_cast<int>(ceil(r * cos(rad)));
            yPos = y + static_cast<int>(ceil(r * sin(rad)));
            
            if(inRange(xPos, yPos))
                cGrid[yPos][xPos] = 1;   
        }
        grids.push_back(cGrid);
    }

    FOR(i,0,n){
        if(!dfs(grids[i])){
            cout << i << endl;
            break;
        }
    }


    return 0;
}