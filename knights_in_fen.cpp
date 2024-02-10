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

typedef vector<vector<char>> board;
typedef map<board, int> boards;

set<pair<int,int>> legalMoves = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}    
};


boards build(){

    board init = {
        {'1', '1', '1', '1', '1'},
        {'0', '1', '1', '1', '1'},
        {'0', '0', ' ', '1', '1'},
        {'0', '0', '0', '0', '1'},
        {'0', '0', '0', '0', '0'},
    };

    boards out;
    out[init] = 0;

    queue<board> q;
    q.push(init);

    while(1){
        board cB = q.front(); q.pop();

        if(out[cB] == 10) break;

        int bx, by;

        FOR(y,0,5){
            FOR(x,0,5){
                if (cB[y][x] == ' '){
                    bx = x; by = y;
                }
            }
        }
        board c = cB;
        fe(i, legalMoves){
            int x = bx + i.second;
            int y = by + i.first;

            if((x >= 0 && x <= 4) && (y >= 0 && y <= 4)){
                swap(c[y][x], c[by][bx]);

                if(out.count(c) == 0){
                    q.push(c);
                    out[c] = out[cB] + 1; 
                }
                swap(c[y][x], c[by][bx]);
            }

        }
    }

    return out;

}



int main(){


    boards allBoards = build();

    board cB(5, vector<char>(5));

    int n; cin >> n;
    FOR(i,0,n){

        FOR(y,0,5){
            cin.ignore();
            FOR(x,0,5) cB[y][x] = getchar();
            
        }

        if(allBoards.count(cB)){
            cout << "Solvable in " << allBoards[cB] << " move(s)." << endl;
        }
        else{
            cout << "Unsolvable in less than 11 move(s)." << endl;
        }
    }

    return 0;
}