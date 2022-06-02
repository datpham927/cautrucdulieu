#pragma once
#include"xu_ly_de.h"

void menu_Nhan_vien() {
	ShowCur(false);
	int vitri = 0;
	int color = 13, b_color = 180;
	int vt_moi = vitri;
	int vt_cu = vt_moi;
	list_nhan_vien nv;
	Menu_nhan_vien();
	bool kt = true;
	while (true) {
		if (kt == true) {
			Khung_sang_menu_nv(vt_cu, color);
			Khung_sang_menu_nv(vt_moi, b_color);
			vt_cu = vt_moi;
			kt = false;
		}
		if (_kbhit()) {
			kt = true;
			char c = _getch();
			if (c == -32) {
				c = _getch();
				if (c == 72) {
					if (vt_moi != 0) vt_moi--;
					else vt_moi = 3;
				}
				else if (c == 80) {
					if (vt_moi != 3) vt_moi++;
					else vt_moi = vitri;
				}
			}if (c == 13) {
				switch (vt_moi) {
				case 0: {
					system("cls");
					Menu_chinh_f0(0, 60);
					them_nhan_vien(nv);
					system("cls");
					Menu_chinh_f0(0, 60);
					Menu_nhan_vien();
					break;
				}case 1: {
					system("cls");
					tree a[100];
					int sl = 0;
					Menu_chinh_f0(0, 60);
					Chuyen_sang_arr(nv.TREE, a, sl);
					sap_xep_chuoi(a, sl);
					Xuat_nhan_vien(a, sl);
					Giai_phong_vung_nho(a, sl);
					gotoXY(68, 30); system("pause");
					system("cls");
					Menu_chinh_f0(0, 60);
					Menu_nhan_vien();
					break;
				}case 2: {
					system("cls");
					Menu_chinh_f0(0, 60);
					xoa_nhan_vien(nv.TREE);
					gotoXY(68, 30); system("pause");
					system("cls");
					Menu_chinh_f0(0, 60);
					Menu_nhan_vien();
					break;
				}case 3: {
					system("cls");
					Menu_chinh_f0(0, 60);
					Hieu_chinh_nv(nv);
					gotoXY(68, 30); system("pause");
					system("cls");
					Menu_chinh_f0(0, 60);
					Hieu_chinh_nv(nv);
					break;
				}
				}
			 }if (c == 27) {
				break;
			}
		}
	}
}
void menu_vat_tu() {
	List_vat_tu vt;
	Doc_file_vt(vt);
	int vitri = 0;
	int color = 13, b_color = 180;
	int vt_moi = vitri;
	int vt_cu = vt_moi;
	Menu_vat_tu();
	bool kt = true;
	while (true) {
		if (kt == true) {
			Khung_sang_menu_vt(vt_cu, color);
			Khung_sang_menu_vt(vt_moi, b_color);
			vt_cu = vt_moi;
			kt = false;
		}
		if (_kbhit()) {
			kt = true;
			char c = _getch();
			if (c == -32) {
				c = _getch();
				if (c == 72) {
					if (vt_moi != 0) vt_moi--;
					else vt_moi = 3;
				}
				else if (c == 80) {
					if (vt_moi != 3) vt_moi++;
					else vt_moi = vitri;
				}
			}if (c == 13) {
				switch (vt_moi) {
				case 0: {
					system("cls");
					Menu_chinh_f0(0, 60);
					them_vat_tu(vt);
					system("cls");
					Menu_chinh_f0(0, 60);
					Menu_vat_tu();
					
					break;
				}case 1: {
					system("cls");
					Menu_chinh_f0(0, 60);
					in_danh_sach_vt(vt);
					gotoXY(68, 30); system("pause");
					system("cls");
					Menu_chinh_f0(0, 60);
					Menu_vat_tu();
					break;
				}case 2: {
					system("cls");
					Menu_chinh_f0(0, 60);
					xoa_vat_tu(vt);
					gotoXY(68, 30); system("pause");
					system("cls");
					Menu_chinh_f0(0, 60);
					Menu_vat_tu();
					break;
				}case 3: {
					system("cls");
					Menu_chinh_f0(0, 60);
					Hieu_chinh_vt(vt);
					gotoXY(68, 30); system("pause");
					system("cls");
					Menu_chinh_f0(0, 60);
					Menu_vat_tu();
					break;
				}
				}
			}
			if (c == 27) {
				break;
			}
		}
	}
}
void Menu_cha() {
	//intro();
	//_getch();
	
	int color = 60, b_color = 180;
	int vitri = 0;
	int vt_moi = vitri;
	int vt_cu = vt_moi;
	int sleep = 2;
	List_vat_tu vt;
	list_nhan_vien nv;
	system("cls");
	system("color 0D");
	Menu_chinh_f0(0, color);
	file_qltv();
	bool kt = true;
	while (true) {
		if (kt == true) {
			Thanh_sang(vt_cu, color);
			Thanh_sang(vt_moi, b_color);
			vt_cu = vt_moi;
			kt = false;
		}
		//nhấn phím thì mới thực hiện còn không thì bỏ qua
		if (_kbhit()) { //_kbhit dùng để bắt phím 
			kt = true;
			char c = _getch();
			if (c == -32) {
				c = _getch();
				if (c == 80) {
					if (vt_moi != 4) vt_moi++;
					else vt_moi = vitri;
				}
				else if (c == 72) {
					if (vt_moi != 0) vt_moi--;
					else vt_moi = 4;
				}
			}if (c == 13) {
				switch (vt_moi) {
				case 0: {
					system("cls");
					Menu_chinh_f0(0, color);
					menu_vat_tu();
					system("cls");
					Menu_chinh_f0(0, color);
					file_qltv();
					break;
				}case 1: {
					system("cls");
					Menu_chinh_f0(0, color);
					lap_hoa_don(nv);
					system("cls");
					Menu_chinh_f0(0, color);
					file_qltv();
					break;
					lap_hoa_don(nv);
				}case 2: {
					system("cls");
					Menu_chinh_f0(0, color);
					menu_Nhan_vien();
					system("cls");
					Menu_chinh_f0(0, color);
					file_qltv();
					break;

				}
				}
			}
		}
	}
}

int main() {
	
	//Menu_cha();
	/*list_nhan_vien nv;
	lap_hoa_don(nv);*/
	List_vat_tu vt;
	Doc_file_vt(vt);
	in_danh_sach_vt(vt);
}
