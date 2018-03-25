
namespace eglbinding
{


EGLBINDING_CONSTEXPR Version::Version(const Version &version)
    : khrbinding::Version<eglbinding::Version>::Version(version.majorVersion(), version.minorVersion())
{
}

EGLBINDING_CONSTEXPR Version::Version(Version && version)
: khrbinding::Version<eglbinding::Version>::Version(std::move(version.majorVersion()), std::move(version.minorVersion()))
{
}

Version & Version::operator=(const Version &version)
{
    m_major = version.m_major;
    m_minor = version.m_minor;

    return *this;
}

Version & Version::operator=(Version && version)
{
    m_major = std::move(version.m_major);
    m_minor = std::move(version.m_minor);

    return *this;
}


} // namespace eglbinding
