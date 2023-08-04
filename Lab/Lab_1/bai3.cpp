#include<iostream>
using namespace std;
#define MAX 1000

struct DaThuc {
    int bac;
    float dt[MAX];
};

void nhap(DaThuc& s) {
    cout << "Bac cua da thuc? : ";
    cin >> s.bac;
    for(int i=s.bac; i>=0; i--) {
        cout << "He so x^" << i << " = ";
        cin >> s.dt[i];
    }
}

void xuat(DaThuc s) {
    if(s.dt[s.bac]!=0) cout << s.dt[s.bac] << ".x^" << s.bac;
    for(int i=s.bac-1; i>1; i--) {
        if(s.dt[i]!=0) {
            if(s.dt[i]>0) {
                cout << " + " << s.dt[i] << ".x^" << i;
            } else {
                cout << " - " << -s.dt[i] << ".x^" << i;
            }
        }
    }
    if(s.dt[1]!=0) {
        if(s.dt[1]>0) {
            cout << " + " << s.dt[1] << ".x";
        } else {
            cout << " - " << -s.dt[1] << ".x";
        }
    }
    if(s.dt[0]!=0) {
        if(s.dt[0]>0) {
            cout << " + " << s.dt[0];
        } else {
            cout << " - " << -s.dt[0];
        }
    }
    cout << endl;
}

DaThuc cong(DaThuc a, DaThuc b) {
    DaThuc c;
    if(a.bac > b.bac) {
        c.bac = a.bac;
        for(int i=0; i<=b.bac; i++) {
            c.dt[i] = a.dt[i] + b.dt[i];
        }
        for(int i=b.bac+1; i<=a.bac; i++) {
            c.dt[i] = a.dt[i];
        }
    } else {
        c.bac = b.bac;
        for(int i=0; i<=a.bac; i++) {
            c.dt[i] = a.dt[i] + b.dt[i];
        }
        for(int i=a.bac+1; i<=b.bac; i++) {
            c.dt[i] = b.dt[i];
        }
    }
    return c;
}

DaThuc tru(DaThuc a, DaThuc b) {
    DaThuc c;
    int max = a.bac > b.bac ? a.bac : b.bac;
    c.bac = max;
    for(int i=0; i<=max; i++) {
        int hesoA = (a.bac >= i) ? a.dt[i] : 0;
        int hesoB = (b.bac >= i) ? b.dt[i] : 0;
        c.dt[i] = hesoA - hesoB;
    }
    // chuẩn hoá bậc ( loại bỏ các bậc có hệ số bằng 0 ở đằng trước )
    while(c.bac>0 && c.dt[c.bac]==0) {
        c.bac--;
    }
    return c;
}

DaThuc nhan(DaThuc a, DaThuc b) {
    DaThuc c;
    c.bac = a.bac + b.bac;
    for(int i=0; i<=a.bac; i++) {
        for(int j=0; j<=b.bac; j++) {
            c.dt[i+j] += a.dt[i]*b.dt[j];
        }
    }
    return c;
}


DaThuc chia(DaThuc a, DaThuc b, DaThuc& du) {
    DaThuc kq;
    kq.bac = a.bac - b.bac;
    du = a;
    while(du.bac >= b.bac) {
        // tính số mũ và hệ số
        int mu = du.bac - b.bac;
        float heso = du.dt[du.bac] / b.dt[b.bac];
        // gán kết quả
        kq.dt[mu] = heso;
        // trừ số bị chia cho số chia * đơn thức thương mới
        for(int i=0; i<=b.bac; i++) {
            int temp_mu = mu + i; // mũ của phần số chia * đơn thức thương mới
            int temp_heso = heso * b.dt[i]; // hệ số của phần số chia * đơn thức thương mới
            du.dt[temp_mu] -= temp_heso; // thực hiện trừ
        }
        // chuẩn hoá bậc
        while(du.bac>0 && du.dt[du.bac]==0) {
            du.bac--;
        }
    }
    return kq;
}

int main() {
    DaThuc dt1, dt2, kq;
    do {
        nhap(dt1);
        nhap(dt2);
        cout << endl;
        cout << "======MENU======" << endl;
        cout << "1. Cong 2 da thuc" << endl;
        cout << "2. Tru 2 da thuc" << endl;
        cout << "3. Nhan 2 da thuc" << endl;
        cout << "4. Chia 2 da thuc" << endl;
        cout << "=================" << endl;
        int choose;
        cout << "Lua chon: ";
        cin >> choose;
        switch(choose) {
            case 1: {
                kq = cong(dt1, dt2);
                xuat(kq);
            }
            break;
            case 2: {
                kq = tru(dt1, dt2);
                xuat(kq);
            }
            break;
            case 3: {
                kq = nhan(dt1, dt2);
                xuat(kq);
            }
            break;
            case 4: {
                DaThuc du;
                kq = chia(dt1, dt2, du);
                cout << "Kq = ";
                xuat(kq);
                cout << "du = ";
                xuat(du);
            }
            break;
            default: cout << "Lua chon kh hop le!" << endl;
        }
    } while(1);
    return 0;
}