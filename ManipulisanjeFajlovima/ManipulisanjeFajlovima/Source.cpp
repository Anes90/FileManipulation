#include<iostream>
#include<fstream>
using namespace std;

char *crt = "\n===========================================================\n";
char *poruka_o_gresci = "Greska prilikom otvaranja datoteke!";

void UnosSadrzaja(const char * nazivFajla) {
	cout << crt << "\t\t::UNOS SADRZAJA::" << crt;
	const int max = 200;
	char tekst[max];
	ofstream upis(nazivFajla);
	if (upis.fail())
		cout << crt << poruka_o_gresci << crt;
	else {
		cout << "Unesite tekst: ";
		cin.getline(tekst, max);
		upis << tekst;
		cout << crt << "Sadrzaj upisan u datoteku!" << crt;
	}
	upis.close();
}

void PrikazSadrzaja(const char *nazivFajla) {
	cout << crt << "\t\t::PRIKAZ SADRZAJA::" << crt;
	char znak;
	ifstream ispis(nazivFajla, ios::in | ios::_Nocreate);
	if (ispis.fail())
		cout << crt << poruka_o_gresci << crt;
	else {
		cout << crt << "DATOTEKA: " << nazivFajla << crt << "SADRZAJ:" << crt;
		while (ispis.get(znak))
			cout << znak;
		cout << crt << "Sadrzaj datoteke prikazan!" << crt;
	}
	ispis.close();
}

void DodavanjeSadrzaja(const char *nazivFajla) {
	cout << crt << "\t\t::DODAVANJE TEKSTA::" << crt;
	const int max = 200;
	char noviTekst[max];
	ofstream upis(nazivFajla, ios::app | ios::_Nocreate);
	if (upis.fail())
		cout << crt << poruka_o_gresci << crt;
	else {
		cout << "Unesite sadrzaj koji zelite dodati: ";
		cin.getline(noviTekst, max);
		upis << endl << noviTekst << endl;
		cout << crt << "Novi sadrzaj uspjesno dodan!" << endl;
	}
	upis.close();
}

void KopiranjeSadrzaja(const char *nazivFajla) {
	cout << crt << "\t\t::KOPIRANJE SADRZAJA::" << crt;
	const int max = 30;
	char nazivNovogFajla[max];
	char znak;
	cout << "Unesite ime datoteke u koju zelite kopirati sadrzaj: ";
	cin.getline(nazivNovogFajla, max);
	ifstream ispis(nazivFajla, ios::in | ios::_Nocreate);
	ofstream upis(nazivNovogFajla, ios::app);
	if (!ispis.fail()) {
		if (!upis.fail()) {
			while (ispis.get(znak))
				upis << znak;
			cout << crt << "Sadrzaj datoteke: " << nazivFajla;
			cout << " uspjesno kopiran u datoteku: " << nazivNovogFajla << crt;
		}
		else cout << crt << "Destinacijski::" << poruka_o_gresci << crt;
	}
	else cout << crt << "Izvorni::" << poruka_o_gresci << crt;
	ispis.close();
	upis.close();
}

int VelicinaFajla(const char * nazivFajla) {
	cout << crt << "\t\t::VELICINA DATOTEKE::" << crt;
	ifstream ispis(nazivFajla);
	if (!ispis.fail()) {
		ispis.seekg(0, ios::end);
		int velicina = ispis.tellg();
		cout << "Velicina datoteke je: " << velicina << " bajta." << crt;
		ispis.close();
		return velicina;
	}
	else
		cout << crt << poruka_o_gresci << crt;
	return -1;
}

void PretragaSadrzajaKarakter(const char * nazivFajla) {
	cout << crt << "\t\t::PRETRAGA (karakter)::" << crt;
	char znak, trazeni;
	int ukupno = 0, pronadjeno = 0;
	ifstream ispis(nazivFajla);
	cout << "Unesite znak koji trazite: ";
	cin >> trazeni;
	cin.ignore(100, '\n');
	if (!ispis.fail()) {
		while (ispis.get(znak)) {
			if (znak == trazeni)
				pronadjeno++;
			ukupno++;
		}
		cout << crt << "Fajl " << nazivFajla << " ima ukupno " << ukupno << " znakova.";
		cout << crt << "Znak '" << trazeni << "' se nalazi na " << pronadjeno << " mjesta.";
	}
	else
		cout << crt << poruka_o_gresci << crt;
	ispis.close();
}

void PretragaSadrzajaRijec(const char * nazivFajla) {
	cout << crt << "\t\t::PRETRAGA (rijec)::" << crt;
	char rijec[15];
	char znak, temp[1000];
	int pronadjeno = 0;
	cout << "Unesite rijec koju trazite: ";
	cin.getline(rijec, 15);
	ifstream ispis(nazivFajla);
	if (!ispis.fail()) {
		while (ispis.get(znak)) {
			ispis >> temp;
		}
	}
	else
		cout << crt << poruka_o_gresci << crt;
	if (strstr(temp, rijec) != NULL)
		cout << crt << "U datoteci je pronadjena rijec '" << rijec << "'." << crt;
	else
		cout << crt << "U datoteci nije pronadjena rijec '" << rijec << "'." << crt;

}

void BrisanjeSadrzaja(const char * nazivFajla) {
	cout << crt << "\t\t::BRISANJE SADRZAJA::" << crt;
	ofstream ispis(nazivFajla, ios::trunc);
	if (!ispis.fail())
		cout << crt << "Sadrzaj datoteke " << nazivFajla << " obrisan!" << crt;
	else
		cout << crt << poruka_o_gresci << crt;
}

void PrikaziMeni(int & izbor) {
	do {
		cout << crt << "\t\t::MANIPULISANJE DATOTEKAMA::" << crt;
		cout << "1. Upisi sadrzaj u datoteku. " << endl;
		cout << "2. Prikazi sadrzaj datoteke. " << endl;
		cout << "3. Dodaj novi sadrzaj datoteci. " << endl;
		cout << "4. Kopiraj sadrzaj datoteke u drugu datoteku. " << endl;
		cout << "5. Pretrazuj sadrzaj datoteke (karakter). " << endl;
		cout << "6. Pretrazuj sadrzaj datoteke (rijec)." << endl;
		cout << "7. Prikazi velicinu datoteke. " << endl;
		cout << "8. Brisi sadrzaj datoteke. " << endl;
		cout << "9. Rad sa novom datotekom. " << endl;
		cout << "10. Izadji iz programa. " << crt;
		cout << "Unesite vas izbor: ";
		cin >> izbor;
		cin.ignore();
		system("cls");
	} while (izbor < 1 || izbor>10);
}

void main() {
	int izbor = 1;
	const int max = 30;
	char nazivFajla[max];
	do {
		cout << crt << "\t\t::MANIPULISANJE DATOTEKAMA::" << crt;
		cout << "Unesite ime datoteke i ekstenziju: ";
		cin.getline(nazivFajla, max);
		do {
			PrikaziMeni(izbor);
			switch (izbor) {
			case 1:UnosSadrzaja(nazivFajla); break;
			case 2:PrikazSadrzaja(nazivFajla); break;
			case 3:DodavanjeSadrzaja(nazivFajla); break;
			case 4:KopiranjeSadrzaja(nazivFajla); break;
			case 5: PretragaSadrzajaKarakter(nazivFajla); break;
			case 6: PretragaSadrzajaRijec(nazivFajla); break;
			case 7: VelicinaFajla(nazivFajla); break;
			case 8: BrisanjeSadrzaja(nazivFajla); break;
			}
		} while (izbor != 9 && izbor != 10);
	} while (izbor != 10);
	system("pause>0");
}