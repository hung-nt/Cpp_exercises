#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Nguoi {
private:
    string hoTen;
    int tuoi;
    string cmnd;

public:
    Nguoi(string ht, int t, string c) : hoTen(ht), tuoi(t), cmnd(c) {}

    string getHoTen() {
        return hoTen;
    }

    int getTuoi() {
        return tuoi;
    }

    string getCMND() {
        return cmnd;
    }
};

class KhachSan {
private:
    vector<Nguoi> dsKhach;
    vector<int> soNgayThue;
    vector<char> loaiPhong;
    const int giaA = 500;
    const int giaB = 300;
    const int giaC = 100;

public:
    void themKhach(Nguoi khach, int ngay, char loai) {
        dsKhach.push_back(khach);
        soNgayThue.push_back(ngay);
        loaiPhong.push_back(loai);
    }

    void xoaKhach(string cmnd) {
        for (int i = 0; i < dsKhach.size(); i++) {
            if (dsKhach[i].getCMND() == cmnd) {
                dsKhach.erase(dsKhach.begin() + i);
                soNgayThue.erase(soNgayThue.begin() + i);
                loaiPhong.erase(loaiPhong.begin() + i);
                cout << "Xoa khach thanh cong." << endl;
                return;
            }
        }
        cout << "Khong tim thay khach hang co CMND " << cmnd << endl;
    }

    int tinhTien(string cmnd) {
        int tien = 0;
        for (int i = 0; i < dsKhach.size(); i++) {
            if (dsKhach[i].getCMND() == cmnd) {
                char loai = loaiPhong[i];
                int ngay = soNgayThue[i];
                if (loai == 'A') {
                    tien = ngay * giaA;
                } else if (loai == 'B') {
                    tien = ngay * giaB;
                } else if (loai == 'C') {
                    tien = ngay * giaC;
                }
                cout << "Tien thue phong cua " << dsKhach[i].getHoTen() << " la: " << tien << "$" << endl;
                return tien;
            }
        }
        cout << "Khong tim thay khach hang co CMND " << cmnd << endl;
        return 0;
    }

    void timKiemVaInDanhSach(string cmnd) {
        for (int i = 0; i < dsKhach.size(); i++) {
            if (dsKhach[i].getCMND() == cmnd) {
                cout << "Thong tin khach hang co CMND " << cmnd << ":" << endl;
                cout << "Ho ten: " << dsKhach[i].getHoTen() << endl;
                cout << "Tuoi: " << dsKhach[i].getTuoi() << endl;
                cout << "Loai phong thue: " << loaiPhong[i] << endl;
                cout << "So ngay thue: " << soNgayThue[i] << endl;
                return;
            }
        }
        cout << "Khong tim thay khach hang co CMND " << cmnd << endl;
    }

    void hienThiKhachDangThue() {
        if (dsKhach.empty()) {
            cout << "Khong co khach nao dang thue phong." << endl;
            return;
        }

        cout << "Danh sach khach dang thue phong:" << endl;
        for (int i = 0; i < dsKhach.size(); i++) {
            cout << "----------------------------------" << endl;
            cout << "Ho ten: " << dsKhach[i].getHoTen() << endl;
            cout << "Tuoi: " << dsKhach[i].getTuoi() << endl;
            cout << "Loai phong thue: " << loaiPhong[i] << endl;
            cout << "So ngay thue: " << soNgayThue[i] << endl;
        }
        cout << "----------------------------------" << endl;
    }
};

int main() {
    KhachSan ks;

    while (true) {
        cout << "------ MENU ------" << endl;
        cout << "1. Them moi khach" << endl;
        cout << "2. Xoa khach" << endl;
        cout << "3. Tinh tien thue phong" << endl;
        cout << "4. Tim kiem va in danh sach khach" << endl;
        cout << "5. Hien thi khach dang thue" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon: ";

        int luaChon;
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                string hoTen, cmnd;
                int tuoi, soNgayThue;
                char loaiPhong;

                cout << "Nhap ho ten: ";
                cin.ignore();
                getline(cin, hoTen);

                cout << "Nhap tuoi: ";
                cin >> tuoi;

                cout << "Nhap so CMND: ";
                cin.ignore();
                getline(cin, cmnd);

                cout << "Nhap loai phong (A/B/C): ";
                cin >> loaiPhong;

                cout << "Nhap so ngay thue: ";
                cin >> soNgayThue;

                Nguoi khach(hoTen, tuoi, cmnd);
                ks.themKhach(khach, soNgayThue, loaiPhong);
                break;
            }
            case 2: {
                string cmnd;
                cout << "Nhap so CMND cua khach muon xoa: ";
                cin.ignore();
                getline(cin, cmnd);
                ks.xoaKhach(cmnd);
                break;
            }
            case 3: {
                string cmnd;
                cout << "Nhap so CMND de tinh tien thue phong: ";
                cin.ignore();
                getline(cin, cmnd);
                ks.tinhTien(cmnd);
                break;
            }
            case 4: {
                string cmnd;
                cout << "Nhap so CMND de tim kiem va in danh sach khach: ";
                cin.ignore();
                getline(cin, cmnd);
                ks.timKiemVaInDanhSach(cmnd);
                break;
            }
            case 5:
                ks.hienThiKhachDangThue();
                break;
            case 0:
                cout << "Thoat chuong trinh. Tam biet!";
                return 0;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
        }
    }
    return 0;
}