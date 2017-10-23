#pragma once

#include "stdafx.h"
#include "CanSignal.h"

class CanSignal;

class CanSignalMap
{
public:
    CanSignalMap(uint8_t offset, CanSignal * signal);
    ~CanSignalMap();

    uint64_t read();
    void write(uint64_t data);
    uint8_t offset();
    CanSignal * signal();

private:
    uint8_t _offset;
    CanSignal * _signal;
};

