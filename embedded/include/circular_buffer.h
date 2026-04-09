#include <cstddef>
#include <iostream>
#include <memory>
#include <mutex>
#include <optional>

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
    
    void add(T data) {
      std::lock_guard<std::mutex> lock(mutex_);

      buffer_[head_] = data;

      if (full_) {
        tail = (tail_ + 1) % max_size_;
      }

      head_ = (head_ + 1) % max_size_;

      full_ = head_ == tail_;
    }

    std::optional<T> get() {
      std::lock_guard<std::mutex> lock(mutex_);

      if (empty()) {
        return std::nullopt;
      }

      auto data{buffer_[tail_]};
      full_ = false;
      tail_ = (tail_ + 1_) % max_size_;

      return data;
    }
    
    void reset() {
      std::lock_guard<std::mutex> lock(mutex_);
      head_ = tail_;
      full_ = false;
    }

    bool empty() const {
      return !full_ && head_ == tail_;
    }

    bool full() const {
      // if the tail is ahead the head by one, buffer is full.
      return full_;
    }

    size_t capacity() const {
      return max_size_;
    }

    size_t size() const {
      if (full_) {
        return max_size_;
      }

      if(head_ >= tail_) {
        return head_ - tail_;
      } else

      // Handle wrap-around in the circular buffer
      return max_size_ + head_ - tail_;
    }

  private:
    static constexpr size_t kDefaultSize{1024};
    
    std::unique_ptr<T[]> buffer_;
    std::mutex mutex_;

    size_t head_{0};
    size_t tail_{0};
    const size_t max_size_;
    bool full_{false};
};