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
    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void print(Node* head) {
    if(head!=NULL) {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void insert(Node*& head, int x) {
    Node* p = makeNode(x);
    if(head == NULL) {
        head = p;
    } else {
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        if(head->data > x) {
            p->next = head;
            head = p;
        } else if(temp->data < x) {
            temp->next = p;
        } else {
            Node* k = head;
            Node* q = NULL;
            while(k->data <= x) {
                q = k;
                k = k->next;
            }
            p->next = q->next;
            q->next = p;
        }
    }
}

Node* search(Node* head, int x) {
    Node* temp = head;
    while(temp!=NULL && temp->data!=x) {
        temp = temp->next;
    }
    return temp;
}

void deleteNode(Node*& head, int x) {
    Node* temp = head;
    Node* preTemp = NULL;
    if(head->data == x) {
        head = head->next;
    } else {
        while(temp->data!=x) {
            preTemp = temp;
            temp = temp->next;
        }
        preTemp->next = temp->next;
        delete temp;
    }
}

int searchAndDelete(Node*& head, int x) {
    Node* p = search(head,x);
    if(p!=NULL) {
        deleteNode(head,p->data);
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Node* head;
    init(head);
    while(1) {
        cout << endl;
        cout << "==========MENU=========" << endl;
        cout << "1. Duyet danh sach" << endl;
        cout << "2. Them phan tu" << endl;
        cout << "3. Tim " << endl;
        cout << "4. Tim va xoa phan tu" << endl;
        cout << "========================" << endl;
        int choose;
        cout << "Lua chon: ";
        cin >> choose;
        switch(choose) {
            case 1: print(head);
            break;
            case 2: {
                int x;
                cout << "Gia tri can them: ";
                cin >> x;
                insert(head,x); 
            }
            break;
            case 3: {
                int x;
                cout << "Gia tri can tim: ";
                cin >> x;
                Node* temp = search(head,x);
                if(temp!=NULL) {
                    cout << "Tim thay gia tri " << temp->data << endl;
                } else {
                    cout << "Khong tim thay gia tri" << endl;
                }
            }
            break;
            case 4: {
                int x;
                cout << "Gia tri can tim va xoa: ";
                cin >> x;
                int result = searchAndDelete(head,x);
                if(result) {
                    cout << "Xoa thanh cong" << endl;
                } else {
                    cout << "Xoa that bai!" << endl;
                }
            }
        }
    }
    return 0;
} 