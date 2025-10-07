#pragma once
#include <vector>
#include <string>
#include "class_tong.h"
using namespace std;
class GiaoDich {
private:
    string maHoaDon;
    string ngayBan;
    string tenKhachHang;
    vector<pair<hang_hoa, int>> dsHangBan;
    double tongTien;
    double loiNhuan;
public:
    GiaoDich();
    void nhapGiaoDich(vector<hang_hoa>& danhSach);
    void xuatGiaoDich() const;
    double getTongTien() const;
    double getLoiNhuan() const;
    string getNgayBan() const;
    string getMaHoaDon() const;
    vector<pair<hang_hoa, int>> getDSHangBan() const;
    void ghiVaoFile(ofstream& fout) const;
    void docTuFile(ifstream& fin);
};

