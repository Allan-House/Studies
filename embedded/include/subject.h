#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <memory>
#include <vector>

#include "observer.h"

/**
 * \class Subject
 * \brief Subject template for the observer pattern.
 * \tparam Data The type of data passed to observers on notification.
 */
template <class Data>
class Subject {
  public:
  virtual ~Subject() {};

  /**
   * \brief Attaches an observer to this subject.
   * \param observer A shared pointer to the observer to attach.
   */
  void Attach(std::shared_ptr<Observer<Data>> observer) {
    observers_.push_back(std::weak_ptr<Observer<Data>>(observer));
  }

  /**
   * \brief Detaches an observer from this subject.
   * \param observer A shared pointer to the observer to detach.
   */
  void Detach(std::shared_ptr<Observer<Data>> observer) {
      std::erase_if(observers_,
        [&observer](const std::weak_ptr<Observer<Data>>& wp) {
          return wp.lock() == observer;
      });
  }

  /**
   * \brief Notifies all attached observers with the provided data.
   * \param data Pointer to the data to pass to each observer.
   */
  void Notify(Data* data) {
    auto it = observers_.begin();
    while (it != observers_.end()) {
      if (auto observer = it->lock()) {
        observer->Update(data);
        ++it;
      }
      else {
        // Clean up expired observers. 
        it = observers_.erase(it);
      }
    }
  }

 private:
  /**
   * \brief Vector of weakly-referenced observers.
   *
   * Weak pointers are used to avoid extending the lifetime of observers
   * beyond their intended scope.
   */
  std::vector<std::weak_ptr<Observer<Data>>> observers_;
};

#endif
