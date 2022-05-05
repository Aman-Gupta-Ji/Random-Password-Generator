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

// 2. forward declaration (also see later)
void toClipboard(HWND hwnd, const std::string &s);

int main (){

	using namespace std;

	string AAA;

	cout <<"Please enter sentence: "; cin >> AAA;
	cout << endl;
	cout << endl;
	cout << "This has been copied to the clipboard: ";
	cout << AAA << endl;
	// 1. strlen takes a const char*, so have to call the strings c_str() method
	// (but it would be better to use len = AAA.length() instead)
	size_t len = strlen(AAA.c_str());
	cout << len << " char(s)" << endl;
	// get desktop windows and the call toClipboard
	HWND hwnd = GetDesktopWindow();
	toClipboard(hwnd, AAA);
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();

	return 0; 
}

// 2. declare functions at file scope 
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
