#include "GiaoDich.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
GiaoDich::GiaoDich() {
    tongTien = 0;
    loiNhuan = 0;
}
string layNgayHienTai() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    stringstream ss;
    ss << setfill('0') << setw(2) << ltm->tm_mday << "/"// cái phần này ở chatgpt dundg hoi vi t emso biết
       << setw(2) << 1 + ltm->tm_mon << "/"
       << 1900 + ltm->tm_year;
    return ss.str();
}

void GiaoDich::nhapGiaoDich(vector<hang_hoa>& danhSach) {
    cout << "\n=== TẠO HÓA ĐƠN BÁN HÀNG ===\n";
    cout << "Nhập mã hóa đơn: ";
    cin.ignore();
    getline(cin, maHoaDon);
    ngayBan = layNgayHienTai();
    cout << "Tên khách hàng: ";
    getline(cin, tenKhachHang);
    int n;
    cout << "Nhập số mặt hàng cần bán: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int ma;
        int sl;
        cout << "Nhập mã hàng thứ " << i + 1 << ": ";
        cin >> ma;
        cout << "Số lượng bán: ";
        cin >> sl;
        bool found = false;
        for (auto& h : danhSach) {
            if (h.ma_hang == ma) {
                if (h.so_luong < sl) {
                    cout << "❌ Không đủ hàng tồn kho!\n";
                } else {
                    h.so_luong -= sl;
                    double thanhTien = sl * h.gia_ban;
                    tongTien += thanhTien;
                    loiNhuan += thanhTien * 0.1; // giả định lợi nhuận 10%
                    dsHangBan.push_back({h, sl});
                    cout << "✅ Đã thêm " << h.ten_hang << " vào hóa đơn.\n";
                }
                found = true;
                break;
            }
        }
        if (!found) cout << "⚠️ Không tìm thấy mã hàng!\n";
    }
    cout << "Tổng tiền hóa đơn: " << tongTien << " VND\n";
}
void GiaoDich::xuatGiaoDich() const {
    cout << "\n--- HÓA ĐƠN " << maHoaDon << " ---\n";
    cout << "Ngày bán: " << ngayBan << "\n";
    cout << "Khách hàng: " << tenKhachHang << "\n";
    cout << "Sản phẩm:\n";
    for (auto& sp : dsHangBan) {
        cout << "- " << sp.first.ten_hang
             << " | SL: " << sp.second
             << " | Giá: " << sp.first.gia_ban
             << " | Thành tiền: " << sp.second * sp.first.gia_ban << "\n";
    }
    cout << "Tổng tiền: " << tongTien << " VND\n";
    cout << "Lợi nhuận: " << loiNhuan << " VND\n";
}
double GiaoDich::getTongTien() const { return tongTien; }
double GiaoDich::getLoiNhuan() const { return loiNhuan; }
string GiaoDich::getNgayBan() const { return ngayBan; }
string GiaoDich::getMaHoaDon() const { return maHoaDon; }
vector<pair<hang_hoa, int>> GiaoDich::getDSHangBan() const { return dsHangBan; }
void GiaoDich::ghiVaoFile(ofstream& fout) const {
    int len;
    len = maHoaDon.size();
    fout.write((char*)&len, sizeof(int));
    fout.write(maHoaDon.c_str(), len);
    len = ngayBan.size();
    fout.write((char*)&len, sizeof(int));
    fout.write(ngayBan.c_str(), len);
    len = tenKhachHang.size();
    fout.write((char*)&len, sizeof(int));
    fout.write(tenKhachHang.c_str(), len);
    fout.write((char*)&tongTien, sizeof(double));
    fout.write((char*)&loiNhuan, sizeof(double));
    int soSP = dsHangBan.size();
    fout.write((char*)&soSP, sizeof(int));
    for (auto& sp : dsHangBan) {
        fout.write((char*)&sp.first, sizeof(hang_hoa));
        fout.write((char*)&sp.second, sizeof(int));
    }
}
void GiaoDich::docTuFile(ifstream& fin) {
    int len;
    char buffer[100];
    fin.read((char*)&len, sizeof(int));
    fin.read(buffer, len);
    buffer[len] = '\0';
    maHoaDon = buffer;

    fin.read((char*)&len, sizeof(int));
    fin.read(buffer, len);
    buffer[len] = '\0';
    ngayBan = buffer;

    fin.read((char*)&len, sizeof(int));
    fin.read(buffer, len);
    buffer[len] = '\0';
    tenKhachHang = buffer;
    fin.read((char*)&tongTien, sizeof(double));
    fin.read((char*)&loiNhuan, sizeof(double));
    int soSP;
    fin.read((char*)&soSP, sizeof(int));
    dsHangBan.clear();
    for (int i = 0; i < soSP; ++i) {
        hang_hoa hh;
        int sl;
        fin.read((char*)&hh, sizeof(hang_hoa));
        fin.read((char*)&sl, sizeof(int));
        dsHangBan.push_back({hh, sl});
    }
}
