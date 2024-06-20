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


#define X 200 
#define Y 300
#define dToRad(degree) degree *  M_PI / static_cast<double> (180)

#define xCord static_cast<int>(floor(r * cos(dToRad(d))))
#define yCord static_cast<int>(floor(r * sin(dToRad(d))))

inline bool inRange(int x, int y){return (x >= 0 && x <= X) && (y >= 0 && y <= Y);}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; std::cin >> n;

    //blocked = 1
    vvi grid(X+1, vi(Y+1, 0));

    FOR(i,0,n){
        int x, y, r; std::cin >> x >> y >> r;

        for(double d = 0; d < 360; d++){
            if (inRange(xCord, yCord))
                grid[xCord][yCord] != 1;
        }



        //assuming the rbot thakes up the entire square (smh)


    }

    return 0;
}