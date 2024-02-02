#include <iostream>
#include <memory>

class SoPhucView {
public:
    void hienThi(const double phanThuc, const double phanAo) {
        std::cout << "So phuc: " << phanThuc << " + " << phanAo << "i" << std::endl;
    }
};

class SoPhucModel {
private:
    double phanThuc;
    double phanAo;

public:
    SoPhucModel(double pt, double pa) : phanThuc(pt), phanAo(pa) {}

    double layPhanThuc() const {
        return phanThuc;
    }

    double layPhanAo() const {
        return phanAo;
    }

    void datPhanThuc(double pt) {
        phanThuc = pt;
    }

    void datPhanAo(double pa) {
        phanAo = pa;
    }

    SoPhucModel cong(const SoPhucModel& other) const {
        return SoPhucModel(phanThuc + other.phanThuc, phanAo + other.phanAo);
    }

    SoPhucModel nhan(const SoPhucModel& other) const {
        double pt = phanThuc * other.phanThuc - phanAo * other.phanAo;
        double pa = phanThuc * other.phanAo + phanAo * other.phanThuc;
        return SoPhucModel(pt, pa);
    }
};

class SoPhucController {
private:
    std::shared_ptr<SoPhucModel> model;
    SoPhucView view;

public:
    SoPhucController(std::shared_ptr<SoPhucModel> m) : model(m) {}

    void nhapSoPhuc() {
        double pt, pa;
        std::cout << "Nhap phan thuc: ";
        std::cin >> pt;
        std::cout << "Nhap phan ao: ";
        std::cin >> pa;
        model->datPhanThuc(pt);
        model->datPhanAo(pa);
    }

    void hienThiSoPhuc() {
        double pt = model->layPhanThuc();
        double pa = model->layPhanAo();
        view.hienThi(pt, pa);
    }

    void congHaiSoPhuc(const SoPhucModel& other) {
        SoPhucModel ketQua = model->cong(other);
        view.hienThi(ketQua.layPhanThuc(), ketQua.layPhanAo());
    }

    void nhanHaiSoPhuc(const SoPhucModel& other) {
        SoPhucModel ketQua = model->nhan(other);
        view.hienThi(ketQua.layPhanThuc(), ketQua.layPhanAo());
    }
};

int main() {
    // Sử dụng smart pointer để quản lý đối tượng SoPhucModel
    std::shared_ptr<SoPhucModel> soPhuc1 = std::make_shared<SoPhucModel>(0, 0);
    SoPhucController controller(soPhuc1);

    std::cout << "Nhap so phuc 1:" << std::endl;
    controller.nhapSoPhuc();

    std::cout << "Nhap so phuc 2:" << std::endl;
    std::shared_ptr<SoPhucModel> soPhuc2 = std::make_shared<SoPhucModel>(0, 0);
    SoPhucController controller2(soPhuc2);
    controller2.nhapSoPhuc();

    std::cout << "Tong hai so phuc:" << std::endl;
    controller.congHaiSoPhuc(*soPhuc2);

    std::cout << "Tich hai so phuc:" << std::endl;
    controller.nhanHaiSoPhuc(*soPhuc2);

    return 0;
}
