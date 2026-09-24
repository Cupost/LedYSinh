#ifndef Wave_H
#define Wave_H
#include "Struct.h"
typedef struct
{
    Status Status;
    Power_Level Power_Level;
}WAVE;


void Wave_ChangePower();
void Wave_Status();

extern WAVE *Wave;

#endif