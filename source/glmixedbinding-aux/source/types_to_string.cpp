
#include <glmixedbinding-aux/types_to_string.h>

#include <ostream>
#include <bitset>
#include <sstream>

#include <glmixedbinding/Version.h>
#include <glmixedbinding-aux/Meta.h>

#include "types_to_string_private.h"


namespace glmixed
{


std::ostream & operator<<(std::ostream & stream, const GLenum & value)
{
    const auto strings = glmixedbinding::aux::Meta::getStrings(value);

    if (strings.size() == 0)
    {
        return stream;
    }

    stream << strings[0];

    for (auto i = static_cast<std::size_t>(1); i < strings.size(); ++i)
        stream << " | " << strings[i];

    return stream;
}

std::ostream & operator<<(std::ostream & stream, const GLboolean & value)
{
    stream << glmixedbinding::aux::Meta::getString(value);

    return stream;
}

std::ostream & operator<<(std::ostream & stream, const GLextension & value)
{
    stream << glmixedbinding::aux::Meta::getString(value);

    return stream;
}

std::ostream & operator<<(std::ostream & stream, const AttribMask & value)
{
    stream << glmixedbinding::aux::bitfieldString<AttribMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const BufferStorageMask & value)
{
    stream << glmixedbinding::aux::bitfieldString<BufferStorageMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const ClearBufferMask & value)
{
    stream << glmixedbinding::aux::bitfieldString<ClearBufferMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const ClientAttribMask & value)
{
    stream << glmixedbinding::aux::bitfieldString<ClientAttribMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const ContextFlagMask & value)
{
    stream << glmixedbinding::aux::bitfieldString<ContextFlagMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const ContextProfileMask & value)
{
    stream << glmixedbinding::aux::bitfieldString<ContextProfileMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const FfdMaskSGIX & value)
{
    stream << glmixedbinding::aux::bitfieldString<FfdMaskSGIX>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const FragmentShaderColorModMaskATI & value)
{
    stream << glmixedbinding::aux::bitfieldString<FragmentShaderColorModMaskATI>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const FragmentShaderDestMaskATI & value)
{
    stream << glmixedbinding::aux::bitfieldString<FragmentShaderDestMaskATI>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const FragmentShaderDestModMaskATI & value)
{
    stream << glmixedbinding::aux::bitfieldString<FragmentShaderDestModMaskATI>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const MapBufferAccessMask & value)
{
    stream << glmixedbinding::aux::bitfieldString<MapBufferAccessMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const MemoryBarrierMask & value)
{
    stream << glmixedbinding::aux::bitfieldString<MemoryBarrierMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const OcclusionQueryEventMaskAMD & value)
{
    stream << glmixedbinding::aux::bitfieldString<OcclusionQueryEventMaskAMD>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const PathFontStyle & value)
{
    stream << glmixedbinding::aux::bitfieldString<PathFontStyle>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const PathMetricMask & value)
{
    stream << glmixedbinding::aux::bitfieldString<PathMetricMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const PerformanceQueryCapsMaskINTEL & value)
{
    stream << glmixedbinding::aux::bitfieldString<PerformanceQueryCapsMaskINTEL>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const SyncObjectMask & value)
{
    stream << glmixedbinding::aux::bitfieldString<SyncObjectMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const TextureStorageMaskAMD & value)
{
    stream << glmixedbinding::aux::bitfieldString<TextureStorageMaskAMD>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const UnusedMask & value)
{
    stream << glmixedbinding::aux::bitfieldString<UnusedMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const UseProgramStageMask & value)
{
    stream << glmixedbinding::aux::bitfieldString<UseProgramStageMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const VertexHintsMaskPGI & value)
{
    stream << glmixedbinding::aux::bitfieldString<VertexHintsMaskPGI>(value);
    return stream;
}


} // namespace glmixed


