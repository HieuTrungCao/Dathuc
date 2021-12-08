#include"Dathuc.h"

Dathuc::Dathuc() {
    this->bac = 0;
}

Dathuc::~Dathuc() {
    //delete[]a; // giai phong bo nho khi chay het chuong trinh
    cout << "Da xoa\n";
}

int Dathuc::getBac() {
    return bac;
}

int* Dathuc::getHeso() {
    return a;
}

void Dathuc::setBac(const int& b) {
    this->bac = b;
}

//nap chong toan tu nhap
istream& operator >> (istream& is, Dathuc& d) { // ham nhap da thuc
    cin >> d.bac;

    for (int i = 0; i <= d.bac; i++)
        cin >> d.a[i];

    return is;
}

// nap chrong toan tu in
ostream& operator <<(ostream& os, const Dathuc& d) {
    for (int i = d.bac; i >= 1; i--)
        cout << d.a[i] << "*x^" << i << " + ";
    cout << d.a[0];

    return os;
}

Dathuc& Dathuc::operator + (Dathuc& b) {
    int b_a = bac;
    int b_b = b.getBac();

    Dathuc c;

    int* heso_b = b.getHeso();
    int* heso_c = c.getHeso();

    if (b_a > b_b) { // th bac cua a lon hon bac cua b
        c.setBac(b_a);

        int i = b_a;
        // he so cua x co so mu lon hon bac cua b trong c 
        //thi bang he so cua a tuong ung voi so mu

        while (i > b_b) {
            heso_c[i] = a[i];
            i--;
        }

        // cac he so con lai trong c thi bang tong cac he so trong a va b voi so mu tuong ung
        while (i >= 0) {
            heso_c[i] = a[i] + heso_b[i];
            i--;
        }
    }
    else {  // th bac cua b lon hon bac cua a
        c.setBac(b_b);

        int i = b_b;
        // he so cua x co so mu lon hon bac cua a trong c 
        //thi bang he so cua b tuong ung voi so mu

        while (i > b_a) {
            heso_c[i] = heso_b[i];
            i--;
        }

        // cac he so con lai trong c thi bang tong cac he so trong a va b voi so mu tuong ung
        while (i >= 0) {
            heso_c[i] = a[i] + heso_b[i];
            i--;
        }
    }
    return c;
}

Dathuc& Dathuc::operator - (Dathuc& b) {
    int b_a = bac;
    int b_b = b.getBac();

    Dathuc c;

    int* heso_b = b.getHeso();
    int* heso_c = c.getHeso();

    if (b_a > b_b) { // th bac cua a lon hon bac cua b
        c.setBac(b_a);

        int i = b_a;

        // he so cua x co so mu lon hon bac cua b trong c 
        //thi bang he so cua a tuong ung voi so mu

        while (i > b_b) {
            heso_c[i] = a[i];
            i--;
        }
        // cac he so con lai trong c thi bang hieu cac he so trong a va b voi so mu tuong ung
        while (i >= 0) {
            heso_c[i] = a[i] - heso_b[i];
            i--;
        }
    }
    else { // th bac cua a lon hon bac cua b
        c.setBac(b_b);

        int i = b_b;

        // he so cua x co so mu lon hon bac cua a trong c 
        //thi bang so doi cua he so cua b tuong ung voi so mu

        while (i > b_a) {
            heso_c[i] = -heso_b[i];
            i--;
        }

        // cac he so con lai trong c thi bang hieu cac he so trong a va b voi so mu tuong ung

        while (i >= 0) {
            heso_c[i] = heso_b[i] - a[i];
            i--;
        }
    }

    return c;
}

Dathuc& Dathuc::operator * (Dathuc& b) {
    int b_a = bac;
    int b_b = b.getBac();

    Dathuc c;

    int* heso_b = b.getHeso();
    int* heso_c = c.getHeso();

    int b_c = b_a + b_b;

    c.setBac(b_c);

    for (int i = 0; i <= b_c; i++) {

        int result = 0; // tinh he so 

        for (int j_a = 0; j_a <= i; j_a++) {

            if(j_a <= b_a && (i - j_a) <= b_b)
                result += a[j_a] * heso_b[i - j_a];
        }

        heso_c[i] = result;
    }
    return c;
}

void quyChuanDathuc(Dathuc &a) {
    int b = a.getBac();
    int* heso = a.getHeso();

    while (heso[b] == 0) {
        b--;
        a.setBac(b);
    }
}

double tinhGiaTriDaThuc(Dathuc& d, const double x) {
    double result = 0;
    
    int b = d.getBac();
    int* heso_d = d.getHeso();

    for (int i = b; i >= 0; i--)
        result += heso_d[i] * pow(x, i); //tinh bieu thuc a[i]*a^i

    return result;
}