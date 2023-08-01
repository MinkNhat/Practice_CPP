#include<iostream>
#define MAX 100
using namespace std;

void nhap(int a[], int &n) {
    cout << "Nhap so phan tu: ";
    cin >> n;
    for(int i=0; i<n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i]; 
    }
}

void xuat(int a[], int n) {
    for(int i=0; i<n; i++) {
        cout << a[i] << "  ";
    }
    cout << endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void sort(int a[],int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=n-1; j>i; j--) {
            if(a[j] < a[j-1]) {
                swap(a[j],a[j-1]);
            }
        }
    }
}

void sort_reverse(int a[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=n-1; j>i; j--) {
            if(a[j] > a[j-1]) {
                swap(a[j],a[j-1]);
            }
        }
    }
}

int main() {
    int a[MAX];
    int n;
    char ctn;
    do {
        nhap(a,n); 
        int choose;
        cout << "1. Sap xep tu nho -> lon" << endl;
        cout << "2. Sap xep tu lon -> nho" << endl;
        cout << "Lua chon: ";
        cin >> choose;
        if(choose==1) {
            sort(a,n);
            xuat(a,n);
        } else if(choose==2) {
            sort_reverse(a,n);
            xuat(a,n);
        } else {
            cout << "Lua chon khong hop le!" << endl;
        }
        cout << "Tiep tuc? (y/n) : ";
        cin >> ctn;
    } while(ctn!='n');
    return 0;
} 