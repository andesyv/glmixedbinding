
#include <glmixedbinding/State.h>

#include <glmixedbinding/Binding.h>


namespace glmixedbinding
{


void State::resolve(const char * name)
{
    if (m_initialized)
    {
        return;
    }

    m_address = Binding::resolveFunction(name);
    m_initialized = true;
}


} // namespace glmixedbinding