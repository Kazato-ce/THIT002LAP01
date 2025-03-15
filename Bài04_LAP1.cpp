#include <iostream>
#include <math.h>
using namespace std;

// Hàm tính giai thừa
int gt(int n) {
    if (n == 0 || n == 1) return 1;  // Xử lý trường hợp n = 0
    return n * gt(n - 1);
}

int main() {
    // Nhập giá trị cho x
    double x, t = 0, term;
    int n = 0;

    cout << "Nhap x: ";
    cin >> x;

    // Khởi tạo giá trị đầu tiên của sin(x) khi n==0;
    term = (pow(-1, n) * pow(x, 2 * n + 1)) / gt(2 * n + 1);

    while (fabs(term) > 0.00001) {  // Dừng khi giá trị tuyệt đối nhỏ hơn 0.00001
        t += term;
        n++;
        term = (pow(-1, n) * pow(x, 2 * n + 1)) / gt(2 * n + 1);
    }

    cout << "Gia tri cua sin(x) xap xi: " << t << endl;
    return 0;
}
