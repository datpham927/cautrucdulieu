#pragma once
#include"Myclip.h"
#include"fstream"
#include"string"
using namespace std;
//========== đọc file ====================================
void intro();
void file_qltv();
//==================== Menu chính ===========================
//thanh đổi màu
void Thanh_sang(int vitri, int color);
//vẽ menu chính tùy chọn 
void Menu_chinh_f0(int sleep, int color);
// vẽ khung console
void Ve_khung(int sleep);
//=================================== Khung chung ==============================
void n_khung_nhap(int x, int y, int  w, int  h, string s, int& sl);// nhiều khung

//========================== Vat tu =============================
void Menu_vat_tu();
void Khung_sang_menu_vt(int vitri, int color);
void khung_nhap(int x, int y, int h, int w);//1 khung
void thong_tin_nhap_vt();// thông tin yêu cầu nhập
void khung_sang(int x, int y, int w, int h, int color);// khung duy chuyển
void Khung_Xuat_vat_tu();
void Khung_Xuat_nhan_vien();

//========================== Nhân viên ==========================
void Menu_nhan_vien();
void Khung_sang_menu_nv(int vitri, int color);
void thong_tin_nhap_nv();
//========================== Hóa đơn ============================
void Menu_Hd(int color);
void Khung_NX_hd();
void Thanh_sang_hd(int vitri, int color);
//========================== chi tiết hóa đơn ===================

