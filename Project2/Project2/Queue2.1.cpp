//#include <iostream>
//using namespace std;
//
//struct Node {
//    int value;
//    Node* prev;
//    Node* next;
//    Node(int v) : value(v), prev(nullptr), next(nullptr) {}
//};
//
//class Queue {
//    Node* head;
//    Node* tail;
//    int size;
//public:
//    Queue() : head(nullptr), tail(nullptr), size(0) {}
//
//    bool isEmpty() {
//        return size == 0;
//    }
//
//    void enqueue(int v) {
//        Node* n = new Node(v);
//        if (isEmpty()) {
//            head = tail = n;
//        }
//        else {
//            tail->next = n;
//            n->prev = tail;
//            tail = n;
//        }
//        size++;
//    }
//
//    int dequeue() {
//        if (isEmpty()) {
//            cout << "Очередь пуста!" << endl;
//            return -1;
//        }
//        int v = head->value;
//        Node* tmp = head;
//        head = head->next;
//        if (head) head->prev = nullptr;
//        else tail = nullptr;
//        delete tmp;
//        size--;
//        return v;
//    }
//
//    int front() {
//        if (isEmpty()) {
//            cout << "Очередь пуста!" << endl;
//            return -1;
//        }
//        return head->value;
//    }
//
//    int back() {
//        if (isEmpty()) {
//            cout << "Очередь пуста!" << endl;
//            return -1;
//        }
//        return tail->value;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    Queue q;
//    q.enqueue(10);
//    q.enqueue(20);
//    q.enqueue(30);
//
//    cout << "Первый элемент: " << q.front() << endl;
//    cout << "Последний элемент: " << q.back() << endl;
//    cout << "Удалён: " << q.dequeue() << endl;
//    cout << "Удалён: " << q.dequeue() << endl;
//    cout << "Первый элемент: " << q.front() << endl;
//
//    return 0;
//}