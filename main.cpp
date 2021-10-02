/*=========================================================
//HW#: Assignment 1
//Your name: Justin Butler and David Farjon
// Date : September 2021
//Complier:  g++
//File type: client program
//===========================================================*/

#include <chrono>
#include <iostream>
#include <iomanip>
#include "ReadyQueue.h"
/**
 * This program implements a ready queue. This will sort inputs of integers/pcb's
 * into a queue in largest -> smallest order. 
 * It does this by adding and removing PCB's into an array and sorting them.
 * 
 * Commands
 * Add an element: queueName.addPCB(int a) or queueName.addPCB(PCB a)
 * Remove an element: queueName.removePCB() - this will also return the largest element
 * Print all elements INCLUDING RUNNING/TERMINATED PCB's: queueName.print()
 * Print all READY elements - queueName.display();
 * View the size of the current queue - queueName.size()
 * 
 */
int main(int argc, char *argv[])
{
	//Print basic information about the program
	srand(time(NULL));
	std::cout << "CS 433 Programming assignment 1" << std::endl;
	std::cout << "Author: Justin Butler and David Farjon" << std::endl;
	std::cout << "Date: 09/07/2021" << std::endl;
	std::cout << "Course: CS433 (Operating Systems)" << std::endl;
	std::cout << "Description : Program to implement a priority ready queue of processes" << std::endl;
	std::cout << "=================================" << std::endl;

	std::cout << "Performing Test 1" << std::endl;
	ReadyQueue q1(15);
	int process[] = {15, 6, 23, 39, 8}; // step 1.
	for (int i = 0; i < 5; i++)
	{
		q1.addPCB(PCB(i, process[i], NEW));
	}
	std::cout << "Queue 1" << std::endl;
	q1.display();
	q1.removePCB();
	std::cout << "remove the process with the highest priority from Queue 1 and display Queue 1" << std::endl;
	q1.display();
	std::cout << std::endl;
	int process2[] = {47, 1, 37, 5}; // step 3.
	for (int i = 0; i < 4; i++)
	{
		q1.addPCB(PCB(i, process2[i], NEW));
	}
	std::cout << "add processes 47, 1, 37 and 5 into Queue 1, and display Queue 1" << std::endl;
	q1.display();
	std::cout << "Remove One: " << std::endl;
	q1.removePCB(); // step 4.
	q1.display();
	std::cout << "size of q1: " << q1.size() << std::endl;
	int process3[] = {43, 17, 32, 12, 19}; // step 5.
	for (int i = 0; i < 5; i++)
	{
		q1.addPCB(PCB(i, process3[i], NEW));
	}
	std::cout << "add processes 43, 17, 32, 12 and 19 to Queue 1 and display Queue 1 " << std::endl;
	q1.display(); // original array
	std::cout << "One by one remove" << std::endl;
	for (int i = q1.size(); i > 0; i--) // step 6.
	{
		q1.removePCB();
		q1.display();
	}
	std::cout << std::endl;

	std::cout << "Performing Test 2" << std::endl;
	ReadyQueue q2 = ReadyQueue();
	for (int i = 0; i < 100; i++)
	{
		q2.addPCB((rand() % 50 + 1));
	}
	using namespace std::chrono;
	auto start = high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++)
	{
		if (rand() & 1) // generate a random boolean
		{
			q2.removePCB();
		}
		else
		{
			q2.addPCB(PCB(i, (rand() % 50 + 1), NEW)); // add a PCB with a random priority in New State.
		}
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << std::setprecision(5) << (duration.count() / 1000000.0) << " seconds" << std::endl;
	std::cout << "The size of q2 is " << q2.size() << std::endl;
	q2.display();
	return 0;
}