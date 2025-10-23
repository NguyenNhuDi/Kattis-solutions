// supply routes
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
#define fe(x,y) for(const auto & x : y)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;

struct node{


    int name;
    int parent;

    node(int name, int parent){
        this->name = name;
        this->parent = parent;
    }
};

int getRoot(int i, vector<node> & cMap){
    node a = cMap[i];

    if (a.parent < 0){
        return a.name;
    }

    return getRoot(a.parent, cMap);

}

void connect(int l, int r, vector<node> &cMap){
    node a = cMap[l]; node b = cMap[r];

    int lRoot = getRoot(l, cMap);
    int rRoot = getRoot(r, cMap);

    if (lRoot == rRoot){
        return;
    }

    if(cMap[lRoot].parent <= cMap[rRoot].parent){
        cMap[lRoot].parent += cMap[rRoot].parent;
        cMap[rRoot].parent = lRoot;

    }
    else{
        cMap[rRoot].parent += cMap[lRoot].parent;
        cMap[lRoot].parent = rRoot;

    }

}

bool isConect(int l, int r, vector<node> & cMap){

    node a = cMap[l]; node b = cMap[r];

    int lRoot = getRoot(l, cMap);
    int rRoot = getRoot(r, cMap);

    return lRoot == rRoot ? true : false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int junct, street, q; cin >> junct >> street >> q;

    vector<node> cityMap;


    FOR(i,0,junct){
        cityMap.push_back(node(i, -1));
    }

    set<pair<int, int>> connections;

    FOR(i, 0, street){
        int l, r; 
        cin >> l >> r;

        int maxi = max(l, r);
        int mini = min(l, r);

        connections.insert(pair<int, int>(mini, maxi));
    }

    stack<vi> queries;
    FOR(i, 0, q){
        vi t;

        int task, l, r; cin >> task >> l >> r;

        t.push_back(task);
        t.push_back(l);
        t.push_back(r);

        queries.push(t);

        if(task == 0){

            int maxi = max(l, r);
            int mini = min(l, r);


            connections.erase(pair<int, int>(mini, maxi));
        }
    }

    fe(connection, connections){
        connect(connection.first, connection.second, cityMap);
    }
    stack<string> out;

    while (!queries.empty()){

        vi currQuery = queries.top();
        queries.pop();

        int task = currQuery[0];
        int l = currQuery[1];
        int r = currQuery[2];

        if (task){
            if (isConect(l, r, cityMap)){
                out.push("safe\n");
            }
            else{
                out.push("unsafe\n");
            }
        }
        else{
            connect(l, r, cityMap);
        }


    }

    while(!out.empty()){
        cout << out.top();
        out.pop();
    }
    return 0;
}
