#include <bits/stdc++.h>
#include "class_tong.h"
#include "function_class_hh.cpp"
#include "function_class_kh.cpp"
using namespace std;


int main(){
	kho_hang kh;
	kh.doc_du_lieu("kho_hang.dat");
	kh.them_hang_hoa();
	kh.hien_thi_danh_sach();
	kh.xoa_hang_hoa();
	kh.hien_thi_danh_sach();
	return 0;
}