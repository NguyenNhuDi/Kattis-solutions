//Interview Preparation

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
#define pii pair<int,int>


using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B, T, tA, tB, c;
    cin >> A >> B >> T >> tA >> tB >> c;

    if(T == 0){
        long long out = 0;
        FOR(i,0,c){
            long long a, b;
            cin >> a >> b;
            if(a <= A && b <= B){
                out++;
            }
        }
        cout << out << endl;
        return 0;
    }

    vector<pair<long long,char>> tL;           //time line

    FOR(i,0,c){
        long long a, b;
        cin >> a >> b;
        a = (a - A) * tA;
        b = T - ((b - B) * tB);

     
        if(a <= b){
            tL.push_back(pair<long long,char>(a,'a'));
            tL.push_back(pair<long long,char>(b+1,'z'));
        }
        
       
    }

    sort(tL.begin(),tL.end());

    long long ans = 0;
    long long count = 0;

    bool update = false;

    long long prev = -1;

    for(const auto & x : tL){

        if(prev != x.first){
            update = true;
        }
        else{
            update = false;
        }

        if(update){
            ans = max(ans,count);
        }

        if(x.second == 'a'){
            count++;
        }
        if(x.second == 'z'){
            count--;
        }

        prev = x.first;

        
    }

    cout << ans << endl;

    return 0;
}
