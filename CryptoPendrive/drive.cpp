#include "drive.h"


drive::drive(void)
{
}


drive::~drive(void)
{
}

int drive::ReadSector(int numSector,char* buf)
{
    int retCode = 0;
    BYTE sector[512];
    DWORD bytesRead;
    HANDLE device = NULL;

    device = CreateFile("\\\\.\\J:",    // Drive to open
        GENERIC_READ,           // Access mode
        FILE_SHARE_READ,        // Share Mode
        NULL,                   // Security Descriptor
        OPEN_EXISTING,          // How to create
        0,                      // File attributes
        NULL);                  // Handle to template

    if(device != NULL)
    {
        // Read one sector
        SetFilePointer (device, numSector*512, NULL, FILE_BEGIN) ;

        if (!ReadFile(device, sector, 512, &bytesRead, NULL))
        {
            //Print("Error in reading1 floppy disk\n",numligne++);
			std::cout << " ERROR reading disc" ; 
        
		}
        else
        {
            // Copy boot sector into buffer and set retCode
            memcpy(buf,sector, 512);retCode=1;
        }

        CloseHandle(device);
        // Close the handle
    }

    return retCode;
}