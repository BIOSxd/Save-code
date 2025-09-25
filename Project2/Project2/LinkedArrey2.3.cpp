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
//class Array {
//    Node* head;
//    Node* tail;
//    int size;
//    int count;
//    int growStep;
//public:
//    Array(int s = 0, int g = 1) : head(nullptr), tail(nullptr), size(s), count(0), growStep(g) {
//        for (int i = 0; i < s; i++) Add(0);
//    }
//
//    int GetSize() { return size; }
//
//    void SetSize(int newSize, int grow = 1) {
//        growStep = grow;
//        if (newSize < count) {
//            while (count > newSize) RemoveAt(count - 1);
//        }
//        else {
//            while (size < newSize) Add(0);
//        }
//        size = newSize;
//    }
//
//    int GetUpperBound() { return count - 1; }
//
//    bool IsEmpty() { return count == 0; }
//
//    void FreeExtra() { size = count; }
//
//    void RemoveAll() {
//        while (head) {
//            Node* tmp = head;
//            head = head->next;
//            delete tmp;
//        }
//        tail = nullptr;
//        size = 0;
//        count = 0;
//    }
//
//    int GetAt(int index) {
//        Node* cur = head;
//        for (int i = 0; i < index; i++) cur = cur->next;
//        return cur->value;
//    }
//
//    void SetAt(int index, int val) {
//        Node* cur = head;
//        for (int i = 0; i < index; i++) cur = cur->next;
//        cur->value = val;
//    }
//
//    int& operator[](int index) {
//        Node* cur = head;
//        for (int i = 0; i < index; i++) cur = cur->next;
//        return cur->value;
//    }
//
//    int Add(int val) {
//        if (count >= size) size += growStep;
//        Node* n = new Node(val);
//        if (!head) {
//            head = tail = n;
//        }
//        else {
//            tail->next = n;
//            n->prev = tail;
//            tail = n;
//        }
//        return count++;
//    }
//
//    void Append(Array& other) {
//        Node* cur = other.head;
//        while (cur) {
//            Add(cur->value);
//            cur = cur->next;
//        }
//    }
//
//    Array& operator=(Array& other) {
//        if (this == &other) return *this;
//        RemoveAll();
//        Node* cur = other.head;
//        while (cur) {
//            Add(cur->value);
//            cur = cur->next;
//        }
//        return *this;
//    }
//
//    void InsertAt(int index, int val) {
//        if (index == count) { Add(val); return; }
//        Node* cur = head;
//        for (int i = 0; i < index; i++) cur = cur->next;
//        Node* n = new Node(val);
//        n->next = cur;
//        n->prev = cur->prev;
//        if (cur->prev) cur->prev->next = n;
//        else head = n;
//        cur->prev = n;
//        count++;
//        if (count > size) size += growStep;
//    }
//
//    void RemoveAt(int index) {
//        Node* cur = head;
//        for (int i = 0; i < index; i++) cur = cur->next;
//        if (cur->prev) cur->prev->next = cur->next;
//        else head = cur->next;
//        if (cur->next) cur->next->prev = cur->prev;
//        else tail = cur->prev;
//        delete cur;
//        count--;
//    }
//
//    void print() {
//        Node* cur = head;
//        while (cur) {
//            cout << cur->value << " ";
//            cur = cur->next;
//        }
//        cout << endl;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    Array arr(5, 2);
//    arr.SetAt(0, 10);
//    arr.SetAt(1, 20);
//    arr.SetAt(2, 30);
//    arr.SetAt(3, 40);
//    arr.SetAt(4, 50);
//
//    cout << "Массив: "; arr.print();
//    cout << "Размер: " << arr.GetSize() << endl;
//    cout << "Последний индекс: " << arr.GetUpperBound() << endl;
//
//    arr.Add(60);
//    arr.Add(70);
//    cout << "После добавления: "; arr.print();
//
//    arr.InsertAt(2, 99);
//    cout << "После вставки: "; arr.print();
//
//    arr.RemoveAt(3);
//    cout << "После удаления: "; arr.print();
//
//    return 0;
//}