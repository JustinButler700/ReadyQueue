// ====================================================
//Assignment 1
//Your name: Justin Butler and David Farjon
//Complier:  g++
//File type: Ready Queue Header File
//=====================================================
#pragma once
#include "PCB.h"
#include <stdio.h>
/**
 * ReadyQueue is a queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue here such that the process with the highest priority
 * can be selected next.
 */
class ReadyQueue
{
private:
	PCB *arr;				   // Initialize an empty array of PCB values
	int idCount;			   //Create a unique ID for each PCB
	int capacity;			   // hold the maximum size capacity of the array
	int mySize;				   // holds the number of elements in the array at current time
	void sort();			   //Purpose: Implements a gnome sort to sort the queue in the correct order.
	void swap(PCB *a, PCB *b); // swap two PCB pointers on the array.
public:
	int removePCB();			// remove and return the PCB with the highest priority from the queue
	void addPCB(int _priority); // add a PCB with a passed integer priority to the queue
	void addPCB(PCB _myPcb);	// adds a new PCB to the array representing a process in the ready queue
	void print();				// print only the items in the queue in the ready state

	// Returns the number of elements in the queue.
	int size();

	void display();			  // Prints the queue contents
	ReadyQueue();			  //PURPOSE: Constructs a new array of PCB's with a given initial capacity of 102 nodes.
	ReadyQueue(int capacity); //PURPOSE: Constructs a new array of PCB's with a given passed capacity
	~ReadyQueue();			  //destructor
	class Overflow			  // when the PCB array has too many values, handle with overflow
	{
	};
	class Underflow // when the PCB array has <0 values, handle with underflow
	{
	};
};
