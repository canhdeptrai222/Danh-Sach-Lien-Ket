#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#define M 5
using namespace std;

struct NhanVien {
	string hoVaTen;
	double luong;
	string chucVu;
	string queQuan;
};

struct Node {
	NhanVien value;
	Node* next;
};
void init(Node*& head) {
	head = NULL;
}

Node* createNode(NhanVien x) {
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	return p;
}

void addFirst(Node*& head, NhanVien x) {
	Node* p = createNode(x);
	p->next = head;
	head = p;
}

void docFile(Node*& head) {
	fstream myfile("DSNV.txt");
	if (myfile.is_open()) {

		while (!myfile.eof()) {
			NhanVien nv;
			getline(myfile, nv.hoVaTen, '\n');
			myfile >> nv.luong;
			myfile.ignore();
			getline(myfile, nv.chucVu, '\n');
			getline(myfile, nv.queQuan, '\n');
			addFirst(head, nv);
		}

		myfile.close();
	}
}

void xuat1NV(NhanVien nv) {
	cout << "====THONG TIN NHAN VIEN====\n";
	cout << "Ho va ten: " << nv.hoVaTen << endl;
	cout << "Luong: " << nv.luong << endl;
	cout << "Chuc vu: " << nv.chucVu << endl;
	cout << "Que quan: " << nv.queQuan << endl;
	cout << "===========================\n";
}

void output(Node* head) {
	Node* p = head;
	while (p != NULL) {
		xuat1NV(p->value);
		p = p->next;
	}
}

Node* search(Node* head, int fromPrice, int toPrice) {
	Node* kq;
	init(kq);
	Node* p = head;
	while (p != NULL) {
		if(p->value.luong >= fromPrice && p->value.luong <= toPrice){
			addFirst(kq, p->value);
		}
		p = p->next;
	}
	return kq;
}

Node* search(Node* head, string name) {
	Node* kq;
	init(kq);
	Node* p = head;
	while (p != NULL) {
		if (p->value.hoVaTen.find(name) != string::npos) {
			addFirst(kq, p->value);
		}
		p = p->next;
	}
	return kq;
}
void swap(NhanVien& a, NhanVien& b) {
	NhanVien tmp = a;
	a = b;
	b = tmp;
}

void sortPriceAsd(Node*& head) {
	for (Node* p = head; p != NULL; p = p->next) {
		for (Node* q = p->next; q != NULL; q = q->next) {
			if (p->value.luong > q->value.luong) {
				swap(p->value, q->value);
			}
		}
	}
}

void sortQueQuan(Node*& head) {
	for (Node* p = head; p != NULL; p = p->next) {
		for (Node* q = p->next; q != NULL; q = q->next) {
			if (p->value.queQuan < q->value.queQuan) {
				swap(p->value, q->value);
			}
			else if (p->value.queQuan == q->value.queQuan) {
				if (p->value.hoVaTen > q->value.hoVaTen) {
					swap(p->value, q->value);
				}
			}
		}
	}
}

void initHash(Node* heads[]) {
	for (int i = 0; i < M; i++) {
		heads[i] = NULL;
	}
}

int hashFunc(string s) {
	int h = 0;
	for (int i = 0; i < s.length(); i++) {
		h += ((int)s[i]) * (i + 1);
	}
	return h % M;
}

void addToHashTable(Node* heads[], NhanVien nv) {
	int hash = hashFunc(nv.queQuan);
	addFirst(heads[hash], nv);
}

void xuatFile(Node* heads[]) {
	ofstream myFile("NhanVien_output.txt");
	if (myFile.is_open()) {
		for (int i = 0; i < M; i++) {
			if (heads[i] != NULL) {
				Node* p = heads[i];
				string tmp = "";
				int count = 0; double sum = 0;
				while (p != NULL) {
					count++;
					sum += p->value.luong;
					tmp += "Ho va ten: " + p->value.hoVaTen + "\n";
					tmp += "Luong: " + to_string(p->value.luong) + "\n";
					tmp += "Chuc vu: " + p->value.chucVu + "\n";
					p = p->next;
				}
				double avg = sum / count;
				p = heads[i];
				myFile << "===" << p->value.queQuan << ": " << count << " NV; AVG = " << fixed << setprecision(2) << avg << " trieu" << endl;
				myFile << tmp;
			}
		}
		myFile.close();
	}
}

void deleteFirst(Node*& head) {
	if (head != NULL) {
		Node* p = head;
		head = p->next;
		p->next = NULL;
		delete (p);
	}
}

void clean(Node*& head) {
	while (head != NULL) {
		deleteFirst(head);
	}
}


int main() {
	Node* head;
	init(head);
	docFile(head);
	output(head);
	cout << "====TIM KIEM THEO LUONG====\n";
	Node* res = search(head, 9, 10);
	output(res);
	cout << "====TIM KIEM THEO TEN====\n";
	Node* res2 = search(head, "Nguyen");
	output(res2);
	cout << "====PRICE TANG DAN====\n";
	sortPriceAsd(head);
	output(head);
	cout << "====QUE QUAN GIAM DAN====\n";
	sortQueQuan(head);
	output(head);
	cout << "====XUAT DANH SACH GOP NHOM====\n";
	cout << "processing....." << endl;
	Node* hashTable[M];
	initHash(hashTable);
	Node* p = head;
	while (p != NULL) {
		addToHashTable(hashTable, p->value);
		p = p->next;
	}
	xuatFile(hashTable);
	cout << "DONE!" << endl;
	clean(res2);
	clean(res);
	clean(head);
	return 1;
}