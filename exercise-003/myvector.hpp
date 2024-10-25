#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP


class MyVector {
public:
    MyVector();
    MyVector(unsigned int size);
    ~MyVector();
    auto size() -> int;
    auto at(int value) -> int;
    auto push_back(int new_value) -> void;
private:
    int* m_data;
    unsigned int m_size;
}
#endif /* MYVECTOR_HPP */