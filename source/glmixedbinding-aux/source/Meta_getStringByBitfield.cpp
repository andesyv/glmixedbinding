
#include <glmixedbinding-aux/Meta.h>

#include <glmixedbinding/glmixed/bitfield.h>

#include "Meta_Maps.h"


using namespace glmixed;


namespace
{


const auto none = std::string{};


} // namespace


namespace glmixedbinding { namespace aux
{


const std::string & Meta::getString(const AttribMask glmixedbitfield)
{
    const auto i = Meta_StringsByAttribMask.find(glmixedbitfield);
    if (i != Meta_StringsByAttribMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const BufferStorageMask glmixedbitfield)
{
    const auto i = Meta_StringsByBufferStorageMask.find(glmixedbitfield);
    if (i != Meta_StringsByBufferStorageMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const ClearBufferMask glmixedbitfield)
{
    const auto i = Meta_StringsByClearBufferMask.find(glmixedbitfield);
    if (i != Meta_StringsByClearBufferMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const ClientAttribMask glmixedbitfield)
{
    const auto i = Meta_StringsByClientAttribMask.find(glmixedbitfield);
    if (i != Meta_StringsByClientAttribMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const ContextFlagMask glmixedbitfield)
{
    const auto i = Meta_StringsByContextFlagMask.find(glmixedbitfield);
    if (i != Meta_StringsByContextFlagMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const ContextProfileMask glmixedbitfield)
{
    const auto i = Meta_StringsByContextProfileMask.find(glmixedbitfield);
    if (i != Meta_StringsByContextProfileMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const FfdMaskSGIX glmixedbitfield)
{
    const auto i = Meta_StringsByFfdMaskSGIX.find(glmixedbitfield);
    if (i != Meta_StringsByFfdMaskSGIX.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const FragmentShaderColorModMaskATI glmixedbitfield)
{
    const auto i = Meta_StringsByFragmentShaderColorModMaskATI.find(glmixedbitfield);
    if (i != Meta_StringsByFragmentShaderColorModMaskATI.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const FragmentShaderDestMaskATI glmixedbitfield)
{
    const auto i = Meta_StringsByFragmentShaderDestMaskATI.find(glmixedbitfield);
    if (i != Meta_StringsByFragmentShaderDestMaskATI.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const FragmentShaderDestModMaskATI glmixedbitfield)
{
    const auto i = Meta_StringsByFragmentShaderDestModMaskATI.find(glmixedbitfield);
    if (i != Meta_StringsByFragmentShaderDestModMaskATI.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const MapBufferAccessMask glmixedbitfield)
{
    const auto i = Meta_StringsByMapBufferAccessMask.find(glmixedbitfield);
    if (i != Meta_StringsByMapBufferAccessMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const MemoryBarrierMask glmixedbitfield)
{
    const auto i = Meta_StringsByMemoryBarrierMask.find(glmixedbitfield);
    if (i != Meta_StringsByMemoryBarrierMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const OcclusionQueryEventMaskAMD glmixedbitfield)
{
    const auto i = Meta_StringsByOcclusionQueryEventMaskAMD.find(glmixedbitfield);
    if (i != Meta_StringsByOcclusionQueryEventMaskAMD.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const PathFontStyle glmixedbitfield)
{
    const auto i = Meta_StringsByPathFontStyle.find(glmixedbitfield);
    if (i != Meta_StringsByPathFontStyle.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const PathMetricMask glmixedbitfield)
{
    const auto i = Meta_StringsByPathMetricMask.find(glmixedbitfield);
    if (i != Meta_StringsByPathMetricMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const PerformanceQueryCapsMaskINTEL glmixedbitfield)
{
    const auto i = Meta_StringsByPerformanceQueryCapsMaskINTEL.find(glmixedbitfield);
    if (i != Meta_StringsByPerformanceQueryCapsMaskINTEL.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const SyncObjectMask glmixedbitfield)
{
    const auto i = Meta_StringsBySyncObjectMask.find(glmixedbitfield);
    if (i != Meta_StringsBySyncObjectMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const TextureStorageMaskAMD glmixedbitfield)
{
    const auto i = Meta_StringsByTextureStorageMaskAMD.find(glmixedbitfield);
    if (i != Meta_StringsByTextureStorageMaskAMD.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const UnusedMask glmixedbitfield)
{
    const auto i = Meta_StringsByUnusedMask.find(glmixedbitfield);
    if (i != Meta_StringsByUnusedMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const UseProgramStageMask glmixedbitfield)
{
    const auto i = Meta_StringsByUseProgramStageMask.find(glmixedbitfield);
    if (i != Meta_StringsByUseProgramStageMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const VertexHintsMaskPGI glmixedbitfield)
{
    const auto i = Meta_StringsByVertexHintsMaskPGI.find(glmixedbitfield);
    if (i != Meta_StringsByVertexHintsMaskPGI.end())
    {
        return i->second;
    }
    return none;
}


} } // namespace glmixedbinding::aux