void file_qltv() {
	ShowCur(false);
	ifstream file;
	file.open("qltv.txt");
	int color = 1;
	int i = 6;
	TextColor(13);
	while (!file.eof()) {
		string s;
		getline(file, s);
		gotoXY(60, i); cout << s << endl;
		Sleep(100);
		i++;
	}
}
void intro() {
	ShowCur(false);
	ifstream file;
	file.open("intro.txt");
	int color = 1;
	//bool isplay = PlaySound(L"sound.wav", NULL, SND_FILENAME);
	while (!file.eof()) {
		SetColor(color);
		string s;
		getline(file, s);
		cout << s << endl;
		Sleep(100);
		color++;
	}
	file.close();
	for (int i = 20; i <= 100; i++) {
		TextColor(100);
		gotoXY(i, 28); cout << ' ';
		Sleep(30);
	}
	while (!_kbhit()) { //_kbhit mặt định trả về true và khi nhấn phím bất kì thì trả về false
		gotoXY(35, 30);
		TextColor(rand() % 14 + 1);//chạy từ 1 đến 14
		gotoXY(55, 26); cout << "PHAM NGOC DAT";
		TextColor(rand() % 13 + 3);
		gotoXY(45, 30); cout << "Xin vui long ! nhan SPACE de tiep tuc ";
		Sleep(200);

	}

}
void Ve_khung(int sleep) {
	ShowCur(false);
	for (int i = 1; i < 130; i++) {
		TextColor(180);
		gotoXY(i, 1); cout << " ";
		//khung duoi 
		gotoXY(i, 32); cout << " ";
	}//khung trái
	for (int i = 1; i < 32; i++) {
		TextColor(180);
		gotoXY(129, i); cout << " ";
		Sleep(sleep);
	}
	//khung phải
	for (int i = 32; i > 1; i--) {
		TextColor(180);
		gotoXY(1, i); cout << " ";
		Sleep(sleep);
	}
	for (int i = 1; i < 32; i++) {
		TextColor(180);
		gotoXY(37, i); cout << " ";
		Sleep(sleep);
	}
	//khung ngang
	for (int i = 1; i < 38; i++) {
		TextColor(180);
		gotoXY(i, 9); cout << " ";
		Sleep(sleep);
	}
	TextColor(14);
	gotoXY(12, 4); cout << "PHAM NGOC DAT";
	gotoXY(12, 5); cout << "  K27-DTU  ";
}
//----------- khung chọn trình độ , chức vụ -----------------
//void Khung_sang_td_cv(int vitri, int color) {
//	TextColor(color);
//	switch (vitri) {
//	case 0: {
//		gotoXY(79, 14); cout << Chuc_vu[0]; break;
//	}
//	case 1: {
//		gotoXY(80, 16); cout << Chuc_vu[1]; break;
//	}
//	case 2: {
//		gotoXY(80, 18); cout << Chuc_vu[2]; break;
//	}
//	}
//}
//void Khung_chon_trinh_do() {
//	//vẽ khung 
//	TextColor(14);
//	for (int i = 73; i <= 95; i++) {
//		gotoXY(i, 11); cout << char(205);
//		gotoXY(i, 13); cout << char(205);
//		gotoXY(i, 20); cout << char(205);
//	}
//	for (int i = 11; i <= 20; i++) {
//		gotoXY(73, i); cout << char(186);
//		gotoXY(95, i); cout << char(186);
//	}
//	gotoXY(73, 11); cout << char(201);
//	gotoXY(73, 20); cout << char(200);
//	gotoXY(95, 11); cout << char(187);
//	gotoXY(95, 20); cout << char(188);
//	//----------------------
//	TextColor(160);
//	gotoXY(74, 12); cout << "       Trinh do      ";
//	TextColor(13);
//	gotoXY(81, 14); cout << Trinh_do[0];
//	gotoXY(81, 16); cout << Trinh_do[1];
//	gotoXY(81, 18); cout << Trinh_do[2];
//	//----------------------------
//	TextColor(9);
//	gotoXY(67, 26); cout << "ESC : Thoat             ENTER : Chon ";
//	gotoXY(105, 16); cout << char(30) << ": UP";
//	gotoXY(105, 17); cout << char(31) << ": DOWN";
//}
//void Khung_chon_chuc_vu() {
//	//vẽ khung 
//	TextColor(14);
//	for (int i = 73; i <= 95; i++) {
//		gotoXY(i, 11); cout << char(205);
//		gotoXY(i, 13); cout << char(205);
//		gotoXY(i, 20); cout << char(205);
//	}
//	for (int i = 11; i <= 20; i++) {
//		gotoXY(73, i); cout << char(186);
//		gotoXY(95, i); cout << char(186);
//	}
//	gotoXY(73, 11); cout << char(201);
//	gotoXY(73, 20); cout << char(200);
//	gotoXY(95, 11); cout << char(187);
//	gotoXY(95, 20); cout << char(188);
//	//----------------------
//	TextColor(160);
//	gotoXY(74, 12); cout << "       Chuc vu       ";
//	TextColor(13);
//	gotoXY(79, 14); cout << Chuc_vu[0];
//	gotoXY(80, 16); cout << Chuc_vu[1];
//	gotoXY(80, 18); cout << Chuc_vu[2];
//	//-----------------------------
//	TextColor(9);
//	gotoXY(67, 26); cout << "ESC : Thoat             ENTER : Chon ";
//	gotoXY(105, 16); cout << char(30) << ": UP";
//	gotoXY(105, 17); cout << char(31) << ": DOWN";
//
//}
string s[5] = { "       Quan ly vat tu         ",
				"       Quan Ly hoa don        ",
				"      Quan ly nhan vien       ",
				"     Doanh thu tung thang     ",
				"            Thoat             " };

void Thanh_sang(int vitri, int color) {
	TextColor(color);
	int x = 5;

	if (color == 60) {
		SetColor(14);
	}
	else {
		SetColor(12);
	}
	gotoXY(x, 7 + (vitri + 1) * 4); cout << "                              ";
	gotoXY(x, 8 + (vitri + 1) * 4); cout << s[vitri];
	gotoXY(x, 9 + (vitri + 1) * 4); cout << "                              ";
}

