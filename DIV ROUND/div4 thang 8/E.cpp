#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        // Tổng của tất cả các phần tử trong mảng
        long long totalSum = n * k + (n * (n - 1)) / 2;
        
        // Chia đôi tổng để tìm giá trị nhỏ nhất của |2 * S1 - T|
        // Nếu totalSum là chẵn thì kết quả là 0
        // Nếu totalSum là lẻ thì kết quả là 1
        long long result = totalSum % 2;

        cout << result << endl;
    }

    return 0;
}
