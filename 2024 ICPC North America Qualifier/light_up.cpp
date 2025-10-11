#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define MOD 0x3b9aca07
#define f first
#define s second
#define IN(a, b) (a >= 0 && a < n && b >= 0 && b < n)

using namespace std;

using pii = std::pair<int, int>;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; std::cin >> n;
    std::vector<std::vector<char>> grid(n, std::vector<char>(n));

    std::unordered_map<char, std::vector<pii>> nums;
    std::vector<pii> bulbs;

    int open = 0;

    FOR(x, 0, n){
        FOR(y, 0, n){
            char in; std::cin >> in;

            if(in == '0' || in == '1' || in == '2' || in == '3' || in == '4'){
                nums[in].emplace_back(x, y);
            }
            else if(in == '?')
                bulbs.emplace_back(x, y);
            else if (in == '.')
                open++;

            grid[x][y] = in;
        }
    }

    bool valid = true;
    // Light up the grid
    fe(bulb, bulbs){

        // go left
        for(int i = (bulb.f - 1); i >= 0; i--){
            if(grid[i][bulb.s] == '?'){
                valid = false;
                break;
            }
            else if(grid[i][bulb.s] == 'Z')
               continue;
            else if(grid[i][bulb.s] == '.'){
                open--;
                grid[i][bulb.s] = 'Z';
            }
            else
                break;
        }

        // go right
        for(int i = (bulb.f + 1); i < grid.size(); i++){
            if(grid[i][bulb.s] == '?'){
                valid = false;
                break;
            }
            else if(grid[i][bulb.s] == 'Z')
               continue;
            else if(grid[i][bulb.s] == '.') {
                open--;
                grid[i][bulb.s] = 'Z';
            }
            else
                break;
        }

        // go up
        for(int i = (bulb.s - 1); i >= 0; i--){
            if(grid[bulb.f][i] == '?'){
                valid = false;
                break;
            }
            else if(grid[bulb.f][i] == 'Z')
               continue;
            else if(grid[bulb.f][i] == '.'){
                open--;
                grid[bulb.f][i] = 'Z';
            }
            else
                break;
        }

        // go down
        for(int i = (bulb.s + 1); i < grid.size(); i++){
            if(grid[bulb.f][i] == '?'){
                valid = false;
                break;
            }
            else if(grid[bulb.f][i] == 'Z')
               continue;
            else if(grid[bulb.f][i] == '.'){
                open--;
                grid[bulb.f][i] = 'Z';
            }
            else
                break;
        }
    }

    valid = open == 0 && valid;

    // Check nums
    fe(num, nums){
        fe(coord, num.s){
            int number = num.f - '0';

            // left
            if(IN(coord.f - 1, coord.s) && grid[coord.f - 1][coord.s] == '?')
                number--;
            // right 
            if(IN(coord.f + 1, coord.s) && grid[coord.f + 1][coord.s] == '?')
                number--;
            // up
            if(IN(coord.f, coord.s - 1) && grid[coord.f][coord.s - 1] == '?')
                number--;
            // down 
            if(IN(coord.f, coord.s + 1) && grid[coord.f][coord.s + 1] == '?')
                number--;
            
            if (number != 0)
                valid = false;
        }
    }

    std::cout << valid << std::endl;
    return 0;
}
