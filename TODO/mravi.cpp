#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<climits>
#include<queue>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()

using namespace std;

typedef vector<int> vi;
typedef pair<double,int> pdi;
typedef vector<double>  vd;
typedef vector<vd> vvd;


struct node{
    
    int parent = -1;
    int nodeName = 1;
    double percent;
    int square;
    double required;
    int index;
};

typedef vector<node> vn;

double calculate(vn all, node curr){
    if(curr.parent == -1){
        return curr.required;
    }

    double required = curr.required;

    if(curr.square == 1){
        required = sqrt(required);
    }
    required /= (curr.percent / 100);

    all[curr.parent-1].required = required;

    node parent = all[curr.parent -1];


    return calculate(all,parent);

}

bool org(node a, node b){
    return a.nodeName < b.nodeName;
}

int main(){

    int N, parent, child, square;
    double percent;

    cin >> N;

    node temp;
    vn all;
    vi req;
    FOR(i,0,N){
        all.push_back(temp);
    }

    FOR(i,0,N-1){
        cin >> parent >> child >> percent >> square;
        
        all[i].parent = parent;
        all[i].nodeName = child;
        all[i].percent = percent;
        all[i].square = square;
    }
    sort(all.begin(),all.end(),org);
   
    FOR(i,0,N){
        double temp;
        cin >> temp;
        req.push_back(temp);
    }

    double max = 0;
    FOR(i,0,N){
        if(req[i] > 0){
            node  curr = all[i];

            curr.required = req[i];
            int parentIndex = curr.parent;
            
            double required = calculate(all,curr);

            if(required > max){
                max = required;
            }

        }
    }
    printf("%.4lf\n",max);
    
    return 0;
}
