/*
   Copyright 2011 John Selbie

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef STUN_SERVER_UTILS_H
#define	STUN_SERVER_UTILS_H

#include "commonincludes.hpp"
#include "stuncore.h"
#include "server.h"
#include "tcpserver.h"
#include "adapters.h"
#include "cmdlineparser.h"

#include <getopt.h>

#include "prettyprint.h"
#include "oshelper.h"
#include "stringhelper.h"



struct StartupArgs
{
    std::string strMode;
    std::string strPrimaryInterface;
    std::string strAltInterface;
    std::string strPrimaryPort;
    std::string strAltPort;
    std::string strPrimaryAdvertised;
    std::string strAlternateAdvertised;
    std::string strFamily;
    std::string strProtocol;
    std::string strHelp;
    std::string strVerbosity;
    std::string strMaxConnections;
    std::string strDosProtect;
    std::string strConfigFile;
    std::string strReuseAddr;

};

void PrintUsage(bool fSummaryUsage);
char* strerror_helper(int result, char* msg, int err);
char* strerror_helper(char* pszResult, char*, int);
void LogHR(uint16_t level, HRESULT hr);
void DumpStartupArgs(StartupArgs& args);
void DumpConfig(CStunServerConfig &config);
HRESULT ResolveAdapterName(bool fPrimary, int family, std::string& strAdapterName, uint16_t port, CSocketAddress* pAddr);
HRESULT BuildServerConfigurationFromArgs(StartupArgs& argsIn, CStunServerConfig* pConfigOut);
HRESULT ParseCommandLineArgs(int argc, char** argv, int startindex, StartupArgs* pStartupArgs);
HRESULT LoadConfigsFromFile(const std::string& filename, std::vector<StartupArgs>& configurations);
HRESULT BlockSignal(int sig);
void WaitForAppExitSignal();
HRESULT StartUDP(CRefCountedPtr<CStunServer>& spServer, CStunServerConfig& config);
HRESULT StartTCP(CRefCountedPtr<CTCPServer>& spTCPServer, CStunServerConfig& config);

#endif /* UTILS */