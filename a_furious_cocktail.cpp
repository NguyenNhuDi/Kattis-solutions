#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<int> vi;

bool isSmall(int i, int j){
    return i > j;
}

int main(){

    int n, time;

    cin >> n >> time;

    vi allP;

    for(int i = 0; i < n; i++){
        int input;

        cin >> input;
        allP.push_back(input);
    }

    sort(allP.begin(), allP.end(), isSmall);

    int rest = allP.size() - 1;

    for(int i = 0; i < allP.size(); i++){

        if((rest - i) * time >= allP[i]){
            cout << "NO" << endl;
            return 0;
        }

    }

    cout <<"YES" << endl;



    return 0;
}
