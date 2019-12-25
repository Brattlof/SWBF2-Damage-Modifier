#include <Windows.h>
#include <iostream>
#include "Offsets.h"

int main()
{
	DWORD pid;
	GetWindowThreadProcessId(FindWindowA(NULL, "star wars battlefront ii"), &pid);
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	byte* shellcode = new byte[6]{ 0xb9, 0x00, 0x00, 0x00, 0x00, 0x90 };

	int newDamage = 1;

	for (;;)
	{
		if (sizeof(DWORD_PTR) == 4)
		{
			std::cout << "Must build in x64" << std::endl;
		}
		else
		{

			std::cout << "L1lPump H00k\n\n\n";

			std::cout << "Current multiplier value = " << newDamage << "\n\n\n";

			std::cout << "> Enter new multiplier value: ";
			if (std::cin >> newDamage) {
				system("CLS");
			}

			memcpy(shellcode + 1, &newDamage, 4);
			WriteProcessMemory(hProc, (LPVOID)OFFSET_XDMG, shellcode, 6, nullptr);
		}
	}
}