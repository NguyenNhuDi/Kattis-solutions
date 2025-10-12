#include <bits/stdc++.h>
#include <string>

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define fe(x,item) for(auto & x : item)
#define MOD 0x3b9aca07
#define a first
#define b second

using namespace std;

vector<string> joiner(
    std::vector<string> & in, 
    std::unordered_map<string, pair<int, int>> & tracker, 
    size_t win
){
    std::vector<string> out;

    string curr = in[0];
    int a = tracker[curr].a;
    int b = tracker[curr].b;

    for(size_t i = 1; i < in.size(); i++){
        
        fe(c, in[i]){
            curr += c;

            if(tracker.find(curr) == tracker.end())
                tracker[curr] = {a + tracker[string(1, c)].a, b + tracker[string(1, c)].b};

            a = tracker[curr].a;
            b = tracker[curr].b;

            if(a == win || b == win){
                out.push_back(curr);
                curr = "";
                a = b = 0;
            }
        }
    }

    if (curr != "")
        out.push_back(curr);

    return out;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input; std::cin >> input;

    std::unordered_map<string, pair<int, int>> tracker;

    tracker["A"] = {1, 0};
    tracker["B"] = {0, 1};

    std::vector<string> arr;

    fe(x, input) arr.emplace_back(string(1, x));

    size_t k = 1;
    std::vector<size_t> out;
    while(1){
        size_t a_win = 0, b_win = 0;
        fe(x, arr){
            if (tracker[x].a == k)
                a_win++;
            else if(tracker[x].b == k)
                b_win++;
        }

        if (a_win > b_win)
            out.push_back(k);

        if(arr.size() == 1)
            break;

        arr = joiner(arr, tracker, ++k);
    }

    std::cout << out.size() << "\n";
    fe(x, out)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