void Menu_chinh_f0(int sleep, int color) {
	system("color 0D");
	Ve_khung(sleep);
	TextColor(color);
	SetColor(14);
	int x = 5;
	for (int i = 0; i < 5; i++) {
		gotoXY(x, 7 + (i + 1) * 4); cout << "                              ";
		gotoXY(x, 8 + (i + 1) * 4); cout << s[i];
		gotoXY(x, 9 + (i + 1) * 4); cout << "                              ";
		Sleep(sleep);
	}

}

//khung nhâp thông tin
void khung_nhap(int x, int y, int h, int w) {
	for (int i = x; i <= x + w; i++) {
		gotoXY(i, y); cout << char(196);
		gotoXY(i, y + h); cout << char(196);
	}
	for (int i = y; i <= y + h; i++) {
		gotoXY(x, i); cout << char(179);
		gotoXY(x + w, i); cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);

}
void n_khung_nhap(int x, int y, int w, int h, string s, int& sl) {
	TextColor(13);
	for (int i = 41; i <= 125; i++) {
		gotoXY(i, 5); cout << char(205);
		gotoXY(i, 30); cout << char(205);
	}
	for (int i = 5; i <= 30; i++) {
		gotoXY(41, i); cout << char(186);
		gotoXY(125, i); cout << char(186);
	}
	gotoXY(41, 5); cout << char(201);
	gotoXY(41, 30); cout << char(200);
	gotoXY(125, 5); cout << char(187);
	gotoXY(125, 30); cout << char(188);
	//-------------------
	SetColor(10);
	gotoXY(73, 3); cout << s;//tieu de 

	// vẽ nhiều khung
	for (int i = 0; i < sl; i++) {
		SetColor(2);
		khung_nhap(x, y + (i * 4), h, w);
		Sleep(60);
	}

}

void thong_tin_nhap_vt() {
	string s[4] = { "MA VAT TU :",
					"TEN VAT TU :",
					"DON VI TINH :",
					"SO LUONG TON :" };
	SetColor(30);
	int j = 0;
	for (int i = 9; i <= 25; i += 4) {
		gotoXY(65, i);
		if (j < 4) {
			cout << s[j];
		}
		j++;
	}
	SetColor(7); gotoXY(65, 26); cout << "ENTER : Them                        ESC : Thoat";
}
void khung_sang(int x, int y, int w, int h, int color) {
	SetColor(color);
	for (int i = x; i <= x + w; i++) {
		gotoXY(i, y); cout << char(196);
		gotoXY(i, y + h); cout << char(196);
	}
	for (int i = y; i <= y + h; i++) {
		gotoXY(x, i); cout << char(179);
		gotoXY(x + w, i); cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x + w, y + h); cout << char(217);

}

void Khung_Xuat_vat_tu()
{
	TextColor(13);
	int x = 50;
	gotoXY(x, 6); cout << " +---------------------------------------------------------------+ " << endl;
	gotoXY(x, 7); cout << " |          |	         	 |	           | 	           |" << endl;
	gotoXY(x, 8); cout << " |----------+------------------+-----------------+---------------+" << endl;
	gotoXY(x, 9); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 10); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 11); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 12); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 13); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 14); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 15); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 16); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 17); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 18); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 19); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 20); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 21); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 22); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 23); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 24); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 25); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 26); cout << " |          |		         |	           | 	           |" << endl;
	gotoXY(x, 27); cout << " +----------+------------------+-----------------+---------------+" << endl;
	gotoXY(x + 2, 7); cout << "MA VAT TU";
	gotoXY(x + 16, 7); cout << " TEN VAT TU";
	gotoXY(x + 35, 7); cout << "DON VI TINH";
	gotoXY(x + 52, 7); cout << "SO LUONG TON";
	SetColor(12);
	gotoXY(77, 4); cout << "XUAT VAT TU";
}


string vt[4] = { "Them vat tu",
				 "In danh sach",
				 " Xoa vat tu",
				 " Hieu chinh" };
