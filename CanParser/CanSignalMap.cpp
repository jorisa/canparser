#include "stdafx.h"
#include "CanSignalMap.h"

CanSignalMap::CanSignalMap(uint8_t offset, CanSignal * signal) : _offset(offset), _signal(signal)
{
}

CanSignalMap::~CanSignalMap()
{

}

uint64_t CanSignalMap::read()
{
	return ((uint64_t)_signal->read()) << _offset;
}

void CanSignalMap::write(uint64_t data)
{
	_signal->write((uint32_t)(data >> _offset));
}

uint8_t CanSignalMap::offset()
{
	return _offset;
}

CanSignal * CanSignalMap::signal()
{
	return _signal;
}
