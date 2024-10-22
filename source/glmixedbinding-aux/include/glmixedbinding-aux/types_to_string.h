
#pragma once


#include <string>
#include <iosfwd>

#include <glmixedbinding-aux/glmixedbinding-aux_api.h>
#include <glmixedbinding-aux/glmixedbinding-aux_features.h>

#include <glmixedbinding/glmixed/types.h>
#include <glmixedbinding/Value.h>


namespace glmixed
{


GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const GLenum & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const GLboolean & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const GLextension & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const AttribMask & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const BufferStorageMask & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const ClearBufferMask & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const ClientAttribMask & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const ContextFlagMask & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const ContextProfileMask & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const FfdMaskSGIX & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const FragmentShaderColorModMaskATI & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const FragmentShaderDestMaskATI & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const FragmentShaderDestModMaskATI & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const MapBufferAccessMask & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const MemoryBarrierMask & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const OcclusionQueryEventMaskAMD & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const PathFontStyle & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const PathMetricMask & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const PerformanceQueryCapsMaskINTEL & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const SyncObjectMask & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const TextureStorageMaskAMD & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const UnusedMask & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const UseProgramStageMask & value);
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const VertexHintsMaskPGI & value);


} // namespace glmixed


namespace glmixedbinding
{


class Version;


/**
*  @brief
*    Generic ostream operator for the Value template
*/
template <typename T>
GLMIXEDBINDING_AUX_TEMPLATE_API std::ostream & operator<<(std::ostream & stream, const Value<T> & value);

/**
*  @brief
*    Generic ostream operator for the Value template with pointer types
*/
template <typename T>
GLMIXEDBINDING_AUX_TEMPLATE_API std::ostream & operator<<(std::ostream & stream, const Value<T *> & value);

/**
*  @brief
*    A specialized ostream operator for the glmixed::GLenum Value template
*/
template <>
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const Value<glmixed::GLenum> & value);

/* <- ToDo: Add back second * when implementing this function again
*  @brief
*    A specialized ostream operator for the glmixed::GLbitfield Value template
*/
/*template <>
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const Value<glmixed::GLbitfield> & value);*/

/**
*  @brief
*    A specialized ostream operator for the glmixed::GLenum Value template
*/
template <>
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const Value<glmixed::GLboolean> & value);

/**
*  @brief
*    A specialized ostream operator for the const char * Value template
*/
template <>
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const Value<const char *> & value);

/**
*  @brief
*    A specialized ostream operator for the GLubyte * Value template
*/
template <>
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const Value<glmixed::GLubyte *> & value);

/**
*  @brief
*    A specialized ostream operator for the GLchar * Value template
*/
template <>
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const Value<glmixed::GLchar *> & value);

/**
*  @brief
*    The operator to allow Versions to be printed onto a std::ostream
*/
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const Version & version);

/**
*  @brief
*    The operator to allow AbstractValues to be printed onto a std::ostream
*/
GLMIXEDBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const AbstractValue * value);


} // namespace glmixedbinding


#include <glmixedbinding-aux/types_to_string.inl>