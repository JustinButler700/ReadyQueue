#include "PCB.h"
// ====================================================
//Assignment 1
//Your name: Justin Butler and David Farjon
//Complier:  g++
//File type: PCB Program implementation file
//=====================================================

/* 
Process control block(PCB) is a data structure representing a process in the system.
A process should have at least an ID and a state(i.e.NEW, READY, RUNNING, WAITING or TERMINATED).
It may also have other attributes, such as scheduling information (e.g. priority)
*/
//Purpose: Constructs a new PCB with the given passed values for its id, priority value and state. checking if the priority value is in valid range (1-50)
PCB::PCB(int _id, int _priority, ProcState _state)
{
    id = _id;
    state = _state;
    if (_priority >= 1 && _priority <= 50)
    {
        priority = _priority;
    }
    else
    {
        state = TERMINATED;
    }
}
// Purpose: sets the PCB state to a new ENUM value
void PCB::setState(ProcState _state)
{
    state = _state;
}
