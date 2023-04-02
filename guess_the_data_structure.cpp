#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
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

    stack<int> s;
    priority_queue<int> pq;
    queue<int> q;

    int n, command, x;


    bool sCounter, pCounter, qCounter;
    
    while(cin >> n){
        sCounter = pCounter = qCounter = true;
        
        FOR(i,0,n){
            cin >> command >> x;

            if(command == 1){
                s.push(x);
                q.push(x);
                pq.push(x);

            }
            else{
                if(s.empty()){
                    sCounter = pCounter = qCounter = false;
                    continue;
                }
                if(s.top() != x){
                    sCounter = false;
                }
                if(pq.top() != x){
                    pCounter = false;
                }
                if(q.front() != x){
                    qCounter = false;
                }
                s.pop();
                pq.pop();
                q.pop();
            
            
            }
        }

        if((sCounter && pCounter) || (sCounter && qCounter) || (pCounter && qCounter)){
            cout << "not sure\n";
        }
        else if(sCounter){
            cout << "stack\n";
        }
        else if(pCounter){
            cout << "priority queue\n";
        }
        else if(qCounter){
            cout << "queue\n";
        }
        else{
            cout << "impossible\n";
        }
    
        while(!s.empty()){
            s.pop();
        }
        while(!q.empty()){
            q.pop();
        }
        while(!pq.empty()){
            pq.pop();
        }

   }

    return 0;
}
