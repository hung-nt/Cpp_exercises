#include "../Inc/khoa.h"
using namespace std;

Khoa::Khoa(string tenKhoa) : tenKhoa(tenKhoa) {}

Khoa::~Khoa()
{
    for (auto sv : danhSachSinhVien)
    {
        delete sv;
    }
}

void Khoa::themSinhVien(SinhVien *sv)
{
    danhSachSinhVien.push_back(sv);
}

int Khoa::soSinhVienChinhQuy() const
{
    int count = 0;
    for (const auto &sv : danhSachSinhVien)
    {
        if (sv->laChinhQuy())
        {
            count++;
        }
    }
    return count;
}

SinhVien *Khoa::sinhVienDiemDauVaoCaoNhat() const
{
    if (danhSachSinhVien.empty())
    {
        return nullptr;
    }

    auto maxIter = max_element(danhSachSinhVien.begin(), danhSachSinhVien.end(),
                                    [](const SinhVien *sv1, const SinhVien *sv2)
                                    {
                                        return sv1->getDiemDauVao() < sv2->getDiemDauVao();
                                    });

    return *maxIter;
}

vector<SinhVienTaiChuc *> Khoa::danhSachSinhVienTaiChucNoiLienKet(string noiLienKet) const
{
    vector<SinhVienTaiChuc *> result;

    for (const auto &sv : danhSachSinhVien)
    {
        if (!sv->laChinhQuy())
        {
            SinhVienTaiChuc *svTaiChuc = dynamic_cast<SinhVienTaiChuc *>(sv);
            if (svTaiChuc && svTaiChuc->getNoiLienKet() == noiLienKet)
            {
                result.push_back(svTaiChuc);
            }
        }
    }

    return result;
}

vector<SinhVien *> Khoa::sinhVienDiemTrungBinhCaoNhatHocKy(string hocKy, float diem) const
{
    vector<SinhVien *> result;

    for (const auto &sv : danhSachSinhVien)
    {
        if (sv->diemTrungBinh(hocKy) >= diem)
        {
            result.push_back(sv);
        }
    }

    return result;
}

SinhVien *Khoa::sinhVienDiemTrungBinhCaoNhat() const
{
    if (danhSachSinhVien.empty())
    {
        return nullptr;
    }

    auto maxIter = max_element(danhSachSinhVien.begin(), danhSachSinhVien.end(),
                                    [](const SinhVien *sv1, const SinhVien *sv2)
                                    {
                                        return sv1->diemTrungBinh("HocKyCuoi") < sv2->diemTrungBinh("HocKyCuoi");
                                    });

    return *maxIter;
}

void Khoa::sapXepDanhSach()
{
    sort(danhSachSinhVien.begin(), danhSachSinhVien.end(),
              [](const SinhVien *sv1, const SinhVien *sv2)
              {
                  if (sv1->laChinhQuy() && !sv2->laChinhQuy())
                  {
                      return true;
                  }
                  else if (!sv1->laChinhQuy() && sv2->laChinhQuy())
                  {
                      return false;
                  }
                  else
                  {
                      return sv1->getNamVaoHoc() > sv2->getNamVaoHoc();
                  }
              });
}

map<int, int> Khoa::thongKeSoLuongSinhVienTheoNam() const
{
    map<int, int> thongKe;

    for (const auto &sv : danhSachSinhVien)
    {
        int nam = sv->getNamVaoHoc();
        thongKe[nam]++;
    }

    return thongKe;
}