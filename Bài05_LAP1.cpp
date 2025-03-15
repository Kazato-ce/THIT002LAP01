#include <iostream>
using namespace std;

class DongHo {
private:
    int D;
    int M;
    int Y;

public:
    void Nhap() {
        cout<<"Nhap Ngay:";cin>>D;
        cout<<"Nhap Thang:";cin>>M;
        cout<<"Nhap Nam:";cin>>Y;
    }

    void Xuat() {
        cout<<"Ngay hien tai la: ";
        cout << D << "/" << M << "/" << Y << endl;
    }
    void ThemNgay(int n){
        D += n;
        while (D > Day(M, Y)) {
            D -= Day(M, Y);
            M++;
            if (M > 12) {
                M = 1;
                Y++;
            }
        }
    }
    void GiamNgay(int n){
        D -= n;
        while (D <= 0) {
            M--;
            if (M < 1) {
                M = 12;
                Y--;
            }
            D += Day(M, Y);
        }
    }
    void ThemThang(int n){
        M += n;
        while (M > 12) {
            M -= 12;
            Y++;
        }
        if (D > Day(M, Y)) {
            D = Day(M, Y);
        }
    }
    void GiamThang(int n){
        M -= n;
        while (M < 1) {
            M += 12;
            Y--;
        }
        if (D > Day(M, Y)) {
            D = Day(M, Y);
        }
    }
    void ThemNam(int n) {
        Y += n;
        if (D > Day(M, Y)) {
            D = Day(M, Y);
        }
    }
    void GiamNam(int n){
        Y -= n;
        if (Y < 0) {
            Y = 0;
        }
        if (D > Day(M, Y)) {
            D = Day(M, Y);
        }
    }
    void XuatThu(){
        cout<<"Ngay hien tai là "<< D << "/" << M << "/" << Y <<" là ";
        if(Week(D,M,Y)==1) cout<<"Chu Nhat";
        else cout<<"thu "<<Week(D,M,Y);
        cout<<endl;
    }
private:
    int Day(int x,int y){
   switch (x){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: {
            return 31;
            break;
        }
        case 4:
        case 6:
        case 9:
        case 11: {
            return 30;
            break;
        }
        case 2:{
                if(y%4==0&&y%100==0){
                    return 29;
                }else return 28;
            break;
        }
     }
   }
    int TN(int x,int y,int z){
       int s=x;
       for(int i=1;i<y;i++){
        s+=Day(i,y);
       }
   return s;
   }
    int Week(int x, int y,int z){
        return ((z-1)+(z-1)/4-(z-1)/100+(z-1)/400+TN(x,y,z))%7+1;
    }
};

int main() {
    DongHo DH;
    DH.Nhap();
    DH.Xuat();
    DH.XuatThu();
    int n;
    cout<<"Nhap so ngay can them ";cin>>n; DH.ThemNgay(n);DH.Xuat();
    cout<<"Nhap so ngay can giam ";cin>>n; DH.GiamNgay(n);DH.Xuat();
    cout<<"Nhap so thang can them ";cin>>n; DH.ThemThang(n);DH.Xuat();
    cout<<"Nhap so thang can giam ";cin>>n; DH.GiamThang(n);DH.Xuat();
    cout<<"Nhap so nam can them ";cin>>n; DH.ThemNam(n);DH.Xuat();
    cout<<"Nhap so nam can giam ";cin>>n; DH.GiamNam(n);DH.Xuat();
    cout<<"Thu sau khi thay doi cac buoc tren"<<endl;
    DH.XuatThu();
    return 0;
}
