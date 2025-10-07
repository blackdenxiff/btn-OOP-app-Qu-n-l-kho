#include "QuanLyBanHang.h"
#include <fstream>
#include <iostream>
#include <map>
#include <algorithm>

void QuanLyBanHang::taoHoaDon(vector<hang_hoa>& danhSach) {
    GiaoDich gd;
    gd.nhapGiaoDich(danhSach);
    dsGiaoDich.push_back(gd);
    luuFile();
}



void QuanLyBanHang::xuatTatCaHoaDon() const {
    cout << "\n===== DANH SÁCH HÓA ĐƠN =====\n";
    for (auto& gd : dsGiaoDich) {
        gd.xuatGiaoDich();
    }
}
void QuanLyBanHang::baoCaoDoanhThu() const {
    double tongDoanhThu = 0, tongLoiNhuan = 0;
    for (auto& gd : dsGiaoDich) {
        tongDoanhThu += gd.getTongTien();
        tongLoiNhuan += gd.getLoiNhuan();
    }
    cout << "\n===== BÁO CÁO DOANH THU =====\n";
    cout << "Tổng doanh thu: " << tongDoanhThu << " VND\n";
    cout << "Tổng lợi nhuận: " << tongLoiNhuan << " VND\n";
}

void QuanLyBanHang::sanPhamBanChay() const {
    map<string, int> thongKe;
    for (auto& gd : dsGiaoDich) {
