#include<iostream>
using namespace std;

// front=5 -> 6 -> 7 -> 8=rear -> NULL

struct node{
    int data;
    node* next;
};

node* front;
node* rear;

void init() {
    front = NULL;
    rear = NULL;
}

void print() {
    node* p = front;
    while(p != NULL) {
        cout << p->data << "  ";
        p = p->next;
    }
}

bool isEmpty() {
    if(front==NULL) return true;
    return false;
}

void push(int x) {
    node* p = new node;
    p->data = x;
    p->next = NULL;
    if(rear == NULL) {
        front = p;
    } else {
        rear->next = p;
    }
    rear = p;
} 

int pop(int &x) {
    if(front != NULL) {
        node* p = front;
        x = p->data;
        front = front->next;
        if(front == NULL) {
            rear = NULL;
        }
        delete p;
        return 1;
    } else {
        cout << "Queue rong" << endl;
        return 0;
    }
}

int main() {
    init();
    while(1) {
        cout << endl;
        cout << "==========Queue=========" << endl;
        cout << "1.Duyet queue" << endl;
        cout << "2.Kiem tra queue rong?" << endl;
        cout << "3.Them 1 phan tu vao queue" << endl;
        cout << "4.Lay 1 phan tu ra khoi queue" << endl;
        cout << "==========================" << endl;

        int choose;
        cout << "Nhap lua chon: ";
        cin >> choose;

        if(choose==1) {
            print();
        } else if(choose==2) {
            bool result = isEmpty();
            if(result) {
                cout << "queue trong" << endl;
            } else {
                cout << "queue chua trong" << endl;
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