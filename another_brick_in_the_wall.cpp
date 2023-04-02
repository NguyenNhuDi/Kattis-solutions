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

    int h, w, n;

    cin >> h >> w >> n;

    vi bricks;
    FOR(i,0,n){
        int length;
        cin >> length;
        bricks.push_back(length);
    }

    int currWidth = 0;
    int index = 0;
    int completed = 0;
    FOR(i,0,h){
        while(1){
            if(currWidth + bricks[index] > w){
                currWidth = 0;
                break;
            }
            else if(currWidth + bricks[index] == w){
                currWidth = 0;
                index++;
                completed++;
                break;
            }
            currWidth += bricks[index];
            index++;
        }
    }
    if(completed != h){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
    }

    

    return 0;
}
