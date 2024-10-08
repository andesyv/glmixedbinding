
#pragma once


#include <glmixedbinding-aux/glmixedbinding-aux_api.h>


namespace glmixedbinding { namespace aux
{


/**
*  @brief
*    Register the glGetError after callback
*
*  @remark
*    This function just registers the global after callback within glbinding.
*    For actual use, the callback has to be enabled, e.g., by a call to enableGetErrorCallback().
*
*  @remark
*    Any previously registered after callback get overwritten.
*/
GLMIXEDBINDING_AUX_API void registerGetErrorCallback();

/**
*  @brief
*    Enable glGetError() after callback
*
*  @remark
*    This registers the glGetError after callback if it wasn't registered before (by an internall call to registerGetErrorCallback()).
*    Thus, any previously registered after callback get overwritten.
*/
GLMIXEDBINDING_AUX_API void enableGetErrorCallback();

/**
*  @brief
*    Disables calls to the glGetError() after callback.
*
*  @remark
*    This does not unregister the after callback.
*/
GLMIXEDBINDING_AUX_API void disableGetErrorCallback();


} } // namespace glmixedbinding::aux
