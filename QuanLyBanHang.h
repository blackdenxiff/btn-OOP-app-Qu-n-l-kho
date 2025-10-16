#pragma once
#include "GiaoDich.h"
#include "kho_hang.h"
#include <vector>
using namespace std;
class QuanLyBanHang {
private:
    vector<GiaoDich> dsGiaoDich;
public:
    void taoHoaDon(vector<hang_hoa>& danhSach);
    void xuatTatCaHoaDon() const;
    void baoCaoDoanhThu() const;
    void sanPhamBanChay() const;
    void luuFile() const;
    void docFile();
};
