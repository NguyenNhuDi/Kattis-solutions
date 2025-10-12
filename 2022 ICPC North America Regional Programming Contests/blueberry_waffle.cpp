//blue berry waffle

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


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n, m;
    cin >> n >> m;

    double rps = 180 /n;

    double rem = rps * m;

    while(abs(-1)){
        if(rem - 360 < 0){
            break;
        }
        else{
            rem -= 360;
        }
    }

    if(rem >= 90 && rem <= 270){
        cout << "down\n";
    }
    else{
        cout << "up\n";
    }


    return 0;
}
