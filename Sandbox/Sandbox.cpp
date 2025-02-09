#include <Nixalis.h>

class Sandbox : public Nixalis::Application
{
public:
    Sandbox()
    {

    }
    ~Sandbox()
    {

    }
};

Nixalis::Application* Nixalis::CreateApplication()
{
    return new Sandbox();
}
