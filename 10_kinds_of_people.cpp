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

bool inRange(int Y, int X, int cY, int cX){
    return 0 <= cY && cY < Y && 0 <= cX && cX < X;
}


void solve(vector<string> & inpoo, vvi & out, int Y, int X){
    vector<vector<bool>> visited(Y, vector<bool>(X, false));

    int id = 0;
    FOR(y,0,Y){
        FOR(x, 0, X){
            if(!visited[y][x]){
                stack<pii> s;
                s.push({y, x});
                visited[y][x] = true;

                while(!s.empty()){
                    int tY = s.top().f, tX = s.top().s;
                    s.pop();
                    out[tY][tX] = id;
                    for(int i = -1; i <= 1; i += 2){
                        // left rigt
                        if (inRange(Y, X, tY, tX + i) && inpoo[tY][tX + i] == inpoo[tY][tX] && !visited[tY][tX + i]){
                            visited[tY][tX + i] = true;
                            s.push({tY, tX + i});
                        }

                        // up down
                        if (inRange(Y, X, tY + i, tX) && inpoo[tY + i][tX] == inpoo[tY][tX] && !visited[tY + i][tX]){
                            visited[tY + i][tX] = true;
                            s.push({tY + i, tX});
                        }
                    }
                }
                id++;
            }

        }
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Y, X; cin >> Y >> X;

    vector<string> inpoo(Y);
    vvi key(Y, vi(X, -1));

    FOR(i,0,Y) cin >> inpoo[i];
    solve(inpoo, key, Y, X);

    

    int n; cin >> n;

    FOR(i,0,n){
        int sY, sX, eY, eX; cin >> sY >> sX >> eY >> eX;

        sY--; sX--; eY--; eX--;

        if (key[eY][eX] == key[sY][sX]){
            if(inpoo[sY][sX] == '0') cout << "binary" << endl;
            else cout << "decimal" << endl;
        }
        else cout << "neither" << endl;
    }


    return 0;
}