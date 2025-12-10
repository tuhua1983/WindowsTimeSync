#include <cstdlib>
#include <Windows.h>
#include <fstream>
#include <ctime>
using namespace std;
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
	system("sc start w32time >nul 2>&1");
	system("w32tm /resync");
	ofstream log(L"time_sync_log.txt", ios::app);
	char dt[32];
	time_t now = time(nullptr);
	ctime_s(dt, sizeof(dt), &now);
	log << dt << "\tOK\n";
	log.close();
	return 0;
}