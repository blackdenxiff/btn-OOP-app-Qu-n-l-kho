#include <bits/stdc++.h>
#include "class_tong.h"
#include "function_class_hh.cpp"
#include "function_class_kh.cpp"
#include "GiaoDich.cpp"
#include "QuanLyBanHang.cpp"
using namespace std;

int main() {
    kho_hang kh;
    QuanLyBanHang qlbh;
    kh.doc_du_lieu("kho_hang.dat");
    kh.them_hang_hoa();     
    kh.hien_thi_danh_sach();   
    kh.xoa_hang_hoa();     
    kh.hien_thi_danh_sach(); 

    // Quản lý bán hàng (phần 5)
    qlbh.docFile();               
    qlbh.taoHoaDon(kh.ds_hang_hoa); 
    qlbh.xuatTatCaHoaDon();      

    // Báo cáo & phân tích (phần 6)
    qlbh.baoCaoDoanhThu();       
    qlbh.sanPhamBanChay();      
    // Lưu lại kho sau khi bán
    kh.luu_du_lieu("kho_hang.dat", 2); // ghi dè lên đó :Đ

    return 0;
}
