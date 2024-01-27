#ifndef KHOA_H
#define KHOA_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#include "SinhVien.h"

class Khoa {
private:
    std::string tenKhoa;
    std::vector<SinhVien*> danhSachSinhVien;

public:
    Khoa(std::string tenKhoa);
    ~Khoa(); // Hủy các đối tượng con (SinhVien)
    void themSinhVien(SinhVien* sv);
    int soSinhVienChinhQuy() const;
    SinhVien* sinhVienDiemDauVaoCaoNhat() const;
    std::vector<SinhVienTaiChuc*> danhSachSinhVienTaiChucNoiLienKet(std::string noiLienKet) const;
    std::vector<SinhVien*> sinhVienDiemTrungBinhCaoNhatHocKy(std::string hocKy, float diem) const;
    SinhVien* sinhVienDiemTrungBinhCaoNhat() const;
    void sapXepDanhSach();

    std::map<int, int> thongKeSoLuongSinhVienTheoNam() const;
        const std::vector<SinhVien*>& getDanhSachSinhVien() const {
        return danhSachSinhVien;
    }
};

#endif  // KHOA_H
