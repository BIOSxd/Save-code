//#include <iostream>
//#include <stdexcept>
//
//struct Nod {
//    int val;
//    Nod* pr;
//    Nod* nx;
//    Nod(int v) : val(v), pr(nullptr), nx(nullptr) {}
//};
//
//class Lst {
//    Nod* hd;
//    Nod* tl;
//    int sz;
//public:
//    Lst() : hd(nullptr), tl(nullptr), sz(0) {}
//
//    void add(int v) {
//        Nod* n = new(std::nothrow) Nod(v);
//        if (!n) throw std::bad_alloc();
//        if (!hd) { hd = tl = n; }
//        else { tl->nx = n; n->pr = tl; tl = n; }
//        sz++;
//    }
//
//    void rem() {
//        if (!tl) throw std::underflow_error("������ ����, �������� ����������");
//        Nod* t = tl;
//        if (tl->pr) { tl = tl->pr; tl->nx = nullptr; }
//        else { hd = tl = nullptr; }
//        delete t;
//        sz--;
//    }
//
//    int get(int i) {
//        if (i < 0 || i >= sz) throw std::out_of_range("�������� ������");
//        Nod* c = hd;
//        for (int j = 0; j < i; j++) c = c->nx;
//        return c->val;
//    }
//
//    void prt() {
//        Nod* c = hd;
//        while (c) { std::cout << c->val << " "; c = c->nx; }
//        std::cout << std::endl;
//    }
//};
//
//int main() {
//    setlocale(0, "ru");
//    Lst l;
//    try {
//        l.add(10);
//        l.add(20);
//        l.add(30);
//        l.prt();
//        std::cout << "������� � �������� 1: " << l.get(1) << std::endl;
//        l.rem();
//        l.rem();
//        l.rem();
//        l.rem();
//    }
//    catch (const std::bad_alloc& e) {
//        std::cerr << "������ ������: " << e.what() << std::endl;
//    }
//    catch (const std::underflow_error& e) {
//        std::cerr << "������: " << e.what() << std::endl;
//    }
//    catch (const std::out_of_range& e) {
//        std::cerr << "������: " << e.what() << std::endl;
//    }
//    catch (...) {
//        std::cerr << "����������� ������" << std::endl;
//    }
//
//    return 0;
//}