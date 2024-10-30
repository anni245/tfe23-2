#include "myvector.hpp"
#include <fmt/format.h>

MyVector::MyVector() {
    this->m_data = nullptr;
    this->m_size = 0;
}

MyVector::MyVector(unsigned int size) {
    this->m_data = new int[size];
    this->m_size = size;
}

MyVector::~MyVector() {
    if(this->m_data != nullptr) {
        delete [] m_data;
    }
}

auto MyVector::size() -> unsigned int {
    return this->m_size;
}
    
auto MyVector::at(unsigned int index) -> int {
    if(index < this->m_size) {
        return this->m_data[index];
    }
    return -1;
}

auto MyVector::push_back(int new_data) -> void {
    if(this->m_data == nullptr) {
        this->m_data = new int[1];
        this->m_size = 1;
    }
    else {
        this->resize(this->m_size+1);
    }
    this->m_data[this->m_size-1] = new_data;
}

/*auto MyVector::push_back(int* new_data, int new_size) -> void {
    if(this->m_data == nullptr) {
        this->m_data = new int[new_size];
        this->m_size = 0;
    }
    else {
        this->resize(new_size);
    }
    for(int i = this->m_size; i < new_size; i ++) {
        this->m_data = &new_data[i-this->m_size];
    }
    this->m_size = new_size;
}

/*auto MyVector::push_back(int& new_data, int new_size) -> void {
    if(this->m_data == nullptr) {
        this->m_data = new int[new_size];
        this->m_size = 0;
    }
    else {
        this->resize(new_size);
    }
    for(int i = this->m_size; i < new_size; i ++) {
        this->m_data = *new_data[i-this->m_size];
    }
    this->m_size = new_size;
}*/

auto MyVector::resize(int new_size) -> int {
    if (this->m_size == new_size) {
        return 0;
    }

    int* new_data = nullptr;
    try {
        new_data = new int[new_size];
    } catch (const std::bad_alloc&) {
        return -1;
    }

    for (int i = 0; i < this->m_size; i++) {
        new_data[i] = this->m_data[i];
    }

    delete[] this->m_data;
    this->m_data = new_data;
    this->m_size = new_size;

    return 1;
}

auto MyVector::print_vector() -> void {
    for(int i = 0; i < this->m_size; i++) {
        fmt::print("[{}]", this->at(i));
    }
    fmt::print("\nsize: {}", this->m_size);
}