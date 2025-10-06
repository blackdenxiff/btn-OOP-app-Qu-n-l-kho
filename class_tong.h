#ifndef CLASS_TONG_H
#define CLASS_TONG_H
#include <bits/stdc++.h>
using namespace std;

class hang_hoa {
    private:
        int ma_hang;
        string ten_hang;
        string loai_hang;
        string don_vi_tinh;
        int so_luong;
        double gia_ban;
        string nha_san_xuat;
        string ngay_san_xuat;
        string han_su_dung;
        string mo_ta;
    public:
        friend istream& operator>>(istream& is, hang_hoa& hh);
        friend ostream& operator<<(ostream& os, hang_hoa& hh);
        friend class kho_hang;
};

class kho_hang{
    private:
        vector<hang_hoa> ds_hang_hoa;
    public:
        void them_hang_hoa(); // xong
        void luu_du_lieu(const string& filename, int i = 1);//xong
        void doc_du_lieu(const string& filename);//xong
        void hien_thi_danh_sach();//tuong d?i v?n ch? d? hi?n th? test code
        void xoa_hang_hoa();// xong
        void cap_nhat_so_luong(int ma_hang, int so_luong_moi);
        void tim_kiem_theo_ten(const string& ten);
        void sap_xep_theo_gia_ban();
};


#endif// CLASS_TONG_H