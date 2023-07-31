#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* top;

void init() {
    top = NULL;
}

void print() {
    node* p = top;
    while(p != NULL) {
        cout << p->data << "  ";
        p = p->next;
    }
}

bool isEmpty() {
    if(top==NULL) return true;
    return false;
}

void push(int x) {
    node* p = new node;
    p->data = x;
    p->next = top;
    top = p;
} 

int pop(int &x) {
    if(top != NULL) {
        node* p = top;
        x = p->data;
        top = top->next;
        delete p;
        return 1;
    } else {
        cout << "Stack rong" << endl;
        return 0;
    }
}

int main() {
    init();
    while(1) {
        cout << endl;
        cout << "==========STACK=========" << endl;
        cout << "1.Duyet stack" << endl;
        cout << "2.Kiem tra stack rong?" << endl;
        cout << "3.Them 1 phan tu vao stack" << endl;
        cout << "4.Lay 1 phan tu ra khoi stack" << endl;
        cout << "==========================" << endl;

        int choose;
        cout << "Nhap lua chon: ";
        cin >> choose;

        if(choose==1) {
            print();
        } else if(choose==2) {
            bool result = isEmpty();
            if(result) {
                cout << "Stack trong" << endl;
            } else {
                cout << "Stack chua trong" << endl;
            }
        } else if(choose==3) {
            int x;
            cout << "Nhap gia tri can them: ";
            cin >> x;
            push(x);
        } else if(choose==4) {
            int x;
            int result = pop(x);
            if (result) {
                cout << "Gia tri lay ra la: " << x << endl; 
            }
        }
    }
    return 0;
}