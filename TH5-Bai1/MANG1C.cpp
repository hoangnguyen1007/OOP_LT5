#include "MANG1C.h"

bool MANG1C::ktra_snt(int x)
{
	if (x < 2) return 0;
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0) return 0;
	}
	return 1;
}
bool MANG1C::ktra_scp(int x)
{
	int can = sqrt(x);
	if (can * can == x) return 1;
	else return 0;
}
bool MANG1C::ktra_sht(int x)
{
    int tong = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            tong += i;
            if (i != n / i) {
                tong += n / i;
            }
        }
    }
    if (tong - n == n) {
        return 1;
    }
    return 0;
}
bool MANG1C::ktra_sdx(int x)
{
    string s = to_string(x);
    int l = 0;
    int r = s.size() - 1;
    while (l < r)
    {
        if (s[l] != s[r]) return 0;
        l++;
        r--;
    }
    return 1;
}
MANG1C::~MANG1C() {};
MANG1C::MANG1C() {};
MANG1C::MANG1C(int n)
{
    this->n = n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
}
MANG1C::MANG1C(int n, int m)
{
    this->n = n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = m;
    }
}
MANG1C::MANG1C(const MANG1C* x)
{
    if (x->n <= 0)
    {
        a = NULL;
        this->n = 0;
    }
    this->n = x->n;
    this->a = new int[n];
    for (int i = 0; i < n; i++)
    {
        this->a[i] = x->a[i];
    }
}
MANG1C MANG1C::operator=(const MANG1C& x)
{
    if (x.n <= 0)
    {
        a = NULL;
        this->n = 0;
    }
    this->n = x.n;
    this->a = new int[n];
    for (int i = 0; i < n; i++)
    {
        this->a[i] = x.a[i];
    }
    return *this;
}
int MANG1C::getN() const
{
    return n;
}
int* MANG1C::getA() const
{
    return a;
}
void MANG1C::setN(int n)
{
    if (n <= 0) this->~MANG1C();
    if (a == NULL)
    {
        MANG1C t(n);
        *this = t;
    }
    else
    {
        MANG1C m(n);
        int min = this->n > n ? n : this->n;
        for (int i = 0; i < min; i++) m.a[i] = a[i];
        for (int i = min; i < n; i++) m.a[i] = a[i];
        this->~MANG1C();
        *this = m;
    }
}
void MANG1C::setA(MANG1C& m)
{
    *this = m;
}
void MANG1C::Nhap()
{
    cout << "Nhap so phan tu: ";
    cin >> n;
    while (cin.fail() || n < 0)
    {
        cin.clear();
        cin.ignore();
        cout << "Khong hop le! Vui long nhap lai!" << endl;
        cout << "Nhap so phan tu: ";
        cin >> n;
    }
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}
void MANG1C::Xuat() const
{
    if (a == NULL) cout << "Mang rong!" << endl;
    else
    {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
}
istream& operator>>(istream& is, MANG1C& x)
{
    x.Nhap();
    return is;
}
ostream& operator<<(ostream& os, const MANG1C& x)
{
    x.Xuat();
    return os;
}
void MANG1C::phatsinh()
{
    if (a != NULL) this->~MANG1C();
    cout << "Nhap so phan tu mang:";
    cin >> n;
    while (cin.fail() || n <= 0)
    {
        cout << "Khong hop le! Vui long nhap lai!" << endl;
        cout << "Nhap so phan tu mang:";
        cin >> n;
    }
    a = new int[n];
    int m1, m2;
    cout << "Nhap mien gia tri phat sinh: ";
    cin >> m1 >> m2;
    srand(time(NULL));
    for (int i = 0; i < n; i++) a[i] = m1 + rand() % (m1 - m2 + 1);
}
void MANG1C::LietKeSNT()
{
    bool co = false;
    bool* da_co = new bool[a[n - 1] + 1] {false};
    for (int i = 0; i < n; i++)
    {
        if (ktra_snt(a[i]) && !da_co[a[i]])
        {
            co = true;
            da_co[a[i]] = true;
            cout << a[i] << " ";
        }
    }
    cout << endl;
    if (!co) cout << "Khong tim thay SNT trong mang!" << endl;
}
int MANG1C::DemSCP()
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (ktra_scp(a[i])) dem++;
    }
    return dem;
}
long long MANG1C::TongSHT()
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (ktra_sht(a[i])) sum += a[i];
    }
    return sum;
}
double MANG1C::TBCSo_doi_xung()
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (ktra_sdx(a[i]))
        {
            sum += a[i];
            count++;
        }
    }
    return count > 0 ? sum / count : 0;
}
bool MANG1C::ktra_mang_le()
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0) return 0;
    }
    return 1;
}
void MANG1C::chan_min()
{
    int vtri = -1;
    int min = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0 && a[i] < min)
        {
            min = a[i];
            vtri = i;
        }
    }
    if (vtri == -1) cout << "Trong mang khong co phan tu chan nao!" << endl;
    else cout << "Phan tu chan nho nhat la: a[" << vtri << "] = " << min<<endl;
}
void MANG1C::sap_xep_tang_dan()
{
    sort(a, a + n);
}
void MANG1C::sap_xep_giam_dan()
{
    sort(a, a + n, greater<int>());
}
void MANG1C::xoa_phan_tu(int vt)
{
    if (vt < 0 || vt >= n) return;
    else
    {
        for (int i = vt; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        n--;
        if (n == 0)
        {
            a = NULL;
        }
    }
}
void MANG1C::cap_nhat_gia_tri(int vt, int gt)
{
    if (vt < 0 || vt >= n) return;
    a[vt] = gt;
}
int MANG1C::tim_kiem_tt(int gt)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == gt) return i;
    }
    return -1;
}
int MANG1C::tim_kiem_np(int gt)
{
    int res = -1;
    sap_xep_tang_dan();
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == gt)
        {
            res = m;
            break;
        }
        if (a[m] > gt) r = m - 1;
        if (a[m] < gt) l = m + 1;
    }
    return res;
}