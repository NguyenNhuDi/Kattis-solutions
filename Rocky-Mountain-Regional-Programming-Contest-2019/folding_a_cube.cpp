#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define fe(x, item) for (auto &x : item)
#define MOD 0x3b9aca07
#define f first
#define s second

#define VALID(a, b) ((dx == a && dy == b) || (dx == b && dy == a))

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  std::vector<string> inpoo(6);

  int min_y = 6;
  int max_y = -1;
  int min_x = 6;
  int max_x = -1;

  FOR(y, 0, 6) {
    std::cin >> inpoo[y];

    FOR(x, 0, 6) {
      if (inpoo[y][x] == '#') {
        min_y = std::min(y, min_y);
        max_y = std::max(y + 1, max_y);
        min_x = std::min(x, min_x);
        max_x = std::max(x + 1, max_x);
      }
    }
  }

  int dy = max_y - min_y;
  int dx = max_x - min_x;

  bool valid = true;
  if (VALID(4, 3)) {
    FOR(y, min_y, max_y - 1) {
      FOR(x, min_x, max_x - 1) {
        if (inpoo[y][x] == '.' && inpoo[y + 1][x] == '.' &&
            inpoo[y][x + 1] == '.' && inpoo[y + 1][x + 1] == '.') {
          valid = false;
          break;
        }
      }
      if (!valid)
        break;
    }
  } else if (VALID(5, 2)) {
    int sum = 0;
    if (dx == 5) {
      FOR(i, min_x, max_x) {
        if (inpoo[min_y][i] == '#')
          sum++;
      }
    } else {
      FOR(i, min_y, max_y) {
        if (inpoo[i][min_x] == '#')
          sum++;
      }
    }

    if (sum != 3)
      valid = false;

  } else {
    valid = false;
  }

  if (valid)
    std::cout << "can fold" << std::endl;
  else
    std::cout << "cannot fold" << std::endl;

  return 0;
}
