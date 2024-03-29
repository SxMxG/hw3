#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()){
    m_ = m;
    c_ = c;
  }

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap(){};

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const{
    return heap.empty();
  }

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const{
    return heap.size();
  }

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heap;
  int m_;
  PComparator c_;

};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty");
  }
  std::swap(heap[0],heap[heap.size()-1]);
  heap.pop_back();
  std::size_t index = 0;
  
  while(index < heap.size()){
    std::size_t childindex = index*m_+1;
    std::size_t swapindex = childindex;
    T& curr = heap[index];
    for(int i = 0;i<m_;i++){//finding max or big child
      if(childindex+i < heap.size()){
        T& comp = heap[childindex+i];
        T& swap = heap[swapindex];
        if(c_(comp,swap)){
          swapindex = childindex+i;
        }
      }else{
        break;
      }
    }
    if(swapindex >= heap.size()){
      break;
    }
    if(c_(heap[swapindex],curr)){//compare with parent and swap
      std::swap(heap[swapindex],curr);
      index = swapindex;
    }else{
      break;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  heap.push_back(item);
  std::size_t index = heap.size()-1;
  while(index != 0){
    std::size_t parindex = (index-1)/m_;
    T& curr = heap[index];
    T& par = heap[parindex];
    if(c_(par,curr) || par == curr){
      break;
    }
    std::swap(curr,par);
    index = parindex;
  }
}



#endif

