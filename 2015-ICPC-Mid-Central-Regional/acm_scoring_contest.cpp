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

    long int time;
    char problem;
    string correct;


    long int right = 0;
    long int tTime = 0;


    map<char,int> problems;

    while(cin >> time >> problem >> correct){
        problems.insert(pair<char,int>(problem,0));

        if(correct == "right"){
            right += 1;
            tTime += time;

            tTime += problems.find(problem)->second * 20;
        }
        else{
            problems.find(problem)->second += 1;
        }
    }

    cout << right << " " << tTime << endl;


    return 0;
}
