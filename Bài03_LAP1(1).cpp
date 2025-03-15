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

    // Hàm cộng phân số
    PhanSo cong(const PhanSo &ps) const {
        double tuMoi = tuSo * ps.mauSo + mauSo * ps.tuSo;
        double mauMoi = mauSo * ps.mauSo;
        return PhanSo(tuMoi, mauMoi);
    }

    // Hàm trừ phân số
    PhanSo tru(const PhanSo &ps) const {
        double tuMoi = tuSo * ps.mauSo - mauSo * ps.tuSo;
        double mauMoi = mauSo * ps.mauSo;
        return PhanSo(tuMoi, mauMoi);
    }

    // Hàm nhân phân số
    PhanSo nhan(const PhanSo &ps) const {
        double tuMoi = tuSo * ps.tuSo;
        double mauMoi = mauSo * ps.mauSo;
        return PhanSo(tuMoi, mauMoi);
    }

    // Hàm chia phân số
    PhanSo chia(const PhanSo &ps) const {
        if (ps.tuSo == 0) {
            cout << "Lỗi: Không thể chia cho phân số có tử số bằng 0!" << endl;
            return *this; // Trả về phân số ban đầu
        }
        double tuMoi = tuSo * ps.mauSo;
        double mauMoi = mauSo * ps.tuSo;
        return PhanSo(tuMoi, mauMoi);
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
    PhanSo ps1, ps2;
    cout << "Nhập phân số 1:" << endl;
    ps1.nhap();
    cout << "Nhập phân số 2:" << endl;
    ps2.nhap();

    // Thực hiện các phép tính
    PhanSo ketQua;

    ketQua = ps1.cong(ps2);
    cout << "Kết quả phép cộng: ";
    ketQua.xuat();

    ketQua = ps1.tru(ps2);
    cout << "Kết quả phép trừ: ";
    ketQua.xuat();

    ketQua = ps1.nhan(ps2);
    cout << "Kết quả phép nhân: ";
    ketQua.xuat();

    ketQua = ps1.chia(ps2);
    cout << "Kết quả phép chia: ";
    ketQua.xuat();

    return 0;
}
