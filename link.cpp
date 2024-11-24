#include <iostream>
#include <string>

using namespace std;

class ChainLink {
private:
    string color;

public:
    ChainLink(string color) {
        this->color = color;
    }

    string get_color() {
        return this->color;
    }
};

class Node {
public:
    ChainLink* link; 
    Node* next;       

    Node(ChainLink* link) {
        this->link = link;
        this->next = nullptr;  
    }
};

class SingleLinkedList {
private:
    Node* head;  

public:
    SingleLinkedList() {
        head = nullptr;
    }

    ~SingleLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current->link;  
            delete current;        
            current = nextNode;
        }
    }

    void append(ChainLink* newLink) {
        Node* newNode = new Node(newLink);
        if (head == nullptr) {
            head = newNode;  
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;  
            }
            current->next = newNode;  
        }
    }

    ChainLink* view(int index) {
        Node* current = head;
        int currentIndex = 0;
        while (current != nullptr) {
            if (currentIndex == index) {
                return current->link;  
            }
            current = current->next;
            currentIndex++;
        }
        return nullptr;  
    }
};

int main() {
  
    SingleLinkedList list;

    list.append(new ChainLink("Red"));
    list.append(new ChainLink("Blue"));
    list.append(new ChainLink("Green"));
   
    ChainLink* link1 = list.view(0);
    if (link1 != nullptr) {
        cout << "ChainLink at index 0: " << link1->get_color() << endl;
    }

    ChainLink* link2 = list.view(1);
    if (link2 != nullptr) {
        cout << "ChainLink at index 1: " << link2->get_color() << endl;
    }

    ChainLink* link3 = list.view(2);
    if (link3 != nullptr) {
        cout << "ChainLink at index 2: " << link3->get_color() << endl;
    }

 
    ChainLink* invalidLink = list.view(7);
    if (invalidLink == nullptr) {
        cout << "Index 7 is out of bounds." << endl;
    }

    return 0;
}
