#include <vector>
#include <stdexcept>
#include "stack.h"


template <typename T> Stack<T>::Stack() : std::vector<T>(){

}

template <typename T>
bool Stack<T>::empty() const{
    return this->empty();
}
template <typename T>
size_t Stack<T>::size() const{
    return this->size();
}

template <typename T>
void Stack<T>::push(const T& item){
    this->push_back(item);
}
template <typename T>
void Stack<T>::pop(){
    if(empty()){
        throw std::underflow_error("empty list");
        return;
    }
    this->pop_back()
}
template <typename T>
const T& Stack<T>::top() const{
    if(empty()){
        throw std::underflow_error("empty list");
        return;
    }
    this->back();
}