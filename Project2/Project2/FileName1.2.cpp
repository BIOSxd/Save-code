//#include <iostream>
//using namespace std;
//
//struct Node {
//    int value;
//    Node* next;
//    Node(int v) : value(v), next(nullptr) {}
//};
//
//class List {
//    Node* head;
//public:
//    List() : head(nullptr) {}
//
//    Node* getHead() { return head; }
//
//    void pushBack(int v) {
//        Node* n = new Node(v);
//        if (!head) {
//            head = n;
//        }
//        else {
//            Node* cur = head;
//            while (cur->next) cur = cur->next;
//            cur->next = n;
//        }
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
//
//    Node* clone() {
//        if (!head) return nullptr;
//        Node* newHead = new Node(head->value);
//        Node* curOld = head->next;
//        Node* curNew = newHead;
//        while (curOld) {
//            curNew->next = new Node(curOld->value);
//            curNew = curNew->next;
//            curOld = curOld->next;
//        }
//        return newHead;
//    }
//
//    Node* operator+(List& other) {
//        List result;
//        Node* cur = head;
//        while (cur) {
//            result.pushBack(cur->value);
//            cur = cur->next;
//        }
//        cur = other.head;
//        while (cur) {
//            result.pushBack(cur->value);
//            cur = cur->next;
//        }
//        return result.head;
//    }
//
//    Node* operator*(List& other) {
//        List result;
//        Node* cur1 = head;
//        while (cur1) {
//            Node* cur2 = other.head;
//            while (cur2) {
//                if (cur1->value == cur2->value) {
//                    result.pushBack(cur1->value);
//                    break;
//                }
//                cur2 = cur2->next;
//            }
//            cur1 = cur1->next;
//        }
//        return result.head;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "ru");
//    List a, b;
//    a.pushBack(1);
//    a.pushBack(2);
//    a.pushBack(3);
//
//    b.pushBack(2);
//    b.pushBack(3);
//    b.pushBack(4);
//
//    cout << "Список A: "; a.print();
//    cout << "Список B: "; b.print();
//
//    Node* cloneA = a.clone();
//    cout << "Клон списка A: ";
//    for (Node* c = cloneA; c; c = c->next) cout << c->value << " ";
//    cout << endl;
//
//    Node* plusAB = a + b;
//    cout << "A + B: ";
//    for (Node* c = plusAB; c; c = c->next) cout << c->value << " ";
//    cout << endl;
//
//    Node* multAB = a * b;
//    cout << "A * B: ";
//    for (Node* c = multAB; c; c = c->next) cout << c->value << " ";
//    cout << endl;
//
//    return 0;
//}