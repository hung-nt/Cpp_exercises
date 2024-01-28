// main.cpp
#include "Khoa.h"
using namespace std;

int main()
{
    Khoa khoaCNTT("Cong Nghe Thong Tin");

    int soSinhVien;
    cout << "Nhap so sinh vien: ";
    cin >> soSinhVien;
    cin.ignore();

    for (int i = 0; i < soSinhVien; ++i)
    {
        cout << "Nhap loai sinh vien (1: Chinh quy, 2: Tai chuc): ";
        int loaiSinhVien;
        cin >> loaiSinhVien;
        cin.ignore();

        if (loaiSinhVien == 1)
        {
            SinhVienChinhQuy *svChinhQuy = new SinhVienChinhQuy();
            svChinhQuy->input();
            khoaCNTT.themSinhVien(svChinhQuy);
        }
        else if (loaiSinhVien == 2)
        {
            SinhVienTaiChuc *svTaiChuc = new SinhVienTaiChuc();
            svTaiChuc->input();
            khoaCNTT.themSinhVien(svTaiChuc);
        }
        else
        {
            cout << "Loai sinh vien khong hop le." << endl;
            --i;
        }
    }

    cout << "Danh sach sinh vien theo khoa:" << endl;
    for (const auto &sv : khoaCNTT.getDanhSachSinhVien())
    {
        sv->output();
        cout << "--------------------------------------------" << endl;
    }

    cout << "So sinh vien chinh quy: " << khoaCNTT.soSinhVienChinhQuy() << endl;

    SinhVien *svDauVaoCaoNhat = khoaCNTT.sinhVienDiemDauVaoCaoNhat();
    if (svDauVaoCaoNhat)
    {
        cout << "Sinh vien co diem dau vao cao nhat: " << endl;
        svDauVaoCaoNhat->output();
        cout << "--------------------------------------------" << endl;
    }
    else
    {
        cout << "Danh sach sinh vien rong." << endl;
    }

    std::vector<SinhVienTaiChuc *> svTaiChucDN = khoaCNTT.danhSachSinhVienTaiChucNoiLienKet("Dong Nai");
    cout << "Danh sach sinh vien tai chuc tai Dong Nai: " << endl;
    for (const auto &sv : svTaiChucDN)
    {
        sv->output();
        cout << "--------------------------------------------" << endl;
    }

    std::vector<SinhVien *> svDiemCaoHocKyCuoi = khoaCNTT.sinhVienDiemTrungBinhCaoNhatHocKy("HocKyCuoi", 8.0);
    cout << "Danh sach sinh vien co diem trung binh cao nhat o hoc ky cuoi (>= 8.0): " << endl;
    for (const auto &sv : svDiemCaoHocKyCuoi)
    {
        sv->output();
        cout << "--------------------------------------------" << endl;
    }

    SinhVien *svDiemCaoNhat = khoaCNTT.sinhVienDiemTrungBinhCaoNhat();
    if (svDiemCaoNhat)
    {
        cout << "Sinh vien co diem trung binh cao nhat: " << endl;
        svDiemCaoNhat->output();
        cout << "--------------------------------------------" << endl;
    }
    else
    {
        cout << "Danh sach sinh vien rong." << endl;
    }

    khoaCNTT.sapXepDanhSach();

    cout << "Danh sach sinh vien sau khi sap xep:" << endl;
    for (const auto &sv : khoaCNTT.getDanhSachSinhVien())
    {
        sv->output();
        cout << "--------------------------------------------" << endl;
    }

    cout << "Thong ke so luong sinh vien theo nam: " << endl;
    std::map<int, int> thongKe = khoaCNTT.thongKeSoLuongSinhVienTheoNam();
    for (const auto &entry : thongKe)
    {
        cout << "Nam " << entry.first << ": " << entry.second << " sinh vien" << endl;
    }

    return 0;
}
