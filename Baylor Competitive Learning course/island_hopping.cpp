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
#define x first
#define y second
#define vpi vector<pii>
#define gDist(x, y) pow(pow(x.first - y.first, 2) + pow(x.second - y.second, 2), 0.5)

using namespace std;

struct uf{
    private:
        vi tree;
        int size;
    public:

        uf(int size){
            this->size = size;
            this->tree.resize(size);
        }

        int gRoot(int x){
            //get the root;
            int root = x;
            while(root != tree[root])
                root = tree[root];

            int temp;
            while(root != x){
                temp = tree[x];
                tree[x] = root;
                x = temp;
            }

            return root;

        }

        bool join(int x, int y){
            int rX = gRoot(x), rY = gRoot(y);

            if(rX == rY) 
                return false;

            tree[rY] = rX;
            
            return true;
        }
};


void solve(vector<pair<double, double>>  & input){
    map<int, vpi> dist;

    //generate all distances

    FOR(i,0,input.size()){
        FOR(j,i+1,input.size()){
            std::cout << i << " " << j << std::endl;
            dist[gDist(input[i], input[j])].push_back({i, j});
        }
    }

    fe(x, dist){
        std::cout << x.x << " | ";
        fe(y, x.y)
            std::cout << y.x << " " << y.y << " : ";

        std::cout << std::endl;
    }


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; std::cin >> n;

    FOR(i,0,n){
        int m; std::cin >> m;
        vector<pair<double, double>> coord(m);

        FOR(j,0,m)
            std::cin >> coord[j].x >> coord[j].y;

        solve(coord);

        std::cout << "----------------" << std::endl;
    }


    return 0;
}