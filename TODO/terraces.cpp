//terraces
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<queue>
#include<map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>

using namespace std;

struct point{
    int height;
    pair<int,int> n,w,s,e;
    int x, y;
    bool valid = true;
};

vector<point> grid;
int x, y;

void update(int i, int j){
    point curr = grid[i + j * x];

    if(curr.valid){
        grid[i + j * x].valid = false;

            if(curr.height == grid[curr.n.first + curr.n.second * x].height){
                if(curr.y != 0){
                    update(curr.n.first,curr.n.second);
                }
            }

            if(curr.height == grid[curr.w.first + curr.w.second * x].height){
                if(curr.x != 0){
                    update(curr.w.first,curr.w.second);
                }
            }

            if(curr.height == grid[curr.s.first + curr.s.second * x].height){
                if(curr.y != y -1){
                    update(curr.s.first,curr.s.second);
                }
            }

            if(curr.height == grid[curr.e.first + curr.e.second * x].height){
                if(curr.x != x-1){
                    update(curr.e.first,curr.e.second);
                }   
            }
    }
}


int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

    cin >> x >> y;

    

    FOR(i,0,y){
        FOR(j,0,x){
            point temp;
            int h;
            cin >> h;
            temp.height = h;
            temp.x = j;
            temp.y = i;


            if(j == 0){
                temp.w.first = temp.x; temp.w.second = temp.y;
                temp.e.first = temp.x + 1; temp.e.second = temp.y;
            }
            else if(j == x-1){
                temp.w.first = temp.x -1; temp.w.second = temp.y;
                temp.e.first = temp.x; temp.e.second = temp.y;
                
            }
            else{
                temp.w.first = temp.x -1; temp.w.second = temp.y;
                temp.e.first = temp.x + 1; temp.e.second = temp.y;
            }

            if(i == 0){
                temp.n.first = temp.x; temp.n.second = temp.y;
                temp.s.first = temp.x; temp.s.second = temp.y+1;
            }
            else if(i == y-1){
                temp.n.first = temp.x; temp.n.second = temp.y-1;
                temp.s.first = temp.x; temp.s.second = temp.y;
            }
            else{
                temp.n.first = temp.x; temp.n.second = temp.y-1;
                temp.s.first = temp.x; temp.s.second = temp.y+1;
            }
            grid.push_back(temp);
        }
    }

    int valid = 0;


    FOR(i,0,y * x){


        if(!grid[grid[i].n.first  + grid[i].n.second * x].valid &&
             grid[grid[i].n.first  + grid[i].n.second * x].height == grid[i].height){
            
            grid[i].valid = false;
            continue;

        }
        if(!grid[grid[i].s.first + grid[i].s.second* x].valid &&
             grid[grid[i].s.first  + grid[i].s.second* x].height == grid[i].height){
            
            grid[i].valid = false;            
            continue;

        }
        if(!grid[grid[i].w.first  + grid[i].w.second* x].valid &&
             grid[grid[i].w.first  + grid[i].w.second* x].height == grid[i].height){
            
            grid[i].valid = false;
            continue;

        }
        if(!grid[grid[i].e.first + grid[i].e.second* x].valid &&
             grid[grid[i].e.first  + grid[i].e.second* x].height == grid[i].height){
            
            grid[i].valid = false;
            continue;

        }

        int h = grid[i].height;


        if( grid[grid[i].n.first  + grid[i].n.second* x].height < h ||
            grid[grid[i].s.first  + grid[i].s.second* x].height < h ||
            grid[grid[i].w.first  + grid[i].w.second* x].height < h ||
            grid[grid[i].e.first  + grid[i].e.second* x].height < h){
                update(grid[i].x,grid[i].y);
                
        }


    }

    FOR(i,0,x*y){
        if(grid[i].valid){
             valid++;
        }
    }
    cout << valid << endl;


    return 0;
}
