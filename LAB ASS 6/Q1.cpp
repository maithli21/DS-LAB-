#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    void insert(int val, int pos = -1) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        if (pos == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }
        Node* temp = head;
        int idx = 0;
        while (temp->next && (pos == -1 || idx < pos - 1)) {
            temp = temp->next;
            idx++;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteNode(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) {
                if (temp->prev) temp->prev->next = temp->next;
                else head = temp->next; // head node
                if (temp->next) temp->next->prev = temp->prev;
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }
};
class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(nullptr) {}

    void insert(int val, int pos = -1) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }

        if (pos == 0) {
            Node* last = head;
            while (last->next != head) last = last->next;
            newNode->next = head;
            last->next = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        int idx = 0;
        while (temp->next != head && (pos == -1 || idx < pos - 1)) {
            temp = temp->next;
            idx++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int val) {
        if (!head) return;
        Node* temp = head, *prev = nullptr;
        do {
            if (temp->data == val) {
                if (prev) prev->next = temp->next;
                else { 
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    if (head == head->next) { head = nullptr; delete temp; return; }
                    last->next = temp->next;
                    head = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
    }

    bool search(int val) {
        if (!head) return false;
        Node* temp = head;
        do {
            if (temp->data == val) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }
};
