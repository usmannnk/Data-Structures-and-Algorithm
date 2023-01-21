#include<iostream>
#include<map>
using namespace std;

class Node {

public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

};

void insertAtHead(Node*& head, int da) {

    Node* temp = new Node(da);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node*& tail, int da) {

    Node* temp = new Node(da);
    tail->next = temp;
    tail = temp;
}

void print(Node*& head) {

    if (head == NULL) {
        cout << "List is empty " << endl;
        return;
    }
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(Node*& tail, Node*& head, int position, int da) {

    if (position == 1) {
        insertAtHead(head, da);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertAtTail(tail, da);
        return;
    }

    Node* nodeToInsert = new Node(da);

    nodeToInsert->next = temp->next;

    temp->next = nodeToInsert;
}











int main() {

    Node* node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    Node* head = node1;
    Node* tail = node1;

    print(head);
    insertAtHead(head, 10);

    insertAtTail(tail, 15);
    print(tail);

    insertAtPosition(tail, head, 4, 22);
    print(head);
}