namespace glmixedbinding
{


template <>
std::ostream & operator<<(std::ostream & stream, const Value<glmixed::GLenum> & value)
{
    stream << value.value();

    return stream;
}

/*template <>
std::ostream & operator<<(std::ostream & stream, const Value<glmixed::GLbitfield> & value)
{
    std::stringstream ss;
    ss << "0x" << std::hex << static_cast<unsigned>(value.value());
    stream << ss.str();

    return stream;
}*/

template <>
std::ostream & operator<<(std::ostream & stream, const Value<glmixed::GLboolean> & value)
{
    const auto & name = aux::Meta::getString(value.value());
    stream.write(name.c_str(), static_cast<std::streamsize>(name.size()));

    return stream;
}

template <>
std::ostream & operator<<(std::ostream & stream, const Value<const char *> & value)
{
    auto s = aux::wrapString(value.value());
    stream.write(s.c_str(), static_cast<std::streamsize>(s.size()));

    return stream;
}


template <>
std::ostream & operator<<(std::ostream & stream, const Value<glmixed::GLchar *> & value)
{
    auto s = aux::wrapString(reinterpret_cast<const char*>(value.value()));
    stream.write(s.c_str(), static_cast<std::streamsize>(s.size()));

    return stream;
}

template <>
std::ostream & operator<<(std::ostream & stream, const Value<glmixed::GLubyte *> & value)
{
    auto s = aux::wrapString(reinterpret_cast<const char*>(value.value()));
    stream.write(s.c_str(), static_cast<std::streamsize>(s.size()));

    return stream;
}


std::ostream & operator<<(std::ostream & stream, const Version & version)
{
    stream << version.toString();

    return stream;
}

std::ostream & operator<<(std::ostream & stream, const AbstractValue * value)
{
    if (typeid(*value) == typeid(AbstractValue))
    {
        return stream << reinterpret_cast<const void*>(value);
    }

    if (typeid(*value) == typeid(Value<char>))
    {
        return stream << *reinterpret_cast<const Value<char>*>(value);
    }

    if (typeid(*value) == typeid(Value<double>))
    {
        return stream << *reinterpret_cast<const Value<double>*>(value);
    }

    if (typeid(*value) == typeid(Value<float>))
    {
        return stream << *reinterpret_cast<const Value<float>*>(value);
    }

    if (typeid(*value) == typeid(Value<int>))
    {
        return stream << *reinterpret_cast<const Value<int>*>(value);
    }

    if (typeid(*value) == typeid(Value<long>))
    {
        return stream << *reinterpret_cast<const Value<long>*>(value);
    }

    if (typeid(*value) == typeid(Value<long long>))
    {
        return stream << *reinterpret_cast<const Value<long long>*>(value);
    }

    if (typeid(*value) == typeid(Value<unsigned char>))
    {
        return stream << *reinterpret_cast<const Value<unsigned char>*>(value);
    }

    if (typeid(*value) == typeid(Value<unsigned int>))
    {
        return stream << *reinterpret_cast<const Value<unsigned int>*>(value);
    }

    if (typeid(*value) == typeid(Value<unsigned long>))
    {
        return stream << *reinterpret_cast<const Value<unsigned long>*>(value);
    }

    if (typeid(*value) == typeid(Value<unsigned long long>))
    {
        return stream << *reinterpret_cast<const Value<unsigned long long>*>(value);
    }

    if (typeid(*value) == typeid(Value<glmixed::GLvoid *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::GLvoid *>*>(value);
    }
if (typeid(*value) == typeid(Value<const char *>))
    {
        return stream << *reinterpret_cast<const Value<const char *>*>(value);
    }

    if (typeid(*value) == typeid(Value<glmixed::GLchar *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::GLchar *>*>(value);
    }

    if (typeid(*value) == typeid(Value<glmixed::GLubyte *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::GLubyte *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::AttribMask>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::AttribMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::AttribMask *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::AttribMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::BufferStorageMask>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::BufferStorageMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::BufferStorageMask *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::BufferStorageMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::ClearBufferMask>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::ClearBufferMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::ClearBufferMask *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::ClearBufferMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::ClientAttribMask>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::ClientAttribMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::ClientAttribMask *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::ClientAttribMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::ContextFlagMask>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::ContextFlagMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::ContextFlagMask *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::ContextFlagMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::ContextProfileMask>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::ContextProfileMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::ContextProfileMask *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::ContextProfileMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::FfdMaskSGIX>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::FfdMaskSGIX>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::FfdMaskSGIX *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::FfdMaskSGIX *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::FragmentShaderColorModMaskATI>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::FragmentShaderColorModMaskATI>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::FragmentShaderColorModMaskATI *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::FragmentShaderColorModMaskATI *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::FragmentShaderDestMaskATI>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::FragmentShaderDestMaskATI>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::FragmentShaderDestMaskATI *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::FragmentShaderDestMaskATI *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::FragmentShaderDestModMaskATI>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::FragmentShaderDestModMaskATI>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::FragmentShaderDestModMaskATI *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::FragmentShaderDestModMaskATI *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::GLenum>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::GLenum>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::GLenum *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::GLenum *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::GLextension>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::GLextension>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::GLextension *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::GLextension *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::GLhandleARB>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::GLhandleARB>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::GLhandleARB *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::GLhandleARB *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::MapBufferAccessMask>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::MapBufferAccessMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::MapBufferAccessMask *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::MapBufferAccessMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::MemoryBarrierMask>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::MemoryBarrierMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::MemoryBarrierMask *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::MemoryBarrierMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::OcclusionQueryEventMaskAMD>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::OcclusionQueryEventMaskAMD>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::OcclusionQueryEventMaskAMD *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::OcclusionQueryEventMaskAMD *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::PathFontStyle>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::PathFontStyle>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::PathFontStyle *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::PathFontStyle *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::PathMetricMask>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::PathMetricMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::PathMetricMask *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::PathMetricMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::PerformanceQueryCapsMaskINTEL>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::PerformanceQueryCapsMaskINTEL>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::PerformanceQueryCapsMaskINTEL *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::PerformanceQueryCapsMaskINTEL *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::SyncObjectMask>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::SyncObjectMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::SyncObjectMask *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::SyncObjectMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::TextureStorageMaskAMD>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::TextureStorageMaskAMD>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::TextureStorageMaskAMD *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::TextureStorageMaskAMD *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::UnusedMask>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::UnusedMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::UnusedMask *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::UnusedMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::UseProgramStageMask>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::UseProgramStageMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::UseProgramStageMask *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::UseProgramStageMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<glmixed::VertexHintsMaskPGI>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::VertexHintsMaskPGI>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<glmixed::VertexHintsMaskPGI *>))
    {
        return stream << *reinterpret_cast<const Value<glmixed::VertexHintsMaskPGI *>*>(value);
    }

    // expect an AbstractValue with a pointer in first member
    return stream << *reinterpret_cast<const Value<void *>*>(value);
}


} // namespace glmixedbinding