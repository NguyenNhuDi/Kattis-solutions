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
#define fe(x,y) for(auto & x : y)
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;

typedef vector<pair<int,int>> vpii;

int bSearch(vpii & arr, int x, int l, int r){
    if (l >= r){
        return -1;
    }

    int m = (l + r) / 2;

    if(arr[m].first == x){
        return m;
    }
    else if(x < arr[m].first){
        return bSearch(arr, x, l, m);
    }
    else{
        return bSearch(arr, x, m+1, r);
    }
}

void bPrev(vpii & arr, vi & prev, int n){
    vi stack;

    FOR(i,0,n){
        while (stack.size() && arr[i].second > arr[stack[stack.size()-1]].second){
            stack.pop_back();
        }

        if (stack.size()){
            prev[i] = stack[stack.size() - 1];
        }

        stack.push_back(i);
    }

}

void bNext(vpii & arr, vi & next, int n){
    vi stack;

    FORD(i,n-1,0){
        while(stack.size() && arr[i].second > arr[stack[stack.size()-1]].second){
            stack.pop_back();
        }

        if(stack.size()){
            next[i] = stack[stack.size() - 1];
        }

        stack.push_back(i);
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    bool first = true;

    while(cin >> n){

        if (n == 0) return 0;

        if (first){
            first = false;
        }
        else{
            cout << endl;
        }


        vpii yR(n);
        vi prev;
        vi next;
        
        FOR(i,0,n){
            prev.push_back(i);
            next.push_back(i);
        }


        FOR(i,0,n){
            int y, r; cin >> y >> r;

            yR[i] = {y, r};
        }

        bPrev(yR, prev, n);
        bNext(yR, next, n);

        int m; cin >> m;

        FOR(i,0,m){
            int l, r; cin >> l >> r;

            int li = bSearch(yR, l, 0, n);
            int ri = bSearch(yR, r, 0, n);


            if(li  >= 0 && ri >= 0){
                // cout << "both exists" << endl;
                if(prev[ri] != li){
                    
                    cout << "false" << endl;
                }
                else{
                    if(r - l == ri - li){
                        cout << "true" << endl;
                    }
                    else{
                        cout << "maybe" << endl;
                    }
                }
            }
            else if(li == -1 && ri >= 0){
                // cout << "in right exists" << endl;
                if(yR[prev[ri]].first  - l <= 0 || yR[prev[ri]].first == yR[ri].first){
                    cout << "maybe" << endl;
                }
                else{
                    cout << "false" << endl;
                }
            }
            else if(li >= 0 && ri == -1 ){
                // cout << "in left exists" << endl;
                if(yR[next[li]].first - r > 0 || yR[next[li]].first == yR[li].first){
                    cout << "maybe" << endl;

                }
                 else{
                    cout << "false" << endl;
                }
            }
            else{
                // cout << "none exists" << endl;
                cout << "maybe" << endl;
            }


        }
    }

    return 0;
}