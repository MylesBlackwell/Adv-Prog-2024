#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Template for classes
template <typename T>
class LinkedList {
    struct Node {
        T data;
        unique_ptr<Node> next;
        Node(T data) : data(move(data)), next(nullptr) {}
    };

    unique_ptr<Node> head;
public:
    LinkedList() {
        head = nullptr;
    }

    // Add a node at the end of the list
    void addNode(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Delete a node with a specific value
    void deleteNode(T key) {
        Node<T>* temp = head;
        Node<T>* prev = nullptr;

        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    T& refNode(int index) {
        Node<T>* current = head;
        int count = 0;

        while (current != nullptr) {
            if (count == index) {
                return current->data;
            }
            count++;
            current = current->next;
        }

        throw out_of_range("Index out of bounds");
    }  
};
