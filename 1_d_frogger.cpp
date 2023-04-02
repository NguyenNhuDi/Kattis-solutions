#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<climits>
#include<queue>
#include<map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()

using namespace std;

typedef vector<int> vi;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, start, win;

    cin >> n >> start >> win;

    int index = --start;

    int squares[n];

    FOR(i,0,n){
        int temp; cin >> temp;
        squares[i] = temp;
    }

    
    set<int> visited;
    int moves = 0;
    while(1){
        if(index < 0){
            cout << "left\n";
            cout << moves << endl;
            return 0;
        }
        if(index >= n){
            cout <<"right\n";
            cout << moves << endl;
            return 0;
        }
        if(squares[index] == win){
            cout << "magic\n";
            cout << moves << endl;
            return 0;
        }

        if(visited.count(index)){
            cout << "cycle\n";
            cout << moves << endl;
            return 0;
        }
        visited.insert(index);
        index += squares[index];
        moves++;
    }

    return 0;
}
