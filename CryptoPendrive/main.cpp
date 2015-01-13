#include <windows.h>
#include <stdio.h>
#include <iostream>
#include "drive.h"

using namespace std;




int main()
{
	cout << "WItam " << endl;

	char buffor[512] ;
	drive::ReadSector(0, buffor);
	for(int i = 0; i < 512; i++)
	{
		cout << buffor[i];

	}

	getchar();
	return 0;
}
