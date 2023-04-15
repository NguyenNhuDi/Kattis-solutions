//City Numbers
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

struct node{
    int pos;
    int parent;
    si childrens;
};


void buildTree(node & curr, int parent, vector<node> & arr){
    curr.parent = parent;
    curr.childrens.erase(parent);

    if(curr.parent != curr.pos){
        curr.childrens.erase(curr.pos);
    }

    for(auto & x : curr.childrens){
        buildTree(arr[x],curr.pos,arr);
    }

}
vector<node> cities;
int k;
int counter;

vector<vi> dp;

int f(node & n, int x){
    //leaf node
    if(SIZE(n.childrens) == 0){
        return x;
    }

    if(dp[n.pos][x] >= 0){
        return dp[n.pos][x];
    }

    bool illegal = true;
    int out = x;
    for(auto & child : n.childrens){
        int mini = INT32_MAX;
        FORE(i,1,k){
            if(i != x){
                illegal = false;
                int currF = f(cities[child],i);
                mini = min(currF,mini);
                if(mini == -1){
                    return -1;
                }
                counter++;
            }
        }
        out += mini;
    }

    if(illegal){
        return -1;
    }

    dp[n.pos][x] = out;
    return out;
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n >> k;
    

    FOR(i,0,n){
        node city;
        city.pos = i;
        city.parent = -1;
        city.childrens.insert(i);
        cities.push_back(city);
      
    }
    dp.assign(n,vi(k+1,-1));


    //building the conections
    FOR(i,0,n-1){
        int a, b;
        cin >> a >> b;
        a--;b--;
        cities[a].childrens.insert(b);
        cities[b].childrens.insert(a);

    }

    buildTree(cities[0],0,cities);

    
    for(const auto & x : cities){
        FORE(i,1,k){
            FORE(j,1,k){
                counter++;
            }
        }
    }


    counter = 0;
    int out = INT32_MAX;
    FORE(i,1,k){
        int t = f(cities[0],i);
        out = min(out, t);
    }

    cout << out << endl;

    return 0;
}
