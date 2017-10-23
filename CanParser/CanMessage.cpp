#include "stdafx.h"
#include "CanSignal.h"
#include "CanMessage.h"

CanMessage::CanMessage(char * name, IdentifierType identifier, uint32_t id, uint8_t length, uint32_t cycleTime, uint8_t numSignals, CanSignalMap signals[]) :
	_name(name), _identifier(identifier), _id(id), _length(length), _cycleTime(cycleTime), _numSignals(numSignals), _signals(signals)
{
}

CanMessage::~CanMessage()
{
}

void CanMessage::pack()
{
	_data = 0;
	for (int i = 0; i < _numSignals; i++)
	{
		_data |= _signals[i].read();
	}
}

void CanMessage::unpack()
{
	for (int i = 0; i < _numSignals; i++)
	{
		_signals[i].write(_data);
	}
}

void CanMessage::debugPrint()
{
	pack();
	printf("\n[0x%03X] %-20s [%d] %4d ms -", _id, _name, _length, _cycleTime);
	for (int i = 0; i < _length; i++)
	{
		printf(" %02x", (((uint8_t *)&_data)[i]));
	}
	printf("\n");
	for (int i = 0; i < _numSignals; i++)
	{
		uint8_t offset = _signals[i].offset();
		CanSignal * signal = _signals[i].signal();
		signal->debugPrint();
		//printf("Signal %d: Offset %d Value %d \n", i, offset, signal->read());
	}
}

bool CanMessage::isValid()
{
	return false;
}