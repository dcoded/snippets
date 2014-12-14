#pragma once
#ifndef INCLUDE_LISTENER_H
#define INCLUDE_LISTENER_H

template <typename T>
class listener {
public:
    virtual void recv (const T message) = 0;
};

#endif

/* METRICS: bits sent, bits recv'd, # of retransmissions */