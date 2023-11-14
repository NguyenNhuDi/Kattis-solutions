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


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, R; cin >> n >> R;

    unordered_map<int, int> temp_pos;

    int min_x = INT32_MAX;
    int max_x = INT32_MIN;

    FOR(i,0,n){
        int t; cin >> t;

        min_x = min(min_x, t);
        max_x = max(max_x, t);
        
        if(temp_pos.find(t) != temp_pos.end()){
            temp_pos[t]++;
        }
        else{
            temp_pos[t] = 1;
        }
    }

    vi positions(max_x-min_x + 1, 0);

    fe(x, temp_pos){
        positions[x.first - min_x] += x.second;
    }

    //clearing mem
    temp_pos = unordered_map<int,int>();

    vi ans;

    int start_pos = 0;
    int end_pos = max_x - min_x + 1;
    while(1){
        bool all_zeroes = true;
        int max_killed = INT32_MIN;
        int killed = 0;
        int bomb_pos = -1;
        int actual_pos = -1;

        for(int r = start_pos; r < end_pos; r++){
            int l = r - 2 * R;

            if (positions[r] != 0){
                all_zeroes = false;
            }

            killed +=positions[r];

            if(l > 0){
                killed -= positions[l-1];
            }

            if(killed > max_killed){
                max_killed = killed;
                bomb_pos = (l + r + 2*min_x) / 2;
                actual_pos = (l + r) / 2;
            }

        }

        if(all_zeroes){ 
            break;
        }
        ans.push_back(bomb_pos);
        int ls = actual_pos - R < 0 ? 0 : actual_pos - R;
        int rs = actual_pos + R + 1;

        if (rs <= start_pos + 2*R){
            start_pos = rs;

        }

        if ((ls + min_x + 1) > end_pos - R*2){
            end_pos = ls;
        }

        FOR(i,ls,rs) positions[i] = 0;


    }

    cout << ans.size() << endl;
    fe(x, ans) cout << x << " ";
    cout << endl;



    return 0;
}
