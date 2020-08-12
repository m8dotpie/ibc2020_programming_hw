#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, bool> > a(2 * k);
    for (int i = 0; i < k; ++i) {
        std::cin >> a[i].first >> a[k + i].first;
        a[i].first--;
        a[i].second = true;
        a[k + i].second = false;
    }

    std::sort(a.begin(), a.end());
    
    std::vector<bool> alive(n);
    int cnt = 0, it = 0;
    for (int i = 0; i < n; ++i) {
        while (it < 2 * k && a[it].first <= i) {
            if (a[it].second) {
                cnt++;
            } else {
                cnt--;
            }
            it++;
        }
        if (!cnt) {
            alive[i] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << (alive[i] ? 'I' : '.');
    }
}
