#pragma once
#include "GiaoDich.h"



class QuanLyBanHang {
private:
    vector<GiaoDich> dsGiaoDich;
public:
    void taoHoaDon(vector<hang_hoa>& danhSach);
    void xuatTatCaHoaDon() const;
    void baoCaoDoanhThu() const;
    void sanPhamBanChay() const;
    void luuFile();
    void docFile();
};
