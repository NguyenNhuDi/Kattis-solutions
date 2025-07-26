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

    string N, M;

    cin >> N >> M;

    reverse(N.begin(),N.end());
    reverse(M.begin(),M.end());

    while(N.size() < M.size()){
        N.push_back('0');
    }
    while(M.size() < N.size()){
        M.push_back('0');
    }

    string N1, M1;

    for(int i = 0; i < N.size(); i++){
        if(N[i] >= M[i]){
            N1.push_back(N[i]);
        }

        if(M[i] >= N[i]){
            M1.push_back(M[i]);
        }
    }

    while(N1[N1.size() -1] == '0' && N1.size() > 1){
        N1.pop_back();
    }
    while(M1[M1.size() -1] == '0' && M1.size() > 1){
        M1.pop_back();
    }

    reverse(N1.begin(),N1.end());
    reverse(M1.begin(),M1.end());

    if(N1.length() > 0){
        cout << N1 << endl;
    }
    else{
        cout << "YODA\n";
    }
    if(M1.length() > 0){
        cout << M1 << endl;
    }
    else{
        cout << "YODA\n";
    }


    return 0;
}
