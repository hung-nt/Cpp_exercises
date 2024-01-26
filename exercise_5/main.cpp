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
                break;
            }
        }
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
                break;
            }
        }
        return tien;
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
};

int main() {
    KhachSan ks;
    Nguoi n1("Nguyen Van A", 25, "123456789");
    Nguoi n2("Tran Thi B", 30, "987654321");
    Nguoi n3("Le Van C", 35, "456789123");

    ks.themKhach(n1, 3, 'A');
    ks.themKhach(n2, 2, 'B');
    ks.themKhach(n3, 1, 'C');

    cout << "Tien thue phong cua Nguyen Van A la: " << ks.tinhTien("123456789") << "$" << endl;

    ks.xoaKhach("987654321");

    ks.timKiemVaInDanhSach("123456789");

    return 0;
}
