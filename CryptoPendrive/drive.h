#pragma once
#include <windows.h>
#include <stdio.h>
#include <iostream>



class drive
{
public:
	drive(void);
	~drive(void);
	static int ReadSector(int numSector,char* buf);
};

