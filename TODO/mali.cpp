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


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vi A(101), B(101), cA(101), cB(101);

    while(n--){
        int ans = -1;
        int a, b; cin >> a >> b;

        A[a]++; B[b]++;

        cA = A; cB = B;

        int currA = -1, currB = 101;

        while(1){
            FOR(i,currA + 1,102){
                currA = i;
                if(cA[i] != 0){
                    break;
                }
            }
            if(currA == 101) break;

            for(int i = currB - 1; i >= 0; i--){
                currB = i;
                if(cB[i] != 0){
                    break;
                }
            }

            if (currB == 0) break;

            int vA = cA[currA], vB = cB[currB];
            
            ans = max(ans, currA + currB);

            int mini = min(cA[currA], cB[currB]);
            cA[currA] -= mini; cB[currB] -= mini;

            if (vA < vB){
                currB++;
            }
            else if(vA == vB){
                currA--;
                currB++;
            }
            else{
                currA--;
            }

        }

        cout << ans << endl;


    }

    return 0;
}

