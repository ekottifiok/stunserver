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

#include "../common/hresult.h"
#include "../common/commonincludes.hpp"
#include "main.h"

int main(int argc, char** argv)
{
    // HRESULT_H hr = S_OK;
    StartupArgs args;
//     std::vector<StartupArgs> argsVector;
//     int serverindex = 1;

//     typedef CRefCountedPtr<CStunServer> UdpServerPtr;
//     typedef CRefCountedPtr<CTCPServer> TcpServerPtr;

//     std::vector<UdpServerPtr> udpServers;
//     std::vector<TcpServerPtr> tcpServers;

//      // block sigpipe so that socket send calls from raising SIGPIPE
    signal(SIGPIPE, SIG_IGN);
    // BlockSignal(SIGPIPE);

//     // Block SIGTERM and SIGINT such that the child threads will never get that signal (so that subsequent WaitForAppExitSignal hooks on *this* thread)
//     BlockSignal(SIGTERM);
//     BlockSignal(SIGINT);


// #ifdef DEBUG
//     Logging::SetLogLevel(LL_DEBUG);
// #else
//     Logging::SetLogLevel(LL_ALWAYS);
// #endif


//     hr = ParseCommandLineArgs(argc, argv, 1, &args);
//     if (FAILED(hr))
//     {
//         PrintUsage(true);
//         return -1;
//     }

//     if (args.strHelp.length() > 0)
//     {
//         PrintUsage(false);
//         return -2;
//     }

//     if (args.strVerbosity.length() > 0)
//     {
//         int loglevel = (uint32_t)atoi(args.strVerbosity.c_str());

//         if (loglevel >= 0)
//         {
//             Logging::SetLogLevel((uint32_t)loglevel);
//         }
//     }

//     if (args.strConfigFile.empty() == false)
//     {
//         hr = LoadConfigsFromFile(args.strConfigFile, argsVector);
//         if (FAILED(hr))
//         {
//             Logging::LogMsg(LL_ALWAYS, "Can't process configuration file");
//             return -3;
//         }
//     }
//     else
//     {
//         argsVector.push_back(args);
//     }

//     if (SUCCEEDED(hr))
//     {
//         for (std::vector<StartupArgs>::iterator itor = argsVector.begin(); itor != argsVector.end(); itor++)
//         {
//             CStunServerConfig config;
//             StartupArgs args = *itor;

//             Logging::LogMsg(LL_DEBUG, "Starting server %d", serverindex);
//             serverindex++;

//             ::DumpStartupArgs(args);
//             hr = BuildServerConfigurationFromArgs(args, &config);
//             if (FAILED(hr))
//             {
//                 Logging::LogMsg(LL_ALWAYS, "Error building configuration from options given");
//                 break;
//             }
//             DumpConfig(config);

//             if (config.fTCP)
//             {
//                 TcpServerPtr spTcpServer;
//                 hr = StartTCP(spTcpServer, config);

//                 if (SUCCEEDED(hr))
//                 {
//                     tcpServers.push_back(spTcpServer);
//                 }
//             }
//             else
//             {
//                 UdpServerPtr spUdpServer;
//                 hr = StartUDP(spUdpServer, config);
//                 if (SUCCEEDED(hr))
//                 {
//                     udpServers.push_back(spUdpServer);
//                 }
//             }

//             if (FAILED(hr))
//             {
//                 break;
//             }
//         }
//     }


//     if (SUCCEEDED(hr))
//     {
//         Logging::LogMsg(LL_DEBUG, "Successfully started server.");
//         WaitForAppExitSignal();
//     }


//     Logging::LogMsg(LL_DEBUG, "Server is exiting");


//     for (std::vector<UdpServerPtr>::iterator itor = udpServers.begin(); itor != udpServers.end(); itor++)
//     {
//         Logging::LogMsg(LL_DEBUG, "Shutting down UDP server");
//         UdpServerPtr server = *itor;
//         server->Stop();
//     }

//     for (std::vector<TcpServerPtr>::iterator itor = tcpServers.begin(); itor != tcpServers.end(); itor++)
//     {
//         Logging::LogMsg(LL_DEBUG, "Shutting down TCP server");
//         TcpServerPtr server = *itor;
//         server->Stop();
//     }

    return 0;
}

