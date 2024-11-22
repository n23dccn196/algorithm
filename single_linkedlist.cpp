#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void duyet(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}

int count(Node* head) {
    int dem = 0;
    while (head != nullptr) {
        dem++;
        head = head->next;
    }
    return dem;
}

void pushFront(Node** head, int x) {
    Node* newNode = new Node(x);
    newNode->next = *head;
    *head = newNode;
}

void pushBack(Node** head, int x) {
    Node* newNode = new Node(x);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insert(Node** head, int x, int k) {
    int n = count(*head);
    if (k < 1 || k > n + 1) return;
    if (k == 1) {
        pushFront(head, x);
        return;
    }
    Node* temp = *head;
    for (int i = 0; i < k - 2; i++) {
        temp = temp->next;
    }
    Node* newNode = new Node(x);
    newNode->next = temp->next;
    temp->next = newNode;
}

void popFront(Node** head) {
    if (*head == nullptr) return;
    Node* temp = *head;
    *head = (*head)->next;
    delete temp;
}

void popBack(Node** head) {
    if (*head == nullptr) return;
    Node* temp = *head;
    if (temp->next == nullptr) {
        *head = nullptr;
        delete temp;
        return;
    }
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    Node* last = temp->next;
    temp->next = nullptr;
    delete last;
}

void erase(Node** head, int k) {
    if (*head == nullptr) return;
    int n = count(*head);
    if (k < 1 || k > n) return;
    if (k == 1) {
        popFront(head);
        return;
    }
    Node* temp = *head;
    for (int i = 0; i < k - 2; i++) {
        temp = temp->next;
    }
    Node* last = temp->next;
    temp->next = last->next;
    delete last;
}