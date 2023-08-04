#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void init(Node*& head) {
    head = NULL;
}

Node* makeNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

int size(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void xuat(Node* head) {
    if(head != NULL) {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    } else {
        cout << "DSLK rong" << endl;
    }
}

Node* search(Node* head, int x) {
    Node* temp = head;
    while(temp!=NULL && temp->data!=x) {
        temp = temp->next;
    }
    return temp;
}

void insertFirst(Node*& head, int x) {
    Node* p = makeNode(x);
    p->next = head;
    head = p;
}

void insertLast(Node*& head, int x) {
    Node* p = makeNode(x);
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p;
}

int deleteFirst(Node*& head) {
    if(head == NULL) {
        return 0;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
        return 1;
    }
}

int deleteLast(Node*& head) {
    if(head == NULL) {
        return 0;
    } else {
        Node* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        Node* p = temp->next;
        temp->next = NULL;
        delete p;
        return 1;
    }
}

int searchAndDelete(Node*& head, int x) {
    if(head == NULL) {
        return 0;
    } else {
        Node* temp = head;
        Node* p = NULL;
        while(temp!=NULL && temp->data!=x) {
            p = temp;
            temp = temp->next;
        }
        if(temp!=NULL) {
            p->next = temp->next;
            delete temp;
            return 1;
        }
        return 0;
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sort(Node* head) {
    if(head != NULL) {
        Node* p = new Node;
        Node* k = new Node;
        for(p=head; p!=NULL; p=p->next) {
            for(k=p->next; k!=NULL; k=k->next) {
                if(p->data > k->data) {
                    swap(p->data, k->data);
                }
            }
        }
    } else {
        cout << "DSLK rong" << endl;
    }
}

int main() {
    Node* head;
    init(head);
    while(1) {
        cout << endl;
        cout << "=========MENU========" << endl;
        cout << "1. Duyet DSLK" << endl;
        cout << "2. Tim phan tu" << endl;
        cout << "3. Them dau DSLK" << endl;
        cout << "4. Them cuoi DSLK" << endl;
        cout << "5. Xoa dau DSLK" << endl;
        cout << "6. Xoa cuoi DSLK" << endl;
        cout << "7. Tim va xoa" << endl;
        cout << "8. Sap xep" << endl;
        cout << "======================" << endl;
        int choose;
        cout << "Lua chon: ";
        cin >> choose;

        switch(choose) {
            case 1: xuat(head);
            break;
            case 2: {
                int x;
                cout << "Gia tri can tim: ";
                cin >> x;
                Node* result = search(head,x);
                if(result!=NULL) {
                    cout << "Da tim thay gia tri" << result->data << endl;
                } else {
                    cout << "Khong tim thay gia tri" << endl;
                }
            }
            break;
            case 3: {
                int x;
                cout << "Gia tri can them: ";
                cin >> x;
                insertFirst(head,x);
            }
            break;
            case 4: {
                int x;
                cout << "Gia tri can them: ";
                cin >> x;
                insertLast(head,x);
            }
            break;
            case 5: {
                int result = deleteFirst(head);
                if(result) {
                    cout << "Xoa thanh cong" << endl;
                } else {
                    cout << "DSLK rong" << endl;
                }
            }
            break;
            case 6: {
                int result = deleteLast(head);
                if(result) {
                    cout << "Xoa thanh cong" << endl;
                } else {
                    cout << "DSLK rong" << endl;
                }
            }
            break;
            case 7: {
                int x;
                cout << "Gia tri can tim va xoa: ";
                cin >> x;
                int result = searchAndDelete(head,x);
                if(result) {
                    cout << "Xoa thanh cong" << endl;
                } else {
                    cout << "DSLK rong hoac kh tim thay gia tri" << endl;
                }
            }
            break;
            case 8: {
                sort(head);
            }
        }
    }
    return 0;
}