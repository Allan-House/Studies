#ifndef OBSERVER_H_
#define OBSERVER_H_

template <class Data>
/**
 * \class Observer.
 * \brief Observer template for the observer pattern. 
 */
class Observer {
 public:
  virtual ~Observer() {};
  virtual void Update(Data* data) = 0;
};

#endif
