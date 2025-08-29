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

#define IN_REC (x <= px) && (px <= (x + w)) && (y <= py) && (py <= (y + h)) 
#define TOP_LEFT (x <= px) && (px <= (x + r)) && (y <= py) && (py <= (y + r))
#define BOT_LEFT (x <= px) && (px <= (x + r)) && (y + h - r <= py) && (py <= (y + h))
#define TOP_RIGHT (x + w - r <= px) && (px <= (x + w)) && (y <= py) && (py <= (y + r))
#define BOT_RIGHT (x + w - r <= px) && (px <= (x + w)) && (y + h - r <= py) && (py <= (y + h))

bool solve(double px, double py, double cx, double cy, double r, bool left, bool top){
    double dist = std::sqrt(std::pow(cx - px, 2) + std::pow(cy - py, 2));
    if(top){
        if(left){
            if(px <= cx && py <= cy)
                return dist <= r;
            
            return true;
        }
        else{
            if(px >= cx && py <= cy)
                return dist <= r;
            return true;
        }
    }
    else{
        if(left){
            if(px <= cx && py >= cy)
                return dist <= r;
            return true;
        }
        else{
            if(px >= cx && py >= cy)
                return dist <= r;
            return true;
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; std::cin >> n;
    while(n--){
        double x, y, w, h, r; std::cin >> x >> y >> w >> h >> r;

        int m; std::cin >> m;

        while(m--){
            double px, py; std::cin >> px >> py;

            bool inside = false;

            if (IN_REC){
                if(TOP_LEFT){
                    inside = solve(px, py, x + r, y + r, r, true, true);
                }
                else if(BOT_LEFT){
                    inside = solve(px, py, x + r, y + h - r, r, true, false);
                }
                else if(TOP_RIGHT){
                    inside = solve(px, py, x + w - r, y + r, r, false, true);
                }
                else if(BOT_RIGHT){
                    inside = solve(px, py, x + w - r, y + h - r, r, false, false);

                }
                else{
                    inside = true;
                }
            }
            std::cout << ((inside) ? "inside" : "outside") << std::endl;
        }
        std::cout << std::endl;


    }
    
    return 0;
}
