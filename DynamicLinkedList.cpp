#include <iostream>
#include <ctime>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void remove() {
        if (head != nullptr) {
            Node* current = head;
            Node* prev = nullptr;
            while (current->next != nullptr) {
                prev = current;
                current = current->next;
            }

            if (prev != nullptr) {
                prev->next = nullptr;
                tail = prev;
            } else {
                head = nullptr;
                tail = nullptr;
            }

            delete current;
        }
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList linkedList;
    int insertions = 900;
    int deletions = 100;

    clock_t start_time = clock();

    for (int i = 0; i < insertions; i++) {
        linkedList.insert(i);
    }

    for (int i = 0; i < deletions; i++) {
        linkedList.remove();
    }

    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;

    std::cout << "Time taken for " << insertions << " insertions and " << deletions << " deletions: " << time_taken << " seconds" << std::endl;
    std::cout << "Final linked list: ";
    linkedList.print();

    return 0;
}

