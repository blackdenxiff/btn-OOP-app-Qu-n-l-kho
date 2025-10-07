#include "GiaoDich.h"
#include <ctime>
#include <iomanip>

GiaoDich::GiaoDich() {
    tongTien = 0;
    loiNhuan = 0;
}
string layNgayHienTai() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    stringstream ss;
    ss << setfill('0') << setw(2) << ltm->tm_mday << "/"// lay trên chat phaadn này meo hiểu nên đùng hoi
       << setw(2) << 1 + ltm->tm_mon << "/"
       << 1900 + ltm->tm_year;
    return ss.str();
}
void GiaoDich::nhapGiaoDich(vector<HangHoa> &danhSach) {
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
        string ma;
        int sl;
        cout << "Nhập mã hàng thứ " << i + 1 << ": ";
        cin >> ma;
        cout << "Số lượng bán: ";
        cin >> sl;
        bool found = false;
        for (auto &h : danhSach) {
            if (h.getMaHang() == ma) {
                if (h.getSoLuong() < sl) {
                    cout << "❌ Không đủ hàng tồn kho!\n";
                } else {
                    h.setSoLuong(h.getSoLuong() - sl);
                    double thanhTien = sl * h.getGiaBan();
                    double lai = sl * (h.getGiaBan() - h.getGiaNhap());
                    tongTien += thanhTien;
                    loiNhuan += lai;
                    dsHangBan.push_back({h, sl});
                    cout << "✅ Đã thêm " << h.getTenHang() << " vào hóa đơn.\n";
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
    for (auto &sp : dsHangBan) {
        cout << "- " << sp.first.getTenHang() 
             << " | SL: " << sp.second 
             << " | Giá: " << sp.first.getGiaBan() 
             << " | Thành tiền: " << sp.second * sp.first.getGiaBan() << "\n";
    }
    cout << "Tổng tiền: " << tongTien << " VND\n";
    cout << "Lợi nhuận: " << loiNhuan << " VND\n";
}
double GiaoDich::getTongTien() const { return tongTien; }
double GiaoDich::getLoiNhuan() const { return loiNhuan; }
string GiaoDich::getNgayBan() const { return ngayBan; }
vector<pair<HangHoa,int>> GiaoDich::getDSHangBan() const { return dsHangBan; }
string GiaoDich::getMaHoaDon() const { return maHoaDon; }
