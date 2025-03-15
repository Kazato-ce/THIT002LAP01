#include <iostream>
#include <cmath>
using namespace std;

class PhanSo {
private:
    double tuSo;   // Tử số (số thực)
    double mauSo;  // Mẫu số (số thực)

public:
    // Hàm khởi tạo
    PhanSo(double tu = 0, double mau = 1) : tuSo(tu), mauSo(mau) {
        if (mauSo == 0) {
            cout << "Mẫu số không thể bằng 0! Gán mẫu số mặc định là 1." << endl;
            mauSo = 1;
        }
        rutGon();
        dongHoa();
    }

    // Hàm nhập phân số
    void nhap() {
        cout << "Nhập tử số: ";
        cin >> tuSo;
        cout << "Nhập mẫu số: ";
        cin >> mauSo;
        if (mauSo == 0) {
            cout << "Mẫu số không thể bằng 0! Gán mẫu số mặc định là 1." << endl;
            mauSo = 1;
        }
        rutGon();
        dongHoa();
    }

    // Hàm xuất phân số
    void xuat() const {
        cout << "Phân số: " << tuSo << "/" << mauSo << endl;
    }

    // Hàm rút gọn phân số
    void rutGon() {
        double ucln = gcd(tuSo, mauSo);
        tuSo /= ucln;
        mauSo /= ucln;
        if (mauSo < 0) { // Đảm bảo mẫu số luôn dương
            tuSo = -tuSo;
            mauSo = -mauSo;
        }
    }

    // Hàm chuẩn hóa số thực thành số nguyên nếu có thể
    void dongHoa() {
        while (!check(tuSo) || !check(mauSo)) {
            tuSo *= 10;
            mauSo *= 10;
        }
    }
     void soSanh(const PhanSo& ps) const {
        double val1 = tuSo / mauSo;
        double val2 = ps.tuSo / ps.mauSo;

        cout << "So sánh: ";
        if (fabs(val1 - val2) < 1e-9) {
            cout << "Hai phân số bằng nhau.\n";
        } else if (val1 > val2) {
            cout << "Phân số thứ nhất lớn hơn phân số thứ hai.\n";
            this->xuat();
        } else {
            cout << "Phân số thứ nhất nhỏ hơn phân số thứ hai.\n";
            ps.xuat();
        }
    }
private:
    // Tìm ước chung lớn nhất cho số thực
    double gcd(double a, double b) {
        while (fabs(b) > 1e-9) {
            double temp = b;
            b = fmod(a, b);
            a = temp;
        }
        return fabs(a);
    }

    // Kiểm tra số có phải số nguyên không
    bool check(double a) {
        return floor(a) == a;
    }
};
int main() {
    PhanSo ps1,ps2;
    ps1.nhap();
    ps2.nhap();
    ps1.soSanh(ps2);

    return 0;
}
