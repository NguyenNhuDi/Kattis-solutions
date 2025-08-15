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

    std::vector<std::vector<char>> board(
        2001, std::vector<char>(2001, ' '));

    size_t x = 1000, y = 1000;

    
    size_t maxiX = x, miniX = x;
    size_t maxiY = y, miniY = y;
    
    
    std::string in;
    while(std::cin >> in){
        if(in == "down"){
            y++;
        }
        else if(in == "up"){
            y--;
        }
        else if(in == "right"){
            x++;
        }
        else{
            x--;
        }
        board[y][x] = '*';
        
        maxiX = std::max(maxiX, x);
        miniX = std::min(miniX, x);
        maxiY = std::max(maxiY, y);
        miniY = std::min(miniY, y);
    }
    board[1000][1000] = 'S';
    board[y][x] = 'E';

    FOR(i, miniY - 1, maxiY + 2){
        FOR(j, miniX - 1, maxiX + 2){

            if(i == miniY - 1 || i == maxiY + 1 || j == miniX - 1 || j == maxiX + 1){
                std::cout << "#";
            }
            else{
                std::cout << board[i][j];
            }
        }
        std::cout << std::endl;
    }


    return 0;
}
