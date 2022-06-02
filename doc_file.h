#pragma once
#include"co_so_du_lieu.h"

//========== đọc file ====================================
void doc_file_nhan_vien(list_nhan_vien& ds_nv);
void Doc_file_vt(List_vat_tu& vt);

void Doc_file_vt(List_vat_tu& vt) {
	ifstream file;
	file.open("ds_vt.txt", ios_base::in);
	while (file.eof() != true)
	{
		vt.ds[vt.sl] = new vat_tu;
		getline(file, vt.ds[vt.sl]->ma_vt,',');
		getline(file, vt.ds[vt.sl]->ten_vt, ',');
		getline(file, vt.ds[vt.sl]->don_vi_tinh, ',');
		file >> vt.ds[vt.sl]->so_luong_ton; file.ignore();
		file >> vt.ds[vt.sl]->kt; file.ignore();
		vt.sl++;
	} 
	file.close();
}

void doc_file_nhan_vien(list_nhan_vien& ds_nv) {
	ifstream filein;
	filein.open("ds_nv.txt", ios_base::in);
	while (filein.eof() != true)
	{
		nhan_vien* x = khoitaonode();
		filein >> x->ma_nv;
		filein.ignore();
		getline(filein, x->ho, ',');
		getline(filein, x->ten, ',');
		getline(filein, x->phai);
		them_vao_cay(ds_nv.TREE, x);
		ds_nv.sl++;
	}
	filein.close();
}

