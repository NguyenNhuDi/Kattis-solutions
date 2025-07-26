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


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, sX, sY, eX, eY;
    vector<pii> moves = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    while(cin >> x >> y >> sX >> sY >> eX >> eY){
        vector<vi> grid(x+1, vi(y+1, -1));

        grid[sX][sY] = 0;
        queue<pii> pos; pos.push({sX, sY});

        while(!pos.empty()){

            pii cPos = pos.front();
            pos.pop();


            int cX = cPos.f, cY = cPos.s;
            int cCost = grid[cX][cY];



            for(pii & i : moves){
                if((cX + i.f >= 1 && cX + i.f <= x && cY + i.s >= 1 && cY + i.s <= y) && grid[cX + i.f][cY + i.s] == -1){
                    grid[cX + i.f][cY + i.s] = cCost + 1;
                    pos.push({cX + i.f, cY + i.s});
                }
            }


        }


        if(grid[eX][eY] == -1) cout << "impossible" << endl;
        else cout << grid[eX][eY] << endl;


    }

    return 0;
}