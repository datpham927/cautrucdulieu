#pragma once
#include <cstdlib>// rand , srand
#include"ve_do_hoa.h"
//============== danh sach vat tu ==============
struct vat_tu
{
	string ma_vt;
	string ten_vt;
	string don_vi_tinh;
	int so_luong_ton = 0;
	bool kt = 0;//true: da duoc lap hoa don	  -   false: chua duoc lap hoa
};
typedef struct vat_tu VAT_TU;
struct ds_vat_tu
{
	VAT_TU* ds[100];
	int sl = 0;
};
typedef struct ds_vat_tu      List_vat_tu;
//=============== danh sach chi tiet hoa don ================
struct chi_tiet_hoa_don
{
	string ma_vt;
	int don_gia;
	float VAT;//% thue
	vat_tu vattu;
	bool trang_thai;//1: khach mua - 0: khach tra
};
typedef struct chi_tiet_hoa_don CHI_TIET_HOA_DON;
struct ds_chi_tiet_hd
{
	CHI_TIET_HOA_DON ds[20];
	int sl = 0;
};
typedef struct ds_chi_tiet_hd
List_CHI_TIET_HD;
//=============== danh sach hoa don (dslkd)=============
struct hoa_don
{
	//data
	string so_hd;
	string ngay_lap_hd;
	char loai;//X: xuat - N: nhap
	//dschitiet hd
	List_CHI_TIET_HD danh_sach_chi_tiet_hd;
	//pointer
	hoa_don* pnext;
};
typedef struct hoa_don HOA_DON;
struct ds_hoa_don {
	HOA_DON* ptail;
	HOA_DON* phead;
	int sl = 0;
};
typedef struct  ds_hoa_don List_hoa_don;
void khoitao_list_HD(List_hoa_don& p) {
	p.phead = p.ptail = NULL;
}
void  them_vao_hd(List_hoa_don &p, HOA_DON* h) {
	if (p.phead == NULL) {
		p.phead = p.ptail = h;
	}
	else {
		h->pnext = p.phead;
		p.phead = h;
	}
}
HOA_DON* khoi_tao_node_hoa_don() {
	HOA_DON* p = new HOA_DON;
	p->pnext = NULL;
	return p;
}
//=============== danh sach nhan vien ================

struct nhan_vien {
	//data
	int ma_nv;
	string ho;
	string ten;
	string phai;
	//*dshd
	List_hoa_don  ds_hoa_don;
	//pointer
	nhan_vien* pleft;
	nhan_vien* pright;
}; typedef nhan_vien* tree;
struct ds_nhan_vien
{
	tree TREE = NULL;
	int sl = 0;
};
typedef struct ds_nhan_vien list_nhan_vien;

//khởi tạo node cho nhan vien
tree khoitaonode() {
	nhan_vien* p = new nhan_vien;
	p->pleft = NULL;
	p->pright = NULL;
	return p;
}
void them_vao_cay(tree& t, nhan_vien* p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->ma_nv > t->ma_nv)
		{
			them_vao_cay(t->pright, p);
		}
		else if (p->ma_nv < t->ma_nv)
		{
			them_vao_cay(t->pleft, p);
		}
	}
}