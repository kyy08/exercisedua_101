#include <iostream>
#include <vector>
using namespace std;

class pengarang;
class penerbit {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;
	penerbit(string pNama) :nama(pNama) {
		cout << "Penerbit \" " << nama << "\" ada \n";
	}
	~penerbit() {
		cout << "Penerbit \" " << nama << "\" tidak ada \n";
	}
	void tambahPengarang(pengarang*);
	void cetakPengarang();
};

class pengarang {
public:
	string nama;
	vector<penerbit*> daftar_penerbit;

	pengarang(string pNama) :nama(pNama) {
		cout << "Pengarang \" " << nama << "\"ada\n";
	}
	~pengarang() {
		cout << "Pengarang \" " << nama << "\"tidak ada\n";
	}

	void tambahPenerbit();
	void cetakPenerbit();
};

void penerbit::tambahPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}

void penerbit::cetakPengarang() {
	cout << "Daftar Pengarang pada penerbit Gama Press dan Intan Pariwara" " << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

void pengarang::tambahPenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
	pPenerbit->tambahPengarang(this);
}

void pengarang::cetakPenerbit() {
	cout << "Daftar Penerbit Gama Press dan Intan Pariwara dari pengarang \" " << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	pengarang* varPengarang1 = new pengarang("Joko");
	pengarang* varPengarang2 = new pengarang("Lia");
	pengarang* varPengarang3 = new pengarang("Giga");
	pengarang* varpengarang4 = new pengarang("Asroni");
	penerbit* varPenerbit1 = new penerbit("Gama Press");
	penerbit* varPenerbit2 = new penerbit("Intan Pariwara");

	varPengarang3->tambahPenerbit(varPenerbit1);
	varPengarang3->tambahPenerbit(varPenerbit2);
	varPengarang4->tambahPasien(varPenerbit2);
	varPengarang3->tambahPasien(varPenerbit2);

	
}



