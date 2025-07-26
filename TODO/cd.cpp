#include<iostream>
#include<unordered_set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    int x;

    while(N > 0 || M > 0){


        unordered_set<int> nCD;
        int counter = 0;

        for (int i = 0; i < N; i++){
            cin >> x;
            nCD.insert(x);
        }
        
        for(int i = 0; i < M; i++){
            cin >> x;

            if(nCD.count(x)){
                counter++;
            }
        }
        cout << counter << "\n";
        cin >> N >> M;
    }


    return 0;
}
