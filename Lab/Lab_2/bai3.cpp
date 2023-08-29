#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct date {
    int ngay;
    int thang;
    int nam;
};

struct SinhVien {
    int maSv;
    string ten;
    string ho;
    date ngaySinh;
    int gioiTinh;
    double diemTb;
};

struct Node {
    SinhVien sv;
    Node* next;
};

Node* head = NULL;

int size() {
    int cnt = 0;
    Node* p = head;
    while(p!=NULL) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

int MSSV() {
    bool flags;
    int mssv;
    do {
        cout << "Ma so SV: ";
        cin >> mssv;
        Node* p = head;
        flags = false;
        while(p!=NULL) {
            if(p->sv.maSv == mssv) {
                flags = true;
                break;
            }
            p = p->next;
        }
    } while(flags == true);
    return mssv;
}

date Date() {
    date day;
    int d,m,y;
    do {
        cout << "Ngay sinh: ";
        cin >> d;
    } while(d<=0 || d>31);
    do {
        cout << "Thang sinh: ";
        cin >> m;
    } while(m<=0 || m>12);
    do {
        cout << "Nam sinh: ";
        cin >> y;
    } while(y<=0);
    day.ngay = d;
    day.thang = m;
    day.nam = y;
    return day;
}

SinhVien nhapSV() {
    SinhVien sv;
    sv.maSv = MSSV();
    cout << "Ho: ";
    cin.ignore();
    getline(cin,sv.ho);
    cout << "Ten: ";
    getline(cin,sv.ten);
    sv.ngaySinh = Date();
    do {
        cout << "Gioi tinh ( 1.Nam - 0.Nu ): ";
        cin >> sv.gioiTinh; 
    } while(sv.gioiTinh!=1 && sv.gioiTinh!=0);
    do {
        cout << "Diem TB: ";
        cin >> sv.diemTb;
    } while(sv.diemTb<0 || sv.diemTb>10);
    return sv;
}

void ghiFile() {
    int n = size();
    ofstream ghi;
    ghi.open("data.txt");
    ghi << n << endl;
    Node* p = head;
    while(p!=NULL) {
        string gioitinh = p->sv.gioiTinh ? "Nam" : "Nu";
        ghi << p->sv.maSv << "#" << p->sv.ho << "#" << p->sv.ten << "#" << p->sv.ngaySinh.ngay << "/" << p->sv.ngaySinh.thang << "/" << p->sv.ngaySinh.nam << "/"  << "#" << gioitinh << "#" << p->sv.diemTb << "#" << endl;
        p=p->next;
    }
}

void nhapDSSV(int &n) {
    cout << "So luong sv: ";
    cin >> n;
    for(int i=0; i<n; i++) {
        Node* p = new Node;
        p->sv = nhapSV();
        p->next = head;
        head = p;
    }
    ghiFile();
}

int main() {
    int n;
    nhapDSSV(n);
    return 0;
}