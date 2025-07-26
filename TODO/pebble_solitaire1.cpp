//Pebble Solitaire 1
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
#define FORD(i,a,b) for(int i = a; i >= b; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>

using namespace std;

map<string,int> dp;


int f(string & board){
    if(dp.find(board) != dp.end()){
        return dp[board];
    }  

    int left = 0, right = 0;

    //move stone left
    bool fMove = false;
    FORD(i,11,2){
        if(board[i] == 'o' && board[i - 1] == 'o' && board[i - 2] == '-'){
            string t = board;
            fMove = true;
            t[i--] = '-';
            t[i--] = '-';
            t[i] = 'o';
        
            left = max(left, f(t) + 1);
        }
    }
    //move stone right
    FOR(i,0,10){
        if(board[i] == 'o' && board[i + 1] == 'o' && board[i + 2] == '-'){
            string t = board;
            fMove = true;
            t[i++] = '-';
            t[i++] = '-';
            t[i] = 'o';
            right = max(right, f(t) + 1);
        }
    }

    if(!fMove){
        return dp[board] = 1;
    }

    return dp[board] = max(left,right);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    FOR(i,0,n){
        string board;


        cin >> board;
        int oCount = 0;
        for(const auto & x : board){
            if(x == 'o'){
                oCount++;
            }
        }
        cout << ++oCount - f(board) << endl;
    }




    return 0;
}
