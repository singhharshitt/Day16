#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertInSortedOrder(Node*& head, int value) {
    Node* newNode = createNode(value);

    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, value, data;

    cout << "Enter number of elements in the sorted linked list: ";
    cin >> n;

    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        insertInSortedOrder(head, data);
    }

    cout << "Enter value to insert: ";
    cin >> value;

    insertInSortedOrder(head, value);

    cout << "Updated List: ";
    printList(head);

    return 0;
}
