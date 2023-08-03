#include<iostream>
using namespace std;
#define MAX 100

int a[MAX];
int n = 0;

void push(int arr[], int& n, int x) {
    if(n==0) {
        arr[0]=x;
        n++;
    } else {
        int i=n-1;
        while(arr[i]>x) {
            arr[i+1] = arr[i];
            i--;
        }   
        arr[i+1] = x;
        n++;
    }
}

void xuat(int arr[],int l) {
    cout << "DS : ";
    for(int i=0; i<l; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int search(int x) {
    for(int i=0; i<n; i++) {
        if(a[i] == x) {
            return i;
        }
    }
    return -1;
}

int searchBinary_recursive(int x, int start, int end) {
    int mid = (start + end) / 2;
    if (start > end) return -1;
    if(x == a[mid]) {
        return mid;
    } else if(x > a[mid]) {
        searchBinary_recursive(x,mid+1,end);
    } 
    return searchBinary_recursive(x,start,mid-1);
}

int searchBinary(int x, int start, int end) {
    while(start < end) {
        int mid = (start + end) / 2;
        if(x == a[mid]) {
            return mid;
        } else if(x > a[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

void Delete(int pos) {
    int i = pos;
    while(i < n-1) {
        a[i] = a[i+1];
        i++;
    }
    n--;
}

void searchAndDelete(int x) {
    int index = search(x);
    if(index != -1) {
        Delete(index);
    } else {
        cout << "Khong tim thay phan tu!" << endl;
    }
}

void nhap(int p[],int& q) {
    cout << "Nhap so phan tu: ";
    cin >> q;
    cout << "Nhap mang: ";
    for(int i=0; i<q; i++) {
        cin >> p[i];
    }
}

void merge(int b[], int k, int c[], int m) {
    int array[MAX];
    int v = 0;
    nhap(b,k);
    nhap(c,m);
    for(int i=0; i<k; i++) {
        push(array,v,b[i]);
    }
    for(int i=0; i<m; i++) {
        push(array,v,c[i]);
    }
    xuat(array,v);
}

int main() {
    char ctn;
    do {
        cout << endl;
        cout << "==========MENU==========" << endl;
        cout << "1. Duyet DS" << endl;
        cout << "2. Them phan tu" << endl;
        cout << "3. Tim ( tuan tu )" << endl;
        cout << "4. Tim ( nhi phan )" << endl;
        cout << "5. Tim ( nhi phan - de qui )" << endl;
        cout << "6. Tim va xoa phan tu" << endl;
        cout << "7. Gop 2 DS" << endl;
        cout << "=========================" << endl;
        int choose;
        cout << "Lua chon: ";
        cin >> choose;

        switch(choose) {
            case 1: xuat(a,n);
            break;
            case 2: {
                int x;
                cout << "Nhap gia tri: ";
                cin >> x;
                push(a, n, x);
            }
            break;
            case 3: {
                int x;
                cout << "Gia tri can tim: ";
                cin >> x;
                int result = search(x);
                if(result != -1) {
                    cout << "Gia tri " << x << " ton tai o vi tri " << result << endl;
                } else {
                    cout << "Khong ton tai gia tri" << endl;
                }
            }
            break;
            case 4: {
                int x;
                cout << "Gia tri can tim: ";
                cin >> x;
                int result = searchBinary(x,0,n-1);
                if(result != -1) {
                    cout << "Gia tri " << x << " ton tai o vi tri " << result << endl;
                } else {
                    cout << "Khong ton tai gia tri" << endl;
                }
            }
            break;
            case 5: {
                int x;
                cout << "Gia tri can tim: ";
                cin >> x;
                int result = searchBinary_recursive(x,0,n-1);
                if(result != -1) {
                    cout << "Gia tri " << x << " ton tai o vi tri " << result << endl;
                } else {
                    cout << "Khong ton tai gia tri" << endl;
                }
            }
            break;
            case 6: {
                int x;
                cout << "Gia tri can xoa: ";
                cin >> x;
                searchAndDelete(x);
            }
            break;
            case 7: {
                int b[MAX], c[MAX];
                int m, k;
                merge(b,k,c,m);
            }
            break;
        }
    } while(ctn!='n');
    return 0;
} 