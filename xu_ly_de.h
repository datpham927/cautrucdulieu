#pragma once
#include"doc_file.h"
//====================== Vat tu ==========================
void them_vat_tu(List_vat_tu& vt);
void in_danh_sach_vt(List_vat_tu& vt);
void xoa_vat_tu(List_vat_tu& vt);
string code_auto_vt();
void chuyen_hoa_chu(string& a);
int kt_code_trung(string& a, List_vat_tu& vt);
void Hieu_chinh_vt(List_vat_tu& vt);
//====================== Nhan vien ========================
void them_nhan_vien(list_nhan_vien& nv);
int  code_auto_nv();
int kt_code_trung_nv(tree& t, int& code);
void Chuyen_sang_arr(tree ds, tree p[], int& sl);
void sap_xep_chuoi(tree arr[], int sl);
void Hoan_vi_nv(tree a, tree b);
void Xuat_nhan_vien(nhan_vien* arr[], int sl);
void Giai_phong_vung_nho(tree arr[], int sl);
void xoa_nhan_vien(tree t);
void xoa_1_nv(tree& t, int& code);
void node_thay_the(nhan_vien*& t, nhan_vien*& x);
void Hieu_chinh_nv(list_nhan_vien& nv);
//==================== Hóa đơn =============================
void lap_hoa_don(list_nhan_vien& nv);
nhan_vien* kt_ma_nv(tree& t, int& ma);
string tao_ma_hd(List_hoa_don hd);
bool kt_trung_ma_hd(List_hoa_don p, string& ma);


