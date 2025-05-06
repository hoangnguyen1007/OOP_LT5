#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
class MATRAN
{
private:
	int sd, sc;
	int** p;
	bool ktra_snt(int);
	bool ktra_scp(int);
	bool ktra_sht(int);
	bool ktra_sdx(int);
public:
	~MATRAN();
	MATRAN();
	MATRAN(int, int);
	MATRAN(const MATRAN&);
	MATRAN operator=(const MATRAN&);
	int getSD() const;
	int getSC() const;
	int **getP() const;
	void setSD(int);
	void setSC(int);
	void setP(const MATRAN&);
	void Nhap();
	void Xuat() const;
	friend istream& operator>>(istream&, MATRAN&);
	friend ostream& operator<<(ostream&, const MATRAN&);
	void phat_sinh();
	void liet_ke_SNT();
	int so_ptu_SCP();
	long long tong_SHT();
	double TBC_so_doi_xung();
	void sap_xep_giam_dan();
	void sap_xep_tang_dan_tren_dong();
};

