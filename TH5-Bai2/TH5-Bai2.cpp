#include "MATRAN.h"

int main()
{
	MATRAN x;
	int cont;
	do
	{
		cout << "=====================CHUONG TRINH=======================" << endl;
		cout << "1. Nhap ma tran" << endl;
		cout << "2. Phat sinh ma tran" << endl;
		cout << "3. Xuat ma tran" << endl;
		cout << "4. Cai dat ma tran bang setSD" << endl;
		cout << "5. Cai dat ma tran bang setSC" << endl;
		cout << "6. Liet ke SNT co trong ma tran" << endl;
		cout << "7. Tim so phan tu la so chinh phuong trong ma tran" << endl;
		cout << "8. Tinh tong so hoan thien" << endl;
		cout << "9. Tinh trung binh cong so doi xung" << endl;
		cout << "10. Sap xep ma tran giam dan" << endl;
		cout << "11. Sap xep ma tran tang dan tren dong" << endl;
		cout << "12. Xoa ma tran" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "======================================================" << endl;
		cout << "Lua chon cua ban la: ";
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
			cin >> x;
			break;
		case 2:
			x.phat_sinh();
			break;
		case 3:
			cout << x;
			break;
		case 4:
			int sd;
			cout << "Nhap so dong ban muon set: ";
			cin >> sd;
			while (cin.fail() || sd < 0)
			{
				cin.clear();
				cin.ignore();
				cout << "Khong hop le! Vui long nhap lai!" << endl;
				cout << "Nhap so dong ban muon set: ";
				cin >> sd;
			}
			x.setSD(sd);
			cout << "Ma tran sau khi set " << sd << " dong: " << endl;
			cout << x;
			break;
		case 5:
			int sc;
			cout << "Nhap so cot ban muon set: ";
			cin >> sc;
			while (cin.fail() || sc < 0)
			{
				cin.clear();
				cin.ignore();
				cout << "Khong hop le! Vui long nhap lai!" << endl;
				cout << "Nhap so cot ban muon set: ";
				cin >> sc;
			}
			x.setSC(sc);
			cout << "Ma tran sau khi set " << sc << " cot: " << endl;
			cout << x;
			break;
		case 6:
			x.liet_ke_SNT();
			break;
		case 7:
			cout << "Trong ma tran co " << x.so_ptu_SCP() << " la so chinh phuong" << endl;
			break;
		case 8:
			cout << "Tong gia tri la so hoan thien trong ma tran la: " << x.tong_SHT() << endl;
			break;
		case 9:
			cout << "Trung binh cong so doi xung co trong ma tran la: " << x.TBC_so_doi_xung() << endl;
			break;
		case 10:
			x.sap_xep_giam_dan();
			cout << "Sap xep thanh cong!" << endl;
			cout << "Ma tran sau khi sap xep: " << endl;
			cout << x;
			break;
		case 11:
			x.sap_xep_tang_dan_tren_dong();
			cout << "Sap xep thanh cong!" << endl;;
			cout << "Ma tran sau khi sap xep: " << endl;
			cout << x;
			break;
		case 12:
			x.~MATRAN();
			cout << "Huy ma tran thanh cong!" << endl;
			break;
		case 0:
			cout << "Dang thoat chuong trinh!...";
			return 0;
		default:
			cout << "Khong hop le!" << endl;
		}
		cout << "Ban co muon tiep tuc khong?" << endl;
		cout << "1. CO" << endl;
		cout << "0.KHONG" << endl;
		cout << "Lua chon cua ban la: ";
		cin >> cont;
		while (cont != 1 && cont != 0)
		{
			cout << "Khong hop le! Vui long nhap lai!" << endl;
			cout << "Lua chon cua ban la: ";
			cin >> cont;
		}
		system("cls");
	} while (cont == 1);
}