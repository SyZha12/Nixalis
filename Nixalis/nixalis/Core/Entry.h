#ifndef ENTRY_H
#define ENTRY_H

#include <nixalis/Core/Application.h>

int main(int argc, char** argv)
{
    auto* application = Nixalis::CreateApplication();
    delete application;

    return 0;
}

#endif //ENTRY_H
