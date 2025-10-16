#include "QuanLyBanHang.h"
#include <fstream>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void QuanLyBanHang::taoHoaDon(vector<hang_hoa>& danhSach) {
    GiaoDich gd;
    gd.nhapGiaoDich(danhSach); // tạo giao dịch mới, trừ hàng trong danhSach
    dsGiaoDich.push_back(gd);

    // Lưu giao dịch ra file
    luuFile();

    // Cập nhật tồn kho thực tế (file nhị phân)
    ofstream fout("kho_hang.dat", ios::binary | ios::trunc);
    if (!fout) {
        cerr << "Không thể mở file kho_hang.dat để ghi!\n";
        return;
    }

    for (auto& h : danhSach) {
        fout.write((char*)&h.ma_hang, sizeof(h.ma_hang));
        auto ghiString = [&](const string& s) {
            size_t len = s.size();
            fout.write((char*)&len, sizeof(len));
            fout.write(s.c_str(), len);
        };
        ghiString(h.ten_hang);
        ghiString(h.loai_hang);
        ghiString(h.don_vi_tinh);
        fout.write((char*)&h.so_luong, sizeof(h.so_luong));
        fout.write((char*)&h.gia_ban, sizeof(h.gia_ban));
        ghiString(h.nha_san_xuat);
        ghiString(h.ngay_san_xuat);
        ghiString(h.han_su_dung);
        ghiString(h.mo_ta);
    }
    fout.close();

    cout << "\n✅ Hóa đơn đã được tạo và tồn kho đã cập nhật!\n";
}

// =============================
// 2️ XUẤT TẤT CẢ HÓA ĐƠN
// =============================
void QuanLyBanHang::xuatTatCaHoaDon() const {
    cout << "\n===== DANH SÁCH HÓA ĐƠN =====\n";
    for (auto& gd : dsGiaoDich) {
        gd.xuatGiaoDich();
    }
}


//BÁO CÁO DOANH THU / LỢI NHUẬN
// =============================
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
        for (auto& sp : gd.getDSHangBan()) {
            thongKe[sp.first.getTen()] += sp.second;
        }
    }

    if (thongKe.empty()) {
        cout << "\n⚠️ Chưa có giao dịch nào!\n";
        return;
    }

    cout << "\n===== SẢN PHẨM BÁN CHẠY =====\n";
    vector<pair<string, int>> ds(thongKe.begin(), thongKe.end());
    sort(ds.begin(), ds.end(),
         [](auto& a, auto& b) { return a.second > b.second; });

    for (auto& sp : ds) {
        cout << left << setw(25) << sp.first
             << " | Số lượng bán: " << sp.second << endl;
    }
}

// luu danh sách ra file(nhị phân )
void QuanLyBanHang::luuFile() const {
    ofstream fout("giaodich.dat", ios::binary | ios::trunc);
    if (!fout) {
        cerr << "Không thể ghi file giao dịch!\n";
        return;
    }

    int soGD = dsGiaoDich.size();
    fout.write((char*)&soGD, sizeof(soGD));
    for (auto& gd : dsGiaoDich) {
        gd.ghiVaoFile(fout);
    }
    fout.close();
}
// doc lai file
void QuanLyBanHang::docFile() {
    dsGiaoDich.clear();
    ifstream fin("giaodich.dat", ios::binary);
    if (!fin) return;

    int soGD;
    fin.read((char*)&soGD, sizeof(soGD));
    for (int i = 0; i < soGD; ++i) {
        GiaoDich gd;
        gd.docTuFile(fin);
        dsGiaoDich.push_back(gd);
    }
    fin.close();
}
