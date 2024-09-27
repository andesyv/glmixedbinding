
#pragma once


#include <functional>

#include <glmixedbinding/glmixedbinding_api.h>
#include <glmixedbinding/glmixedbinding_features.h>


namespace glmixedbinding
{


class GLMIXEDBINDING_API Boolean32
{
public:
    using underlying_type = unsigned int;

public:
    GLMIXEDBINDING_CONSTEXPR inline Boolean32();
    GLMIXEDBINDING_CONSTEXPR inline Boolean32(bool on);
    GLMIXEDBINDING_CONSTEXPR inline Boolean32(char on);
    GLMIXEDBINDING_CONSTEXPR inline Boolean32(unsigned char on);
    GLMIXEDBINDING_CONSTEXPR inline Boolean32(int on);
    GLMIXEDBINDING_CONSTEXPR inline Boolean32(unsigned int on);

    GLMIXEDBINDING_CONSTEXPR inline explicit operator bool() const;
    GLMIXEDBINDING_CONSTEXPR inline explicit operator char() const;
    GLMIXEDBINDING_CONSTEXPR inline explicit operator unsigned char() const;
    GLMIXEDBINDING_CONSTEXPR inline explicit operator int() const;
    GLMIXEDBINDING_CONSTEXPR inline explicit operator unsigned int() const;

    GLMIXEDBINDING_CONSTEXPR inline bool operator<(const Boolean32 & other) const;
    GLMIXEDBINDING_CONSTEXPR inline bool operator>(const Boolean32 & other) const;
    GLMIXEDBINDING_CONSTEXPR inline bool operator<=(const Boolean32 & other) const;
    GLMIXEDBINDING_CONSTEXPR inline bool operator>=(const Boolean32 & other) const;

    GLMIXEDBINDING_CONSTEXPR inline bool operator==(const Boolean32 & other) const;
    GLMIXEDBINDING_CONSTEXPR inline bool operator!=(const Boolean32 & other) const;

public:
    underlying_type m_value;
};


} // namespace gl


#include <glmixedbinding/Boolean32.inl>