#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, fav;

    vector<pair<int,int>> all;

    cin >> N;


    for(int i = 0; i < N; i++){
        cin >> fav;
        all.push_back({i+1, fav});
    }

    int index = 0;

    int size = all.size();
    while (size >  1){
        fav = (index + all[index].second - 1) % size;

        if(fav == size -1){
            index = 0;
        }
        else{
            index = fav;
        }

        all.erase(all.begin() + fav);
        size = all.size();
    }

    cout << all.front().first << endl;
    return 0;
}
