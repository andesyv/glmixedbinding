
#pragma once


#include <ostream>
#include <bitset>
#include <sstream>

#include <glmixedbinding-aux/Meta.h>


namespace glmixedbinding { namespace aux
{


template <typename T>
std::string bitfieldString(T value)
{
    std::bitset<sizeof(glmixed::GLbitfield) * 8> bits(static_cast<glmixed::GLbitfield>(value));

    std::stringstream ss;
    bool first = true;

    for (size_t i = 0; i < sizeof(glmixed::GLbitfield) * 8; ++i)
    {
    if (!bits.test(i))
        continue;

    if (first)
        {
            first = false;
        }
        else
        {
            ss << " | ";
        }

    const glmixed::GLbitfield bit = 1 << i;

    const auto identifier = glmixedbinding::aux::Meta::getString(static_cast<T>(bit));
    if (identifier.empty())
    {
        ss << "1 << " << i;
    }
    else
    {
        ss << identifier;
    }
    }
    return ss.str();
}

std::string wrapString(const char * value);


} } // namespace glmixedbinding::aux
