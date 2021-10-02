#pragma once
// ====================================================
//Assignment 1
//Your name: Justin Butler and David Farjon
//Complier:  g++
//File type: PCB Queue Header File
//=====================================================

// enum class of process state
// A process (PCB) in ready queue should be in READY state
enum ProcState
{
	NEW = 0, //Given that enums are integer types, i initiated them to integer values incase I want to compare values in the future
	READY = 1,
	RUNNING = 2,
	WAITING = 3,
	TERMINATED = 4
};
/* 
Process control block(PCB) is a data structure representing a process in the system.
A process should have at least an ID and a state(i.e.NEW, READY, RUNNING, WAITING or TERMINATED).
It may also have other attributes, such as scheduling information (e.g. priority)
*/
class PCB
{
public:
	ProcState state;
	// The unique process ID
	int id;
	// The priority of a process valued between 1-50. Larger number represents higher priority
	int priority;
	// The current state of the process.
	// A process in the ReadyQueue should be in READY state

	//Purpose: Constructs a new PCB with the given passed values for its id, priority value and state. checking if the priority value is in valid range (1-50)
	PCB(int _id = 0, int _priority = 0, ProcState _state = NEW);
	//Purpose: Returns the state of the current PCB
	int getState();
	// Purpose: sets the PCB state to a new ENUM value
	void setState(ProcState _state);
};
