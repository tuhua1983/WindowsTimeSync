#include <cstdlib>
#include <Windows.h>
#include <fstream>
#include <ctime>
using namespace std;
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
	system("net start w32time");
	system("w32tm /resync");
	ofstream log("time_sync_log.txt", ios::app);
	char dt[32];
	time_t* ptr = new time_t(time(nullptr));
	ctime_s(dt, sizeof(dt), ptr);
	delete ptr;
	log << dt << "\tOK\n";
	return 0;
}