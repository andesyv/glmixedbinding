
#include <glmixedbinding-aux/ContextInfo.h>

#include <sstream>
#include <iostream>

#include <glmixedbinding/AbstractFunction.h>

#include <glmixedbinding/Version.h>
#include <glmixedbinding/glmixed/glmixed.h>
#include <glmixedbinding/Binding.h>

#include <glmixedbinding-aux/Meta.h>


using namespace glmixed;


namespace
{


void insertExtension(
    const std::string & extensionName
,   std::set<GLextension> * extensions
,   std::set<std::string> * unknownExtensionNames)
{
    const auto extension = glmixedbinding::aux::Meta::getExtension(extensionName);

    if (GLextension::UNKNOWN != extension)
    {
        extensions->insert(extension);
    }
    else if (unknownExtensionNames)
    {
        unknownExtensionNames->insert(extensionName);
    }
}

// Implementation for functions with optional parameters (extensions, supported). 
// This design prefers a reference focussed interface over optional 
// parameters via pointers while maintaining a single implementation.

std::set<GLextension> extensions(std::set<std::string> * const unknown)
{
    const auto v = glmixedbinding::aux::ContextInfo::version();

    if (v <= glmixedbinding::Version(1, 0)) // OpenGL 1.0 doesn't support extensions
    {
        return std::set<GLextension>{};
    }

    auto extensions = std::set<GLextension>{};

    if (v < glmixedbinding::Version(3, 0))
    {
        const auto extensionString = glGetString(GL_EXTENSIONS);

        if (!extensionString)
        {
            return extensions;
        }

        std::istringstream stream{ reinterpret_cast<const char *>(extensionString) };
        auto extensionName = std::string{ };

        while (std::getline(stream, extensionName, ' '))
        {
            insertExtension(extensionName, &extensions, unknown);
        }
    }
    else
    {
        auto numExtensions = 0;
        glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);

        for (GLuint i = 0; i < static_cast<GLuint>(numExtensions); ++i)
        {
            const auto name = glGetStringi(GL_EXTENSIONS, i);
            if (name)
            {
                insertExtension(reinterpret_cast<const char*>(name), &extensions, unknown);
            }
        }
    }

    return extensions;
}

bool supported(const std::set<glmixed::GLextension> & extensions, std::set<glmixed::GLextension> * unsupported)
{
    const auto supportedExtensions = ::extensions(nullptr);
    auto support = true;

    for (const auto extension : extensions)
    {
        if (supportedExtensions.find(extension) != supportedExtensions.cend())
        {
            continue;
        }

        support &= false;
        if (unsupported)
        {
            unsupported->insert(extension);
        }
    }

    return support;
}

bool supported(
    const std::set<glmixedbinding::AbstractFunction *> & functions
,   std::set<glmixedbinding::AbstractFunction *> * unsupported
,   const bool resolve)
{
    auto support = true;

    for (const auto function : functions)
    {
        if(resolve)
        {
            function->resolveAddress();
        }

        if (function->isResolved())
        {
            continue;
        }

        support &= false;
        if (unsupported)
        {
            unsupported->insert(function);
        }
    }

    return support;
}

bool supported(const glmixedbinding::Version & version
    , const bool resolve
    , std::set<glmixed::GLextension> * unsupportedExtensions
    , std::set<glmixedbinding::AbstractFunction *> * unsupportedFunctions)
{
    const auto requiredExtensions = glmixedbinding::aux::Meta::extensions(version);
    const auto requiredFunctions = glmixedbinding::aux::Meta::functions(version);

    auto support = true;

    support &= supported(requiredExtensions, unsupportedExtensions);
    support &= supported(requiredFunctions, unsupportedFunctions, resolve);

    return support;
}

} // namespace


namespace glmixedbinding { namespace aux
{

std::string ContextInfo::renderer()
{
    auto s = reinterpret_cast<const char *>(glGetString(GL_RENDERER));

    if (!s)
    {
        return "";
    }

    return std::string{ s };
}

std::string ContextInfo::vendor()
{
    auto s = reinterpret_cast<const char *>(glGetString(GL_VENDOR));

    if (!s)
    {
        return "";
    }

    return std::string{ s };
}

Version ContextInfo::version()
{
    auto majorVersion = 0;
    auto minorVersion = 0;

    Binding::GetIntegerv.directCall(GL_MAJOR_VERSION, &majorVersion);
    Binding::GetIntegerv.directCall(GL_MINOR_VERSION, &minorVersion);

    const auto version = Version(static_cast<unsigned char>(majorVersion & 255)
        , static_cast<unsigned char>(minorVersion & 255));

    // probably version below 3.0
    if (GL_INVALID_ENUM == Binding::GetError.directCall())
    {
        const auto versionString = Binding::GetString.directCall(GL_VERSION);
        return Version(versionString[0] - '0', versionString[2] - '0');
    }

    return version;
}

std::set<GLextension> ContextInfo::extensions()
{
    return ::extensions(nullptr);
}

std::set<GLextension> ContextInfo::extensions(std::set<std::string> & unknown)
{
    return ::extensions(&unknown);
}

bool ContextInfo::supported(const std::set<glmixed::GLextension> & extensions)
{
    return ::supported(extensions, nullptr);
}

bool ContextInfo::supported(const std::set<glmixed::GLextension> & extensions, std::set<glmixed::GLextension> & unsupported)
{
    return ::supported(extensions, &unsupported);
}

bool ContextInfo::supported(const Version & version, const bool resolve)
{
    return ::supported(version, resolve, nullptr, nullptr);
}

bool ContextInfo::supported(const Version & version
    , std::set<glmixed::GLextension> & unsupportedExtensions
    , std::set<AbstractFunction *> & unsupportedFunctions
    , const bool resolve)
{
    return ::supported(version, resolve, &unsupportedExtensions, &unsupportedFunctions);
}


} } // namespace glmixedbinding::aux
