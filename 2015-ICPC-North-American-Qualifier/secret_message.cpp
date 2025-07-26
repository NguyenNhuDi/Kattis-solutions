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
#define f first
#define s second

using namespace std;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    while(n--){
        string inpoo; cin >> inpoo;
        int l = inpoo.size();
        int k = (int) ceil(sqrt((double)l));
        vector<vector<char>> matrix(k, vector<char>(k, '*'));

        FOR(i,0,k){
            bool exit = false;
            FOR(j,0,k){
                int index = i * k + j;
                if(index >= l){ exit = true; break;}

                matrix[i][j] = inpoo[index]; 
            }
            if(exit) break;
        }

        FOR(i,0,k) for(int j = k-1; j >= 0; j--) if(matrix[j][i] != '*') cout << matrix[j][i]; 
        
        cout << endl;

    }


    return 0;
}