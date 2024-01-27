// SinhVien.cpp
#include "SinhVien.h"

// Phần triển khai các phương thức của lớp KetQuaHocTap
KetQuaHocTap::KetQuaHocTap() : tenHocKy(""), diemTrungBinh(0.0) {}

KetQuaHocTap::KetQuaHocTap(string tenHocKy, float diemTrungBinh)
    : tenHocKy(tenHocKy), diemTrungBinh(diemTrungBinh) {}

KetQuaHocTap::KetQuaHocTap(const KetQuaHocTap& kq)
    : tenHocKy(kq.tenHocKy), diemTrungBinh(kq.diemTrungBinh) {}

void KetQuaHocTap::input() {
    cout << "Nhap ten hoc ky: ";
    getline(cin, tenHocKy);
    cout << "Nhap diem trung binh: ";
    cin >> diemTrungBinh;
    cin.ignore(); // Đọc và loại bỏ kí tự '\n' còn lại trong buffer
}

void KetQuaHocTap::output() const {
    cout << "Hoc ky: " << tenHocKy << ", Diem trung binh: " << diemTrungBinh << endl;
}

string KetQuaHocTap::getTenHocKy() const {
    return tenHocKy;
}

float KetQuaHocTap::getDiemTrungBinh() const {
    return diemTrungBinh;
}

// Phần triển khai các phương thức của lớp SinhVien
SinhVien::SinhVien()
    : maSV(""), hoTen(""), ngaySinh(""), namVaoHoc(0), diemDauVao(0.0) {}

SinhVien::SinhVien(string maSV, string hoTen, string ngaySinh, int namVaoHoc, float diemDauVao, vector<KetQuaHocTap> ketQuaHocTap)
    : maSV(maSV), hoTen(hoTen), ngaySinh(ngaySinh), namVaoHoc(namVaoHoc), diemDauVao(diemDauVao), ketQuaHocTap(ketQuaHocTap) {}

SinhVien::SinhVien(const SinhVien& sv)
    : maSV(sv.maSV), hoTen(sv.hoTen), ngaySinh(sv.ngaySinh), namVaoHoc(sv.namVaoHoc), diemDauVao(sv.diemDauVao), ketQuaHocTap(sv.ketQuaHocTap) {}

void SinhVien::input() {
    cout << "Nhap ma sinh vien: ";
    getline(cin, maSV);
    cout << "Nhap ho ten sinh vien: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, ngaySinh);
    cout << "Nhap nam vao hoc: ";
    cin >> namVaoHoc;
    cout << "Nhap diem dau vao: ";
    cin >> diemDauVao;
    cin.ignore(); // Đọc và loại bỏ kí tự '\n' còn lại trong buffer

    int soHocKy;
    cout << "Nhap so hoc ky: ";
    cin >> soHocKy;
    cin.ignore();

    for (int i = 0; i < soHocKy; ++i) {
        KetQuaHocTap kq;
        kq.input();
        ketQuaHocTap.push_back(kq);
    }
}

void SinhVien::output() const {
    cout << "Ma sinh vien: " << maSV << endl;
    cout << "Ho ten sinh vien: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
    cout << "Nam vao hoc: " << namVaoHoc << endl;
    cout << "Diem dau vao: " << diemDauVao << endl;
    cout << "Ket qua hoc tap:" << endl;

    for (const auto& kq : ketQuaHocTap) {
        kq.output();
    }
}

bool SinhVien::laChinhQuy() const {
    return false; // Lớp cơ sở là lớp trừu tượng, không có sinh viên chính quy cụ thể
}

float SinhVien::diemTrungBinh(string hocKy) const {
    float diemTrungBinhHocKy = 0.0;
    int soMonHoc = 0;

    for (const auto& kq : ketQuaHocTap) {
        if (kq.getTenHocKy() == hocKy) {
            diemTrungBinhHocKy += kq.getDiemTrungBinh();
            soMonHoc++;
        }
    }

    return (soMonHoc > 0) ? (diemTrungBinhHocKy / soMonHoc) : 0.0;
}

string SinhVien::getMaSV() const {
    return maSV;
}

string SinhVien::getHoTen() const {
    return hoTen;
}

string SinhVien::getNgaySinh() const {
    return ngaySinh;
}

int SinhVien::getNamVaoHoc() const {
    return namVaoHoc;
}

float SinhVien::getDiemDauVao() const {
    return diemDauVao;
}

vector<KetQuaHocTap> SinhVien::getKetQuaHocTap() const {
    return ketQuaHocTap;
}

// Phần triển khai các phương thức của lớp SinhVienChinhQuy
SinhVienChinhQuy::SinhVienChinhQuy() {}

SinhVienChinhQuy::SinhVienChinhQuy(string maSV, string hoTen, string ngaySinh, int namVaoHoc, float diemDauVao, vector<KetQuaHocTap> ketQuaHocTap)
    : SinhVien(maSV, hoTen, ngaySinh, namVaoHoc, diemDauVao, ketQuaHocTap) {}

SinhVienChinhQuy::SinhVienChinhQuy(const SinhVienChinhQuy& svcq)
    : SinhVien(svcq) {}

bool SinhVienChinhQuy::laChinhQuy() const {
    return true;
}

// Phần triển khai các phương thức của lớp SinhVienTaiChuc
SinhVienTaiChuc::SinhVienTaiChuc()
    : noiLienKet("") {}

SinhVienTaiChuc::SinhVienTaiChuc(string maSV, string hoTen, string ngaySinh, int namVaoHoc, float diemDauVao, vector<KetQuaHocTap> ketQuaHocTap, string noiLienKet)
    : SinhVien(maSV, hoTen, ngaySinh, namVaoHoc, diemDauVao, ketQuaHocTap), noiLienKet(noiLienKet) {}

SinhVienTaiChuc::SinhVienTaiChuc(const SinhVienTaiChuc& svtc)
    : SinhVien(svtc), noiLienKet(svtc.noiLienKet) {}

bool SinhVienTaiChuc::laChinhQuy() const {
    return false;
}

void SinhVienTaiChuc::input() {
    SinhVien::input();
    cout << "Nhap noi lien ket dao tao: ";
    getline(cin, noiLienKet);
}

void SinhVienTaiChuc::output() const {
    SinhVien::output();
    cout << "Noi lien ket dao tao: " << noiLienKet << endl;
}

string SinhVienTaiChuc::getNoiLienKet() const {
    return noiLienKet;
}
