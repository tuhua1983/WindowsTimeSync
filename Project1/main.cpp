#include <cstdlib>
#include <Windows.h>
#include <fstream>
#include <ctime>
using namespace std;
int main() {
	int ret1 = system("sc start w32time >nul 2>&1");
	int ret2 = system("w32tm /resync >nul 2>&1");
	ofstream log(L"time_sync_log.txt", ios::app);
	char dt[32];
	time_t now = time(nullptr);
	ctime_s(dt, sizeof(dt), &now);
	log << ret1 << "\t" << ret2 << "\t" << dt;
	log.close();
	return 0;
}