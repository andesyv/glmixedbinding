
#pragma once


#include <glmixedbinding/glmixed/types.h>


namespace std
{


template<>
struct hash<glmixed::GLextension>
{
    std::size_t operator()(const glmixed::GLextension & t) const
    {
        return hash<std::underlying_type<glmixed::GLextension>::type>()(static_cast<std::underlying_type<glmixed::GLextension>::type>(t));
    }
};


} // namespace std


namespace std
{


template<>
struct hash<glmixed::GLenum>
{
    std::size_t operator()(const glmixed::GLenum & t) const
    {
        return hash<std::underlying_type<glmixed::GLenum>::type>()(static_cast<std::underlying_type<glmixed::GLenum>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline GLenum operator+(const GLenum & a, const std::underlying_type<GLenum>::type b)
{
    return static_cast<GLenum>(static_cast<std::underlying_type<GLenum>::type>(a) + b);
}

GLMIXEDBINDING_CONSTEXPR inline GLenum operator-(const GLenum & a, const std::underlying_type<GLenum>::type b)
{
    return static_cast<GLenum>(static_cast<std::underlying_type<GLenum>::type>(a) - b);
}

GLMIXEDBINDING_CONSTEXPR inline bool operator==(const GLenum & a, std::underlying_type<GLenum>::type b)
{
    return static_cast<std::underlying_type<GLenum>::type>(a) == b;
}

GLMIXEDBINDING_CONSTEXPR inline bool operator!=(const GLenum & a, std::underlying_type<GLenum>::type b)
{
    return static_cast<std::underlying_type<GLenum>::type>(a) != b;
}

GLMIXEDBINDING_CONSTEXPR inline bool operator< (const GLenum & a, std::underlying_type<GLenum>::type b)
{
    return static_cast<std::underlying_type<GLenum>::type>(a) < b;
}

GLMIXEDBINDING_CONSTEXPR inline bool operator<=(const GLenum & a, std::underlying_type<GLenum>::type b)
{
    return static_cast<std::underlying_type<GLenum>::type>(a) <= b;
}

GLMIXEDBINDING_CONSTEXPR inline bool operator> (const GLenum & a, std::underlying_type<GLenum>::type b)
{
    return static_cast<std::underlying_type<GLenum>::type>(a) > b;
}

GLMIXEDBINDING_CONSTEXPR inline bool operator>=(const GLenum & a, std::underlying_type<GLenum>::type b)
{
    return static_cast<std::underlying_type<GLenum>::type>(a) >= b;
}

GLMIXEDBINDING_CONSTEXPR inline bool operator==(std::underlying_type<GLenum>::type a, const GLenum & b)
{
    return a == static_cast<std::underlying_type<GLenum>::type>(b);
}

GLMIXEDBINDING_CONSTEXPR inline bool operator!=(std::underlying_type<GLenum>::type a, const GLenum & b)
{
    return a != static_cast<std::underlying_type<GLenum>::type>(b);
}

GLMIXEDBINDING_CONSTEXPR inline bool operator< (std::underlying_type<GLenum>::type a, const GLenum & b)
{
    return a < static_cast<std::underlying_type<GLenum>::type>(b);
}

GLMIXEDBINDING_CONSTEXPR inline bool operator<=(std::underlying_type<GLenum>::type a, const GLenum & b)
{
    return a <= static_cast<std::underlying_type<GLenum>::type>(b);
}

GLMIXEDBINDING_CONSTEXPR inline bool operator> (std::underlying_type<GLenum>::type a, const GLenum & b)
{
    return a > static_cast<std::underlying_type<GLenum>::type>(b);
}

GLMIXEDBINDING_CONSTEXPR inline bool operator>=(std::underlying_type<GLenum>::type a, const GLenum & b)
{
    return a >= static_cast<std::underlying_type<GLenum>::type>(b);
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::AttribMask>
{
    std::size_t operator()(const glmixed::AttribMask & t) const
    {
        return hash<std::underlying_type<glmixed::AttribMask>::type>()(static_cast<std::underlying_type<glmixed::AttribMask>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline AttribMask operator|(const AttribMask & a, const AttribMask & b)
{
    return static_cast<AttribMask>(static_cast<std::underlying_type<AttribMask>::type>(a) | static_cast<std::underlying_type<AttribMask>::type>(b));
}

inline AttribMask & operator|=(AttribMask & a, const AttribMask & b)
{
    a = static_cast<AttribMask>(static_cast<std::underlying_type<AttribMask>::type>(a) | static_cast<std::underlying_type<AttribMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline AttribMask operator&(const AttribMask & a, const AttribMask & b)
{
    return static_cast<AttribMask>(static_cast<std::underlying_type<AttribMask>::type>(a) & static_cast<std::underlying_type<AttribMask>::type>(b));
}

inline AttribMask & operator&=(AttribMask & a, const AttribMask & b)
{
    a = static_cast<AttribMask>(static_cast<std::underlying_type<AttribMask>::type>(a) & static_cast<std::underlying_type<AttribMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline AttribMask operator^(const AttribMask & a, const AttribMask & b)
{
    return static_cast<AttribMask>(static_cast<std::underlying_type<AttribMask>::type>(a) ^ static_cast<std::underlying_type<AttribMask>::type>(b));
}

inline AttribMask & operator^=(AttribMask & a, const AttribMask & b)
{
    a = static_cast<AttribMask>(static_cast<std::underlying_type<AttribMask>::type>(a) ^ static_cast<std::underlying_type<AttribMask>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::BufferStorageMask>
{
    std::size_t operator()(const glmixed::BufferStorageMask & t) const
    {
        return hash<std::underlying_type<glmixed::BufferStorageMask>::type>()(static_cast<std::underlying_type<glmixed::BufferStorageMask>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline BufferStorageMask operator|(const BufferStorageMask & a, const BufferStorageMask & b)
{
    return static_cast<BufferStorageMask>(static_cast<std::underlying_type<BufferStorageMask>::type>(a) | static_cast<std::underlying_type<BufferStorageMask>::type>(b));
}

inline BufferStorageMask & operator|=(BufferStorageMask & a, const BufferStorageMask & b)
{
    a = static_cast<BufferStorageMask>(static_cast<std::underlying_type<BufferStorageMask>::type>(a) | static_cast<std::underlying_type<BufferStorageMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline BufferStorageMask operator&(const BufferStorageMask & a, const BufferStorageMask & b)
{
    return static_cast<BufferStorageMask>(static_cast<std::underlying_type<BufferStorageMask>::type>(a) & static_cast<std::underlying_type<BufferStorageMask>::type>(b));
}

inline BufferStorageMask & operator&=(BufferStorageMask & a, const BufferStorageMask & b)
{
    a = static_cast<BufferStorageMask>(static_cast<std::underlying_type<BufferStorageMask>::type>(a) & static_cast<std::underlying_type<BufferStorageMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline BufferStorageMask operator^(const BufferStorageMask & a, const BufferStorageMask & b)
{
    return static_cast<BufferStorageMask>(static_cast<std::underlying_type<BufferStorageMask>::type>(a) ^ static_cast<std::underlying_type<BufferStorageMask>::type>(b));
}

inline BufferStorageMask & operator^=(BufferStorageMask & a, const BufferStorageMask & b)
{
    a = static_cast<BufferStorageMask>(static_cast<std::underlying_type<BufferStorageMask>::type>(a) ^ static_cast<std::underlying_type<BufferStorageMask>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::ClearBufferMask>
{
    std::size_t operator()(const glmixed::ClearBufferMask & t) const
    {
        return hash<std::underlying_type<glmixed::ClearBufferMask>::type>()(static_cast<std::underlying_type<glmixed::ClearBufferMask>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline ClearBufferMask operator|(const ClearBufferMask & a, const ClearBufferMask & b)
{
    return static_cast<ClearBufferMask>(static_cast<std::underlying_type<ClearBufferMask>::type>(a) | static_cast<std::underlying_type<ClearBufferMask>::type>(b));
}

inline ClearBufferMask & operator|=(ClearBufferMask & a, const ClearBufferMask & b)
{
    a = static_cast<ClearBufferMask>(static_cast<std::underlying_type<ClearBufferMask>::type>(a) | static_cast<std::underlying_type<ClearBufferMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline ClearBufferMask operator&(const ClearBufferMask & a, const ClearBufferMask & b)
{
    return static_cast<ClearBufferMask>(static_cast<std::underlying_type<ClearBufferMask>::type>(a) & static_cast<std::underlying_type<ClearBufferMask>::type>(b));
}

inline ClearBufferMask & operator&=(ClearBufferMask & a, const ClearBufferMask & b)
{
    a = static_cast<ClearBufferMask>(static_cast<std::underlying_type<ClearBufferMask>::type>(a) & static_cast<std::underlying_type<ClearBufferMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline ClearBufferMask operator^(const ClearBufferMask & a, const ClearBufferMask & b)
{
    return static_cast<ClearBufferMask>(static_cast<std::underlying_type<ClearBufferMask>::type>(a) ^ static_cast<std::underlying_type<ClearBufferMask>::type>(b));
}

inline ClearBufferMask & operator^=(ClearBufferMask & a, const ClearBufferMask & b)
{
    a = static_cast<ClearBufferMask>(static_cast<std::underlying_type<ClearBufferMask>::type>(a) ^ static_cast<std::underlying_type<ClearBufferMask>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::ClientAttribMask>
{
    std::size_t operator()(const glmixed::ClientAttribMask & t) const
    {
        return hash<std::underlying_type<glmixed::ClientAttribMask>::type>()(static_cast<std::underlying_type<glmixed::ClientAttribMask>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline ClientAttribMask operator|(const ClientAttribMask & a, const ClientAttribMask & b)
{
    return static_cast<ClientAttribMask>(static_cast<std::underlying_type<ClientAttribMask>::type>(a) | static_cast<std::underlying_type<ClientAttribMask>::type>(b));
}

inline ClientAttribMask & operator|=(ClientAttribMask & a, const ClientAttribMask & b)
{
    a = static_cast<ClientAttribMask>(static_cast<std::underlying_type<ClientAttribMask>::type>(a) | static_cast<std::underlying_type<ClientAttribMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline ClientAttribMask operator&(const ClientAttribMask & a, const ClientAttribMask & b)
{
    return static_cast<ClientAttribMask>(static_cast<std::underlying_type<ClientAttribMask>::type>(a) & static_cast<std::underlying_type<ClientAttribMask>::type>(b));
}

inline ClientAttribMask & operator&=(ClientAttribMask & a, const ClientAttribMask & b)
{
    a = static_cast<ClientAttribMask>(static_cast<std::underlying_type<ClientAttribMask>::type>(a) & static_cast<std::underlying_type<ClientAttribMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline ClientAttribMask operator^(const ClientAttribMask & a, const ClientAttribMask & b)
{
    return static_cast<ClientAttribMask>(static_cast<std::underlying_type<ClientAttribMask>::type>(a) ^ static_cast<std::underlying_type<ClientAttribMask>::type>(b));
}

inline ClientAttribMask & operator^=(ClientAttribMask & a, const ClientAttribMask & b)
{
    a = static_cast<ClientAttribMask>(static_cast<std::underlying_type<ClientAttribMask>::type>(a) ^ static_cast<std::underlying_type<ClientAttribMask>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::ContextFlagMask>
{
    std::size_t operator()(const glmixed::ContextFlagMask & t) const
    {
        return hash<std::underlying_type<glmixed::ContextFlagMask>::type>()(static_cast<std::underlying_type<glmixed::ContextFlagMask>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline ContextFlagMask operator|(const ContextFlagMask & a, const ContextFlagMask & b)
{
    return static_cast<ContextFlagMask>(static_cast<std::underlying_type<ContextFlagMask>::type>(a) | static_cast<std::underlying_type<ContextFlagMask>::type>(b));
}

inline ContextFlagMask & operator|=(ContextFlagMask & a, const ContextFlagMask & b)
{
    a = static_cast<ContextFlagMask>(static_cast<std::underlying_type<ContextFlagMask>::type>(a) | static_cast<std::underlying_type<ContextFlagMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline ContextFlagMask operator&(const ContextFlagMask & a, const ContextFlagMask & b)
{
    return static_cast<ContextFlagMask>(static_cast<std::underlying_type<ContextFlagMask>::type>(a) & static_cast<std::underlying_type<ContextFlagMask>::type>(b));
}

inline ContextFlagMask & operator&=(ContextFlagMask & a, const ContextFlagMask & b)
{
    a = static_cast<ContextFlagMask>(static_cast<std::underlying_type<ContextFlagMask>::type>(a) & static_cast<std::underlying_type<ContextFlagMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline ContextFlagMask operator^(const ContextFlagMask & a, const ContextFlagMask & b)
{
    return static_cast<ContextFlagMask>(static_cast<std::underlying_type<ContextFlagMask>::type>(a) ^ static_cast<std::underlying_type<ContextFlagMask>::type>(b));
}

inline ContextFlagMask & operator^=(ContextFlagMask & a, const ContextFlagMask & b)
{
    a = static_cast<ContextFlagMask>(static_cast<std::underlying_type<ContextFlagMask>::type>(a) ^ static_cast<std::underlying_type<ContextFlagMask>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::ContextProfileMask>
{
    std::size_t operator()(const glmixed::ContextProfileMask & t) const
    {
        return hash<std::underlying_type<glmixed::ContextProfileMask>::type>()(static_cast<std::underlying_type<glmixed::ContextProfileMask>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline ContextProfileMask operator|(const ContextProfileMask & a, const ContextProfileMask & b)
{
    return static_cast<ContextProfileMask>(static_cast<std::underlying_type<ContextProfileMask>::type>(a) | static_cast<std::underlying_type<ContextProfileMask>::type>(b));
}

inline ContextProfileMask & operator|=(ContextProfileMask & a, const ContextProfileMask & b)
{
    a = static_cast<ContextProfileMask>(static_cast<std::underlying_type<ContextProfileMask>::type>(a) | static_cast<std::underlying_type<ContextProfileMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline ContextProfileMask operator&(const ContextProfileMask & a, const ContextProfileMask & b)
{
    return static_cast<ContextProfileMask>(static_cast<std::underlying_type<ContextProfileMask>::type>(a) & static_cast<std::underlying_type<ContextProfileMask>::type>(b));
}

inline ContextProfileMask & operator&=(ContextProfileMask & a, const ContextProfileMask & b)
{
    a = static_cast<ContextProfileMask>(static_cast<std::underlying_type<ContextProfileMask>::type>(a) & static_cast<std::underlying_type<ContextProfileMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline ContextProfileMask operator^(const ContextProfileMask & a, const ContextProfileMask & b)
{
    return static_cast<ContextProfileMask>(static_cast<std::underlying_type<ContextProfileMask>::type>(a) ^ static_cast<std::underlying_type<ContextProfileMask>::type>(b));
}

inline ContextProfileMask & operator^=(ContextProfileMask & a, const ContextProfileMask & b)
{
    a = static_cast<ContextProfileMask>(static_cast<std::underlying_type<ContextProfileMask>::type>(a) ^ static_cast<std::underlying_type<ContextProfileMask>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::FfdMaskSGIX>
{
    std::size_t operator()(const glmixed::FfdMaskSGIX & t) const
    {
        return hash<std::underlying_type<glmixed::FfdMaskSGIX>::type>()(static_cast<std::underlying_type<glmixed::FfdMaskSGIX>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline FfdMaskSGIX operator|(const FfdMaskSGIX & a, const FfdMaskSGIX & b)
{
    return static_cast<FfdMaskSGIX>(static_cast<std::underlying_type<FfdMaskSGIX>::type>(a) | static_cast<std::underlying_type<FfdMaskSGIX>::type>(b));
}

inline FfdMaskSGIX & operator|=(FfdMaskSGIX & a, const FfdMaskSGIX & b)
{
    a = static_cast<FfdMaskSGIX>(static_cast<std::underlying_type<FfdMaskSGIX>::type>(a) | static_cast<std::underlying_type<FfdMaskSGIX>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline FfdMaskSGIX operator&(const FfdMaskSGIX & a, const FfdMaskSGIX & b)
{
    return static_cast<FfdMaskSGIX>(static_cast<std::underlying_type<FfdMaskSGIX>::type>(a) & static_cast<std::underlying_type<FfdMaskSGIX>::type>(b));
}

inline FfdMaskSGIX & operator&=(FfdMaskSGIX & a, const FfdMaskSGIX & b)
{
    a = static_cast<FfdMaskSGIX>(static_cast<std::underlying_type<FfdMaskSGIX>::type>(a) & static_cast<std::underlying_type<FfdMaskSGIX>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline FfdMaskSGIX operator^(const FfdMaskSGIX & a, const FfdMaskSGIX & b)
{
    return static_cast<FfdMaskSGIX>(static_cast<std::underlying_type<FfdMaskSGIX>::type>(a) ^ static_cast<std::underlying_type<FfdMaskSGIX>::type>(b));
}

inline FfdMaskSGIX & operator^=(FfdMaskSGIX & a, const FfdMaskSGIX & b)
{
    a = static_cast<FfdMaskSGIX>(static_cast<std::underlying_type<FfdMaskSGIX>::type>(a) ^ static_cast<std::underlying_type<FfdMaskSGIX>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::FragmentShaderColorModMaskATI>
{
    std::size_t operator()(const glmixed::FragmentShaderColorModMaskATI & t) const
    {
        return hash<std::underlying_type<glmixed::FragmentShaderColorModMaskATI>::type>()(static_cast<std::underlying_type<glmixed::FragmentShaderColorModMaskATI>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline FragmentShaderColorModMaskATI operator|(const FragmentShaderColorModMaskATI & a, const FragmentShaderColorModMaskATI & b)
{
    return static_cast<FragmentShaderColorModMaskATI>(static_cast<std::underlying_type<FragmentShaderColorModMaskATI>::type>(a) | static_cast<std::underlying_type<FragmentShaderColorModMaskATI>::type>(b));
}

inline FragmentShaderColorModMaskATI & operator|=(FragmentShaderColorModMaskATI & a, const FragmentShaderColorModMaskATI & b)
{
    a = static_cast<FragmentShaderColorModMaskATI>(static_cast<std::underlying_type<FragmentShaderColorModMaskATI>::type>(a) | static_cast<std::underlying_type<FragmentShaderColorModMaskATI>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline FragmentShaderColorModMaskATI operator&(const FragmentShaderColorModMaskATI & a, const FragmentShaderColorModMaskATI & b)
{
    return static_cast<FragmentShaderColorModMaskATI>(static_cast<std::underlying_type<FragmentShaderColorModMaskATI>::type>(a) & static_cast<std::underlying_type<FragmentShaderColorModMaskATI>::type>(b));
}

inline FragmentShaderColorModMaskATI & operator&=(FragmentShaderColorModMaskATI & a, const FragmentShaderColorModMaskATI & b)
{
    a = static_cast<FragmentShaderColorModMaskATI>(static_cast<std::underlying_type<FragmentShaderColorModMaskATI>::type>(a) & static_cast<std::underlying_type<FragmentShaderColorModMaskATI>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline FragmentShaderColorModMaskATI operator^(const FragmentShaderColorModMaskATI & a, const FragmentShaderColorModMaskATI & b)
{
    return static_cast<FragmentShaderColorModMaskATI>(static_cast<std::underlying_type<FragmentShaderColorModMaskATI>::type>(a) ^ static_cast<std::underlying_type<FragmentShaderColorModMaskATI>::type>(b));
}

inline FragmentShaderColorModMaskATI & operator^=(FragmentShaderColorModMaskATI & a, const FragmentShaderColorModMaskATI & b)
{
    a = static_cast<FragmentShaderColorModMaskATI>(static_cast<std::underlying_type<FragmentShaderColorModMaskATI>::type>(a) ^ static_cast<std::underlying_type<FragmentShaderColorModMaskATI>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::FragmentShaderDestMaskATI>
{
    std::size_t operator()(const glmixed::FragmentShaderDestMaskATI & t) const
    {
        return hash<std::underlying_type<glmixed::FragmentShaderDestMaskATI>::type>()(static_cast<std::underlying_type<glmixed::FragmentShaderDestMaskATI>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline FragmentShaderDestMaskATI operator|(const FragmentShaderDestMaskATI & a, const FragmentShaderDestMaskATI & b)
{
    return static_cast<FragmentShaderDestMaskATI>(static_cast<std::underlying_type<FragmentShaderDestMaskATI>::type>(a) | static_cast<std::underlying_type<FragmentShaderDestMaskATI>::type>(b));
}

inline FragmentShaderDestMaskATI & operator|=(FragmentShaderDestMaskATI & a, const FragmentShaderDestMaskATI & b)
{
    a = static_cast<FragmentShaderDestMaskATI>(static_cast<std::underlying_type<FragmentShaderDestMaskATI>::type>(a) | static_cast<std::underlying_type<FragmentShaderDestMaskATI>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline FragmentShaderDestMaskATI operator&(const FragmentShaderDestMaskATI & a, const FragmentShaderDestMaskATI & b)
{
    return static_cast<FragmentShaderDestMaskATI>(static_cast<std::underlying_type<FragmentShaderDestMaskATI>::type>(a) & static_cast<std::underlying_type<FragmentShaderDestMaskATI>::type>(b));
}

inline FragmentShaderDestMaskATI & operator&=(FragmentShaderDestMaskATI & a, const FragmentShaderDestMaskATI & b)
{
    a = static_cast<FragmentShaderDestMaskATI>(static_cast<std::underlying_type<FragmentShaderDestMaskATI>::type>(a) & static_cast<std::underlying_type<FragmentShaderDestMaskATI>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline FragmentShaderDestMaskATI operator^(const FragmentShaderDestMaskATI & a, const FragmentShaderDestMaskATI & b)
{
    return static_cast<FragmentShaderDestMaskATI>(static_cast<std::underlying_type<FragmentShaderDestMaskATI>::type>(a) ^ static_cast<std::underlying_type<FragmentShaderDestMaskATI>::type>(b));
}

inline FragmentShaderDestMaskATI & operator^=(FragmentShaderDestMaskATI & a, const FragmentShaderDestMaskATI & b)
{
    a = static_cast<FragmentShaderDestMaskATI>(static_cast<std::underlying_type<FragmentShaderDestMaskATI>::type>(a) ^ static_cast<std::underlying_type<FragmentShaderDestMaskATI>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::FragmentShaderDestModMaskATI>
{
    std::size_t operator()(const glmixed::FragmentShaderDestModMaskATI & t) const
    {
        return hash<std::underlying_type<glmixed::FragmentShaderDestModMaskATI>::type>()(static_cast<std::underlying_type<glmixed::FragmentShaderDestModMaskATI>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline FragmentShaderDestModMaskATI operator|(const FragmentShaderDestModMaskATI & a, const FragmentShaderDestModMaskATI & b)
{
    return static_cast<FragmentShaderDestModMaskATI>(static_cast<std::underlying_type<FragmentShaderDestModMaskATI>::type>(a) | static_cast<std::underlying_type<FragmentShaderDestModMaskATI>::type>(b));
}

inline FragmentShaderDestModMaskATI & operator|=(FragmentShaderDestModMaskATI & a, const FragmentShaderDestModMaskATI & b)
{
    a = static_cast<FragmentShaderDestModMaskATI>(static_cast<std::underlying_type<FragmentShaderDestModMaskATI>::type>(a) | static_cast<std::underlying_type<FragmentShaderDestModMaskATI>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline FragmentShaderDestModMaskATI operator&(const FragmentShaderDestModMaskATI & a, const FragmentShaderDestModMaskATI & b)
{
    return static_cast<FragmentShaderDestModMaskATI>(static_cast<std::underlying_type<FragmentShaderDestModMaskATI>::type>(a) & static_cast<std::underlying_type<FragmentShaderDestModMaskATI>::type>(b));
}

inline FragmentShaderDestModMaskATI & operator&=(FragmentShaderDestModMaskATI & a, const FragmentShaderDestModMaskATI & b)
{
    a = static_cast<FragmentShaderDestModMaskATI>(static_cast<std::underlying_type<FragmentShaderDestModMaskATI>::type>(a) & static_cast<std::underlying_type<FragmentShaderDestModMaskATI>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline FragmentShaderDestModMaskATI operator^(const FragmentShaderDestModMaskATI & a, const FragmentShaderDestModMaskATI & b)
{
    return static_cast<FragmentShaderDestModMaskATI>(static_cast<std::underlying_type<FragmentShaderDestModMaskATI>::type>(a) ^ static_cast<std::underlying_type<FragmentShaderDestModMaskATI>::type>(b));
}

inline FragmentShaderDestModMaskATI & operator^=(FragmentShaderDestModMaskATI & a, const FragmentShaderDestModMaskATI & b)
{
    a = static_cast<FragmentShaderDestModMaskATI>(static_cast<std::underlying_type<FragmentShaderDestModMaskATI>::type>(a) ^ static_cast<std::underlying_type<FragmentShaderDestModMaskATI>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::MapBufferAccessMask>
{
    std::size_t operator()(const glmixed::MapBufferAccessMask & t) const
    {
        return hash<std::underlying_type<glmixed::MapBufferAccessMask>::type>()(static_cast<std::underlying_type<glmixed::MapBufferAccessMask>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline MapBufferAccessMask operator|(const MapBufferAccessMask & a, const MapBufferAccessMask & b)
{
    return static_cast<MapBufferAccessMask>(static_cast<std::underlying_type<MapBufferAccessMask>::type>(a) | static_cast<std::underlying_type<MapBufferAccessMask>::type>(b));
}

inline MapBufferAccessMask & operator|=(MapBufferAccessMask & a, const MapBufferAccessMask & b)
{
    a = static_cast<MapBufferAccessMask>(static_cast<std::underlying_type<MapBufferAccessMask>::type>(a) | static_cast<std::underlying_type<MapBufferAccessMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline MapBufferAccessMask operator&(const MapBufferAccessMask & a, const MapBufferAccessMask & b)
{
    return static_cast<MapBufferAccessMask>(static_cast<std::underlying_type<MapBufferAccessMask>::type>(a) & static_cast<std::underlying_type<MapBufferAccessMask>::type>(b));
}

inline MapBufferAccessMask & operator&=(MapBufferAccessMask & a, const MapBufferAccessMask & b)
{
    a = static_cast<MapBufferAccessMask>(static_cast<std::underlying_type<MapBufferAccessMask>::type>(a) & static_cast<std::underlying_type<MapBufferAccessMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline MapBufferAccessMask operator^(const MapBufferAccessMask & a, const MapBufferAccessMask & b)
{
    return static_cast<MapBufferAccessMask>(static_cast<std::underlying_type<MapBufferAccessMask>::type>(a) ^ static_cast<std::underlying_type<MapBufferAccessMask>::type>(b));
}

inline MapBufferAccessMask & operator^=(MapBufferAccessMask & a, const MapBufferAccessMask & b)
{
    a = static_cast<MapBufferAccessMask>(static_cast<std::underlying_type<MapBufferAccessMask>::type>(a) ^ static_cast<std::underlying_type<MapBufferAccessMask>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::MemoryBarrierMask>
{
    std::size_t operator()(const glmixed::MemoryBarrierMask & t) const
    {
        return hash<std::underlying_type<glmixed::MemoryBarrierMask>::type>()(static_cast<std::underlying_type<glmixed::MemoryBarrierMask>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline MemoryBarrierMask operator|(const MemoryBarrierMask & a, const MemoryBarrierMask & b)
{
    return static_cast<MemoryBarrierMask>(static_cast<std::underlying_type<MemoryBarrierMask>::type>(a) | static_cast<std::underlying_type<MemoryBarrierMask>::type>(b));
}

inline MemoryBarrierMask & operator|=(MemoryBarrierMask & a, const MemoryBarrierMask & b)
{
    a = static_cast<MemoryBarrierMask>(static_cast<std::underlying_type<MemoryBarrierMask>::type>(a) | static_cast<std::underlying_type<MemoryBarrierMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline MemoryBarrierMask operator&(const MemoryBarrierMask & a, const MemoryBarrierMask & b)
{
    return static_cast<MemoryBarrierMask>(static_cast<std::underlying_type<MemoryBarrierMask>::type>(a) & static_cast<std::underlying_type<MemoryBarrierMask>::type>(b));
}

inline MemoryBarrierMask & operator&=(MemoryBarrierMask & a, const MemoryBarrierMask & b)
{
    a = static_cast<MemoryBarrierMask>(static_cast<std::underlying_type<MemoryBarrierMask>::type>(a) & static_cast<std::underlying_type<MemoryBarrierMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline MemoryBarrierMask operator^(const MemoryBarrierMask & a, const MemoryBarrierMask & b)
{
    return static_cast<MemoryBarrierMask>(static_cast<std::underlying_type<MemoryBarrierMask>::type>(a) ^ static_cast<std::underlying_type<MemoryBarrierMask>::type>(b));
}

inline MemoryBarrierMask & operator^=(MemoryBarrierMask & a, const MemoryBarrierMask & b)
{
    a = static_cast<MemoryBarrierMask>(static_cast<std::underlying_type<MemoryBarrierMask>::type>(a) ^ static_cast<std::underlying_type<MemoryBarrierMask>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::OcclusionQueryEventMaskAMD>
{
    std::size_t operator()(const glmixed::OcclusionQueryEventMaskAMD & t) const
    {
        return hash<std::underlying_type<glmixed::OcclusionQueryEventMaskAMD>::type>()(static_cast<std::underlying_type<glmixed::OcclusionQueryEventMaskAMD>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline OcclusionQueryEventMaskAMD operator|(const OcclusionQueryEventMaskAMD & a, const OcclusionQueryEventMaskAMD & b)
{
    return static_cast<OcclusionQueryEventMaskAMD>(static_cast<std::underlying_type<OcclusionQueryEventMaskAMD>::type>(a) | static_cast<std::underlying_type<OcclusionQueryEventMaskAMD>::type>(b));
}

inline OcclusionQueryEventMaskAMD & operator|=(OcclusionQueryEventMaskAMD & a, const OcclusionQueryEventMaskAMD & b)
{
    a = static_cast<OcclusionQueryEventMaskAMD>(static_cast<std::underlying_type<OcclusionQueryEventMaskAMD>::type>(a) | static_cast<std::underlying_type<OcclusionQueryEventMaskAMD>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline OcclusionQueryEventMaskAMD operator&(const OcclusionQueryEventMaskAMD & a, const OcclusionQueryEventMaskAMD & b)
{
    return static_cast<OcclusionQueryEventMaskAMD>(static_cast<std::underlying_type<OcclusionQueryEventMaskAMD>::type>(a) & static_cast<std::underlying_type<OcclusionQueryEventMaskAMD>::type>(b));
}

inline OcclusionQueryEventMaskAMD & operator&=(OcclusionQueryEventMaskAMD & a, const OcclusionQueryEventMaskAMD & b)
{
    a = static_cast<OcclusionQueryEventMaskAMD>(static_cast<std::underlying_type<OcclusionQueryEventMaskAMD>::type>(a) & static_cast<std::underlying_type<OcclusionQueryEventMaskAMD>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline OcclusionQueryEventMaskAMD operator^(const OcclusionQueryEventMaskAMD & a, const OcclusionQueryEventMaskAMD & b)
{
    return static_cast<OcclusionQueryEventMaskAMD>(static_cast<std::underlying_type<OcclusionQueryEventMaskAMD>::type>(a) ^ static_cast<std::underlying_type<OcclusionQueryEventMaskAMD>::type>(b));
}

inline OcclusionQueryEventMaskAMD & operator^=(OcclusionQueryEventMaskAMD & a, const OcclusionQueryEventMaskAMD & b)
{
    a = static_cast<OcclusionQueryEventMaskAMD>(static_cast<std::underlying_type<OcclusionQueryEventMaskAMD>::type>(a) ^ static_cast<std::underlying_type<OcclusionQueryEventMaskAMD>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::PathFontStyle>
{
    std::size_t operator()(const glmixed::PathFontStyle & t) const
    {
        return hash<std::underlying_type<glmixed::PathFontStyle>::type>()(static_cast<std::underlying_type<glmixed::PathFontStyle>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline PathFontStyle operator|(const PathFontStyle & a, const PathFontStyle & b)
{
    return static_cast<PathFontStyle>(static_cast<std::underlying_type<PathFontStyle>::type>(a) | static_cast<std::underlying_type<PathFontStyle>::type>(b));
}

inline PathFontStyle & operator|=(PathFontStyle & a, const PathFontStyle & b)
{
    a = static_cast<PathFontStyle>(static_cast<std::underlying_type<PathFontStyle>::type>(a) | static_cast<std::underlying_type<PathFontStyle>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline PathFontStyle operator&(const PathFontStyle & a, const PathFontStyle & b)
{
    return static_cast<PathFontStyle>(static_cast<std::underlying_type<PathFontStyle>::type>(a) & static_cast<std::underlying_type<PathFontStyle>::type>(b));
}

inline PathFontStyle & operator&=(PathFontStyle & a, const PathFontStyle & b)
{
    a = static_cast<PathFontStyle>(static_cast<std::underlying_type<PathFontStyle>::type>(a) & static_cast<std::underlying_type<PathFontStyle>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline PathFontStyle operator^(const PathFontStyle & a, const PathFontStyle & b)
{
    return static_cast<PathFontStyle>(static_cast<std::underlying_type<PathFontStyle>::type>(a) ^ static_cast<std::underlying_type<PathFontStyle>::type>(b));
}

inline PathFontStyle & operator^=(PathFontStyle & a, const PathFontStyle & b)
{
    a = static_cast<PathFontStyle>(static_cast<std::underlying_type<PathFontStyle>::type>(a) ^ static_cast<std::underlying_type<PathFontStyle>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::PathMetricMask>
{
    std::size_t operator()(const glmixed::PathMetricMask & t) const
    {
        return hash<std::underlying_type<glmixed::PathMetricMask>::type>()(static_cast<std::underlying_type<glmixed::PathMetricMask>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline PathMetricMask operator|(const PathMetricMask & a, const PathMetricMask & b)
{
    return static_cast<PathMetricMask>(static_cast<std::underlying_type<PathMetricMask>::type>(a) | static_cast<std::underlying_type<PathMetricMask>::type>(b));
}

inline PathMetricMask & operator|=(PathMetricMask & a, const PathMetricMask & b)
{
    a = static_cast<PathMetricMask>(static_cast<std::underlying_type<PathMetricMask>::type>(a) | static_cast<std::underlying_type<PathMetricMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline PathMetricMask operator&(const PathMetricMask & a, const PathMetricMask & b)
{
    return static_cast<PathMetricMask>(static_cast<std::underlying_type<PathMetricMask>::type>(a) & static_cast<std::underlying_type<PathMetricMask>::type>(b));
}

inline PathMetricMask & operator&=(PathMetricMask & a, const PathMetricMask & b)
{
    a = static_cast<PathMetricMask>(static_cast<std::underlying_type<PathMetricMask>::type>(a) & static_cast<std::underlying_type<PathMetricMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline PathMetricMask operator^(const PathMetricMask & a, const PathMetricMask & b)
{
    return static_cast<PathMetricMask>(static_cast<std::underlying_type<PathMetricMask>::type>(a) ^ static_cast<std::underlying_type<PathMetricMask>::type>(b));
}

inline PathMetricMask & operator^=(PathMetricMask & a, const PathMetricMask & b)
{
    a = static_cast<PathMetricMask>(static_cast<std::underlying_type<PathMetricMask>::type>(a) ^ static_cast<std::underlying_type<PathMetricMask>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::PerformanceQueryCapsMaskINTEL>
{
    std::size_t operator()(const glmixed::PerformanceQueryCapsMaskINTEL & t) const
    {
        return hash<std::underlying_type<glmixed::PerformanceQueryCapsMaskINTEL>::type>()(static_cast<std::underlying_type<glmixed::PerformanceQueryCapsMaskINTEL>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline PerformanceQueryCapsMaskINTEL operator|(const PerformanceQueryCapsMaskINTEL & a, const PerformanceQueryCapsMaskINTEL & b)
{
    return static_cast<PerformanceQueryCapsMaskINTEL>(static_cast<std::underlying_type<PerformanceQueryCapsMaskINTEL>::type>(a) | static_cast<std::underlying_type<PerformanceQueryCapsMaskINTEL>::type>(b));
}

inline PerformanceQueryCapsMaskINTEL & operator|=(PerformanceQueryCapsMaskINTEL & a, const PerformanceQueryCapsMaskINTEL & b)
{
    a = static_cast<PerformanceQueryCapsMaskINTEL>(static_cast<std::underlying_type<PerformanceQueryCapsMaskINTEL>::type>(a) | static_cast<std::underlying_type<PerformanceQueryCapsMaskINTEL>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline PerformanceQueryCapsMaskINTEL operator&(const PerformanceQueryCapsMaskINTEL & a, const PerformanceQueryCapsMaskINTEL & b)
{
    return static_cast<PerformanceQueryCapsMaskINTEL>(static_cast<std::underlying_type<PerformanceQueryCapsMaskINTEL>::type>(a) & static_cast<std::underlying_type<PerformanceQueryCapsMaskINTEL>::type>(b));
}

inline PerformanceQueryCapsMaskINTEL & operator&=(PerformanceQueryCapsMaskINTEL & a, const PerformanceQueryCapsMaskINTEL & b)
{
    a = static_cast<PerformanceQueryCapsMaskINTEL>(static_cast<std::underlying_type<PerformanceQueryCapsMaskINTEL>::type>(a) & static_cast<std::underlying_type<PerformanceQueryCapsMaskINTEL>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline PerformanceQueryCapsMaskINTEL operator^(const PerformanceQueryCapsMaskINTEL & a, const PerformanceQueryCapsMaskINTEL & b)
{
    return static_cast<PerformanceQueryCapsMaskINTEL>(static_cast<std::underlying_type<PerformanceQueryCapsMaskINTEL>::type>(a) ^ static_cast<std::underlying_type<PerformanceQueryCapsMaskINTEL>::type>(b));
}

inline PerformanceQueryCapsMaskINTEL & operator^=(PerformanceQueryCapsMaskINTEL & a, const PerformanceQueryCapsMaskINTEL & b)
{
    a = static_cast<PerformanceQueryCapsMaskINTEL>(static_cast<std::underlying_type<PerformanceQueryCapsMaskINTEL>::type>(a) ^ static_cast<std::underlying_type<PerformanceQueryCapsMaskINTEL>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::SyncObjectMask>
{
    std::size_t operator()(const glmixed::SyncObjectMask & t) const
    {
        return hash<std::underlying_type<glmixed::SyncObjectMask>::type>()(static_cast<std::underlying_type<glmixed::SyncObjectMask>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline SyncObjectMask operator|(const SyncObjectMask & a, const SyncObjectMask & b)
{
    return static_cast<SyncObjectMask>(static_cast<std::underlying_type<SyncObjectMask>::type>(a) | static_cast<std::underlying_type<SyncObjectMask>::type>(b));
}

inline SyncObjectMask & operator|=(SyncObjectMask & a, const SyncObjectMask & b)
{
    a = static_cast<SyncObjectMask>(static_cast<std::underlying_type<SyncObjectMask>::type>(a) | static_cast<std::underlying_type<SyncObjectMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline SyncObjectMask operator&(const SyncObjectMask & a, const SyncObjectMask & b)
{
    return static_cast<SyncObjectMask>(static_cast<std::underlying_type<SyncObjectMask>::type>(a) & static_cast<std::underlying_type<SyncObjectMask>::type>(b));
}

inline SyncObjectMask & operator&=(SyncObjectMask & a, const SyncObjectMask & b)
{
    a = static_cast<SyncObjectMask>(static_cast<std::underlying_type<SyncObjectMask>::type>(a) & static_cast<std::underlying_type<SyncObjectMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline SyncObjectMask operator^(const SyncObjectMask & a, const SyncObjectMask & b)
{
    return static_cast<SyncObjectMask>(static_cast<std::underlying_type<SyncObjectMask>::type>(a) ^ static_cast<std::underlying_type<SyncObjectMask>::type>(b));
}

inline SyncObjectMask & operator^=(SyncObjectMask & a, const SyncObjectMask & b)
{
    a = static_cast<SyncObjectMask>(static_cast<std::underlying_type<SyncObjectMask>::type>(a) ^ static_cast<std::underlying_type<SyncObjectMask>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::TextureStorageMaskAMD>
{
    std::size_t operator()(const glmixed::TextureStorageMaskAMD & t) const
    {
        return hash<std::underlying_type<glmixed::TextureStorageMaskAMD>::type>()(static_cast<std::underlying_type<glmixed::TextureStorageMaskAMD>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline TextureStorageMaskAMD operator|(const TextureStorageMaskAMD & a, const TextureStorageMaskAMD & b)
{
    return static_cast<TextureStorageMaskAMD>(static_cast<std::underlying_type<TextureStorageMaskAMD>::type>(a) | static_cast<std::underlying_type<TextureStorageMaskAMD>::type>(b));
}

inline TextureStorageMaskAMD & operator|=(TextureStorageMaskAMD & a, const TextureStorageMaskAMD & b)
{
    a = static_cast<TextureStorageMaskAMD>(static_cast<std::underlying_type<TextureStorageMaskAMD>::type>(a) | static_cast<std::underlying_type<TextureStorageMaskAMD>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline TextureStorageMaskAMD operator&(const TextureStorageMaskAMD & a, const TextureStorageMaskAMD & b)
{
    return static_cast<TextureStorageMaskAMD>(static_cast<std::underlying_type<TextureStorageMaskAMD>::type>(a) & static_cast<std::underlying_type<TextureStorageMaskAMD>::type>(b));
}

inline TextureStorageMaskAMD & operator&=(TextureStorageMaskAMD & a, const TextureStorageMaskAMD & b)
{
    a = static_cast<TextureStorageMaskAMD>(static_cast<std::underlying_type<TextureStorageMaskAMD>::type>(a) & static_cast<std::underlying_type<TextureStorageMaskAMD>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline TextureStorageMaskAMD operator^(const TextureStorageMaskAMD & a, const TextureStorageMaskAMD & b)
{
    return static_cast<TextureStorageMaskAMD>(static_cast<std::underlying_type<TextureStorageMaskAMD>::type>(a) ^ static_cast<std::underlying_type<TextureStorageMaskAMD>::type>(b));
}

inline TextureStorageMaskAMD & operator^=(TextureStorageMaskAMD & a, const TextureStorageMaskAMD & b)
{
    a = static_cast<TextureStorageMaskAMD>(static_cast<std::underlying_type<TextureStorageMaskAMD>::type>(a) ^ static_cast<std::underlying_type<TextureStorageMaskAMD>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::UnusedMask>
{
    std::size_t operator()(const glmixed::UnusedMask & t) const
    {
        return hash<std::underlying_type<glmixed::UnusedMask>::type>()(static_cast<std::underlying_type<glmixed::UnusedMask>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline UnusedMask operator|(const UnusedMask & a, const UnusedMask & b)
{
    return static_cast<UnusedMask>(static_cast<std::underlying_type<UnusedMask>::type>(a) | static_cast<std::underlying_type<UnusedMask>::type>(b));
}

inline UnusedMask & operator|=(UnusedMask & a, const UnusedMask & b)
{
    a = static_cast<UnusedMask>(static_cast<std::underlying_type<UnusedMask>::type>(a) | static_cast<std::underlying_type<UnusedMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline UnusedMask operator&(const UnusedMask & a, const UnusedMask & b)
{
    return static_cast<UnusedMask>(static_cast<std::underlying_type<UnusedMask>::type>(a) & static_cast<std::underlying_type<UnusedMask>::type>(b));
}

inline UnusedMask & operator&=(UnusedMask & a, const UnusedMask & b)
{
    a = static_cast<UnusedMask>(static_cast<std::underlying_type<UnusedMask>::type>(a) & static_cast<std::underlying_type<UnusedMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline UnusedMask operator^(const UnusedMask & a, const UnusedMask & b)
{
    return static_cast<UnusedMask>(static_cast<std::underlying_type<UnusedMask>::type>(a) ^ static_cast<std::underlying_type<UnusedMask>::type>(b));
}

inline UnusedMask & operator^=(UnusedMask & a, const UnusedMask & b)
{
    a = static_cast<UnusedMask>(static_cast<std::underlying_type<UnusedMask>::type>(a) ^ static_cast<std::underlying_type<UnusedMask>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::UseProgramStageMask>
{
    std::size_t operator()(const glmixed::UseProgramStageMask & t) const
    {
        return hash<std::underlying_type<glmixed::UseProgramStageMask>::type>()(static_cast<std::underlying_type<glmixed::UseProgramStageMask>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline UseProgramStageMask operator|(const UseProgramStageMask & a, const UseProgramStageMask & b)
{
    return static_cast<UseProgramStageMask>(static_cast<std::underlying_type<UseProgramStageMask>::type>(a) | static_cast<std::underlying_type<UseProgramStageMask>::type>(b));
}

inline UseProgramStageMask & operator|=(UseProgramStageMask & a, const UseProgramStageMask & b)
{
    a = static_cast<UseProgramStageMask>(static_cast<std::underlying_type<UseProgramStageMask>::type>(a) | static_cast<std::underlying_type<UseProgramStageMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline UseProgramStageMask operator&(const UseProgramStageMask & a, const UseProgramStageMask & b)
{
    return static_cast<UseProgramStageMask>(static_cast<std::underlying_type<UseProgramStageMask>::type>(a) & static_cast<std::underlying_type<UseProgramStageMask>::type>(b));
}

inline UseProgramStageMask & operator&=(UseProgramStageMask & a, const UseProgramStageMask & b)
{
    a = static_cast<UseProgramStageMask>(static_cast<std::underlying_type<UseProgramStageMask>::type>(a) & static_cast<std::underlying_type<UseProgramStageMask>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline UseProgramStageMask operator^(const UseProgramStageMask & a, const UseProgramStageMask & b)
{
    return static_cast<UseProgramStageMask>(static_cast<std::underlying_type<UseProgramStageMask>::type>(a) ^ static_cast<std::underlying_type<UseProgramStageMask>::type>(b));
}

inline UseProgramStageMask & operator^=(UseProgramStageMask & a, const UseProgramStageMask & b)
{
    a = static_cast<UseProgramStageMask>(static_cast<std::underlying_type<UseProgramStageMask>::type>(a) ^ static_cast<std::underlying_type<UseProgramStageMask>::type>(b));

    return a;
}


} // namespace glmixed


namespace std
{


template<>
struct hash<glmixed::VertexHintsMaskPGI>
{
    std::size_t operator()(const glmixed::VertexHintsMaskPGI & t) const
    {
        return hash<std::underlying_type<glmixed::VertexHintsMaskPGI>::type>()(static_cast<std::underlying_type<glmixed::VertexHintsMaskPGI>::type>(t));
    }
};


} // namespace std


namespace glmixed
{


GLMIXEDBINDING_CONSTEXPR inline VertexHintsMaskPGI operator|(const VertexHintsMaskPGI & a, const VertexHintsMaskPGI & b)
{
    return static_cast<VertexHintsMaskPGI>(static_cast<std::underlying_type<VertexHintsMaskPGI>::type>(a) | static_cast<std::underlying_type<VertexHintsMaskPGI>::type>(b));
}

inline VertexHintsMaskPGI & operator|=(VertexHintsMaskPGI & a, const VertexHintsMaskPGI & b)
{
    a = static_cast<VertexHintsMaskPGI>(static_cast<std::underlying_type<VertexHintsMaskPGI>::type>(a) | static_cast<std::underlying_type<VertexHintsMaskPGI>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline VertexHintsMaskPGI operator&(const VertexHintsMaskPGI & a, const VertexHintsMaskPGI & b)
{
    return static_cast<VertexHintsMaskPGI>(static_cast<std::underlying_type<VertexHintsMaskPGI>::type>(a) & static_cast<std::underlying_type<VertexHintsMaskPGI>::type>(b));
}

inline VertexHintsMaskPGI & operator&=(VertexHintsMaskPGI & a, const VertexHintsMaskPGI & b)
{
    a = static_cast<VertexHintsMaskPGI>(static_cast<std::underlying_type<VertexHintsMaskPGI>::type>(a) & static_cast<std::underlying_type<VertexHintsMaskPGI>::type>(b));

    return a;
}

GLMIXEDBINDING_CONSTEXPR inline VertexHintsMaskPGI operator^(const VertexHintsMaskPGI & a, const VertexHintsMaskPGI & b)
{
    return static_cast<VertexHintsMaskPGI>(static_cast<std::underlying_type<VertexHintsMaskPGI>::type>(a) ^ static_cast<std::underlying_type<VertexHintsMaskPGI>::type>(b));
}

inline VertexHintsMaskPGI & operator^=(VertexHintsMaskPGI & a, const VertexHintsMaskPGI & b)
{
    a = static_cast<VertexHintsMaskPGI>(static_cast<std::underlying_type<VertexHintsMaskPGI>::type>(a) ^ static_cast<std::underlying_type<VertexHintsMaskPGI>::type>(b));

    return a;
}


} // namespace glmixed