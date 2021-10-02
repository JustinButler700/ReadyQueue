#include <iostream>
#include "ReadyQueue.h"
using namespace std;
// ====================================================
//Assignment 1
//Your name: Justin Butler and David Farjon
//Complier:  g++
//File type: Ready Queue Implementation File
//=====================================================

/**
 * ReadyQueue is a queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue here such that the process with the highest priority
 * can be selected next.
 */

//PURPOSE: Constructs a new array of PCB's with a given passed capacity
//PARAMETER: capacity is the maximum array size
ReadyQueue::ReadyQueue()
{
    this->capacity = 3000; // If not given a capacity, set default to 3000. (Anything higher will be caught in overflow)
    arr = new PCB[capacity];
    this->idCount = 0;
    this->mySize = 1; //mySize is all PCB's that are in the Ready state
}
//PURPOSE: Constructs a new array of PCB's with a given passed capacity
//PARAMETER: capacity is the maximum array size
ReadyQueue::ReadyQueue(int capacity)
{
    this->idCount = 0;
    this->capacity = capacity; // Capacity is the real initiated size of the array
    arr = new PCB[capacity];
    this->mySize = 1; //mySize is all PCB's that are in the Ready state
}
//PURPOSE: Deconstructor for our readyqueue
ReadyQueue::~ReadyQueue() {}

//PURPOSE: Returns the size of the array (All PCBs that are not terminated are considered elements)
int ReadyQueue::size()
{
    return mySize - 1;
}
/*Purpose: It adds a new PCB to the end of the array, and then re-sorts the array to the correct order.*/
// It takes in an int representing the priority value
void ReadyQueue::addPCB(int _priority)
{
    if (mySize >= capacity)
    {
        throw Overflow();
    }
    idCount++;
    arr[mySize] = PCB(idCount, _priority, READY);
    mySize++;                                                //increment the size of the array
    if (arr[mySize - 1].priority < arr[mySize - 2].priority) // checks if the array is already in sorted order or not.
    {
        sort();
    }
}
/*Purpose: Overloaded function, Add PCB handles the case that the user wants to add a PCB obj rather than an int.
            It adds a new PCB to the end of the array, and then re-sorts the array to the correct order.*/
void ReadyQueue::addPCB(PCB _myPcb)
{
    if (mySize >= capacity)
    {
        throw Overflow();
    }
    _myPcb.setState(READY);
    idCount++;
    _myPcb.id = idCount;
    arr[mySize] = _myPcb;
    mySize++;                                                //increment the size of the array
    if (arr[mySize - 1].priority < arr[mySize - 2].priority) // checks if the array is already in sorted order or not.
    {
        sort();
    }
}
//PURPOSE Swap the posistions of two PCB's on the PCB array
// a manual swap function vs std::swap yields a small performance boost.
void ReadyQueue::swap(PCB *a, PCB *b)
{
    PCB temp = *a;
    *a = *b;
    *b = temp;
}
//Purpose: Implements a gnome sort to sort the queue in the correct order.
/*
A gnome sort is a very simple sortation algo and is similar to an insertion sort/bubble sort.
it utilizes swapping pointer values to properly order a given array. For more details as to why
I chose this please look to my report.
*/
void ReadyQueue::sort()
{
    int i = 0;
    while (i < mySize)
    {
        if (i == 0)
            i++;
        if (arr[i].priority >= arr[i - 1].priority)
            i++;
        else
        {
            swap(&arr[i], &arr[i - 1]);
            i--;
        }
    }
}
//Purpose: Remove the PCB of the highest priority from the queue and
// return its priority value
int ReadyQueue::removePCB()
{
    if (mySize < 0)
    {
        return 0;
    }
    int max = arr[mySize - 1].priority;
    arr[mySize - 1].setState(RUNNING);
    arr[mySize - 1].priority = INT16_MAX;
    mySize--;
    return max; // returns stored balue
}
//Purpose:: Displays all elements in the ready queue including invisible / terminated / running elements
void ReadyQueue::print()
{
    for (int i = mySize; i >= 0; i--)
    {
        std::cout << "Priority: " << arr[i].priority << "  ID " << arr[i].id;
        if (arr[i].state == READY)
        {
            std::cout << " State: READY" << std::endl;
        }
        else if (arr[i].state == RUNNING)
        {
            std::cout << " State: RUNNING" << std::endl;
        }
        else if (arr[i].state == TERMINATED)
        {
            std::cout << " State: TERMINATED" << std::endl;
        }
        else if (arr[i].state == NEW)
        {
            std::cout << " State: NEW" << std::endl;
        }
    }
    std::cout << std::endl;
}
//Purpose:: Print only the items in the priority queue in the READY state
void ReadyQueue::display()
{
    for (int i = mySize; i >= 0; i--)
    {
        if (arr[i].state == READY)
            std::cout << "Priority: " << arr[i].priority << "  ID " << arr[i].id << " State: READY" << std::endl;
    }
    std::cout << std::endl;
}
