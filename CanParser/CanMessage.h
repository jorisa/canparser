#pragma once

#include "stdafx.h"
#include "CanSignalMap.h"

class CanSignalMap;

class CanMessage
{
public:
	enum IdentifierType {ID_STD, ID_EXT };

public:
	CanMessage(char * name, IdentifierType identifier, uint32_t id, uint8_t length, uint32_t cycleTime, uint8_t numSignals, CanSignalMap signals[]);
	~CanMessage();
	
	void pack();
	void unpack();
	bool isValid();
	void debugPrint();

private:
	// Live Values
	uint32_t lastUpdated;
	uint64_t _data;

	// Constants
	const char * const _name;
	const IdentifierType _identifier;
	const uint32_t _id;
	const uint8_t _length;
	const uint32_t _cycleTime;

	const uint8_t _numSignals;
	CanSignalMap * const _signals;
};

