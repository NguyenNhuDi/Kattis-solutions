#include <bits/stdc++.h>

struct point{
    long long x, y;

    point(long long x, long long y){this->x = x; this->y = y;};
};

struct node{
    std::string name;
    long long dist;

    node(point A, point B, point C, std::string name){
        this->name = name;

        long long dx = B.x - A.x;
        long long dy = B.y - A.y;
        this->dist = std::abs(dx * (C.y - A.y) - dy * (C.x - A.x));
    }

    bool operator<(const node & other){
        return this->dist < other.dist;
    }
};

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    size_t n; std::cin >> n;

    for(size_t i = 0; i < n; i++){
        long long x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        size_t o; std::cin >> o;

        std::vector<node> inpoo;

        long long mini = std::numeric_limits<long long>::max();

        for(size_t j = 0; j < o; j++){
            std::string name;
            long long x, y;
            std::cin >> name >> x >> y;

            node a(point(x1, y1), point(x2, y2), point(x, y), name);

            mini = std::min(mini, a.dist);
            inpoo.push_back(a);
        }

        for(const node & x : inpoo){
            if(x.dist == mini) std::cout << x.name << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
