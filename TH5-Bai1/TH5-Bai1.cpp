#include "MANG1C.h"

int main()
{
	MANG1C a;
	int cont;
	do
	{
		cout << "==============CHUONG TRINH===============" << endl;
		cout << "1. Nhap mang" << endl;
		cout << "2. Phat sinh mang" << endl;
		cout << "3. Xuat mang" << endl;
		cout << "4. Cap nhat phan tu bang setN(n)" << endl;
		cout << "5. Liet ke cac phan tu la SNT" << endl;
		cout << "6. Dem so luong phan tu la so chinh phuong" << endl;
		cout << "7. Tinh tong cac gia tri la SHT" << endl;
		cout << "8. Tinh trung binh cong cac phan tu la SDX" << endl;
		cout << "9. Kiem tra mang toan phan tu le" << endl;
		cout << "10. Tim phan tu chan be nhat" << endl;
		cout << "11. Sap xep mang tang dan" << endl;
		cout << "12. Xoa phan tu tai mot vi tri" << endl;
		cout << "13. Cap nhat gia tri tai mot vi tri" << endl;
		cout << "14. Tim kiem tuyen tinh" << endl;
		cout << "15. Tim kiem nhi phan" << endl;
		cout << "16. Xoa mang" << endl;
		cout << "0. Thoat chuong trinh!" << endl;
		cout << "===========================================" << endl;
		cout << "Lua chon cua ban la: ";
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
			cin >> a;
			break;
		case 2:
			a.phatsinh();
			break;
		case 3:
			cout << a;
			break;
		case 4:
			int k;
			cout << "Nhap so phan tu ban muon cap nhat: ";
			cin >> k;
			a.setN(k);
			cout << "Mang sau khi cap nhat la: " << a;
			break;
		case 5:
			a.LietKeSNT();
			break;
		case 6:
			cout << "So phan tu la so chinh phuong trong mang la " << a.DemSCP() << " phan tu" << endl;
			break;
		case 7:
			cout << "Tong cac phan tu la so hoan thien la: " << a.TongSHT()<<endl;
			break;
		case 8:
			cout << "Trung binh cac so doi xung trong mang la: " << a.TBCSo_doi_xung()<<endl;
			break;
		case 9:
			if (a.ktra_mang_le()) cout << "Mang toan phan tu le!" << endl;
			else cout << "Khong phai mang toan phan tu le!" << endl;
			break;
		case 10:
			a.chan_min();
			break;
		case 11:
			a.sap_xep_tang_dan();
			cout << "Mang sau khi sap xep: " << a;
			break;
		case 12:
			cout << "Nhap vi tri phan tu ban muon xoa: ";
			int l;
			cin >> l;
			a.xoa_phan_tu(l);
			cout << "Mang sau khi xoa phan tu tai vi tri " << l << ": " << a;
			break;
		case 13:
			cout << "Nhap vi tri ban muon cap nhat: ";
			int m;
			cin >> m;
			cout << "Nhap gia tri ban muon cap nhat: ";
			int n;
			cin >> n;
			a.cap_nhat_gia_tri(m, n);
			cout << "Mang sau khi cap nhat: " << a;
			break;
		case 14:
			cout << "Nhap phan tu ban muon tim kiem: ";
			int x;
			cin >> x;
			if (a.tim_kiem_tt(x) != -1) cout << "Phan tu x " << " nam tai vi tri " << a.tim_kiem_tt(x) << endl;
			else cout << "Khong ton tai phan tu " << x << " trong mang!" << endl;
			break;
		case 15:
			cout << "Nhap phan tu ban muon tim kiem: ";
			int y;
			cin >> y;
			if (a.tim_kiem_np(y) != -1) cout << "Phan tu x " << " nam tai vi tri " << a.tim_kiem_tt(x) << endl;
			else cout << "Khong ton tai phan tu " << y << " trong mang!" << endl;
			break;
		case 16:
			a.~MANG1C();
			cout << "Da xoa mang!" << endl;
			break;
		case 0:
			cout << "Dang thoat chuong trinh!...";
			return 0;
		default:
			cout << "Lua chon khong hop le!";
		}
		cout << "Ban muon tiep tuc khong?" << endl;
		cout << "1. Co" << endl;
		cout << "2. Khong" << endl;
		cout << "Lua chon cua ban la: ";
		cin >> cont;
		while (cont != 0 && cont != 1)
		{
			cout << "Vui long chon dung!" << endl;
			cout << "Ban muon tiep tuc khong?" << endl;
			cout << "1. Co" << endl;
			cout << "0. Khong" << endl;
			cout << "Lua chon cua ban la: ";
			cin >> cont;
		}
		system("cls");
	}while (cont == 1);
	cout << "Dang thoat chuong trinh!....";
	return 0;
}