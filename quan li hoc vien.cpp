#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct HocVien {
	long long maHV;
	string tenHV;
	int year;
};

void nhapTTHV(HocVien& h) {
	cout << "Nhap ma hoc vien: ";
	cin >> h.maHV;
	cin.ignore();
	cout << "Nhap ten hoc vien: ";
	getline(cin, h.tenHV);
	cout << "Nhap nam: ";
	cin >> h.year;
}

void xuatTTHV(const HocVien h) {
	cout << "==========TTHV==========\n";
	cout << "Ma hoc vien: " << h.maHV << endl;
	cout << "Ten hoc vien: " << h.tenHV << endl;
	cout << "Nam hoc: " << h.year << endl;
	cout << "========================\n";
}
struct NodeHV {
	HocVien hv;
	NodeHV* next;
};

void init(NodeHV*& hv) {
	hv = NULL;
}
NodeHV* createNode(HocVien h) {
	NodeHV* p = new NodeHV;
	p->hv = h;
	p->next = NULL;
	return p;
}
void addHVFirst(NodeHV*& hv, HocVien h) {
	NodeHV* p = createNode(h);
	p->next = hv;
	hv = p;
}
void deleteFirst(NodeHV*& hv) {
	if (hv != NULL) {
		NodeHV* p = hv;
		hv = p->next;
		p->next = NULL;
		delete(p);
	}
}
void docTTTuFile(NodeHV*& hv) {
	//NodeHV* hvtmp = hv;
	ifstream myFile("DSHV.txt");
	if (myFile.is_open()) {
		while (myFile.eof() == false) {
			HocVien h;
			myFile >> h.maHV;
			myFile.ignore();
			getline(myFile, h.tenHV, '\n');
			myFile >> h.year;
			addHVFirst(hv, h);
		}
		cout << "Nhap thong tin thanh cong!" << endl;
		myFile.close();
	}
}
void xuatDSHV(NodeHV* hv) {
	NodeHV* p = hv;
	while (p != NULL) {
		xuatTTHV(p->hv);
		p = p->next;
	}
	cout << endl;
}
void swapNode(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void swap(NodeHV*& a, NodeHV*& b) {
	NodeHV* tmp = a;
	a = b;
	b = tmp;
}
void sortDSByYear(NodeHV* hv) {
	for (NodeHV* i = hv; i != NULL; i = i->next) {
		for (NodeHV* j = i->next; j != NULL; j = j->next) {
			if (i->hv.year > j->hv.year) {
				//swapNode(i->hv.year, j->hv.year);
				swap(i->hv, j->hv);
			}
		}
	}
}
void add1HocVien(NodeHV*& hv, HocVien h) {
	cout << "Nhap thong tin hoc vien can them: \n";
	nhapTTHV(h);
	NodeHV* HV = createNode(h);
	NodeHV* p = hv;
	if (p == NULL) {
		addHVFirst(HV, h);
	}
	else {
		while (p-> next != NULL) {
			p = p->next;
		}
		p->next = HV;
	}
}
void addNhieuHocVien(NodeHV*& hv) {
	int opt;
	do {
		add1HocVien(hv, hv->hv);
		do {
			cout << "Nhap lua chon: (0: ket thuc/ 1: tiep tuc) ";
			cin >> opt;
			if (opt != 0 && opt != 1) {
				cout << "Nhap sai, nhap lai!!!" << endl;
			}
		} while (opt != 0 && opt != 1);
	} while (opt != 0);
}
void deleteHocVien(NodeHV*& hv, int id) {
	
	if (hv == NULL) {
		cout << "Danh sach rong!" << endl;
	}
	else {
		NodeHV* p = hv;
		NodeHV* prev = NULL;
		while (p != NULL && p->hv.maHV != id) {
			prev = p;
			p = p->next;
		}
		if (p != NULL) {// da tim thay
			if (prev == NULL) {
				//vi hv dang tro o vi tri dau
				deleteFirst(hv);
			}
			else {
				prev->next = p->next;
				p->next = NULL;
				delete (p);
			}
		}

	}
}
void clean(NodeHV*& hv) {
	while (hv != NULL) {
		deleteFirst(hv);
	}
}
int main() {
	NodeHV* hv;
	init(hv);
	docTTTuFile(hv);
	xuatDSHV(hv);
	//clean(hv);
	//cout << "==========DANH SANH SAU KHI SORT==========\n";
	//sortDSByYear(hv);
	//xuatDSHV(hv);
	cout << "==========DANH SACH HOC VIEN SAU KHI XOA==========\n";
	deleteHocVien(hv, 5);
	xuatDSHV(hv);
	return 1;
}