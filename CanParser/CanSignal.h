#pragma once

#include "stdafx.h"
#include "CanMessage.h"

class CanMessage;

class CanSignal
{
public:
	CanSignal(char * name, uint8_t length, char * unit, char * comment);
	~CanSignal();

	void write(uint32_t value);
	int read();
	bool isValid();
	void debugPrint();

public:
	/** A shorthand for Write() */
	CanSignal& operator= (uint32_t value) {
		write(value);
		return *this;
	}

	/** A shorthand for Read() */
	operator uint32_t() {
		return read();
	}

private:
	// Live Values
	uint32_t _value;
	bool _isValid;
	
	// Constants
	const char * const _name;
	const char * const _comment;
	const char * const _unit;
	const uint32_t _length;
};