string code_auto_vt() {
	string s = "HDC000";
	srand(time(NULL));
	for (int i = 3; i < s.size(); i++) {
		s[i] = rand() % 10 + 48;
	}
	return s;
}
int  code_auto_nv() {
	int s;
	do {
		srand(time(NULL));
		s = rand() % 999 + 100;
	} while (kt_code_trung_nv < 0);
	return s;
}
void chuyen_hoa_chu(string& a) {
	//xóa đầu
	while (a[0] == ' ') {
		a.erase(a.begin() + 0);
	}
	//xóa cuối
	while (a.size() - 1 == ' ') {
		a.erase(a.begin() + a.length() - 1);
	}
	//xóa giữa
	for (int i = 1; i < a.size(); i++) {
		if (a[i] == ' ' && a[i + 1] == ' ') {
			a.erase(a.begin() + i + 1);
			i--;
		}
	}
	//viết hoa kí tự đầu tiên
	if (a[0] >= 97 && a[0] <= 122) {
		a[0] -= 32;
	}
	//viết hoa kí tự sau khoảng trắng
	for (int i = 1; i < a.size(); i++) {
		if (a[i] == ' ') {
			if (a[i + 1] >= 97 && a[i + 1] <= 122) {
				a[i + 1] -= 32;
			}
		}
		else {
			//viết thường
			if (a[i + 1] >= 65 && a[i + 1] <= 90) {
				a[i + 1] += 32;
			}
		}
	}

}
void them_vat_tu(List_vat_tu& vt) {
	ShowCur(true);
	int x = 90, y = 8, w = 30, h = 2, sl = 4;
	string s = "NHAP VAT TU";
	n_khung_nhap(x, y, w, h, s, sl);
	thong_tin_nhap_vt();
		gotoXY(x + 1, y + 1); cout << code_auto_vt();
		vat_tu* p = new vat_tu;
		p->ma_vt = code_auto_vt(); cin.ignore();
		gotoXY(x + 1, y + 5);  getline(cin, p->ten_vt);
		gotoXY(x + 1, y + 9); getline(cin, p->don_vi_tinh);
		gotoXY(x + 1, y + 13); cin >> p->so_luong_ton;
		

		vt.ds[vt.sl] = p;
		vt.sl++;
		/*ofstream file;
		file.open("ds_vt.txt", ios_base::in);
		file.open("ds_vt.txt", ios_base::in);
		file << p->ma_vt << ",";
		file << p->ten_vt << ",";
		file << p->don_vi_tinh << ",";
		file << p->so_luong_ton << endl;;
		file.close();*/
}
void in_danh_sach_vt(List_vat_tu& vt) {
	int y = 9;
	Khung_Xuat_vat_tu();
	for (int i = 0; i < vt.sl; i++) {
		SetColor(2);
		chuyen_hoa_chu(vt.ds[i]->don_vi_tinh);
		chuyen_hoa_chu(vt.ds[i]->ten_vt);
		gotoXY(54, y); cout<< vt.ds[i]->ma_vt;
		gotoXY(64, y); cout << vt.ds[i]->ten_vt;
		gotoXY(88, y); cout << vt.ds[i]->don_vi_tinh;
		gotoXY(106, y); cout << vt.ds[i]->so_luong_ton;
		Sleep(20);
		 y++;
		}
	while (!_kbhit()) {
		SetColor(rand() % 15 + 1);
		gotoXY(68, 29); cout << "Please ! press enter to exit";
		Sleep(200);
	}
}
void xoa_vat_tu(List_vat_tu& vt) {
	ShowCur(true);
	string a;
	TextColor(1);
	gotoXY(76, 8); cout << "MA SO CAN XOA "; cin.ignore();
	gotoXY(79, 9); getline(cin, a);
	int kt = kt_code_trung(a, vt);
	if (kt < 0) {
		while (!_kbhit()) {
			SetColor(rand() % 15 + 1);
			gotoXY(65, 11); cout << "Vat tu khong ton tai hoac da bi xoa !";
			Sleep(200);
		}
	}
	else {
		for (int i = 0; i < vt.sl; i++) {
			if (vt.ds[i]->ma_vt == a) {
				vt.ds[i] = vt.ds[i + 1];
				vt.sl--;
			}
		}
		while (!_kbhit()) {
			SetColor(rand() % 15 + 1);
			gotoXY(74, 11); cout << "Da xoa thanh cong !" << endl;
			Sleep(200);
		}

	}
}
int kt_code_trung(string& a, List_vat_tu& vt) {
	for (int i = 0; i < vt.sl; i++) {
		if (vt.ds[i]->ma_vt == a) {
			return i;
		}
	}
	return -1;
}
void Hieu_chinh_vt(List_vat_tu& vt) {
	ShowCur(true);
	int x = 90, y = 10, w = 30, h = 2, sl = 3;
	string a = "HIEU CHINH VAT TU";
	n_khung_nhap(x, y, w, h, a, sl);

	string s[4] = { "NHAP MA VAT TU :",
					"TEN VAT TU :",
					"DON VI TINH :", };
	SetColor(30);
	int j = 0;
	for (int i = 11; i <= 25; i += 4) {
		gotoXY(65, i);
		if (j < 4) {
			cout << s[j];
		}
		j++;
	}
	SetColor(7); gotoXY(65, 26); cout << "ENTER : Cap nhat                       ESC : Thoat";
	string code;
	gotoXY(93, 11); cin.ignore(); getline(cin, code);

	int kt = kt_code_trung(code, vt);
	if (kt == -1) {
		while (!_kbhit()) {
			SetColor(rand() % 15 + 1);
			gotoXY(70, 7); cout << "Code vat tu khong ton tai !";
			Sleep(100);
		}
	}
	else {
		gotoXY(93, 15); getline(cin, vt.ds[kt]->ten_vt);
		gotoXY(93, 19); getline(cin, vt.ds[kt]->don_vi_tinh);
		chuyen_hoa_chu(vt.ds[kt]->don_vi_tinh);
		chuyen_hoa_chu(vt.ds[kt]->ten_vt);
		gotoXY(70, 7); SetColor(13); cout << "Cap nhat thanh cong ";
	}
}
void them_nhan_vien(list_nhan_vien& nv) {
	ShowCur(true);
	int x = 90, y = 8, w = 30, h = 2, sl = 4;
	string s = "NHAP NHAN VIEN";
	n_khung_nhap(x, y, w, h, s, sl);
	thong_tin_nhap_nv();
	nhan_vien* p = khoitaonode();
	gotoXY(x + 1, y + 1); cout << code_auto_nv();
	p->ma_nv = code_auto_nv(); cin.ignore();
	gotoXY(x + 1, y + 5);  getline(cin, p->ho);
	gotoXY(x + 1, y + 9); getline(cin, p->ten);
	gotoXY(x + 1, y + 13); cin >> p->phai;
	them_vao_cay(nv.TREE, p);
	nv.sl++;

}
void Chuyen_sang_arr(tree ds, tree p[], int& sl) {
	if (ds != NULL) {
		p[sl] = new nhan_vien;
		p[sl]->ho = ds->ho;
		p[sl]->ma_nv = ds->ma_nv;
		p[sl]->phai = ds->phai;
		p[sl]->ten = ds->ten;
		sl++;
		Chuyen_sang_arr(ds->pleft, p, sl);
		Chuyen_sang_arr(ds->pright, p, sl);
	}
}
void Xuat_nhan_vien(nhan_vien* arr[], int sl) {
	int y = 9;
	Khung_Xuat_nhan_vien();
	for (int i = 0; i < sl; i++) {
		chuyen_hoa_chu(arr[i]->ho);
		chuyen_hoa_chu(arr[i]->ten);
		chuyen_hoa_chu(arr[i]->phai);
		gotoXY(70, y); cout << arr[i]->ma_nv;
		gotoXY(79, y); cout << arr[i]->ho << " " << arr[i]->ten;
		gotoXY(105, y); cout << arr[i]->phai;
		y++;
	}
	while (!_kbhit()) {
		SetColor(rand() % 15 + 1);
		gotoXY(68, 29); cout << "Please ! press enter to exit";
		Sleep(200);
	}
}
void sap_xep_chuoi(tree arr[], int sl) {
	for (int i = 0; i < sl - 1; i++) {
		for (int j = i + 1; j < sl; j++) {
			if (arr[i]->ten > arr[j]->ten) {
				Hoan_vi_nv(arr[i], arr[j]);
			}
			else if (arr[i]->ten == arr[i]->ten) {
				if (arr[i]->ho > arr[j]->ho) {
					Hoan_vi_nv(arr[i], arr[j]);
				}
			}
		}
	}
}
int kt_code_trung_nv(tree& t, int& code)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		if (t->ma_nv == code)
		{
			return 1;
		}
		else if (t->ma_nv < code)
		{
			kt_code_trung_nv(t->pright, code);
		}
		else
		{
			kt_code_trung_nv(t->pleft, code);
		}
	}
}
void Hoan_vi_nv(tree a, tree b) {
	tree tam = new nhan_vien;
	tam = a;
	a = b;
	b = tam;
}
void Giai_phong_vung_nho(tree arr[], int sl) {

	for (int i = 0; i < sl; i++) {
		delete arr[i];
	}
}
void xoa_nhan_vien(tree t) {
	int  code;
	cin >> code;
	if (kt_code_trung_nv(t, code) >= 0) {
		xoa_1_nv(t, code);
	}
	else {
		cout << "khong ton tai phan tu ";

	}
}
void xoa_1_nv(tree& t, int& code) {
	if (t != NULL) {
		nhan_vien* x = t;
		if (t->ma_nv == code) {
			if (t->pleft == NULL) {
				t = t->pright;
			}
			else if (t->pright == NULL) {
				t = t->pleft;
			}
			else if (t->pleft != NULL && t->pright != NULL) {
				//tim node thay the
				//node_thay_the(t, x);
			}
			delete x;
			cout << "Da xoa thanh cong " << endl;
		}
		else if (t->ma_nv > code) {
			xoa_1_nv(t->pleft, code);
		}
		else if (t->ma_nv < code) {
			xoa_1_nv(t->pright, code);
		}

	}
}
void node_thay_the(nhan_vien*& t, nhan_vien*& x) {
	if (t->pleft != NULL) {
		node_thay_the(t->pleft, x);
	}
	else {
		Hoan_vi_nv(t, x);
		x = t;
		t = t->pright;
	}
}
void Hieu_chinh_nv(list_nhan_vien& nv) {
	ShowCur(true);
	int x = 90, y = 10, w = 30, h = 2, sl = 3;
	string a = "HIEU CHINH NHAN VIEN";
	n_khung_nhap(x, y, w, h, a, sl);

	string s[4] = { "HO NV :",
					"TEN NV :",
					"PHAI :", };
	SetColor(30);
	int j = 0;
	for (int i = 11; i <= 25; i += 4) {
		gotoXY(65, i);
		if (j < 4) {
			cout << s[j];
		}
		j++;
	}
	SetColor(7); gotoXY(65, 26); cout << "ENTER : Cap nhat                       ESC : Thoat";
	int code;
	gotoXY(93, 11); cin >> code;

	int kt = kt_code_trung_nv(nv.TREE, code);
	if (kt == 0) {
		while (!_kbhit()) {
			SetColor(rand() % 15 + 1);
			gotoXY(70, 7); cout << "Code vat tu khong ton tai !";
			Sleep(100);
		}
	}
	else {
		gotoXY(93, 15); getline(cin, nv.TREE->ho);
		gotoXY(93, 19); getline(cin, nv.TREE->ten);
		gotoXY(93, 23); getline(cin, nv.TREE->phai);
		chuyen_hoa_chu(nv.TREE->ho);
		chuyen_hoa_chu(nv.TREE->ten);
		chuyen_hoa_chu(nv.TREE->phai);
		gotoXY(70, 7); SetColor(13); cout << "Cap nhat thanh cong ";
	}
}
//void lap_hoa_don(list_nhan_vien& ds_nv) {
//	//doc_file_nhan_vien(ds_nv);
//	int code_nv;
//	TextColor(1);
//	ShowCur(1);
//	gotoXY(70, 10); cout << "NHAP MA NHAN VIEN LAP HOA DON  "; gotoXY(83, 12); cin >> code_nv;
//	nhan_vien* tam = kt_ma_nv(ds_nv.TREE, code_nv);
//	if (tam == NULL) {
//		do {
//			ShowCur(0);
//			int n = rand() % 15 + 1;
//			SetColor(n);
//			gotoXY(73, 15);  cout << "Nhan vien khong ton tai ";
//			Sleep(100);
//		} while (!_kbhit());
//	}
//	else {
//		HOA_DON* hd = khoi_tao_node_hoa_don();
//		bool nhap;
//		bool kt = true;
//		int vt = 0;
//		int vtm = vt;
//		int vtc = vtm;
//		Menu_Hd(140);
//		while (true) {
//			if (kt == true) {
//				Thanh_sang_hd(vtc, 140);
//				Thanh_sang_hd(vtm, 40);
//				vtc = vtm;
//				kt = false;
//			}
//			if (_kbhit()) {
//				kt = true;
//				char c = _getch();
//				if (c == -32) {
//					c = _getch();
//					if (c == 72) {
//						if (vtm != 0) vtm--;
//						else vtm = 2;
//					}
//					else if (c == 80) {
//						if (vtm != 2) vtm++;
//						else vtm = vt;
//					}
//				}
//				if (c == 13) {
//					system("cls");
//					if (vtm == 0) {
//						Khung_NX_hd();
//						gotoXY(80, 5); cout << "HOA DON NHAP\n";
//						nhap = true;
//						hd->loai = 'N';
//					}if (vtm == 1) {
//						Khung_NX_hd();
//						gotoXY(75, 5); cout << "HOA DON XUAT\n";
//						nhap = false;
//						hd->loai = 'X';
//					}if (vtm == 2) {
//						break;
//					}
//					ShowCur(1);
//					gotoXY(65, 7); cout << "MA HOA DON : "; gotoXY(79, 7); cin >> hd->so_hd;
//
//					//hd->so_hd = tao_ma_hd(tam->ds_hoa_don);
//					gotoXY(64, 9); cout << "NGAY LAP HD : ";
//					cin.ignore(); getline(cin, hd->ngay_lap_hd);
//					do {
//						int n = rand() % 15 + 1;
//						SetColor(n);
//						gotoXY(67, 11); cout << "Nhan enter de nhap chi tiet hoa don";
//						Sleep(100);
//					} while (!_kbhit());
//					//tạm dừng khi chưa nhấn phím
//					if (c == 13) {
//						gotoXY(67, 11); cout << "                                          \n";
//						if (nhap == true) {
//							int soluong;
//							gotoXY(66, 13); cout << "So luong vat tu can nhap : "; gotoXY(10, 12); cin >> soluong;
//
//							gotoXY(66, 13); cout << "                              \n";
//							hd_nhap_xuat();
//							int y = 14;
//							int i = 0;
//							for (int i = 0; i < soluong; i++) {
//								gotoXY(62, y + ((i + 1) * 2)); cout << i + 1;
//								gotoXY(68, y + ((i + 1) * 2)); cin.ignore(); getline(cin, hd->danh_sach_chi_tiet_hd.ds->vattu.ten_vt);
//								gotoXY(82, y + ((i + 1) * 2)); cin.ignore(); getline(cin, hd->danh_sach_chi_tiet_hd.ds->vattu.don_vi_tinh);
//								gotoXY(94, y + ((i + 1) * 2)); cin >> hd->danh_sach_chi_tiet_hd.ds->don_gia;
//								gotoXY(102, y + ((i + 1) * 2)); cin >> hd->danh_sach_chi_tiet_hd.ds->VAT;
//								hd->danh_sach_chi_tiet_hd.sl++;
//							}
//
//						}
//					}
//				}
//			}
//		}
//	}
//}
nhan_vien* kt_ma_nv(tree& t, int& ma) {
	if (t != NULL) {
		if (t->ma_nv == ma) {
			return t;
		}
		else {
			if (t->ma_nv < ma) {
				kt_ma_nv(t->pleft, ma);
			}
			else if (t->ma_nv > ma) {
				kt_ma_nv(t->pright, ma);
			}

		}
		return NULL;
	}
}
string tao_ma_hd(List_hoa_don hd) {
	string s = "HD0000";
	srand(time(NULL));
	do {
		for (int i = 2; i < s.size(); i++) {
			s[i] = rand() % 10 + 48;
		}
	} while (kt_trung_ma_hd(hd, s) == true);

	return s;
}
bool kt_trung_ma_hd(List_hoa_don p, string& ma) {
	for (HOA_DON* k = p.phead; k != NULL; k = k->pnext) {
		if (k->so_hd == ma) {
			return true;
		}
	}
	return false;
}

