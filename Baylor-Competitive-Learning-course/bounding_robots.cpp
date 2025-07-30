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

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, h;
    while(std::cin >> w >> h){
        if(w == 0 && w == 0)
            break;

        int n; std::cin >> n;

        int bot_pos_x = 0, bot_pos_y = 0;
        int actual_pos_x = 0, actual_pos_y = 0;
        FOR(i, 0, n){
            string ins; std::cin >> ins;
            int move; std::cin >> move;

            if(ins == "u") {
                bot_pos_y += move;
                
                actual_pos_y += move;
                actual_pos_y = std::min(actual_pos_y, h - 1);
            
            }
            else if(ins == "d") {
                bot_pos_y -= move;
                
                actual_pos_y -= move;
                actual_pos_y = std::max(actual_pos_y, 0);
            }
            else if(ins == "r") {
                bot_pos_x += move;

                actual_pos_x += move;
                actual_pos_x = std::min(actual_pos_x, w - 1);
            }
            else {
                bot_pos_x -= move;

                actual_pos_x -= move;
                actual_pos_x = std::max(actual_pos_x, 0);
            }             
        }
        
        std::cout << "Robot thinks " << bot_pos_x << " " << bot_pos_y << std::endl;
        std::cout << "Actually at " << actual_pos_x << " " << actual_pos_y << std::endl;
        std::cout << std::endl;

    }

    return 0;
}
