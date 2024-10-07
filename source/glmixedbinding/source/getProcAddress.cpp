
#include <glmixedbinding/getProcAddress.h>

#include <cassert>

#ifdef SYSTEM_WINDOWS
    #include <string>
    #include <tchar.h>
    #include <windows.h>
#else
    #include <dlfcn.h>
#endif


namespace glmixedbinding {

#ifdef SYSTEM_WINDOWS

ProcAddress getProcAddress(const char * name)
{
    // With two APIs we have no clue which one should be used by default. So just load any of the two and use the first one available.
    static auto glModule = LoadLibrary(_T("OPENGL32.DLL"));
    if (glModule != nullptr)
    {
        // Prevent static linking of opengl32
        static auto glWglGetProcAddress_ = reinterpret_cast<void * (__stdcall *)(const char *)>((uintptr_t) ::GetProcAddress(glModule, "wglGetProcAddress"));
        assert(glWglGetProcAddress_ != nullptr);

        auto procAddress = glWglGetProcAddress_(name);
        if (procAddress != nullptr)
        {
            return reinterpret_cast<ProcAddress>(procAddress);
        }

        procAddress = (void *) ::GetProcAddress(glModule, name);
        if (procAddress != nullptr)
        {
            return reinterpret_cast<ProcAddress>(procAddress);
        }
    }


    static auto glesModule = LoadLibrary(_T("libGLESv2.DLL"));
    if (glesModule != nullptr)
    {
        // Prevent static linking of opengl32
        static auto glesWglGetProcAddress_ = reinterpret_cast<void * (__stdcall *)(const char *)>((uintptr_t) ::GetProcAddress(glesModule, "wglGetProcAddress"));
        assert(glesWglGetProcAddress_ != nullptr);

        auto procAddress = glesWglGetProcAddress_(name);
        if (procAddress != nullptr)
        {
            return reinterpret_cast<ProcAddress>(procAddress);
        }

        procAddress = (void *) ::GetProcAddress(glesModule, name);
        if (procAddress != nullptr)
        {
            return reinterpret_cast<ProcAddress>(procAddress);
        }
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