void lap_hoa_don(list_nhan_vien& ds_nv) {
	int color = 60;
	doc_file_nhan_vien(ds_nv);
	int code_nv;
	TextColor(1);
	gotoXY(70, 10); cout << "NHAP MA NHAN VIEN LAP HOA DON  "; gotoXY(83, 12); cin >> code_nv;
	nhan_vien* tam = kt_ma_nv(ds_nv.TREE, code_nv);
	if (tam == NULL) {
		do {
			int n = rand() % 15 + 1;
			SetColor(n);
			gotoXY(73, 15);  cout << "Nhan vien khong ton tai ";
			Sleep(100);
		} while (!_kbhit());
	}
	else {
		HOA_DON* hd = khoi_tao_node_hoa_don();
		bool nhap;
		bool kt = true;
		int vt = 0;
		int vtm = vt;
		int vtc = vtm;
		Menu_Hd(140);
		while (true) {
			if (kt == true) {
				Thanh_sang_hd(vtc, 140);
				Thanh_sang_hd(vtm, 40);
				vtc = vtm;
				kt = false;
			}
			if (_kbhit()) {
				kt = true;
				char c = _getch();
				if (c == -32) {
					c = _getch();
					if (c == 72) {
						if (vtm != 0) vtm--;
						else vtm = 2;
					}
					else if (c == 80) {
						if (vtm != 2) vtm++;
						else vtm = vt;
					}
				}
				if (c == 13) {
					system("cls");
					if (vtm == 0) {
						Menu_chinh_f0(0, 60);
						Khung_NX_hd();
						gotoXY(80, 5); cout << "HOA DON NHAP\n";
						nhap = true;
						hd->loai = 'N';
					}if (vtm == 1) {
						Menu_chinh_f0(0, 60);
						Khung_NX_hd();
						gotoXY(75, 5); cout << "HOA DON XUAT\n";
						nhap = false;
						hd->loai = 'X';
					}if (vtm == 2) {
						break;
					}
					ShowCur(1);
					gotoXY(65, 7); cout << "MA HOA DON : "; gotoXY(79, 7); cin >> hd->so_hd;
					//hd->so_hd = tao_ma_hd(tam->ds_hoa_don);
					gotoXY(64, 9); cout << "NGAY LAP HD : ";
					cin.ignore(); getline(cin, hd->ngay_lap_hd);
					do {
						int n = rand() % 15 + 1;
						SetColor(n);
						gotoXY(67, 11); cout << "Nhan enter de nhap chi tiet hoa don";
						Sleep(100);
					} while (!_kbhit());
					
						gotoXY(67, 11); cout << "                                          \n";
						if (nhap == true) {
							ShowCur(1);
							int soluong;
							Menu_chinh_f0(0, color);
							TextColor(1);
							gotoXY(66, 13); cout << "So luong vat tu can nhap : "; 
							gotoXY(70, 13); cin >> soluong;
							gotoXY(66, 13); cout << "                              \n";
							int y = 14;
							int i = 0;
							hd_nhap();
							List_vat_tu vt;
							for (int i = 0; i < soluong; i++) {
								ShowCur(1);
								gotoXY(60, y + ((i + 1) * 2)); cout << i + 1;
								gotoXY(67, y + ((i + 1) * 2)); cin.ignore(); getline(cin, hd->danh_sach_chi_tiet_hd.ds[i].vattu.ten_vt);
								gotoXY(82, y + ((i + 1) * 2));getline(cin, hd->danh_sach_chi_tiet_hd.ds[i].vattu.don_vi_tinh);
								gotoXY(92, y + ((i + 1) * 2)); cin >> hd->danh_sach_chi_tiet_hd.ds[i].don_gia;
								gotoXY(106, y + ((i + 1) * 2)); cin >> hd->danh_sach_chi_tiet_hd.ds[i].VAT;
								chuyen_hoa_chu(hd->danh_sach_chi_tiet_hd.ds[i].vattu.ten_vt);
								chuyen_hoa_chu(hd->danh_sach_chi_tiet_hd.ds[i].vattu.don_vi_tinh);
								hd->danh_sach_chi_tiet_hd.sl++;
								/*for (int j = 0; j < vt.sl; j++) {
									if (vt.ds[j]->ma_vt == hd->danh_sach_chi_tiet_hd.ds[i].vattu.ma_vt);
								}*/
							}

							}
							/*for (int i = 0; i < hd->danh_sach_chi_tiet_hd.sl; i++) {
								cout << "Ten vat tu : " << hd->danh_sach_chi_tiet_hd.ds[i].vattu.ten_vt << endl;
								cout << "Don vi tinh : " << hd->danh_sach_chi_tiet_hd.ds[i].vattu.don_vi_tinh << endl;
								cout << "Don gia :" << hd->danh_sach_chi_tiet_hd.ds[i].don_gia << endl;

							}*/

						}
					}
				}
			}
		}
