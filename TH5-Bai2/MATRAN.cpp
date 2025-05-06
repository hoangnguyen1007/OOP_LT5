#include "MATRAN.h"

bool MATRAN::ktra_snt(int x)
{
    if (x < 2) return 0;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0) return 0;
    }
    return 1;
}
bool MATRAN::ktra_scp(int x)
{
    int can = sqrt(x);
    if (can * can == x) return 1;
    else return 0;
}
bool MATRAN::ktra_sht(int x)
{
    int tong = 0;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            tong += i;
            if (i != x / i) {
                tong += x / i;
            }
        }
    }
    if (tong - x == x) {
        return 1;
    }
    return 0;
}
bool MATRAN::ktra_sdx(int x)
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
MATRAN::~MATRAN()
{
    if (p != NULL)
    {
        for (int i = 0; i < sd; i++)
        {
            delete[] p[i];
        }
        delete[] p;
        p = nullptr;
    }
}
MATRAN::MATRAN() {};
MATRAN::MATRAN(int sd, int sc)
{
    p = new int*[sd];
    for (int i = 0; i < sd; i++)
    {
        p[i] = new int[sc];
    }
    for (int i = 0; i < sd; i++)
    {
        for (int j = 0; j < sc; j++)
        {
            p[i][j] = 0;
        }
    }
}
MATRAN::MATRAN(const MATRAN& x)
{
    this->sd = x.sd;
    this->sc = x.sc;
    p = new int*[sd];
    for (int i = 0; i < sd; i++)
    {
        p[i] = new int[sc];
    }
    for (int i = 0; i < sd; i++)
    {
        for (int j = 0; j < sc; j++)
        {
            p[i][j] = x.p[i][j];
        }
    }
}
MATRAN MATRAN::operator=(const MATRAN& x)
{
    this->sd = x.sd;
    this->sc = x.sc;
    p = new int* [sd];
    for (int i = 0; i < sd; i++)
    {
        p[i] = new int[sc];
    }
    for (int i = 0; i < sd; i++)
    {
        for (int j = 0; j < sc; j++)
        {
            p[i][j] = x.p[i][j];
        }
    }
    return *this;
}
int MATRAN::getSD() const
{
    return sd;
}
int MATRAN::getSC() const
{
    return sc;
}
int** MATRAN::getP() const
{
    return p;
}
void MATRAN::setSD(int sdm)
{
    if (sd <= 0) this->~MATRAN();
    MATRAN t(sdm, sc);
    int min = sdm < sd ? sdm : sd;
    for (int i = 0; i < min; i++)
    {
        for (int j = 0; j < sc; j++)
        {
            t.p[i][j] = p[i][j];
        }
    }
    for (int i = min; i < sd; i++)
    {
        for (int j = 0; j < sc; j++)
        {
            t.p[i][j] = p[i][j];
        }
    }
}
void MATRAN::setSC(int scm)
{
    if (sc <= 0) this->~MATRAN();
    MATRAN t(sd, scm);
    int min = scm < sc ? scm : sc;
    for (int i = 0; i < sd; i++)
    {
        for (int j = 0; j < min; j++)
        {
            t.p[i][j] = p[i][j];
        }
    }
    for (int i = 0; i < sd; i++)
    {
        for (int j = min; j < sc; j++)
        {
            t.p[i][j] = p[i][j];
        }
    }
}
void MATRAN::setP(const MATRAN& x)
{
    *this = x;
}
void MATRAN::Nhap()
{
    cout << "Nhap so dong: ";
    cin >> sd;
    while (cin.fail() || sd < 0)
    {
        cin.clear();
        cin.ignore();
        cout << "Khong hop le! Vui long nhap lai!" << endl;
        cout << "Nhap so dong: ";
        cin >> sd;
    }
    cout << "Nhap so cot: ";
    cin >> sc;
    while (cin.fail() || sd < 0)
    {
        cin.clear();
        cin.ignore();
        cout << "Khong hop le! Vui long nhap lai!" << endl;
        cout << "Nhap so cot: ";
        cin >> sc;
    }
    p = new int* [sd];
    for (int i = 0; i < sd; i++)
    {
        p[i] = new int[sc];
    }
    for (int i = 0; i < sd; i++)
    {
        for (int j = 0; j < sc; j++)
        {
            cout << "p[" << i << "][" << j << "]= ";
            cin >> p[i][j];
            while (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Khong hop le! Vui long nhap lai!" << endl;
                cout << "p[" << i << "][" << j << "]= ";
                cin >> p[i][j];
            }
        }
    }
}
void MATRAN::Xuat() const
{
    if (p == NULL)
    {
        cout << "Ma tran rong!" << endl;
        return;
    }
    for (int i = 0; i < sd; i++)
    {
        for (int j = 0; j < sc; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}
istream& operator>>(istream& is, MATRAN& x)
{
    x.Nhap();
    return is;
}
ostream& operator<<(ostream& os, const MATRAN& x)
{
    x.Xuat();
    return os;
}
void MATRAN::phat_sinh()
{
    if (p != NULL) this->~MATRAN();
    cout << "Nhap so dong: ";
    cin >> sd;
    while (cin.fail() || sd < 0)
    {
        cin.clear();
        cin.ignore();
        cout << "Khong hop le! Vui long nhap lai!" << endl;
        cout << "Nhap so dong: ";
        cin >> sd;
    }
    cout << "Nhap so cot: ";
    cin >> sc;
    while (cin.fail() || sd < 0)
    {
        cin.clear();
        cin.ignore();
        cout << "Khong hop le! Vui long nhap lai!" << endl;
        cout << "Nhap so cot: ";
        cin >> sc;
    }
    p = new int* [sd];
    for (int i = 0; i < sd; i++)
    {
        p[i] = new int[sc];
    }
    cout << "Nhap mien gia tri phat sinh:";
    int m1, m2;
    cin >> m1 >> m2;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Khong hop le! Vui long nhap lai!" << endl;
        cout << "Nhap mien gia tri phat sinh:";
        cin >> m1 >> m2;
    }
    srand(time(NULL));
    for (int i = 0; i < sd; i++)
    {
        for (int j = 0; j < sc; j++)
        {
            p[i][j] = m1 + rand() % (m1 - m2 + 1);
        }
    }
}
void MATRAN::liet_ke_SNT()
{
    bool co = false;
    bool* da_co = new bool[p[sd - 1][sc - 1] + 1] {false};
    for (int i = 0; i < sd; i++)
    {
        for (int j = 0; j < sc; j++)
        {
            if (ktra_snt(p[i][j]) && !da_co[p[i][j]])
            {
                co = true;
                da_co[p[i][j]] = true;
                cout << p[i][j] << " ";
            }
        }
    }
    cout << endl;
    if (!co) cout << "Khong co so nguyen to nao trong mang!" << endl;
}
int MATRAN::so_ptu_SCP()
{
    int dem = 0;
    for (int i = 0; i < sd; i++)
    {
        for (int j = 0; j < sc; j++)
        {
            if (ktra_scp(p[i][j])) dem++;
        }
    }
    return dem;
}
long long MATRAN::tong_SHT()
{
    long long sum = 0;
    for (int i = 0; i < sd; i++)
    {
        for (int j = 0; j < sc; j++)
        {
            if (ktra_sht(p[i][j])) sum += p[i][j];
        }
    }
    return sum;
}
double MATRAN::TBC_so_doi_xung()
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < sd; i++)
    {
        for (int j = 0; j < sc; j++)
        {
            if (ktra_sdx(p[i][j]))
            {
                sum += p[i][j];
                count++;
            }
        }
    }
    return count > 0 ? sum / count : 0;
}
void MATRAN::sap_xep_giam_dan()
{
    int total = sd * sc;
    int* tmp = new int[total];
    int k = 0;
    for (int i = 0; i < sd; i++)
    {
        for (int j = 0; j < sc; j++)
        {
            tmp[k++] = p[i][j];
        }
    }
    sort(tmp, tmp + total, greater<int>());
    k = 0;
    for (int i = 0; i < sd; i++)
    {
        for (int j = 0; j < sc; j++)
        {
            p[i][j] = tmp[k++];
        }
    }
    delete[] tmp;
    tmp = NULL;
}
void MATRAN::sap_xep_tang_dan_tren_dong()
{
    for (int i = 0; i < sd; i++)
    {
        sort(p[i], p[i] + sc);
    }
}