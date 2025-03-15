#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>
using namespace std;
class HocSinh {
    string hoTen;
    float diemToan, diemVan, diemAnh, diemTB;

public:
    // Nhập thông tin học sinh (có kiểm tra hợp lệ)
    void nhap() {
        cin.ignore();
        while (true) {
            cout << "Nhap ho ten: ";
            getline(cin, hoTen);
            if (kiemTraHoTen(hoTen)) break;
            cout << "Ho ten khong hop le! Nhap lai.\n";
        }

        diemToan = nhapDiem("Toan");
        diemVan = nhapDiem("Van");
        diemAnh = nhapDiem("Anh");

        // Tính điểm trung bình
        diemTB = (2 * diemToan + diemVan + diemAnh) / 4;
    }

    // Xuất thông tin học sinh
   void xuat() {
    cout << left << "| " << setw(20) << hoTen
         << "| " << setw(6) << diemToan
         << "| " << setw(6) << diemVan
         << "| " << setw(6) << diemAnh
         << "| " << setw(6) << diemTB
         << "| " << setw(12) << xepLoai()
         << "|\n";
}

    // Xếp loại học sinh dựa vào điểm trung bình
    string xepLoai() {
        if (diemTB >= 9) return "Xuat sac";
        if (diemTB >= 8) return "Gioi";
        if (diemTB >= 6.5) return "Kha";
        if (diemTB >= 5) return "Trung binh";
        return "Yeu";
    }

    // Lấy điểm trung bình
    float getDiemTB() const { return diemTB; }

    // Lấy điểm Toán
    float getDiemToan() const { return diemToan; }
    float getDiemVan() const { return diemVan; }
    float getDiemAnh() const { return diemAnh; }

    // Lấy họ tên
    string getHoTen() const { return hoTen; }

    // Kiểm tra xem tên có chứa từ khóa tìm kiếm không
    bool timKiemTen(const string &tukhoa) {
        return hoTen.find(tukhoa) != string::npos;
    }

private:
    // Kiểm tra họ tên (không chứa số)
    bool kiemTraHoTen(const string &ten) {
        if (ten.empty()) return false;
        for (char c : ten)
            if (isdigit(c)) return false;
        return true;
    }

    // Nhập điểm với kiểm tra hợp lệ
    float nhapDiem(const string &mon) {
        float diem;
        while (true) {
            cout << "Nhap diem " << mon << ": ";
            cin >> diem;
            if (!cin.fail() && diem >= 0 && diem <= 10) break;
            cout << "Diem khong hop le! Nhap lai.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return diem;
    }
};
int main() {
    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    // Tạo danh sách học sinh
    vector<HocSinh> hs(n);

    // Nhập thông tin học sinh
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin hoc sinh " << i + 1 << ":\n";
        hs[i].nhap();
    }

    // Xuất danh sách học sinh
    cout << "\nDanh sach hoc sinh:\n";
    cout<<"_____________________________________________________________\n";
    for (int i = 0; i < n; i++) {
        hs[i].xuat();
    }
    cout<<"_____________________________________________________________\n";
    // Tìm kiếm học sinh theo tên
    cin.ignore();
    string timm;
    cout << "\nNhap ten hoc sinh can tim: ";
    getline(cin, timm);

    bool timThay = false;
    cout << "\nKet qua tim kiem:\n";
    for (int i = 0; i < n; i++) {
        if (hs[i].timKiemTen(timm)) {
            hs[i].xuat();
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Khong tim thay hoc sinh voi ten: " << timm << endl;
    }
// Tìm học sinh có điểm Toán thấp nhất
float dmin = 10;
for (int i = 0; i < n; i++) {
    if (hs[i].getDiemToan() < dmin) dmin = hs[i].getDiemToan();
}
cout << "\nDanh sách học sinh có điểm Toán thấp nhất:\n";
cout << setfill('_') << setw(40) << "_" << setfill(' ') << "\n";
cout << left << "| " << setw(20) << "Ho Ten" << "| " << setw(8) << "Diem Toan" << "|\n";
cout << setfill('_') << setw(40) << "_" << setfill(' ') << "\n";
for (int i = 0; i < n; i++) {
    if (hs[i].getDiemToan() == dmin) {
        cout << "| " << setw(20) << hs[i].getHoTen()
             << "| " << setw(8) << hs[i].getDiemToan()
             << "|\n";
    }
}
cout << setfill('_') << setw(40) << "_" << setfill(' ') << "\n";

// Tìm học sinh có điểm Anh thấp nhất
dmin = 10;
for (int i = 0; i < n; i++) {
    if (hs[i].getDiemAnh() < dmin) dmin = hs[i].getDiemAnh();
}
cout << "\nDanh sách học sinh có điểm Anh thấp nhất:\n";
cout << setfill('_') << setw(40) << "_" << setfill(' ') << "\n";
cout << left << "| " << setw(20) << "Ho Ten" << "| " << setw(8) << "Diem Anh" << "|\n";
cout << setfill('_') << setw(40) << "_" << setfill(' ') << "\n";
for (int i = 0; i < n; i++) {
    if (hs[i].getDiemAnh() == dmin) {
        cout << "| " << setw(20) << hs[i].getHoTen()
             << "| " << setw(8) << hs[i].getDiemAnh()
             << "|\n";
    }
}
cout << setfill('_') << setw(40) << "_" << setfill(' ') << "\n";

// Tìm học sinh có điểm Văn thấp nhất
dmin = 10;
for (int i = 0; i < n; i++) {
    if (hs[i].getDiemVan() < dmin) dmin = hs[i].getDiemVan();
}
cout << "\nDanh sách học sinh có điểm Văn thấp nhất:\n";
cout << setfill('_') << setw(40) << "_" << setfill(' ') << "\n";
cout << left << "| " << setw(20) << "Ho Ten" << "| " << setw(8) << "Diem Van" << "|\n";
cout << setfill('_') << setw(40) << "_" << setfill(' ') << "\n";
for (int i = 0; i < n; i++) {
    if (hs[i].getDiemVan() == dmin) {
        cout << "| " << setw(20) << hs[i].getHoTen()
             << "| " << setw(8) << hs[i].getDiemVan()
             << "|\n";
    }
}
cout << setfill('_') << setw(40) << "_" << setfill(' ') << "\n";
return 0;
}
