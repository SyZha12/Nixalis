#ifndef LAYER_H
#define LAYER_H

#include <string>

namespace Nixalis
{
    class Layer
    {
    public:
        explicit Layer(std::string_view name = "Layer");
        virtual ~Layer();

        virtual void OnAttach();
        virtual void OnDetach();
        virtual void OnUpdate();
        virtual void OnRender();
    private:
        std::string m_Name;
    };
}




#endif //LAYER_H
