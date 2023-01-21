#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }


};


void print(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void insertAtHead(Node*& tail, Node*& head, int d) {


    if (head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

}

void insertAtTail(Node*& tail, Node*& head, int d) {
    if (tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else {
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

}


void insertAtPosition(Node*& tail, Node*& head, int position, int d) {


    if (position == 1) {
        insertAtHead(tail, head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }


    if (temp->next == NULL) {
        insertAtTail(tail, head, d);
        return;
    }

    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}





int main() {


    Node* head = NULL;
    Node* tail = NULL;

    print(head);


    insertAtHead(tail, head, 11);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtHead(tail, head, 13);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtHead(tail, head, 8);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;



    insertAtPosition(tail, head, 2, 100);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtPosition(tail, head, 1, 101);
    print(head);

    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtPosition(tail, head, 7, 102);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;






    return 0;
}