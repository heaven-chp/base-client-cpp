#include <iostream>
using namespace std;

#include "FileLog.h"
#include "Singleton.h"
#include "ParentProcess.h"
#include "EnvironmentVariable.h"
#include "SocketClientChildProcess.h"

#include "Main.h"

bool Main::Run(int iArgc, char *pcArgv[])
{
	DEBUG_G(__PRETTY_FUNCTION__);

	if(Singleton<EnvironmentVariable>::Instance().Initialize(iArgc, pcArgv) == false) {
		ERROR_L_G(Singleton<EnvironmentVariable>::Instance().Usage());
		return false;
	}

	if(ParentProcess(make_unique<SocketClientChildProcess>()).Start() == false) {
		ERROR_L_G("UserJob Start fail");
		return false;
	}

	return true;
}