#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* pre;
};

struct ListNode{
    Node* head;
    Node* tail;
};

void init(ListNode*& list) {
    list->head = NULL;
    list->tail = NULL;
}

ListNode* makeNode(int x) {
    ListNode* list = new ListNode;
    list->head = new Node;
    list->head->data = x;
    list->head->next = NULL;
    list->head->pre = NULL;
    list->tail = list->head;
    return list;
}

void print(ListNode* list) {
    Node* p = list->head;
    while(p!=NULL) {
        cout << p->data << "  ";
        p = p->next;
    }
    cout << endl;
}

void insertFirst(ListNode*& list, int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->pre = NULL;
    temp->next = list->head;
    if(list->head != NULL) {
        list->head->pre = temp;
    } else {
        list->tail = temp;
    }
    list->head = temp;
}

void insertLast(ListNode*& list, int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;
    temp->pre = list->tail;
    if(list->tail != NULL) {
        list->tail->next = temp;
    } else {
        list->head = temp;
    }
    list->tail = temp;
}

int deleteFirst(ListNode*& list) {
    if(list->head==NULL) {
        return 0;
    } else {
        Node* temp = list->head;
        list->head = list->head->next;
        delete temp;
        return 1;
    }
}

int deleteLast(ListNode*& list) {
    if(list->head==NULL) {
        return 0;
    } else {
        Node* temp = list->tail;
        list->tail = list->tail->pre;
        list->tail->next = NULL;
        delete temp;
        return 1;
    }
}

Node* search(ListNode* list, int x) {
    Node* temp = list->head;
    while(temp != NULL && temp->data!=x) {
        temp = temp->next;
    }
    return temp;
}

int searchAndInsert(ListNode*& list, int x, int n) {
    if(list->head==NULL) {
        return 0;
    } else {
        Node* temp = list->head;
        int min = 99;
        while(temp!=NULL && temp->data!=x) {
            if(temp->data > x && (temp->data - x) < min) {
                min = temp->data - x;
            }
            temp = temp->next;
        }
        if(temp!=NULL) {
            Node* p = new Node;
            p->data = n;
            p->next = temp;
            p->pre = temp->pre;
            temp->pre->next = p;
            temp->pre = p;
            return 1;
        } else {
            if(min==99) {
                return 0;
            } else {
                int nearData = min + x;
                Node* p = list->head;
                while(p!=NULL && p->data!=nearData) {
                    p = p->next;
                }
                Node* q = new Node;
                q->data = n;
                q->next = p;
                q->pre = p->pre;
                p->pre->next = q;
                p->pre = q;
                return 1;
            }
        }
    }
}

int main() {
    ListNode* list = new ListNode;
    init(list);
    while(1) {
        cout << endl;
        cout << "==========MENU===========" << endl;
        cout << "0. Duyet" << endl;
        cout << "1. Them dau DS" << endl;
        cout << "2. Them cuoi DS" << endl;
        cout << "3. Xoa dau DS" << endl;
        cout << "4. Xoa cuoi DS" << endl;
        cout << "5. Tim va them" << endl;
        cout << "========================" << endl;

        int choose;
        cout << "Lua chon cua ban: ";
        cin >> choose;

        switch(choose) {
            case 0: print(list);
            break;

            case 1: {
                int x;
                cout << "Gia tri: ";
                cin >> x;
                insertFirst(list,x);
            }
            break;

            case 2: {
                int x;
                cout << "Gia tri: ";
                cin >> x;
                insertLast(list,x);
            }
            break;

            case 3: {
                int result = deleteFirst(list);
                if(result) {
                    cout << "Xoa thanh cong" << endl;
                } else {
                    cout << "Xoa that bai" << endl;
                }
            }
            break;

            case 4: {
                int result = deleteLast(list);
                if(result) {
                    cout << "Xoa thanh cong" << endl;
                } else {
                    cout << "Xoa that bai" << endl;
                }
            }
            break;

            case 5: {
                int x,n;
                cout << "Nhap gia tri x: ";
                cin >> x;
                cout << "Gia tri them: ";
                cin >> x;
                int result = searchAndInsert(list,x,n);
                if(result) {
                    cout << "Them thanh cong" << endl;
                } else {
                    cout << "Them that bai" << endl;
                }
            }
            break;
        }
    }
    return 0;
}  