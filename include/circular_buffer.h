#include <cstddef>
#include <iostream>
#include <memory>
#include <mutex>

template <class T>
class CircularBuffer {
  public:
    explicit CircularBuffer(size_t size) :
      buffer_{std::unique_ptr<T[]>(new T[size])},
      max_size_{size}
    {
      std::cout << "Circular buffer of size " << max_size_ << std::endl;
    }
    
    CircularBuffer() : 
      CircularBuffer(kDefaultSize)
    {
      // empty constructor
    }
    
    void add(T data);
    T get();
    void reset();
    bool empty() const;
    bool full() const;
    size_t capacity() const;
    size_t size() const;

  private:
    static constexpr size_t kDefaultSize{1024};
    
    std::unique_ptr<T[]> buffer_;
    std::mutex mutex_;

    size_t head_ = 0;
    size_t tail_ = 0;
    const size_t max_size_;
    bool full_ = false;
};