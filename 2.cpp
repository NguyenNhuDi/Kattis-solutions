//thesaurus
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

struct item{
    string self;
    string parent;
}; 

//return index to root parent
int setFind(item a, map<string,int> & strArr, item * arr){

   if(a.self == a.parent){
        return strArr[a.self];
   }

    a.self = a.parent;
    a.parent = arr[strArr[a.self]].parent;

    return setFind(a,strArr,arr);    
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<string> essay(n);

    FOR(i,0,n){
        cin >> essay[i];
    }

    item  * allItem = new item[m * 2];
    map<string,int> allStr;
   
    int i = 0;
    int index = 0;
    while(i < m * 2){
        string t1, t2;
        cin >> t1 >> t2;

        item item1, item2;

        item1.self = t1;
        item2.self = t2;
        
        //they are both not in the map yet
        if(allStr.find(t1) == allStr.end() && allStr.find(t2) == allStr.end()){
            allStr[t1] = index;
            allStr[t2] = index + 1;

            //t1 is longer than t2
            if(SIZE(t1) > SIZE(t2)){
                item1.parent = t2;
                item2.parent = t2;
            }
            else{
                item1.parent = t1;
                item2.parent = t1;

            }

            allItem[index] = item1;
            allItem[index + 1] = item2;
            index += 2;
        }
        //t1 is not in the map, but t2 is
        else if(allStr.find(t1) == allStr.end() && allStr.find(t2) != allStr.end()){
            allStr[t1] = index;
            
            item2.parent = allItem[allStr[t2]].parent;
            int rootIndex = setFind(item2, allStr,allItem);
            
            //if t1 is longer or equal to t2 root parent
            if(SIZE(t1) >= SIZE(allItem[rootIndex].parent)){
                
                item1.parent = allItem[rootIndex].parent;
                allItem[index] = item1;
            }
            //t1 is shorter than t2 root parent
            else{
                item1.parent = t1;
                allItem[rootIndex].parent = t1;
                allItem[index] = item1;
            }
            index++;
        }
        else if(allStr.find(t1) != allStr.end() && allStr.find(t2) == allStr.end()){
            allStr[t2] = index;
            
            item1.parent = allItem[allStr[t1]].parent;
            int rootIndex = setFind(item1, allStr,allItem);
            
            //if t2 is longer or equal to t1 root parent
            if(SIZE(t2) >= SIZE(allItem[rootIndex].parent)){
                
                item2.parent = allItem[rootIndex].parent;
                allItem[index] = item2;
            }
            //t1 is shorter than t2 root parent
            else{
                item2.parent = t2;
                allItem[rootIndex].parent = t2;
                allItem[index] = item2;
            }
            index++;
        }
        //they are both in the map alr
        else{
            int rootIndex1 = setFind(allItem[allStr[t1]], allStr,allItem);
            int rootIndex2 = setFind(allItem[allStr[t2]], allStr,allItem);

            if(SIZE(allItem[rootIndex1].parent) > SIZE(allItem[rootIndex2].parent)){
                allItem[rootIndex1].parent = allItem[rootIndex2].parent;
            }else{
                allItem[rootIndex2].parent = allItem[rootIndex1].parent;
            }
        }

        i+= 2;
    }

    int out = 0;

    for(const auto & x : essay){
        if(allStr.find(x) == allStr.end()){
            out += SIZE(x);
        }
        else{
            int rootNode = setFind(allItem[allStr[x]],allStr,allItem);
            out += SIZE(allItem[rootNode].parent);
        }
    }

    cout << out << endl;

    // FOR(i,0,index){
    //     int rootIndex = setFind(allItem[i], allStr, allItem);
    //     cout << allItem[i].self << " : " << allItem[rootIndex].parent << endl;

    // }


    return 0;
}