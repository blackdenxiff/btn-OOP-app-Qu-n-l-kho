#include <bits/stdc++.h>
#include "class_tong.h"
using namespace std;

istream& operator>>(istream& is, hang_hoa& hh) {
    cout << "Nhap ma hang: ";
    is >> hh.ma_hang;
    is.ignore();
    cout << "Nhap ten hang: ";
    getline(is, hh.ten_hang);
    cout << "Nhap loai hang: ";
    getline(is, hh.loai_hang);
    cout << "Nhap don vi tinh: ";
    getline(is, hh.don_vi_tinh);
    cout << "Nhap so luong: ";
    is >> hh.so_luong;
    cout << "Nhap gia ban: ";
    is >> hh.gia_ban;
    is.ignore();
    cout << "Nhap nha san xuat: ";
    getline(is, hh.nha_san_xuat);
    cout << "Nhap ngay san xuat (dd/mm/yyyy): ";
    getline(is, hh.ngay_san_xuat);
    cout << "Nhap han su dung (dd/mm/yyyy): ";
    getline(is, hh.han_su_dung);
    cout << "Nhap mo ta: ";
    getline(is, hh.mo_ta);
    return is;
}

/*ostream& operator<<(ostream& os, hang_hoa& hh) { // dạng bảng
    os << left << setw(10) << hh.ma_hang
       << left << setw(20) << hh.ten_hang
       << left << setw(15) << hh.loai_hang
       << left << setw(10) << hh.don_vi_tinh
       << left << setw(10) << hh.so_luong
       << left << setw(15) << fixed << setprecision(2) << hh.gia_ban
       << left << setw(20) << hh.nha_san_xuat
       << left << setw(15) << hh.ngay_san_xuat
       << left << setw(15) << hh.han_su_dung
       << left << setw(30) << hh.mo_ta;
    return os;
}*/

ostream& operator<<(ostream& os, hang_hoa& hh) {
    os << "----------------------------------------\n";
    os << "Ma hang         : " << hh.ma_hang << "\n";
    os << "Ten hang        : " << hh.ten_hang << "\n";
    os << "Loai hang       : " << hh.loai_hang << "\n";
    os << "Don vi tinh     : " << hh.don_vi_tinh << "\n";
    os << "So luong        : " << hh.so_luong << "\n";
    os << "Gia ban         : " << fixed << setprecision(2) << hh.gia_ban << "\n";
    os << "Nha san xuat    : " << hh.nha_san_xuat << "\n";
    os << "Ngay san xuat   : " << hh.ngay_san_xuat << "\n";
    os << "Han su dung     : " << hh.han_su_dung << "\n";
    os << "Mo ta           : " << hh.mo_ta << "\n";
    os << "----------------------------------------"; // Dòng cuối có thể không cần "\n"
    return os;
}