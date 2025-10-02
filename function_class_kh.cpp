#include <bits/stdc++.h>
#include "class_tong.h"
using namespace std;

void kho_hang::luu_du_lieu(const string& filename) {
    ofstream ofs(filename, ios::binary);
    if (!ofs) {
        cerr << "Khong the mo file de luu du lieu!" << endl;
        return;
    }
    size_t size = ds_hang_hoa.size();
    ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (const auto& hh : ds_hang_hoa) {
        ofs.write(reinterpret_cast<const char*>(&hh), sizeof(hang_hoa));
    }
    ofs.close();
    cout << "Luu du lieu thanh cong vao file: " << filename << endl;
}
void kho_hang::doc_du_lieu(const string& filename) {
    ifstream ifs(filename, ios::binary);
    if (!ifs) {
        cerr << "Khong the mo file de doc du lieu!" << endl;
        return;
    }
    size_t size;
    ifs.read(reinterpret_cast<char*>(&size), sizeof(size));
    ds_hang_hoa.resize(size);
    for (auto& hh : ds_hang_hoa) {
        ifs.read(reinterpret_cast<char*>(&hh), sizeof(hang_hoa));
    }
    ifs.close();
    cout << "Doc du lieu thanh cong tu file: " << filename << endl;
}
void kho_hang::them_hang_hoa(){
    while(true){
        cout << "Ban co muon them hang hoa khong? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore(); // Bo qua ky tu newline con lai trong bo dem
        if(choice == 'y' || choice == 'Y'){
            hang_hoa hh;
            cin >> hh;
            ds_hang_hoa.push_back(hh);
            luu_du_lieu("kho_hang.txt");
            delete &hh;
        } else if(choice == 'n' || choice == 'N'){
            break;
        } else {
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }
    }
}
void kho_hang::hien_thi_danh_sach() const {
    if(ds_hang_hoa.empty()){
        cout << "Danh sach hang hoa trong!" << endl;
        return;
    }
    cout << left << setw(10) << "Ma Hang"
         << left << setw(20) << "Ten Hang"
         << left << setw(15) << "Loai Hang"
         << left << setw(10) << "Don Vi"
         << left << setw(10) << "So Luong"
         << left << setw(15) << "Gia Ban"
         << left << setw(20) << "Nha SX"
         << left << setw(15) << "Ngay SX"
         << left << setw(15) << "Han SD"
         << left << setw(30) << "Mo Ta" << endl;
    cout << string(160, '-') << endl;
    for(const auto& hh : ds_hang_hoa){
        cout << hh << endl;
    }
}