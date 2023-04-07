//Card Trading
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<queue>
#include<map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>

using namespace std;
map<long long,pair<long long,long long>> prices;
map<long long,long long> diff;

bool sortCard(long long a, long long b){
    long long p1 = prices[a].first + prices[a].second;
    long long p2 = prices[b].first + prices[b].second;

    if(p1 != p2){
        return p1 < p2;
    }
    else{
        return prices[a].first < prices[b].first;
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, t, k;

    cin >> n >> t >> k;

    int * cards = new int[t + 1];
    FOR(i,0,n){
        int card;
        cin >> card;
        cards[card]++;
    }

    vi cardPrice;
    FORE(i,1,t){
        long long bP,sP;
        cin >> bP >> sP;
        cardPrice.push_back(i);

        long long buyPrice = (2 - cards[i]) * bP;
        long long sellPrice = cards[i] * sP;
        

        prices[i] = pair<long long, long long>(buyPrice,sellPrice);
    }

    sort(cardPrice.begin(),cardPrice.end(),sortCard);

    long long profit = 0;

    FOR(i,0,k){
        profit -= prices[cardPrice[i]].first;
    }
    FOR(i,k,t){
        profit +=  prices[cardPrice[i]].second;
    }
    cout << profit << endl;

    return 0;
}
