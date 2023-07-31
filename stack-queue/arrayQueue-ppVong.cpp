#include<iostream>
#define MAX 100
using namespace std;



void init(int a[], int &front, int &rear) {
    front = -1;
    rear = -1;
}

void print(int a[], int &front, int &rear) {
    for(int i=front; i<=rear; i++) {
        cout << a[i] << "  ";
    }
}

int push(int a[], int &front, int &rear, int x) {
    if((rear-front == MAX-1) || (rear-front == -1)) {
        cout << "Queue day" << endl;
        return 0;
    } else {
        if(front == -1) {
            front = 0;
        }
        if(rear == MAX-1) {
            rear = -1;
        }
        a[++rear] = x;
        return 1;
    }
}

int pop(int a[], int &front, int &rear, int &x) {
    if(front == -1) {
        cout << "Queue trong" << endl;
        return 0;
    } else {
        x = a[front];
        if(front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
            if(front > MAX-1) {
                front = 0;
            }
        }
        return 1;
    }
}

int main() {
    int a[MAX];
    int front, rear;
    init(a,front,rear);
    while(1) {
        cout << endl;
        cout << "==========STACK=========" << endl;
        cout << "1.Duyet stack" << endl;
        cout << "2.Them 1 phan tu vao stack" << endl;
        cout << "3.Lay 1 phan tu ra khoi stack" << endl;
        cout << "==========================" << endl;

        int choose;
        cout << "Nhap lua chon: ";
        cin >> choose;

        if(choose==1) {
            print(a,front,rear);
        } else if(choose==2) {
            int x;
            cout << "Nhap gia tri can them: ";
            cin >> x;
            push(a,front,rear,x);
        } else if(choose==3) {
            int x;
            int result = pop(a,front,rear,x);
            if (result) {
                cout << "Gia tri lay ra la: " << x << endl; 
            }
        }
    }
    return 0;
}