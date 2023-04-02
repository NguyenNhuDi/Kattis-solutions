#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;


int main(){

    float N, M;

    cin >> N;

    vector<int> all;

    float sum = 0;

    for(int i = 0; i < N; i++){
        cin >> M;
        all.push_back(M);
    }

    for(int i = 0; i < all.size(); i++){

        if(all[i] >= 0){
            sum += all[i];
        }
        else{
            N--;
        }



    }

    cout << (sum / N) << endl;

    
    return 0;
}
