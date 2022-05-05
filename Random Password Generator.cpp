#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <Windows.h> // use < > for all system and library headers
#include <winuser.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <complex>
#include <string>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
//selectArray is a utility function that is used to
//randomly generate a integer in the range 1 to 4 (both inclusive)
int selectArray()
{
	srand(time(NULL));
	int i = rand() % 5;
	if (i == 0)
	i++;
	return i;
}
//getKey() is another utility function that is used to randomly generate
//an integer in the range 0 to 25 (both inclusive)
int getKey()
{
	srand(time(NULL)); 
	int key = rand() % 26;
	return key;
}

string generate_password()
{
	int length=15;
	 //Intializing result string password as NULL.
	 string password = "";
	 //Strings whose characters will be used to build password
	 string alphabet = "abcdefghijklmnopqrstuvwxyz";
	 string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	 string s_symbol = "!@#$%&";
	 string number = "0123456789";
	 //initializing local variables
	 int key, count_alphabet = 0, count_ALPHABET = 0, count_number = 0, count_s_symbol =0;
	 //Count will store the length of the password being created,
	 //initially this will be zero(0)
	 int count = 0;
	 while (count < length) 
	 {
		 // selectArray() function will return a number 1 to 4
		 // and will use to select one of the above defined string
		 //(i.e alphabet or ALPHABET or s_symbol or number )
		 // 1 is for string alphabet
		 // 2 is for string ALPHABET 
		 // 3 is for string number
		 // and 4 is for string s_symbol
		 int k = selectArray();
		 //for the first character of password it is mentioned that,
		 //it should be a letter
		 //so the string that should be selected is alphabet (i.e 1)
		 //following if condition will take care of it.
		 if (count == 0) 
		 {
	 		k=1;
		 }
		 if (count == length-1)
		 {
		 	k=2;
		 }
		 switch (k) 
		 {
			 case 1:
				 // following if condition will check if minimum requirement of alphabet
				 // character has been fulfilled or not
				 // in case it has been fulfilled and minimum requirements of other
				 // characters is still left then it will break ;
				 if ((count_alphabet == 2) && (count_number == 0 || count_ALPHABET == 0 ||count_ALPHABET == 1 || count_s_symbol == 0))
				 break;
			 key = getKey();
			 password = password + alphabet[key]; 
			 count_alphabet++;
			 count++;
			 break;
			 case 2:
			 // following if condition will check if minimum requirement of
			 // ALPHABET character has been fulfilled or not
			 // in case it has been fulfilled and minimum requirements of
			 // other characters is still left then it will break ;
			 if ((count_ALPHABET == 2) && (count_number == 0 || count_alphabet == 0 ||count_alphabet == 1 || count_s_symbol == 0))
			 	break;
			 key = getKey();
			 password = password + ALPHABET[key];
			 count_ALPHABET++;
			 count++;
			 break;
			 case 3:
				 // following if condition will check if minimum requirement
				 // of Numbers has been fulfilled or not
				 // in case it has been fulfilled and minimum requirements of
				 // other characters is still left then it will break ;
				 if ((count_number == 1) && (count_alphabet == 0 || count_alphabet == 1 ||count_ALPHABET == 1 || count_ALPHABET == 0 || count_s_symbol == 0))
				 	break;
				 key = getKey(); 
				 key = key % 10;
				 password = password + number[key];
				 count_number++;
				 count++;
				 break;
			 case 4:
				 // following if condition will check if minimum requirement of
				 // Special symbol character has been fulfilled or not
				 // in case it has been fulfilled and minimum requirements of
				 // other characters is still left then it will break ;
				 if ((count_s_symbol == 1) && (count_alphabet == 0 || count_alphabet == 1 ||count_ALPHABET == 0 || count_ALPHABET == 1 || count_number == 0))
				 	break;
				 key = getKey();
				 key = key % 6;
				 password = password + s_symbol[key];
				 count_s_symbol++;
				 count++;
				 break;
		}
	}
	return password;
}

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

void toClipboard(HWND hwnd, const std::string &s){
	OpenClipboard(hwnd);
	EmptyClipboard();
	HGLOBAL hg=GlobalAlloc(GMEM_MOVEABLE,s.size()+1);
	if (!hg){
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg),s.c_str(),s.size()+1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT,hg);
	CloseClipboard();
	GlobalFree(hg);
}
/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "GUI Button",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           600,                 /* The programs width */
           600,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
           
            case WM_CREATE:
                
                CreateWindow(TEXT("button"), TEXT("Click to copy"),
                WS_VISIBLE | WS_CHILD,
                170, 200, 240, 70,
                hwnd, (HMENU) 1, NULL, NULL
                );
                
                case WM_COMMAND:
                     
                     if (LOWORD(wParam) == 1)
                     {
                        MessageBox(hwnd, "Message copied to the click board on clicking here", "Password Copied", MB_OK | MB_ICONINFORMATION);
                        using namespace std;
						string AAA;
                        AAA=generate_password();
                        size_t len = strlen(AAA.c_str());
                        HWND hwnd = GetDesktopWindow();
						toClipboard(hwnd, AAA);

                        }
                     
                     break;
                     
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

