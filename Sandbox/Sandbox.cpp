#include <Nixalis.h>
#include <iostream>

class Sandbox : public Nixalis::Application
{
public:
    Sandbox()
    {
        Hello();
    }
    ~Sandbox()
    {

    }
};

Nixalis::Application* Nixalis::CreateApplication()
{
    std::cout << "Creating Sandbox Application" << std::endl;
    return new Sandbox();
}
