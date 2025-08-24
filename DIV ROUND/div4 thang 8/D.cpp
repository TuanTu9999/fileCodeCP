#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        unordered_map<int, int> count_x, count_y;
        vector<pair<int, int>> points(n);
        
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            points[i] = {x, y};
            count_x[x]++;
            count_y[y]++;
        }
        
        long long result = 0;
        for (auto point : points) {
            int x = point.first;
            int y = point.second;
            // Tổng số tam giác có đỉnh tại điểm này
            result += (count_x[x] - 1) * (count_y[y] - 1);
        }
        
        cout << result << endl;
    }
    
    return 0;
}