void Menu_vat_tu() {
	//vẽ khung 
	TextColor(14);
	for (int i = 73; i <= 95; i++) {
		gotoXY(i, 11); cout << char(205);
		gotoXY(i, 13); cout << char(205);
		gotoXY(i, 21); cout << char(205);
	}
	for (int i = 11; i <= 21; i++) {
		gotoXY(73, i); cout << char(186);
		gotoXY(95, i); cout << char(186);
	}
	gotoXY(73, 11); cout << char(201);
	gotoXY(73, 21); cout << char(200);
	gotoXY(95, 11); cout << char(187);
	gotoXY(95, 21); cout << char(188);
	//----------------------
	TextColor(160);
	gotoXY(74, 12); cout << "        Menu         ";
	TextColor(13);
	gotoXY(79, 14); cout << vt[0];
	gotoXY(79, 16); cout << vt[1];
	gotoXY(79, 18); cout << vt[2];
	gotoXY(79, 20); cout << vt[3];

	//----------------------------
	TextColor(9);
	gotoXY(67, 26); cout << "ESC : Thoat             ENTER : Chon ";
	gotoXY(105, 16); cout << char(30) << ": UP";
	gotoXY(105, 17); cout << char(31) << ": DOWN";
}


void Khung_sang_menu_vt(int vitri, int color) {
	TextColor(color);
	switch (vitri) {
	case 0: {
		gotoXY(79, 14); cout << vt[0]; break;
	}
	case 1: {
		gotoXY(79, 16); cout << vt[1]; break;
	}
	case 2: {
		gotoXY(79, 18); cout << vt[2]; break;
	}case 3: {
		gotoXY(79, 20); cout << vt[3]; break;

	}
	}
}
//===============================================

void Khung_Xuat_nhan_vien() {
	TextColor(13);
	int x = 65;
	gotoXY(x, 6); cout << " +------------------------------------------------+ " << endl;
	gotoXY(x, 7); cout << " |          |	         	 |	           |" << endl;
	gotoXY(x, 8); cout << " |----------+-------------------+-----------------|" << endl;
	gotoXY(x, 9); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 10); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 11); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 12); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 13); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 14); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 15); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 16); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 17); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 18); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 19); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 20); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 21); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 22); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 23); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 24); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 25); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 26); cout << " |          |		         |	           |" << endl;
	gotoXY(x, 27); cout << " +----------+-------------------+-----------------+" << endl;
	gotoXY(x + 2, 7); cout << "  MA NV";
	gotoXY(x + 16, 7); cout << "   HO TEN";
	gotoXY(x + 35, 7); cout << "    PHAI";
	SetColor(12);
	gotoXY(77, 4); cout << "XUAT NHAN VIEN";
}
string nv[4] = { "Them nhan vien",
				 "In danh sach",
				 "Xoa nhan vien",
				 "Hieu chinh" };
