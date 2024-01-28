#ifndef _SINHVIEN_H_
#define _SINHVIEN_H_

#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;

class KetQuaHocTap
{
private:
    string tenHocKy;
    float diemTrungBinh;

public:
    KetQuaHocTap();
    KetQuaHocTap(string tenHocKy, float diemTrungBinh);
    KetQuaHocTap(const KetQuaHocTap &kq);
    void input();
    void output() const;
    string getTenHocKy() const;
    float getDiemTrungBinh() const;
};

class SinhVien
{
protected:
    string maSV;
    string hoTen;
    string ngaySinh;
    int namVaoHoc;
    float diemDauVao;
    vector<KetQuaHocTap> ketQuaHocTap;

public:
    SinhVien();
    SinhVien(string maSV, string hoTen, string ngaySinh, int namVaoHoc, float diemDauVao, vector<KetQuaHocTap> ketQuaHocTap);
    SinhVien(const SinhVien &sv);
    virtual void input();
    virtual void output() const;
    virtual bool laChinhQuy() const = 0;
    float diemTrungBinh(string hocKy) const;
    string getMaSV() const;
    string getHoTen() const;
    string getNgaySinh() const;
    int getNamVaoHoc() const;
    float getDiemDauVao() const;
    vector<KetQuaHocTap> getKetQuaHocTap() const;
};

class SinhVienChinhQuy : public SinhVien
{
public:
    SinhVienChinhQuy();
    SinhVienChinhQuy(string maSV, string hoTen, string ngaySinh, int namVaoHoc, float diemDauVao, vector<KetQuaHocTap> ketQuaHocTap);
    SinhVienChinhQuy(const SinhVienChinhQuy &svcq);
    bool laChinhQuy() const;
};

class SinhVienTaiChuc : public SinhVien
{
private:
    string noiLienKet;

public:
    SinhVienTaiChuc();
    SinhVienTaiChuc(string maSV, string hoTen, string ngaySinh, int namVaoHoc, float diemDauVao, vector<KetQuaHocTap> ketQuaHocTap, string noiLienKet);
    SinhVienTaiChuc(const SinhVienTaiChuc &svtc);
    bool laChinhQuy() const;
    void input() override;
    void output() const override;
    string getNoiLienKet() const;
};

#endif /* _SINHVIEN_H_ */