#include <iostream>
#include <string>
using namespace std;

struct VNode {
    string v;
    VNode* n;
    VNode(string val) : v(val), n(nullptr) {}
};

struct Node {
    string p;
    VNode* vList;
    Node* l;
    Node* r;
    Node(string plate, string val) : p(plate), l(nullptr), r(nullptr) {
        vList = new VNode(val);
    }
};

class DB {
    Node* root;

    void ins(Node*& node, const string& plate, const string& val) {
        if (!node) { node = new Node(plate, val); return; }
        if (plate < node->p) ins(node->l, plate, val);
        else if (plate > node->p) ins(node->r, plate, val);
        else {
            VNode* cur = node->vList;
            while (cur->n) cur = cur->n;
            cur->n = new VNode(val);
        }
    }

    void printAll(Node* node) {
        if (!node) return;
        printAll(node->l);
        cout << node->p << ": ";
        VNode* cur = node->vList;
        while (cur) { cout << cur->v; if (cur->n) cout << ", "; cur = cur->n; }
        cout << endl;
        printAll(node->r);
    }

    Node* find(Node* node, const string& plate) {
        if (!node) return nullptr;
        if (plate == node->p) return node;
        if (plate < node->p) return find(node->l, plate);
        return find(node->r, plate);
    }

    void printRange(Node* node, const string& low, const string& high) {
        if (!node) return;
        if (low < node->p) printRange(node->l, low, high);
        if (low <= node->p && node->p <= high) {
            cout << node->p << ": ";
            VNode* cur = node->vList;
            while (cur) { cout << cur->v; if (cur->n) cout << ", "; cur = cur->n; }
            cout << endl;
        }
        if (node->p < high) printRange(node->r, low, high);
    }

public:
    DB() : root(nullptr) {}

    void add(const string& plate, const string& val) { ins(root, plate, val); }

    void printAll() { printAll(root); }

    void printPlate(const string& plate) {
        Node* node = find(root, plate);
        if (!node) { cout << "Нет данных для " << plate << endl; return; }
        cout << node->p << ": ";
        VNode* cur = node->vList;
        while (cur) { cout << cur->v; if (cur->n) cout << ", "; cur = cur->n; }
        cout << endl;
    }

    void printRange(const string& low, const string& high) { printRange(root, low, high); }
};

int main() {
    setlocale(LC_ALL, "ru");
    DB db;

    db.add("A123BC", "Speeding");
    db.add("A123BC", "Red light");
    db.add("B456DE", "Parking");
    db.add("C789FG", "Speeding");

    cout << "Полная база:" << endl;
    db.printAll();

    cout << "\nДанные по A123BC:" << endl;
    db.printPlate("A123BC");

    cout << "\nДанные по диапазону B000AA - C999ZZ:" << endl;
    db.printRange("B000AA", "C999ZZ");

    return 0;
}