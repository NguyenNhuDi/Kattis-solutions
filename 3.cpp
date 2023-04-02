//union-find

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

int setFind(int num, int * all){

    if(all[num] < 0){
        return num;
    }

    num = all[num];
    return setFind(num, all);

}

void setUnion(int a, int b, int * all){
    int rootA, rootB;
   
    rootA = setFind(a, all);
    rootB = setFind(b, all);


    if(rootA == rootB){
        return;
    }

    if(all[rootA] <= all[rootB]){
        all[rootA] += all[rootB];
        all[rootB] = rootA;
    }
    else{
        all[rootB] += all[rootA];
        all[rootA] = rootB;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int * all = new int[n];

    FOR(i,0,n){
        all[i] = -1;
    }

    FOR(i,0,q){
        int l, r;
        char op;
        cin >> op >> l >> r;

        if(op == '?'){
            if(setFind(l,all) == setFind(r,all)){
                cout << "yes\n";
            }
            else{
                cout << "no\n";
            }
        }
        else{
            setUnion(l,r, all);
        }
    }


    return 0;
}