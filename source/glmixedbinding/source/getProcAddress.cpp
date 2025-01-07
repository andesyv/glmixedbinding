
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
#ifdef WINDOWS_STORE
    static auto glModule = LoadPackagedLibrary(_T("OPENGL32.DLL"), 0);
#else
    static auto glModule = LoadLibrary(_T("OPENGL32.DLL"));
#endif
    if (glModule != nullptr)
    {
        // Prevent static linking of opengl32
        static auto wglGetProcAddress_ = reinterpret_cast<void * (__stdcall *)(const char *)>((uintptr_t) ::GetProcAddress(glModule, "wglGetProcAddress"));
        if (wglGetProcAddress_ != nullptr)
        {
            auto procAddress = wglGetProcAddress_(name);
            if (procAddress != nullptr)
            {
                return reinterpret_cast<ProcAddress>(procAddress);
            }
        }

        auto procAddress = (void *) ::GetProcAddress(glModule, name);
        if (procAddress != nullptr)
        {
            return reinterpret_cast<ProcAddress>(procAddress);
        }
    }

    // GL ES can also be loaded via EGL (even on Windows), in which case eglGetProcAddress is the function that decides where the gl implementations are loaded from
#ifdef WINDOWS_STORE
    static auto eglModule = LoadPackagedLibrary(_T("libEGL.DLL"), 0);
#else
    static auto eglModule = LoadLibrary(_T("libEGL.DLL"));
#endif
    if (eglModule != nullptr)
    {
        static auto eglGetProcAddress_ = reinterpret_cast<void * (__stdcall *)(const char *)>((uintptr_t) ::GetProcAddress(eglModule, "eglGetProcAddress"));
        if (eglGetProcAddress_ != nullptr)
        {
            auto procAddress = eglGetProcAddress_(name);
            if (procAddress != nullptr)
            {
                return reinterpret_cast<ProcAddress>(procAddress);
            }
        }

        auto procAddress = (void *) ::GetProcAddress(eglModule, name);
        if (procAddress != nullptr)
        {
            return reinterpret_cast<ProcAddress>(procAddress);
        }
    }

    // Finally, on Windows, certain drivers (i.e. NVidia) also apparently exposes wglGetProcAddress through libGLESv2.dll
#ifdef WINDOWS_STORE
    static auto glesModule = LoadPackagedLibrary(_T("libGLESv2.DLL"), 0);
#else
    static auto glesModule = LoadLibrary(_T("libGLESv2.DLL"));
#endif
    if (glesModule != nullptr)
    {
        static auto wglGetProcAddress_ = reinterpret_cast<void * (__stdcall *)(const char *)>((uintptr_t) ::GetProcAddress(glesModule, "wglGetProcAddress"));
        if (wglGetProcAddress_ != nullptr)
        {
            auto procAddress = wglGetProcAddress_(name);
            if (procAddress != nullptr)
            {
                return reinterpret_cast<ProcAddress>(procAddress);
            }
        }

        auto procAddress = (void *) ::GetProcAddress(glesModule, name);
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
