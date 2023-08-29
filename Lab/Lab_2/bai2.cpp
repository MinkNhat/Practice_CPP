#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* pre;
};

Node* head = NULL;
Node* tail = NULL;

void docFile() {
    ifstream ip;
    ip.open("sort.txt");
    while(!ip.eof()) {
        Node* p = new Node;
        ip >> p->data;
        p->next = head;
        p->pre = NULL;
        if(head==NULL) {
            tail = p;
        } else {
            head->pre = p;
        }
        head = p;
    }
}

void xuat() {
    Node* p = head;
    while(p!=NULL) {
        cout << p->data << "  ";
        p=p->next;
    }
    cout << endl;
}

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

void selectionSort() {
    for(Node* p=head; p!=NULL; p=p->next) {
        Node* min = p;
        for(Node* q=p->next; q!=NULL; q=q->next) {
            if(q->data < min->data) {
                min = q;
            }
        }
        swap(min->data,p->data);
    }
    xuat();
}

void insertSort() {
    bool flags;
    for(Node* p=head->next; p!=NULL; p=p->next) {
        int x = p->data;
        Node* j = p->pre;
        flags = false;
        while(j!=NULL && x<j->data) {
            j->next->data = j->data;
            j=j->pre;
            flags=true;
        }
        if(flags==true) j->next->data = x; 
    }
    xuat();
}

//3 57 33 10 28 36 58 10 26 2 73 6
int main() {
    docFile();
    xuat();
    //selectionSort();
    insertSort();
    return 0;
}