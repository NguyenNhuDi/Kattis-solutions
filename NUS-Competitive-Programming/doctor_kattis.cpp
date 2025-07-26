#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#include<cmath>
#include<climits>
#include<queue>
#include<map>
#include<unordered_map>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define FORE(i,a,b) for(int i = a; i <=b; i++)
#define SIZE(x) x.size()
#define vi vector<int>
#define usi unordered_set<int>
#define si set<int>

using namespace std;

struct cat{
    int arival;
    int iLvl;
    string name;


    bool operator < (const cat & c) const{
        if(iLvl != c.iLvl){
            return iLvl > c.iLvl;
        }
        return arival < c.arival;
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, comand, iLvl;
    int totalCat = 0;
    string name;
    cat c;
    cin >> n;

    set<cat> allCats;
    map<string, pair<int, int>> old;

    FOR(i,0,n){
        cin >> comand;

        if (comand == 0){

            
            cin >> name >> iLvl;

            c.arival = totalCat;
            c.iLvl = iLvl;
            c.name = name;

            allCats.insert(c);
            
            old[name] = {totalCat, iLvl};
            totalCat++;
        }
        else if(comand == 1){
            cin >> name >> iLvl;

            c.name = name;
            c.iLvl = old.at(name).second;

            c.arival = old.at(name).first;

            auto it = allCats.find(c); //find this cat in the set
            auto oldCat = *it;          //get its content by de reference

            allCats.erase(it);          //make it go bye bye
            oldCat.iLvl += iLvl;
            allCats.insert(oldCat);     //insert the new boi

            old.at(name).second = oldCat.iLvl; //update the map

        }
        else if(comand == 2){
            cin >> name;    

            c.name = name;
            c.arival = old.at(name).first;
            c.iLvl = old.at(name).second;

            allCats.erase(allCats.find(c));
        }

        else{
            if(allCats.empty()){
                cout << "The clinic is empty\n";
            }
            else{
                cout << (*allCats.begin()).name << endl;
            }
        }
    }

    return 0;
}
