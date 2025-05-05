#pragma once
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;
class MANG1C
{
private:
	int n;
	int* a;
	bool ktra_snt(int);
	bool ktra_scp(int);
	bool ktra_sht(int);
	bool ktra_sdx(int);
public:
	~MANG1C();
	MANG1C();
	MANG1C(int);
	MANG1C(int, int);
	MANG1C(const MANG1C* x);
	MANG1C operator=(const MANG1C&);
	int getN() const;
	int *getA() const;
	void setN(int n);
	void setA(MANG1C&);
	void Nhap();
	void Xuat() const;
	friend istream& operator>>(istream&, MANG1C&);
	friend ostream& operator<<(ostream&, const MANG1C&);
	void phatsinh();
	void LietKeSNT();
	int DemSCP();
	long long TongSHT();
	double TBCSo_doi_xung();
	bool ktra_mang_le();
	void chan_min();
	void sap_xep_tang_dan();
	void sap_xep_giam_dan();
	void xoa_phan_tu(int vt);
	void cap_nhat_gia_tri(int gt, int vt);
	int tim_kiem_tt(int gt);
	int tim_kiem_np(int gt);
};

