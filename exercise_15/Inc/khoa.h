#ifndef _KHOA_H_
#define _KHOA_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "sinhvien.h"


using namespace std;
class Khoa {
private:
    string tenKhoa;
    vector<SinhVien*> danhSachSinhVien;

public:
    Khoa(string tenKhoa);
    void themSinhVien(SinhVien* sv);
    int soSinhVienChinhQuy() const;
    SinhVien* sinhVienDiemDauVaoCaoNhat() const;
    vector<SinhVienTaiChuc*> danhSachSinhVienTaiChucNoiLienKet(string noiLienKet) const;
    vector<SinhVien*> sinhVienDiemTrungBinhCaoNhatHocKy(string hocKy, float diem) const;
    SinhVien* sinhVienDiemTrungBinhCaoNhat() const;
    void sapXepDanhSach();

    map<int, int> thongKeSoLuongSinhVienTheoNam() const;
    const vector<SinhVien*>& getDanhSachSinhVien() const {
        return danhSachSinhVien;
    }
    virtual ~Khoa();
};

#endif  /* _KHOA_H_ */
