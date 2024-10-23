#include<iostream>
#define MAX 100
using namespace std;

void init(int a[], int &top) {
    top = -1;
}

void print(int a[], int top) {
    for(int i=0; i<=top; i++) {
        cout << a[i] << "  ";
    }
}

bool isFull(int a[], int top) {
    if(top==MAX-1) return true;
    return false;
}

bool isEmpty(int a[], int top) {
    if(top==-1) return true;
    return false;
}

int push(int a[], int &top, int x) {
    if(top<MAX-1) {
        a[++top] = x;
        return 1;
    } else {
        cout << "Stack day!" << endl;
        return 0;
    }
}

int pop(int a[], int &top, int &x) {
    if(top!=-1) {
        x = a[top--];
        return 1;
    } else {
        cout << "Stack rong!" << endl;
        return 0;
    }
}

int main() {
    int a[MAX];
    int top;  // đỉnh stack
    init(a,top);
    
    while(1) {
        cout << endl;
        cout << "==========STACK=========" << endl;
        cout << "0.Duyet stack" << endl;
        cout << "1.Kiem tra stack day?" << endl;
        cout << "2.Kiem tra stack rong?" << endl;
        cout << "3.Them 1 phan tu vao stack" << endl;
        cout << "4.Lay 1 phan tu ra khoi stack" << endl;
        cout << "==========================" << endl;

        int choose;
        cout << "Nhap lua chon: ";
        cin >> choose;

        if(choose==0) {
            print(a,top);
        } else if(choose==1) {
            bool result = isFull(a,top);
            if(result) {
                cout << "Stack da day" << endl;
            } else {
                cout << "Stack chua day" << endl;
            }
        } else if(choose==2) {
            bool result = isEmpty(a,top);
            if(result) {
                cout << "Stack trong" << endl;
            } else {
                cout << "Stack chua trong" << endl;
            }
        } else if(choose==3) {
            int x;
            cout << "Nhap gia tri can them: ";
            cin >> x;
            int result = push(a,top,x);
            if(result) {
                cout << "Them thanh cong" << endl;
            }
        } else if(choose==4) {
            int x;
            int result = pop(a,top,x);
            if (result) {
                cout << "Gia tri lay ra la: " << x << endl; 
            }
        }
    }
}