#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP


class MyVector {
public:
    MyVector();
    MyVector(unsigned int size);
    ~MyVector();
    auto size() -> unsigned int;
    auto at(unsigned int index) -> int;
    //auto push_back(int& new_data, int new_size) -> void;
    //auto push_back(int* new_data, int new_size) -> void;
    auto push_back(int new_data) -> void;
    auto print_vector() -> void;
    auto resize(int new_size) -> int ;
private:
    int* m_data;
    unsigned int m_size;
    unsigned int m_capacity;
};
#endif /* MYVECTOR_HPP */