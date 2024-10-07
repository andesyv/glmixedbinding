
#include <glmixedbinding/getProcAddress.h>

#include <cassert>
#include <string_view>

#ifdef SYSTEM_WINDOWS
    #include <string>
    #include <tchar.h>
    #include <windows.h>
#else
    #include <dlfcn.h>
#endif


namespace glmixedbinding {

    #define SYSTEM_WINDOWS

#ifdef SYSTEM_WINDOWS

namespace {
    template <std::string_view LibraryName>
    ProcAddress getProcAddressImpl(const char* name)
    {
        static auto module = LoadLibrary(LibraryName.c_str());
        if (module == nullptr)
        {
            return nullptr;
        }

        // Prevent static linking of opengl32
        static auto wglGetProcAddress_ = reinterpret_cast<void * (__stdcall *)(const char *)>((uintptr_t) ::GetProcAddress(module, "wglGetProcAddress"));
        assert(wglGetProcAddress_ != nullptr);

        auto procAddress = wglGetProcAddress_(name);
        if (procAddress != nullptr)
        {
            return reinterpret_cast<ProcAddress>(procAddress);
        }

        procAddress = (void *) ::GetProcAddress(module, name);
        if (procAddress != nullptr)
        {
            return reinterpret_cast<ProcAddress>(procAddress);
        }

        return nullptr;
    }
}

ProcAddress getProcAddress(const char * name)
{
    // With two APIs we have no clue which one should be used by default. So just load any of the two and use the first one available.
    auto glProcAddress = getProcAddressImpl<"OPENGL32.DLL">(name);
    if (glProcAddress != nullptr)
    {
        return glProcAddress;
    }

    auto glesProcAddress = getProcAddressImpl<"libGLESv2.DLL">(name);
    if (glesProcAddress != nullptr)
    {
        return glesProcAddress;
    }

    return nullptr;
}

#else

ProcAddress getProcAddress(const char * name)
{
#ifdef SYSTEM_DARWIN
    static auto library = dlopen("/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL", RTLD_LAZY);
    // TODO: implement for OpenGL ES
#else
    // With two APIs we have no clue which one should be used by default. So just load any of the two and use the first one available.
    static auto library = dlopen("libGL.so", RTLD_LAZY);
    if (library == nullptr)
    {
        library = dlopen("libGLESv2.so", RTLD_LAZY);
    }
#endif

    assert(library != nullptr);

    auto symbol = dlsym(library, name);

    return reinterpret_cast<ProcAddress>(symbol);
}

#endif


} // namespace glmixedbinding
