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
        friend ostream& operator<<(ostream& os, const hang_hoa& hh);
};

class kho_hang{
    private:
        vector<hang_hoa> ds_hang_hoa;
    public:
        void them_hang_hoa();
        void luu_du_lieu(const string& filename);
        void doc_du_lieu(const string& filename);
        void hien_thi_danh_sach() const;
        void tim_kiem_theo_ten(const string& ten) const;
        void sap_xep_theo_gia_ban();
        void xoa_hang_hoa(int ma_hang);
        void cap_nhat_so_luong(int ma_hang, int so_luong_moi);     
};