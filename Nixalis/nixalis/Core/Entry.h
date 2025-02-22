#ifndef ENTRY_H
#define ENTRY_H

#include "nixalis/Core/Application.h"
#include "nixalis/Core/Log.h"

int main(int argc, char** argv)
{
    Nixalis::Log::Init();

    auto* application = Nixalis::CreateApplication();

    application->Run();

    delete application;

    return 0;
}

#endif //ENTRY_H
