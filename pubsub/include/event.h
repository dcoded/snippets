#pragma once
#ifndef INCLUDE_EVENT_H
#define INCLUDE_EVENT_H

#include <vector>
#include <functional>

#include <listener.h>

template <typename T>
class event {
protected:
    std::vector <listener<T>*> listeners_;
public:
    event ();
    ~event ();

    virtual void subscribe (listener<T>* ln);
    virtual void publish (const T& message) const;

    const std::vector <listener<T>*> listeners () const;
};

template <typename T>
event<T>::event () {}

template <typename T>
event<T>::~event () {}

template <typename T>
void event<T>::subscribe (listener<T>* ln) {
    listeners_.push_back (ln);
}

template <typename T>
void event<T>::publish (const T& message) const {
    for (auto& listener : listeners_)
        listener->recv (message);
}

#endif