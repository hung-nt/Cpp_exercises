#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Nguoi
{
private:
    string hoTen;
    int tuoi;
    string cmnd;
    char loaiPhong; 

public:
    Nguoi(string ht, int t, string c, char lp) : hoTen(ht), tuoi(t), cmnd(c), loaiPhong(lp) {}

    string getHoTen()
    {
        return hoTen;
    }

    int getTuoi()
    {
        return tuoi;
    }

    string getCMND()
    {
        return cmnd;
    }

    char getLoaiPhong()
    {
        return loaiPhong;
    }
};

class KhachSan
{
private:
    struct KhachInfo
    {
        Nguoi khach;
        int soNgayThueA;
        int soNgayThueB;
        int soNgayThueC;

        KhachInfo(Nguoi _khach) : khach(_khach), soNgayThueA(0), soNgayThueB(0), soNgayThueC(0) {}
    };

    vector<KhachInfo> dsKhach;
    const int giaA = 500;
    const int giaB = 300;
    const int giaC = 100;

public:
    void themKhach(Nguoi khach, int ngay, char loai)
    {
        for (int i = 0; i < dsKhach.size(); i++)
        {
            if (dsKhach[i].khach.getCMND() == khach.getCMND())
            {
                switch (loai)
                {
                case 'A':
                    dsKhach[i].soNgayThueA += ngay;
                    break;
                case 'B':
                    dsKhach[i].soNgayThueB += ngay;
                    break;
                case 'C':
                    dsKhach[i].soNgayThueC += ngay;
                    break;
                default:
                    cout << "Loai phong khong hop le." << endl;
                    return;
                }
                cout << "Them loai phong cho khach thanh cong." << endl;
                return;
            }
        }

        KhachInfo newKhachInfo(khach);
        switch (loai)
        {
        case 'A':
            newKhachInfo.soNgayThueA += ngay;
            break;
        case 'B':
            newKhachInfo.soNgayThueB += ngay;
            break;
        case 'C':
            newKhachInfo.soNgayThueC += ngay;
            break;
        default:
            cout << "Loai phong khong hop le." << endl;
            return;
        }

        dsKhach.push_back(newKhachInfo);
        cout << "Them moi khach thanh cong." << endl;
    }

    void xoaKhach(string cmnd)
    {
        for (int i = 0; i < dsKhach.size(); i++)
        {
            if (dsKhach[i].khach.getCMND() == cmnd)
            {
                cout << "Khach " << dsKhach[i].khach.getHoTen() << " dang thue cac loai phong: ";
                if (dsKhach[i].soNgayThueA > 0)
                    cout << "A ";
                if (dsKhach[i].soNgayThueB > 0)
                    cout << "B ";
                if (dsKhach[i].soNgayThueC > 0)
                    cout << "C ";

                cout << endl;

                cout << "Chon loai phong muon xoa (A/B/C): ";
                char loaiPhong;
                cin >> loaiPhong;


                switch (loaiPhong)
                {
                case 'A':
                    dsKhach[i].soNgayThueA = 0;
                    break;
                case 'B':
                    dsKhach[i].soNgayThueB = 0;
                    break;
                case 'C':
                    dsKhach[i].soNgayThueC = 0;
                    break;
                default:
                    cout << "Loai phong khong hop le." << endl;
                    return;
                }


                cout << "Xoa loai phong thanh cong." << endl;


                if (dsKhach[i].soNgayThueA == 0 && dsKhach[i].soNgayThueB == 0 && dsKhach[i].soNgayThueC == 0)
                {
                    dsKhach.erase(dsKhach.begin() + i);
                    cout << "Xoa khach thanh cong." << endl;
                }

                return;
            }
        }


        cout << "Khong tim thay khach hang co CMND " << cmnd << endl;
    }

    int tinhTien(string cmnd)
    {
        int tongTien = 0;
        bool found = false;

        for (int i = 0; i < dsKhach.size(); i++)
        {
            if (dsKhach[i].khach.getCMND() == cmnd)
            {
                int tienA = dsKhach[i].soNgayThueA * giaA;
                int tienB = dsKhach[i].soNgayThueB * giaB;
                int tienC = dsKhach[i].soNgayThueC * giaC;

                cout << "Tien thue phong loai A cua " << dsKhach[i].khach.getHoTen() << " la: " << tienA << "$" << endl;
                cout << "Tien thue phong loai B cua " << dsKhach[i].khach.getHoTen() << " la: " << tienB << "$" << endl;
                cout << "Tien thue phong loai C cua " << dsKhach[i].khach.getHoTen() << " la: " << tienC << "$" << endl;


                tongTien += tienA + tienB + tienC;
                found = true;
            }
        }

        if (!found)
        {
            cout << "Khong tim thay khach hang co CMND " << cmnd << endl;
        }

        return tongTien;
    }

    void timKiemVaInDanhSach(string cmnd)
    {
        for (int i = 0; i < dsKhach.size(); i++)
        {
            if (dsKhach[i].khach.getCMND() == cmnd)
            {
                cout << "Thong tin khach hang co CMND " << cmnd << ":" << endl;
                cout << "Ho ten: " << dsKhach[i].khach.getHoTen() << endl;
                cout << "Tuoi: " << dsKhach[i].khach.getTuoi() << endl;
                cout << "Loai phong thue: " << dsKhach[i].khach.getLoaiPhong() << endl; 
                cout << "So ngay thue A: " << dsKhach[i].soNgayThueA << endl;
                cout << "So ngay thue B: " << dsKhach[i].soNgayThueB << endl;
                cout << "So ngay thue C: " << dsKhach[i].soNgayThueC << endl;
                return;
            }
        }
        cout << "Khong tim thay khach hang co CMND " << cmnd << endl;
    }

    void hienThiKhachDangThue()
    {
        if (dsKhach.empty())
        {
            cout << "Khong co khach nao dang thue phong." << endl;
            return;
        }

        cout << "Danh sach khach dang thue phong:" << endl;
        for (int i = 0; i < dsKhach.size(); i++)
        {
            cout << "----------------------------------" << endl;
            cout << "Ho ten: " << dsKhach[i].khach.getHoTen() << endl;
            cout << "Tuoi: " << dsKhach[i].khach.getTuoi() << endl;
            cout << "Loai phong thue A: " << dsKhach[i].soNgayThueA << " ngay" << endl;
            cout << "Loai phong thue B: " << dsKhach[i].soNgayThueB << " ngay" << endl;
            cout << "Loai phong thue C: " << dsKhach[i].soNgayThueC << " ngay" << endl;
        }
        cout << "----------------------------------" << endl;
    }
};


int main()
{
    KhachSan ks;

    while (true)
    {
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

        switch (luaChon)
        {
        case 1:
        {
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

            Nguoi khach(hoTen, tuoi, cmnd, loaiPhong);
            ks.themKhach(khach, soNgayThue, loaiPhong);
            break;
        }
        case 2:
        {
            string cmnd;
            cout << "Nhap so CMND cua khach muon xoa: ";
            cin.ignore();
            getline(cin, cmnd);
            ks.xoaKhach(cmnd);
            break;
        }
        case 3:
        {
            string cmnd;
            cout << "Nhap so CMND de tinh tien thue phong: ";
            cin.ignore();
            getline(cin, cmnd);
            ks.tinhTien(cmnd);
            break;
        }
        case 4:
        {
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