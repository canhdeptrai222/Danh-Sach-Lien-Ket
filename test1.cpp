#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <cstring>
#define MAX 100
using namespace std;

int NhapSoNguyen(string s, int min, int max) {
	int n;
	do {
		cout << s;
		cin >> n;
		if (n < min || n > max) {
			cout << "Nhap lai!!!";
		}
	} while (n < min || n > max);
	return n;
}

struct SinhVien
{
	int MSSV;
	string hoVaten;
	char ngaySinh[11];
	string queQuan;
	double diemTB;
};

void nhap1SV(SinhVien& sv)
{
	cout << "Nhap MSSV: ";
	cin >> sv.MSSV;
	cin.ignore();
	cout << "Nhap ho va ten: ";
	getline(cin, sv.hoVaten, '\n');
	cout << "Nhap ngay sinh: ";
	cin >> sv.ngaySinh;
	cin.ignore();
	cout << "Nhap que quan: ";
	getline(cin, sv.queQuan, '\n');
	cout << "Nhap diem TB: ";
	cin >> sv.diemTB;
}

void xuat1SV(const SinhVien sv)
{
	cout << "=========THONG TIN SINH VIEN==========\n";
	cout << "MSSV: " << sv.MSSV << endl;
	cout << "Ho va ten: " << sv.hoVaten << endl;
	cout << "Ngay sinh: " << sv.ngaySinh << endl;
	cout << "Que quan: " << sv.queQuan << endl;
	cout << "Diem TB: " << sv.diemTB << endl;
	cout << "======================================\n";
}

struct DSSV
{
	SinhVien sv[MAX];
	int n;
};

void nhapDSSV(DSSV& ds) {
	ds.n = NhapSoNguyen("Nhap so luong sinh vien: ", 1, 100);
	for (int i = 0; i < ds.n; i++) {
		nhap1SV(ds.sv[i]);
	}
}

void xuatDSSV(DSSV& ds) {
	cout << "=========DANH SACH SINH VIEN==========\n";
	for (int i = 0; i < ds.n; i++) {
		xuat1SV(ds.sv[i]);
	}
}

void nhapSVtuFile(DSSV& ds) {
	ifstream myFile("SinhVien.txt");
	if (myFile.is_open()) {
		myFile >> ds.n;
		for (int i = 0; i < ds.n; i++) {
			myFile >> ds.sv[i].MSSV;
			myFile.ignore();
			getline(myFile, ds.sv[i].hoVaten, '#');
			myFile.getline(ds.sv[i].ngaySinh, 11, '#');
			getline(myFile, ds.sv[i].queQuan, '#');
			myFile >> ds.sv[i].diemTB;
		}
		cout << "DONE!" << endl;
		myFile.close();
	}
}


int search(DSSV ds, int id) {

	for (int i = 0; i < ds.n; i++) {
		if (ds.sv[i].MSSV == id)
			return i;
	}
	return -1;

}

int search(DSSV ds, string key) {

	for (int i = 0; i < ds.n; i++) {
		if (ds.sv[i].hoVaten == key || ds.sv[i].queQuan == key)
			return i;
	}
	return -1;
}

void swap(SinhVien& sv1, SinhVien& sv2) {
	SinhVien tmp = sv1;
	sv1 = sv2;
	sv2 = tmp;
}
int cpmWithID(SinhVien sv1, SinhVien sv2) {
	if (sv1.MSSV > sv2.MSSV)
		return 1;
	if (sv1.MSSV < sv1.MSSV)
		return -1;
	return 0;
}
void sort(DSSV ds, int compare(SinhVien, SinhVien)) {
	for (int i = 0; i < ds.n - 1; i++) {
		for (int j = i + 1; j < ds.n; j++) {
			if (compare(ds.sv[i], ds.sv[j]) == -1)
				swap(ds.sv[i], ds.sv[j]);
		}
	}
}

void delSV(DSSV& ds, int id) {
	int index = search(ds, id);
	if (index != -1) {
		for (int i = index; i < ds.n; i++) {
			ds.sv[i] = ds.sv[i + 1];
		}
		ds.n--;
	}
}

void addSV(DSSV& ds, int id, SinhVien sv) {
	int index = search(ds, id);
	if (index != -1 && index < MAX) {

		for (int i = ds.n; i > index; i--) {
			ds.sv[i] = ds.sv[i - 1];
		}
		ds.sv[index] = sv;
		ds.n++;
	}
}

void loading() {
	cout << "Loading.";
	for (int i = 0; i < 10; i++) {
		Sleep(500);
		cout << ".";
	}
}
int main() {
	DSSV ds;
	nhapSVtuFile(ds);
	xuatDSSV(ds);
	//delSV(ds, 2018010);
	/*SinhVien sv;
	nhap1SV(sv);
	addSV(ds, 2018004, sv);
	xuatDSSV(ds);*/
	cout << "=======TIMM KIEM=====\n";
	auto res = 2018010;
	cout << search(ds, res);
	system("Color A");
	return 1;
}