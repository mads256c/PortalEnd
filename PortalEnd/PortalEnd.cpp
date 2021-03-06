// PortalEnd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

#include <Windows.h>
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

std::wstring path;

void SlowType(const std::string input)
{
	for (const auto c : input)
	{
		std::cout << c;
		Sleep(100);
	}
}

void ShowFile(const std::wstring input)
{
	system("cls");

	std::fstream file(path + L"\\" + input);

	while(file.good())
	{
		std::cout << static_cast<char>(file.get());
	}
}

int main()
{
	TCHAR dest[MAX_PATH];

	GetModuleFileName(NULL, dest, MAX_PATH);
	PathRemoveFileSpec(dest);

	path = std::wstring(dest);

	std::fstream stillAlive(path + L"\\StillAlive.txt");
	

	if (stillAlive.is_open())
	{
		while(stillAlive.good())
		{
			char line[256];
			stillAlive.getline(line, 256);

			if (strcmp(line, ".") == 0)
			{
				Sleep(1000);
			}
			else
			{
				if (strcmp(line, "Aperture Science.") == 0)
				{
					ShowFile(L"ApertureLogo.txt");
				}
				if (strcmp(line, "Maybe Black Mesa") == 0)
				{
					ShowFile(L"BlackMesa.txt");
				}
				if (strcmp(line, "Anyway, this cake is great.") == 0)
				{
					ShowFile(L"Cake.txt");
				}
				if (strcmp(line, "Even though you broke my heart.") == 0)
				{
					ShowFile(L"Heart.txt");
				}

				SlowType(line);
				std::cout << std::endl;
			}
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
