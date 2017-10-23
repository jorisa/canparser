#include "stdafx.h"
#include "CanSignal.h"


CanSignal::CanSignal(char * name, uint8_t length, char * unit, char * comment) :
	_length(length), _name(name), _unit(unit), _comment(comment)
{
	_value = 0;
	_isValid = false;
}

CanSignal::~CanSignal()
{
}

void CanSignal::write(uint32_t value)
{
	uint32_t mask;
	int sizeInBits = sizeof(mask) * 8; // BITS_PER_BYTE = 8;
	mask = (_length >= sizeInBits ? -1 : (1 << _length) - 1);

	_value = value & mask;
}

int CanSignal::read()
{
	return _value;
}

bool CanSignal::isValid()
{
	return _isValid;
}

void CanSignal::debugPrint()
{
	printf("    %-20s [%2d]: %4d\n", _name, _length, _value);
}
