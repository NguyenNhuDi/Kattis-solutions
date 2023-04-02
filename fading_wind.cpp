//fading wind

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

    int h, k, v ,s;

    cin >> h >> k >> v >> s;

    int out = 0;

    while(h > 0){
        v += s;
        int temp = v /10;
        v -= max(1, temp);
        
        if(v >= k){
            h++;
        }
        if(0 < v && v < k){
            h--;
            if(h == 0){
                v = 0;
            }
        }

        if(v <= 0){
            h = v = 0;
        }
        out += v;

        if(s > 0){
            s--;
        }


    }
    cout << out << endl;

    return 0;
}
