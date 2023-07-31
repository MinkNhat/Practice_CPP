#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

Node* createNewNode(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

int size() {
    int count = 0;
    Node* p = head;
    while(p!=NULL) {
        p = p->next;
        count++;
    }
    return count;
}

void printList() {
    Node* p = new Node;
    p = head;
    while(p!=NULL) {
        cout << p->data << "  ";
        p = p->next;
    }
}

void insertFirst(int x) {
    Node* p = createNewNode(x);
    if(head==NULL) {
        head = p;
    } else {
        p->next = head;
        head = p;
    }
}

void insertLast(int x) {
    Node* p = createNewNode(x);
    if(head==NULL) {
        head = p;
    } else {
        Node* tmp = head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = p;
    }
}

void insertMiddle(int x, int pos) {
    int n = size();
    Node* p = createNewNode(x);
    if(pos <= 0 || pos > n+1) {
        cout << "Vi tri khong hop le!" << endl;
    } else if(pos==1) {
        insertFirst(x);
    } else if(pos==n+1) {
        insertLast(x);
    } else {
        Node* tmp = head;
        for(int i=0; i<pos-2; i++) {
            tmp = tmp->next;
        }
        p->next = tmp->next;
        tmp->next = p;
    }
}

void deleteFirst() {
    Node* p = head;
    if(p != NULL) {
        p = p->next;
    }
    head = p;
}

void deleteLast() {
    Node* p = head;
    Node* q = NULL;
    while(p->next != NULL) {
        q = p;
        p = p->next;
    }
    q -> next = NULL;
}

void deleteMiddle(int pos) {
    Node* p = head;
    Node* q = NULL;
    for(int i=1; i<pos; i++) {
        q = p;
        p = p->next;
    }
    q->next = p->next;
}

int main() {
    
    while(1) {
        cout << endl;
        cout << "------------MENU---------------" << endl;
        cout << "0. Kich thuoc DS" << endl;
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
            printList();
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
            insertMiddle(x,pos);
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
}