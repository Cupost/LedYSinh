#ifndef Led_H
#define Led_H
#include "Struct.h"
typedef struct
{
    Status Status;
    Power_Level Power_Level;
}LED;


void Led_ChangePower();
void Led_Status();

extern LED *Led; 

#endif