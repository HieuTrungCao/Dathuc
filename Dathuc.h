#pragma once
#include<iostream>
#include<cmath>

using namespace std;

class Dathuc {
private:
    int bac;
    int* a = new int[100];
public:
    Dathuc();

    ~Dathuc();

    int getBac();

    int* getHeso();

    void setBac(const int& b);

    friend istream& operator >>(istream& is, Dathuc& d);

    friend ostream& operator <<(ostream& os,const Dathuc& d);

    Dathuc& operator + (Dathuc& b);
    Dathuc& operator - (Dathuc& b);
    Dathuc& operator * (Dathuc& b);
};


void quyChuanDathuc(Dathuc &a);

double tinhGiaTriDaThuc(Dathuc& a, const double x);
