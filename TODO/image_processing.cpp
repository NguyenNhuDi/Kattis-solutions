//image processing

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


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int bH, bW, sH, sW;
    cin >> bH >> bW >> sH >> sW;

    int big[bH][bW];
    int small[sH][sW];

    FOR(i,0,bH){
        FOR(j,0,bW){
            cin >> big[i][j];
        }
    }

    FOR(i,0,sH){
        FOR(j,0,sW){
            cin >> small[i][j];
        }
    }

    int row, col,sum;

    row = bW - sW + 1;
    col = bH - sH + 1;

    FOR(i,0,col){
        FOR(j,0,row){     
            int c = sH -1;
            sum = 0;
            FOR(x,0,sH){
                int r = sW -1;
                FOR(y,0,sW){
                    sum += small[c][r] * big[x + i][y + j];
                    r--;
                }
                c--;
            }
            cout << sum << " ";
        }
        cout << endl;
    }

    return 0;
}