void Menu_nhan_vien() {
	//vẽ khung 
	TextColor(14);
	for (int i = 73; i <= 95; i++) {
		gotoXY(i, 11); cout << char(205);
		gotoXY(i, 13); cout << char(205);
		gotoXY(i, 21); cout << char(205);
	}
	for (int i = 11; i <= 21; i++) {
		gotoXY(73, i); cout << char(186);
		gotoXY(95, i); cout << char(186);
	}
	gotoXY(73, 11); cout << char(201);
	gotoXY(73, 21); cout << char(200);
	gotoXY(95, 11); cout << char(187);
	gotoXY(95, 21); cout << char(188);
	//----------------------
	TextColor(160);
	gotoXY(74, 12); cout << "        Menu         ";
	TextColor(13);
	gotoXY(78, 14); cout << nv[0];
	gotoXY(78, 16); cout << nv[1];
	gotoXY(78, 18); cout << nv[2];
	gotoXY(79, 20); cout << nv[3];

	//----------------------------
	TextColor(9);
	gotoXY(67, 26); cout << "ESC : Thoat             ENTER : Chon ";
	gotoXY(105, 16); cout << char(30) << ": UP";
	gotoXY(105, 17); cout << char(31) << ": DOWN";
}
void thong_tin_nhap_nv() {
	string s[4] = { "        MA NV :",
					"        HO NV :",
					"       TEN NV :",
					"         PHAI :" };
	SetColor(30);
	int j = 0;
	for (int i = 9; i <= 25; i += 4) {
		gotoXY(65, i);
		if (j < 4) {
			cout << s[j];
		}
		j++;
	}
	SetColor(7); gotoXY(65, 26); cout << "ENTER : Them                        ESC : Thoat";
}
void Khung_sang_menu_nv(int vitri, int color) {

	TextColor(color);
	switch (vitri) {
	case 0: {
		gotoXY(78, 14); cout << nv[0]; break;
	}
	case 1: {
		gotoXY(78, 16); cout << nv[1]; break;
	}
	case 2: {
		gotoXY(78, 18); cout << nv[2]; break;
	}case 3: {
		gotoXY(79, 20); cout << nv[3]; break;

	}
	}
}
//===================================
void Khung_NX_hd() {
	//-------------------------Nhập thông tin ----------------------
	system("color 0D");
	Menu_chinh_f0(0, 60);
	//vẽ khung 
	int x = 54, w = 60, y = 3, h = 26;
	TextColor(14);
	for (int i = x; i <= x + w; i++) {
		gotoXY(i, y); cout << char(205);
		gotoXY(i, 12); cout << char(205);
		gotoXY(i, y + h); cout << char(205);
	}
	for (int i = y; i <= y + h; i++) {
		gotoXY(x, i); cout << char(186);
		gotoXY(x + w, i); cout << char(186);
	}
	gotoXY(x, y); cout << char(201);
	gotoXY(x, y + h); cout << char(200);
	gotoXY(x + w, y); cout << char(187);
	gotoXY(x + w, y + h); cout << char(188);
	TextColor(9);
	gotoXY(67, 30); cout << "ESC : Thoat             ENTER : Chon ";

}


void Thanh_sang_hd(int vitri, int color) {
	ShowCur(0);
	string c[3] = { "     HOA DON NHAP     ",
					"     HOA DON XUAT     ",
					"         THOAT        " };
	int x = 75;
	TextColor(color);
	SetColor(11);
	gotoXY(x, 9 + (vitri * 4)); cout << "                      ";
	gotoXY(x, 10 + (vitri * 4)); cout << c[vitri];
	gotoXY(x, 11 + (vitri * 4)); cout << "                      ";
}
void Menu_Hd(int color) {
	system("cls");
	Menu_chinh_f0(0, 60);
	string c[3] = { "     HOA DON NHAP     ",
					"     HOA DON XUAT     ",
					"         THOAT        " };
	TextColor(color);
	SetColor(11);
	int x = 75;
	for (int i = 0; i < 3; i++) {
		gotoXY(x, 9 + (i * 4)); cout << "                      ";
		gotoXY(x, 10 + (i * 4)); cout << c[i];
		gotoXY(x, 11 + (i * 4)); cout << "                      ";
	}
}
void hd_xuat() {
	string s[5] = { "STT","Ten vat tu","Don gia","VAT","trang thai" };
	int y = 14;
	gotoXY(60, y); cout << s[0];
	gotoXY(66, y); cout << s[1];
	gotoXY(80, y); cout << s[2];
	gotoXY(92, y); cout << s[3];
	gotoXY(100, y); cout << s[4];
}
void hd_nhap() {
	string s[5] = { "STT","Ten vat tu","Don vi ", "Don gia","VAT" };
	int y = 14;
	gotoXY(60, y); cout << s[0];
	gotoXY(66, y); cout << s[1];
	gotoXY(81, y); cout << s[2];
	gotoXY(92, y); cout << s[3];
	gotoXY(105, y); cout << s[4];
}