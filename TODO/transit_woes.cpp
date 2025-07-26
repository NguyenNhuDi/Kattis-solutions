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
#define foreach(x,y) for(const auto & x : y)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>
#define MOD 0x3b9aca07

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s, t, n;

    cin >> s >> t >> n;

    vi walkTime(n+1);
    vi busTime(n);
    vi waitTime(n);

    FOR(i,0,n+1){
        cin >> walkTime[i];
    }

    FOR(i,0,n){
        cin >> busTime[i];
    }

    FOR(i,0,n){
        cin >> waitTime[i];
    }

    int timeLeft = t-s;

    int counter = 0;

    int totalTime = 0;
    while (counter < n){

        //time it takes to walk to destination
        int walkT = walkTime[counter];

        totalTime += walkT;

        //time it takes to wait at the stop

        int leftOver = totalTime / waitTime[counter];


        int waitT = waitTime[counter] - totalTime;

        if (leftOver > 0){
            waitT = totalTime - waitTime[counter] * leftOver;
        }

        totalTime += waitT;

        // ride time

        totalTime += busTime[counter];

        counter++;
    }

    totalTime += walkTime[counter];

    if (totalTime < t){
        cout << "yes\n";
    }
    else{
        cout << "no\n";
    }

    return 0;
}
