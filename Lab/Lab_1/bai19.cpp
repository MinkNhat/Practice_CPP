#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct SinhVien {
    string maSV;
    string hoTen;
    int namSinh;
    string diaChi;
    bool gioiTinh;
    double diemTB;
};

struct Node {
    SinhVien sv;
    Node* next;
};

Node* head = NULL;


int size() {
    int count = 0;
    Node* p = head;
    while(p!=NULL) {
        count++;
        p = p->next;
    }
    return count;
}

Node* nhap1SV() {
    Node* p = new Node;
    cout << "Nhap ma SV: ";
    cin >> p->sv.maSV;
    cout << "Nhap ho va ten: ";
    cin.ignore();
    getline(cin,p->sv.hoTen);
    cout << "Nhap nam sinh: ";
    cin >> p->sv.namSinh;
    cout << "Nhap dia chi: ";
    cin.ignore();
    getline(cin,p->sv.diaChi);
    cout << "Gioi tinh (1.Nam - 0.Nu): ";
    cin >> p->sv.gioiTinh;
    cout << "Diem TB: ";
    cin >> p->sv.diemTB;
    cout << endl;
    return p;
}

void nhapDSSV(int &n) {
    cout << "So luong SV: ";
    cin >> n;
    for(int i=0; i<n; i++) {
        Node* sv = nhap1SV();
        sv->next = head;
        head = sv;
    }
}

void xuat1SV(Node* p) {
    cout << "Ma SV: " << p->sv.maSV << endl;
    cout << "Ten: " << p->sv.hoTen << endl;
    cout << "Nam sinh: " << p->sv.namSinh << endl;
    cout << "Dia chi: " << p->sv.diaChi << endl;
    string gt = (p->sv.gioiTinh) ? "Nam" : "Nu";
    cout << "Gioi tinh: " << gt << endl;
    cout << "Diem TB: " << p->sv.diemTB << endl << endl;
}

void xuatDSSV() {
    Node* p = head;
    while(p!=NULL) {
        xuat1SV(p);
        p = p->next;
    }
}

void docFile(int &n) {
    ifstream inp;
    inp.open("data.txt");
    inp >> n;
    for(int i=0; i<n; i++) {
        Node* p = new Node;
        inp.ignore();
        getline(inp,p->sv.maSV,'#');
        getline(inp,p->sv.hoTen,'#');
        inp >> p->sv.namSinh;
        inp.ignore();
        getline(inp,p->sv.diaChi,'#');
        inp >> p->sv.gioiTinh;
        inp.ignore();
        inp >> p->sv.diemTB;

        p->next = head;
        head = p;
    }
}

void ghiFile() {
    ofstream outp;
    outp.open("data.txt");
    int n = size();
    outp << n << endl;
    Node* p = head;
    while(p!=NULL) {
        outp << p->sv.maSV << "#" << p->sv.hoTen << "#" << p->sv.namSinh << "#" << p->sv.diaChi << "#" << p->sv.gioiTinh << "#" << p->sv.diemTB << "#" << endl;
        p = p->next;
    }
}

void filter() {
    double key;
    cout << "Loc diem TB tren: ";
    cin >> key;
    cout << "Ket qua loc: " << endl;
    Node* p = head;
    while(p!=NULL) {
        if(p->sv.diemTB > key) {
            xuat1SV(p);
        }
        p = p->next;
    }
}

void themSV() {
    int pos;
    int n = size();
    cout << "Nhap vi tri: ";
    cin >> pos;
    if(pos<0 || pos>n) {
        cout << "Vi tri khong hop le" << endl;
    } else {
        Node* sv = nhap1SV();
        if(pos==0 || n==0) {
            sv->next = head;
            head = sv;
        } else if(pos==n) {
            Node* p = head;
            while(p->next != NULL) {
                p = p->next;
            }
            p->next = sv;
        } else {
            Node* p = head;
            for(int i=0; i<pos-1; i++) {
                p = p->next;
            }
            sv->next = p->next;
            p->next = sv;
        }
        ghiFile();
    }
}

void xoaSV() {
    int pos;
    int n = size();
    cout << "Vi tri can xoa: ";
    cin >> pos;
    if(pos<0 || pos>n-1) {
        cout << "Vi tri khong hop le" << endl;
    } else {
        if(pos==0) {
            Node* p = head;
            head = head->next;
            delete p;
        } else if(pos==n-1) {
            Node* p = head;
            while(p->next->next != NULL) {
                p = p->next;
            }
            Node* q = p->next;
            p->next = NULL;
            delete q;
        } else {
            Node* p = head;
            for(int i=0; i<pos-1; i++) {
                p = p->next;
            }
            Node* q = p->next;
            p->next = q->next;
            delete q;
        }
        ghiFile();
    }
}

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

void sapxep() {
    for(Node* p=head; p->next!=NULL; p=p->next) {
        for(Node* q=p->next; q!=NULL; q=q->next) {
            if(p->sv.diemTB > q->sv.diemTB) {
                swap(p->sv.diemTB, q->sv.diemTB);
            }
        }
    }
    cout << "Ket qua: " << endl << endl;
    xuatDSSV();
}

int main() {
    string stop;
    int n;
    do {
        cout << endl;
        cout << "========MENU=======" << endl;
        cout << "1. Nhap danh sach SV" << endl;
        cout << "2. Doc du lieu tu file" << endl;
        cout << "3. Xuat danh sach SV" << endl;
        cout << "4. Loc" << endl;
        cout << "5. Them 1 SV vao vi tri bat ki" << endl;
        cout << "6. Xoa 1 SV o vi tri bat ki" << endl;
        cout << "7. Sap xep" << endl;
        cout << "8. Ghi danh sach" << endl;
        cout << "====================" << endl << endl;

        int choose;
        cout << "Lua chon: ";
        cin >> choose;
        switch(choose) {
            case 1: {
                nhapDSSV(n);
            }
            break;

            case 2: {
                docFile(n);
            }
            break;

            case 3: {
                xuatDSSV();
            }
            break;

            case 4: {
                filter();
            }
            break;

            case 5: {
                themSV();
            }
            break;

            case 6: {
                xoaSV();
            }
            break;

            case 7: {
                sapxep();
            }
            break;
        }
        
        cout << "Dung? (y/n): ";
        cin >> stop;
    } while(stop!="y");
    return 0;
}