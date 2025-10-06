#include <bits/stdc++.h>
#include "class_tong.h"
using namespace std;

void kho_hang::luu_du_lieu(const string& filename, int i) {
	if( i == 1){
	    ofstream ofs(filename, ios::binary | ios::app);
	    if (!ofs) {
	        cerr << "Khong the mo file de luu du lieu!" << endl;
	        return;
	    }
	
	    for (const auto& hh : ds_hang_hoa) {
	        ofs.write(reinterpret_cast<const char*>(&hh.ma_hang), sizeof(hh.ma_hang));
	        ofs.write(reinterpret_cast<const char*>(&hh.so_luong), sizeof(hh.so_luong));
	        ofs.write(reinterpret_cast<const char*>(&hh.gia_ban), sizeof(hh.gia_ban));
	
	        auto write_string = [&](const string& s) {
	            size_t len = s.size();
	            ofs.write(reinterpret_cast<const char*>(&len), sizeof(len));
	            ofs.write(s.data(), len);
	        };
	
	        write_string(hh.ten_hang);
	        write_string(hh.loai_hang);
	        write_string(hh.don_vi_tinh);
	        write_string(hh.nha_san_xuat);
	        write_string(hh.ngay_san_xuat);
	        write_string(hh.han_su_dung);
	        write_string(hh.mo_ta);
	    }
	
	    ofs.close();
	    cout << "✅ Luu du lieu thanh cong vao file: " << filename << endl;
	}
	else{
		ofstream ofs(filename, ios::binary);
	    if (!ofs) {
	        cerr << "Khong the mo file de luu du lieu!" << endl;
	        return;
	    }
	
	    for (const auto& hh : ds_hang_hoa) {
	        ofs.write(reinterpret_cast<const char*>(&hh.ma_hang), sizeof(hh.ma_hang));
	        ofs.write(reinterpret_cast<const char*>(&hh.so_luong), sizeof(hh.so_luong));
	        ofs.write(reinterpret_cast<const char*>(&hh.gia_ban), sizeof(hh.gia_ban));
	
	        auto write_string = [&](const string& s) {
	            size_t len = s.size();
	            ofs.write(reinterpret_cast<const char*>(&len), sizeof(len));
	            ofs.write(s.data(), len);
	        };
	
	        write_string(hh.ten_hang);
	        write_string(hh.loai_hang);
	        write_string(hh.don_vi_tinh);
	        write_string(hh.nha_san_xuat);
	        write_string(hh.ngay_san_xuat);
	        write_string(hh.han_su_dung);
	        write_string(hh.mo_ta);
	    }
	
	    ofs.close();
	    cout << "✅ Luu du lieu thanh cong vao file: " << filename << endl;
	}
}


void kho_hang::doc_du_lieu(const string& filename) {
    ifstream ifs(filename, ios::binary);
    if (!ifs) {
        cerr << "Khong the mo file de doc du lieu!" << endl;
        return;
    }

    ds_hang_hoa.clear();

    while (true) {
        hang_hoa hh;

        ifs.read(reinterpret_cast<char*>(&hh.ma_hang), sizeof(hh.ma_hang));
        if (!ifs) break; 

        ifs.read(reinterpret_cast<char*>(&hh.so_luong), sizeof(hh.so_luong));
        ifs.read(reinterpret_cast<char*>(&hh.gia_ban), sizeof(hh.gia_ban));

        auto read_string = [&](string& s) {
            size_t len;
            ifs.read(reinterpret_cast<char*>(&len), sizeof(len));
            if (!ifs) return false;
            s.resize(len);
            ifs.read(&s[0], len);
            return static_cast<bool>(ifs);
        };

        if (!read_string(hh.ten_hang)) break;
        if (!read_string(hh.loai_hang)) break;
        if (!read_string(hh.don_vi_tinh)) break;
        if (!read_string(hh.nha_san_xuat)) break;
        if (!read_string(hh.ngay_san_xuat)) break;
        if (!read_string(hh.han_su_dung)) break;
        if (!read_string(hh.mo_ta)) break;

        ds_hang_hoa.push_back(hh);
    }

    ifs.close();
    cout << "✅ Doc du lieu thanh cong tu file: " << filename 
         << " (" << ds_hang_hoa.size() << " mat hang)" << endl;
}


void kho_hang::them_hang_hoa(){
    while(true){
        cout << "Ban co muon them hang hoa khong? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore();
        if(choice == 'y' || choice == 'Y'){
            hang_hoa hh;
            cin >> hh;
            ds_hang_hoa.push_back(hh);
            luu_du_lieu("kho_hang.dat");
            doc_du_lieu("kho_hang.dat");
        } else if(choice == 'n' || choice == 'N'){
            break;
        } else {
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }
    }
}

void kho_hang::xoa_hang_hoa() {
    if (ds_hang_hoa.empty()) {
        cout << "Danh sach hang hoa trong!" << endl;
        return;
    }

    int ma;
    cout << "Nhap ma hang hoa can xoa: ";
    cin >> ma;

    auto it = find_if(ds_hang_hoa.begin(), ds_hang_hoa.end(),
                      [ma](const hang_hoa& hh) { return hh.ma_hang == ma; });

    if (it != ds_hang_hoa.end()) {
        cout << "Tim thay hang hoa: " << it->ten_hang << endl;
        char xac_nhan;
        cout << "Ban co chac chan muon xoa (y/n)? ";
        cin >> xac_nhan;

        if (xac_nhan == 'y' || xac_nhan == 'Y') {
            ds_hang_hoa.erase(it);
            cout << "Da xoa hang hoa co ma: " << ma << endl;
            int i = 2;
            luu_du_lieu("kho_hang.dat", i);
            doc_du_lieu("kho_hang.dat");
        } else {
            cout << "Huy xoa hang hoa." << endl;
        }
    } else {
        cout << "Khong tim thay hang hoa co ma: " << ma << endl;
    }
}

void kho_hang::hien_thi_danh_sach(){
    if(ds_hang_hoa.empty()){
        cout << "Danh sach hang hoa trong!" << endl;
        return;
    }
    for( auto& hh : ds_hang_hoa){
        cout << hh << endl;
    }
}



/*void kho_hang::hien_thi_danh_sach(){ dạng bảng
    if(ds_hang_hoa.empty()){
        cout << "Danh sach hang hoa trong!" << endl;
        return;
    }
    cout << string(160, '-') << endl;
    cout << left << setw(10) << "Ma Hang"
         << left << setw(20) << "Ten Hang"
         << left << setw(15) << "Loai Hang"
         << left << setw(10) << "DVT"
         << left << setw(10) << "So Luong"
         << left << setw(15) << "Gia Ban"
         << left << setw(20) << "Nha San Xuat"
         << left << setw(15) << "NSX"
         << left << setw(15) << "HSD"
         << left << setw(30) << "Mo Ta" << endl;
    cout << string(160, '-') << endl;
    for( auto& hh : ds_hang_hoa){
        cout << hh << endl;
    }
}*/
