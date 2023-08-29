#include<iostream>
#include<string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top;

void print() {
    Node* p = top;
    while(p!=NULL) {
        cout << p->data << "  ";
        p = p->next;
    }
    cout << endl;
}

void push(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = top;
    top = p;
}

void pop(int& x) {
    Node* p = top;
    x = p->data;
    top = top->next;
    delete p;
}

void convert() {
    int n,k;
    cout << "Nhap so ( dang thap phan ): ";
    cin >> n;
    cout << "Chuyen sang he: ";
    cin >> k;

    while(n/k != 0) {
        int temp = n % k;
        n = n/k;
        push(temp);
    }
    push(n);

    Node* p = top;
    cout << "Ket qua = ";
    while(p!=NULL) {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}

int main() {
    convert();
    return 0;
}