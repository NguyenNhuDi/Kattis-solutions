#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<climits>
#include<queue>

using namespace std;

struct s{

    int l, r;
};


bool struct_sort(s a, s b){
    return a.l < b.l;
}

bool lock_sort(s a, s b){
    return a.r < b.r;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, lock;

    cin >> N >> lock;

    vector<s> all;

    for(int i = 0; i < N; i++){
        int l, r;
        s temp;
        cin >> l >> r;

        temp.l = l;
        temp.r = r;
        all.push_back(temp);
    }

    sort(all.begin(), all.end(), struct_sort);
    int counter = 0;

    vector<s> currUsed;
    vector<s> lockPrio;
    
    priority_queue<int> que;

    for(int i = 0; i < N; i++){
        while(!que.empty()){
            if(-que.top() > all[i].l){
                break;
            }
            if(-que.top() + lock >= all[i].l){
                counter++;
                que.pop();
                break;
            }
            que.pop();
            
        }
        que.push(-all[i].l - all[i].r);
    }

    cout << counter << endl;
    return 0;
}
