#include <iostream>
#include <stdlib.h>

struct node {
    std::string value;
    node* next;
};

class Queue {
public:
    size_t size;
    node* head;
    node* tail;
    Queue() {
        size = 0;
    }

    void enqueue(std::string value) {
        if (size == 0) {
            head = (node*)malloc(sizeof(node));
            head->value = value;
            head->next = NULL;
            tail = head;
            size++;
            return;
        }
        size++;
        node* newNode = (node*)malloc(sizeof(node));
        newNode->value = value;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }


    std::string dequeue() {
        if (size == 0) return std::string("Empty");
        std::string tmp = head->value;
        node* toGo = head;
        head = head->next;
        free(toGo);
        size--;
        return tmp;
    }

};

int main(void)
{
    Queue queue = Queue();
    queue.enqueue("Blitz");
    queue.enqueue("Blitz2");
    queue.enqueue("Blitz3");
    std::cout << queue.dequeue() << '\n';
    std::cout << queue.dequeue() << '\n';
}