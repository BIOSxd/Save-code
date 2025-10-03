#include <iostream>
#include <exception>

class Err : public std::exception {
    std::string msg;
public:
    Err(const std::string& s) : msg(s) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class MathErr : public Err {
public:
    MathErr(const std::string& s) : Err("Math Error: " + s) {}
};

class MemErr : public Err {
public:
    MemErr(const std::string& s) : Err("Memory Error: " + s) {}
};

class FileErr : public Err {
public:
    FileErr(const std::string& s) : Err("File Error: " + s) {}
};

int main() {
    setlocale(0, "ru");
    try {
        throw MathErr("Деление на ноль");
    }
    catch (const Err& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        throw MemErr("Нехватка памяти");
    }
    catch (const Err& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        throw FileErr("Файл не найден");
    }
    catch (const Err& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}