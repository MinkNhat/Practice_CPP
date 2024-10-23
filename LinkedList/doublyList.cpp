#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* pre;
};

node* head;
node* tail;

void init() {
    head = NULL;
    tail = NULL;
}

int size() {
    int count = 0;
    node* p = head;
    while(p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void printXuoi() {
    node* p = head;
    while(p != NULL) {
        cout << p->data << "  ";
        p = p->next;
    }
}

void printNguoc() {
    node* p = tail;
    while(p != NULL) {
        cout << p->data << "  ";
        p = p->pre;
    }
}

void insertFirst(int x) {
    node* p = new node;
    p->data = x;
    p->next = head;
    p->pre = NULL;
    if(head != NULL) {
        head->pre = p;
    } else {
        tail = p;
    }
    head = p;
}

void insertLast(int x) {
    node* p = new node;
    p->data = x;
    p->next = NULL;
    p->pre = tail;
    if(tail != NULL) {
        tail->next = p;
    } else {
        head = p;
    }
    tail = p;
}

void insertMiddle(int pos, int x) {
    int n = size();
    if(pos>=0 && pos<=n) {
        if(pos==0) {
            insertFirst(x);
        } else if(pos==n) {
            insertLast(x);
        } else {
            node* p = head;
            for(int i=0; i<pos-1; i++) {
                p = p->next;
            }
            node* temp = new node;
            temp->data = x;
            temp->next = p->next;
            temp->pre = p;
            p->next->pre = temp;
            p->next = temp;
        }
    } else {
        cout << "Vi tri khong phu hop!" << endl;
    }
}

void deleteFirst() {
    if(head != NULL) {
        node* p = head;
        head = head->next;
        delete p;
        if(head != NULL) {
            head->pre = NULL;
        } else {
            tail = NULL;
        }
    }
}

void deleteLast() {
    if(tail != NULL) {
        node* p = tail;
        tail = tail->pre;
        delete p;
        if(tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL;
        }
    }
}

void deleteMiddle(int pos) {
    int n = size();
    if(n>0) {
        if(pos>=0 && pos<=n-1) {
            if(pos==0) {
                deleteFirst();
            } else if(pos==n-1) {
                deleteLast();
            } else {
                node* p = head;
                for(int i=0; i<pos-1; i++) {
                    p = p->next;
                }
                node* p2 = p->next;
                node* p3 = p2->next;
                p->next = p3;
                p3->pre = p;
                delete p2;
            }
        } else {
            cout << "Vi tri khong hop le" << endl;
        }
    } else {
        cout << "Khong ton tai phan tu" << endl;

    }
}

int main() {
    init();
    while(1) {
        cout << endl;
        cout << "------------MENU---------------" << endl;
        cout << "0. Duyet danh sach theo chieu xuoi" << endl;
        cout << "1. Duyet danh sach theo chieu nguoc" << endl;
        cout << "2. Them phan tu vao dau DS" << endl;
        cout << "3. Them phan tu vao cuoi DS" << endl;
        cout << "4. Them phan tu vao vi tri bat ki DS" << endl;
        cout << "5. Xoa phan tu dau DS" << endl;
        cout << "6. Xoa phan tu cuoi DS" << endl;
        cout << "7. Xoa phan tu tai vi tri bat ki DS" << endl;
        cout << "-------------------------------" << endl;
        cout << endl;

        int choose;
        cout << "Nhap lua chon: ";
        cin >> choose;

        if(choose==0) {
            printXuoi();
        } else if(choose==1) {
            printNguoc(); 
        } else if(choose==2) {
            int x;
            cout << "Nhap gia tri can chen: ";
            cin >> x;
            insertFirst(x);
        } else if(choose==3) {
            int x;
            cout << "Nhap gia tri can chen: ";
            cin >> x;
            insertLast(x);
        } else if(choose==4) {
            int x,pos;
            cout << "Nhap vi tri can chen: ";
            cin >> pos;
            cout << "Nhap gia tri can chen: ";
            cin >> x;
            insertMiddle(pos,x);
        } else if(choose==5) {
            deleteFirst();
        } else if(choose==6) {
            deleteLast();
        } else if(choose==7) {
            int pos;
            cout << "Nhap vi tri can xoa: ";
            cin >> pos;
            deleteMiddle(pos);
        }
    }
    return 0;
}