#include <iostream>
#include <vector>

using namespace std;

vector<int> timViTriXuatHien(const vector<int>& A, const vector<int>& B) {
    vector<int> viTri;
    int n = A.size(), m = B.size();

    for (int i = 0; i <= m - n; i++) { // Duyệt qua mảng B
        bool found = true;
        for (int j = 0; j < n; j++) {
            if (B[i + j] != A[j]) { // Nếu có phần tử khác nhau, bỏ qua
                found = false;
                break;
            }
        }
        if (found) viTri.push_back(i); // Nếu tìm thấy, lưu vị trí
    }
    return viTri;
}

int main() {
    int n, m;
    cin >> n >> m;  // Nhập số phần tử của A và B

    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++) cin >> A[i];  // Nhập mảng A
    for (int i = 0; i < m; i++) cin >> B[i];  // Nhập mảng B

    vector<int> viTri = timViTriXuatHien(A, B);

    cout << viTri.size() << endl; // In số lần xuất hiện
    for (int pos : viTri) cout << pos << " "; // In các chỉ số bắt đầu
    cout << endl;

    return 0;
}
