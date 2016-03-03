#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#ifndef _cplusplus_
#include <stdbool.h>
#endif

using namespace std;

const std::string currentTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return buf;
}

std::string getOsName()
{
    #ifdef _WIN32
    return "Windows 32-bit";
    #elif _WIN64
    return "Windows 64-bit";
    #elif __unix || __unix__
    return "Unix";
    #elif __APPLE__ || __MACH__
    return "Mac OSX";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #else
    return "Other";
    #endif
}       





void ngiStart() {
    string appId;
    string cmd = "null";
    std::cout << "\nEnter a command. To see commands list type '/help' ";
    std::cin >> cmd;
    if (cmd == "/help") {
        std::cout << "\n=========================================================\n";
        std::cout << "/help = Shows list of commands \n" ; 
        std::cout << "/info = Shows info about the OS\n" ;
        std::cout << "/applist = Shows list of apps\n" ;
        std::cout << "/shutdown = Shuts down the OS\n";
        std::cout << "/time = Shows current time\n";
        std::cout << "=========================================================";
        ngiStart();
    }else if (cmd == "/info") {
        std::cout << "\n=========================================================\n";
        std::cout << "Name: ElectrOS C++ edition;\nVersion: 0.3.1;\nInterface: NTI (None Graphics Intreface);\nLanguage: English.\nRuns on: " << getOsName() << endl; 
        std::cout << "=========================================================";ngiStart();
    }else if (cmd == "/shutdown") {
        std::cout << "Shuttng down...\n";
        std::cout << "Shutted down! Have a nice day :)";
    }else if (cmd == "/appList") {
        std::cout << "\n=========================================================\n";
        std::cout << "Calculator (id:calc);\nNotes (id:notes);\n";
        std::cout << "=========================================================";
        ngiStart();
    }else if (cmd == "/open") {
        std::cout << "Which application do you want to open? (type an id of app, for example 'calc' or 'notes' ";
        
        cin >> appId;
        if (appId == "calc") {
            
        }else{    
        std::cout << "ERROR: Invaild ID."    ;
        ngiStart();}
    }else if (cmd == "/time") {
        

        std::cout << "It's " << currentTime();
        ngiStart();
    }else{
        std::cout << "ERROR: unknown command. ";
        ngiStart();
    }
}
int main() {
        
        std::cout << "Welcome, " << getOsName() << " user!";
        ngiStart(); 
}
  
