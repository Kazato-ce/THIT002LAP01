#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <fstream>
#include <limits>
using namespace std;

class Ngay {
public:
    int d, m, y;

    bool xetnam(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool xetngay() {
        int ngaytrongthang[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (xetnam(y)) ngaytrongthang[2] = 29;
        return (m >= 1 && m <= 12) && (d >= 1 && d <= ngaytrongthang[m]);
    }

    void Nhap() {
        do {
            cout << "Nhap ngay bay : ";cin>>d;
            cout << "Nhap thang bay : ";cin>>m;
            cout << "Nhap nam bay : ";cin>>y;
            if (!xetngay()) cout << "Ngay khong hop le, vui long nhap lai!\n";
        } while (!xetngay());
    }

    void Xuat() const {
        cout << d << "/" << m << "/" << y;
    }

    bool operator<(const Ngay& other) const {
        if (y != other.y) return y < other.y;
        if (m != other.m) return m < other.m;
        return d < other.d;
    }
};

class Gio {
public:
    int H, M;

    bool xetgio() {
        return (H >= 0 && H < 24) && (M >= 0 && M < 60);
    }

    void Nhap() {
        do {
            cout << "Nhap gio bay : ";cin >> H;
            cout << "Nhap phut bay : ";cin >> M;
            if (!xetgio()) cout << "Gio khong hop le, vui long nhap lai!\n";
        } while (!xetgio());
    }

    void Xuat() const {
        cout << (H < 10 ? "0" : "") << H << ":" << (M < 10 ? "0" : "") << M;
    }

    bool operator<(const Gio& other) const {
        return (H != other.H) ? (H < other.H) : (M < other.M);
    }
};

class Maybay {
public:
    string MCB, NDdi, NDden;
    Ngay NB;
    Gio GB;

    bool isValidFlightCode(const string& code) {
        return regex_match(code, regex("^[A-Za-z0-9]{1,5}$"));
    }

    bool isValidPlace(const string& place) {
        return regex_match(place, regex("^[A-Za-zÀ-ỹ\\s]{1,20}$"));
    }

    void Nhap() {
        do {
            cout << "Nhap ma chuyen bay (Toi da 5 ky tu, khong dau cach): ";
            cin >> MCB;
            if (!isValidFlightCode(MCB)) cout << "Ma khong hop le, vui long nhap lai!\n";
        } while (!isValidFlightCode(MCB));

        cout << "Nhap ngay bay:\n";
        NB.Nhap();

        cout << "Nhap gio bay:\n";
        GB.Nhap();

        cin.ignore();
        do {
            cout << "Nhap noi di: ";
            getline(cin, NDdi);
            if (!isValidPlace(NDdi)) cout << "Noi di khong hop le, vui long nhap lai!\n";
        } while (!isValidPlace(NDdi));

        do {
            cout << "Nhap noi den: ";
            getline(cin, NDden);
            if (!isValidPlace(NDden)) cout << "Noi den khong hop le, vui long nhap lai!\n";
        } while (!isValidPlace(NDden));
    }

    void Xuat() const {
        cout << "Ma chuyen bay: " << MCB << "\nNgay bay: ";
        NB.Xuat();
        cout << "\nGio bay: ";
        GB.Xuat();
        cout << "\nNoi di: " << NDdi << "\nNoi den: " << NDden << "\n";
    }

    bool operator<(const Maybay& other) const {
        return (NB < other.NB) || (NB.y == other.NB.y && NB.m == other.NB.m && NB.d == other.NB.d && GB < other.GB);
    }
    string getMCB() const { return MCB; }
    string getNDdi() const { return NDdi; }
    string getNDden() const { return NDden; }
};

void TimKiemChuyenBay(const vector<Maybay>& danhSach, const string& key) {
    bool found = false;
    for (const auto& mb : danhSach) {
        if (mb.getMCB() == key || mb.getNDdi() == key || mb.getNDden() == key) {
            mb.Xuat();
            cout << "----------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay chuyen bay voi tu khoa: " << key << "!\n";
    }
}

void SapXepChuyenBay(vector<Maybay>& danhSach) {
    sort(danhSach.begin(), danhSach.end());
}

void LietKeChuyenBay(const vector<Maybay>& danhSach, string noiDi, Ngay ngay) {
    bool found = false;
    for (const auto& mb : danhSach) {
        if (mb.NDdi == noiDi && mb.NB.d == ngay.d && mb.NB.m == ngay.m && mb.NB.y == ngay.y) {
            mb.Xuat();
            found = true;
        }
    }
    if (!found) cout << "Khong co chuyen bay nao phu hop!\n";
}

int DemChuyenBay(const vector<Maybay>& danhSach, string noiDi, string noiDen) {
    int count = 0;
    for (const auto& mb : danhSach) {
        if (mb.NDdi == noiDi && mb.NDden == noiDen) count++;
    }
    return count;
}

void LuuFile(const vector<Maybay>& danhSach, const string& filename) {
    ofstream file(filename);
    for (const auto& mb : danhSach) {
        file << mb.getMCB() << " " << mb.getNDdi() << " " << mb.getNDden() << " "
             << mb.NB.d << " " << mb.NB.m << " " << mb.NB.y << " "
             << mb.GB.H << " " << mb.GB.M << "\n";
    }
    file.close();
}

void DocFile(vector<Maybay>& danhSach, const string& filename) {
    ifstream file(filename);
    Maybay mb;
    while (file >> mb.MCB >> mb.NDdi >> mb.NDden >> mb.NB.d >> mb.NB.m >> mb.NB.y >> mb.GB.H >> mb.GB.M) {
        danhSach.push_back(mb);
    }
    file.close();
}

int main() {
    vector<Maybay> danhSach;
int n;
            cout << "Nhap so luong chuyen bay: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                    cout << "\nNhap thong tin chuyen bay " << i + 1 << ":\n";
                    Maybay mb;
                    mb.Nhap();
                    danhSach.push_back(mb);
                    }

                cout << "\nDanh sach chuyen bay:\n";
                for (const auto& mb : danhSach) mb.Xuat();
                string key;
                 SapXepChuyenBay(danhSach);cout << "\nDanh sach chuyen bay sau khi sap xep:\n";
                for (const auto& mb : danhSach) mb.Xuat();
                cout << "\nNhap ma chuyen bay hoac noi di/den can tim: ";
                cin.ignore();
                getline(cin, key);
                TimKiemChuyenBay(danhSach, key);
                string noiDi,noiDen;
                Ngay ngay;
                cout << "\nNhap ngay va noi di de liet ke chuyen bay:\n";
                ngay.Nhap();
                cout << "Nhap noi di: ";
                cin.ignore();
                getline(cin, noiDi);
                LietKeChuyenBay(danhSach, noiDi, ngay);
                cout << "\nNhap noi di: "; cin.ignore();   getline(cin, noiDi);
                cout << "\nNhap noi den: "; cin.ignore();   getline(cin, noiDen);
                cout << "So chuyen bay: " << DemChuyenBay(danhSach, noiDi, noiDen) << "\n";

    return 0;
}
