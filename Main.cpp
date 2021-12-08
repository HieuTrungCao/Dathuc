#include"Dathuc.h"


void nhap(Dathuc* d, const int& n) {
    for (int i = 0; i < n; i++)
        cin >> d[i];
}

//sap xep tang dan ve bac
void sapxep(Dathuc* d, const int& n) {
   
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++)
            if (d[j].getBac() < d[j + 1].getBac()) {
                Dathuc dt = d[j];
                d[j] = d[j + 1];
                d[j + 1] = dt;
            }
    }
}

void in(Dathuc* d, const int& n) {
    for (int i = 0; i < n; i++)
        cout << d[i] << endl;
}

int main() {
    unsigned int n;
    cin >> n;

    Dathuc* d = new Dathuc[n];

    nhap(d, n);

    sapxep(d, n);

    in(d, n);

    for (int i = 0; i < n; i++)
        delete [] d[i].getHeso(); // giai phong bo nho cua mang he so

    delete[] d; // giai phong bo nho
    
	return 0;
}