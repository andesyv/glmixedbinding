
#pragma once


namespace glmixedbinding
{


GLMIXEDBINDING_CONSTEXPR Boolean32::Boolean32()
: Boolean32(false)
{
}

GLMIXEDBINDING_CONSTEXPR Boolean32::Boolean32(bool value)
: m_value(static_cast<underlying_type>(value))
{
}

GLMIXEDBINDING_CONSTEXPR Boolean32::Boolean32(char value)
: m_value(value)
{
}

GLMIXEDBINDING_CONSTEXPR Boolean32::Boolean32(unsigned char value)
: m_value(static_cast<underlying_type>(value))
{
}

GLMIXEDBINDING_CONSTEXPR Boolean32::Boolean32(int value)
: m_value(static_cast<underlying_type>(value))
{
}

GLMIXEDBINDING_CONSTEXPR Boolean32::Boolean32(unsigned int value)
: m_value(static_cast<underlying_type>(value))
{
}

GLMIXEDBINDING_CONSTEXPR Boolean32::operator bool() const
{
    return m_value != 0;
}

GLMIXEDBINDING_CONSTEXPR Boolean32::operator char() const
{
    return m_value;
}

GLMIXEDBINDING_CONSTEXPR Boolean32::operator unsigned char() const
{
    return m_value;
}

GLMIXEDBINDING_CONSTEXPR Boolean32::operator int() const
{
    return m_value;
}

GLMIXEDBINDING_CONSTEXPR Boolean32::operator unsigned int() const
{
    return m_value;
}

GLMIXEDBINDING_CONSTEXPR bool Boolean32::operator<(const Boolean32 & other) const
{
    return m_value < other.m_value;
}

GLMIXEDBINDING_CONSTEXPR bool Boolean32::operator>(const Boolean32 & other) const
{
    return m_value > other.m_value;
}

GLMIXEDBINDING_CONSTEXPR bool Boolean32::operator<=(const Boolean32 & other) const
{
    return m_value <= other.m_value;
}

GLMIXEDBINDING_CONSTEXPR bool Boolean32::operator>=(const Boolean32 & other) const
{
    return m_value >= other.m_value;
}

GLMIXEDBINDING_CONSTEXPR bool Boolean32::operator==(const Boolean32 & other) const
{
    return m_value == other.m_value;
}

GLMIXEDBINDING_CONSTEXPR bool Boolean32::operator!=(const Boolean32 & other) const
{
    return m_value != other.m_value;
}


} // namespace glmixedbinding


namespace std
{


template<>
struct hash<glmixedbinding::Boolean32>
{
    std::size_t operator()(const glmixedbinding::Boolean32 & boolean) const
    {
        return hash<glmixedbinding::Boolean32::underlying_type>()(static_cast<glmixedbinding::Boolean32::underlying_type>(boolean));
    }
};


} // namespace std