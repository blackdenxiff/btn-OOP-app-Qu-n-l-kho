#pragma once
#include <bits/stdc++.h>
#include "HangHoa.h"
using namespace std;
class GiaoDich {
private:
    string maHoaDon;
    string ngayBan;
    string tenKhachHang;
    vector<pair<HangHoa, int>> dsHangBan; // sản phẩm + số lượng bán
    double tongTien;
    double loiNhuan;
public:
    GiaoDich();
    void nhapGiaoDich(vector<HangHoa> &danhSach);
    void xuatGiaoDich() const;
    double getTongTien() const;
    double getLoiNhuan() const;
    string getNgayBan() const;
    vector<pair<HangHoa,int>> getDSHangBan() const;
    string getMaHoaDon() const;
};
