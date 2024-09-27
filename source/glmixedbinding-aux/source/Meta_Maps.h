
#pragma once


#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>
#include <array>

#include <glmixedbinding/glmixed/types.h>
#include <glmixedbinding/glmixed/extension.h>


namespace glmixedbinding
{


class Version;


namespace aux
{


extern const std::array<std::unordered_map<std::string, glmixed::GLextension>, 27> Meta_ExtensionsByStringMaps;
extern const std::unordered_map<glmixed::GLextension, Version> Meta_ReqVersionsByExtension;

extern const std::unordered_map<glmixed::GLboolean, std::string> Meta_StringsByBoolean;
extern const std::multimap<glmixed::GLenum, std::string> Meta_StringsByEnum;
extern const std::unordered_map<glmixed::GLextension, std::string> Meta_StringsByExtension;
extern const std::unordered_map<glmixed::GLextension, std::set<std::string>> Meta_FunctionStringsByExtension;
extern const std::map<Version, std::set<std::string>> Meta_FunctionStringsByVersion;

extern const std::unordered_map<glmixed::AttribMask, std::string> Meta_StringsByAttribMask;
extern const std::unordered_map<glmixed::BufferStorageMask, std::string> Meta_StringsByBufferStorageMask;
extern const std::unordered_map<glmixed::ClearBufferMask, std::string> Meta_StringsByClearBufferMask;
extern const std::unordered_map<glmixed::ClientAttribMask, std::string> Meta_StringsByClientAttribMask;
extern const std::unordered_map<glmixed::ContextFlagMask, std::string> Meta_StringsByContextFlagMask;
extern const std::unordered_map<glmixed::ContextProfileMask, std::string> Meta_StringsByContextProfileMask;
extern const std::unordered_map<glmixed::FfdMaskSGIX, std::string> Meta_StringsByFfdMaskSGIX;
extern const std::unordered_map<glmixed::FragmentShaderColorModMaskATI, std::string> Meta_StringsByFragmentShaderColorModMaskATI;
extern const std::unordered_map<glmixed::FragmentShaderDestMaskATI, std::string> Meta_StringsByFragmentShaderDestMaskATI;
extern const std::unordered_map<glmixed::FragmentShaderDestModMaskATI, std::string> Meta_StringsByFragmentShaderDestModMaskATI;
extern const std::unordered_map<glmixed::MapBufferAccessMask, std::string> Meta_StringsByMapBufferAccessMask;
extern const std::unordered_map<glmixed::MemoryBarrierMask, std::string> Meta_StringsByMemoryBarrierMask;
extern const std::unordered_map<glmixed::OcclusionQueryEventMaskAMD, std::string> Meta_StringsByOcclusionQueryEventMaskAMD;
extern const std::unordered_map<glmixed::PathFontStyle, std::string> Meta_StringsByPathFontStyle;
extern const std::unordered_map<glmixed::PathMetricMask, std::string> Meta_StringsByPathMetricMask;
extern const std::unordered_map<glmixed::PerformanceQueryCapsMaskINTEL, std::string> Meta_StringsByPerformanceQueryCapsMaskINTEL;
extern const std::unordered_map<glmixed::SyncObjectMask, std::string> Meta_StringsBySyncObjectMask;
extern const std::unordered_map<glmixed::TextureStorageMaskAMD, std::string> Meta_StringsByTextureStorageMaskAMD;
extern const std::unordered_map<glmixed::UnusedMask, std::string> Meta_StringsByUnusedMask;
extern const std::unordered_map<glmixed::UseProgramStageMask, std::string> Meta_StringsByUseProgramStageMask;
extern const std::unordered_map<glmixed::VertexHintsMaskPGI, std::string> Meta_StringsByVertexHintsMaskPGI;


extern const std::array<std::unordered_map<std::string, glmixed::GLbitfield>, 27> Meta_BitfieldsByStringMaps;
extern const std::unordered_map<std::string, glmixed::GLboolean> Meta_BooleansByString;
extern const std::array<std::unordered_map<std::string, glmixed::GLenum>, 27> Meta_EnumsByStringMaps;
extern const std::array<std::unordered_map<std::string, std::set<glmixed::GLextension>>, 27> Meta_ExtensionsByFunctionStringMaps;


} } // namespace glmixedbinding::aux