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
    for(int i=1; i<n; i++) {
        int x = a[i];
        int j = i-1;
        while(j>=0 && a[j]>x) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}

int main() {
    int a[MAX];
    int n;
    nhap(a,n); 
    sort(a,n);
    xuat(a,n);
    return 0;
}