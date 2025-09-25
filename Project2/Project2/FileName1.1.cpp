//#include <iostream>
//using namespace std;
//
//struct Node {
//    int value;
//    Node* next;
//    Node(int v) : value(v), next(nullptr) {}
//};
//
//class Stack {
//    Node* top;
//    int size;
//public:
//    Stack() : top(nullptr), size(0) {}
//
//    bool isEmpty() {
//        return top == nullptr;
//    }
//
//    void push(int v) {
//        Node* n = new Node(v);
//        n->next = top;
//        top = n;
//        size++;
//    }
//
//    int pop() {
//        if (isEmpty()) throw runtime_error("Стек пуст, нельзя сделать pop");
//        int v = top->value;
//        Node* tmp = top;
//        top = top->next;
//        delete tmp;
//        size--;
//        return v;
//    }
//
//    int peek() {
//        if (isEmpty()) throw runtime_error("Стек пуст, нельзя сделать peek");
//        return top->value;
//    }
//
//    int getSize() {
//        return size;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    Stack st;
//    st.push(10);
//    st.push(20);
//    st.push(30);
//
//    cout << "Верхний элемент: " << st.peek() << endl;
//    cout << "Извлечён: " << st.pop() << endl;
//    cout << "Извлечён: " << st.pop() << endl;
//    cout << "Верхний элемент: " << st.peek() << endl;
//    cout << "Размер стека: " << st.getSize() << endl;
//
//    return 0;
//}