#include<iostream>
using namespace std;
#define MAX 100

int a[MAX];

void nhap(int& n) {
    cout << "Nhap so phan tu: "; 
    cin >> n;
    cout << "Danh sach: ";
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
}

void xuat(int n) {
    for(int i=0; i<n; i++) {
        cout << a[i] << "  ";
    }
    cout << endl;
}

int find(int n, int x) {
    if(n<=0) {
        return -1;
    }
    for(int i=0; i<n; i++) {
        if(a[i] == x) {
            return i;
        }
    }
    return -1;
}

void insertFirst(int& n, int x) {
    int i=n;
    while(i>0) {
        a[i] = a[i-1];
        i--;
    }
    a[0] = x;
    n++;
}

void insertLast(int& n, int x) {
    a[n] = x;
    n++;
} 

void insertMiddle(int& n, int x, int pos) {
    if(pos<0 || pos>n) {
        cout << "Vi tri khong hop le!" << endl;
    } else {
        int i = n;
        while(i>pos) {
            a[i] = a[i-1];
            i--;
        }
        a[i] = x;
        n++;
    }
}

void deleteFirst(int& n) {
    for(int i=0; i<n-1; i++) {
        a[i] = a[i+1];
    }
    n--;
}

void deleteLast(int& n) {
    n--;
}

void deleteMiddle(int& n, int pos) {
    if(n<=0) {
        cout << "Danh sach rong!" << endl;
    } else {
        int i = pos;
        while(i<n) {
            a[i] = a[i+1];
            i++; 
        }
        n--;
    }
}

void findAndDelete(int& n, int x) {
    int tmp = find(n,x);
    if(tmp==-1) {
        cout << "Khong ton tai phan tu " << endl; 
    } else {
        deleteMiddle(n,tmp);
    }
}

int main() {
    int n;
    char ctn;
    nhap(n);
    do {
        cout << endl;
        cout << "========MENU========" << endl;
        cout << "0. Nhap danh sach" << endl;
        cout << "1. Duyet danh sach" << endl;
        cout << "2. Tim kiem " << endl;
        cout << "3. Chen dau DS" << endl;
        cout << "4. Chen cuoi DS" << endl;
        cout << "5. Chen vi tri bat ki" << endl;
        cout << "6. Xoa dau DS" << endl;
        cout << "7. Xoa cuoi DS" << endl;
        cout << "8. Xoa vi tri bat ki" << endl;
        cout << "9. Tim va xoa" << endl;
        cout << "====================" << endl;

        int choose;
        cout << "Lua chon: ";
        cin >> choose;

        switch(choose) {
            case 0: nhap(n);
            break;
            case 1: xuat(n);
            break;
            case 2: {
                int x;
                cout << "Nhap gia tri can tim: ";
                cin >> x;
                int result = find(n,x);
                if(result==-1) {
                    cout << "Khong tim thay" << endl;
                } else {
                    cout << "Gia tri " << x << " tim thay tai vi tri i=" << result << endl; 
                }
            } 
            break;
            case 3: {
                int x;
                cout << "Gia tri can chen: ";
                cin >> x;
                insertFirst(n,x);
                cout << "result: ";
                xuat(n);
            }
            break;
            case 4: {
                int x;
                cout << "Gia tri can chen: ";
                cin >> x;
                insertLast(n,x);
                cout << "result: ";
                xuat(n);
            }
            break;
            case 5: {
                int x,pos;
                cout << "Gia tri can chen: ";
                cin >> x;
                cout << "Vi tri can chen: ";
                cin >> pos;
                insertMiddle(n,x,pos);
                cout << "result: ";
                xuat(n);
            }
            break;
            case 6: {
                deleteFirst(n);
                cout << "result: ";
                xuat(n);
            }
            break;
            case 7: {
                deleteLast(n);
                cout << "result: ";
                xuat(n);
            }
            break;
            case 8: {
                int pos;
                cout << "Vi tri can xoa: ";
                cin >> pos;
                deleteMiddle(n,pos);
                cout << "result: ";
                xuat(n);
            }
            break;
            case 9: {
                int x;
                cout << "Nhap gia tri can tim va xoa: ";
                cin >> x;
                findAndDelete(n,x);
                cout << "result: ";
                xuat(n);
            }
            break;
        }
        cout << endl;
        cout << "Tiep tuc? (y/n) : ";
        cin >> ctn;
    } while(ctn!='n');
    return 0;
}