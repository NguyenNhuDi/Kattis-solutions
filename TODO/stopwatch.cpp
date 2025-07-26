#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

int bSearch(vector<int> a, int x){
    int size = a.size();
    int l = 0;
    int r = size - 1;
    int result = -1;
    while(l <= r){
        int m = (l + r) /2;
        if(a[m] <= x){
            l = m + 1;
            result = m;
        }
        else{
            r = m -1;
        }
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> all;
    int N;
    cin >> N;#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

int bSearch(vector<int> a, int x){
    int size = a.size();
    int l = 0;
    int r = size - 1;
    int result = -1;
    while(l <= r){
        int m = (l + r) /2;
        if(a[m] <= x){
            l = m + 1;
            result = m;
        }
        else{
            r = m -1;
        }
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

int bSearch(vector<int> a, int x){
    int size = a.size();
    int l = 0;
    int r = size - 1;
    int result = -1;
    while(l <= r){
        int m = (l + r) /2;
        if(a[m] <= x){
            l = m + 1;
            result = m;
        }
        else{
            r = m -1;
        }
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> all;
    int N;
    cin >> N;

    int time = 0;
    if(N % 2 != 0){
        cout << "still running\n";
        return 0;
    }
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        all.push_back(temp);
    }

    for(int i = 0; i < N-1; i+=2){
        time += all[i + 1] - all[i];
    }

    cout << time << "\n";

    return 0;
}
    
    vector<int> all;
    int N;
    cin >> N;

    int time = 0;
    if(N % 2 != 0){
        cout << "still running\n";
        return 0;
    }
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        all.push_back(temp);
    }

    for(int i = 0; i < N-1; i+=2){
        time += all[i + 1] - all[i];
    }

    cout << time << "\n";

    return 0;
}

    int time = 0;
    if(N % 2 != 0){
        cout << "still running\n";
        return 0;
    }
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        all.push_back(temp);
    }

    for(int i = 0; i < N-1; i+=2){
        time += all[i + 1] - all[i];
    }

    cout << time << "\n";

    return 0;
}
