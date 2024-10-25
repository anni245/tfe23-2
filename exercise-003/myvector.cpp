#include "myvector.hpp"
#include <fmt/format.h>

MyVector::MyVector() {
    this->m_data = nullptr;
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

}
    
auto MyVector::at(int value) -> int {

}    

auto MyVector::push_back(int new_value) -> void {

}