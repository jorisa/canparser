// Application.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

#include "CanSignal.h"
#include "CanSignalMap.h"
#include "CanMessage.h"

class CanReceiverSignals
{
public:
    CanSignal MCLF_SomeSignal       = CanSignal("MCLF_SomeSignal",    8, "mm",  "Some Cool Signal");
    CanSignal MCLF_OtherSignal      = CanSignal("MCLF_OtherSignal",  16, "m/s", "Some Other Cool Signal");
    CanSignal MCLF_Woopy            = CanSignal("MCLF_Woopy",        32, "deg", "Some Woopy Signal");
    CanSignal MCLF_Bool1            = CanSignal("MCLF_Bool1",         1, "",    "Some Woopy Signal");
    CanSignal MCLF_Bool2            = CanSignal("MCLF_Bool2",         1, "",    "Some Woopy Signal");
    CanSignal MCLF_Bool3            = CanSignal("MCLF_Bool3",         1, "",    "Some Woopy Signal");
    CanSignal MCLF_Bool4            = CanSignal("MCLF_Bool4",         1, "",    "Some Woopy Signal");
    CanSignal MCLF_Shorty           = CanSignal("MCLF_Shorty",        4, "",    "Some Woopy Signal");
    CanSignal MCLF_Woopsy           = CanSignal("MCLF_Woopsy",        8, "",    "Some Woopy Signal");
};

class CanReceiverMessages
{
public:
    CanReceiverSignals signals;

    CanMessage MCLF_SomeMessage = CanMessage("MCLF_SomeMessage", CanMessage::ID_STD, 0x100, 8U, 100U, 8, new CanSignalMap[8]{
        CanSignalMap(0U,  &signals.MCLF_SomeSignal),
        CanSignalMap(8U,  &signals.MCLF_OtherSignal),
        CanSignalMap(24U, &signals.MCLF_Woopy),
        CanSignalMap(56U, &signals.MCLF_Bool1),
        CanSignalMap(57U, &signals.MCLF_Bool2),
        CanSignalMap(58U, &signals.MCLF_Bool3),
        CanSignalMap(59U, &signals.MCLF_Bool4),
        CanSignalMap(60U, &signals.MCLF_Shorty),
    });


    CanMessage MCLF_SomeOtherMessage = CanMessage("MCLF_SomeOtherMessage", CanMessage::ID_STD, 0x100, 1U, 100U, 1, new CanSignalMap[1]{
        CanSignalMap(0U, &signals.MCLF_Woopsy),
    });

private:
    CanMessage * _messageTable[2] = {
        &MCLF_SomeMessage,
        &MCLF_SomeOtherMessage
    };

    CanMessage GetById(uint32_t id)
    {
        for (int i = 0; i < 2; i++)
        {

        }
    }

};

int main()
{
    CanReceiverMessages canRx;
    //CanReceiverMessages canTx;

    //canTx.MCLF_SomeOtherMessage.onTransmit(&txHandler);
    //canTx.transmit10ms();

    //canRx.MCLF_SomeMessage.onReceive(&someEventHandler)
    //canRx.MCLF_SomeMessage.onTransmit(&someEventHandler)

    canRx.signals.MCLF_Bool1 = 1;

    canRx.signals.MCLF_SomeSignal = 10;
    canRx.signals.MCLF_OtherSignal = 9;
    canRx.signals.MCLF_Woopy = 100;
    canRx.signals.MCLF_Bool1 = 1;
    canRx.signals.MCLF_Bool2 = 1;
    canRx.signals.MCLF_Shorty = 0xF;

    canRx.MCLF_SomeMessage.debugPrint();
    canRx.MCLF_SomeOtherMessage.debugPrint();
    (void)getc(stdin);

    return 0;
}

