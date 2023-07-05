#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head;

void init() {
    head = NULL;
}

int size() {
    int count = 0;
    node* p = head;
    if(p != NULL) {
        do{
            count++;
            p = p->next;
        } while(p != head); 
    }
    return count;
}

void print() {
    node* p = head;
    if(p != NULL) {
        do {
            cout << p->data << "  ";
            p = p->next;
        } while(p != head);
    }
}

void insertFirst(int x) {
    node* p = new node;
    p->data = x;
    p->next = head;
    node* q = head;
    if(q != NULL) {
        while(q->next != head) {
            q = q->next;
        }
        q->next = p;
    } else {
        p->next = p;
    }
    head = p;
}

void insertLast(int x) {
    node* p = new node;
    p->data = x;
    node* q = head;
    if(q != NULL) {
        while(q->next != head) {
            q = q->next;
        }
        q->next = p;
        p->next = head;
    } else {
        p->next = p;
    }
}

void insertMiddle(int pos, int x) {
    int n = size();
    if(pos>=0 && pos<=n) {
        if(pos==0) {
            insertFirst(x);
        } else if(pos==n) {
            insertLast(x);
        } else {
            node* p = new node;
            p->data = x;
            node* q = head;
            for(int i=0; i<pos-1; i++) {
                q = q->next;
            }
            p->next = q->next;
            q->next = p;
        }
    } else {
        cout << "vi tri khong hop le" << endl;
    }
}

void deleteFirst() {
    if(head != NULL) {
        node* p = head;
        node* q = head;
        while(q->next != head) {
            q = q->next;
        }
        if(p != q) {
            head = head->next;
            q->next = head;
        } else {
            head = NULL;
        }
        delete p;
    }
}

void deleteLast() {
    if(head != NULL) {
        node* p = head;
        node* q = NULL;
        while(p->next != head) {
            q = p;
            p = p->next;
        }
        if(q != NULL) {
            q->next = head;
        } else {
            head = NULL;
        }
        delete p;
    }
}

void deleteMiddle(int pos) {
    if(head != NULL) {
        int n = size();
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
                node* q = p->next;
                p->next = q->next;
                delete q;
            }
        } else {
            cout << "Vi tri khong hop le" << endl;
        }
    }
}

int main() {
    init();
    while(1) {
        cout << endl;
        cout << "------------MENU---------------" << endl;
        cout << "1. Duyet danh sach" << endl;
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
            int n = size();
            cout << "DS co kich thuoc = " << n << endl;
        } else if(choose==1) {
            print();
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