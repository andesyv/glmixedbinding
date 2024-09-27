
#pragma once


#include <string>
#include <set>
#include <array>
#include <vector>
#include <functional>
#include <unordered_map>

#ifdef GLMIXEDBINDING_USE_BOOST_THREAD
#include <boost/thread.hpp>
namespace std_boost = boost;
#else
#include <mutex>
namespace std_boost = std;
#endif

#include <glmixedbinding/glmixedbinding_api.h>
#include <glmixedbinding/glmixedbinding_features.h>

#include <glmixedbinding/AbstractFunction.h>
#include <glmixedbinding/ContextHandle.h>
#include <glmixedbinding/Function.h>
#include <glmixedbinding/CallbackMask.h>
#include <glmixedbinding/FunctionCall.h>
#include <glmixedbinding/ProcAddress.h>

#include <glmixedbinding/glmixed/types.h>


namespace glmixedbinding
{


/**
*  @brief
*    The main interface to handle additional features to OpenGL functions besides regular function calls
*
*  Additional features include binding initialization (even for multi-threaded environments), additional function registration,
*  context switches (for multi-context environments) and basic reflection in form of accessors to the full list of functions.
*/
class GLMIXEDBINDING_API Binding
{
public:
    /**
    *  @brief
    *    The callback type of a simple function callback without parameters and return value
    */
    using SimpleFunctionCallback = std::function<void(const AbstractFunction &)>;

    /**
    *  @brief
    *    The callback type of a function callback with parameters and return value
    */
    using FunctionCallback = std::function<void(const FunctionCall &)>;

    /**
    *  @brief
    *    The callback type of a function log callback with parameters and return value
    */
    using FunctionLogCallback = std::function<void(FunctionCall &&)>;

    using ContextSwitchCallback = std::function<void(ContextHandle)>;   ///< The signature of the context switch callback
    
    using array_t = std::array<AbstractFunction *, 3213>; ///< The type of the build-in functions collection


public:
    /**
    *  @brief
    *    Deleted Constructor as all functions are static
    */
    Binding() = delete;

    /**
    *  @brief
    *    Initializes the binding for the current active OpenGL context
    *
    *  @param[in] functionPointerResolver
    *    A function pointer to resolve binding functions for this context.
    *    If `nullptr` is passed for first time initialization, `glmixedbinding::getProcAddress` is used for convenience.
    *  @param[in] resolveFunctions (optional)
    *    Whether to resolve function pointers lazy (\a resolveFunctions = `false`) or immediately
    *
    *  @remark
    *    After this call, the initialized context is already set active for the current thread.
    *
    *  @remark
    *    A functionPointerResolver with value 'nullptr' will get initialized with the function
    *    pointer from the initial thread.
    *
    *  @remark
    *    Using glmixedbinding::getProcAddress is provided for convenience only. Please don't use this in new code.
    *    Instead, use an external function resolution callback, e.g.,
    *     * wglGetProcAddress
    *     * glxGetProcAddress
    *     * glfwGetProcAddress
    *     * QOpenGlContext::getProcAddress
    */
    static void initialize(glmixedbinding::GetProcAddress functionPointerResolver, bool resolveFunctions = true);

    /**
    *  @brief
    *    Initializes the binding for a specific OpenGL context
    *
    *  @param[in] context
    *    The context handle of the context to initialize
    *  @param[in] functionPointerResolver
    *    A function pointer to resolve binding functions for this context
    *  @param[in] useContext
    *    Whether to set the context active (\a useContext = `true`) after the initialization
    *  @param[in] resolveFunctions (optional)
    *    Whether to resolve function pointers lazy (\a resolveFunctions = `false`) or immediately
    *
    *  @remark
    *    A functionPointerResolver with value 'nullptr' will get initialized with the function
    *    pointer from the initial thread.
    */
    static void initialize(ContextHandle context, glmixedbinding::GetProcAddress functionPointerResolver, bool useContext = true, bool resolveFunctions = true);

    /**
    *  @brief
    *    Registers an additional function for the additional features
    *
    *  @param[in] function
    *    The function to register
    */
    static void registerAdditionalFunction(AbstractFunction * function);

    /**
    *  @brief
    *    Resolve a single function pointer by given name
    *
    *  @param[in] name
    *    The name of the function
    */
    static ProcAddress resolveFunction(const char * name);

    /**
    *  @brief
    *    Resolves the funtion pointers of all registered OpenGL functions immediately for the current context
    */
    static void resolveFunctions();

    /**
    *  @brief
    *    Update the current context state in glmixedbinding
    *
    *  @remark
    *    This function queries the driver for the current OpenGL context
    */
    static void useCurrentContext();

    /**
    *  @brief
    *    Update the current context state in glmixedbinding
    *
    *  @param[in] context
    *    The context handle of the context to set current
    */
    static void useContext(ContextHandle context);

    /**
    *  @brief
    *    Removes the current context from the state of glmixedbinding
    *
    *  @remark
    *    This function queries the driver for the current OpenGL context
    */
    static void releaseCurrentContext();

    /**
    *  @brief
    *    Removes the current context from the state of glmixedbinding
    *
    *  @param[in] context
    *    The context handle of the context to remove
    */
    static void releaseContext(ContextHandle context);

    /**
    *  @brief
    *    Registers an additional callback that gets called each time the context is switched using the useContext method
    *
    *  @remark
    *    There may be multiple context switch callbacks registered at once
    */
    static void addContextSwitchCallback(ContextSwitchCallback callback);

    /**
    *  @brief
    *    Updates the callback mask of all registered OpenGL functions in the current state
    *
    *  @param[in] mask
    *    The new CallbackMask
    */
    static void setCallbackMask(CallbackMask mask);

    /**
    *  @brief
    *    Updates the callback mask of all registered OpenGL functions in the current state, excluding the blacklisted functions
    *
    *  @param[in] mask
    *    The new CallbackMask
    *  @param[in] blackList
    *    The blacklist of functions to exclude in this update
    */
    static void setCallbackMaskExcept(CallbackMask mask, const std::set<std::string> & blackList);

    /**
    *  @brief
    *    Updates the callback mask of all registered OpenGL functions in the current state to include the passed CallbackMask
    *
    *  @param[in] mask
    *    The CallbackMask to include
    */
    static void addCallbackMask(CallbackMask mask);

    /**
    *  @brief
    *    Updates the callback mask of all registered OpenGL functions in the current state to include the passed CallbackMask, excluding the blacklisted functions
    *
    *  @param[in] mask
    *    The CallbackMask to include
    *  @param[in] blackList
    *    The blacklist of functions to exclude in this update
    */
    static void addCallbackMaskExcept(CallbackMask mask, const std::set<std::string> & blackList);

    /**
    *  @brief
    *    Updates the callback mask of all registered OpenGL functions in the current state to exclude the passed CallbackMask
    *
    *  @param[in] mask
    *    The CallbackMask to exclude
    */
    static void removeCallbackMask(CallbackMask mask);

    /**
    *  @brief
    *    Updates the callback mask of all registered OpenGL functions in the current state to exclude the passed CallbackMask, excluding the blacklisted functions
    *
    *  @param[in] mask
    *    The CallbackMask to exclude
    *  @param[in] blackList
    *    The blacklist of functions to exclude in this update
    */
    static void removeCallbackMaskExcept(CallbackMask mask, const std::set<std::string> & blackList);

    /**
    *  @brief
    *    Unresolved callback accessor
    *
    *  @return
    *    The callback to use instead of unresolved function calls
    *
    *  @remark
    *    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the After flag to enable the callback
    */
    static SimpleFunctionCallback unresolvedCallback();

    /**
    *  @brief
    *    Updates the unresolved callback that is called upon invocation of an OpenGL function which has no counterpart in the OpenGL driver
    *
    *  @param[in] callback
    *    The callback to use instead of unresolved function calls
    *
    *  @remark
    *    This callback is registered globally across all states.
    *  @remark
    *    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the Unresolved flag to enable the callback
    */
    static void setUnresolvedCallback(SimpleFunctionCallback callback);

    /**
    *  @brief
    *    Before callback accessor
    *
    *  @return
    *    The callback to use before an OpenGL function call
    *
    *  @remark
    *    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the After flag to enable the callback
    */
    static FunctionCallback beforeCallback();

    /**
    *  @brief
    *    Updates the before callback that is called before the actual OpenGL function invocation
    *
    *  @param[in] callback
    *    The callback to use before an OpenGL function call
    *
    *  @remark
    *    This callback is registered globally across all states.
    *  @remark
    *    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the Before flag to enable the callback
    */
    static void setBeforeCallback(FunctionCallback callback);

    /**
    *  @brief
    *    After callback accessor
    *
    *  @return
    *    The callback to use after an OpenGL function call
    *
    *  @remark
    *    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the After flag to enable the callback
    */
    static FunctionCallback afterCallback();

    /**
    *  @brief
    *    Updates the after callback that is called after the actual OpenGL function invocation
    *
    *  @param[in] callback
    *    The callback to use after an OpenGL function call
    *
    *  @remark
    *    This callback is registered globally across all states.
    *  @remark
    *    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the After flag to enable the callback
    */
    static void setAfterCallback(FunctionCallback callback);

    /**
    *  @brief
    *    Logging callback accessor
    *
    *  @return
    *    The callback to use for logging an OpenGL function call
    *
    *  @remark
    *    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the Logging flag to enable the callback
    */
    static FunctionLogCallback logCallback();

    /**
    *  @brief
    *    Updates the logging callback that is called to log the actual OpenGL function invocation
    *
    *  @param[in] callback
    *    The callback to use for logging an OpenGL function call
    *
    *  @remark
    *    This callback is registered globally across all states.
    *
    *  @remark
    *    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the Logging flag to enable the callback
    */
    static void setLogCallback(FunctionLogCallback callback);
    
    /**
    *  @brief
    *    The accessor for all build-in functions
    * 
    *  @return
    *    The list of all build-in functions
    */
    static const array_t & functions();

    /**
    *  @brief
    *    Accessor for additional functions
    *
    *  @return
    *    List of additional functions
    */
    static const std::vector<AbstractFunction *> & additionalFunctions();

    /**
    *  @brief
    *    Get index of current state
    *
    *  @return
    *    Index of current state
    */
    static int currentPos();

    /**
    *  @brief
    *    Get highest state index currently used
    *
    *  @return
    *    Highest state index currently used
    */
    static int maxPos();

    /**
    *  @brief
    *    Query total number of functions
    *
    *  @return
    *    Total number of functions
    */
    static size_t size();

    /**
    *  @brief
    *    Call unresolved callback
    *
    *  @param[in] function
    *    Parameter for callback
    *
    *  @see Binding::unresolvedCallback()
    */
    static void unresolved(const AbstractFunction * function);

    /**
    *  @brief
    *    Call before callback
    *
    *  @param[in] call
    *    Parameter for callback
    *
    *  @see Binding::beforeCallback()
    */
    static void before(const FunctionCall & call);

    /**
    *  @brief
    *    Call after callback
    *
    *  @param[in] call
    *    Parameter for callback
    *
    *  @see Binding::afterCallback()
    */
    static void after(const FunctionCall & call);

    /**
    *  @brief
    *    Call log callback
    *
    *  @param[in] call
    *    Parameter for callback
    *
    *  @see Binding::logCallback()
    */
    static void log(FunctionCall && call);


public:
    static Function<void, glmixed::GLenum, glmixed::GLfloat> Accum; ///< Wrapper for glAccum
    static Function<void, glmixed::GLenum, glmixed::GLfixed> AccumxOES; ///< Wrapper for glAccumxOES
    static Function<glmixed::GLboolean, glmixed::GLuint, glmixed::GLuint64, glmixed::GLuint> AcquireKeyedMutexWin32EXT; ///< Wrapper for glAcquireKeyedMutexWin32EXT
    static Function<void, glmixed::GLuint> ActiveProgramEXT; ///< Wrapper for glActiveProgramEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint> ActiveShaderProgram; ///< Wrapper for glActiveShaderProgram
    static Function<void, glmixed::GLuint, glmixed::GLuint> ActiveShaderProgramEXT; ///< Wrapper for glActiveShaderProgramEXT
    static Function<void, glmixed::GLenum> ActiveStencilFaceEXT; ///< Wrapper for glActiveStencilFaceEXT
    static Function<void, glmixed::GLenum> ActiveTexture; ///< Wrapper for glActiveTexture
    static Function<void, glmixed::GLenum> ActiveTextureARB; ///< Wrapper for glActiveTextureARB
    static Function<void, glmixed::GLuint, const glmixed::GLchar *> ActiveVaryingNV; ///< Wrapper for glActiveVaryingNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::FragmentShaderDestModMaskATI, glmixed::GLuint, glmixed::GLuint, glmixed::FragmentShaderColorModMaskATI> AlphaFragmentOp1ATI; ///< Wrapper for glAlphaFragmentOp1ATI
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::FragmentShaderDestModMaskATI, glmixed::GLuint, glmixed::GLuint, glmixed::FragmentShaderColorModMaskATI, glmixed::GLuint, glmixed::GLuint, glmixed::FragmentShaderColorModMaskATI> AlphaFragmentOp2ATI; ///< Wrapper for glAlphaFragmentOp2ATI
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::FragmentShaderDestModMaskATI, glmixed::GLuint, glmixed::GLuint, glmixed::FragmentShaderColorModMaskATI, glmixed::GLuint, glmixed::GLuint, glmixed::FragmentShaderColorModMaskATI, glmixed::GLuint, glmixed::GLuint, glmixed::FragmentShaderColorModMaskATI> AlphaFragmentOp3ATI; ///< Wrapper for glAlphaFragmentOp3ATI
    static Function<void, glmixed::GLenum, glmixed::GLfloat> AlphaFunc; ///< Wrapper for glAlphaFunc
    static Function<void, glmixed::GLenum, glmixed::GLclampf> AlphaFuncQCOM; ///< Wrapper for glAlphaFuncQCOM
    static Function<void, glmixed::GLenum, glmixed::GLfixed> AlphaFuncxOES; ///< Wrapper for glAlphaFuncxOES
    static Function<void, glmixed::GLenum> AlphaToCoverageDitherControlNV; ///< Wrapper for glAlphaToCoverageDitherControlNV
    static Function<void> ApplyFramebufferAttachmentCMAAINTEL; ///< Wrapper for glApplyFramebufferAttachmentCMAAINTEL
    static Function<void, glmixed::GLenum> ApplyTextureEXT; ///< Wrapper for glApplyTextureEXT
    static Function<glmixed::GLboolean, glmixed::GLsizei, const glmixed::GLuint *, glmixed::GLboolean *> AreProgramsResidentNV; ///< Wrapper for glAreProgramsResidentNV
    static Function<glmixed::GLboolean, glmixed::GLsizei, const glmixed::GLuint *, glmixed::GLboolean *> AreTexturesResident; ///< Wrapper for glAreTexturesResident
    static Function<glmixed::GLboolean, glmixed::GLsizei, const glmixed::GLuint *, glmixed::GLboolean *> AreTexturesResidentEXT; ///< Wrapper for glAreTexturesResidentEXT
    static Function<void, glmixed::GLint> ArrayElement; ///< Wrapper for glArrayElement
    static Function<void, glmixed::GLint> ArrayElementEXT; ///< Wrapper for glArrayElementEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLuint, glmixed::GLuint> ArrayObjectATI; ///< Wrapper for glArrayObjectATI
    static Function<glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *, const glmixed::GLuint64 *, glmixed::GLuint, glmixed::GLbitfield, glmixed::GLuint, glmixed::GLuint, glmixed::GLintptr, glmixed::GLintptr, glmixed::GLsizeiptr, glmixed::GLsizei, const glmixed::GLuint *, const glmixed::GLuint64 *> AsyncCopyBufferSubDataNVX; ///< Wrapper for glAsyncCopyBufferSubDataNVX
    static Function<glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *, const glmixed::GLuint64 *, glmixed::GLuint, glmixed::GLbitfield, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, const glmixed::GLuint *, const glmixed::GLuint64 *> AsyncCopyImageSubDataNVX; ///< Wrapper for glAsyncCopyImageSubDataNVX
    static Function<void, glmixed::GLuint> AsyncMarkerSGIX; ///< Wrapper for glAsyncMarkerSGIX
    static Function<void, glmixed::GLhandleARB, glmixed::GLhandleARB> AttachObjectARB; ///< Wrapper for glAttachObjectARB
    static Function<void, glmixed::GLuint, glmixed::GLuint> AttachShader; ///< Wrapper for glAttachShader
    static Function<void, glmixed::GLenum> Begin; ///< Wrapper for glBegin
    static Function<void, glmixed::GLuint, glmixed::GLenum> BeginConditionalRender; ///< Wrapper for glBeginConditionalRender
    static Function<void, glmixed::GLuint, glmixed::GLenum> BeginConditionalRenderNV; ///< Wrapper for glBeginConditionalRenderNV
    static Function<void, glmixed::GLuint> BeginConditionalRenderNVX; ///< Wrapper for glBeginConditionalRenderNVX
    static Function<void> BeginFragmentShaderATI; ///< Wrapper for glBeginFragmentShaderATI
    static Function<void, glmixed::GLuint> BeginOcclusionQueryNV; ///< Wrapper for glBeginOcclusionQueryNV
    static Function<void, glmixed::GLuint> BeginPerfMonitorAMD; ///< Wrapper for glBeginPerfMonitorAMD
    static Function<void, glmixed::GLuint> BeginPerfQueryINTEL; ///< Wrapper for glBeginPerfQueryINTEL
    static Function<void, glmixed::GLenum, glmixed::GLuint> BeginQuery; ///< Wrapper for glBeginQuery
    static Function<void, glmixed::GLenum, glmixed::GLuint> BeginQueryARB; ///< Wrapper for glBeginQueryARB
    static Function<void, glmixed::GLenum, glmixed::GLuint> BeginQueryEXT; ///< Wrapper for glBeginQueryEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint> BeginQueryIndexed; ///< Wrapper for glBeginQueryIndexed
    static Function<void, glmixed::GLenum> BeginTransformFeedback; ///< Wrapper for glBeginTransformFeedback
    static Function<void, glmixed::GLenum> BeginTransformFeedbackEXT; ///< Wrapper for glBeginTransformFeedbackEXT
    static Function<void, glmixed::GLenum> BeginTransformFeedbackNV; ///< Wrapper for glBeginTransformFeedbackNV
    static Function<void> BeginVertexShaderEXT; ///< Wrapper for glBeginVertexShaderEXT
    static Function<void, glmixed::GLuint> BeginVideoCaptureNV; ///< Wrapper for glBeginVideoCaptureNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, const glmixed::GLchar *> BindAttribLocation; ///< Wrapper for glBindAttribLocation
    static Function<void, glmixed::GLhandleARB, glmixed::GLuint, const glmixed::GLcharARB *> BindAttribLocationARB; ///< Wrapper for glBindAttribLocationARB
    static Function<void, glmixed::GLenum, glmixed::GLuint> BindBuffer; ///< Wrapper for glBindBuffer
    static Function<void, glmixed::GLenum, glmixed::GLuint> BindBufferARB; ///< Wrapper for glBindBufferARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint> BindBufferBase; ///< Wrapper for glBindBufferBase
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint> BindBufferBaseEXT; ///< Wrapper for glBindBufferBaseEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint> BindBufferBaseNV; ///< Wrapper for glBindBufferBaseNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLintptr> BindBufferOffsetEXT; ///< Wrapper for glBindBufferOffsetEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLintptr> BindBufferOffsetNV; ///< Wrapper for glBindBufferOffsetNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr> BindBufferRange; ///< Wrapper for glBindBufferRange
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr> BindBufferRangeEXT; ///< Wrapper for glBindBufferRangeEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr> BindBufferRangeNV; ///< Wrapper for glBindBufferRangeNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *> BindBuffersBase; ///< Wrapper for glBindBuffersBase
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *, const glmixed::GLintptr *, const glmixed::GLsizeiptr *> BindBuffersRange; ///< Wrapper for glBindBuffersRange
    static Function<void, glmixed::GLuint, glmixed::GLuint, const glmixed::GLchar *> BindFragDataLocation; ///< Wrapper for glBindFragDataLocation
    static Function<void, glmixed::GLuint, glmixed::GLuint, const glmixed::GLchar *> BindFragDataLocationEXT; ///< Wrapper for glBindFragDataLocationEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, const glmixed::GLchar *> BindFragDataLocationIndexed; ///< Wrapper for glBindFragDataLocationIndexed
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, const glmixed::GLchar *> BindFragDataLocationIndexedEXT; ///< Wrapper for glBindFragDataLocationIndexedEXT
    static Function<void, glmixed::GLuint> BindFragmentShaderATI; ///< Wrapper for glBindFragmentShaderATI
    static Function<void, glmixed::GLenum, glmixed::GLuint> BindFramebuffer; ///< Wrapper for glBindFramebuffer
    static Function<void, glmixed::GLenum, glmixed::GLuint> BindFramebufferEXT; ///< Wrapper for glBindFramebufferEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLboolean, glmixed::GLint, glmixed::GLenum, glmixed::GLenum> BindImageTexture; ///< Wrapper for glBindImageTexture
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLboolean, glmixed::GLint, glmixed::GLenum, glmixed::GLint> BindImageTextureEXT; ///< Wrapper for glBindImageTextureEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *> BindImageTextures; ///< Wrapper for glBindImageTextures
    static Function<glmixed::GLuint, glmixed::GLenum, glmixed::GLenum> BindLightParameterEXT; ///< Wrapper for glBindLightParameterEXT
    static Function<glmixed::GLuint, glmixed::GLenum, glmixed::GLenum> BindMaterialParameterEXT; ///< Wrapper for glBindMaterialParameterEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> BindMultiTextureEXT; ///< Wrapper for glBindMultiTextureEXT
    static Function<glmixed::GLuint, glmixed::GLenum> BindParameterEXT; ///< Wrapper for glBindParameterEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint> BindProgramARB; ///< Wrapper for glBindProgramARB
    static Function<void, glmixed::GLenum, glmixed::GLuint> BindProgramNV; ///< Wrapper for glBindProgramNV
    static Function<void, glmixed::GLuint> BindProgramPipeline; ///< Wrapper for glBindProgramPipeline
    static Function<void, glmixed::GLuint> BindProgramPipelineEXT; ///< Wrapper for glBindProgramPipelineEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint> BindRenderbuffer; ///< Wrapper for glBindRenderbuffer
    static Function<void, glmixed::GLenum, glmixed::GLuint> BindRenderbufferEXT; ///< Wrapper for glBindRenderbufferEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint> BindSampler; ///< Wrapper for glBindSampler
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *> BindSamplers; ///< Wrapper for glBindSamplers
    static Function<void, glmixed::GLuint> BindShadingRateImageNV; ///< Wrapper for glBindShadingRateImageNV
    static Function<glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum> BindTexGenParameterEXT; ///< Wrapper for glBindTexGenParameterEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint> BindTexture; ///< Wrapper for glBindTexture
    static Function<void, glmixed::GLenum, glmixed::GLuint> BindTextureEXT; ///< Wrapper for glBindTextureEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *> BindTextures; ///< Wrapper for glBindTextures
    static Function<void, glmixed::GLuint, glmixed::GLuint> BindTextureUnit; ///< Wrapper for glBindTextureUnit
    static Function<glmixed::GLuint, glmixed::GLenum, glmixed::GLenum> BindTextureUnitParameterEXT; ///< Wrapper for glBindTextureUnitParameterEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint> BindTransformFeedback; ///< Wrapper for glBindTransformFeedback
    static Function<void, glmixed::GLenum, glmixed::GLuint> BindTransformFeedbackNV; ///< Wrapper for glBindTransformFeedbackNV
    static Function<void, glmixed::GLuint> BindVertexArray; ///< Wrapper for glBindVertexArray
    static Function<void, glmixed::GLuint> BindVertexArrayAPPLE; ///< Wrapper for glBindVertexArrayAPPLE
    static Function<void, glmixed::GLuint> BindVertexArrayOES; ///< Wrapper for glBindVertexArrayOES
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizei> BindVertexBuffer; ///< Wrapper for glBindVertexBuffer
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *, const glmixed::GLintptr *, const glmixed::GLsizei *> BindVertexBuffers; ///< Wrapper for glBindVertexBuffers
    static Function<void, glmixed::GLuint> BindVertexShaderEXT; ///< Wrapper for glBindVertexShaderEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLintptrARB> BindVideoCaptureStreamBufferNV; ///< Wrapper for glBindVideoCaptureStreamBufferNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> BindVideoCaptureStreamTextureNV; ///< Wrapper for glBindVideoCaptureStreamTextureNV
    static Function<void, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte> Binormal3bEXT; ///< Wrapper for glBinormal3bEXT
    static Function<void, const glmixed::GLbyte *> Binormal3bvEXT; ///< Wrapper for glBinormal3bvEXT
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> Binormal3dEXT; ///< Wrapper for glBinormal3dEXT
    static Function<void, const glmixed::GLdouble *> Binormal3dvEXT; ///< Wrapper for glBinormal3dvEXT
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Binormal3fEXT; ///< Wrapper for glBinormal3fEXT
    static Function<void, const glmixed::GLfloat *> Binormal3fvEXT; ///< Wrapper for glBinormal3fvEXT
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint> Binormal3iEXT; ///< Wrapper for glBinormal3iEXT
    static Function<void, const glmixed::GLint *> Binormal3ivEXT; ///< Wrapper for glBinormal3ivEXT
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> Binormal3sEXT; ///< Wrapper for glBinormal3sEXT
    static Function<void, const glmixed::GLshort *> Binormal3svEXT; ///< Wrapper for glBinormal3svEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const void *> BinormalPointerEXT; ///< Wrapper for glBinormalPointerEXT
    static Function<void, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, const glmixed::GLubyte *> Bitmap; ///< Wrapper for glBitmap
    static Function<void, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, const glmixed::GLubyte *> BitmapxOES; ///< Wrapper for glBitmapxOES
    static Function<void> BlendBarrier; ///< Wrapper for glBlendBarrier
    static Function<void> BlendBarrierKHR; ///< Wrapper for glBlendBarrierKHR
    static Function<void> BlendBarrierNV; ///< Wrapper for glBlendBarrierNV
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> BlendColor; ///< Wrapper for glBlendColor
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> BlendColorEXT; ///< Wrapper for glBlendColorEXT
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> BlendColorxOES; ///< Wrapper for glBlendColorxOES
    static Function<void, glmixed::GLenum> BlendEquation; ///< Wrapper for glBlendEquation
    static Function<void, glmixed::GLenum> BlendEquationEXT; ///< Wrapper for glBlendEquationEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum> BlendEquationi; ///< Wrapper for glBlendEquationi
    static Function<void, glmixed::GLuint, glmixed::GLenum> BlendEquationiARB; ///< Wrapper for glBlendEquationiARB
    static Function<void, glmixed::GLuint, glmixed::GLenum> BlendEquationiEXT; ///< Wrapper for glBlendEquationiEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum> BlendEquationIndexedAMD; ///< Wrapper for glBlendEquationIndexedAMD
    static Function<void, glmixed::GLuint, glmixed::GLenum> BlendEquationiOES; ///< Wrapper for glBlendEquationiOES
    static Function<void, glmixed::GLenum, glmixed::GLenum> BlendEquationSeparate; ///< Wrapper for glBlendEquationSeparate
    static Function<void, glmixed::GLenum, glmixed::GLenum> BlendEquationSeparateEXT; ///< Wrapper for glBlendEquationSeparateEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum> BlendEquationSeparatei; ///< Wrapper for glBlendEquationSeparatei
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum> BlendEquationSeparateiARB; ///< Wrapper for glBlendEquationSeparateiARB
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum> BlendEquationSeparateiEXT; ///< Wrapper for glBlendEquationSeparateiEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum> BlendEquationSeparateIndexedAMD; ///< Wrapper for glBlendEquationSeparateIndexedAMD
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum> BlendEquationSeparateiOES; ///< Wrapper for glBlendEquationSeparateiOES
    static Function<void, glmixed::GLenum, glmixed::GLenum> BlendFunc; ///< Wrapper for glBlendFunc
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum> BlendFunci; ///< Wrapper for glBlendFunci
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum> BlendFunciARB; ///< Wrapper for glBlendFunciARB
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum> BlendFunciEXT; ///< Wrapper for glBlendFunciEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum> BlendFuncIndexedAMD; ///< Wrapper for glBlendFuncIndexedAMD
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum> BlendFunciOES; ///< Wrapper for glBlendFunciOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum> BlendFuncSeparate; ///< Wrapper for glBlendFuncSeparate
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum> BlendFuncSeparateEXT; ///< Wrapper for glBlendFuncSeparateEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum> BlendFuncSeparatei; ///< Wrapper for glBlendFuncSeparatei
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum> BlendFuncSeparateiARB; ///< Wrapper for glBlendFuncSeparateiARB
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum> BlendFuncSeparateiEXT; ///< Wrapper for glBlendFuncSeparateiEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum> BlendFuncSeparateIndexedAMD; ///< Wrapper for glBlendFuncSeparateIndexedAMD
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum> BlendFuncSeparateINGR; ///< Wrapper for glBlendFuncSeparateINGR
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum> BlendFuncSeparateiOES; ///< Wrapper for glBlendFuncSeparateiOES
    static Function<void, glmixed::GLenum, glmixed::GLint> BlendParameteriNV; ///< Wrapper for glBlendParameteriNV
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::ClearBufferMask, glmixed::GLenum> BlitFramebuffer; ///< Wrapper for glBlitFramebuffer
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::ClearBufferMask, glmixed::GLenum> BlitFramebufferANGLE; ///< Wrapper for glBlitFramebufferANGLE
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::ClearBufferMask, glmixed::GLenum> BlitFramebufferEXT; ///< Wrapper for glBlitFramebufferEXT
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::ClearBufferMask, glmixed::GLenum> BlitFramebufferLayerEXT; ///< Wrapper for glBlitFramebufferLayerEXT
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::ClearBufferMask, glmixed::GLenum> BlitFramebufferLayersEXT; ///< Wrapper for glBlitFramebufferLayersEXT
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::ClearBufferMask, glmixed::GLenum> BlitFramebufferNV; ///< Wrapper for glBlitFramebufferNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::ClearBufferMask, glmixed::GLenum> BlitNamedFramebuffer; ///< Wrapper for glBlitNamedFramebuffer
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint64EXT, glmixed::GLsizeiptr> BufferAddressRangeNV; ///< Wrapper for glBufferAddressRangeNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint64> BufferAttachMemoryNV; ///< Wrapper for glBufferAttachMemoryNV
    static Function<void, glmixed::GLenum, glmixed::GLsizeiptr, const void *, glmixed::GLenum> BufferData; ///< Wrapper for glBufferData
    static Function<void, glmixed::GLenum, glmixed::GLsizeiptrARB, const void *, glmixed::GLenum> BufferDataARB; ///< Wrapper for glBufferDataARB
    static Function<void, glmixed::GLenum, glmixed::GLintptr, glmixed::GLsizeiptr, glmixed::GLboolean> BufferPageCommitmentARB; ///< Wrapper for glBufferPageCommitmentARB
    static Function<void, glmixed::GLenum, glmixed::GLintptr, glmixed::GLsizeiptr, glmixed::GLuint, glmixed::GLuint64, glmixed::GLboolean> BufferPageCommitmentMemNV; ///< Wrapper for glBufferPageCommitmentMemNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> BufferParameteriAPPLE; ///< Wrapper for glBufferParameteriAPPLE
    static Function<void, glmixed::GLenum, glmixed::GLsizeiptr, const void *, glmixed::BufferStorageMask> BufferStorage; ///< Wrapper for glBufferStorage
    static Function<void, glmixed::GLenum, glmixed::GLsizeiptr, const void *, glmixed::BufferStorageMask> BufferStorageEXT; ///< Wrapper for glBufferStorageEXT
    static Function<void, glmixed::GLenum, glmixed::GLintptr, glmixed::GLsizeiptr, glmixed::GLeglClientBufferEXT, glmixed::BufferStorageMask> BufferStorageExternalEXT; ///< Wrapper for glBufferStorageExternalEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizeiptr, glmixed::GLuint, glmixed::GLuint64> BufferStorageMemEXT; ///< Wrapper for glBufferStorageMemEXT
    static Function<void, glmixed::GLenum, glmixed::GLintptr, glmixed::GLsizeiptr, const void *> BufferSubData; ///< Wrapper for glBufferSubData
    static Function<void, glmixed::GLenum, glmixed::GLintptrARB, glmixed::GLsizeiptrARB, const void *> BufferSubDataARB; ///< Wrapper for glBufferSubDataARB
    static Function<void, glmixed::GLuint> CallCommandListNV; ///< Wrapper for glCallCommandListNV
    static Function<void, glmixed::GLuint> CallList; ///< Wrapper for glCallList
    static Function<void, glmixed::GLsizei, glmixed::GLenum, const void *> CallLists; ///< Wrapper for glCallLists
    static Function<glmixed::GLenum, glmixed::GLenum> CheckFramebufferStatus; ///< Wrapper for glCheckFramebufferStatus
    static Function<glmixed::GLenum, glmixed::GLenum> CheckFramebufferStatusEXT; ///< Wrapper for glCheckFramebufferStatusEXT
    static Function<glmixed::GLenum, glmixed::GLuint, glmixed::GLenum> CheckNamedFramebufferStatus; ///< Wrapper for glCheckNamedFramebufferStatus
    static Function<glmixed::GLenum, glmixed::GLuint, glmixed::GLenum> CheckNamedFramebufferStatusEXT; ///< Wrapper for glCheckNamedFramebufferStatusEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum> ClampColor; ///< Wrapper for glClampColor
    static Function<void, glmixed::GLenum, glmixed::GLenum> ClampColorARB; ///< Wrapper for glClampColorARB
    static Function<void, glmixed::ClearBufferMask> Clear; ///< Wrapper for glClear
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ClearAccum; ///< Wrapper for glClearAccum
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> ClearAccumxOES; ///< Wrapper for glClearAccumxOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, const void *> ClearBufferData; ///< Wrapper for glClearBufferData
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLfloat, glmixed::GLint> ClearBufferfi; ///< Wrapper for glClearBufferfi
    static Function<void, glmixed::GLenum, glmixed::GLint, const glmixed::GLfloat *> ClearBufferfv; ///< Wrapper for glClearBufferfv
    static Function<void, glmixed::GLenum, glmixed::GLint, const glmixed::GLint *> ClearBufferiv; ///< Wrapper for glClearBufferiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLintptr, glmixed::GLsizeiptr, glmixed::GLenum, glmixed::GLenum, const void *> ClearBufferSubData; ///< Wrapper for glClearBufferSubData
    static Function<void, glmixed::GLenum, glmixed::GLint, const glmixed::GLuint *> ClearBufferuiv; ///< Wrapper for glClearBufferuiv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ClearColor; ///< Wrapper for glClearColor
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> ClearColorIiEXT; ///< Wrapper for glClearColorIiEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> ClearColorIuiEXT; ///< Wrapper for glClearColorIuiEXT
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> ClearColorxOES; ///< Wrapper for glClearColorxOES
    static Function<void, glmixed::GLdouble> ClearDepth; ///< Wrapper for glClearDepth
    static Function<void, glmixed::GLdouble> ClearDepthdNV; ///< Wrapper for glClearDepthdNV
    static Function<void, glmixed::GLfloat> ClearDepthf; ///< Wrapper for glClearDepthf
    static Function<void, glmixed::GLclampf> ClearDepthfOES; ///< Wrapper for glClearDepthfOES
    static Function<void, glmixed::GLfixed> ClearDepthxOES; ///< Wrapper for glClearDepthxOES
    static Function<void, glmixed::GLfloat> ClearIndex; ///< Wrapper for glClearIndex
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, const void *> ClearNamedBufferData; ///< Wrapper for glClearNamedBufferData
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, const void *> ClearNamedBufferDataEXT; ///< Wrapper for glClearNamedBufferDataEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLintptr, glmixed::GLsizeiptr, glmixed::GLenum, glmixed::GLenum, const void *> ClearNamedBufferSubData; ///< Wrapper for glClearNamedBufferSubData
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizeiptr, glmixed::GLsizeiptr, glmixed::GLenum, glmixed::GLenum, const void *> ClearNamedBufferSubDataEXT; ///< Wrapper for glClearNamedBufferSubDataEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLfloat, glmixed::GLint> ClearNamedFramebufferfi; ///< Wrapper for glClearNamedFramebufferfi
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, const glmixed::GLfloat *> ClearNamedFramebufferfv; ///< Wrapper for glClearNamedFramebufferfv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, const glmixed::GLint *> ClearNamedFramebufferiv; ///< Wrapper for glClearNamedFramebufferiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, const glmixed::GLuint *> ClearNamedFramebufferuiv; ///< Wrapper for glClearNamedFramebufferuiv
    static Function<void, glmixed::GLsizei, glmixed::GLsizei, const glmixed::GLuint *> ClearPixelLocalStorageuiEXT; ///< Wrapper for glClearPixelLocalStorageuiEXT
    static Function<void, glmixed::GLint> ClearStencil; ///< Wrapper for glClearStencil
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, const void *> ClearTexImage; ///< Wrapper for glClearTexImage
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, const void *> ClearTexImageEXT; ///< Wrapper for glClearTexImageEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> ClearTexSubImage; ///< Wrapper for glClearTexSubImage
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> ClearTexSubImageEXT; ///< Wrapper for glClearTexSubImageEXT
    static Function<void, glmixed::GLenum> ClientActiveTexture; ///< Wrapper for glClientActiveTexture
    static Function<void, glmixed::GLenum> ClientActiveTextureARB; ///< Wrapper for glClientActiveTextureARB
    static Function<void, glmixed::GLenum> ClientActiveVertexStreamATI; ///< Wrapper for glClientActiveVertexStreamATI
    static Function<void, glmixed::ClientAttribMask> ClientAttribDefaultEXT; ///< Wrapper for glClientAttribDefaultEXT
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *, const glmixed::GLuint64 *> ClientWaitSemaphoreui64NVX; ///< Wrapper for glClientWaitSemaphoreui64NVX
    static Function<glmixed::GLenum, glmixed::GLsync, glmixed::SyncObjectMask, glmixed::GLuint64> ClientWaitSync; ///< Wrapper for glClientWaitSync
    static Function<glmixed::GLenum, glmixed::GLsync, glmixed::SyncObjectMask, glmixed::GLuint64> ClientWaitSyncAPPLE; ///< Wrapper for glClientWaitSyncAPPLE
    static Function<void, glmixed::GLenum, glmixed::GLenum> ClipControl; ///< Wrapper for glClipControl
    static Function<void, glmixed::GLenum, glmixed::GLenum> ClipControlEXT; ///< Wrapper for glClipControlEXT
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> ClipPlane; ///< Wrapper for glClipPlane
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> ClipPlanefOES; ///< Wrapper for glClipPlanefOES
    static Function<void, glmixed::GLenum, const glmixed::GLfixed *> ClipPlanexOES; ///< Wrapper for glClipPlanexOES
    static Function<void, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte> Color3b; ///< Wrapper for glColor3b
    static Function<void, const glmixed::GLbyte *> Color3bv; ///< Wrapper for glColor3bv
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> Color3d; ///< Wrapper for glColor3d
    static Function<void, const glmixed::GLdouble *> Color3dv; ///< Wrapper for glColor3dv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Color3f; ///< Wrapper for glColor3f
    static Function<void, const glmixed::GLfloat *> Color3fv; ///< Wrapper for glColor3fv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Color3fVertex3fSUN; ///< Wrapper for glColor3fVertex3fSUN
    static Function<void, const glmixed::GLfloat *, const glmixed::GLfloat *> Color3fVertex3fvSUN; ///< Wrapper for glColor3fVertex3fvSUN
    static Function<void, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV> Color3hNV; ///< Wrapper for glColor3hNV
    static Function<void, const glmixed::GLhalfNV *> Color3hvNV; ///< Wrapper for glColor3hvNV
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint> Color3i; ///< Wrapper for glColor3i
    static Function<void, const glmixed::GLint *> Color3iv; ///< Wrapper for glColor3iv
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> Color3s; ///< Wrapper for glColor3s
    static Function<void, const glmixed::GLshort *> Color3sv; ///< Wrapper for glColor3sv
    static Function<void, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte> Color3ub; ///< Wrapper for glColor3ub
    static Function<void, const glmixed::GLubyte *> Color3ubv; ///< Wrapper for glColor3ubv
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> Color3ui; ///< Wrapper for glColor3ui
    static Function<void, const glmixed::GLuint *> Color3uiv; ///< Wrapper for glColor3uiv
    static Function<void, glmixed::GLushort, glmixed::GLushort, glmixed::GLushort> Color3us; ///< Wrapper for glColor3us
    static Function<void, const glmixed::GLushort *> Color3usv; ///< Wrapper for glColor3usv
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> Color3xOES; ///< Wrapper for glColor3xOES
    static Function<void, const glmixed::GLfixed *> Color3xvOES; ///< Wrapper for glColor3xvOES
    static Function<void, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte> Color4b; ///< Wrapper for glColor4b
    static Function<void, const glmixed::GLbyte *> Color4bv; ///< Wrapper for glColor4bv
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> Color4d; ///< Wrapper for glColor4d
    static Function<void, const glmixed::GLdouble *> Color4dv; ///< Wrapper for glColor4dv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Color4f; ///< Wrapper for glColor4f
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Color4fNormal3fVertex3fSUN; ///< Wrapper for glColor4fNormal3fVertex3fSUN
    static Function<void, const glmixed::GLfloat *, const glmixed::GLfloat *, const glmixed::GLfloat *> Color4fNormal3fVertex3fvSUN; ///< Wrapper for glColor4fNormal3fVertex3fvSUN
    static Function<void, const glmixed::GLfloat *> Color4fv; ///< Wrapper for glColor4fv
    static Function<void, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV> Color4hNV; ///< Wrapper for glColor4hNV
    static Function<void, const glmixed::GLhalfNV *> Color4hvNV; ///< Wrapper for glColor4hvNV
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> Color4i; ///< Wrapper for glColor4i
    static Function<void, const glmixed::GLint *> Color4iv; ///< Wrapper for glColor4iv
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> Color4s; ///< Wrapper for glColor4s
    static Function<void, const glmixed::GLshort *> Color4sv; ///< Wrapper for glColor4sv
    static Function<void, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte> Color4ub; ///< Wrapper for glColor4ub
    static Function<void, const glmixed::GLubyte *> Color4ubv; ///< Wrapper for glColor4ubv
    static Function<void, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLfloat, glmixed::GLfloat> Color4ubVertex2fSUN; ///< Wrapper for glColor4ubVertex2fSUN
    static Function<void, const glmixed::GLubyte *, const glmixed::GLfloat *> Color4ubVertex2fvSUN; ///< Wrapper for glColor4ubVertex2fvSUN
    static Function<void, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Color4ubVertex3fSUN; ///< Wrapper for glColor4ubVertex3fSUN
    static Function<void, const glmixed::GLubyte *, const glmixed::GLfloat *> Color4ubVertex3fvSUN; ///< Wrapper for glColor4ubVertex3fvSUN
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> Color4ui; ///< Wrapper for glColor4ui
    static Function<void, const glmixed::GLuint *> Color4uiv; ///< Wrapper for glColor4uiv
    static Function<void, glmixed::GLushort, glmixed::GLushort, glmixed::GLushort, glmixed::GLushort> Color4us; ///< Wrapper for glColor4us
    static Function<void, const glmixed::GLushort *> Color4usv; ///< Wrapper for glColor4usv
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> Color4xOES; ///< Wrapper for glColor4xOES
    static Function<void, const glmixed::GLfixed *> Color4xvOES; ///< Wrapper for glColor4xvOES
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei> ColorFormatNV; ///< Wrapper for glColorFormatNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::FragmentShaderDestMaskATI, glmixed::FragmentShaderDestModMaskATI, glmixed::GLuint, glmixed::GLuint, glmixed::FragmentShaderColorModMaskATI> ColorFragmentOp1ATI; ///< Wrapper for glColorFragmentOp1ATI
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::FragmentShaderDestMaskATI, glmixed::FragmentShaderDestModMaskATI, glmixed::GLuint, glmixed::GLuint, glmixed::FragmentShaderColorModMaskATI, glmixed::GLuint, glmixed::GLuint, glmixed::FragmentShaderColorModMaskATI> ColorFragmentOp2ATI; ///< Wrapper for glColorFragmentOp2ATI
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::FragmentShaderDestMaskATI, glmixed::FragmentShaderDestModMaskATI, glmixed::GLuint, glmixed::GLuint, glmixed::FragmentShaderColorModMaskATI, glmixed::GLuint, glmixed::GLuint, glmixed::FragmentShaderColorModMaskATI, glmixed::GLuint, glmixed::GLuint, glmixed::FragmentShaderColorModMaskATI> ColorFragmentOp3ATI; ///< Wrapper for glColorFragmentOp3ATI
    static Function<void, glmixed::GLboolean, glmixed::GLboolean, glmixed::GLboolean, glmixed::GLboolean> ColorMask; ///< Wrapper for glColorMask
    static Function<void, glmixed::GLuint, glmixed::GLboolean, glmixed::GLboolean, glmixed::GLboolean, glmixed::GLboolean> ColorMaski; ///< Wrapper for glColorMaski
    static Function<void, glmixed::GLuint, glmixed::GLboolean, glmixed::GLboolean, glmixed::GLboolean, glmixed::GLboolean> ColorMaskiEXT; ///< Wrapper for glColorMaskiEXT
    static Function<void, glmixed::GLuint, glmixed::GLboolean, glmixed::GLboolean, glmixed::GLboolean, glmixed::GLboolean> ColorMaskIndexedEXT; ///< Wrapper for glColorMaskIndexedEXT
    static Function<void, glmixed::GLuint, glmixed::GLboolean, glmixed::GLboolean, glmixed::GLboolean, glmixed::GLboolean> ColorMaskiOES; ///< Wrapper for glColorMaskiOES
    static Function<void, glmixed::GLenum, glmixed::GLenum> ColorMaterial; ///< Wrapper for glColorMaterial
    static Function<void, glmixed::GLenum, glmixed::GLuint> ColorP3ui; ///< Wrapper for glColorP3ui
    static Function<void, glmixed::GLenum, const glmixed::GLuint *> ColorP3uiv; ///< Wrapper for glColorP3uiv
    static Function<void, glmixed::GLenum, glmixed::GLuint> ColorP4ui; ///< Wrapper for glColorP4ui
    static Function<void, glmixed::GLenum, const glmixed::GLuint *> ColorP4uiv; ///< Wrapper for glColorP4uiv
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, const void *> ColorPointer; ///< Wrapper for glColorPointer
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, const void *> ColorPointerEXT; ///< Wrapper for glColorPointerEXT
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLint, const void **, glmixed::GLint> ColorPointerListIBM; ///< Wrapper for glColorPointerListIBM
    static Function<void, glmixed::GLint, glmixed::GLenum, const void **> ColorPointervINTEL; ///< Wrapper for glColorPointervINTEL
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> ColorSubTable; ///< Wrapper for glColorSubTable
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> ColorSubTableEXT; ///< Wrapper for glColorSubTableEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> ColorTable; ///< Wrapper for glColorTable
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> ColorTableEXT; ///< Wrapper for glColorTableEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> ColorTableParameterfv; ///< Wrapper for glColorTableParameterfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> ColorTableParameterfvSGI; ///< Wrapper for glColorTableParameterfvSGI
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> ColorTableParameteriv; ///< Wrapper for glColorTableParameteriv
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> ColorTableParameterivSGI; ///< Wrapper for glColorTableParameterivSGI
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> ColorTableSGI; ///< Wrapper for glColorTableSGI
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum> CombinerInputNV; ///< Wrapper for glCombinerInputNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLboolean, glmixed::GLboolean, glmixed::GLboolean> CombinerOutputNV; ///< Wrapper for glCombinerOutputNV
    static Function<void, glmixed::GLenum, glmixed::GLfloat> CombinerParameterfNV; ///< Wrapper for glCombinerParameterfNV
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> CombinerParameterfvNV; ///< Wrapper for glCombinerParameterfvNV
    static Function<void, glmixed::GLenum, glmixed::GLint> CombinerParameteriNV; ///< Wrapper for glCombinerParameteriNV
    static Function<void, glmixed::GLenum, const glmixed::GLint *> CombinerParameterivNV; ///< Wrapper for glCombinerParameterivNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> CombinerStageParameterfvNV; ///< Wrapper for glCombinerStageParameterfvNV
    static Function<void, glmixed::GLuint, glmixed::GLuint> CommandListSegmentsNV; ///< Wrapper for glCommandListSegmentsNV
    static Function<void, glmixed::GLuint> CompileCommandListNV; ///< Wrapper for glCompileCommandListNV
    static Function<void, glmixed::GLuint> CompileShader; ///< Wrapper for glCompileShader
    static Function<void, glmixed::GLhandleARB> CompileShaderARB; ///< Wrapper for glCompileShaderARB
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLchar *const*, const glmixed::GLint *> CompileShaderIncludeARB; ///< Wrapper for glCompileShaderIncludeARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, const void *> CompressedMultiTexImage1DEXT; ///< Wrapper for glCompressedMultiTexImage1DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, const void *> CompressedMultiTexImage2DEXT; ///< Wrapper for glCompressedMultiTexImage2DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, const void *> CompressedMultiTexImage3DEXT; ///< Wrapper for glCompressedMultiTexImage3DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, const void *> CompressedMultiTexSubImage1DEXT; ///< Wrapper for glCompressedMultiTexSubImage1DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, const void *> CompressedMultiTexSubImage2DEXT; ///< Wrapper for glCompressedMultiTexSubImage2DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, const void *> CompressedMultiTexSubImage3DEXT; ///< Wrapper for glCompressedMultiTexSubImage3DEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, const void *> CompressedTexImage1D; ///< Wrapper for glCompressedTexImage1D
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, const void *> CompressedTexImage1DARB; ///< Wrapper for glCompressedTexImage1DARB
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, const void *> CompressedTexImage2D; ///< Wrapper for glCompressedTexImage2D
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, const void *> CompressedTexImage2DARB; ///< Wrapper for glCompressedTexImage2DARB
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, const void *> CompressedTexImage3D; ///< Wrapper for glCompressedTexImage3D
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, const void *> CompressedTexImage3DARB; ///< Wrapper for glCompressedTexImage3DARB
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, const void *> CompressedTexImage3DOES; ///< Wrapper for glCompressedTexImage3DOES
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, const void *> CompressedTexSubImage1D; ///< Wrapper for glCompressedTexSubImage1D
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, const void *> CompressedTexSubImage1DARB; ///< Wrapper for glCompressedTexSubImage1DARB
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, const void *> CompressedTexSubImage2D; ///< Wrapper for glCompressedTexSubImage2D
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, const void *> CompressedTexSubImage2DARB; ///< Wrapper for glCompressedTexSubImage2DARB
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, const void *> CompressedTexSubImage3D; ///< Wrapper for glCompressedTexSubImage3D
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, const void *> CompressedTexSubImage3DARB; ///< Wrapper for glCompressedTexSubImage3DARB
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, const void *> CompressedTexSubImage3DOES; ///< Wrapper for glCompressedTexSubImage3DOES
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, const void *> CompressedTextureImage1DEXT; ///< Wrapper for glCompressedTextureImage1DEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, const void *> CompressedTextureImage2DEXT; ///< Wrapper for glCompressedTextureImage2DEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, const void *> CompressedTextureImage3DEXT; ///< Wrapper for glCompressedTextureImage3DEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, const void *> CompressedTextureSubImage1D; ///< Wrapper for glCompressedTextureSubImage1D
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, const void *> CompressedTextureSubImage1DEXT; ///< Wrapper for glCompressedTextureSubImage1DEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, const void *> CompressedTextureSubImage2D; ///< Wrapper for glCompressedTextureSubImage2D
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, const void *> CompressedTextureSubImage2DEXT; ///< Wrapper for glCompressedTextureSubImage2DEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, const void *> CompressedTextureSubImage3D; ///< Wrapper for glCompressedTextureSubImage3D
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, const void *> CompressedTextureSubImage3DEXT; ///< Wrapper for glCompressedTextureSubImage3DEXT
    static Function<void, glmixed::GLenum, glmixed::GLfloat> ConservativeRasterParameterfNV; ///< Wrapper for glConservativeRasterParameterfNV
    static Function<void, glmixed::GLenum, glmixed::GLint> ConservativeRasterParameteriNV; ///< Wrapper for glConservativeRasterParameteriNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> ConvolutionFilter1D; ///< Wrapper for glConvolutionFilter1D
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> ConvolutionFilter1DEXT; ///< Wrapper for glConvolutionFilter1DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> ConvolutionFilter2D; ///< Wrapper for glConvolutionFilter2D
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> ConvolutionFilter2DEXT; ///< Wrapper for glConvolutionFilter2DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat> ConvolutionParameterf; ///< Wrapper for glConvolutionParameterf
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat> ConvolutionParameterfEXT; ///< Wrapper for glConvolutionParameterfEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> ConvolutionParameterfv; ///< Wrapper for glConvolutionParameterfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> ConvolutionParameterfvEXT; ///< Wrapper for glConvolutionParameterfvEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> ConvolutionParameteri; ///< Wrapper for glConvolutionParameteri
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> ConvolutionParameteriEXT; ///< Wrapper for glConvolutionParameteriEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> ConvolutionParameteriv; ///< Wrapper for glConvolutionParameteriv
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> ConvolutionParameterivEXT; ///< Wrapper for glConvolutionParameterivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfixed> ConvolutionParameterxOES; ///< Wrapper for glConvolutionParameterxOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfixed *> ConvolutionParameterxvOES; ///< Wrapper for glConvolutionParameterxvOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLintptr, glmixed::GLintptr, glmixed::GLsizeiptr> CopyBufferSubData; ///< Wrapper for glCopyBufferSubData
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLintptr, glmixed::GLintptr, glmixed::GLsizeiptr> CopyBufferSubDataNV; ///< Wrapper for glCopyBufferSubDataNV
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLint, glmixed::GLint, glmixed::GLsizei> CopyColorSubTable; ///< Wrapper for glCopyColorSubTable
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLint, glmixed::GLint, glmixed::GLsizei> CopyColorSubTableEXT; ///< Wrapper for glCopyColorSubTableEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei> CopyColorTable; ///< Wrapper for glCopyColorTable
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei> CopyColorTableSGI; ///< Wrapper for glCopyColorTableSGI
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei> CopyConvolutionFilter1D; ///< Wrapper for glCopyConvolutionFilter1D
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei> CopyConvolutionFilter1DEXT; ///< Wrapper for glCopyConvolutionFilter1DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> CopyConvolutionFilter2D; ///< Wrapper for glCopyConvolutionFilter2D
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> CopyConvolutionFilter2DEXT; ///< Wrapper for glCopyConvolutionFilter2DEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei> CopyImageSubData; ///< Wrapper for glCopyImageSubData
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei> CopyImageSubDataEXT; ///< Wrapper for glCopyImageSubDataEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei> CopyImageSubDataNV; ///< Wrapper for glCopyImageSubDataNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei> CopyImageSubDataOES; ///< Wrapper for glCopyImageSubDataOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLint> CopyMultiTexImage1DEXT; ///< Wrapper for glCopyMultiTexImage1DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint> CopyMultiTexImage2DEXT; ///< Wrapper for glCopyMultiTexImage2DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei> CopyMultiTexSubImage1DEXT; ///< Wrapper for glCopyMultiTexSubImage1DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> CopyMultiTexSubImage2DEXT; ///< Wrapper for glCopyMultiTexSubImage2DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> CopyMultiTexSubImage3DEXT; ///< Wrapper for glCopyMultiTexSubImage3DEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLintptr, glmixed::GLintptr, glmixed::GLsizeiptr> CopyNamedBufferSubData; ///< Wrapper for glCopyNamedBufferSubData
    static Function<void, glmixed::GLuint, glmixed::GLuint> CopyPathNV; ///< Wrapper for glCopyPathNV
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum> CopyPixels; ///< Wrapper for glCopyPixels
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLint> CopyTexImage1D; ///< Wrapper for glCopyTexImage1D
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLint> CopyTexImage1DEXT; ///< Wrapper for glCopyTexImage1DEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint> CopyTexImage2D; ///< Wrapper for glCopyTexImage2D
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint> CopyTexImage2DEXT; ///< Wrapper for glCopyTexImage2DEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei> CopyTexSubImage1D; ///< Wrapper for glCopyTexSubImage1D
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei> CopyTexSubImage1DEXT; ///< Wrapper for glCopyTexSubImage1DEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> CopyTexSubImage2D; ///< Wrapper for glCopyTexSubImage2D
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> CopyTexSubImage2DEXT; ///< Wrapper for glCopyTexSubImage2DEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> CopyTexSubImage3D; ///< Wrapper for glCopyTexSubImage3D
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> CopyTexSubImage3DEXT; ///< Wrapper for glCopyTexSubImage3DEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> CopyTexSubImage3DOES; ///< Wrapper for glCopyTexSubImage3DOES
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLint> CopyTextureImage1DEXT; ///< Wrapper for glCopyTextureImage1DEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint> CopyTextureImage2DEXT; ///< Wrapper for glCopyTextureImage2DEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei> CopyTextureLevelsAPPLE; ///< Wrapper for glCopyTextureLevelsAPPLE
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei> CopyTextureSubImage1D; ///< Wrapper for glCopyTextureSubImage1D
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei> CopyTextureSubImage1DEXT; ///< Wrapper for glCopyTextureSubImage1DEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> CopyTextureSubImage2D; ///< Wrapper for glCopyTextureSubImage2D
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> CopyTextureSubImage2DEXT; ///< Wrapper for glCopyTextureSubImage2DEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> CopyTextureSubImage3D; ///< Wrapper for glCopyTextureSubImage3D
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> CopyTextureSubImage3DEXT; ///< Wrapper for glCopyTextureSubImage3DEXT
    static Function<void, glmixed::GLboolean> CoverageMaskNV; ///< Wrapper for glCoverageMaskNV
    static Function<void, glmixed::GLenum> CoverageModulationNV; ///< Wrapper for glCoverageModulationNV
    static Function<void, glmixed::GLsizei, const glmixed::GLfloat *> CoverageModulationTableNV; ///< Wrapper for glCoverageModulationTableNV
    static Function<void, glmixed::GLenum> CoverageOperationNV; ///< Wrapper for glCoverageOperationNV
    static Function<void, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> CoverFillPathInstancedNV; ///< Wrapper for glCoverFillPathInstancedNV
    static Function<void, glmixed::GLuint, glmixed::GLenum> CoverFillPathNV; ///< Wrapper for glCoverFillPathNV
    static Function<void, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> CoverStrokePathInstancedNV; ///< Wrapper for glCoverStrokePathInstancedNV
    static Function<void, glmixed::GLuint, glmixed::GLenum> CoverStrokePathNV; ///< Wrapper for glCoverStrokePathNV
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> CreateBuffers; ///< Wrapper for glCreateBuffers
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> CreateCommandListsNV; ///< Wrapper for glCreateCommandListsNV
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> CreateFramebuffers; ///< Wrapper for glCreateFramebuffers
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> CreateMemoryObjectsEXT; ///< Wrapper for glCreateMemoryObjectsEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint *> CreatePerfQueryINTEL; ///< Wrapper for glCreatePerfQueryINTEL
    static Function<glmixed::GLuint> CreateProgram; ///< Wrapper for glCreateProgram
    static Function<glmixed::GLhandleARB> CreateProgramObjectARB; ///< Wrapper for glCreateProgramObjectARB
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> CreateProgramPipelines; ///< Wrapper for glCreateProgramPipelines
    static Function<glmixed::GLuint> CreateProgressFenceNVX; ///< Wrapper for glCreateProgressFenceNVX
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLuint *> CreateQueries; ///< Wrapper for glCreateQueries
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> CreateRenderbuffers; ///< Wrapper for glCreateRenderbuffers
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> CreateSamplers; ///< Wrapper for glCreateSamplers
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> CreateSemaphoresNV; ///< Wrapper for glCreateSemaphoresNV
    static Function<glmixed::GLuint, glmixed::GLenum> CreateShader; ///< Wrapper for glCreateShader
    static Function<glmixed::GLhandleARB, glmixed::GLenum> CreateShaderObjectARB; ///< Wrapper for glCreateShaderObjectARB
    static Function<glmixed::GLuint, glmixed::GLenum, const glmixed::GLchar *> CreateShaderProgramEXT; ///< Wrapper for glCreateShaderProgramEXT
    static Function<glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLchar *const*> CreateShaderProgramv; ///< Wrapper for glCreateShaderProgramv
    static Function<glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLchar *const*> CreateShaderProgramvEXT; ///< Wrapper for glCreateShaderProgramvEXT
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> CreateStatesNV; ///< Wrapper for glCreateStatesNV
    static Function<glmixed::GLsync, glmixed::_cl_context *, glmixed::_cl_event *, glmixed::GLbitfield> CreateSyncFromCLeventARB; ///< Wrapper for glCreateSyncFromCLeventARB
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLuint *> CreateTextures; ///< Wrapper for glCreateTextures
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> CreateTransformFeedbacks; ///< Wrapper for glCreateTransformFeedbacks
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> CreateVertexArrays; ///< Wrapper for glCreateVertexArrays
    static Function<void, glmixed::GLenum> CullFace; ///< Wrapper for glCullFace
    static Function<void, glmixed::GLenum, glmixed::GLdouble *> CullParameterdvEXT; ///< Wrapper for glCullParameterdvEXT
    static Function<void, glmixed::GLenum, glmixed::GLfloat *> CullParameterfvEXT; ///< Wrapper for glCullParameterfvEXT
    static Function<void, glmixed::GLint> CurrentPaletteMatrixARB; ///< Wrapper for glCurrentPaletteMatrixARB
    static Function<void, glmixed::GLDEBUGPROC, const void *> DebugMessageCallback; ///< Wrapper for glDebugMessageCallback
    static Function<void, glmixed::GLDEBUGPROCAMD, void *> DebugMessageCallbackAMD; ///< Wrapper for glDebugMessageCallbackAMD
    static Function<void, glmixed::GLDEBUGPROCARB, const void *> DebugMessageCallbackARB; ///< Wrapper for glDebugMessageCallbackARB
    static Function<void, glmixed::GLDEBUGPROCKHR, const void *> DebugMessageCallbackKHR; ///< Wrapper for glDebugMessageCallbackKHR
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLuint *, glmixed::GLboolean> DebugMessageControl; ///< Wrapper for glDebugMessageControl
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLuint *, glmixed::GLboolean> DebugMessageControlARB; ///< Wrapper for glDebugMessageControlARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLuint *, glmixed::GLboolean> DebugMessageControlKHR; ///< Wrapper for glDebugMessageControlKHR
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLuint *, glmixed::GLboolean> DebugMessageEnableAMD; ///< Wrapper for glDebugMessageEnableAMD
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLchar *> DebugMessageInsert; ///< Wrapper for glDebugMessageInsert
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLchar *> DebugMessageInsertAMD; ///< Wrapper for glDebugMessageInsertAMD
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLchar *> DebugMessageInsertARB; ///< Wrapper for glDebugMessageInsertARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLchar *> DebugMessageInsertKHR; ///< Wrapper for glDebugMessageInsertKHR
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLint, glmixed::GLint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLint, glmixed::GLint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLint, glmixed::GLint, const glmixed::GLdouble *> DeformationMap3dSGIX; ///< Wrapper for glDeformationMap3dSGIX
    static Function<void, glmixed::GLenum, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLint, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLint, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLint, glmixed::GLint, const glmixed::GLfloat *> DeformationMap3fSGIX; ///< Wrapper for glDeformationMap3fSGIX
    static Function<void, glmixed::FfdMaskSGIX> DeformSGIX; ///< Wrapper for glDeformSGIX
    static Function<void, glmixed::GLuint, glmixed::GLsizei> DeleteAsyncMarkersSGIX; ///< Wrapper for glDeleteAsyncMarkersSGIX
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteBuffers; ///< Wrapper for glDeleteBuffers
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteBuffersARB; ///< Wrapper for glDeleteBuffersARB
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteCommandListsNV; ///< Wrapper for glDeleteCommandListsNV
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteFencesAPPLE; ///< Wrapper for glDeleteFencesAPPLE
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteFencesNV; ///< Wrapper for glDeleteFencesNV
    static Function<void, glmixed::GLuint> DeleteFragmentShaderATI; ///< Wrapper for glDeleteFragmentShaderATI
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteFramebuffers; ///< Wrapper for glDeleteFramebuffers
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteFramebuffersEXT; ///< Wrapper for glDeleteFramebuffersEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei> DeleteLists; ///< Wrapper for glDeleteLists
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteMemoryObjectsEXT; ///< Wrapper for glDeleteMemoryObjectsEXT
    static Function<void, glmixed::GLint, const glmixed::GLchar *> DeleteNamedStringARB; ///< Wrapper for glDeleteNamedStringARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, const glmixed::GLuint *> DeleteNamesAMD; ///< Wrapper for glDeleteNamesAMD
    static Function<void, glmixed::GLhandleARB> DeleteObjectARB; ///< Wrapper for glDeleteObjectARB
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteOcclusionQueriesNV; ///< Wrapper for glDeleteOcclusionQueriesNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei> DeletePathsNV; ///< Wrapper for glDeletePathsNV
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> DeletePerfMonitorsAMD; ///< Wrapper for glDeletePerfMonitorsAMD
    static Function<void, glmixed::GLuint> DeletePerfQueryINTEL; ///< Wrapper for glDeletePerfQueryINTEL
    static Function<void, glmixed::GLuint> DeleteProgram; ///< Wrapper for glDeleteProgram
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteProgramPipelines; ///< Wrapper for glDeleteProgramPipelines
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteProgramPipelinesEXT; ///< Wrapper for glDeleteProgramPipelinesEXT
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteProgramsARB; ///< Wrapper for glDeleteProgramsARB
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteProgramsNV; ///< Wrapper for glDeleteProgramsNV
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteQueries; ///< Wrapper for glDeleteQueries
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteQueriesARB; ///< Wrapper for glDeleteQueriesARB
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteQueriesEXT; ///< Wrapper for glDeleteQueriesEXT
    static Function<void, glmixed::GLsizei, const glmixed::GLint *> DeleteQueryResourceTagNV; ///< Wrapper for glDeleteQueryResourceTagNV
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteRenderbuffers; ///< Wrapper for glDeleteRenderbuffers
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteRenderbuffersEXT; ///< Wrapper for glDeleteRenderbuffersEXT
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteSamplers; ///< Wrapper for glDeleteSamplers
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteSemaphoresEXT; ///< Wrapper for glDeleteSemaphoresEXT
    static Function<void, glmixed::GLuint> DeleteShader; ///< Wrapper for glDeleteShader
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteStatesNV; ///< Wrapper for glDeleteStatesNV
    static Function<void, glmixed::GLsync> DeleteSync; ///< Wrapper for glDeleteSync
    static Function<void, glmixed::GLsync> DeleteSyncAPPLE; ///< Wrapper for glDeleteSyncAPPLE
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteTextures; ///< Wrapper for glDeleteTextures
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteTexturesEXT; ///< Wrapper for glDeleteTexturesEXT
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteTransformFeedbacks; ///< Wrapper for glDeleteTransformFeedbacks
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteTransformFeedbacksNV; ///< Wrapper for glDeleteTransformFeedbacksNV
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteVertexArrays; ///< Wrapper for glDeleteVertexArrays
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteVertexArraysAPPLE; ///< Wrapper for glDeleteVertexArraysAPPLE
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> DeleteVertexArraysOES; ///< Wrapper for glDeleteVertexArraysOES
    static Function<void, glmixed::GLuint> DeleteVertexShaderEXT; ///< Wrapper for glDeleteVertexShaderEXT
    static Function<void, glmixed::GLdouble, glmixed::GLdouble> DepthBoundsdNV; ///< Wrapper for glDepthBoundsdNV
    static Function<void, glmixed::GLclampd, glmixed::GLclampd> DepthBoundsEXT; ///< Wrapper for glDepthBoundsEXT
    static Function<void, glmixed::GLenum> DepthFunc; ///< Wrapper for glDepthFunc
    static Function<void, glmixed::GLboolean> DepthMask; ///< Wrapper for glDepthMask
    static Function<void, glmixed::GLdouble, glmixed::GLdouble> DepthRange; ///< Wrapper for glDepthRange
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLdouble *> DepthRangeArraydvNV; ///< Wrapper for glDepthRangeArraydvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> DepthRangeArrayfvNV; ///< Wrapper for glDepthRangeArrayfvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> DepthRangeArrayfvOES; ///< Wrapper for glDepthRangeArrayfvOES
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLdouble *> DepthRangeArrayv; ///< Wrapper for glDepthRangeArrayv
    static Function<void, glmixed::GLdouble, glmixed::GLdouble> DepthRangedNV; ///< Wrapper for glDepthRangedNV
    static Function<void, glmixed::GLfloat, glmixed::GLfloat> DepthRangef; ///< Wrapper for glDepthRangef
    static Function<void, glmixed::GLclampf, glmixed::GLclampf> DepthRangefOES; ///< Wrapper for glDepthRangefOES
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble> DepthRangeIndexed; ///< Wrapper for glDepthRangeIndexed
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble> DepthRangeIndexeddNV; ///< Wrapper for glDepthRangeIndexeddNV
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat> DepthRangeIndexedfNV; ///< Wrapper for glDepthRangeIndexedfNV
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat> DepthRangeIndexedfOES; ///< Wrapper for glDepthRangeIndexedfOES
    static Function<void, glmixed::GLfixed, glmixed::GLfixed> DepthRangexOES; ///< Wrapper for glDepthRangexOES
    static Function<void, glmixed::GLhandleARB, glmixed::GLhandleARB> DetachObjectARB; ///< Wrapper for glDetachObjectARB
    static Function<void, glmixed::GLuint, glmixed::GLuint> DetachShader; ///< Wrapper for glDetachShader
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLfloat *> DetailTexFuncSGIS; ///< Wrapper for glDetailTexFuncSGIS
    static Function<void, glmixed::GLenum> Disable; ///< Wrapper for glDisable
    static Function<void, glmixed::GLenum> DisableClientState; ///< Wrapper for glDisableClientState
    static Function<void, glmixed::GLenum, glmixed::GLuint> DisableClientStateiEXT; ///< Wrapper for glDisableClientStateiEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint> DisableClientStateIndexedEXT; ///< Wrapper for glDisableClientStateIndexedEXT
    static Function<void, glmixed::GLuint> DisableDriverControlQCOM; ///< Wrapper for glDisableDriverControlQCOM
    static Function<void, glmixed::GLenum, glmixed::GLuint> Disablei; ///< Wrapper for glDisablei
    static Function<void, glmixed::GLenum, glmixed::GLuint> DisableiEXT; ///< Wrapper for glDisableiEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint> DisableIndexedEXT; ///< Wrapper for glDisableIndexedEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint> DisableiNV; ///< Wrapper for glDisableiNV
    static Function<void, glmixed::GLenum, glmixed::GLuint> DisableiOES; ///< Wrapper for glDisableiOES
    static Function<void, glmixed::GLuint> DisableVariantClientStateEXT; ///< Wrapper for glDisableVariantClientStateEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint> DisableVertexArrayAttrib; ///< Wrapper for glDisableVertexArrayAttrib
    static Function<void, glmixed::GLuint, glmixed::GLuint> DisableVertexArrayAttribEXT; ///< Wrapper for glDisableVertexArrayAttribEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum> DisableVertexArrayEXT; ///< Wrapper for glDisableVertexArrayEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum> DisableVertexAttribAPPLE; ///< Wrapper for glDisableVertexAttribAPPLE
    static Function<void, glmixed::GLuint> DisableVertexAttribArray; ///< Wrapper for glDisableVertexAttribArray
    static Function<void, glmixed::GLuint> DisableVertexAttribArrayARB; ///< Wrapper for glDisableVertexAttribArrayARB
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLenum *> DiscardFramebufferEXT; ///< Wrapper for glDiscardFramebufferEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> DispatchCompute; ///< Wrapper for glDispatchCompute
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> DispatchComputeGroupSizeARB; ///< Wrapper for glDispatchComputeGroupSizeARB
    static Function<void, glmixed::GLintptr> DispatchComputeIndirect; ///< Wrapper for glDispatchComputeIndirect
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLsizei> DrawArrays; ///< Wrapper for glDrawArrays
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLsizei> DrawArraysEXT; ///< Wrapper for glDrawArraysEXT
    static Function<void, glmixed::GLenum, const void *> DrawArraysIndirect; ///< Wrapper for glDrawArraysIndirect
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> DrawArraysInstanced; ///< Wrapper for glDrawArraysInstanced
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> DrawArraysInstancedANGLE; ///< Wrapper for glDrawArraysInstancedANGLE
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> DrawArraysInstancedARB; ///< Wrapper for glDrawArraysInstancedARB
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLuint> DrawArraysInstancedBaseInstance; ///< Wrapper for glDrawArraysInstancedBaseInstance
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLuint> DrawArraysInstancedBaseInstanceEXT; ///< Wrapper for glDrawArraysInstancedBaseInstanceEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> DrawArraysInstancedEXT; ///< Wrapper for glDrawArraysInstancedEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> DrawArraysInstancedNV; ///< Wrapper for glDrawArraysInstancedNV
    static Function<void, glmixed::GLenum> DrawBuffer; ///< Wrapper for glDrawBuffer
    static Function<void, glmixed::GLsizei, const glmixed::GLenum *> DrawBuffers; ///< Wrapper for glDrawBuffers
    static Function<void, glmixed::GLsizei, const glmixed::GLenum *> DrawBuffersARB; ///< Wrapper for glDrawBuffersARB
    static Function<void, glmixed::GLsizei, const glmixed::GLenum *> DrawBuffersATI; ///< Wrapper for glDrawBuffersATI
    static Function<void, glmixed::GLsizei, const glmixed::GLenum *> DrawBuffersEXT; ///< Wrapper for glDrawBuffersEXT
    static Function<void, glmixed::GLint, const glmixed::GLenum *, const glmixed::GLint *> DrawBuffersIndexedEXT; ///< Wrapper for glDrawBuffersIndexedEXT
    static Function<void, glmixed::GLsizei, const glmixed::GLenum *> DrawBuffersNV; ///< Wrapper for glDrawBuffersNV
    static Function<void, glmixed::GLenum, const glmixed::GLuint64 *, const glmixed::GLsizei *, glmixed::GLuint> DrawCommandsAddressNV; ///< Wrapper for glDrawCommandsAddressNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, const glmixed::GLintptr *, const glmixed::GLsizei *, glmixed::GLuint> DrawCommandsNV; ///< Wrapper for glDrawCommandsNV
    static Function<void, const glmixed::GLuint64 *, const glmixed::GLsizei *, const glmixed::GLuint *, const glmixed::GLuint *, glmixed::GLuint> DrawCommandsStatesAddressNV; ///< Wrapper for glDrawCommandsStatesAddressNV
    static Function<void, glmixed::GLuint, const glmixed::GLintptr *, const glmixed::GLsizei *, const glmixed::GLuint *, const glmixed::GLuint *, glmixed::GLuint> DrawCommandsStatesNV; ///< Wrapper for glDrawCommandsStatesNV
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLsizei> DrawElementArrayAPPLE; ///< Wrapper for glDrawElementArrayAPPLE
    static Function<void, glmixed::GLenum, glmixed::GLsizei> DrawElementArrayATI; ///< Wrapper for glDrawElementArrayATI
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *> DrawElements; ///< Wrapper for glDrawElements
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLint> DrawElementsBaseVertex; ///< Wrapper for glDrawElementsBaseVertex
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLint> DrawElementsBaseVertexEXT; ///< Wrapper for glDrawElementsBaseVertexEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLint> DrawElementsBaseVertexOES; ///< Wrapper for glDrawElementsBaseVertexOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, const void *> DrawElementsIndirect; ///< Wrapper for glDrawElementsIndirect
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLsizei> DrawElementsInstanced; ///< Wrapper for glDrawElementsInstanced
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLsizei> DrawElementsInstancedANGLE; ///< Wrapper for glDrawElementsInstancedANGLE
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLsizei> DrawElementsInstancedARB; ///< Wrapper for glDrawElementsInstancedARB
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLuint> DrawElementsInstancedBaseInstance; ///< Wrapper for glDrawElementsInstancedBaseInstance
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLuint> DrawElementsInstancedBaseInstanceEXT; ///< Wrapper for glDrawElementsInstancedBaseInstanceEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLint> DrawElementsInstancedBaseVertex; ///< Wrapper for glDrawElementsInstancedBaseVertex
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLint, glmixed::GLuint> DrawElementsInstancedBaseVertexBaseInstance; ///< Wrapper for glDrawElementsInstancedBaseVertexBaseInstance
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLint, glmixed::GLuint> DrawElementsInstancedBaseVertexBaseInstanceEXT; ///< Wrapper for glDrawElementsInstancedBaseVertexBaseInstanceEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLint> DrawElementsInstancedBaseVertexEXT; ///< Wrapper for glDrawElementsInstancedBaseVertexEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLint> DrawElementsInstancedBaseVertexOES; ///< Wrapper for glDrawElementsInstancedBaseVertexOES
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLsizei> DrawElementsInstancedEXT; ///< Wrapper for glDrawElementsInstancedEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLsizei> DrawElementsInstancedNV; ///< Wrapper for glDrawElementsInstancedNV
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> DrawMeshArraysSUN; ///< Wrapper for glDrawMeshArraysSUN
    static Function<void, glmixed::GLintptr> DrawMeshTasksIndirectNV; ///< Wrapper for glDrawMeshTasksIndirectNV
    static Function<void, glmixed::GLuint, glmixed::GLuint> DrawMeshTasksNV; ///< Wrapper for glDrawMeshTasksNV
    static Function<void, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> DrawPixels; ///< Wrapper for glDrawPixels
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei> DrawRangeElementArrayAPPLE; ///< Wrapper for glDrawRangeElementArrayAPPLE
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei> DrawRangeElementArrayATI; ///< Wrapper for glDrawRangeElementArrayATI
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, const void *> DrawRangeElements; ///< Wrapper for glDrawRangeElements
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLint> DrawRangeElementsBaseVertex; ///< Wrapper for glDrawRangeElementsBaseVertex
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLint> DrawRangeElementsBaseVertexEXT; ///< Wrapper for glDrawRangeElementsBaseVertexEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLint> DrawRangeElementsBaseVertexOES; ///< Wrapper for glDrawRangeElementsBaseVertexOES
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, const void *> DrawRangeElementsEXT; ///< Wrapper for glDrawRangeElementsEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> DrawTextureNV; ///< Wrapper for glDrawTextureNV
    static Function<void, glmixed::GLenum, glmixed::GLuint> DrawTransformFeedback; ///< Wrapper for glDrawTransformFeedback
    static Function<void, glmixed::GLenum, glmixed::GLuint> DrawTransformFeedbackEXT; ///< Wrapper for glDrawTransformFeedbackEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei> DrawTransformFeedbackInstanced; ///< Wrapper for glDrawTransformFeedbackInstanced
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei> DrawTransformFeedbackInstancedEXT; ///< Wrapper for glDrawTransformFeedbackInstancedEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint> DrawTransformFeedbackNV; ///< Wrapper for glDrawTransformFeedbackNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint> DrawTransformFeedbackStream; ///< Wrapper for glDrawTransformFeedbackStream
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei> DrawTransformFeedbackStreamInstanced; ///< Wrapper for glDrawTransformFeedbackStreamInstanced
    static Function<void, glmixed::GLuint64, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> DrawVkImageNV; ///< Wrapper for glDrawVkImageNV
    static Function<void, glmixed::GLboolean> EdgeFlag; ///< Wrapper for glEdgeFlag
    static Function<void, glmixed::GLsizei> EdgeFlagFormatNV; ///< Wrapper for glEdgeFlagFormatNV
    static Function<void, glmixed::GLsizei, const void *> EdgeFlagPointer; ///< Wrapper for glEdgeFlagPointer
    static Function<void, glmixed::GLsizei, glmixed::GLsizei, const glmixed::GLboolean *> EdgeFlagPointerEXT; ///< Wrapper for glEdgeFlagPointerEXT
    static Function<void, glmixed::GLint, const glmixed::GLboolean **, glmixed::GLint> EdgeFlagPointerListIBM; ///< Wrapper for glEdgeFlagPointerListIBM
    static Function<void, const glmixed::GLboolean *> EdgeFlagv; ///< Wrapper for glEdgeFlagv
    static Function<void, glmixed::GLenum, glmixed::GLeglImageOES> EGLImageTargetRenderbufferStorageOES; ///< Wrapper for glEGLImageTargetRenderbufferStorageOES
    static Function<void, glmixed::GLenum, glmixed::GLeglImageOES, const glmixed::GLint*> EGLImageTargetTexStorageEXT; ///< Wrapper for glEGLImageTargetTexStorageEXT
    static Function<void, glmixed::GLenum, glmixed::GLeglImageOES> EGLImageTargetTexture2DOES; ///< Wrapper for glEGLImageTargetTexture2DOES
    static Function<void, glmixed::GLuint, glmixed::GLeglImageOES, const glmixed::GLint*> EGLImageTargetTextureStorageEXT; ///< Wrapper for glEGLImageTargetTextureStorageEXT
    static Function<void, glmixed::GLenum, const void *> ElementPointerAPPLE; ///< Wrapper for glElementPointerAPPLE
    static Function<void, glmixed::GLenum, const void *> ElementPointerATI; ///< Wrapper for glElementPointerATI
    static Function<void, glmixed::GLenum> Enable; ///< Wrapper for glEnable
    static Function<void, glmixed::GLenum> EnableClientState; ///< Wrapper for glEnableClientState
    static Function<void, glmixed::GLenum, glmixed::GLuint> EnableClientStateiEXT; ///< Wrapper for glEnableClientStateiEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint> EnableClientStateIndexedEXT; ///< Wrapper for glEnableClientStateIndexedEXT
    static Function<void, glmixed::GLuint> EnableDriverControlQCOM; ///< Wrapper for glEnableDriverControlQCOM
    static Function<void, glmixed::GLenum, glmixed::GLuint> Enablei; ///< Wrapper for glEnablei
    static Function<void, glmixed::GLenum, glmixed::GLuint> EnableiEXT; ///< Wrapper for glEnableiEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint> EnableIndexedEXT; ///< Wrapper for glEnableIndexedEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint> EnableiNV; ///< Wrapper for glEnableiNV
    static Function<void, glmixed::GLenum, glmixed::GLuint> EnableiOES; ///< Wrapper for glEnableiOES
    static Function<void, glmixed::GLuint> EnableVariantClientStateEXT; ///< Wrapper for glEnableVariantClientStateEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint> EnableVertexArrayAttrib; ///< Wrapper for glEnableVertexArrayAttrib
    static Function<void, glmixed::GLuint, glmixed::GLuint> EnableVertexArrayAttribEXT; ///< Wrapper for glEnableVertexArrayAttribEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum> EnableVertexArrayEXT; ///< Wrapper for glEnableVertexArrayEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum> EnableVertexAttribAPPLE; ///< Wrapper for glEnableVertexAttribAPPLE
    static Function<void, glmixed::GLuint> EnableVertexAttribArray; ///< Wrapper for glEnableVertexAttribArray
    static Function<void, glmixed::GLuint> EnableVertexAttribArrayARB; ///< Wrapper for glEnableVertexAttribArrayARB
    static Function<void> End; ///< Wrapper for glEnd
    static Function<void> EndConditionalRender; ///< Wrapper for glEndConditionalRender
    static Function<void> EndConditionalRenderNV; ///< Wrapper for glEndConditionalRenderNV
    static Function<void> EndConditionalRenderNVX; ///< Wrapper for glEndConditionalRenderNVX
    static Function<void> EndFragmentShaderATI; ///< Wrapper for glEndFragmentShaderATI
    static Function<void> EndList; ///< Wrapper for glEndList
    static Function<void> EndOcclusionQueryNV; ///< Wrapper for glEndOcclusionQueryNV
    static Function<void, glmixed::GLuint> EndPerfMonitorAMD; ///< Wrapper for glEndPerfMonitorAMD
    static Function<void, glmixed::GLuint> EndPerfQueryINTEL; ///< Wrapper for glEndPerfQueryINTEL
    static Function<void, glmixed::GLenum> EndQuery; ///< Wrapper for glEndQuery
    static Function<void, glmixed::GLenum> EndQueryARB; ///< Wrapper for glEndQueryARB
    static Function<void, glmixed::GLenum> EndQueryEXT; ///< Wrapper for glEndQueryEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint> EndQueryIndexed; ///< Wrapper for glEndQueryIndexed
    static Function<void, glmixed::GLbitfield> EndTilingQCOM; ///< Wrapper for glEndTilingQCOM
    static Function<void> EndTransformFeedback; ///< Wrapper for glEndTransformFeedback
    static Function<void> EndTransformFeedbackEXT; ///< Wrapper for glEndTransformFeedbackEXT
    static Function<void> EndTransformFeedbackNV; ///< Wrapper for glEndTransformFeedbackNV
    static Function<void> EndVertexShaderEXT; ///< Wrapper for glEndVertexShaderEXT
    static Function<void, glmixed::GLuint> EndVideoCaptureNV; ///< Wrapper for glEndVideoCaptureNV
    static Function<void, glmixed::GLdouble> EvalCoord1d; ///< Wrapper for glEvalCoord1d
    static Function<void, const glmixed::GLdouble *> EvalCoord1dv; ///< Wrapper for glEvalCoord1dv
    static Function<void, glmixed::GLfloat> EvalCoord1f; ///< Wrapper for glEvalCoord1f
    static Function<void, const glmixed::GLfloat *> EvalCoord1fv; ///< Wrapper for glEvalCoord1fv
    static Function<void, glmixed::GLfixed> EvalCoord1xOES; ///< Wrapper for glEvalCoord1xOES
    static Function<void, const glmixed::GLfixed *> EvalCoord1xvOES; ///< Wrapper for glEvalCoord1xvOES
    static Function<void, glmixed::GLdouble, glmixed::GLdouble> EvalCoord2d; ///< Wrapper for glEvalCoord2d
    static Function<void, const glmixed::GLdouble *> EvalCoord2dv; ///< Wrapper for glEvalCoord2dv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat> EvalCoord2f; ///< Wrapper for glEvalCoord2f
    static Function<void, const glmixed::GLfloat *> EvalCoord2fv; ///< Wrapper for glEvalCoord2fv
    static Function<void, glmixed::GLfixed, glmixed::GLfixed> EvalCoord2xOES; ///< Wrapper for glEvalCoord2xOES
    static Function<void, const glmixed::GLfixed *> EvalCoord2xvOES; ///< Wrapper for glEvalCoord2xvOES
    static Function<void, glmixed::GLenum, glmixed::GLenum> EvalMapsNV; ///< Wrapper for glEvalMapsNV
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint> EvalMesh1; ///< Wrapper for glEvalMesh1
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> EvalMesh2; ///< Wrapper for glEvalMesh2
    static Function<void, glmixed::GLint> EvalPoint1; ///< Wrapper for glEvalPoint1
    static Function<void, glmixed::GLint, glmixed::GLint> EvalPoint2; ///< Wrapper for glEvalPoint2
    static Function<void> EvaluateDepthValuesARB; ///< Wrapper for glEvaluateDepthValuesARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, const glmixed::GLfloat *> ExecuteProgramNV; ///< Wrapper for glExecuteProgramNV
    static Function<void, glmixed::GLenum, void **> ExtGetBufferPointervQCOM; ///< Wrapper for glExtGetBufferPointervQCOM
    static Function<void, glmixed::GLuint *, glmixed::GLint, glmixed::GLint *> ExtGetBuffersQCOM; ///< Wrapper for glExtGetBuffersQCOM
    static Function<void, glmixed::GLuint *, glmixed::GLint, glmixed::GLint *> ExtGetFramebuffersQCOM; ///< Wrapper for glExtGetFramebuffersQCOM
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLchar *, glmixed::GLint *> ExtGetProgramBinarySourceQCOM; ///< Wrapper for glExtGetProgramBinarySourceQCOM
    static Function<void, glmixed::GLuint *, glmixed::GLint, glmixed::GLint *> ExtGetProgramsQCOM; ///< Wrapper for glExtGetProgramsQCOM
    static Function<void, glmixed::GLuint *, glmixed::GLint, glmixed::GLint *> ExtGetRenderbuffersQCOM; ///< Wrapper for glExtGetRenderbuffersQCOM
    static Function<void, glmixed::GLuint *, glmixed::GLint, glmixed::GLint *> ExtGetShadersQCOM; ///< Wrapper for glExtGetShadersQCOM
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLint *> ExtGetTexLevelParameterivQCOM; ///< Wrapper for glExtGetTexLevelParameterivQCOM
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, void *> ExtGetTexSubImageQCOM; ///< Wrapper for glExtGetTexSubImageQCOM
    static Function<void, glmixed::GLuint *, glmixed::GLint, glmixed::GLint *> ExtGetTexturesQCOM; ///< Wrapper for glExtGetTexturesQCOM
    static Function<glmixed::GLboolean, glmixed::GLuint> ExtIsProgramBinaryQCOM; ///< Wrapper for glExtIsProgramBinaryQCOM
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> ExtractComponentEXT; ///< Wrapper for glExtractComponentEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLfloat> ExtrapolateTex2DQCOM; ///< Wrapper for glExtrapolateTex2DQCOM
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> ExtTexObjectStateOverrideiQCOM; ///< Wrapper for glExtTexObjectStateOverrideiQCOM
    static Function<void, glmixed::GLsizei, glmixed::GLenum, glmixed::GLfloat *> FeedbackBuffer; ///< Wrapper for glFeedbackBuffer
    static Function<void, glmixed::GLsizei, glmixed::GLenum, const glmixed::GLfixed *> FeedbackBufferxOES; ///< Wrapper for glFeedbackBufferxOES
    static Function<glmixed::GLsync, glmixed::GLenum, glmixed::GLbitfield> FenceSync; ///< Wrapper for glFenceSync
    static Function<glmixed::GLsync, glmixed::GLenum, glmixed::GLbitfield> FenceSyncAPPLE; ///< Wrapper for glFenceSyncAPPLE
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum> FinalCombinerInputNV; ///< Wrapper for glFinalCombinerInputNV
    static Function<void> Finish; ///< Wrapper for glFinish
    static Function<glmixed::GLint, glmixed::GLuint *> FinishAsyncSGIX; ///< Wrapper for glFinishAsyncSGIX
    static Function<void, glmixed::GLuint> FinishFenceAPPLE; ///< Wrapper for glFinishFenceAPPLE
    static Function<void, glmixed::GLuint> FinishFenceNV; ///< Wrapper for glFinishFenceNV
    static Function<void, glmixed::GLenum, glmixed::GLint> FinishObjectAPPLE; ///< Wrapper for glFinishObjectAPPLE
    static Function<void> FinishTextureSUNX; ///< Wrapper for glFinishTextureSUNX
    static Function<void> Flush; ///< Wrapper for glFlush
    static Function<void, glmixed::GLenum, glmixed::GLintptr, glmixed::GLsizeiptr> FlushMappedBufferRange; ///< Wrapper for glFlushMappedBufferRange
    static Function<void, glmixed::GLenum, glmixed::GLintptr, glmixed::GLsizeiptr> FlushMappedBufferRangeAPPLE; ///< Wrapper for glFlushMappedBufferRangeAPPLE
    static Function<void, glmixed::GLenum, glmixed::GLintptr, glmixed::GLsizeiptr> FlushMappedBufferRangeEXT; ///< Wrapper for glFlushMappedBufferRangeEXT
    static Function<void, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr> FlushMappedNamedBufferRange; ///< Wrapper for glFlushMappedNamedBufferRange
    static Function<void, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr> FlushMappedNamedBufferRangeEXT; ///< Wrapper for glFlushMappedNamedBufferRangeEXT
    static Function<void, glmixed::GLenum> FlushPixelDataRangeNV; ///< Wrapper for glFlushPixelDataRangeNV
    static Function<void> FlushRasterSGIX; ///< Wrapper for glFlushRasterSGIX
    static Function<void, glmixed::GLenum> FlushStaticDataIBM; ///< Wrapper for glFlushStaticDataIBM
    static Function<void, glmixed::GLsizei, void *> FlushVertexArrayRangeAPPLE; ///< Wrapper for glFlushVertexArrayRangeAPPLE
    static Function<void> FlushVertexArrayRangeNV; ///< Wrapper for glFlushVertexArrayRangeNV
    static Function<void, glmixed::GLdouble> FogCoordd; ///< Wrapper for glFogCoordd
    static Function<void, glmixed::GLdouble> FogCoorddEXT; ///< Wrapper for glFogCoorddEXT
    static Function<void, const glmixed::GLdouble *> FogCoorddv; ///< Wrapper for glFogCoorddv
    static Function<void, const glmixed::GLdouble *> FogCoorddvEXT; ///< Wrapper for glFogCoorddvEXT
    static Function<void, glmixed::GLfloat> FogCoordf; ///< Wrapper for glFogCoordf
    static Function<void, glmixed::GLfloat> FogCoordfEXT; ///< Wrapper for glFogCoordfEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei> FogCoordFormatNV; ///< Wrapper for glFogCoordFormatNV
    static Function<void, const glmixed::GLfloat *> FogCoordfv; ///< Wrapper for glFogCoordfv
    static Function<void, const glmixed::GLfloat *> FogCoordfvEXT; ///< Wrapper for glFogCoordfvEXT
    static Function<void, glmixed::GLhalfNV> FogCoordhNV; ///< Wrapper for glFogCoordhNV
    static Function<void, const glmixed::GLhalfNV *> FogCoordhvNV; ///< Wrapper for glFogCoordhvNV
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const void *> FogCoordPointer; ///< Wrapper for glFogCoordPointer
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const void *> FogCoordPointerEXT; ///< Wrapper for glFogCoordPointerEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, const void **, glmixed::GLint> FogCoordPointerListIBM; ///< Wrapper for glFogCoordPointerListIBM
    static Function<void, glmixed::GLenum, glmixed::GLfloat> Fogf; ///< Wrapper for glFogf
    static Function<void, glmixed::GLsizei, const glmixed::GLfloat *> FogFuncSGIS; ///< Wrapper for glFogFuncSGIS
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> Fogfv; ///< Wrapper for glFogfv
    static Function<void, glmixed::GLenum, glmixed::GLint> Fogi; ///< Wrapper for glFogi
    static Function<void, glmixed::GLenum, const glmixed::GLint *> Fogiv; ///< Wrapper for glFogiv
    static Function<void, glmixed::GLenum, glmixed::GLfixed> FogxOES; ///< Wrapper for glFogxOES
    static Function<void, glmixed::GLenum, const glmixed::GLfixed *> FogxvOES; ///< Wrapper for glFogxvOES
    static Function<void, glmixed::GLenum, glmixed::GLenum> FragmentColorMaterialSGIX; ///< Wrapper for glFragmentColorMaterialSGIX
    static Function<void, glmixed::GLuint> FragmentCoverageColorNV; ///< Wrapper for glFragmentCoverageColorNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat> FragmentLightfSGIX; ///< Wrapper for glFragmentLightfSGIX
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> FragmentLightfvSGIX; ///< Wrapper for glFragmentLightfvSGIX
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> FragmentLightiSGIX; ///< Wrapper for glFragmentLightiSGIX
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> FragmentLightivSGIX; ///< Wrapper for glFragmentLightivSGIX
    static Function<void, glmixed::GLenum, glmixed::GLfloat> FragmentLightModelfSGIX; ///< Wrapper for glFragmentLightModelfSGIX
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> FragmentLightModelfvSGIX; ///< Wrapper for glFragmentLightModelfvSGIX
    static Function<void, glmixed::GLenum, glmixed::GLint> FragmentLightModeliSGIX; ///< Wrapper for glFragmentLightModeliSGIX
    static Function<void, glmixed::GLenum, const glmixed::GLint *> FragmentLightModelivSGIX; ///< Wrapper for glFragmentLightModelivSGIX
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat> FragmentMaterialfSGIX; ///< Wrapper for glFragmentMaterialfSGIX
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> FragmentMaterialfvSGIX; ///< Wrapper for glFragmentMaterialfvSGIX
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> FragmentMaterialiSGIX; ///< Wrapper for glFragmentMaterialiSGIX
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> FragmentMaterialivSGIX; ///< Wrapper for glFragmentMaterialivSGIX
    static Function<void, glmixed::GLuint, glmixed::GLenum> FramebufferDrawBufferEXT; ///< Wrapper for glFramebufferDrawBufferEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLenum *> FramebufferDrawBuffersEXT; ///< Wrapper for glFramebufferDrawBuffersEXT
    static Function<void> FramebufferFetchBarrierEXT; ///< Wrapper for glFramebufferFetchBarrierEXT
    static Function<void> FramebufferFetchBarrierQCOM; ///< Wrapper for glFramebufferFetchBarrierQCOM
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint *> FramebufferFoveationConfigQCOM; ///< Wrapper for glFramebufferFoveationConfigQCOM
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> FramebufferFoveationParametersQCOM; ///< Wrapper for glFramebufferFoveationParametersQCOM
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> FramebufferParameteri; ///< Wrapper for glFramebufferParameteri
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> FramebufferParameteriMESA; ///< Wrapper for glFramebufferParameteriMESA
    static Function<void, glmixed::GLuint, glmixed::GLsizei> FramebufferPixelLocalStorageSizeEXT; ///< Wrapper for glFramebufferPixelLocalStorageSizeEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum> FramebufferReadBufferEXT; ///< Wrapper for glFramebufferReadBufferEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> FramebufferRenderbuffer; ///< Wrapper for glFramebufferRenderbuffer
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> FramebufferRenderbufferEXT; ///< Wrapper for glFramebufferRenderbufferEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> FramebufferSampleLocationsfvARB; ///< Wrapper for glFramebufferSampleLocationsfvARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> FramebufferSampleLocationsfvNV; ///< Wrapper for glFramebufferSampleLocationsfvNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, const glmixed::GLfloat *> FramebufferSamplePositionsfvAMD; ///< Wrapper for glFramebufferSamplePositionsfvAMD
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei> FramebufferShadingRateEXT; ///< Wrapper for glFramebufferShadingRateEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint> FramebufferTexture; ///< Wrapper for glFramebufferTexture
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint> FramebufferTexture1D; ///< Wrapper for glFramebufferTexture1D
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint> FramebufferTexture1DEXT; ///< Wrapper for glFramebufferTexture1DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint> FramebufferTexture2D; ///< Wrapper for glFramebufferTexture2D
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint> FramebufferTexture2DDownsampleIMG; ///< Wrapper for glFramebufferTexture2DDownsampleIMG
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint> FramebufferTexture2DEXT; ///< Wrapper for glFramebufferTexture2DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei> FramebufferTexture2DMultisampleEXT; ///< Wrapper for glFramebufferTexture2DMultisampleEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei> FramebufferTexture2DMultisampleIMG; ///< Wrapper for glFramebufferTexture2DMultisampleIMG
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLint> FramebufferTexture3D; ///< Wrapper for glFramebufferTexture3D
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLint> FramebufferTexture3DEXT; ///< Wrapper for glFramebufferTexture3DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLint> FramebufferTexture3DOES; ///< Wrapper for glFramebufferTexture3DOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint> FramebufferTextureARB; ///< Wrapper for glFramebufferTextureARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint> FramebufferTextureEXT; ///< Wrapper for glFramebufferTextureEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLenum> FramebufferTextureFaceARB; ///< Wrapper for glFramebufferTextureFaceARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLenum> FramebufferTextureFaceEXT; ///< Wrapper for glFramebufferTextureFaceEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLint> FramebufferTextureLayer; ///< Wrapper for glFramebufferTextureLayer
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLint> FramebufferTextureLayerARB; ///< Wrapper for glFramebufferTextureLayerARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> FramebufferTextureLayerDownsampleIMG; ///< Wrapper for glFramebufferTextureLayerDownsampleIMG
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLint> FramebufferTextureLayerEXT; ///< Wrapper for glFramebufferTextureLayerEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei> FramebufferTextureMultisampleMultiviewOVR; ///< Wrapper for glFramebufferTextureMultisampleMultiviewOVR
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei> FramebufferTextureMultiviewOVR; ///< Wrapper for glFramebufferTextureMultiviewOVR
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint> FramebufferTextureOES; ///< Wrapper for glFramebufferTextureOES
    static Function<void> FrameTerminatorGREMEDY; ///< Wrapper for glFrameTerminatorGREMEDY
    static Function<void, glmixed::GLint> FrameZoomSGIX; ///< Wrapper for glFrameZoomSGIX
    static Function<void, glmixed::GLuint> FreeObjectBufferATI; ///< Wrapper for glFreeObjectBufferATI
    static Function<void, glmixed::GLenum> FrontFace; ///< Wrapper for glFrontFace
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> Frustum; ///< Wrapper for glFrustum
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> FrustumfOES; ///< Wrapper for glFrustumfOES
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> FrustumxOES; ///< Wrapper for glFrustumxOES
    static Function<glmixed::GLuint, glmixed::GLsizei> GenAsyncMarkersSGIX; ///< Wrapper for glGenAsyncMarkersSGIX
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenBuffers; ///< Wrapper for glGenBuffers
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenBuffersARB; ///< Wrapper for glGenBuffersARB
    static Function<void, glmixed::GLenum> GenerateMipmap; ///< Wrapper for glGenerateMipmap
    static Function<void, glmixed::GLenum> GenerateMipmapEXT; ///< Wrapper for glGenerateMipmapEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum> GenerateMultiTexMipmapEXT; ///< Wrapper for glGenerateMultiTexMipmapEXT
    static Function<void, glmixed::GLuint> GenerateTextureMipmap; ///< Wrapper for glGenerateTextureMipmap
    static Function<void, glmixed::GLuint, glmixed::GLenum> GenerateTextureMipmapEXT; ///< Wrapper for glGenerateTextureMipmapEXT
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenFencesAPPLE; ///< Wrapper for glGenFencesAPPLE
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenFencesNV; ///< Wrapper for glGenFencesNV
    static Function<glmixed::GLuint, glmixed::GLuint> GenFragmentShadersATI; ///< Wrapper for glGenFragmentShadersATI
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenFramebuffers; ///< Wrapper for glGenFramebuffers
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenFramebuffersEXT; ///< Wrapper for glGenFramebuffersEXT
    static Function<glmixed::GLuint, glmixed::GLsizei> GenLists; ///< Wrapper for glGenLists
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint *> GenNamesAMD; ///< Wrapper for glGenNamesAMD
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenOcclusionQueriesNV; ///< Wrapper for glGenOcclusionQueriesNV
    static Function<glmixed::GLuint, glmixed::GLsizei> GenPathsNV; ///< Wrapper for glGenPathsNV
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenPerfMonitorsAMD; ///< Wrapper for glGenPerfMonitorsAMD
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenProgramPipelines; ///< Wrapper for glGenProgramPipelines
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenProgramPipelinesEXT; ///< Wrapper for glGenProgramPipelinesEXT
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenProgramsARB; ///< Wrapper for glGenProgramsARB
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenProgramsNV; ///< Wrapper for glGenProgramsNV
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenQueries; ///< Wrapper for glGenQueries
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenQueriesARB; ///< Wrapper for glGenQueriesARB
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenQueriesEXT; ///< Wrapper for glGenQueriesEXT
    static Function<void, glmixed::GLsizei, glmixed::GLint *> GenQueryResourceTagNV; ///< Wrapper for glGenQueryResourceTagNV
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenRenderbuffers; ///< Wrapper for glGenRenderbuffers
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenRenderbuffersEXT; ///< Wrapper for glGenRenderbuffersEXT
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenSamplers; ///< Wrapper for glGenSamplers
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenSemaphoresEXT; ///< Wrapper for glGenSemaphoresEXT
    static Function<glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> GenSymbolsEXT; ///< Wrapper for glGenSymbolsEXT
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenTextures; ///< Wrapper for glGenTextures
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenTexturesEXT; ///< Wrapper for glGenTexturesEXT
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenTransformFeedbacks; ///< Wrapper for glGenTransformFeedbacks
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenTransformFeedbacksNV; ///< Wrapper for glGenTransformFeedbacksNV
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenVertexArrays; ///< Wrapper for glGenVertexArrays
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenVertexArraysAPPLE; ///< Wrapper for glGenVertexArraysAPPLE
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> GenVertexArraysOES; ///< Wrapper for glGenVertexArraysOES
    static Function<glmixed::GLuint, glmixed::GLuint> GenVertexShadersEXT; ///< Wrapper for glGenVertexShadersEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetActiveAtomicCounterBufferiv; ///< Wrapper for glGetActiveAtomicCounterBufferiv
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLint *, glmixed::GLenum *, glmixed::GLchar *> GetActiveAttrib; ///< Wrapper for glGetActiveAttrib
    static Function<void, glmixed::GLhandleARB, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLint *, glmixed::GLenum *, glmixed::GLcharARB *> GetActiveAttribARB; ///< Wrapper for glGetActiveAttribARB
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetActiveSubroutineName; ///< Wrapper for glGetActiveSubroutineName
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetActiveSubroutineUniformiv; ///< Wrapper for glGetActiveSubroutineUniformiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetActiveSubroutineUniformName; ///< Wrapper for glGetActiveSubroutineUniformName
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLint *, glmixed::GLenum *, glmixed::GLchar *> GetActiveUniform; ///< Wrapper for glGetActiveUniform
    static Function<void, glmixed::GLhandleARB, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLint *, glmixed::GLenum *, glmixed::GLcharARB *> GetActiveUniformARB; ///< Wrapper for glGetActiveUniformARB
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetActiveUniformBlockiv; ///< Wrapper for glGetActiveUniformBlockiv
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetActiveUniformBlockName; ///< Wrapper for glGetActiveUniformBlockName
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetActiveUniformName; ///< Wrapper for glGetActiveUniformName
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *, glmixed::GLenum, glmixed::GLint *> GetActiveUniformsiv; ///< Wrapper for glGetActiveUniformsiv
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLsizei *, glmixed::GLenum *, glmixed::GLchar *> GetActiveVaryingNV; ///< Wrapper for glGetActiveVaryingNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetArrayObjectfvATI; ///< Wrapper for glGetArrayObjectfvATI
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetArrayObjectivATI; ///< Wrapper for glGetArrayObjectivATI
    static Function<void, glmixed::GLhandleARB, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLhandleARB *> GetAttachedObjectsARB; ///< Wrapper for glGetAttachedObjectsARB
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLuint *> GetAttachedShaders; ///< Wrapper for glGetAttachedShaders
    static Function<glmixed::GLint, glmixed::GLuint, const glmixed::GLchar *> GetAttribLocation; ///< Wrapper for glGetAttribLocation
    static Function<glmixed::GLint, glmixed::GLhandleARB, const glmixed::GLcharARB *> GetAttribLocationARB; ///< Wrapper for glGetAttribLocationARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLboolean *> GetBooleani_v; ///< Wrapper for glGetBooleani_v
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLboolean *> GetBooleanIndexedvEXT; ///< Wrapper for glGetBooleanIndexedvEXT
    static Function<void, glmixed::GLenum, glmixed::GLboolean *> GetBooleanv; ///< Wrapper for glGetBooleanv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint64 *> GetBufferParameteri64v; ///< Wrapper for glGetBufferParameteri64v
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetBufferParameteriv; ///< Wrapper for glGetBufferParameteriv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetBufferParameterivARB; ///< Wrapper for glGetBufferParameterivARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint64EXT *> GetBufferParameterui64vNV; ///< Wrapper for glGetBufferParameterui64vNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, void **> GetBufferPointerv; ///< Wrapper for glGetBufferPointerv
    static Function<void, glmixed::GLenum, glmixed::GLenum, void **> GetBufferPointervARB; ///< Wrapper for glGetBufferPointervARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, void **> GetBufferPointervOES; ///< Wrapper for glGetBufferPointervOES
    static Function<void, glmixed::GLenum, glmixed::GLintptr, glmixed::GLsizeiptr, void *> GetBufferSubData; ///< Wrapper for glGetBufferSubData
    static Function<void, glmixed::GLenum, glmixed::GLintptrARB, glmixed::GLsizeiptrARB, void *> GetBufferSubDataARB; ///< Wrapper for glGetBufferSubDataARB
    static Function<void, glmixed::GLenum, glmixed::GLdouble *> GetClipPlane; ///< Wrapper for glGetClipPlane
    static Function<void, glmixed::GLenum, glmixed::GLfloat *> GetClipPlanefOES; ///< Wrapper for glGetClipPlanefOES
    static Function<void, glmixed::GLenum, glmixed::GLfixed *> GetClipPlanexOES; ///< Wrapper for glGetClipPlanexOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, void *> GetColorTable; ///< Wrapper for glGetColorTable
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, void *> GetColorTableEXT; ///< Wrapper for glGetColorTableEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetColorTableParameterfv; ///< Wrapper for glGetColorTableParameterfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetColorTableParameterfvEXT; ///< Wrapper for glGetColorTableParameterfvEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetColorTableParameterfvSGI; ///< Wrapper for glGetColorTableParameterfvSGI
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetColorTableParameteriv; ///< Wrapper for glGetColorTableParameteriv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetColorTableParameterivEXT; ///< Wrapper for glGetColorTableParameterivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetColorTableParameterivSGI; ///< Wrapper for glGetColorTableParameterivSGI
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, void *> GetColorTableSGI; ///< Wrapper for glGetColorTableSGI
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetCombinerInputParameterfvNV; ///< Wrapper for glGetCombinerInputParameterfvNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetCombinerInputParameterivNV; ///< Wrapper for glGetCombinerInputParameterivNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetCombinerOutputParameterfvNV; ///< Wrapper for glGetCombinerOutputParameterfvNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetCombinerOutputParameterivNV; ///< Wrapper for glGetCombinerOutputParameterivNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetCombinerStageParameterfvNV; ///< Wrapper for glGetCombinerStageParameterfvNV
    static Function<glmixed::GLuint, glmixed::GLenum, glmixed::GLuint> GetCommandHeaderNV; ///< Wrapper for glGetCommandHeaderNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, void *> GetCompressedMultiTexImageEXT; ///< Wrapper for glGetCompressedMultiTexImageEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, void *> GetCompressedTexImage; ///< Wrapper for glGetCompressedTexImage
    static Function<void, glmixed::GLenum, glmixed::GLint, void *> GetCompressedTexImageARB; ///< Wrapper for glGetCompressedTexImageARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, void *> GetCompressedTextureImage; ///< Wrapper for glGetCompressedTextureImage
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, void *> GetCompressedTextureImageEXT; ///< Wrapper for glGetCompressedTextureImageEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, void *> GetCompressedTextureSubImage; ///< Wrapper for glGetCompressedTextureSubImage
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, void *> GetConvolutionFilter; ///< Wrapper for glGetConvolutionFilter
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, void *> GetConvolutionFilterEXT; ///< Wrapper for glGetConvolutionFilterEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetConvolutionParameterfv; ///< Wrapper for glGetConvolutionParameterfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetConvolutionParameterfvEXT; ///< Wrapper for glGetConvolutionParameterfvEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetConvolutionParameteriv; ///< Wrapper for glGetConvolutionParameteriv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetConvolutionParameterivEXT; ///< Wrapper for glGetConvolutionParameterivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfixed *> GetConvolutionParameterxvOES; ///< Wrapper for glGetConvolutionParameterxvOES
    static Function<void, glmixed::GLsizei, glmixed::GLfloat *> GetCoverageModulationTableNV; ///< Wrapper for glGetCoverageModulationTableNV
    static Function<glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum *, glmixed::GLenum *, glmixed::GLuint *, glmixed::GLenum *, glmixed::GLsizei *, glmixed::GLchar *> GetDebugMessageLog; ///< Wrapper for glGetDebugMessageLog
    static Function<glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum *, glmixed::GLenum *, glmixed::GLuint *, glmixed::GLsizei *, glmixed::GLchar *> GetDebugMessageLogAMD; ///< Wrapper for glGetDebugMessageLogAMD
    static Function<glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum *, glmixed::GLenum *, glmixed::GLuint *, glmixed::GLenum *, glmixed::GLsizei *, glmixed::GLchar *> GetDebugMessageLogARB; ///< Wrapper for glGetDebugMessageLogARB
    static Function<glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum *, glmixed::GLenum *, glmixed::GLuint *, glmixed::GLenum *, glmixed::GLsizei *, glmixed::GLchar *> GetDebugMessageLogKHR; ///< Wrapper for glGetDebugMessageLogKHR
    static Function<void, glmixed::GLenum, glmixed::GLfloat *> GetDetailTexFuncSGIS; ///< Wrapper for glGetDetailTexFuncSGIS
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLdouble *> GetDoublei_v; ///< Wrapper for glGetDoublei_v
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLdouble *> GetDoublei_vEXT; ///< Wrapper for glGetDoublei_vEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLdouble *> GetDoubleIndexedvEXT; ///< Wrapper for glGetDoubleIndexedvEXT
    static Function<void, glmixed::GLenum, glmixed::GLdouble *> GetDoublev; ///< Wrapper for glGetDoublev
    static Function<void, glmixed::GLint *, glmixed::GLsizei, glmixed::GLuint *> GetDriverControlsQCOM; ///< Wrapper for glGetDriverControlsQCOM
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetDriverControlStringQCOM; ///< Wrapper for glGetDriverControlStringQCOM
    static Function<glmixed::GLenum> GetError; ///< Wrapper for glGetError
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetFenceivNV; ///< Wrapper for glGetFenceivNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetFinalCombinerInputParameterfvNV; ///< Wrapper for glGetFinalCombinerInputParameterfvNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetFinalCombinerInputParameterivNV; ///< Wrapper for glGetFinalCombinerInputParameterivNV
    static Function<void, glmixed::GLuint *> GetFirstPerfQueryIdINTEL; ///< Wrapper for glGetFirstPerfQueryIdINTEL
    static Function<void, glmixed::GLenum, glmixed::GLfixed *> GetFixedvOES; ///< Wrapper for glGetFixedvOES
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLfloat *> GetFloati_v; ///< Wrapper for glGetFloati_v
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLfloat *> GetFloati_vEXT; ///< Wrapper for glGetFloati_vEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLfloat *> GetFloati_vNV; ///< Wrapper for glGetFloati_vNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLfloat *> GetFloati_vOES; ///< Wrapper for glGetFloati_vOES
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLfloat *> GetFloatIndexedvEXT; ///< Wrapper for glGetFloatIndexedvEXT
    static Function<void, glmixed::GLenum, glmixed::GLfloat *> GetFloatv; ///< Wrapper for glGetFloatv
    static Function<void, glmixed::GLfloat *> GetFogFuncSGIS; ///< Wrapper for glGetFogFuncSGIS
    static Function<glmixed::GLint, glmixed::GLuint, const glmixed::GLchar *> GetFragDataIndex; ///< Wrapper for glGetFragDataIndex
    static Function<glmixed::GLint, glmixed::GLuint, const glmixed::GLchar *> GetFragDataIndexEXT; ///< Wrapper for glGetFragDataIndexEXT
    static Function<glmixed::GLint, glmixed::GLuint, const glmixed::GLchar *> GetFragDataLocation; ///< Wrapper for glGetFragDataLocation
    static Function<glmixed::GLint, glmixed::GLuint, const glmixed::GLchar *> GetFragDataLocationEXT; ///< Wrapper for glGetFragDataLocationEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetFragmentLightfvSGIX; ///< Wrapper for glGetFragmentLightfvSGIX
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetFragmentLightivSGIX; ///< Wrapper for glGetFragmentLightivSGIX
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetFragmentMaterialfvSGIX; ///< Wrapper for glGetFragmentMaterialfvSGIX
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetFragmentMaterialivSGIX; ///< Wrapper for glGetFragmentMaterialivSGIX
    static Function<void, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLenum *> GetFragmentShadingRatesEXT; ///< Wrapper for glGetFragmentShadingRatesEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetFramebufferAttachmentParameteriv; ///< Wrapper for glGetFramebufferAttachmentParameteriv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetFramebufferAttachmentParameterivEXT; ///< Wrapper for glGetFramebufferAttachmentParameterivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLfloat *> GetFramebufferParameterfvAMD; ///< Wrapper for glGetFramebufferParameterfvAMD
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetFramebufferParameteriv; ///< Wrapper for glGetFramebufferParameteriv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetFramebufferParameterivEXT; ///< Wrapper for glGetFramebufferParameterivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetFramebufferParameterivMESA; ///< Wrapper for glGetFramebufferParameterivMESA
    static Function<glmixed::GLsizei, glmixed::GLuint> GetFramebufferPixelLocalStorageSizeEXT; ///< Wrapper for glGetFramebufferPixelLocalStorageSizeEXT
    static Function<glmixed::GLenum> GetGraphicsResetStatus; ///< Wrapper for glGetGraphicsResetStatus
    static Function<glmixed::GLenum> GetGraphicsResetStatusARB; ///< Wrapper for glGetGraphicsResetStatusARB
    static Function<glmixed::GLenum> GetGraphicsResetStatusEXT; ///< Wrapper for glGetGraphicsResetStatusEXT
    static Function<glmixed::GLenum> GetGraphicsResetStatusKHR; ///< Wrapper for glGetGraphicsResetStatusKHR
    static Function<glmixed::GLhandleARB, glmixed::GLenum> GetHandleARB; ///< Wrapper for glGetHandleARB
    static Function<void, glmixed::GLenum, glmixed::GLboolean, glmixed::GLenum, glmixed::GLenum, void *> GetHistogram; ///< Wrapper for glGetHistogram
    static Function<void, glmixed::GLenum, glmixed::GLboolean, glmixed::GLenum, glmixed::GLenum, void *> GetHistogramEXT; ///< Wrapper for glGetHistogramEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetHistogramParameterfv; ///< Wrapper for glGetHistogramParameterfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetHistogramParameterfvEXT; ///< Wrapper for glGetHistogramParameterfvEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetHistogramParameteriv; ///< Wrapper for glGetHistogramParameteriv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetHistogramParameterivEXT; ///< Wrapper for glGetHistogramParameterivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfixed *> GetHistogramParameterxvOES; ///< Wrapper for glGetHistogramParameterxvOES
    static Function<glmixed::GLuint64, glmixed::GLuint, glmixed::GLint, glmixed::GLboolean, glmixed::GLint, glmixed::GLenum> GetImageHandleARB; ///< Wrapper for glGetImageHandleARB
    static Function<glmixed::GLuint64, glmixed::GLuint, glmixed::GLint, glmixed::GLboolean, glmixed::GLint, glmixed::GLenum> GetImageHandleNV; ///< Wrapper for glGetImageHandleNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetImageTransformParameterfvHP; ///< Wrapper for glGetImageTransformParameterfvHP
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetImageTransformParameterivHP; ///< Wrapper for glGetImageTransformParameterivHP
    static Function<void, glmixed::GLhandleARB, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLcharARB *> GetInfoLogARB; ///< Wrapper for glGetInfoLogARB
    static Function<glmixed::GLint> GetInstrumentsSGIX; ///< Wrapper for glGetInstrumentsSGIX
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLint64 *> GetInteger64i_v; ///< Wrapper for glGetInteger64i_v
    static Function<void, glmixed::GLenum, glmixed::GLint64 *> GetInteger64v; ///< Wrapper for glGetInteger64v
    static Function<void, glmixed::GLenum, glmixed::GLint64 *> GetInteger64vAPPLE; ///< Wrapper for glGetInteger64vAPPLE
    static Function<void, glmixed::GLenum, glmixed::GLint64 *> GetInteger64vEXT; ///< Wrapper for glGetInteger64vEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLint *> GetIntegeri_v; ///< Wrapper for glGetIntegeri_v
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLint *> GetIntegeri_vEXT; ///< Wrapper for glGetIntegeri_vEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLint *> GetIntegerIndexedvEXT; ///< Wrapper for glGetIntegerIndexedvEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint64EXT *> GetIntegerui64i_vNV; ///< Wrapper for glGetIntegerui64i_vNV
    static Function<void, glmixed::GLenum, glmixed::GLuint64EXT *> GetIntegerui64vNV; ///< Wrapper for glGetIntegerui64vNV
    static Function<void, glmixed::GLenum, glmixed::GLint *> GetIntegerv; ///< Wrapper for glGetIntegerv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLint64 *> GetInternalformati64v; ///< Wrapper for glGetInternalformati64v
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLint *> GetInternalformativ; ///< Wrapper for glGetInternalformativ
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLint *> GetInternalformatSampleivNV; ///< Wrapper for glGetInternalformatSampleivNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLboolean *> GetInvariantBooleanvEXT; ///< Wrapper for glGetInvariantBooleanvEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat *> GetInvariantFloatvEXT; ///< Wrapper for glGetInvariantFloatvEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetInvariantIntegervEXT; ///< Wrapper for glGetInvariantIntegervEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetLightfv; ///< Wrapper for glGetLightfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetLightiv; ///< Wrapper for glGetLightiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfixed *> GetLightxOES; ///< Wrapper for glGetLightxOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfixed *> GetLightxvOES; ///< Wrapper for glGetLightxvOES
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat *> GetListParameterfvSGIX; ///< Wrapper for glGetListParameterfvSGIX
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetListParameterivSGIX; ///< Wrapper for glGetListParameterivSGIX
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLboolean *> GetLocalConstantBooleanvEXT; ///< Wrapper for glGetLocalConstantBooleanvEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat *> GetLocalConstantFloatvEXT; ///< Wrapper for glGetLocalConstantFloatvEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetLocalConstantIntegervEXT; ///< Wrapper for glGetLocalConstantIntegervEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat *> GetMapAttribParameterfvNV; ///< Wrapper for glGetMapAttribParameterfvNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetMapAttribParameterivNV; ///< Wrapper for glGetMapAttribParameterivNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean, void *> GetMapControlPointsNV; ///< Wrapper for glGetMapControlPointsNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLdouble *> GetMapdv; ///< Wrapper for glGetMapdv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetMapfv; ///< Wrapper for glGetMapfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetMapiv; ///< Wrapper for glGetMapiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetMapParameterfvNV; ///< Wrapper for glGetMapParameterfvNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetMapParameterivNV; ///< Wrapper for glGetMapParameterivNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfixed *> GetMapxvOES; ///< Wrapper for glGetMapxvOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetMaterialfv; ///< Wrapper for glGetMaterialfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetMaterialiv; ///< Wrapper for glGetMaterialiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfixed> GetMaterialxOES; ///< Wrapper for glGetMaterialxOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfixed *> GetMaterialxvOES; ///< Wrapper for glGetMaterialxvOES
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLsizei, glmixed::GLuint *> GetMemoryObjectDetachedResourcesuivNV; ///< Wrapper for glGetMemoryObjectDetachedResourcesuivNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetMemoryObjectParameterivEXT; ///< Wrapper for glGetMemoryObjectParameterivEXT
    static Function<void, glmixed::GLenum, glmixed::GLboolean, glmixed::GLenum, glmixed::GLenum, void *> GetMinmax; ///< Wrapper for glGetMinmax
    static Function<void, glmixed::GLenum, glmixed::GLboolean, glmixed::GLenum, glmixed::GLenum, void *> GetMinmaxEXT; ///< Wrapper for glGetMinmaxEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetMinmaxParameterfv; ///< Wrapper for glGetMinmaxParameterfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetMinmaxParameterfvEXT; ///< Wrapper for glGetMinmaxParameterfvEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetMinmaxParameteriv; ///< Wrapper for glGetMinmaxParameteriv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetMinmaxParameterivEXT; ///< Wrapper for glGetMinmaxParameterivEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLfloat *> GetMultisamplefv; ///< Wrapper for glGetMultisamplefv
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLfloat *> GetMultisamplefvNV; ///< Wrapper for glGetMultisamplefvNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetMultiTexEnvfvEXT; ///< Wrapper for glGetMultiTexEnvfvEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetMultiTexEnvivEXT; ///< Wrapper for glGetMultiTexEnvivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLdouble *> GetMultiTexGendvEXT; ///< Wrapper for glGetMultiTexGendvEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetMultiTexGenfvEXT; ///< Wrapper for glGetMultiTexGenfvEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetMultiTexGenivEXT; ///< Wrapper for glGetMultiTexGenivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, void *> GetMultiTexImageEXT; ///< Wrapper for glGetMultiTexImageEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLfloat *> GetMultiTexLevelParameterfvEXT; ///< Wrapper for glGetMultiTexLevelParameterfvEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLint *> GetMultiTexLevelParameterivEXT; ///< Wrapper for glGetMultiTexLevelParameterivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetMultiTexParameterfvEXT; ///< Wrapper for glGetMultiTexParameterfvEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetMultiTexParameterIivEXT; ///< Wrapper for glGetMultiTexParameterIivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint *> GetMultiTexParameterIuivEXT; ///< Wrapper for glGetMultiTexParameterIuivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetMultiTexParameterivEXT; ///< Wrapper for glGetMultiTexParameterivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint64 *> GetNamedBufferParameteri64v; ///< Wrapper for glGetNamedBufferParameteri64v
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetNamedBufferParameteriv; ///< Wrapper for glGetNamedBufferParameteriv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetNamedBufferParameterivEXT; ///< Wrapper for glGetNamedBufferParameterivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint64EXT *> GetNamedBufferParameterui64vNV; ///< Wrapper for glGetNamedBufferParameterui64vNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, void **> GetNamedBufferPointerv; ///< Wrapper for glGetNamedBufferPointerv
    static Function<void, glmixed::GLuint, glmixed::GLenum, void **> GetNamedBufferPointervEXT; ///< Wrapper for glGetNamedBufferPointervEXT
    static Function<void, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr, void *> GetNamedBufferSubData; ///< Wrapper for glGetNamedBufferSubData
    static Function<void, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr, void *> GetNamedBufferSubDataEXT; ///< Wrapper for glGetNamedBufferSubDataEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetNamedFramebufferAttachmentParameteriv; ///< Wrapper for glGetNamedFramebufferAttachmentParameteriv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetNamedFramebufferAttachmentParameterivEXT; ///< Wrapper for glGetNamedFramebufferAttachmentParameterivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLfloat *> GetNamedFramebufferParameterfvAMD; ///< Wrapper for glGetNamedFramebufferParameterfvAMD
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetNamedFramebufferParameteriv; ///< Wrapper for glGetNamedFramebufferParameteriv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetNamedFramebufferParameterivEXT; ///< Wrapper for glGetNamedFramebufferParameterivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetNamedProgramivEXT; ///< Wrapper for glGetNamedProgramivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLdouble *> GetNamedProgramLocalParameterdvEXT; ///< Wrapper for glGetNamedProgramLocalParameterdvEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLfloat *> GetNamedProgramLocalParameterfvEXT; ///< Wrapper for glGetNamedProgramLocalParameterfvEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLint *> GetNamedProgramLocalParameterIivEXT; ///< Wrapper for glGetNamedProgramLocalParameterIivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint *> GetNamedProgramLocalParameterIuivEXT; ///< Wrapper for glGetNamedProgramLocalParameterIuivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, void *> GetNamedProgramStringEXT; ///< Wrapper for glGetNamedProgramStringEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetNamedRenderbufferParameteriv; ///< Wrapper for glGetNamedRenderbufferParameteriv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetNamedRenderbufferParameterivEXT; ///< Wrapper for glGetNamedRenderbufferParameterivEXT
    static Function<void, glmixed::GLint, const glmixed::GLchar *, glmixed::GLsizei, glmixed::GLint *, glmixed::GLchar *> GetNamedStringARB; ///< Wrapper for glGetNamedStringARB
    static Function<void, glmixed::GLint, const glmixed::GLchar *, glmixed::GLenum, glmixed::GLint *> GetNamedStringivARB; ///< Wrapper for glGetNamedStringivARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *> GetnColorTable; ///< Wrapper for glGetnColorTable
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *> GetnColorTableARB; ///< Wrapper for glGetnColorTableARB
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLsizei, void *> GetnCompressedTexImage; ///< Wrapper for glGetnCompressedTexImage
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLsizei, void *> GetnCompressedTexImageARB; ///< Wrapper for glGetnCompressedTexImageARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *> GetnConvolutionFilter; ///< Wrapper for glGetnConvolutionFilter
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *> GetnConvolutionFilterARB; ///< Wrapper for glGetnConvolutionFilterARB
    static Function<void, glmixed::GLuint, glmixed::GLuint *> GetNextPerfQueryIdINTEL; ///< Wrapper for glGetNextPerfQueryIdINTEL
    static Function<void, glmixed::GLenum, glmixed::GLboolean, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *> GetnHistogram; ///< Wrapper for glGetnHistogram
    static Function<void, glmixed::GLenum, glmixed::GLboolean, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *> GetnHistogramARB; ///< Wrapper for glGetnHistogramARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLdouble *> GetnMapdv; ///< Wrapper for glGetnMapdv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLdouble *> GetnMapdvARB; ///< Wrapper for glGetnMapdvARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLfloat *> GetnMapfv; ///< Wrapper for glGetnMapfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLfloat *> GetnMapfvARB; ///< Wrapper for glGetnMapfvARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLint *> GetnMapiv; ///< Wrapper for glGetnMapiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLint *> GetnMapivARB; ///< Wrapper for glGetnMapivARB
    static Function<void, glmixed::GLenum, glmixed::GLboolean, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *> GetnMinmax; ///< Wrapper for glGetnMinmax
    static Function<void, glmixed::GLenum, glmixed::GLboolean, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *> GetnMinmaxARB; ///< Wrapper for glGetnMinmaxARB
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLfloat *> GetnPixelMapfv; ///< Wrapper for glGetnPixelMapfv
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLfloat *> GetnPixelMapfvARB; ///< Wrapper for glGetnPixelMapfvARB
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLuint *> GetnPixelMapuiv; ///< Wrapper for glGetnPixelMapuiv
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLuint *> GetnPixelMapuivARB; ///< Wrapper for glGetnPixelMapuivARB
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLushort *> GetnPixelMapusv; ///< Wrapper for glGetnPixelMapusv
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLushort *> GetnPixelMapusvARB; ///< Wrapper for glGetnPixelMapusvARB
    static Function<void, glmixed::GLsizei, glmixed::GLubyte *> GetnPolygonStipple; ///< Wrapper for glGetnPolygonStipple
    static Function<void, glmixed::GLsizei, glmixed::GLubyte *> GetnPolygonStippleARB; ///< Wrapper for glGetnPolygonStippleARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *, glmixed::GLsizei, void *, void *> GetnSeparableFilter; ///< Wrapper for glGetnSeparableFilter
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *, glmixed::GLsizei, void *, void *> GetnSeparableFilterARB; ///< Wrapper for glGetnSeparableFilterARB
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *> GetnTexImage; ///< Wrapper for glGetnTexImage
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *> GetnTexImageARB; ///< Wrapper for glGetnTexImageARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLdouble *> GetnUniformdv; ///< Wrapper for glGetnUniformdv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLdouble *> GetnUniformdvARB; ///< Wrapper for glGetnUniformdvARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLfloat *> GetnUniformfv; ///< Wrapper for glGetnUniformfv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLfloat *> GetnUniformfvARB; ///< Wrapper for glGetnUniformfvARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLfloat *> GetnUniformfvEXT; ///< Wrapper for glGetnUniformfvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLfloat *> GetnUniformfvKHR; ///< Wrapper for glGetnUniformfvKHR
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLint64 *> GetnUniformi64vARB; ///< Wrapper for glGetnUniformi64vARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLint *> GetnUniformiv; ///< Wrapper for glGetnUniformiv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLint *> GetnUniformivARB; ///< Wrapper for glGetnUniformivARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLint *> GetnUniformivEXT; ///< Wrapper for glGetnUniformivEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLint *> GetnUniformivKHR; ///< Wrapper for glGetnUniformivKHR
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLuint64 *> GetnUniformui64vARB; ///< Wrapper for glGetnUniformui64vARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLuint *> GetnUniformuiv; ///< Wrapper for glGetnUniformuiv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLuint *> GetnUniformuivARB; ///< Wrapper for glGetnUniformuivARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLuint *> GetnUniformuivKHR; ///< Wrapper for glGetnUniformuivKHR
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat *> GetObjectBufferfvATI; ///< Wrapper for glGetObjectBufferfvATI
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetObjectBufferivATI; ///< Wrapper for glGetObjectBufferivATI
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetObjectLabel; ///< Wrapper for glGetObjectLabel
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetObjectLabelEXT; ///< Wrapper for glGetObjectLabelEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetObjectLabelKHR; ///< Wrapper for glGetObjectLabelKHR
    static Function<void, glmixed::GLhandleARB, glmixed::GLenum, glmixed::GLfloat *> GetObjectParameterfvARB; ///< Wrapper for glGetObjectParameterfvARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetObjectParameterivAPPLE; ///< Wrapper for glGetObjectParameterivAPPLE
    static Function<void, glmixed::GLhandleARB, glmixed::GLenum, glmixed::GLint *> GetObjectParameterivARB; ///< Wrapper for glGetObjectParameterivARB
    static Function<void, const void *, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetObjectPtrLabel; ///< Wrapper for glGetObjectPtrLabel
    static Function<void, const void *, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetObjectPtrLabelKHR; ///< Wrapper for glGetObjectPtrLabelKHR
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetOcclusionQueryivNV; ///< Wrapper for glGetOcclusionQueryivNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint *> GetOcclusionQueryuivNV; ///< Wrapper for glGetOcclusionQueryuivNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetPathColorGenfvNV; ///< Wrapper for glGetPathColorGenfvNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetPathColorGenivNV; ///< Wrapper for glGetPathColorGenivNV
    static Function<void, glmixed::GLuint, glmixed::GLubyte *> GetPathCommandsNV; ///< Wrapper for glGetPathCommandsNV
    static Function<void, glmixed::GLuint, glmixed::GLfloat *> GetPathCoordsNV; ///< Wrapper for glGetPathCoordsNV
    static Function<void, glmixed::GLuint, glmixed::GLfloat *> GetPathDashArrayNV; ///< Wrapper for glGetPathDashArrayNV
    static Function<glmixed::GLfloat, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei> GetPathLengthNV; ///< Wrapper for glGetPathLengthNV
    static Function<void, glmixed::PathMetricMask, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLfloat *> GetPathMetricRangeNV; ///< Wrapper for glGetPathMetricRangeNV
    static Function<void, glmixed::PathMetricMask, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLuint, glmixed::GLsizei, glmixed::GLfloat *> GetPathMetricsNV; ///< Wrapper for glGetPathMetricsNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat *> GetPathParameterfvNV; ///< Wrapper for glGetPathParameterfvNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetPathParameterivNV; ///< Wrapper for glGetPathParameterivNV
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLenum, glmixed::GLfloat *> GetPathSpacingNV; ///< Wrapper for glGetPathSpacingNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetPathTexGenfvNV; ///< Wrapper for glGetPathTexGenfvNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetPathTexGenivNV; ///< Wrapper for glGetPathTexGenivNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLchar *, glmixed::GLuint, glmixed::GLchar *, glmixed::GLuint *, glmixed::GLuint *, glmixed::GLuint *, glmixed::GLuint *, glmixed::GLuint64 *> GetPerfCounterInfoINTEL; ///< Wrapper for glGetPerfCounterInfoINTEL
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLuint *, glmixed::GLint *> GetPerfMonitorCounterDataAMD; ///< Wrapper for glGetPerfMonitorCounterDataAMD
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, void *> GetPerfMonitorCounterInfoAMD; ///< Wrapper for glGetPerfMonitorCounterInfoAMD
    static Function<void, glmixed::GLuint, glmixed::GLint *, glmixed::GLint *, glmixed::GLsizei, glmixed::GLuint *> GetPerfMonitorCountersAMD; ///< Wrapper for glGetPerfMonitorCountersAMD
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetPerfMonitorCounterStringAMD; ///< Wrapper for glGetPerfMonitorCounterStringAMD
    static Function<void, glmixed::GLint *, glmixed::GLsizei, glmixed::GLuint *> GetPerfMonitorGroupsAMD; ///< Wrapper for glGetPerfMonitorGroupsAMD
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetPerfMonitorGroupStringAMD; ///< Wrapper for glGetPerfMonitorGroupStringAMD
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, void *, glmixed::GLuint *> GetPerfQueryDataINTEL; ///< Wrapper for glGetPerfQueryDataINTEL
    static Function<void, glmixed::GLchar *, glmixed::GLuint *> GetPerfQueryIdByNameINTEL; ///< Wrapper for glGetPerfQueryIdByNameINTEL
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLchar *, glmixed::GLuint *, glmixed::GLuint *, glmixed::GLuint *, glmixed::PerformanceQueryCapsMaskINTEL> GetPerfQueryInfoINTEL; ///< Wrapper for glGetPerfQueryInfoINTEL
    static Function<void, glmixed::GLenum, glmixed::GLfloat *> GetPixelMapfv; ///< Wrapper for glGetPixelMapfv
    static Function<void, glmixed::GLenum, glmixed::GLuint *> GetPixelMapuiv; ///< Wrapper for glGetPixelMapuiv
    static Function<void, glmixed::GLenum, glmixed::GLushort *> GetPixelMapusv; ///< Wrapper for glGetPixelMapusv
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLfixed *> GetPixelMapxv; ///< Wrapper for glGetPixelMapxv
    static Function<void, glmixed::GLenum, glmixed::GLfloat *> GetPixelTexGenParameterfvSGIS; ///< Wrapper for glGetPixelTexGenParameterfvSGIS
    static Function<void, glmixed::GLenum, glmixed::GLint *> GetPixelTexGenParameterivSGIS; ///< Wrapper for glGetPixelTexGenParameterivSGIS
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetPixelTransformParameterfvEXT; ///< Wrapper for glGetPixelTransformParameterfvEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetPixelTransformParameterivEXT; ///< Wrapper for glGetPixelTransformParameterivEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, void **> GetPointeri_vEXT; ///< Wrapper for glGetPointeri_vEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, void **> GetPointerIndexedvEXT; ///< Wrapper for glGetPointerIndexedvEXT
    static Function<void, glmixed::GLenum, void **> GetPointerv; ///< Wrapper for glGetPointerv
    static Function<void, glmixed::GLenum, void **> GetPointervEXT; ///< Wrapper for glGetPointervEXT
    static Function<void, glmixed::GLenum, void **> GetPointervKHR; ///< Wrapper for glGetPointervKHR
    static Function<void, glmixed::GLubyte *> GetPolygonStipple; ///< Wrapper for glGetPolygonStipple
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLenum *, void *> GetProgramBinary; ///< Wrapper for glGetProgramBinary
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLenum *, void *> GetProgramBinaryOES; ///< Wrapper for glGetProgramBinaryOES
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLdouble *> GetProgramEnvParameterdvARB; ///< Wrapper for glGetProgramEnvParameterdvARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLfloat *> GetProgramEnvParameterfvARB; ///< Wrapper for glGetProgramEnvParameterfvARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLint *> GetProgramEnvParameterIivNV; ///< Wrapper for glGetProgramEnvParameterIivNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint *> GetProgramEnvParameterIuivNV; ///< Wrapper for glGetProgramEnvParameterIuivNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetProgramInfoLog; ///< Wrapper for glGetProgramInfoLog
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetProgramInterfaceiv; ///< Wrapper for glGetProgramInterfaceiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetProgramiv; ///< Wrapper for glGetProgramiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetProgramivARB; ///< Wrapper for glGetProgramivARB
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetProgramivNV; ///< Wrapper for glGetProgramivNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLdouble *> GetProgramLocalParameterdvARB; ///< Wrapper for glGetProgramLocalParameterdvARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLfloat *> GetProgramLocalParameterfvARB; ///< Wrapper for glGetProgramLocalParameterfvARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLint *> GetProgramLocalParameterIivNV; ///< Wrapper for glGetProgramLocalParameterIivNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint *> GetProgramLocalParameterIuivNV; ///< Wrapper for glGetProgramLocalParameterIuivNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLubyte *, glmixed::GLdouble *> GetProgramNamedParameterdvNV; ///< Wrapper for glGetProgramNamedParameterdvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLubyte *, glmixed::GLfloat *> GetProgramNamedParameterfvNV; ///< Wrapper for glGetProgramNamedParameterfvNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLdouble *> GetProgramParameterdvNV; ///< Wrapper for glGetProgramParameterdvNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat *> GetProgramParameterfvNV; ///< Wrapper for glGetProgramParameterfvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetProgramPipelineInfoLog; ///< Wrapper for glGetProgramPipelineInfoLog
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetProgramPipelineInfoLogEXT; ///< Wrapper for glGetProgramPipelineInfoLogEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetProgramPipelineiv; ///< Wrapper for glGetProgramPipelineiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetProgramPipelineivEXT; ///< Wrapper for glGetProgramPipelineivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLenum *, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLfloat *> GetProgramResourcefvNV; ///< Wrapper for glGetProgramResourcefvNV
    static Function<glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, const glmixed::GLchar *> GetProgramResourceIndex; ///< Wrapper for glGetProgramResourceIndex
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLenum *, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLint *> GetProgramResourceiv; ///< Wrapper for glGetProgramResourceiv
    static Function<glmixed::GLint, glmixed::GLuint, glmixed::GLenum, const glmixed::GLchar *> GetProgramResourceLocation; ///< Wrapper for glGetProgramResourceLocation
    static Function<glmixed::GLint, glmixed::GLuint, glmixed::GLenum, const glmixed::GLchar *> GetProgramResourceLocationIndex; ///< Wrapper for glGetProgramResourceLocationIndex
    static Function<glmixed::GLint, glmixed::GLuint, glmixed::GLenum, const glmixed::GLchar *> GetProgramResourceLocationIndexEXT; ///< Wrapper for glGetProgramResourceLocationIndexEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetProgramResourceName; ///< Wrapper for glGetProgramResourceName
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetProgramStageiv; ///< Wrapper for glGetProgramStageiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, void *> GetProgramStringARB; ///< Wrapper for glGetProgramStringARB
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLubyte *> GetProgramStringNV; ///< Wrapper for glGetProgramStringNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint *> GetProgramSubroutineParameteruivNV; ///< Wrapper for glGetProgramSubroutineParameteruivNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLintptr> GetQueryBufferObjecti64v; ///< Wrapper for glGetQueryBufferObjecti64v
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLintptr> GetQueryBufferObjectiv; ///< Wrapper for glGetQueryBufferObjectiv
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLintptr> GetQueryBufferObjectui64v; ///< Wrapper for glGetQueryBufferObjectui64v
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLintptr> GetQueryBufferObjectuiv; ///< Wrapper for glGetQueryBufferObjectuiv
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetQueryIndexediv; ///< Wrapper for glGetQueryIndexediv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetQueryiv; ///< Wrapper for glGetQueryiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetQueryivARB; ///< Wrapper for glGetQueryivARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetQueryivEXT; ///< Wrapper for glGetQueryivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint64 *> GetQueryObjecti64v; ///< Wrapper for glGetQueryObjecti64v
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint64 *> GetQueryObjecti64vEXT; ///< Wrapper for glGetQueryObjecti64vEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetQueryObjectiv; ///< Wrapper for glGetQueryObjectiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetQueryObjectivARB; ///< Wrapper for glGetQueryObjectivARB
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetQueryObjectivEXT; ///< Wrapper for glGetQueryObjectivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint64 *> GetQueryObjectui64v; ///< Wrapper for glGetQueryObjectui64v
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint64 *> GetQueryObjectui64vEXT; ///< Wrapper for glGetQueryObjectui64vEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint *> GetQueryObjectuiv; ///< Wrapper for glGetQueryObjectuiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint *> GetQueryObjectuivARB; ///< Wrapper for glGetQueryObjectuivARB
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint *> GetQueryObjectuivEXT; ///< Wrapper for glGetQueryObjectuivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetRenderbufferParameteriv; ///< Wrapper for glGetRenderbufferParameteriv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetRenderbufferParameterivEXT; ///< Wrapper for glGetRenderbufferParameterivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat *> GetSamplerParameterfv; ///< Wrapper for glGetSamplerParameterfv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetSamplerParameterIiv; ///< Wrapper for glGetSamplerParameterIiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetSamplerParameterIivEXT; ///< Wrapper for glGetSamplerParameterIivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetSamplerParameterIivOES; ///< Wrapper for glGetSamplerParameterIivOES
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint *> GetSamplerParameterIuiv; ///< Wrapper for glGetSamplerParameterIuiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint *> GetSamplerParameterIuivEXT; ///< Wrapper for glGetSamplerParameterIuivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint *> GetSamplerParameterIuivOES; ///< Wrapper for glGetSamplerParameterIuivOES
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetSamplerParameteriv; ///< Wrapper for glGetSamplerParameteriv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetSemaphoreParameterivNV; ///< Wrapper for glGetSemaphoreParameterivNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint64 *> GetSemaphoreParameterui64vEXT; ///< Wrapper for glGetSemaphoreParameterui64vEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, void *, void *, void *> GetSeparableFilter; ///< Wrapper for glGetSeparableFilter
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, void *, void *, void *> GetSeparableFilterEXT; ///< Wrapper for glGetSeparableFilterEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetShaderInfoLog; ///< Wrapper for glGetShaderInfoLog
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetShaderiv; ///< Wrapper for glGetShaderiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *, glmixed::GLint *> GetShaderPrecisionFormat; ///< Wrapper for glGetShaderPrecisionFormat
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetShaderSource; ///< Wrapper for glGetShaderSource
    static Function<void, glmixed::GLhandleARB, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLcharARB *> GetShaderSourceARB; ///< Wrapper for glGetShaderSourceARB
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum *> GetShadingRateImagePaletteNV; ///< Wrapper for glGetShadingRateImagePaletteNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLint *> GetShadingRateSampleLocationivNV; ///< Wrapper for glGetShadingRateSampleLocationivNV
    static Function<void, glmixed::GLenum, glmixed::GLfloat *> GetSharpenTexFuncSGIS; ///< Wrapper for glGetSharpenTexFuncSGIS
    static Function<glmixed::GLushort, glmixed::GLenum> GetStageIndexNV; ///< Wrapper for glGetStageIndexNV
    static Function<const glmixed::GLubyte *, glmixed::GLenum> GetString; ///< Wrapper for glGetString
    static Function<const glmixed::GLubyte *, glmixed::GLenum, glmixed::GLuint> GetStringi; ///< Wrapper for glGetStringi
    static Function<glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, const glmixed::GLchar *> GetSubroutineIndex; ///< Wrapper for glGetSubroutineIndex
    static Function<glmixed::GLint, glmixed::GLuint, glmixed::GLenum, const glmixed::GLchar *> GetSubroutineUniformLocation; ///< Wrapper for glGetSubroutineUniformLocation
    static Function<void, glmixed::GLsync, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLint *> GetSynciv; ///< Wrapper for glGetSynciv
    static Function<void, glmixed::GLsync, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLint *> GetSyncivAPPLE; ///< Wrapper for glGetSyncivAPPLE
    static Function<void, glmixed::GLenum, glmixed::GLfloat *> GetTexBumpParameterfvATI; ///< Wrapper for glGetTexBumpParameterfvATI
    static Function<void, glmixed::GLenum, glmixed::GLint *> GetTexBumpParameterivATI; ///< Wrapper for glGetTexBumpParameterivATI
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetTexEnvfv; ///< Wrapper for glGetTexEnvfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetTexEnviv; ///< Wrapper for glGetTexEnviv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfixed *> GetTexEnvxvOES; ///< Wrapper for glGetTexEnvxvOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetTexFilterFuncSGIS; ///< Wrapper for glGetTexFilterFuncSGIS
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLdouble *> GetTexGendv; ///< Wrapper for glGetTexGendv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetTexGenfv; ///< Wrapper for glGetTexGenfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetTexGeniv; ///< Wrapper for glGetTexGeniv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfixed *> GetTexGenxvOES; ///< Wrapper for glGetTexGenxvOES
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, void *> GetTexImage; ///< Wrapper for glGetTexImage
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLfloat *> GetTexLevelParameterfv; ///< Wrapper for glGetTexLevelParameterfv
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLint *> GetTexLevelParameteriv; ///< Wrapper for glGetTexLevelParameteriv
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLfixed *> GetTexLevelParameterxvOES; ///< Wrapper for glGetTexLevelParameterxvOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetTexParameterfv; ///< Wrapper for glGetTexParameterfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetTexParameterIiv; ///< Wrapper for glGetTexParameterIiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetTexParameterIivEXT; ///< Wrapper for glGetTexParameterIivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetTexParameterIivOES; ///< Wrapper for glGetTexParameterIivOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint *> GetTexParameterIuiv; ///< Wrapper for glGetTexParameterIuiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint *> GetTexParameterIuivEXT; ///< Wrapper for glGetTexParameterIuivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint *> GetTexParameterIuivOES; ///< Wrapper for glGetTexParameterIuivOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetTexParameteriv; ///< Wrapper for glGetTexParameteriv
    static Function<void, glmixed::GLenum, glmixed::GLenum, void **> GetTexParameterPointervAPPLE; ///< Wrapper for glGetTexParameterPointervAPPLE
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfixed *> GetTexParameterxvOES; ///< Wrapper for glGetTexParameterxvOES
    static Function<glmixed::GLuint64, glmixed::GLuint> GetTextureHandleARB; ///< Wrapper for glGetTextureHandleARB
    static Function<glmixed::GLuint64, glmixed::GLuint> GetTextureHandleIMG; ///< Wrapper for glGetTextureHandleIMG
    static Function<glmixed::GLuint64, glmixed::GLuint> GetTextureHandleNV; ///< Wrapper for glGetTextureHandleNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *> GetTextureImage; ///< Wrapper for glGetTextureImage
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, void *> GetTextureImageEXT; ///< Wrapper for glGetTextureImageEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLfloat *> GetTextureLevelParameterfv; ///< Wrapper for glGetTextureLevelParameterfv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLfloat *> GetTextureLevelParameterfvEXT; ///< Wrapper for glGetTextureLevelParameterfvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLint *> GetTextureLevelParameteriv; ///< Wrapper for glGetTextureLevelParameteriv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLint *> GetTextureLevelParameterivEXT; ///< Wrapper for glGetTextureLevelParameterivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat *> GetTextureParameterfv; ///< Wrapper for glGetTextureParameterfv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat *> GetTextureParameterfvEXT; ///< Wrapper for glGetTextureParameterfvEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetTextureParameterIiv; ///< Wrapper for glGetTextureParameterIiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetTextureParameterIivEXT; ///< Wrapper for glGetTextureParameterIivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint *> GetTextureParameterIuiv; ///< Wrapper for glGetTextureParameterIuiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint *> GetTextureParameterIuivEXT; ///< Wrapper for glGetTextureParameterIuivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetTextureParameteriv; ///< Wrapper for glGetTextureParameteriv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLint *> GetTextureParameterivEXT; ///< Wrapper for glGetTextureParameterivEXT
    static Function<glmixed::GLuint64, glmixed::GLuint, glmixed::GLuint> GetTextureSamplerHandleARB; ///< Wrapper for glGetTextureSamplerHandleARB
    static Function<glmixed::GLuint64, glmixed::GLuint, glmixed::GLuint> GetTextureSamplerHandleIMG; ///< Wrapper for glGetTextureSamplerHandleIMG
    static Function<glmixed::GLuint64, glmixed::GLuint, glmixed::GLuint> GetTextureSamplerHandleNV; ///< Wrapper for glGetTextureSamplerHandleNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *> GetTextureSubImage; ///< Wrapper for glGetTextureSubImage
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetTrackMatrixivNV; ///< Wrapper for glGetTrackMatrixivNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLint64 *> GetTransformFeedbacki64_v; ///< Wrapper for glGetTransformFeedbacki64_v
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLint *> GetTransformFeedbacki_v; ///< Wrapper for glGetTransformFeedbacki_v
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetTransformFeedbackiv; ///< Wrapper for glGetTransformFeedbackiv
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLsizei *, glmixed::GLenum *, glmixed::GLchar *> GetTransformFeedbackVarying; ///< Wrapper for glGetTransformFeedbackVarying
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLsizei *, glmixed::GLenum *, glmixed::GLchar *> GetTransformFeedbackVaryingEXT; ///< Wrapper for glGetTransformFeedbackVaryingEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLint *> GetTransformFeedbackVaryingNV; ///< Wrapper for glGetTransformFeedbackVaryingNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLchar *> GetTranslatedShaderSourceANGLE; ///< Wrapper for glGetTranslatedShaderSourceANGLE
    static Function<glmixed::GLuint, glmixed::GLuint, const glmixed::GLchar *> GetUniformBlockIndex; ///< Wrapper for glGetUniformBlockIndex
    static Function<glmixed::GLint, glmixed::GLuint, glmixed::GLint> GetUniformBufferSizeEXT; ///< Wrapper for glGetUniformBufferSizeEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLdouble *> GetUniformdv; ///< Wrapper for glGetUniformdv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLfloat *> GetUniformfv; ///< Wrapper for glGetUniformfv
    static Function<void, glmixed::GLhandleARB, glmixed::GLint, glmixed::GLfloat *> GetUniformfvARB; ///< Wrapper for glGetUniformfvARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint64 *> GetUniformi64vARB; ///< Wrapper for glGetUniformi64vARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint64EXT *> GetUniformi64vNV; ///< Wrapper for glGetUniformi64vNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLchar *const*, glmixed::GLuint *> GetUniformIndices; ///< Wrapper for glGetUniformIndices
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint *> GetUniformiv; ///< Wrapper for glGetUniformiv
    static Function<void, glmixed::GLhandleARB, glmixed::GLint, glmixed::GLint *> GetUniformivARB; ///< Wrapper for glGetUniformivARB
    static Function<glmixed::GLint, glmixed::GLuint, const glmixed::GLchar *> GetUniformLocation; ///< Wrapper for glGetUniformLocation
    static Function<glmixed::GLint, glmixed::GLhandleARB, const glmixed::GLcharARB *> GetUniformLocationARB; ///< Wrapper for glGetUniformLocationARB
    static Function<glmixed::GLintptr, glmixed::GLuint, glmixed::GLint> GetUniformOffsetEXT; ///< Wrapper for glGetUniformOffsetEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLuint *> GetUniformSubroutineuiv; ///< Wrapper for glGetUniformSubroutineuiv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint64 *> GetUniformui64vARB; ///< Wrapper for glGetUniformui64vARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint64EXT *> GetUniformui64vNV; ///< Wrapper for glGetUniformui64vNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint *> GetUniformuiv; ///< Wrapper for glGetUniformuiv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint *> GetUniformuivEXT; ///< Wrapper for glGetUniformuivEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLubyte *> GetUnsignedBytei_vEXT; ///< Wrapper for glGetUnsignedBytei_vEXT
    static Function<void, glmixed::GLenum, glmixed::GLubyte *> GetUnsignedBytevEXT; ///< Wrapper for glGetUnsignedBytevEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat *> GetVariantArrayObjectfvATI; ///< Wrapper for glGetVariantArrayObjectfvATI
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetVariantArrayObjectivATI; ///< Wrapper for glGetVariantArrayObjectivATI
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLboolean *> GetVariantBooleanvEXT; ///< Wrapper for glGetVariantBooleanvEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat *> GetVariantFloatvEXT; ///< Wrapper for glGetVariantFloatvEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetVariantIntegervEXT; ///< Wrapper for glGetVariantIntegervEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, void **> GetVariantPointervEXT; ///< Wrapper for glGetVariantPointervEXT
    static Function<glmixed::GLint, glmixed::GLuint, const glmixed::GLchar *> GetVaryingLocationNV; ///< Wrapper for glGetVaryingLocationNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLint64 *> GetVertexArrayIndexed64iv; ///< Wrapper for glGetVertexArrayIndexed64iv
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetVertexArrayIndexediv; ///< Wrapper for glGetVertexArrayIndexediv
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetVertexArrayIntegeri_vEXT; ///< Wrapper for glGetVertexArrayIntegeri_vEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetVertexArrayIntegervEXT; ///< Wrapper for glGetVertexArrayIntegervEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetVertexArrayiv; ///< Wrapper for glGetVertexArrayiv
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, void **> GetVertexArrayPointeri_vEXT; ///< Wrapper for glGetVertexArrayPointeri_vEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, void **> GetVertexArrayPointervEXT; ///< Wrapper for glGetVertexArrayPointervEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat *> GetVertexAttribArrayObjectfvATI; ///< Wrapper for glGetVertexAttribArrayObjectfvATI
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetVertexAttribArrayObjectivATI; ///< Wrapper for glGetVertexAttribArrayObjectivATI
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLdouble *> GetVertexAttribdv; ///< Wrapper for glGetVertexAttribdv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLdouble *> GetVertexAttribdvARB; ///< Wrapper for glGetVertexAttribdvARB
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLdouble *> GetVertexAttribdvNV; ///< Wrapper for glGetVertexAttribdvNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat *> GetVertexAttribfv; ///< Wrapper for glGetVertexAttribfv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat *> GetVertexAttribfvARB; ///< Wrapper for glGetVertexAttribfvARB
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat *> GetVertexAttribfvNV; ///< Wrapper for glGetVertexAttribfvNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetVertexAttribIiv; ///< Wrapper for glGetVertexAttribIiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetVertexAttribIivEXT; ///< Wrapper for glGetVertexAttribIivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint *> GetVertexAttribIuiv; ///< Wrapper for glGetVertexAttribIuiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint *> GetVertexAttribIuivEXT; ///< Wrapper for glGetVertexAttribIuivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetVertexAttribiv; ///< Wrapper for glGetVertexAttribiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetVertexAttribivARB; ///< Wrapper for glGetVertexAttribivARB
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetVertexAttribivNV; ///< Wrapper for glGetVertexAttribivNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLdouble *> GetVertexAttribLdv; ///< Wrapper for glGetVertexAttribLdv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLdouble *> GetVertexAttribLdvEXT; ///< Wrapper for glGetVertexAttribLdvEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint64EXT *> GetVertexAttribLi64vNV; ///< Wrapper for glGetVertexAttribLi64vNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint64EXT *> GetVertexAttribLui64vARB; ///< Wrapper for glGetVertexAttribLui64vARB
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint64EXT *> GetVertexAttribLui64vNV; ///< Wrapper for glGetVertexAttribLui64vNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, void **> GetVertexAttribPointerv; ///< Wrapper for glGetVertexAttribPointerv
    static Function<void, glmixed::GLuint, glmixed::GLenum, void **> GetVertexAttribPointervARB; ///< Wrapper for glGetVertexAttribPointervARB
    static Function<void, glmixed::GLuint, glmixed::GLenum, void **> GetVertexAttribPointervNV; ///< Wrapper for glGetVertexAttribPointervNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetVideoCaptureivNV; ///< Wrapper for glGetVideoCaptureivNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLdouble *> GetVideoCaptureStreamdvNV; ///< Wrapper for glGetVideoCaptureStreamdvNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat *> GetVideoCaptureStreamfvNV; ///< Wrapper for glGetVideoCaptureStreamfvNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetVideoCaptureStreamivNV; ///< Wrapper for glGetVideoCaptureStreamivNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint64EXT *> GetVideoi64vNV; ///< Wrapper for glGetVideoi64vNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> GetVideoivNV; ///< Wrapper for glGetVideoivNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint64EXT *> GetVideoui64vNV; ///< Wrapper for glGetVideoui64vNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint *> GetVideouivNV; ///< Wrapper for glGetVideouivNV
    static Function<glmixed::GLVULKANPROCNV, const glmixed::GLchar *> GetVkProcAddrNV; ///< Wrapper for glGetVkProcAddrNV
    static Function<void, glmixed::GLbyte> GlobalAlphaFactorbSUN; ///< Wrapper for glGlobalAlphaFactorbSUN
    static Function<void, glmixed::GLdouble> GlobalAlphaFactordSUN; ///< Wrapper for glGlobalAlphaFactordSUN
    static Function<void, glmixed::GLfloat> GlobalAlphaFactorfSUN; ///< Wrapper for glGlobalAlphaFactorfSUN
    static Function<void, glmixed::GLint> GlobalAlphaFactoriSUN; ///< Wrapper for glGlobalAlphaFactoriSUN
    static Function<void, glmixed::GLshort> GlobalAlphaFactorsSUN; ///< Wrapper for glGlobalAlphaFactorsSUN
    static Function<void, glmixed::GLubyte> GlobalAlphaFactorubSUN; ///< Wrapper for glGlobalAlphaFactorubSUN
    static Function<void, glmixed::GLuint> GlobalAlphaFactoruiSUN; ///< Wrapper for glGlobalAlphaFactoruiSUN
    static Function<void, glmixed::GLushort> GlobalAlphaFactorusSUN; ///< Wrapper for glGlobalAlphaFactorusSUN
    static Function<void, glmixed::GLenum, glmixed::GLenum> Hint; ///< Wrapper for glHint
    static Function<void, glmixed::GLenum, glmixed::VertexHintsMaskPGI> HintPGI; ///< Wrapper for glHintPGI
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLboolean> Histogram; ///< Wrapper for glHistogram
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLboolean> HistogramEXT; ///< Wrapper for glHistogramEXT
    static Function<void, glmixed::GLenum, const void *> IglooInterfaceSGIX; ///< Wrapper for glIglooInterfaceSGIX
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat> ImageTransformParameterfHP; ///< Wrapper for glImageTransformParameterfHP
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> ImageTransformParameterfvHP; ///< Wrapper for glImageTransformParameterfvHP
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> ImageTransformParameteriHP; ///< Wrapper for glImageTransformParameteriHP
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> ImageTransformParameterivHP; ///< Wrapper for glImageTransformParameterivHP
    static Function<void, glmixed::GLuint, glmixed::GLuint64, glmixed::GLenum, glmixed::GLint> ImportMemoryFdEXT; ///< Wrapper for glImportMemoryFdEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint64, glmixed::GLenum, void *> ImportMemoryWin32HandleEXT; ///< Wrapper for glImportMemoryWin32HandleEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint64, glmixed::GLenum, const void *> ImportMemoryWin32NameEXT; ///< Wrapper for glImportMemoryWin32NameEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint> ImportSemaphoreFdEXT; ///< Wrapper for glImportSemaphoreFdEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, void *> ImportSemaphoreWin32HandleEXT; ///< Wrapper for glImportSemaphoreWin32HandleEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, const void *> ImportSemaphoreWin32NameEXT; ///< Wrapper for glImportSemaphoreWin32NameEXT
    static Function<glmixed::GLsync, glmixed::GLenum, glmixed::GLintptr, glmixed::GLbitfield> ImportSyncEXT; ///< Wrapper for glImportSyncEXT
    static Function<void, glmixed::GLdouble> Indexd; ///< Wrapper for glIndexd
    static Function<void, const glmixed::GLdouble *> Indexdv; ///< Wrapper for glIndexdv
    static Function<void, glmixed::GLfloat> Indexf; ///< Wrapper for glIndexf
    static Function<void, glmixed::GLenum, glmixed::GLsizei> IndexFormatNV; ///< Wrapper for glIndexFormatNV
    static Function<void, glmixed::GLenum, glmixed::GLclampf> IndexFuncEXT; ///< Wrapper for glIndexFuncEXT
    static Function<void, const glmixed::GLfloat *> Indexfv; ///< Wrapper for glIndexfv
    static Function<void, glmixed::GLint> Indexi; ///< Wrapper for glIndexi
    static Function<void, const glmixed::GLint *> Indexiv; ///< Wrapper for glIndexiv
    static Function<void, glmixed::GLuint> IndexMask; ///< Wrapper for glIndexMask
    static Function<void, glmixed::GLenum, glmixed::GLenum> IndexMaterialEXT; ///< Wrapper for glIndexMaterialEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const void *> IndexPointer; ///< Wrapper for glIndexPointer
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, const void *> IndexPointerEXT; ///< Wrapper for glIndexPointerEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, const void **, glmixed::GLint> IndexPointerListIBM; ///< Wrapper for glIndexPointerListIBM
    static Function<void, glmixed::GLshort> Indexs; ///< Wrapper for glIndexs
    static Function<void, const glmixed::GLshort *> Indexsv; ///< Wrapper for glIndexsv
    static Function<void, glmixed::GLubyte> Indexub; ///< Wrapper for glIndexub
    static Function<void, const glmixed::GLubyte *> Indexubv; ///< Wrapper for glIndexubv
    static Function<void, glmixed::GLfixed> IndexxOES; ///< Wrapper for glIndexxOES
    static Function<void, const glmixed::GLfixed *> IndexxvOES; ///< Wrapper for glIndexxvOES
    static Function<void> InitNames; ///< Wrapper for glInitNames
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> InsertComponentEXT; ///< Wrapper for glInsertComponentEXT
    static Function<void, glmixed::GLsizei, const glmixed::GLchar *> InsertEventMarkerEXT; ///< Wrapper for glInsertEventMarkerEXT
    static Function<void, glmixed::GLsizei, glmixed::GLint *> InstrumentsBufferSGIX; ///< Wrapper for glInstrumentsBufferSGIX
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const void *> InterleavedArrays; ///< Wrapper for glInterleavedArrays
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLfloat> InterpolatePathsNV; ///< Wrapper for glInterpolatePathsNV
    static Function<void, glmixed::GLuint> InvalidateBufferData; ///< Wrapper for glInvalidateBufferData
    static Function<void, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr> InvalidateBufferSubData; ///< Wrapper for glInvalidateBufferSubData
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLenum *> InvalidateFramebuffer; ///< Wrapper for glInvalidateFramebuffer
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLenum *> InvalidateNamedFramebufferData; ///< Wrapper for glInvalidateNamedFramebufferData
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLenum *, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> InvalidateNamedFramebufferSubData; ///< Wrapper for glInvalidateNamedFramebufferSubData
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLenum *, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> InvalidateSubFramebuffer; ///< Wrapper for glInvalidateSubFramebuffer
    static Function<void, glmixed::GLuint, glmixed::GLint> InvalidateTexImage; ///< Wrapper for glInvalidateTexImage
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei> InvalidateTexSubImage; ///< Wrapper for glInvalidateTexSubImage
    static Function<glmixed::GLboolean, glmixed::GLuint> IsAsyncMarkerSGIX; ///< Wrapper for glIsAsyncMarkerSGIX
    static Function<glmixed::GLboolean, glmixed::GLuint> IsBuffer; ///< Wrapper for glIsBuffer
    static Function<glmixed::GLboolean, glmixed::GLuint> IsBufferARB; ///< Wrapper for glIsBufferARB
    static Function<glmixed::GLboolean, glmixed::GLenum> IsBufferResidentNV; ///< Wrapper for glIsBufferResidentNV
    static Function<glmixed::GLboolean, glmixed::GLuint> IsCommandListNV; ///< Wrapper for glIsCommandListNV
    static Function<glmixed::GLboolean, glmixed::GLenum> IsEnabled; ///< Wrapper for glIsEnabled
    static Function<glmixed::GLboolean, glmixed::GLenum, glmixed::GLuint> IsEnabledi; ///< Wrapper for glIsEnabledi
    static Function<glmixed::GLboolean, glmixed::GLenum, glmixed::GLuint> IsEnablediEXT; ///< Wrapper for glIsEnablediEXT
    static Function<glmixed::GLboolean, glmixed::GLenum, glmixed::GLuint> IsEnabledIndexedEXT; ///< Wrapper for glIsEnabledIndexedEXT
    static Function<glmixed::GLboolean, glmixed::GLenum, glmixed::GLuint> IsEnablediNV; ///< Wrapper for glIsEnablediNV
    static Function<glmixed::GLboolean, glmixed::GLenum, glmixed::GLuint> IsEnablediOES; ///< Wrapper for glIsEnablediOES
    static Function<glmixed::GLboolean, glmixed::GLuint> IsFenceAPPLE; ///< Wrapper for glIsFenceAPPLE
    static Function<glmixed::GLboolean, glmixed::GLuint> IsFenceNV; ///< Wrapper for glIsFenceNV
    static Function<glmixed::GLboolean, glmixed::GLuint> IsFramebuffer; ///< Wrapper for glIsFramebuffer
    static Function<glmixed::GLboolean, glmixed::GLuint> IsFramebufferEXT; ///< Wrapper for glIsFramebufferEXT
    static Function<glmixed::GLboolean, glmixed::GLuint64> IsImageHandleResidentARB; ///< Wrapper for glIsImageHandleResidentARB
    static Function<glmixed::GLboolean, glmixed::GLuint64> IsImageHandleResidentNV; ///< Wrapper for glIsImageHandleResidentNV
    static Function<glmixed::GLboolean, glmixed::GLuint> IsList; ///< Wrapper for glIsList
    static Function<glmixed::GLboolean, glmixed::GLuint> IsMemoryObjectEXT; ///< Wrapper for glIsMemoryObjectEXT
    static Function<glmixed::GLboolean, glmixed::GLenum, glmixed::GLuint> IsNameAMD; ///< Wrapper for glIsNameAMD
    static Function<glmixed::GLboolean, glmixed::GLuint> IsNamedBufferResidentNV; ///< Wrapper for glIsNamedBufferResidentNV
    static Function<glmixed::GLboolean, glmixed::GLint, const glmixed::GLchar *> IsNamedStringARB; ///< Wrapper for glIsNamedStringARB
    static Function<glmixed::GLboolean, glmixed::GLuint> IsObjectBufferATI; ///< Wrapper for glIsObjectBufferATI
    static Function<glmixed::GLboolean, glmixed::GLuint> IsOcclusionQueryNV; ///< Wrapper for glIsOcclusionQueryNV
    static Function<glmixed::GLboolean, glmixed::GLuint> IsPathNV; ///< Wrapper for glIsPathNV
    static Function<glmixed::GLboolean, glmixed::GLuint, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat> IsPointInFillPathNV; ///< Wrapper for glIsPointInFillPathNV
    static Function<glmixed::GLboolean, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat> IsPointInStrokePathNV; ///< Wrapper for glIsPointInStrokePathNV
    static Function<glmixed::GLboolean, glmixed::GLuint> IsProgram; ///< Wrapper for glIsProgram
    static Function<glmixed::GLboolean, glmixed::GLuint> IsProgramARB; ///< Wrapper for glIsProgramARB
    static Function<glmixed::GLboolean, glmixed::GLuint> IsProgramNV; ///< Wrapper for glIsProgramNV
    static Function<glmixed::GLboolean, glmixed::GLuint> IsProgramPipeline; ///< Wrapper for glIsProgramPipeline
    static Function<glmixed::GLboolean, glmixed::GLuint> IsProgramPipelineEXT; ///< Wrapper for glIsProgramPipelineEXT
    static Function<glmixed::GLboolean, glmixed::GLuint> IsQuery; ///< Wrapper for glIsQuery
    static Function<glmixed::GLboolean, glmixed::GLuint> IsQueryARB; ///< Wrapper for glIsQueryARB
    static Function<glmixed::GLboolean, glmixed::GLuint> IsQueryEXT; ///< Wrapper for glIsQueryEXT
    static Function<glmixed::GLboolean, glmixed::GLuint> IsRenderbuffer; ///< Wrapper for glIsRenderbuffer
    static Function<glmixed::GLboolean, glmixed::GLuint> IsRenderbufferEXT; ///< Wrapper for glIsRenderbufferEXT
    static Function<glmixed::GLboolean, glmixed::GLuint> IsSampler; ///< Wrapper for glIsSampler
    static Function<glmixed::GLboolean, glmixed::GLuint> IsSemaphoreEXT; ///< Wrapper for glIsSemaphoreEXT
    static Function<glmixed::GLboolean, glmixed::GLuint> IsShader; ///< Wrapper for glIsShader
    static Function<glmixed::GLboolean, glmixed::GLuint> IsStateNV; ///< Wrapper for glIsStateNV
    static Function<glmixed::GLboolean, glmixed::GLsync> IsSync; ///< Wrapper for glIsSync
    static Function<glmixed::GLboolean, glmixed::GLsync> IsSyncAPPLE; ///< Wrapper for glIsSyncAPPLE
    static Function<glmixed::GLboolean, glmixed::GLuint> IsTexture; ///< Wrapper for glIsTexture
    static Function<glmixed::GLboolean, glmixed::GLuint> IsTextureEXT; ///< Wrapper for glIsTextureEXT
    static Function<glmixed::GLboolean, glmixed::GLuint64> IsTextureHandleResidentARB; ///< Wrapper for glIsTextureHandleResidentARB
    static Function<glmixed::GLboolean, glmixed::GLuint64> IsTextureHandleResidentNV; ///< Wrapper for glIsTextureHandleResidentNV
    static Function<glmixed::GLboolean, glmixed::GLuint> IsTransformFeedback; ///< Wrapper for glIsTransformFeedback
    static Function<glmixed::GLboolean, glmixed::GLuint> IsTransformFeedbackNV; ///< Wrapper for glIsTransformFeedbackNV
    static Function<glmixed::GLboolean, glmixed::GLuint, glmixed::GLenum> IsVariantEnabledEXT; ///< Wrapper for glIsVariantEnabledEXT
    static Function<glmixed::GLboolean, glmixed::GLuint> IsVertexArray; ///< Wrapper for glIsVertexArray
    static Function<glmixed::GLboolean, glmixed::GLuint> IsVertexArrayAPPLE; ///< Wrapper for glIsVertexArrayAPPLE
    static Function<glmixed::GLboolean, glmixed::GLuint> IsVertexArrayOES; ///< Wrapper for glIsVertexArrayOES
    static Function<glmixed::GLboolean, glmixed::GLuint, glmixed::GLenum> IsVertexAttribEnabledAPPLE; ///< Wrapper for glIsVertexAttribEnabledAPPLE
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLchar *> LabelObjectEXT; ///< Wrapper for glLabelObjectEXT
    static Function<void, glmixed::GLuint, glmixed::GLbitfield, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei> LGPUCopyImageSubDataNVX; ///< Wrapper for glLGPUCopyImageSubDataNVX
    static Function<void> LGPUInterlockNVX; ///< Wrapper for glLGPUInterlockNVX
    static Function<void, glmixed::GLbitfield, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr, const void *> LGPUNamedBufferSubDataNVX; ///< Wrapper for glLGPUNamedBufferSubDataNVX
    static Function<void, glmixed::GLenum, glmixed::GLint> LightEnviSGIX; ///< Wrapper for glLightEnviSGIX
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat> Lightf; ///< Wrapper for glLightf
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> Lightfv; ///< Wrapper for glLightfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> Lighti; ///< Wrapper for glLighti
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> Lightiv; ///< Wrapper for glLightiv
    static Function<void, glmixed::GLenum, glmixed::GLfloat> LightModelf; ///< Wrapper for glLightModelf
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> LightModelfv; ///< Wrapper for glLightModelfv
    static Function<void, glmixed::GLenum, glmixed::GLint> LightModeli; ///< Wrapper for glLightModeli
    static Function<void, glmixed::GLenum, const glmixed::GLint *> LightModeliv; ///< Wrapper for glLightModeliv
    static Function<void, glmixed::GLenum, glmixed::GLfixed> LightModelxOES; ///< Wrapper for glLightModelxOES
    static Function<void, glmixed::GLenum, const glmixed::GLfixed *> LightModelxvOES; ///< Wrapper for glLightModelxvOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfixed> LightxOES; ///< Wrapper for glLightxOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfixed *> LightxvOES; ///< Wrapper for glLightxvOES
    static Function<void, glmixed::GLint, glmixed::GLushort> LineStipple; ///< Wrapper for glLineStipple
    static Function<void, glmixed::GLfloat> LineWidth; ///< Wrapper for glLineWidth
    static Function<void, glmixed::GLfixed> LineWidthxOES; ///< Wrapper for glLineWidthxOES
    static Function<void, glmixed::GLuint> LinkProgram; ///< Wrapper for glLinkProgram
    static Function<void, glmixed::GLhandleARB> LinkProgramARB; ///< Wrapper for glLinkProgramARB
    static Function<void, glmixed::GLuint> ListBase; ///< Wrapper for glListBase
    static Function<void, glmixed::GLuint, glmixed::GLuint, const void **, const glmixed::GLsizei *, const glmixed::GLuint *, const glmixed::GLuint *, glmixed::GLuint> ListDrawCommandsStatesClientNV; ///< Wrapper for glListDrawCommandsStatesClientNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat> ListParameterfSGIX; ///< Wrapper for glListParameterfSGIX
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLfloat *> ListParameterfvSGIX; ///< Wrapper for glListParameterfvSGIX
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint> ListParameteriSGIX; ///< Wrapper for glListParameteriSGIX
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLint *> ListParameterivSGIX; ///< Wrapper for glListParameterivSGIX
    static Function<void> LoadIdentity; ///< Wrapper for glLoadIdentity
    static Function<void, glmixed::FfdMaskSGIX> LoadIdentityDeformationMapSGIX; ///< Wrapper for glLoadIdentityDeformationMapSGIX
    static Function<void, const glmixed::GLdouble *> LoadMatrixd; ///< Wrapper for glLoadMatrixd
    static Function<void, const glmixed::GLfloat *> LoadMatrixf; ///< Wrapper for glLoadMatrixf
    static Function<void, const glmixed::GLfixed *> LoadMatrixxOES; ///< Wrapper for glLoadMatrixxOES
    static Function<void, glmixed::GLuint> LoadName; ///< Wrapper for glLoadName
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLubyte *> LoadProgramNV; ///< Wrapper for glLoadProgramNV
    static Function<void, const glmixed::GLdouble *> LoadTransposeMatrixd; ///< Wrapper for glLoadTransposeMatrixd
    static Function<void, const glmixed::GLdouble *> LoadTransposeMatrixdARB; ///< Wrapper for glLoadTransposeMatrixdARB
    static Function<void, const glmixed::GLfloat *> LoadTransposeMatrixf; ///< Wrapper for glLoadTransposeMatrixf
    static Function<void, const glmixed::GLfloat *> LoadTransposeMatrixfARB; ///< Wrapper for glLoadTransposeMatrixfARB
    static Function<void, const glmixed::GLfixed *> LoadTransposeMatrixxOES; ///< Wrapper for glLoadTransposeMatrixxOES
    static Function<void, glmixed::GLint, glmixed::GLsizei> LockArraysEXT; ///< Wrapper for glLockArraysEXT
    static Function<void, glmixed::GLenum> LogicOp; ///< Wrapper for glLogicOp
    static Function<void, glmixed::GLenum> MakeBufferNonResidentNV; ///< Wrapper for glMakeBufferNonResidentNV
    static Function<void, glmixed::GLenum, glmixed::GLenum> MakeBufferResidentNV; ///< Wrapper for glMakeBufferResidentNV
    static Function<void, glmixed::GLuint64> MakeImageHandleNonResidentARB; ///< Wrapper for glMakeImageHandleNonResidentARB
    static Function<void, glmixed::GLuint64> MakeImageHandleNonResidentNV; ///< Wrapper for glMakeImageHandleNonResidentNV
    static Function<void, glmixed::GLuint64, glmixed::GLenum> MakeImageHandleResidentARB; ///< Wrapper for glMakeImageHandleResidentARB
    static Function<void, glmixed::GLuint64, glmixed::GLenum> MakeImageHandleResidentNV; ///< Wrapper for glMakeImageHandleResidentNV
    static Function<void, glmixed::GLuint> MakeNamedBufferNonResidentNV; ///< Wrapper for glMakeNamedBufferNonResidentNV
    static Function<void, glmixed::GLuint, glmixed::GLenum> MakeNamedBufferResidentNV; ///< Wrapper for glMakeNamedBufferResidentNV
    static Function<void, glmixed::GLuint64> MakeTextureHandleNonResidentARB; ///< Wrapper for glMakeTextureHandleNonResidentARB
    static Function<void, glmixed::GLuint64> MakeTextureHandleNonResidentNV; ///< Wrapper for glMakeTextureHandleNonResidentNV
    static Function<void, glmixed::GLuint64> MakeTextureHandleResidentARB; ///< Wrapper for glMakeTextureHandleResidentARB
    static Function<void, glmixed::GLuint64> MakeTextureHandleResidentNV; ///< Wrapper for glMakeTextureHandleResidentNV
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLint, glmixed::GLint, const glmixed::GLdouble *> Map1d; ///< Wrapper for glMap1d
    static Function<void, glmixed::GLenum, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLint, glmixed::GLint, const glmixed::GLfloat *> Map1f; ///< Wrapper for glMap1f
    static Function<void, glmixed::GLenum, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLint, glmixed::GLint, glmixed::GLfixed> Map1xOES; ///< Wrapper for glMap1xOES
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLint, glmixed::GLint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLint, glmixed::GLint, const glmixed::GLdouble *> Map2d; ///< Wrapper for glMap2d
    static Function<void, glmixed::GLenum, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLint, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLint, glmixed::GLint, const glmixed::GLfloat *> Map2f; ///< Wrapper for glMap2f
    static Function<void, glmixed::GLenum, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLint, glmixed::GLint, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLint, glmixed::GLint, glmixed::GLfixed> Map2xOES; ///< Wrapper for glMap2xOES
    static Function<void *, glmixed::GLenum, glmixed::GLenum> MapBuffer; ///< Wrapper for glMapBuffer
    static Function<void *, glmixed::GLenum, glmixed::GLenum> MapBufferARB; ///< Wrapper for glMapBufferARB
    static Function<void *, glmixed::GLenum, glmixed::GLenum> MapBufferOES; ///< Wrapper for glMapBufferOES
    static Function<void *, glmixed::GLenum, glmixed::GLintptr, glmixed::GLsizeiptr, glmixed::MapBufferAccessMask> MapBufferRange; ///< Wrapper for glMapBufferRange
    static Function<void *, glmixed::GLenum, glmixed::GLintptr, glmixed::GLsizeiptr, glmixed::MapBufferAccessMask> MapBufferRangeEXT; ///< Wrapper for glMapBufferRangeEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLint, glmixed::GLboolean, const void *> MapControlPointsNV; ///< Wrapper for glMapControlPointsNV
    static Function<void, glmixed::GLint, glmixed::GLdouble, glmixed::GLdouble> MapGrid1d; ///< Wrapper for glMapGrid1d
    static Function<void, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat> MapGrid1f; ///< Wrapper for glMapGrid1f
    static Function<void, glmixed::GLint, glmixed::GLfixed, glmixed::GLfixed> MapGrid1xOES; ///< Wrapper for glMapGrid1xOES
    static Function<void, glmixed::GLint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLint, glmixed::GLdouble, glmixed::GLdouble> MapGrid2d; ///< Wrapper for glMapGrid2d
    static Function<void, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat> MapGrid2f; ///< Wrapper for glMapGrid2f
    static Function<void, glmixed::GLint, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> MapGrid2xOES; ///< Wrapper for glMapGrid2xOES
    static Function<void *, glmixed::GLuint, glmixed::GLenum> MapNamedBuffer; ///< Wrapper for glMapNamedBuffer
    static Function<void *, glmixed::GLuint, glmixed::GLenum> MapNamedBufferEXT; ///< Wrapper for glMapNamedBufferEXT
    static Function<void *, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr, glmixed::MapBufferAccessMask> MapNamedBufferRange; ///< Wrapper for glMapNamedBufferRange
    static Function<void *, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr, glmixed::MapBufferAccessMask> MapNamedBufferRangeEXT; ///< Wrapper for glMapNamedBufferRangeEXT
    static Function<void *, glmixed::GLuint> MapObjectBufferATI; ///< Wrapper for glMapObjectBufferATI
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> MapParameterfvNV; ///< Wrapper for glMapParameterfvNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> MapParameterivNV; ///< Wrapper for glMapParameterivNV
    static Function<void *, glmixed::GLuint, glmixed::GLint, glmixed::GLbitfield, glmixed::GLint *, glmixed::GLenum *> MapTexture2DINTEL; ///< Wrapper for glMapTexture2DINTEL
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLint, glmixed::GLint, const glmixed::GLdouble *> MapVertexAttrib1dAPPLE; ///< Wrapper for glMapVertexAttrib1dAPPLE
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLint, glmixed::GLint, const glmixed::GLfloat *> MapVertexAttrib1fAPPLE; ///< Wrapper for glMapVertexAttrib1fAPPLE
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLint, glmixed::GLint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLint, glmixed::GLint, const glmixed::GLdouble *> MapVertexAttrib2dAPPLE; ///< Wrapper for glMapVertexAttrib2dAPPLE
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLint, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLint, glmixed::GLint, const glmixed::GLfloat *> MapVertexAttrib2fAPPLE; ///< Wrapper for glMapVertexAttrib2fAPPLE
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat> Materialf; ///< Wrapper for glMaterialf
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> Materialfv; ///< Wrapper for glMaterialfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> Materiali; ///< Wrapper for glMateriali
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> Materialiv; ///< Wrapper for glMaterialiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfixed> MaterialxOES; ///< Wrapper for glMaterialxOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfixed *> MaterialxvOES; ///< Wrapper for glMaterialxvOES
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> MatrixFrustumEXT; ///< Wrapper for glMatrixFrustumEXT
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, const void *> MatrixIndexPointerARB; ///< Wrapper for glMatrixIndexPointerARB
    static Function<void, glmixed::GLint, const glmixed::GLubyte *> MatrixIndexubvARB; ///< Wrapper for glMatrixIndexubvARB
    static Function<void, glmixed::GLint, const glmixed::GLuint *> MatrixIndexuivARB; ///< Wrapper for glMatrixIndexuivARB
    static Function<void, glmixed::GLint, const glmixed::GLushort *> MatrixIndexusvARB; ///< Wrapper for glMatrixIndexusvARB
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MatrixLoad3x2fNV; ///< Wrapper for glMatrixLoad3x2fNV
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MatrixLoad3x3fNV; ///< Wrapper for glMatrixLoad3x3fNV
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> MatrixLoaddEXT; ///< Wrapper for glMatrixLoaddEXT
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MatrixLoadfEXT; ///< Wrapper for glMatrixLoadfEXT
    static Function<void, glmixed::GLenum> MatrixLoadIdentityEXT; ///< Wrapper for glMatrixLoadIdentityEXT
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MatrixLoadTranspose3x3fNV; ///< Wrapper for glMatrixLoadTranspose3x3fNV
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> MatrixLoadTransposedEXT; ///< Wrapper for glMatrixLoadTransposedEXT
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MatrixLoadTransposefEXT; ///< Wrapper for glMatrixLoadTransposefEXT
    static Function<void, glmixed::GLenum> MatrixMode; ///< Wrapper for glMatrixMode
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MatrixMult3x2fNV; ///< Wrapper for glMatrixMult3x2fNV
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MatrixMult3x3fNV; ///< Wrapper for glMatrixMult3x3fNV
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> MatrixMultdEXT; ///< Wrapper for glMatrixMultdEXT
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MatrixMultfEXT; ///< Wrapper for glMatrixMultfEXT
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MatrixMultTranspose3x3fNV; ///< Wrapper for glMatrixMultTranspose3x3fNV
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> MatrixMultTransposedEXT; ///< Wrapper for glMatrixMultTransposedEXT
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MatrixMultTransposefEXT; ///< Wrapper for glMatrixMultTransposefEXT
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> MatrixOrthoEXT; ///< Wrapper for glMatrixOrthoEXT
    static Function<void, glmixed::GLenum> MatrixPopEXT; ///< Wrapper for glMatrixPopEXT
    static Function<void, glmixed::GLenum> MatrixPushEXT; ///< Wrapper for glMatrixPushEXT
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> MatrixRotatedEXT; ///< Wrapper for glMatrixRotatedEXT
    static Function<void, glmixed::GLenum, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> MatrixRotatefEXT; ///< Wrapper for glMatrixRotatefEXT
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> MatrixScaledEXT; ///< Wrapper for glMatrixScaledEXT
    static Function<void, glmixed::GLenum, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> MatrixScalefEXT; ///< Wrapper for glMatrixScalefEXT
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> MatrixTranslatedEXT; ///< Wrapper for glMatrixTranslatedEXT
    static Function<void, glmixed::GLenum, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> MatrixTranslatefEXT; ///< Wrapper for glMatrixTranslatefEXT
    static Function<void, glmixed::GLuint> MaxActiveShaderCoresARM; ///< Wrapper for glMaxActiveShaderCoresARM
    static Function<void, glmixed::GLuint> MaxShaderCompilerThreadsARB; ///< Wrapper for glMaxShaderCompilerThreadsARB
    static Function<void, glmixed::GLuint> MaxShaderCompilerThreadsKHR; ///< Wrapper for glMaxShaderCompilerThreadsKHR
    static Function<void, glmixed::MemoryBarrierMask> MemoryBarrier; ///< Wrapper for glMemoryBarrier
    static Function<void, glmixed::MemoryBarrierMask> MemoryBarrierByRegion; ///< Wrapper for glMemoryBarrierByRegion
    static Function<void, glmixed::MemoryBarrierMask> MemoryBarrierEXT; ///< Wrapper for glMemoryBarrierEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLint *> MemoryObjectParameterivEXT; ///< Wrapper for glMemoryObjectParameterivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLboolean> Minmax; ///< Wrapper for glMinmax
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLboolean> MinmaxEXT; ///< Wrapper for glMinmaxEXT
    static Function<void, glmixed::GLfloat> MinSampleShading; ///< Wrapper for glMinSampleShading
    static Function<void, glmixed::GLfloat> MinSampleShadingARB; ///< Wrapper for glMinSampleShadingARB
    static Function<void, glmixed::GLfloat> MinSampleShadingOES; ///< Wrapper for glMinSampleShadingOES
    static Function<void> MulticastBarrierNV; ///< Wrapper for glMulticastBarrierNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::ClearBufferMask, glmixed::GLenum> MulticastBlitFramebufferNV; ///< Wrapper for glMulticastBlitFramebufferNV
    static Function<void, glmixed::GLbitfield, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr, const void *> MulticastBufferSubDataNV; ///< Wrapper for glMulticastBufferSubDataNV
    static Function<void, glmixed::GLuint, glmixed::GLbitfield, glmixed::GLuint, glmixed::GLuint, glmixed::GLintptr, glmixed::GLintptr, glmixed::GLsizeiptr> MulticastCopyBufferSubDataNV; ///< Wrapper for glMulticastCopyBufferSubDataNV
    static Function<void, glmixed::GLuint, glmixed::GLbitfield, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei> MulticastCopyImageSubDataNV; ///< Wrapper for glMulticastCopyImageSubDataNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> MulticastFramebufferSampleLocationsfvNV; ///< Wrapper for glMulticastFramebufferSampleLocationsfvNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLint64 *> MulticastGetQueryObjecti64vNV; ///< Wrapper for glMulticastGetQueryObjecti64vNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLint *> MulticastGetQueryObjectivNV; ///< Wrapper for glMulticastGetQueryObjectivNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint64 *> MulticastGetQueryObjectui64vNV; ///< Wrapper for glMulticastGetQueryObjectui64vNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint *> MulticastGetQueryObjectuivNV; ///< Wrapper for glMulticastGetQueryObjectuivNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLint *> MulticastScissorArrayvNVX; ///< Wrapper for glMulticastScissorArrayvNVX
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> MulticastViewportArrayvNVX; ///< Wrapper for glMulticastViewportArrayvNVX
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat> MulticastViewportPositionWScaleNVX; ///< Wrapper for glMulticastViewportPositionWScaleNVX
    static Function<void, glmixed::GLuint, glmixed::GLbitfield> MulticastWaitSyncNV; ///< Wrapper for glMulticastWaitSyncNV
    static Function<void, glmixed::GLenum, const glmixed::GLint *, const glmixed::GLsizei *, glmixed::GLsizei> MultiDrawArrays; ///< Wrapper for glMultiDrawArrays
    static Function<void, glmixed::GLenum, const glmixed::GLint *, const glmixed::GLsizei *, glmixed::GLsizei> MultiDrawArraysEXT; ///< Wrapper for glMultiDrawArraysEXT
    static Function<void, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLsizei> MultiDrawArraysIndirect; ///< Wrapper for glMultiDrawArraysIndirect
    static Function<void, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLsizei> MultiDrawArraysIndirectAMD; ///< Wrapper for glMultiDrawArraysIndirectAMD
    static Function<void, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint> MultiDrawArraysIndirectBindlessCountNV; ///< Wrapper for glMultiDrawArraysIndirectBindlessCountNV
    static Function<void, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint> MultiDrawArraysIndirectBindlessNV; ///< Wrapper for glMultiDrawArraysIndirectBindlessNV
    static Function<void, glmixed::GLenum, const void *, glmixed::GLintptr, glmixed::GLsizei, glmixed::GLsizei> MultiDrawArraysIndirectCount; ///< Wrapper for glMultiDrawArraysIndirectCount
    static Function<void, glmixed::GLenum, const void *, glmixed::GLintptr, glmixed::GLsizei, glmixed::GLsizei> MultiDrawArraysIndirectCountARB; ///< Wrapper for glMultiDrawArraysIndirectCountARB
    static Function<void, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLsizei> MultiDrawArraysIndirectEXT; ///< Wrapper for glMultiDrawArraysIndirectEXT
    static Function<void, glmixed::GLenum, const glmixed::GLint *, const glmixed::GLsizei *, glmixed::GLsizei> MultiDrawElementArrayAPPLE; ///< Wrapper for glMultiDrawElementArrayAPPLE
    static Function<void, glmixed::GLenum, const glmixed::GLsizei *, glmixed::GLenum, const void *const*, glmixed::GLsizei> MultiDrawElements; ///< Wrapper for glMultiDrawElements
    static Function<void, glmixed::GLenum, const glmixed::GLsizei *, glmixed::GLenum, const void *const*, glmixed::GLsizei, const glmixed::GLint *> MultiDrawElementsBaseVertex; ///< Wrapper for glMultiDrawElementsBaseVertex
    static Function<void, glmixed::GLenum, const glmixed::GLsizei *, glmixed::GLenum, const void *const*, glmixed::GLsizei, const glmixed::GLint *> MultiDrawElementsBaseVertexEXT; ///< Wrapper for glMultiDrawElementsBaseVertexEXT
    static Function<void, glmixed::GLenum, const glmixed::GLsizei *, glmixed::GLenum, const void *const*, glmixed::GLsizei> MultiDrawElementsEXT; ///< Wrapper for glMultiDrawElementsEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLsizei> MultiDrawElementsIndirect; ///< Wrapper for glMultiDrawElementsIndirect
    static Function<void, glmixed::GLenum, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLsizei> MultiDrawElementsIndirectAMD; ///< Wrapper for glMultiDrawElementsIndirectAMD
    static Function<void, glmixed::GLenum, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint> MultiDrawElementsIndirectBindlessCountNV; ///< Wrapper for glMultiDrawElementsIndirectBindlessCountNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint> MultiDrawElementsIndirectBindlessNV; ///< Wrapper for glMultiDrawElementsIndirectBindlessNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, const void *, glmixed::GLintptr, glmixed::GLsizei, glmixed::GLsizei> MultiDrawElementsIndirectCount; ///< Wrapper for glMultiDrawElementsIndirectCount
    static Function<void, glmixed::GLenum, glmixed::GLenum, const void *, glmixed::GLintptr, glmixed::GLsizei, glmixed::GLsizei> MultiDrawElementsIndirectCountARB; ///< Wrapper for glMultiDrawElementsIndirectCountARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, const void *, glmixed::GLsizei, glmixed::GLsizei> MultiDrawElementsIndirectEXT; ///< Wrapper for glMultiDrawElementsIndirectEXT
    static Function<void, glmixed::GLintptr, glmixed::GLintptr, glmixed::GLsizei, glmixed::GLsizei> MultiDrawMeshTasksIndirectCountNV; ///< Wrapper for glMultiDrawMeshTasksIndirectCountNV
    static Function<void, glmixed::GLintptr, glmixed::GLsizei, glmixed::GLsizei> MultiDrawMeshTasksIndirectNV; ///< Wrapper for glMultiDrawMeshTasksIndirectNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, const glmixed::GLint *, const glmixed::GLsizei *, glmixed::GLsizei> MultiDrawRangeElementArrayAPPLE; ///< Wrapper for glMultiDrawRangeElementArrayAPPLE
    static Function<void, const glmixed::GLenum *, const glmixed::GLint *, const glmixed::GLsizei *, glmixed::GLsizei, glmixed::GLint> MultiModeDrawArraysIBM; ///< Wrapper for glMultiModeDrawArraysIBM
    static Function<void, const glmixed::GLenum *, const glmixed::GLsizei *, glmixed::GLenum, const void *const*, glmixed::GLsizei, glmixed::GLint> MultiModeDrawElementsIBM; ///< Wrapper for glMultiModeDrawElementsIBM
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> MultiTexBufferEXT; ///< Wrapper for glMultiTexBufferEXT
    static Function<void, glmixed::GLenum, glmixed::GLbyte> MultiTexCoord1bOES; ///< Wrapper for glMultiTexCoord1bOES
    static Function<void, glmixed::GLenum, const glmixed::GLbyte *> MultiTexCoord1bvOES; ///< Wrapper for glMultiTexCoord1bvOES
    static Function<void, glmixed::GLenum, glmixed::GLdouble> MultiTexCoord1d; ///< Wrapper for glMultiTexCoord1d
    static Function<void, glmixed::GLenum, glmixed::GLdouble> MultiTexCoord1dARB; ///< Wrapper for glMultiTexCoord1dARB
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> MultiTexCoord1dv; ///< Wrapper for glMultiTexCoord1dv
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> MultiTexCoord1dvARB; ///< Wrapper for glMultiTexCoord1dvARB
    static Function<void, glmixed::GLenum, glmixed::GLfloat> MultiTexCoord1f; ///< Wrapper for glMultiTexCoord1f
    static Function<void, glmixed::GLenum, glmixed::GLfloat> MultiTexCoord1fARB; ///< Wrapper for glMultiTexCoord1fARB
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MultiTexCoord1fv; ///< Wrapper for glMultiTexCoord1fv
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MultiTexCoord1fvARB; ///< Wrapper for glMultiTexCoord1fvARB
    static Function<void, glmixed::GLenum, glmixed::GLhalfNV> MultiTexCoord1hNV; ///< Wrapper for glMultiTexCoord1hNV
    static Function<void, glmixed::GLenum, const glmixed::GLhalfNV *> MultiTexCoord1hvNV; ///< Wrapper for glMultiTexCoord1hvNV
    static Function<void, glmixed::GLenum, glmixed::GLint> MultiTexCoord1i; ///< Wrapper for glMultiTexCoord1i
    static Function<void, glmixed::GLenum, glmixed::GLint> MultiTexCoord1iARB; ///< Wrapper for glMultiTexCoord1iARB
    static Function<void, glmixed::GLenum, const glmixed::GLint *> MultiTexCoord1iv; ///< Wrapper for glMultiTexCoord1iv
    static Function<void, glmixed::GLenum, const glmixed::GLint *> MultiTexCoord1ivARB; ///< Wrapper for glMultiTexCoord1ivARB
    static Function<void, glmixed::GLenum, glmixed::GLshort> MultiTexCoord1s; ///< Wrapper for glMultiTexCoord1s
    static Function<void, glmixed::GLenum, glmixed::GLshort> MultiTexCoord1sARB; ///< Wrapper for glMultiTexCoord1sARB
    static Function<void, glmixed::GLenum, const glmixed::GLshort *> MultiTexCoord1sv; ///< Wrapper for glMultiTexCoord1sv
    static Function<void, glmixed::GLenum, const glmixed::GLshort *> MultiTexCoord1svARB; ///< Wrapper for glMultiTexCoord1svARB
    static Function<void, glmixed::GLenum, glmixed::GLfixed> MultiTexCoord1xOES; ///< Wrapper for glMultiTexCoord1xOES
    static Function<void, glmixed::GLenum, const glmixed::GLfixed *> MultiTexCoord1xvOES; ///< Wrapper for glMultiTexCoord1xvOES
    static Function<void, glmixed::GLenum, glmixed::GLbyte, glmixed::GLbyte> MultiTexCoord2bOES; ///< Wrapper for glMultiTexCoord2bOES
    static Function<void, glmixed::GLenum, const glmixed::GLbyte *> MultiTexCoord2bvOES; ///< Wrapper for glMultiTexCoord2bvOES
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble> MultiTexCoord2d; ///< Wrapper for glMultiTexCoord2d
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble> MultiTexCoord2dARB; ///< Wrapper for glMultiTexCoord2dARB
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> MultiTexCoord2dv; ///< Wrapper for glMultiTexCoord2dv
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> MultiTexCoord2dvARB; ///< Wrapper for glMultiTexCoord2dvARB
    static Function<void, glmixed::GLenum, glmixed::GLfloat, glmixed::GLfloat> MultiTexCoord2f; ///< Wrapper for glMultiTexCoord2f
    static Function<void, glmixed::GLenum, glmixed::GLfloat, glmixed::GLfloat> MultiTexCoord2fARB; ///< Wrapper for glMultiTexCoord2fARB
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MultiTexCoord2fv; ///< Wrapper for glMultiTexCoord2fv
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MultiTexCoord2fvARB; ///< Wrapper for glMultiTexCoord2fvARB
    static Function<void, glmixed::GLenum, glmixed::GLhalfNV, glmixed::GLhalfNV> MultiTexCoord2hNV; ///< Wrapper for glMultiTexCoord2hNV
    static Function<void, glmixed::GLenum, const glmixed::GLhalfNV *> MultiTexCoord2hvNV; ///< Wrapper for glMultiTexCoord2hvNV
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint> MultiTexCoord2i; ///< Wrapper for glMultiTexCoord2i
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint> MultiTexCoord2iARB; ///< Wrapper for glMultiTexCoord2iARB
    static Function<void, glmixed::GLenum, const glmixed::GLint *> MultiTexCoord2iv; ///< Wrapper for glMultiTexCoord2iv
    static Function<void, glmixed::GLenum, const glmixed::GLint *> MultiTexCoord2ivARB; ///< Wrapper for glMultiTexCoord2ivARB
    static Function<void, glmixed::GLenum, glmixed::GLshort, glmixed::GLshort> MultiTexCoord2s; ///< Wrapper for glMultiTexCoord2s
    static Function<void, glmixed::GLenum, glmixed::GLshort, glmixed::GLshort> MultiTexCoord2sARB; ///< Wrapper for glMultiTexCoord2sARB
    static Function<void, glmixed::GLenum, const glmixed::GLshort *> MultiTexCoord2sv; ///< Wrapper for glMultiTexCoord2sv
    static Function<void, glmixed::GLenum, const glmixed::GLshort *> MultiTexCoord2svARB; ///< Wrapper for glMultiTexCoord2svARB
    static Function<void, glmixed::GLenum, glmixed::GLfixed, glmixed::GLfixed> MultiTexCoord2xOES; ///< Wrapper for glMultiTexCoord2xOES
    static Function<void, glmixed::GLenum, const glmixed::GLfixed *> MultiTexCoord2xvOES; ///< Wrapper for glMultiTexCoord2xvOES
    static Function<void, glmixed::GLenum, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte> MultiTexCoord3bOES; ///< Wrapper for glMultiTexCoord3bOES
    static Function<void, glmixed::GLenum, const glmixed::GLbyte *> MultiTexCoord3bvOES; ///< Wrapper for glMultiTexCoord3bvOES
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> MultiTexCoord3d; ///< Wrapper for glMultiTexCoord3d
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> MultiTexCoord3dARB; ///< Wrapper for glMultiTexCoord3dARB
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> MultiTexCoord3dv; ///< Wrapper for glMultiTexCoord3dv
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> MultiTexCoord3dvARB; ///< Wrapper for glMultiTexCoord3dvARB
    static Function<void, glmixed::GLenum, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> MultiTexCoord3f; ///< Wrapper for glMultiTexCoord3f
    static Function<void, glmixed::GLenum, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> MultiTexCoord3fARB; ///< Wrapper for glMultiTexCoord3fARB
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MultiTexCoord3fv; ///< Wrapper for glMultiTexCoord3fv
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MultiTexCoord3fvARB; ///< Wrapper for glMultiTexCoord3fvARB
    static Function<void, glmixed::GLenum, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV> MultiTexCoord3hNV; ///< Wrapper for glMultiTexCoord3hNV
    static Function<void, glmixed::GLenum, const glmixed::GLhalfNV *> MultiTexCoord3hvNV; ///< Wrapper for glMultiTexCoord3hvNV
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint> MultiTexCoord3i; ///< Wrapper for glMultiTexCoord3i
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint> MultiTexCoord3iARB; ///< Wrapper for glMultiTexCoord3iARB
    static Function<void, glmixed::GLenum, const glmixed::GLint *> MultiTexCoord3iv; ///< Wrapper for glMultiTexCoord3iv
    static Function<void, glmixed::GLenum, const glmixed::GLint *> MultiTexCoord3ivARB; ///< Wrapper for glMultiTexCoord3ivARB
    static Function<void, glmixed::GLenum, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> MultiTexCoord3s; ///< Wrapper for glMultiTexCoord3s
    static Function<void, glmixed::GLenum, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> MultiTexCoord3sARB; ///< Wrapper for glMultiTexCoord3sARB
    static Function<void, glmixed::GLenum, const glmixed::GLshort *> MultiTexCoord3sv; ///< Wrapper for glMultiTexCoord3sv
    static Function<void, glmixed::GLenum, const glmixed::GLshort *> MultiTexCoord3svARB; ///< Wrapper for glMultiTexCoord3svARB
    static Function<void, glmixed::GLenum, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> MultiTexCoord3xOES; ///< Wrapper for glMultiTexCoord3xOES
    static Function<void, glmixed::GLenum, const glmixed::GLfixed *> MultiTexCoord3xvOES; ///< Wrapper for glMultiTexCoord3xvOES
    static Function<void, glmixed::GLenum, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte> MultiTexCoord4bOES; ///< Wrapper for glMultiTexCoord4bOES
    static Function<void, glmixed::GLenum, const glmixed::GLbyte *> MultiTexCoord4bvOES; ///< Wrapper for glMultiTexCoord4bvOES
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> MultiTexCoord4d; ///< Wrapper for glMultiTexCoord4d
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> MultiTexCoord4dARB; ///< Wrapper for glMultiTexCoord4dARB
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> MultiTexCoord4dv; ///< Wrapper for glMultiTexCoord4dv
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> MultiTexCoord4dvARB; ///< Wrapper for glMultiTexCoord4dvARB
    static Function<void, glmixed::GLenum, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> MultiTexCoord4f; ///< Wrapper for glMultiTexCoord4f
    static Function<void, glmixed::GLenum, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> MultiTexCoord4fARB; ///< Wrapper for glMultiTexCoord4fARB
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MultiTexCoord4fv; ///< Wrapper for glMultiTexCoord4fv
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> MultiTexCoord4fvARB; ///< Wrapper for glMultiTexCoord4fvARB
    static Function<void, glmixed::GLenum, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV> MultiTexCoord4hNV; ///< Wrapper for glMultiTexCoord4hNV
    static Function<void, glmixed::GLenum, const glmixed::GLhalfNV *> MultiTexCoord4hvNV; ///< Wrapper for glMultiTexCoord4hvNV
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> MultiTexCoord4i; ///< Wrapper for glMultiTexCoord4i
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> MultiTexCoord4iARB; ///< Wrapper for glMultiTexCoord4iARB
    static Function<void, glmixed::GLenum, const glmixed::GLint *> MultiTexCoord4iv; ///< Wrapper for glMultiTexCoord4iv
    static Function<void, glmixed::GLenum, const glmixed::GLint *> MultiTexCoord4ivARB; ///< Wrapper for glMultiTexCoord4ivARB
    static Function<void, glmixed::GLenum, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> MultiTexCoord4s; ///< Wrapper for glMultiTexCoord4s
    static Function<void, glmixed::GLenum, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> MultiTexCoord4sARB; ///< Wrapper for glMultiTexCoord4sARB
    static Function<void, glmixed::GLenum, const glmixed::GLshort *> MultiTexCoord4sv; ///< Wrapper for glMultiTexCoord4sv
    static Function<void, glmixed::GLenum, const glmixed::GLshort *> MultiTexCoord4svARB; ///< Wrapper for glMultiTexCoord4svARB
    static Function<void, glmixed::GLenum, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> MultiTexCoord4xOES; ///< Wrapper for glMultiTexCoord4xOES
    static Function<void, glmixed::GLenum, const glmixed::GLfixed *> MultiTexCoord4xvOES; ///< Wrapper for glMultiTexCoord4xvOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> MultiTexCoordP1ui; ///< Wrapper for glMultiTexCoordP1ui
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLuint *> MultiTexCoordP1uiv; ///< Wrapper for glMultiTexCoordP1uiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> MultiTexCoordP2ui; ///< Wrapper for glMultiTexCoordP2ui
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLuint *> MultiTexCoordP2uiv; ///< Wrapper for glMultiTexCoordP2uiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> MultiTexCoordP3ui; ///< Wrapper for glMultiTexCoordP3ui
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLuint *> MultiTexCoordP3uiv; ///< Wrapper for glMultiTexCoordP3uiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> MultiTexCoordP4ui; ///< Wrapper for glMultiTexCoordP4ui
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLuint *> MultiTexCoordP4uiv; ///< Wrapper for glMultiTexCoordP4uiv
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, const void *> MultiTexCoordPointerEXT; ///< Wrapper for glMultiTexCoordPointerEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat> MultiTexEnvfEXT; ///< Wrapper for glMultiTexEnvfEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> MultiTexEnvfvEXT; ///< Wrapper for glMultiTexEnvfvEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> MultiTexEnviEXT; ///< Wrapper for glMultiTexEnviEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> MultiTexEnvivEXT; ///< Wrapper for glMultiTexEnvivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLdouble> MultiTexGendEXT; ///< Wrapper for glMultiTexGendEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, const glmixed::GLdouble *> MultiTexGendvEXT; ///< Wrapper for glMultiTexGendvEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat> MultiTexGenfEXT; ///< Wrapper for glMultiTexGenfEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> MultiTexGenfvEXT; ///< Wrapper for glMultiTexGenfvEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> MultiTexGeniEXT; ///< Wrapper for glMultiTexGeniEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> MultiTexGenivEXT; ///< Wrapper for glMultiTexGenivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, const void *> MultiTexImage1DEXT; ///< Wrapper for glMultiTexImage1DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, const void *> MultiTexImage2DEXT; ///< Wrapper for glMultiTexImage2DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, const void *> MultiTexImage3DEXT; ///< Wrapper for glMultiTexImage3DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat> MultiTexParameterfEXT; ///< Wrapper for glMultiTexParameterfEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> MultiTexParameterfvEXT; ///< Wrapper for glMultiTexParameterfvEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> MultiTexParameteriEXT; ///< Wrapper for glMultiTexParameteriEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> MultiTexParameterIivEXT; ///< Wrapper for glMultiTexParameterIivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, const glmixed::GLuint *> MultiTexParameterIuivEXT; ///< Wrapper for glMultiTexParameterIuivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> MultiTexParameterivEXT; ///< Wrapper for glMultiTexParameterivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> MultiTexRenderbufferEXT; ///< Wrapper for glMultiTexRenderbufferEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> MultiTexSubImage1DEXT; ///< Wrapper for glMultiTexSubImage1DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> MultiTexSubImage2DEXT; ///< Wrapper for glMultiTexSubImage2DEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> MultiTexSubImage3DEXT; ///< Wrapper for glMultiTexSubImage3DEXT
    static Function<void, const glmixed::GLdouble *> MultMatrixd; ///< Wrapper for glMultMatrixd
    static Function<void, const glmixed::GLfloat *> MultMatrixf; ///< Wrapper for glMultMatrixf
    static Function<void, const glmixed::GLfixed *> MultMatrixxOES; ///< Wrapper for glMultMatrixxOES
    static Function<void, const glmixed::GLdouble *> MultTransposeMatrixd; ///< Wrapper for glMultTransposeMatrixd
    static Function<void, const glmixed::GLdouble *> MultTransposeMatrixdARB; ///< Wrapper for glMultTransposeMatrixdARB
    static Function<void, const glmixed::GLfloat *> MultTransposeMatrixf; ///< Wrapper for glMultTransposeMatrixf
    static Function<void, const glmixed::GLfloat *> MultTransposeMatrixfARB; ///< Wrapper for glMultTransposeMatrixfARB
    static Function<void, const glmixed::GLfixed *> MultTransposeMatrixxOES; ///< Wrapper for glMultTransposeMatrixxOES
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint64> NamedBufferAttachMemoryNV; ///< Wrapper for glNamedBufferAttachMemoryNV
    static Function<void, glmixed::GLuint, glmixed::GLsizeiptr, const void *, glmixed::GLenum> NamedBufferData; ///< Wrapper for glNamedBufferData
    static Function<void, glmixed::GLuint, glmixed::GLsizeiptr, const void *, glmixed::GLenum> NamedBufferDataEXT; ///< Wrapper for glNamedBufferDataEXT
    static Function<void, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr, glmixed::GLboolean> NamedBufferPageCommitmentARB; ///< Wrapper for glNamedBufferPageCommitmentARB
    static Function<void, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr, glmixed::GLboolean> NamedBufferPageCommitmentEXT; ///< Wrapper for glNamedBufferPageCommitmentEXT
    static Function<void, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr, glmixed::GLuint, glmixed::GLuint64, glmixed::GLboolean> NamedBufferPageCommitmentMemNV; ///< Wrapper for glNamedBufferPageCommitmentMemNV
    static Function<void, glmixed::GLuint, glmixed::GLsizeiptr, const void *, glmixed::BufferStorageMask> NamedBufferStorage; ///< Wrapper for glNamedBufferStorage
    static Function<void, glmixed::GLuint, glmixed::GLsizeiptr, const void *, glmixed::BufferStorageMask> NamedBufferStorageEXT; ///< Wrapper for glNamedBufferStorageEXT
    static Function<void, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr, glmixed::GLeglClientBufferEXT, glmixed::BufferStorageMask> NamedBufferStorageExternalEXT; ///< Wrapper for glNamedBufferStorageExternalEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizeiptr, glmixed::GLuint, glmixed::GLuint64> NamedBufferStorageMemEXT; ///< Wrapper for glNamedBufferStorageMemEXT
    static Function<void, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr, const void *> NamedBufferSubData; ///< Wrapper for glNamedBufferSubData
    static Function<void, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr, const void *> NamedBufferSubDataEXT; ///< Wrapper for glNamedBufferSubDataEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLintptr, glmixed::GLintptr, glmixed::GLsizeiptr> NamedCopyBufferSubDataEXT; ///< Wrapper for glNamedCopyBufferSubDataEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum> NamedFramebufferDrawBuffer; ///< Wrapper for glNamedFramebufferDrawBuffer
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLenum *> NamedFramebufferDrawBuffers; ///< Wrapper for glNamedFramebufferDrawBuffers
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint> NamedFramebufferParameteri; ///< Wrapper for glNamedFramebufferParameteri
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint> NamedFramebufferParameteriEXT; ///< Wrapper for glNamedFramebufferParameteriEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum> NamedFramebufferReadBuffer; ///< Wrapper for glNamedFramebufferReadBuffer
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> NamedFramebufferRenderbuffer; ///< Wrapper for glNamedFramebufferRenderbuffer
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> NamedFramebufferRenderbufferEXT; ///< Wrapper for glNamedFramebufferRenderbufferEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> NamedFramebufferSampleLocationsfvARB; ///< Wrapper for glNamedFramebufferSampleLocationsfvARB
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> NamedFramebufferSampleLocationsfvNV; ///< Wrapper for glNamedFramebufferSampleLocationsfvNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, const glmixed::GLfloat *> NamedFramebufferSamplePositionsfvAMD; ///< Wrapper for glNamedFramebufferSamplePositionsfvAMD
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLint> NamedFramebufferTexture; ///< Wrapper for glNamedFramebufferTexture
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint> NamedFramebufferTexture1DEXT; ///< Wrapper for glNamedFramebufferTexture1DEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint> NamedFramebufferTexture2DEXT; ///< Wrapper for glNamedFramebufferTexture2DEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLint> NamedFramebufferTexture3DEXT; ///< Wrapper for glNamedFramebufferTexture3DEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLint> NamedFramebufferTextureEXT; ///< Wrapper for glNamedFramebufferTextureEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLenum> NamedFramebufferTextureFaceEXT; ///< Wrapper for glNamedFramebufferTextureFaceEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLint> NamedFramebufferTextureLayer; ///< Wrapper for glNamedFramebufferTextureLayer
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLint> NamedFramebufferTextureLayerEXT; ///< Wrapper for glNamedFramebufferTextureLayerEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei> NamedFramebufferTextureMultiviewOVR; ///< Wrapper for glNamedFramebufferTextureMultiviewOVR
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> NamedProgramLocalParameter4dEXT; ///< Wrapper for glNamedProgramLocalParameter4dEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, const glmixed::GLdouble *> NamedProgramLocalParameter4dvEXT; ///< Wrapper for glNamedProgramLocalParameter4dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> NamedProgramLocalParameter4fEXT; ///< Wrapper for glNamedProgramLocalParameter4fEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, const glmixed::GLfloat *> NamedProgramLocalParameter4fvEXT; ///< Wrapper for glNamedProgramLocalParameter4fvEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> NamedProgramLocalParameterI4iEXT; ///< Wrapper for glNamedProgramLocalParameterI4iEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, const glmixed::GLint *> NamedProgramLocalParameterI4ivEXT; ///< Wrapper for glNamedProgramLocalParameterI4ivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> NamedProgramLocalParameterI4uiEXT; ///< Wrapper for glNamedProgramLocalParameterI4uiEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, const glmixed::GLuint *> NamedProgramLocalParameterI4uivEXT; ///< Wrapper for glNamedProgramLocalParameterI4uivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> NamedProgramLocalParameters4fvEXT; ///< Wrapper for glNamedProgramLocalParameters4fvEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLint *> NamedProgramLocalParametersI4ivEXT; ///< Wrapper for glNamedProgramLocalParametersI4ivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *> NamedProgramLocalParametersI4uivEXT; ///< Wrapper for glNamedProgramLocalParametersI4uivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, const void *> NamedProgramStringEXT; ///< Wrapper for glNamedProgramStringEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> NamedRenderbufferStorage; ///< Wrapper for glNamedRenderbufferStorage
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> NamedRenderbufferStorageEXT; ///< Wrapper for glNamedRenderbufferStorageEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> NamedRenderbufferStorageMultisample; ///< Wrapper for glNamedRenderbufferStorageMultisample
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> NamedRenderbufferStorageMultisampleAdvancedAMD; ///< Wrapper for glNamedRenderbufferStorageMultisampleAdvancedAMD
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> NamedRenderbufferStorageMultisampleCoverageEXT; ///< Wrapper for glNamedRenderbufferStorageMultisampleCoverageEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> NamedRenderbufferStorageMultisampleEXT; ///< Wrapper for glNamedRenderbufferStorageMultisampleEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, const glmixed::GLchar *, glmixed::GLint, const glmixed::GLchar *> NamedStringARB; ///< Wrapper for glNamedStringARB
    static Function<void, glmixed::GLuint, glmixed::GLenum> NewList; ///< Wrapper for glNewList
    static Function<glmixed::GLuint, glmixed::GLsizei, const void *, glmixed::GLenum> NewObjectBufferATI; ///< Wrapper for glNewObjectBufferATI
    static Function<void, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte> Normal3b; ///< Wrapper for glNormal3b
    static Function<void, const glmixed::GLbyte *> Normal3bv; ///< Wrapper for glNormal3bv
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> Normal3d; ///< Wrapper for glNormal3d
    static Function<void, const glmixed::GLdouble *> Normal3dv; ///< Wrapper for glNormal3dv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Normal3f; ///< Wrapper for glNormal3f
    static Function<void, const glmixed::GLfloat *> Normal3fv; ///< Wrapper for glNormal3fv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Normal3fVertex3fSUN; ///< Wrapper for glNormal3fVertex3fSUN
    static Function<void, const glmixed::GLfloat *, const glmixed::GLfloat *> Normal3fVertex3fvSUN; ///< Wrapper for glNormal3fVertex3fvSUN
    static Function<void, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV> Normal3hNV; ///< Wrapper for glNormal3hNV
    static Function<void, const glmixed::GLhalfNV *> Normal3hvNV; ///< Wrapper for glNormal3hvNV
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint> Normal3i; ///< Wrapper for glNormal3i
    static Function<void, const glmixed::GLint *> Normal3iv; ///< Wrapper for glNormal3iv
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> Normal3s; ///< Wrapper for glNormal3s
    static Function<void, const glmixed::GLshort *> Normal3sv; ///< Wrapper for glNormal3sv
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> Normal3xOES; ///< Wrapper for glNormal3xOES
    static Function<void, const glmixed::GLfixed *> Normal3xvOES; ///< Wrapper for glNormal3xvOES
    static Function<void, glmixed::GLenum, glmixed::GLsizei> NormalFormatNV; ///< Wrapper for glNormalFormatNV
    static Function<void, glmixed::GLenum, glmixed::GLuint> NormalP3ui; ///< Wrapper for glNormalP3ui
    static Function<void, glmixed::GLenum, const glmixed::GLuint *> NormalP3uiv; ///< Wrapper for glNormalP3uiv
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const void *> NormalPointer; ///< Wrapper for glNormalPointer
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, const void *> NormalPointerEXT; ///< Wrapper for glNormalPointerEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, const void **, glmixed::GLint> NormalPointerListIBM; ///< Wrapper for glNormalPointerListIBM
    static Function<void, glmixed::GLenum, const void **> NormalPointervINTEL; ///< Wrapper for glNormalPointervINTEL
    static Function<void, glmixed::GLenum, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte> NormalStream3bATI; ///< Wrapper for glNormalStream3bATI
    static Function<void, glmixed::GLenum, const glmixed::GLbyte *> NormalStream3bvATI; ///< Wrapper for glNormalStream3bvATI
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> NormalStream3dATI; ///< Wrapper for glNormalStream3dATI
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> NormalStream3dvATI; ///< Wrapper for glNormalStream3dvATI
    static Function<void, glmixed::GLenum, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> NormalStream3fATI; ///< Wrapper for glNormalStream3fATI
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> NormalStream3fvATI; ///< Wrapper for glNormalStream3fvATI
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint> NormalStream3iATI; ///< Wrapper for glNormalStream3iATI
    static Function<void, glmixed::GLenum, const glmixed::GLint *> NormalStream3ivATI; ///< Wrapper for glNormalStream3ivATI
    static Function<void, glmixed::GLenum, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> NormalStream3sATI; ///< Wrapper for glNormalStream3sATI
    static Function<void, glmixed::GLenum, const glmixed::GLshort *> NormalStream3svATI; ///< Wrapper for glNormalStream3svATI
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLchar *> ObjectLabel; ///< Wrapper for glObjectLabel
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLchar *> ObjectLabelKHR; ///< Wrapper for glObjectLabelKHR
    static Function<void, const void *, glmixed::GLsizei, const glmixed::GLchar *> ObjectPtrLabel; ///< Wrapper for glObjectPtrLabel
    static Function<void, const void *, glmixed::GLsizei, const glmixed::GLchar *> ObjectPtrLabelKHR; ///< Wrapper for glObjectPtrLabelKHR
    static Function<glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum> ObjectPurgeableAPPLE; ///< Wrapper for glObjectPurgeableAPPLE
    static Function<glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum> ObjectUnpurgeableAPPLE; ///< Wrapper for glObjectUnpurgeableAPPLE
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> Ortho; ///< Wrapper for glOrtho
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> OrthofOES; ///< Wrapper for glOrthofOES
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> OrthoxOES; ///< Wrapper for glOrthoxOES
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum> PassTexCoordATI; ///< Wrapper for glPassTexCoordATI
    static Function<void, glmixed::GLfloat> PassThrough; ///< Wrapper for glPassThrough
    static Function<void, glmixed::GLfixed> PassThroughxOES; ///< Wrapper for glPassThroughxOES
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> PatchParameterfv; ///< Wrapper for glPatchParameterfv
    static Function<void, glmixed::GLenum, glmixed::GLint> PatchParameteri; ///< Wrapper for glPatchParameteri
    static Function<void, glmixed::GLenum, glmixed::GLint> PatchParameteriEXT; ///< Wrapper for glPatchParameteriEXT
    static Function<void, glmixed::GLenum, glmixed::GLint> PatchParameteriOES; ///< Wrapper for glPatchParameteriOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> PathColorGenNV; ///< Wrapper for glPathColorGenNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLubyte *, glmixed::GLsizei, glmixed::GLenum, const void *> PathCommandsNV; ///< Wrapper for glPathCommandsNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, const void *> PathCoordsNV; ///< Wrapper for glPathCoordsNV
    static Function<void, glmixed::GLenum> PathCoverDepthFuncNV; ///< Wrapper for glPathCoverDepthFuncNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> PathDashArrayNV; ///< Wrapper for glPathDashArrayNV
    static Function<void, glmixed::GLenum> PathFogGenNV; ///< Wrapper for glPathFogGenNV
    static Function<glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, const void *, glmixed::PathFontStyle, glmixed::GLuint, glmixed::GLsizei, glmixed::GLuint, glmixed::GLfloat> PathGlyphIndexArrayNV; ///< Wrapper for glPathGlyphIndexArrayNV
    static Function<glmixed::GLenum, glmixed::GLenum, const void *, glmixed::PathFontStyle, glmixed::GLuint, glmixed::GLfloat, glmixed::GLuint *> PathGlyphIndexRangeNV; ///< Wrapper for glPathGlyphIndexRangeNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, const void *, glmixed::PathFontStyle, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLuint, glmixed::GLfloat> PathGlyphRangeNV; ///< Wrapper for glPathGlyphRangeNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, const void *, glmixed::PathFontStyle, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLenum, glmixed::GLuint, glmixed::GLfloat> PathGlyphsNV; ///< Wrapper for glPathGlyphsNV
    static Function<glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizeiptr, const void *, glmixed::GLsizei, glmixed::GLuint, glmixed::GLsizei, glmixed::GLuint, glmixed::GLfloat> PathMemoryGlyphIndexArrayNV; ///< Wrapper for glPathMemoryGlyphIndexArrayNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat> PathParameterfNV; ///< Wrapper for glPathParameterfNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLfloat *> PathParameterfvNV; ///< Wrapper for glPathParameterfvNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint> PathParameteriNV; ///< Wrapper for glPathParameteriNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLint *> PathParameterivNV; ///< Wrapper for glPathParameterivNV
    static Function<void, glmixed::GLfloat, glmixed::GLfloat> PathStencilDepthOffsetNV; ///< Wrapper for glPathStencilDepthOffsetNV
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLuint> PathStencilFuncNV; ///< Wrapper for glPathStencilFuncNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, const void *> PathStringNV; ///< Wrapper for glPathStringNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, const glmixed::GLubyte *, glmixed::GLsizei, glmixed::GLenum, const void *> PathSubCommandsNV; ///< Wrapper for glPathSubCommandsNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, const void *> PathSubCoordsNV; ///< Wrapper for glPathSubCoordsNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, const glmixed::GLfloat *> PathTexGenNV; ///< Wrapper for glPathTexGenNV
    static Function<void> PauseTransformFeedback; ///< Wrapper for glPauseTransformFeedback
    static Function<void> PauseTransformFeedbackNV; ///< Wrapper for glPauseTransformFeedbackNV
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const void *> PixelDataRangeNV; ///< Wrapper for glPixelDataRangeNV
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLfloat *> PixelMapfv; ///< Wrapper for glPixelMapfv
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLuint *> PixelMapuiv; ///< Wrapper for glPixelMapuiv
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLushort *> PixelMapusv; ///< Wrapper for glPixelMapusv
    static Function<void, glmixed::GLenum, glmixed::GLint, const glmixed::GLfixed *> PixelMapx; ///< Wrapper for glPixelMapx
    static Function<void, glmixed::GLenum, glmixed::GLfloat> PixelStoref; ///< Wrapper for glPixelStoref
    static Function<void, glmixed::GLenum, glmixed::GLint> PixelStorei; ///< Wrapper for glPixelStorei
    static Function<void, glmixed::GLenum, glmixed::GLfixed> PixelStorex; ///< Wrapper for glPixelStorex
    static Function<void, glmixed::GLenum, glmixed::GLfloat> PixelTexGenParameterfSGIS; ///< Wrapper for glPixelTexGenParameterfSGIS
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> PixelTexGenParameterfvSGIS; ///< Wrapper for glPixelTexGenParameterfvSGIS
    static Function<void, glmixed::GLenum, glmixed::GLint> PixelTexGenParameteriSGIS; ///< Wrapper for glPixelTexGenParameteriSGIS
    static Function<void, glmixed::GLenum, const glmixed::GLint *> PixelTexGenParameterivSGIS; ///< Wrapper for glPixelTexGenParameterivSGIS
    static Function<void, glmixed::GLenum> PixelTexGenSGIX; ///< Wrapper for glPixelTexGenSGIX
    static Function<void, glmixed::GLenum, glmixed::GLfloat> PixelTransferf; ///< Wrapper for glPixelTransferf
    static Function<void, glmixed::GLenum, glmixed::GLint> PixelTransferi; ///< Wrapper for glPixelTransferi
    static Function<void, glmixed::GLenum, glmixed::GLfixed> PixelTransferxOES; ///< Wrapper for glPixelTransferxOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat> PixelTransformParameterfEXT; ///< Wrapper for glPixelTransformParameterfEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> PixelTransformParameterfvEXT; ///< Wrapper for glPixelTransformParameterfvEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> PixelTransformParameteriEXT; ///< Wrapper for glPixelTransformParameteriEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> PixelTransformParameterivEXT; ///< Wrapper for glPixelTransformParameterivEXT
    static Function<void, glmixed::GLfloat, glmixed::GLfloat> PixelZoom; ///< Wrapper for glPixelZoom
    static Function<void, glmixed::GLfixed, glmixed::GLfixed> PixelZoomxOES; ///< Wrapper for glPixelZoomxOES
    static Function<void, glmixed::GLenum, glmixed::GLfloat> PNTrianglesfATI; ///< Wrapper for glPNTrianglesfATI
    static Function<void, glmixed::GLenum, glmixed::GLint> PNTrianglesiATI; ///< Wrapper for glPNTrianglesiATI
    static Function<glmixed::GLboolean, glmixed::GLuint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLfloat, glmixed::GLfloat *, glmixed::GLfloat *, glmixed::GLfloat *, glmixed::GLfloat *> PointAlongPathNV; ///< Wrapper for glPointAlongPathNV
    static Function<void, glmixed::GLenum, glmixed::GLfloat> PointParameterf; ///< Wrapper for glPointParameterf
    static Function<void, glmixed::GLenum, glmixed::GLfloat> PointParameterfARB; ///< Wrapper for glPointParameterfARB
    static Function<void, glmixed::GLenum, glmixed::GLfloat> PointParameterfEXT; ///< Wrapper for glPointParameterfEXT
    static Function<void, glmixed::GLenum, glmixed::GLfloat> PointParameterfSGIS; ///< Wrapper for glPointParameterfSGIS
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> PointParameterfv; ///< Wrapper for glPointParameterfv
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> PointParameterfvARB; ///< Wrapper for glPointParameterfvARB
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> PointParameterfvEXT; ///< Wrapper for glPointParameterfvEXT
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> PointParameterfvSGIS; ///< Wrapper for glPointParameterfvSGIS
    static Function<void, glmixed::GLenum, glmixed::GLint> PointParameteri; ///< Wrapper for glPointParameteri
    static Function<void, glmixed::GLenum, glmixed::GLint> PointParameteriNV; ///< Wrapper for glPointParameteriNV
    static Function<void, glmixed::GLenum, const glmixed::GLint *> PointParameteriv; ///< Wrapper for glPointParameteriv
    static Function<void, glmixed::GLenum, const glmixed::GLint *> PointParameterivNV; ///< Wrapper for glPointParameterivNV
    static Function<void, glmixed::GLenum, glmixed::GLfixed> PointParameterxOES; ///< Wrapper for glPointParameterxOES
    static Function<void, glmixed::GLenum, const glmixed::GLfixed *> PointParameterxvOES; ///< Wrapper for glPointParameterxvOES
    static Function<void, glmixed::GLfloat> PointSize; ///< Wrapper for glPointSize
    static Function<void, glmixed::GLfixed> PointSizexOES; ///< Wrapper for glPointSizexOES
    static Function<glmixed::GLint, glmixed::GLuint *> PollAsyncSGIX; ///< Wrapper for glPollAsyncSGIX
    static Function<glmixed::GLint, glmixed::GLint *> PollInstrumentsSGIX; ///< Wrapper for glPollInstrumentsSGIX
    static Function<void, glmixed::GLenum, glmixed::GLenum> PolygonMode; ///< Wrapper for glPolygonMode
    static Function<void, glmixed::GLenum, glmixed::GLenum> PolygonModeNV; ///< Wrapper for glPolygonModeNV
    static Function<void, glmixed::GLfloat, glmixed::GLfloat> PolygonOffset; ///< Wrapper for glPolygonOffset
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> PolygonOffsetClamp; ///< Wrapper for glPolygonOffsetClamp
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> PolygonOffsetClampEXT; ///< Wrapper for glPolygonOffsetClampEXT
    static Function<void, glmixed::GLfloat, glmixed::GLfloat> PolygonOffsetEXT; ///< Wrapper for glPolygonOffsetEXT
    static Function<void, glmixed::GLfixed, glmixed::GLfixed> PolygonOffsetxOES; ///< Wrapper for glPolygonOffsetxOES
    static Function<void, const glmixed::GLubyte *> PolygonStipple; ///< Wrapper for glPolygonStipple
    static Function<void> PopAttrib; ///< Wrapper for glPopAttrib
    static Function<void> PopClientAttrib; ///< Wrapper for glPopClientAttrib
    static Function<void> PopDebugGroup; ///< Wrapper for glPopDebugGroup
    static Function<void> PopDebugGroupKHR; ///< Wrapper for glPopDebugGroupKHR
    static Function<void> PopGroupMarkerEXT; ///< Wrapper for glPopGroupMarkerEXT
    static Function<void> PopMatrix; ///< Wrapper for glPopMatrix
    static Function<void> PopName; ///< Wrapper for glPopName
    static Function<void, glmixed::GLuint, glmixed::GLuint64EXT, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint> PresentFrameDualFillNV; ///< Wrapper for glPresentFrameDualFillNV
    static Function<void, glmixed::GLuint, glmixed::GLuint64EXT, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint> PresentFrameKeyedNV; ///< Wrapper for glPresentFrameKeyedNV
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> PrimitiveBoundingBox; ///< Wrapper for glPrimitiveBoundingBox
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> PrimitiveBoundingBoxARB; ///< Wrapper for glPrimitiveBoundingBoxARB
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> PrimitiveBoundingBoxEXT; ///< Wrapper for glPrimitiveBoundingBoxEXT
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> PrimitiveBoundingBoxOES; ///< Wrapper for glPrimitiveBoundingBoxOES
    static Function<void, glmixed::GLuint> PrimitiveRestartIndex; ///< Wrapper for glPrimitiveRestartIndex
    static Function<void, glmixed::GLuint> PrimitiveRestartIndexNV; ///< Wrapper for glPrimitiveRestartIndexNV
    static Function<void> PrimitiveRestartNV; ///< Wrapper for glPrimitiveRestartNV
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *, const glmixed::GLfloat *> PrioritizeTextures; ///< Wrapper for glPrioritizeTextures
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *, const glmixed::GLclampf *> PrioritizeTexturesEXT; ///< Wrapper for glPrioritizeTexturesEXT
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *, const glmixed::GLfixed *> PrioritizeTexturesxOES; ///< Wrapper for glPrioritizeTexturesxOES
    static Function<void, glmixed::GLuint, glmixed::GLenum, const void *, glmixed::GLsizei> ProgramBinary; ///< Wrapper for glProgramBinary
    static Function<void, glmixed::GLuint, glmixed::GLenum, const void *, glmixed::GLint> ProgramBinaryOES; ///< Wrapper for glProgramBinaryOES
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> ProgramBufferParametersfvNV; ///< Wrapper for glProgramBufferParametersfvNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLint *> ProgramBufferParametersIivNV; ///< Wrapper for glProgramBufferParametersIivNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *> ProgramBufferParametersIuivNV; ///< Wrapper for glProgramBufferParametersIuivNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> ProgramEnvParameter4dARB; ///< Wrapper for glProgramEnvParameter4dARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, const glmixed::GLdouble *> ProgramEnvParameter4dvARB; ///< Wrapper for glProgramEnvParameter4dvARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ProgramEnvParameter4fARB; ///< Wrapper for glProgramEnvParameter4fARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, const glmixed::GLfloat *> ProgramEnvParameter4fvARB; ///< Wrapper for glProgramEnvParameter4fvARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> ProgramEnvParameterI4iNV; ///< Wrapper for glProgramEnvParameterI4iNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, const glmixed::GLint *> ProgramEnvParameterI4ivNV; ///< Wrapper for glProgramEnvParameterI4ivNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> ProgramEnvParameterI4uiNV; ///< Wrapper for glProgramEnvParameterI4uiNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, const glmixed::GLuint *> ProgramEnvParameterI4uivNV; ///< Wrapper for glProgramEnvParameterI4uivNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> ProgramEnvParameters4fvEXT; ///< Wrapper for glProgramEnvParameters4fvEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLint *> ProgramEnvParametersI4ivNV; ///< Wrapper for glProgramEnvParametersI4ivNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *> ProgramEnvParametersI4uivNV; ///< Wrapper for glProgramEnvParametersI4uivNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> ProgramLocalParameter4dARB; ///< Wrapper for glProgramLocalParameter4dARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, const glmixed::GLdouble *> ProgramLocalParameter4dvARB; ///< Wrapper for glProgramLocalParameter4dvARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ProgramLocalParameter4fARB; ///< Wrapper for glProgramLocalParameter4fARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, const glmixed::GLfloat *> ProgramLocalParameter4fvARB; ///< Wrapper for glProgramLocalParameter4fvARB
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> ProgramLocalParameterI4iNV; ///< Wrapper for glProgramLocalParameterI4iNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, const glmixed::GLint *> ProgramLocalParameterI4ivNV; ///< Wrapper for glProgramLocalParameterI4ivNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> ProgramLocalParameterI4uiNV; ///< Wrapper for glProgramLocalParameterI4uiNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, const glmixed::GLuint *> ProgramLocalParameterI4uivNV; ///< Wrapper for glProgramLocalParameterI4uivNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> ProgramLocalParameters4fvEXT; ///< Wrapper for glProgramLocalParameters4fvEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLint *> ProgramLocalParametersI4ivNV; ///< Wrapper for glProgramLocalParametersI4ivNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *> ProgramLocalParametersI4uivNV; ///< Wrapper for glProgramLocalParametersI4uivNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLubyte *, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> ProgramNamedParameter4dNV; ///< Wrapper for glProgramNamedParameter4dNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLubyte *, const glmixed::GLdouble *> ProgramNamedParameter4dvNV; ///< Wrapper for glProgramNamedParameter4dvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLubyte *, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ProgramNamedParameter4fNV; ///< Wrapper for glProgramNamedParameter4fNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLubyte *, const glmixed::GLfloat *> ProgramNamedParameter4fvNV; ///< Wrapper for glProgramNamedParameter4fvNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> ProgramParameter4dNV; ///< Wrapper for glProgramParameter4dNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, const glmixed::GLdouble *> ProgramParameter4dvNV; ///< Wrapper for glProgramParameter4dvNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ProgramParameter4fNV; ///< Wrapper for glProgramParameter4fNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, const glmixed::GLfloat *> ProgramParameter4fvNV; ///< Wrapper for glProgramParameter4fvNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint> ProgramParameteri; ///< Wrapper for glProgramParameteri
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint> ProgramParameteriARB; ///< Wrapper for glProgramParameteriARB
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint> ProgramParameteriEXT; ///< Wrapper for glProgramParameteriEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLdouble *> ProgramParameters4dvNV; ///< Wrapper for glProgramParameters4dvNV
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> ProgramParameters4fvNV; ///< Wrapper for glProgramParameters4fvNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLint, const glmixed::GLfloat *> ProgramPathFragmentInputGenNV; ///< Wrapper for glProgramPathFragmentInputGenNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, const void *> ProgramStringARB; ///< Wrapper for glProgramStringARB
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLuint *> ProgramSubroutineParametersuivNV; ///< Wrapper for glProgramSubroutineParametersuivNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLdouble> ProgramUniform1d; ///< Wrapper for glProgramUniform1d
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLdouble> ProgramUniform1dEXT; ///< Wrapper for glProgramUniform1dEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLdouble *> ProgramUniform1dv; ///< Wrapper for glProgramUniform1dv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLdouble *> ProgramUniform1dvEXT; ///< Wrapper for glProgramUniform1dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLfloat> ProgramUniform1f; ///< Wrapper for glProgramUniform1f
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLfloat> ProgramUniform1fEXT; ///< Wrapper for glProgramUniform1fEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLfloat *> ProgramUniform1fv; ///< Wrapper for glProgramUniform1fv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLfloat *> ProgramUniform1fvEXT; ///< Wrapper for glProgramUniform1fvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint> ProgramUniform1i; ///< Wrapper for glProgramUniform1i
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint64> ProgramUniform1i64ARB; ///< Wrapper for glProgramUniform1i64ARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint64EXT> ProgramUniform1i64NV; ///< Wrapper for glProgramUniform1i64NV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint64 *> ProgramUniform1i64vARB; ///< Wrapper for glProgramUniform1i64vARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint64EXT *> ProgramUniform1i64vNV; ///< Wrapper for glProgramUniform1i64vNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint> ProgramUniform1iEXT; ///< Wrapper for glProgramUniform1iEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint *> ProgramUniform1iv; ///< Wrapper for glProgramUniform1iv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint *> ProgramUniform1ivEXT; ///< Wrapper for glProgramUniform1ivEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint> ProgramUniform1ui; ///< Wrapper for glProgramUniform1ui
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint64> ProgramUniform1ui64ARB; ///< Wrapper for glProgramUniform1ui64ARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint64EXT> ProgramUniform1ui64NV; ///< Wrapper for glProgramUniform1ui64NV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64 *> ProgramUniform1ui64vARB; ///< Wrapper for glProgramUniform1ui64vARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64EXT *> ProgramUniform1ui64vNV; ///< Wrapper for glProgramUniform1ui64vNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint> ProgramUniform1uiEXT; ///< Wrapper for glProgramUniform1uiEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint *> ProgramUniform1uiv; ///< Wrapper for glProgramUniform1uiv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint *> ProgramUniform1uivEXT; ///< Wrapper for glProgramUniform1uivEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLdouble, glmixed::GLdouble> ProgramUniform2d; ///< Wrapper for glProgramUniform2d
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLdouble, glmixed::GLdouble> ProgramUniform2dEXT; ///< Wrapper for glProgramUniform2dEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLdouble *> ProgramUniform2dv; ///< Wrapper for glProgramUniform2dv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLdouble *> ProgramUniform2dvEXT; ///< Wrapper for glProgramUniform2dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat> ProgramUniform2f; ///< Wrapper for glProgramUniform2f
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat> ProgramUniform2fEXT; ///< Wrapper for glProgramUniform2fEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLfloat *> ProgramUniform2fv; ///< Wrapper for glProgramUniform2fv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLfloat *> ProgramUniform2fvEXT; ///< Wrapper for glProgramUniform2fvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint> ProgramUniform2i; ///< Wrapper for glProgramUniform2i
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint64, glmixed::GLint64> ProgramUniform2i64ARB; ///< Wrapper for glProgramUniform2i64ARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint64EXT, glmixed::GLint64EXT> ProgramUniform2i64NV; ///< Wrapper for glProgramUniform2i64NV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint64 *> ProgramUniform2i64vARB; ///< Wrapper for glProgramUniform2i64vARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint64EXT *> ProgramUniform2i64vNV; ///< Wrapper for glProgramUniform2i64vNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint> ProgramUniform2iEXT; ///< Wrapper for glProgramUniform2iEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint *> ProgramUniform2iv; ///< Wrapper for glProgramUniform2iv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint *> ProgramUniform2ivEXT; ///< Wrapper for glProgramUniform2ivEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint, glmixed::GLuint> ProgramUniform2ui; ///< Wrapper for glProgramUniform2ui
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint64, glmixed::GLuint64> ProgramUniform2ui64ARB; ///< Wrapper for glProgramUniform2ui64ARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint64EXT, glmixed::GLuint64EXT> ProgramUniform2ui64NV; ///< Wrapper for glProgramUniform2ui64NV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64 *> ProgramUniform2ui64vARB; ///< Wrapper for glProgramUniform2ui64vARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64EXT *> ProgramUniform2ui64vNV; ///< Wrapper for glProgramUniform2ui64vNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint, glmixed::GLuint> ProgramUniform2uiEXT; ///< Wrapper for glProgramUniform2uiEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint *> ProgramUniform2uiv; ///< Wrapper for glProgramUniform2uiv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint *> ProgramUniform2uivEXT; ///< Wrapper for glProgramUniform2uivEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> ProgramUniform3d; ///< Wrapper for glProgramUniform3d
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> ProgramUniform3dEXT; ///< Wrapper for glProgramUniform3dEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLdouble *> ProgramUniform3dv; ///< Wrapper for glProgramUniform3dv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLdouble *> ProgramUniform3dvEXT; ///< Wrapper for glProgramUniform3dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ProgramUniform3f; ///< Wrapper for glProgramUniform3f
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ProgramUniform3fEXT; ///< Wrapper for glProgramUniform3fEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLfloat *> ProgramUniform3fv; ///< Wrapper for glProgramUniform3fv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLfloat *> ProgramUniform3fvEXT; ///< Wrapper for glProgramUniform3fvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> ProgramUniform3i; ///< Wrapper for glProgramUniform3i
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint64, glmixed::GLint64, glmixed::GLint64> ProgramUniform3i64ARB; ///< Wrapper for glProgramUniform3i64ARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint64EXT, glmixed::GLint64EXT, glmixed::GLint64EXT> ProgramUniform3i64NV; ///< Wrapper for glProgramUniform3i64NV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint64 *> ProgramUniform3i64vARB; ///< Wrapper for glProgramUniform3i64vARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint64EXT *> ProgramUniform3i64vNV; ///< Wrapper for glProgramUniform3i64vNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> ProgramUniform3iEXT; ///< Wrapper for glProgramUniform3iEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint *> ProgramUniform3iv; ///< Wrapper for glProgramUniform3iv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint *> ProgramUniform3ivEXT; ///< Wrapper for glProgramUniform3ivEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> ProgramUniform3ui; ///< Wrapper for glProgramUniform3ui
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint64, glmixed::GLuint64, glmixed::GLuint64> ProgramUniform3ui64ARB; ///< Wrapper for glProgramUniform3ui64ARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint64EXT, glmixed::GLuint64EXT, glmixed::GLuint64EXT> ProgramUniform3ui64NV; ///< Wrapper for glProgramUniform3ui64NV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64 *> ProgramUniform3ui64vARB; ///< Wrapper for glProgramUniform3ui64vARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64EXT *> ProgramUniform3ui64vNV; ///< Wrapper for glProgramUniform3ui64vNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> ProgramUniform3uiEXT; ///< Wrapper for glProgramUniform3uiEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint *> ProgramUniform3uiv; ///< Wrapper for glProgramUniform3uiv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint *> ProgramUniform3uivEXT; ///< Wrapper for glProgramUniform3uivEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> ProgramUniform4d; ///< Wrapper for glProgramUniform4d
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> ProgramUniform4dEXT; ///< Wrapper for glProgramUniform4dEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLdouble *> ProgramUniform4dv; ///< Wrapper for glProgramUniform4dv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLdouble *> ProgramUniform4dvEXT; ///< Wrapper for glProgramUniform4dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ProgramUniform4f; ///< Wrapper for glProgramUniform4f
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ProgramUniform4fEXT; ///< Wrapper for glProgramUniform4fEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLfloat *> ProgramUniform4fv; ///< Wrapper for glProgramUniform4fv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLfloat *> ProgramUniform4fvEXT; ///< Wrapper for glProgramUniform4fvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> ProgramUniform4i; ///< Wrapper for glProgramUniform4i
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint64, glmixed::GLint64, glmixed::GLint64, glmixed::GLint64> ProgramUniform4i64ARB; ///< Wrapper for glProgramUniform4i64ARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint64EXT, glmixed::GLint64EXT, glmixed::GLint64EXT, glmixed::GLint64EXT> ProgramUniform4i64NV; ///< Wrapper for glProgramUniform4i64NV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint64 *> ProgramUniform4i64vARB; ///< Wrapper for glProgramUniform4i64vARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint64EXT *> ProgramUniform4i64vNV; ///< Wrapper for glProgramUniform4i64vNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> ProgramUniform4iEXT; ///< Wrapper for glProgramUniform4iEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint *> ProgramUniform4iv; ///< Wrapper for glProgramUniform4iv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint *> ProgramUniform4ivEXT; ///< Wrapper for glProgramUniform4ivEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> ProgramUniform4ui; ///< Wrapper for glProgramUniform4ui
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint64, glmixed::GLuint64, glmixed::GLuint64, glmixed::GLuint64> ProgramUniform4ui64ARB; ///< Wrapper for glProgramUniform4ui64ARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint64EXT, glmixed::GLuint64EXT, glmixed::GLuint64EXT, glmixed::GLuint64EXT> ProgramUniform4ui64NV; ///< Wrapper for glProgramUniform4ui64NV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64 *> ProgramUniform4ui64vARB; ///< Wrapper for glProgramUniform4ui64vARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64EXT *> ProgramUniform4ui64vNV; ///< Wrapper for glProgramUniform4ui64vNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> ProgramUniform4uiEXT; ///< Wrapper for glProgramUniform4uiEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint *> ProgramUniform4uiv; ///< Wrapper for glProgramUniform4uiv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint *> ProgramUniform4uivEXT; ///< Wrapper for glProgramUniform4uivEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint64> ProgramUniformHandleui64ARB; ///< Wrapper for glProgramUniformHandleui64ARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint64> ProgramUniformHandleui64IMG; ///< Wrapper for glProgramUniformHandleui64IMG
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint64> ProgramUniformHandleui64NV; ///< Wrapper for glProgramUniformHandleui64NV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64 *> ProgramUniformHandleui64vARB; ///< Wrapper for glProgramUniformHandleui64vARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64 *> ProgramUniformHandleui64vIMG; ///< Wrapper for glProgramUniformHandleui64vIMG
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64 *> ProgramUniformHandleui64vNV; ///< Wrapper for glProgramUniformHandleui64vNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix2dv; ///< Wrapper for glProgramUniformMatrix2dv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix2dvEXT; ///< Wrapper for glProgramUniformMatrix2dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix2fv; ///< Wrapper for glProgramUniformMatrix2fv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix2fvEXT; ///< Wrapper for glProgramUniformMatrix2fvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix2x3dv; ///< Wrapper for glProgramUniformMatrix2x3dv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix2x3dvEXT; ///< Wrapper for glProgramUniformMatrix2x3dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix2x3fv; ///< Wrapper for glProgramUniformMatrix2x3fv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix2x3fvEXT; ///< Wrapper for glProgramUniformMatrix2x3fvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix2x4dv; ///< Wrapper for glProgramUniformMatrix2x4dv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix2x4dvEXT; ///< Wrapper for glProgramUniformMatrix2x4dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix2x4fv; ///< Wrapper for glProgramUniformMatrix2x4fv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix2x4fvEXT; ///< Wrapper for glProgramUniformMatrix2x4fvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix3dv; ///< Wrapper for glProgramUniformMatrix3dv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix3dvEXT; ///< Wrapper for glProgramUniformMatrix3dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix3fv; ///< Wrapper for glProgramUniformMatrix3fv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix3fvEXT; ///< Wrapper for glProgramUniformMatrix3fvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix3x2dv; ///< Wrapper for glProgramUniformMatrix3x2dv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix3x2dvEXT; ///< Wrapper for glProgramUniformMatrix3x2dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix3x2fv; ///< Wrapper for glProgramUniformMatrix3x2fv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix3x2fvEXT; ///< Wrapper for glProgramUniformMatrix3x2fvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix3x4dv; ///< Wrapper for glProgramUniformMatrix3x4dv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix3x4dvEXT; ///< Wrapper for glProgramUniformMatrix3x4dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix3x4fv; ///< Wrapper for glProgramUniformMatrix3x4fv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix3x4fvEXT; ///< Wrapper for glProgramUniformMatrix3x4fvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix4dv; ///< Wrapper for glProgramUniformMatrix4dv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix4dvEXT; ///< Wrapper for glProgramUniformMatrix4dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix4fv; ///< Wrapper for glProgramUniformMatrix4fv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix4fvEXT; ///< Wrapper for glProgramUniformMatrix4fvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix4x2dv; ///< Wrapper for glProgramUniformMatrix4x2dv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix4x2dvEXT; ///< Wrapper for glProgramUniformMatrix4x2dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix4x2fv; ///< Wrapper for glProgramUniformMatrix4x2fv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix4x2fvEXT; ///< Wrapper for glProgramUniformMatrix4x2fvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix4x3dv; ///< Wrapper for glProgramUniformMatrix4x3dv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> ProgramUniformMatrix4x3dvEXT; ///< Wrapper for glProgramUniformMatrix4x3dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix4x3fv; ///< Wrapper for glProgramUniformMatrix4x3fv
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> ProgramUniformMatrix4x3fvEXT; ///< Wrapper for glProgramUniformMatrix4x3fvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint64EXT> ProgramUniformui64NV; ///< Wrapper for glProgramUniformui64NV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64EXT *> ProgramUniformui64vNV; ///< Wrapper for glProgramUniformui64vNV
    static Function<void, glmixed::GLenum, glmixed::GLint> ProgramVertexLimitNV; ///< Wrapper for glProgramVertexLimitNV
    static Function<void, glmixed::GLenum> ProvokingVertex; ///< Wrapper for glProvokingVertex
    static Function<void, glmixed::GLenum> ProvokingVertexEXT; ///< Wrapper for glProvokingVertexEXT
    static Function<void, glmixed::AttribMask> PushAttrib; ///< Wrapper for glPushAttrib
    static Function<void, glmixed::ClientAttribMask> PushClientAttrib; ///< Wrapper for glPushClientAttrib
    static Function<void, glmixed::ClientAttribMask> PushClientAttribDefaultEXT; ///< Wrapper for glPushClientAttribDefaultEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLchar *> PushDebugGroup; ///< Wrapper for glPushDebugGroup
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLchar *> PushDebugGroupKHR; ///< Wrapper for glPushDebugGroupKHR
    static Function<void, glmixed::GLsizei, const glmixed::GLchar *> PushGroupMarkerEXT; ///< Wrapper for glPushGroupMarkerEXT
    static Function<void> PushMatrix; ///< Wrapper for glPushMatrix
    static Function<void, glmixed::GLuint> PushName; ///< Wrapper for glPushName
    static Function<void, glmixed::GLuint, glmixed::GLenum> QueryCounter; ///< Wrapper for glQueryCounter
    static Function<void, glmixed::GLuint, glmixed::GLenum> QueryCounterEXT; ///< Wrapper for glQueryCounterEXT
    static Function<glmixed::GLbitfield, glmixed::GLfixed *, glmixed::GLint *> QueryMatrixxOES; ///< Wrapper for glQueryMatrixxOES
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::OcclusionQueryEventMaskAMD> QueryObjectParameteruiAMD; ///< Wrapper for glQueryObjectParameteruiAMD
    static Function<glmixed::GLint, glmixed::GLenum, glmixed::GLint, glmixed::GLuint, glmixed::GLint *> QueryResourceNV; ///< Wrapper for glQueryResourceNV
    static Function<void, glmixed::GLint, const glmixed::GLchar *> QueryResourceTagNV; ///< Wrapper for glQueryResourceTagNV
    static Function<void, glmixed::GLdouble, glmixed::GLdouble> RasterPos2d; ///< Wrapper for glRasterPos2d
    static Function<void, const glmixed::GLdouble *> RasterPos2dv; ///< Wrapper for glRasterPos2dv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat> RasterPos2f; ///< Wrapper for glRasterPos2f
    static Function<void, const glmixed::GLfloat *> RasterPos2fv; ///< Wrapper for glRasterPos2fv
    static Function<void, glmixed::GLint, glmixed::GLint> RasterPos2i; ///< Wrapper for glRasterPos2i
    static Function<void, const glmixed::GLint *> RasterPos2iv; ///< Wrapper for glRasterPos2iv
    static Function<void, glmixed::GLshort, glmixed::GLshort> RasterPos2s; ///< Wrapper for glRasterPos2s
    static Function<void, const glmixed::GLshort *> RasterPos2sv; ///< Wrapper for glRasterPos2sv
    static Function<void, glmixed::GLfixed, glmixed::GLfixed> RasterPos2xOES; ///< Wrapper for glRasterPos2xOES
    static Function<void, const glmixed::GLfixed *> RasterPos2xvOES; ///< Wrapper for glRasterPos2xvOES
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> RasterPos3d; ///< Wrapper for glRasterPos3d
    static Function<void, const glmixed::GLdouble *> RasterPos3dv; ///< Wrapper for glRasterPos3dv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> RasterPos3f; ///< Wrapper for glRasterPos3f
    static Function<void, const glmixed::GLfloat *> RasterPos3fv; ///< Wrapper for glRasterPos3fv
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint> RasterPos3i; ///< Wrapper for glRasterPos3i
    static Function<void, const glmixed::GLint *> RasterPos3iv; ///< Wrapper for glRasterPos3iv
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> RasterPos3s; ///< Wrapper for glRasterPos3s
    static Function<void, const glmixed::GLshort *> RasterPos3sv; ///< Wrapper for glRasterPos3sv
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> RasterPos3xOES; ///< Wrapper for glRasterPos3xOES
    static Function<void, const glmixed::GLfixed *> RasterPos3xvOES; ///< Wrapper for glRasterPos3xvOES
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> RasterPos4d; ///< Wrapper for glRasterPos4d
    static Function<void, const glmixed::GLdouble *> RasterPos4dv; ///< Wrapper for glRasterPos4dv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> RasterPos4f; ///< Wrapper for glRasterPos4f
    static Function<void, const glmixed::GLfloat *> RasterPos4fv; ///< Wrapper for glRasterPos4fv
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> RasterPos4i; ///< Wrapper for glRasterPos4i
    static Function<void, const glmixed::GLint *> RasterPos4iv; ///< Wrapper for glRasterPos4iv
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> RasterPos4s; ///< Wrapper for glRasterPos4s
    static Function<void, const glmixed::GLshort *> RasterPos4sv; ///< Wrapper for glRasterPos4sv
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> RasterPos4xOES; ///< Wrapper for glRasterPos4xOES
    static Function<void, const glmixed::GLfixed *> RasterPos4xvOES; ///< Wrapper for glRasterPos4xvOES
    static Function<void, glmixed::GLuint, glmixed::GLboolean> RasterSamplesEXT; ///< Wrapper for glRasterSamplesEXT
    static Function<void, glmixed::GLenum> ReadBuffer; ///< Wrapper for glReadBuffer
    static Function<void, glmixed::GLenum, glmixed::GLint> ReadBufferIndexedEXT; ///< Wrapper for glReadBufferIndexedEXT
    static Function<void, glmixed::GLenum> ReadBufferNV; ///< Wrapper for glReadBufferNV
    static Function<void, glmixed::GLint> ReadInstrumentsSGIX; ///< Wrapper for glReadInstrumentsSGIX
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *> ReadnPixels; ///< Wrapper for glReadnPixels
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *> ReadnPixelsARB; ///< Wrapper for glReadnPixelsARB
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *> ReadnPixelsEXT; ///< Wrapper for glReadnPixelsEXT
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, void *> ReadnPixelsKHR; ///< Wrapper for glReadnPixelsKHR
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, void *> ReadPixels; ///< Wrapper for glReadPixels
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> Rectd; ///< Wrapper for glRectd
    static Function<void, const glmixed::GLdouble *, const glmixed::GLdouble *> Rectdv; ///< Wrapper for glRectdv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Rectf; ///< Wrapper for glRectf
    static Function<void, const glmixed::GLfloat *, const glmixed::GLfloat *> Rectfv; ///< Wrapper for glRectfv
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> Recti; ///< Wrapper for glRecti
    static Function<void, const glmixed::GLint *, const glmixed::GLint *> Rectiv; ///< Wrapper for glRectiv
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> Rects; ///< Wrapper for glRects
    static Function<void, const glmixed::GLshort *, const glmixed::GLshort *> Rectsv; ///< Wrapper for glRectsv
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> RectxOES; ///< Wrapper for glRectxOES
    static Function<void, const glmixed::GLfixed *, const glmixed::GLfixed *> RectxvOES; ///< Wrapper for glRectxvOES
    static Function<void, const glmixed::GLdouble *> ReferencePlaneSGIX; ///< Wrapper for glReferencePlaneSGIX
    static Function<glmixed::GLboolean, glmixed::GLuint, glmixed::GLuint64> ReleaseKeyedMutexWin32EXT; ///< Wrapper for glReleaseKeyedMutexWin32EXT
    static Function<void> ReleaseShaderCompiler; ///< Wrapper for glReleaseShaderCompiler
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> RenderbufferStorage; ///< Wrapper for glRenderbufferStorage
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> RenderbufferStorageEXT; ///< Wrapper for glRenderbufferStorageEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> RenderbufferStorageMultisample; ///< Wrapper for glRenderbufferStorageMultisample
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> RenderbufferStorageMultisampleAdvancedAMD; ///< Wrapper for glRenderbufferStorageMultisampleAdvancedAMD
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> RenderbufferStorageMultisampleANGLE; ///< Wrapper for glRenderbufferStorageMultisampleANGLE
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> RenderbufferStorageMultisampleAPPLE; ///< Wrapper for glRenderbufferStorageMultisampleAPPLE
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> RenderbufferStorageMultisampleCoverageNV; ///< Wrapper for glRenderbufferStorageMultisampleCoverageNV
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> RenderbufferStorageMultisampleEXT; ///< Wrapper for glRenderbufferStorageMultisampleEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> RenderbufferStorageMultisampleIMG; ///< Wrapper for glRenderbufferStorageMultisampleIMG
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> RenderbufferStorageMultisampleNV; ///< Wrapper for glRenderbufferStorageMultisampleNV
    static Function<void, glmixed::GLbitfield> RenderGpuMaskNV; ///< Wrapper for glRenderGpuMaskNV
    static Function<glmixed::GLint, glmixed::GLenum> RenderMode; ///< Wrapper for glRenderMode
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const void **> ReplacementCodePointerSUN; ///< Wrapper for glReplacementCodePointerSUN
    static Function<void, glmixed::GLubyte> ReplacementCodeubSUN; ///< Wrapper for glReplacementCodeubSUN
    static Function<void, const glmixed::GLubyte *> ReplacementCodeubvSUN; ///< Wrapper for glReplacementCodeubvSUN
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ReplacementCodeuiColor3fVertex3fSUN; ///< Wrapper for glReplacementCodeuiColor3fVertex3fSUN
    static Function<void, const glmixed::GLuint *, const glmixed::GLfloat *, const glmixed::GLfloat *> ReplacementCodeuiColor3fVertex3fvSUN; ///< Wrapper for glReplacementCodeuiColor3fVertex3fvSUN
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ReplacementCodeuiColor4fNormal3fVertex3fSUN; ///< Wrapper for glReplacementCodeuiColor4fNormal3fVertex3fSUN
    static Function<void, const glmixed::GLuint *, const glmixed::GLfloat *, const glmixed::GLfloat *, const glmixed::GLfloat *> ReplacementCodeuiColor4fNormal3fVertex3fvSUN; ///< Wrapper for glReplacementCodeuiColor4fNormal3fVertex3fvSUN
    static Function<void, glmixed::GLuint, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ReplacementCodeuiColor4ubVertex3fSUN; ///< Wrapper for glReplacementCodeuiColor4ubVertex3fSUN
    static Function<void, const glmixed::GLuint *, const glmixed::GLubyte *, const glmixed::GLfloat *> ReplacementCodeuiColor4ubVertex3fvSUN; ///< Wrapper for glReplacementCodeuiColor4ubVertex3fvSUN
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ReplacementCodeuiNormal3fVertex3fSUN; ///< Wrapper for glReplacementCodeuiNormal3fVertex3fSUN
    static Function<void, const glmixed::GLuint *, const glmixed::GLfloat *, const glmixed::GLfloat *> ReplacementCodeuiNormal3fVertex3fvSUN; ///< Wrapper for glReplacementCodeuiNormal3fVertex3fvSUN
    static Function<void, glmixed::GLuint> ReplacementCodeuiSUN; ///< Wrapper for glReplacementCodeuiSUN
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN; ///< Wrapper for glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN
    static Function<void, const glmixed::GLuint *, const glmixed::GLfloat *, const glmixed::GLfloat *, const glmixed::GLfloat *, const glmixed::GLfloat *> ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN; ///< Wrapper for glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ReplacementCodeuiTexCoord2fNormal3fVertex3fSUN; ///< Wrapper for glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN
    static Function<void, const glmixed::GLuint *, const glmixed::GLfloat *, const glmixed::GLfloat *, const glmixed::GLfloat *> ReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN; ///< Wrapper for glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ReplacementCodeuiTexCoord2fVertex3fSUN; ///< Wrapper for glReplacementCodeuiTexCoord2fVertex3fSUN
    static Function<void, const glmixed::GLuint *, const glmixed::GLfloat *, const glmixed::GLfloat *> ReplacementCodeuiTexCoord2fVertex3fvSUN; ///< Wrapper for glReplacementCodeuiTexCoord2fVertex3fvSUN
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ReplacementCodeuiVertex3fSUN; ///< Wrapper for glReplacementCodeuiVertex3fSUN
    static Function<void, const glmixed::GLuint *, const glmixed::GLfloat *> ReplacementCodeuiVertex3fvSUN; ///< Wrapper for glReplacementCodeuiVertex3fvSUN
    static Function<void, const glmixed::GLuint *> ReplacementCodeuivSUN; ///< Wrapper for glReplacementCodeuivSUN
    static Function<void, glmixed::GLushort> ReplacementCodeusSUN; ///< Wrapper for glReplacementCodeusSUN
    static Function<void, const glmixed::GLushort *> ReplacementCodeusvSUN; ///< Wrapper for glReplacementCodeusvSUN
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *> RequestResidentProgramsNV; ///< Wrapper for glRequestResidentProgramsNV
    static Function<void, glmixed::GLenum> ResetHistogram; ///< Wrapper for glResetHistogram
    static Function<void, glmixed::GLenum> ResetHistogramEXT; ///< Wrapper for glResetHistogramEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum> ResetMemoryObjectParameterNV; ///< Wrapper for glResetMemoryObjectParameterNV
    static Function<void, glmixed::GLenum> ResetMinmax; ///< Wrapper for glResetMinmax
    static Function<void, glmixed::GLenum> ResetMinmaxEXT; ///< Wrapper for glResetMinmaxEXT
    static Function<void> ResizeBuffersMESA; ///< Wrapper for glResizeBuffersMESA
    static Function<void> ResolveDepthValuesNV; ///< Wrapper for glResolveDepthValuesNV
    static Function<void> ResolveMultisampleFramebufferAPPLE; ///< Wrapper for glResolveMultisampleFramebufferAPPLE
    static Function<void> ResumeTransformFeedback; ///< Wrapper for glResumeTransformFeedback
    static Function<void> ResumeTransformFeedbackNV; ///< Wrapper for glResumeTransformFeedbackNV
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> Rotated; ///< Wrapper for glRotated
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Rotatef; ///< Wrapper for glRotatef
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> RotatexOES; ///< Wrapper for glRotatexOES
    static Function<void, glmixed::GLfloat, glmixed::GLboolean> SampleCoverage; ///< Wrapper for glSampleCoverage
    static Function<void, glmixed::GLfloat, glmixed::GLboolean> SampleCoverageARB; ///< Wrapper for glSampleCoverageARB
    static Function<void, glmixed::GLclampx, glmixed::GLboolean> SampleCoveragexOES; ///< Wrapper for glSampleCoveragexOES
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum> SampleMapATI; ///< Wrapper for glSampleMapATI
    static Function<void, glmixed::GLclampf, glmixed::GLboolean> SampleMaskEXT; ///< Wrapper for glSampleMaskEXT
    static Function<void, glmixed::GLuint, glmixed::GLbitfield> SampleMaski; ///< Wrapper for glSampleMaski
    static Function<void, glmixed::GLuint, glmixed::GLbitfield> SampleMaskIndexedNV; ///< Wrapper for glSampleMaskIndexedNV
    static Function<void, glmixed::GLclampf, glmixed::GLboolean> SampleMaskSGIS; ///< Wrapper for glSampleMaskSGIS
    static Function<void, glmixed::GLenum> SamplePatternEXT; ///< Wrapper for glSamplePatternEXT
    static Function<void, glmixed::GLenum> SamplePatternSGIS; ///< Wrapper for glSamplePatternSGIS
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat> SamplerParameterf; ///< Wrapper for glSamplerParameterf
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLfloat *> SamplerParameterfv; ///< Wrapper for glSamplerParameterfv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint> SamplerParameteri; ///< Wrapper for glSamplerParameteri
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLint *> SamplerParameterIiv; ///< Wrapper for glSamplerParameterIiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLint *> SamplerParameterIivEXT; ///< Wrapper for glSamplerParameterIivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLint *> SamplerParameterIivOES; ///< Wrapper for glSamplerParameterIivOES
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLuint *> SamplerParameterIuiv; ///< Wrapper for glSamplerParameterIuiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLuint *> SamplerParameterIuivEXT; ///< Wrapper for glSamplerParameterIuivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLuint *> SamplerParameterIuivOES; ///< Wrapper for glSamplerParameterIuivOES
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLint *> SamplerParameteriv; ///< Wrapper for glSamplerParameteriv
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> Scaled; ///< Wrapper for glScaled
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Scalef; ///< Wrapper for glScalef
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> ScalexOES; ///< Wrapper for glScalexOES
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> Scissor; ///< Wrapper for glScissor
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLint *> ScissorArrayv; ///< Wrapper for glScissorArrayv
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLint *> ScissorArrayvNV; ///< Wrapper for glScissorArrayvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLint *> ScissorArrayvOES; ///< Wrapper for glScissorArrayvOES
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLint *> ScissorExclusiveArrayvNV; ///< Wrapper for glScissorExclusiveArrayvNV
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> ScissorExclusiveNV; ///< Wrapper for glScissorExclusiveNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> ScissorIndexed; ///< Wrapper for glScissorIndexed
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> ScissorIndexedNV; ///< Wrapper for glScissorIndexedNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> ScissorIndexedOES; ///< Wrapper for glScissorIndexedOES
    static Function<void, glmixed::GLuint, const glmixed::GLint *> ScissorIndexedv; ///< Wrapper for glScissorIndexedv
    static Function<void, glmixed::GLuint, const glmixed::GLint *> ScissorIndexedvNV; ///< Wrapper for glScissorIndexedvNV
    static Function<void, glmixed::GLuint, const glmixed::GLint *> ScissorIndexedvOES; ///< Wrapper for glScissorIndexedvOES
    static Function<void, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte> SecondaryColor3b; ///< Wrapper for glSecondaryColor3b
    static Function<void, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte> SecondaryColor3bEXT; ///< Wrapper for glSecondaryColor3bEXT
    static Function<void, const glmixed::GLbyte *> SecondaryColor3bv; ///< Wrapper for glSecondaryColor3bv
    static Function<void, const glmixed::GLbyte *> SecondaryColor3bvEXT; ///< Wrapper for glSecondaryColor3bvEXT
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> SecondaryColor3d; ///< Wrapper for glSecondaryColor3d
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> SecondaryColor3dEXT; ///< Wrapper for glSecondaryColor3dEXT
    static Function<void, const glmixed::GLdouble *> SecondaryColor3dv; ///< Wrapper for glSecondaryColor3dv
    static Function<void, const glmixed::GLdouble *> SecondaryColor3dvEXT; ///< Wrapper for glSecondaryColor3dvEXT
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> SecondaryColor3f; ///< Wrapper for glSecondaryColor3f
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> SecondaryColor3fEXT; ///< Wrapper for glSecondaryColor3fEXT
    static Function<void, const glmixed::GLfloat *> SecondaryColor3fv; ///< Wrapper for glSecondaryColor3fv
    static Function<void, const glmixed::GLfloat *> SecondaryColor3fvEXT; ///< Wrapper for glSecondaryColor3fvEXT
    static Function<void, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV> SecondaryColor3hNV; ///< Wrapper for glSecondaryColor3hNV
    static Function<void, const glmixed::GLhalfNV *> SecondaryColor3hvNV; ///< Wrapper for glSecondaryColor3hvNV
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint> SecondaryColor3i; ///< Wrapper for glSecondaryColor3i
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint> SecondaryColor3iEXT; ///< Wrapper for glSecondaryColor3iEXT
    static Function<void, const glmixed::GLint *> SecondaryColor3iv; ///< Wrapper for glSecondaryColor3iv
    static Function<void, const glmixed::GLint *> SecondaryColor3ivEXT; ///< Wrapper for glSecondaryColor3ivEXT
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> SecondaryColor3s; ///< Wrapper for glSecondaryColor3s
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> SecondaryColor3sEXT; ///< Wrapper for glSecondaryColor3sEXT
    static Function<void, const glmixed::GLshort *> SecondaryColor3sv; ///< Wrapper for glSecondaryColor3sv
    static Function<void, const glmixed::GLshort *> SecondaryColor3svEXT; ///< Wrapper for glSecondaryColor3svEXT
    static Function<void, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte> SecondaryColor3ub; ///< Wrapper for glSecondaryColor3ub
    static Function<void, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte> SecondaryColor3ubEXT; ///< Wrapper for glSecondaryColor3ubEXT
    static Function<void, const glmixed::GLubyte *> SecondaryColor3ubv; ///< Wrapper for glSecondaryColor3ubv
    static Function<void, const glmixed::GLubyte *> SecondaryColor3ubvEXT; ///< Wrapper for glSecondaryColor3ubvEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> SecondaryColor3ui; ///< Wrapper for glSecondaryColor3ui
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> SecondaryColor3uiEXT; ///< Wrapper for glSecondaryColor3uiEXT
    static Function<void, const glmixed::GLuint *> SecondaryColor3uiv; ///< Wrapper for glSecondaryColor3uiv
    static Function<void, const glmixed::GLuint *> SecondaryColor3uivEXT; ///< Wrapper for glSecondaryColor3uivEXT
    static Function<void, glmixed::GLushort, glmixed::GLushort, glmixed::GLushort> SecondaryColor3us; ///< Wrapper for glSecondaryColor3us
    static Function<void, glmixed::GLushort, glmixed::GLushort, glmixed::GLushort> SecondaryColor3usEXT; ///< Wrapper for glSecondaryColor3usEXT
    static Function<void, const glmixed::GLushort *> SecondaryColor3usv; ///< Wrapper for glSecondaryColor3usv
    static Function<void, const glmixed::GLushort *> SecondaryColor3usvEXT; ///< Wrapper for glSecondaryColor3usvEXT
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei> SecondaryColorFormatNV; ///< Wrapper for glSecondaryColorFormatNV
    static Function<void, glmixed::GLenum, glmixed::GLuint> SecondaryColorP3ui; ///< Wrapper for glSecondaryColorP3ui
    static Function<void, glmixed::GLenum, const glmixed::GLuint *> SecondaryColorP3uiv; ///< Wrapper for glSecondaryColorP3uiv
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, const void *> SecondaryColorPointer; ///< Wrapper for glSecondaryColorPointer
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, const void *> SecondaryColorPointerEXT; ///< Wrapper for glSecondaryColorPointerEXT
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLint, const void **, glmixed::GLint> SecondaryColorPointerListIBM; ///< Wrapper for glSecondaryColorPointerListIBM
    static Function<void, glmixed::GLsizei, glmixed::GLuint *> SelectBuffer; ///< Wrapper for glSelectBuffer
    static Function<void, glmixed::GLuint, glmixed::GLboolean, glmixed::GLuint, glmixed::GLint, glmixed::GLuint *> SelectPerfMonitorCountersAMD; ///< Wrapper for glSelectPerfMonitorCountersAMD
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLint *> SemaphoreParameterivNV; ///< Wrapper for glSemaphoreParameterivNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLuint64 *> SemaphoreParameterui64vEXT; ///< Wrapper for glSemaphoreParameterui64vEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *, const void *> SeparableFilter2D; ///< Wrapper for glSeparableFilter2D
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *, const void *> SeparableFilter2DEXT; ///< Wrapper for glSeparableFilter2DEXT
    static Function<void, glmixed::GLuint> SetFenceAPPLE; ///< Wrapper for glSetFenceAPPLE
    static Function<void, glmixed::GLuint, glmixed::GLenum> SetFenceNV; ///< Wrapper for glSetFenceNV
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> SetFragmentShaderConstantATI; ///< Wrapper for glSetFragmentShaderConstantATI
    static Function<void, glmixed::GLuint, glmixed::GLenum, const void *> SetInvariantEXT; ///< Wrapper for glSetInvariantEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, const void *> SetLocalConstantEXT; ///< Wrapper for glSetLocalConstantEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, const glmixed::GLfloat *> SetMultisamplefvAMD; ///< Wrapper for glSetMultisamplefvAMD
    static Function<void, glmixed::GLenum> ShadeModel; ///< Wrapper for glShadeModel
    static Function<void, glmixed::GLsizei, const glmixed::GLuint *, glmixed::GLenum, const void *, glmixed::GLsizei> ShaderBinary; ///< Wrapper for glShaderBinary
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint> ShaderOp1EXT; ///< Wrapper for glShaderOp1EXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> ShaderOp2EXT; ///< Wrapper for glShaderOp2EXT
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> ShaderOp3EXT; ///< Wrapper for glShaderOp3EXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLchar *const*, const glmixed::GLint *> ShaderSource; ///< Wrapper for glShaderSource
    static Function<void, glmixed::GLhandleARB, glmixed::GLsizei, const glmixed::GLcharARB **, const glmixed::GLint *> ShaderSourceARB; ///< Wrapper for glShaderSourceARB
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> ShaderStorageBlockBinding; ///< Wrapper for glShaderStorageBlockBinding
    static Function<void, glmixed::GLenum, glmixed::GLenum> ShadingRateCombinerOpsEXT; ///< Wrapper for glShadingRateCombinerOpsEXT
    static Function<void, glmixed::GLenum> ShadingRateEXT; ///< Wrapper for glShadingRateEXT
    static Function<void, glmixed::GLboolean> ShadingRateImageBarrierNV; ///< Wrapper for glShadingRateImageBarrierNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLenum *> ShadingRateImagePaletteNV; ///< Wrapper for glShadingRateImagePaletteNV
    static Function<void, glmixed::GLenum> ShadingRateQCOM; ///< Wrapper for glShadingRateQCOM
    static Function<void, glmixed::GLenum, glmixed::GLuint, const glmixed::GLint *> ShadingRateSampleOrderCustomNV; ///< Wrapper for glShadingRateSampleOrderCustomNV
    static Function<void, glmixed::GLenum> ShadingRateSampleOrderNV; ///< Wrapper for glShadingRateSampleOrderNV
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLfloat *> SharpenTexFuncSGIS; ///< Wrapper for glSharpenTexFuncSGIS
    static Function<void, glmixed::GLuint, glmixed::GLuint, const glmixed::GLuint *, glmixed::GLuint, const glmixed::GLuint *, const glmixed::GLenum *> SignalSemaphoreEXT; ///< Wrapper for glSignalSemaphoreEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *, const glmixed::GLuint64 *> SignalSemaphoreui64NVX; ///< Wrapper for glSignalSemaphoreui64NVX
    static Function<void, glmixed::GLuint64> SignalVkFenceNV; ///< Wrapper for glSignalVkFenceNV
    static Function<void, glmixed::GLuint64> SignalVkSemaphoreNV; ///< Wrapper for glSignalVkSemaphoreNV
    static Function<void, glmixed::GLuint, const glmixed::GLchar *, glmixed::GLuint, const glmixed::GLuint *, const glmixed::GLuint *> SpecializeShader; ///< Wrapper for glSpecializeShader
    static Function<void, glmixed::GLuint, const glmixed::GLchar *, glmixed::GLuint, const glmixed::GLuint *, const glmixed::GLuint *> SpecializeShaderARB; ///< Wrapper for glSpecializeShaderARB
    static Function<void, glmixed::GLenum, glmixed::GLfloat> SpriteParameterfSGIX; ///< Wrapper for glSpriteParameterfSGIX
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> SpriteParameterfvSGIX; ///< Wrapper for glSpriteParameterfvSGIX
    static Function<void, glmixed::GLenum, glmixed::GLint> SpriteParameteriSGIX; ///< Wrapper for glSpriteParameteriSGIX
    static Function<void, glmixed::GLenum, const glmixed::GLint *> SpriteParameterivSGIX; ///< Wrapper for glSpriteParameterivSGIX
    static Function<void> StartInstrumentsSGIX; ///< Wrapper for glStartInstrumentsSGIX
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLbitfield> StartTilingQCOM; ///< Wrapper for glStartTilingQCOM
    static Function<void, glmixed::GLuint, glmixed::GLenum> StateCaptureNV; ///< Wrapper for glStateCaptureNV
    static Function<void, glmixed::GLsizei, glmixed::GLuint> StencilClearTagEXT; ///< Wrapper for glStencilClearTagEXT
    static Function<void, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, const glmixed::GLfloat *> StencilFillPathInstancedNV; ///< Wrapper for glStencilFillPathInstancedNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint> StencilFillPathNV; ///< Wrapper for glStencilFillPathNV
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLuint> StencilFunc; ///< Wrapper for glStencilFunc
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLuint> StencilFuncSeparate; ///< Wrapper for glStencilFuncSeparate
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint, glmixed::GLuint> StencilFuncSeparateATI; ///< Wrapper for glStencilFuncSeparateATI
    static Function<void, glmixed::GLuint> StencilMask; ///< Wrapper for glStencilMask
    static Function<void, glmixed::GLenum, glmixed::GLuint> StencilMaskSeparate; ///< Wrapper for glStencilMaskSeparate
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum> StencilOp; ///< Wrapper for glStencilOp
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum> StencilOpSeparate; ///< Wrapper for glStencilOpSeparate
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum> StencilOpSeparateATI; ///< Wrapper for glStencilOpSeparateATI
    static Function<void, glmixed::GLenum, glmixed::GLuint> StencilOpValueAMD; ///< Wrapper for glStencilOpValueAMD
    static Function<void, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLuint, glmixed::GLint, glmixed::GLuint, glmixed::GLenum, const glmixed::GLfloat *> StencilStrokePathInstancedNV; ///< Wrapper for glStencilStrokePathInstancedNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint> StencilStrokePathNV; ///< Wrapper for glStencilStrokePathNV
    static Function<void, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> StencilThenCoverFillPathInstancedNV; ///< Wrapper for glStencilThenCoverFillPathInstancedNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum> StencilThenCoverFillPathNV; ///< Wrapper for glStencilThenCoverFillPathNV
    static Function<void, glmixed::GLsizei, glmixed::GLenum, const void *, glmixed::GLuint, glmixed::GLint, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> StencilThenCoverStrokePathInstancedNV; ///< Wrapper for glStencilThenCoverStrokePathInstancedNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint, glmixed::GLenum> StencilThenCoverStrokePathNV; ///< Wrapper for glStencilThenCoverStrokePathNV
    static Function<void, glmixed::GLint> StopInstrumentsSGIX; ///< Wrapper for glStopInstrumentsSGIX
    static Function<void, glmixed::GLsizei, const void *> StringMarkerGREMEDY; ///< Wrapper for glStringMarkerGREMEDY
    static Function<void, glmixed::GLuint, glmixed::GLuint> SubpixelPrecisionBiasNV; ///< Wrapper for glSubpixelPrecisionBiasNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum> SwizzleEXT; ///< Wrapper for glSwizzleEXT
    static Function<void, glmixed::GLuint> SyncTextureINTEL; ///< Wrapper for glSyncTextureINTEL
    static Function<void> TagSampleBufferSGIX; ///< Wrapper for glTagSampleBufferSGIX
    static Function<void, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte> Tangent3bEXT; ///< Wrapper for glTangent3bEXT
    static Function<void, const glmixed::GLbyte *> Tangent3bvEXT; ///< Wrapper for glTangent3bvEXT
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> Tangent3dEXT; ///< Wrapper for glTangent3dEXT
    static Function<void, const glmixed::GLdouble *> Tangent3dvEXT; ///< Wrapper for glTangent3dvEXT
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Tangent3fEXT; ///< Wrapper for glTangent3fEXT
    static Function<void, const glmixed::GLfloat *> Tangent3fvEXT; ///< Wrapper for glTangent3fvEXT
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint> Tangent3iEXT; ///< Wrapper for glTangent3iEXT
    static Function<void, const glmixed::GLint *> Tangent3ivEXT; ///< Wrapper for glTangent3ivEXT
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> Tangent3sEXT; ///< Wrapper for glTangent3sEXT
    static Function<void, const glmixed::GLshort *> Tangent3svEXT; ///< Wrapper for glTangent3svEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const void *> TangentPointerEXT; ///< Wrapper for glTangentPointerEXT
    static Function<void, glmixed::GLuint> TbufferMask3DFX; ///< Wrapper for glTbufferMask3DFX
    static Function<void, glmixed::GLfloat> TessellationFactorAMD; ///< Wrapper for glTessellationFactorAMD
    static Function<void, glmixed::GLenum> TessellationModeAMD; ///< Wrapper for glTessellationModeAMD
    static Function<glmixed::GLboolean, glmixed::GLuint> TestFenceAPPLE; ///< Wrapper for glTestFenceAPPLE
    static Function<glmixed::GLboolean, glmixed::GLuint> TestFenceNV; ///< Wrapper for glTestFenceNV
    static Function<glmixed::GLboolean, glmixed::GLenum, glmixed::GLuint> TestObjectAPPLE; ///< Wrapper for glTestObjectAPPLE
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint64> TexAttachMemoryNV; ///< Wrapper for glTexAttachMemoryNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> TexBuffer; ///< Wrapper for glTexBuffer
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> TexBufferARB; ///< Wrapper for glTexBufferARB
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> TexBufferEXT; ///< Wrapper for glTexBufferEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> TexBufferOES; ///< Wrapper for glTexBufferOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr> TexBufferRange; ///< Wrapper for glTexBufferRange
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr> TexBufferRangeEXT; ///< Wrapper for glTexBufferRangeEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr> TexBufferRangeOES; ///< Wrapper for glTexBufferRangeOES
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> TexBumpParameterfvATI; ///< Wrapper for glTexBumpParameterfvATI
    static Function<void, glmixed::GLenum, const glmixed::GLint *> TexBumpParameterivATI; ///< Wrapper for glTexBumpParameterivATI
    static Function<void, glmixed::GLbyte> TexCoord1bOES; ///< Wrapper for glTexCoord1bOES
    static Function<void, const glmixed::GLbyte *> TexCoord1bvOES; ///< Wrapper for glTexCoord1bvOES
    static Function<void, glmixed::GLdouble> TexCoord1d; ///< Wrapper for glTexCoord1d
    static Function<void, const glmixed::GLdouble *> TexCoord1dv; ///< Wrapper for glTexCoord1dv
    static Function<void, glmixed::GLfloat> TexCoord1f; ///< Wrapper for glTexCoord1f
    static Function<void, const glmixed::GLfloat *> TexCoord1fv; ///< Wrapper for glTexCoord1fv
    static Function<void, glmixed::GLhalfNV> TexCoord1hNV; ///< Wrapper for glTexCoord1hNV
    static Function<void, const glmixed::GLhalfNV *> TexCoord1hvNV; ///< Wrapper for glTexCoord1hvNV
    static Function<void, glmixed::GLint> TexCoord1i; ///< Wrapper for glTexCoord1i
    static Function<void, const glmixed::GLint *> TexCoord1iv; ///< Wrapper for glTexCoord1iv
    static Function<void, glmixed::GLshort> TexCoord1s; ///< Wrapper for glTexCoord1s
    static Function<void, const glmixed::GLshort *> TexCoord1sv; ///< Wrapper for glTexCoord1sv
    static Function<void, glmixed::GLfixed> TexCoord1xOES; ///< Wrapper for glTexCoord1xOES
    static Function<void, const glmixed::GLfixed *> TexCoord1xvOES; ///< Wrapper for glTexCoord1xvOES
    static Function<void, glmixed::GLbyte, glmixed::GLbyte> TexCoord2bOES; ///< Wrapper for glTexCoord2bOES
    static Function<void, const glmixed::GLbyte *> TexCoord2bvOES; ///< Wrapper for glTexCoord2bvOES
    static Function<void, glmixed::GLdouble, glmixed::GLdouble> TexCoord2d; ///< Wrapper for glTexCoord2d
    static Function<void, const glmixed::GLdouble *> TexCoord2dv; ///< Wrapper for glTexCoord2dv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat> TexCoord2f; ///< Wrapper for glTexCoord2f
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> TexCoord2fColor3fVertex3fSUN; ///< Wrapper for glTexCoord2fColor3fVertex3fSUN
    static Function<void, const glmixed::GLfloat *, const glmixed::GLfloat *, const glmixed::GLfloat *> TexCoord2fColor3fVertex3fvSUN; ///< Wrapper for glTexCoord2fColor3fVertex3fvSUN
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> TexCoord2fColor4fNormal3fVertex3fSUN; ///< Wrapper for glTexCoord2fColor4fNormal3fVertex3fSUN
    static Function<void, const glmixed::GLfloat *, const glmixed::GLfloat *, const glmixed::GLfloat *, const glmixed::GLfloat *> TexCoord2fColor4fNormal3fVertex3fvSUN; ///< Wrapper for glTexCoord2fColor4fNormal3fVertex3fvSUN
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> TexCoord2fColor4ubVertex3fSUN; ///< Wrapper for glTexCoord2fColor4ubVertex3fSUN
    static Function<void, const glmixed::GLfloat *, const glmixed::GLubyte *, const glmixed::GLfloat *> TexCoord2fColor4ubVertex3fvSUN; ///< Wrapper for glTexCoord2fColor4ubVertex3fvSUN
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> TexCoord2fNormal3fVertex3fSUN; ///< Wrapper for glTexCoord2fNormal3fVertex3fSUN
    static Function<void, const glmixed::GLfloat *, const glmixed::GLfloat *, const glmixed::GLfloat *> TexCoord2fNormal3fVertex3fvSUN; ///< Wrapper for glTexCoord2fNormal3fVertex3fvSUN
    static Function<void, const glmixed::GLfloat *> TexCoord2fv; ///< Wrapper for glTexCoord2fv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> TexCoord2fVertex3fSUN; ///< Wrapper for glTexCoord2fVertex3fSUN
    static Function<void, const glmixed::GLfloat *, const glmixed::GLfloat *> TexCoord2fVertex3fvSUN; ///< Wrapper for glTexCoord2fVertex3fvSUN
    static Function<void, glmixed::GLhalfNV, glmixed::GLhalfNV> TexCoord2hNV; ///< Wrapper for glTexCoord2hNV
    static Function<void, const glmixed::GLhalfNV *> TexCoord2hvNV; ///< Wrapper for glTexCoord2hvNV
    static Function<void, glmixed::GLint, glmixed::GLint> TexCoord2i; ///< Wrapper for glTexCoord2i
    static Function<void, const glmixed::GLint *> TexCoord2iv; ///< Wrapper for glTexCoord2iv
    static Function<void, glmixed::GLshort, glmixed::GLshort> TexCoord2s; ///< Wrapper for glTexCoord2s
    static Function<void, const glmixed::GLshort *> TexCoord2sv; ///< Wrapper for glTexCoord2sv
    static Function<void, glmixed::GLfixed, glmixed::GLfixed> TexCoord2xOES; ///< Wrapper for glTexCoord2xOES
    static Function<void, const glmixed::GLfixed *> TexCoord2xvOES; ///< Wrapper for glTexCoord2xvOES
    static Function<void, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte> TexCoord3bOES; ///< Wrapper for glTexCoord3bOES
    static Function<void, const glmixed::GLbyte *> TexCoord3bvOES; ///< Wrapper for glTexCoord3bvOES
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> TexCoord3d; ///< Wrapper for glTexCoord3d
    static Function<void, const glmixed::GLdouble *> TexCoord3dv; ///< Wrapper for glTexCoord3dv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> TexCoord3f; ///< Wrapper for glTexCoord3f
    static Function<void, const glmixed::GLfloat *> TexCoord3fv; ///< Wrapper for glTexCoord3fv
    static Function<void, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV> TexCoord3hNV; ///< Wrapper for glTexCoord3hNV
    static Function<void, const glmixed::GLhalfNV *> TexCoord3hvNV; ///< Wrapper for glTexCoord3hvNV
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint> TexCoord3i; ///< Wrapper for glTexCoord3i
    static Function<void, const glmixed::GLint *> TexCoord3iv; ///< Wrapper for glTexCoord3iv
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> TexCoord3s; ///< Wrapper for glTexCoord3s
    static Function<void, const glmixed::GLshort *> TexCoord3sv; ///< Wrapper for glTexCoord3sv
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> TexCoord3xOES; ///< Wrapper for glTexCoord3xOES
    static Function<void, const glmixed::GLfixed *> TexCoord3xvOES; ///< Wrapper for glTexCoord3xvOES
    static Function<void, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte> TexCoord4bOES; ///< Wrapper for glTexCoord4bOES
    static Function<void, const glmixed::GLbyte *> TexCoord4bvOES; ///< Wrapper for glTexCoord4bvOES
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> TexCoord4d; ///< Wrapper for glTexCoord4d
    static Function<void, const glmixed::GLdouble *> TexCoord4dv; ///< Wrapper for glTexCoord4dv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> TexCoord4f; ///< Wrapper for glTexCoord4f
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> TexCoord4fColor4fNormal3fVertex4fSUN; ///< Wrapper for glTexCoord4fColor4fNormal3fVertex4fSUN
    static Function<void, const glmixed::GLfloat *, const glmixed::GLfloat *, const glmixed::GLfloat *, const glmixed::GLfloat *> TexCoord4fColor4fNormal3fVertex4fvSUN; ///< Wrapper for glTexCoord4fColor4fNormal3fVertex4fvSUN
    static Function<void, const glmixed::GLfloat *> TexCoord4fv; ///< Wrapper for glTexCoord4fv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> TexCoord4fVertex4fSUN; ///< Wrapper for glTexCoord4fVertex4fSUN
    static Function<void, const glmixed::GLfloat *, const glmixed::GLfloat *> TexCoord4fVertex4fvSUN; ///< Wrapper for glTexCoord4fVertex4fvSUN
    static Function<void, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV> TexCoord4hNV; ///< Wrapper for glTexCoord4hNV
    static Function<void, const glmixed::GLhalfNV *> TexCoord4hvNV; ///< Wrapper for glTexCoord4hvNV
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> TexCoord4i; ///< Wrapper for glTexCoord4i
    static Function<void, const glmixed::GLint *> TexCoord4iv; ///< Wrapper for glTexCoord4iv
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> TexCoord4s; ///< Wrapper for glTexCoord4s
    static Function<void, const glmixed::GLshort *> TexCoord4sv; ///< Wrapper for glTexCoord4sv
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> TexCoord4xOES; ///< Wrapper for glTexCoord4xOES
    static Function<void, const glmixed::GLfixed *> TexCoord4xvOES; ///< Wrapper for glTexCoord4xvOES
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei> TexCoordFormatNV; ///< Wrapper for glTexCoordFormatNV
    static Function<void, glmixed::GLenum, glmixed::GLuint> TexCoordP1ui; ///< Wrapper for glTexCoordP1ui
    static Function<void, glmixed::GLenum, const glmixed::GLuint *> TexCoordP1uiv; ///< Wrapper for glTexCoordP1uiv
    static Function<void, glmixed::GLenum, glmixed::GLuint> TexCoordP2ui; ///< Wrapper for glTexCoordP2ui
    static Function<void, glmixed::GLenum, const glmixed::GLuint *> TexCoordP2uiv; ///< Wrapper for glTexCoordP2uiv
    static Function<void, glmixed::GLenum, glmixed::GLuint> TexCoordP3ui; ///< Wrapper for glTexCoordP3ui
    static Function<void, glmixed::GLenum, const glmixed::GLuint *> TexCoordP3uiv; ///< Wrapper for glTexCoordP3uiv
    static Function<void, glmixed::GLenum, glmixed::GLuint> TexCoordP4ui; ///< Wrapper for glTexCoordP4ui
    static Function<void, glmixed::GLenum, const glmixed::GLuint *> TexCoordP4uiv; ///< Wrapper for glTexCoordP4uiv
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, const void *> TexCoordPointer; ///< Wrapper for glTexCoordPointer
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, const void *> TexCoordPointerEXT; ///< Wrapper for glTexCoordPointerEXT
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLint, const void **, glmixed::GLint> TexCoordPointerListIBM; ///< Wrapper for glTexCoordPointerListIBM
    static Function<void, glmixed::GLint, glmixed::GLenum, const void **> TexCoordPointervINTEL; ///< Wrapper for glTexCoordPointervINTEL
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat> TexEnvf; ///< Wrapper for glTexEnvf
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> TexEnvfv; ///< Wrapper for glTexEnvfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> TexEnvi; ///< Wrapper for glTexEnvi
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> TexEnviv; ///< Wrapper for glTexEnviv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfixed> TexEnvxOES; ///< Wrapper for glTexEnvxOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfixed *> TexEnvxvOES; ///< Wrapper for glTexEnvxvOES
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> TexEstimateMotionQCOM; ///< Wrapper for glTexEstimateMotionQCOM
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> TexEstimateMotionRegionsQCOM; ///< Wrapper for glTexEstimateMotionRegionsQCOM
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLfloat *> TexFilterFuncSGIS; ///< Wrapper for glTexFilterFuncSGIS
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLdouble> TexGend; ///< Wrapper for glTexGend
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLdouble *> TexGendv; ///< Wrapper for glTexGendv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat> TexGenf; ///< Wrapper for glTexGenf
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> TexGenfv; ///< Wrapper for glTexGenfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> TexGeni; ///< Wrapper for glTexGeni
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> TexGeniv; ///< Wrapper for glTexGeniv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfixed> TexGenxOES; ///< Wrapper for glTexGenxOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfixed *> TexGenxvOES; ///< Wrapper for glTexGenxvOES
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, const void *> TexImage1D; ///< Wrapper for glTexImage1D
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, const void *> TexImage2D; ///< Wrapper for glTexImage2D
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TexImage2DMultisample; ///< Wrapper for glTexImage2DMultisample
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TexImage2DMultisampleCoverageNV; ///< Wrapper for glTexImage2DMultisampleCoverageNV
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, const void *> TexImage3D; ///< Wrapper for glTexImage3D
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, const void *> TexImage3DEXT; ///< Wrapper for glTexImage3DEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TexImage3DMultisample; ///< Wrapper for glTexImage3DMultisample
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TexImage3DMultisampleCoverageNV; ///< Wrapper for glTexImage3DMultisampleCoverageNV
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, const void *> TexImage3DOES; ///< Wrapper for glTexImage3DOES
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, const void *> TexImage4DSGIS; ///< Wrapper for glTexImage4DSGIS
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TexPageCommitmentARB; ///< Wrapper for glTexPageCommitmentARB
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TexPageCommitmentEXT; ///< Wrapper for glTexPageCommitmentEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLuint, glmixed::GLuint64, glmixed::GLboolean> TexPageCommitmentMemNV; ///< Wrapper for glTexPageCommitmentMemNV
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat> TexParameterf; ///< Wrapper for glTexParameterf
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> TexParameterfv; ///< Wrapper for glTexParameterfv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> TexParameteri; ///< Wrapper for glTexParameteri
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> TexParameterIiv; ///< Wrapper for glTexParameterIiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> TexParameterIivEXT; ///< Wrapper for glTexParameterIivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> TexParameterIivOES; ///< Wrapper for glTexParameterIivOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLuint *> TexParameterIuiv; ///< Wrapper for glTexParameterIuiv
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLuint *> TexParameterIuivEXT; ///< Wrapper for glTexParameterIuivEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLuint *> TexParameterIuivOES; ///< Wrapper for glTexParameterIuivOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> TexParameteriv; ///< Wrapper for glTexParameteriv
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLfixed> TexParameterxOES; ///< Wrapper for glTexParameterxOES
    static Function<void, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfixed *> TexParameterxvOES; ///< Wrapper for glTexParameterxvOES
    static Function<void, glmixed::GLenum, glmixed::GLuint> TexRenderbufferNV; ///< Wrapper for glTexRenderbufferNV
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei> TexStorage1D; ///< Wrapper for glTexStorage1D
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei> TexStorage1DEXT; ///< Wrapper for glTexStorage1DEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> TexStorage2D; ///< Wrapper for glTexStorage2D
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> TexStorage2DEXT; ///< Wrapper for glTexStorage2DEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TexStorage2DMultisample; ///< Wrapper for glTexStorage2DMultisample
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei> TexStorage3D; ///< Wrapper for glTexStorage3D
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei> TexStorage3DEXT; ///< Wrapper for glTexStorage3DEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TexStorage3DMultisample; ///< Wrapper for glTexStorage3DMultisample
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TexStorage3DMultisampleOES; ///< Wrapper for glTexStorage3DMultisampleOES
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, const glmixed::GLint*> TexStorageAttribs2DEXT; ///< Wrapper for glTexStorageAttribs2DEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, const glmixed::GLint*> TexStorageAttribs3DEXT; ///< Wrapper for glTexStorageAttribs3DEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLuint, glmixed::GLuint64> TexStorageMem1DEXT; ///< Wrapper for glTexStorageMem1DEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLuint, glmixed::GLuint64> TexStorageMem2DEXT; ///< Wrapper for glTexStorageMem2DEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean, glmixed::GLuint, glmixed::GLuint64> TexStorageMem2DMultisampleEXT; ///< Wrapper for glTexStorageMem2DMultisampleEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLuint, glmixed::GLuint64> TexStorageMem3DEXT; ///< Wrapper for glTexStorageMem3DEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean, glmixed::GLuint, glmixed::GLuint64> TexStorageMem3DMultisampleEXT; ///< Wrapper for glTexStorageMem3DMultisampleEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::TextureStorageMaskAMD> TexStorageSparseAMD; ///< Wrapper for glTexStorageSparseAMD
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> TexSubImage1D; ///< Wrapper for glTexSubImage1D
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> TexSubImage1DEXT; ///< Wrapper for glTexSubImage1DEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> TexSubImage2D; ///< Wrapper for glTexSubImage2D
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> TexSubImage2DEXT; ///< Wrapper for glTexSubImage2DEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> TexSubImage3D; ///< Wrapper for glTexSubImage3D
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> TexSubImage3DEXT; ///< Wrapper for glTexSubImage3DEXT
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> TexSubImage3DOES; ///< Wrapper for glTexSubImage3DOES
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> TexSubImage4DSGIS; ///< Wrapper for glTexSubImage4DSGIS
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint64> TextureAttachMemoryNV; ///< Wrapper for glTextureAttachMemoryNV
    static Function<void> TextureBarrier; ///< Wrapper for glTextureBarrier
    static Function<void> TextureBarrierNV; ///< Wrapper for glTextureBarrierNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint> TextureBuffer; ///< Wrapper for glTextureBuffer
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint> TextureBufferEXT; ///< Wrapper for glTextureBufferEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr> TextureBufferRange; ///< Wrapper for glTextureBufferRange
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr> TextureBufferRangeEXT; ///< Wrapper for glTextureBufferRangeEXT
    static Function<void, glmixed::GLboolean, glmixed::GLboolean, glmixed::GLboolean, glmixed::GLboolean> TextureColorMaskSGIS; ///< Wrapper for glTextureColorMaskSGIS
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> TextureFoveationParametersQCOM; ///< Wrapper for glTextureFoveationParametersQCOM
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, const void *> TextureImage1DEXT; ///< Wrapper for glTextureImage1DEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, const void *> TextureImage2DEXT; ///< Wrapper for glTextureImage2DEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TextureImage2DMultisampleCoverageNV; ///< Wrapper for glTextureImage2DMultisampleCoverageNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TextureImage2DMultisampleNV; ///< Wrapper for glTextureImage2DMultisampleNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLenum, glmixed::GLenum, const void *> TextureImage3DEXT; ///< Wrapper for glTextureImage3DEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TextureImage3DMultisampleCoverageNV; ///< Wrapper for glTextureImage3DMultisampleCoverageNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TextureImage3DMultisampleNV; ///< Wrapper for glTextureImage3DMultisampleNV
    static Function<void, glmixed::GLenum> TextureLightEXT; ///< Wrapper for glTextureLightEXT
    static Function<void, glmixed::GLenum, glmixed::GLenum> TextureMaterialEXT; ///< Wrapper for glTextureMaterialEXT
    static Function<void, glmixed::GLenum> TextureNormalEXT; ///< Wrapper for glTextureNormalEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TexturePageCommitmentEXT; ///< Wrapper for glTexturePageCommitmentEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLuint, glmixed::GLuint64, glmixed::GLboolean> TexturePageCommitmentMemNV; ///< Wrapper for glTexturePageCommitmentMemNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLfloat> TextureParameterf; ///< Wrapper for glTextureParameterf
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLfloat> TextureParameterfEXT; ///< Wrapper for glTextureParameterfEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLfloat *> TextureParameterfv; ///< Wrapper for glTextureParameterfv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, const glmixed::GLfloat *> TextureParameterfvEXT; ///< Wrapper for glTextureParameterfvEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint> TextureParameteri; ///< Wrapper for glTextureParameteri
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLint> TextureParameteriEXT; ///< Wrapper for glTextureParameteriEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLint *> TextureParameterIiv; ///< Wrapper for glTextureParameterIiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> TextureParameterIivEXT; ///< Wrapper for glTextureParameterIivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLuint *> TextureParameterIuiv; ///< Wrapper for glTextureParameterIuiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, const glmixed::GLuint *> TextureParameterIuivEXT; ///< Wrapper for glTextureParameterIuivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, const glmixed::GLint *> TextureParameteriv; ///< Wrapper for glTextureParameteriv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, const glmixed::GLint *> TextureParameterivEXT; ///< Wrapper for glTextureParameterivEXT
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const void *> TextureRangeAPPLE; ///< Wrapper for glTextureRangeAPPLE
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint> TextureRenderbufferEXT; ///< Wrapper for glTextureRenderbufferEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei> TextureStorage1D; ///< Wrapper for glTextureStorage1D
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei> TextureStorage1DEXT; ///< Wrapper for glTextureStorage1DEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> TextureStorage2D; ///< Wrapper for glTextureStorage2D
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei> TextureStorage2DEXT; ///< Wrapper for glTextureStorage2DEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TextureStorage2DMultisample; ///< Wrapper for glTextureStorage2DMultisample
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TextureStorage2DMultisampleEXT; ///< Wrapper for glTextureStorage2DMultisampleEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei> TextureStorage3D; ///< Wrapper for glTextureStorage3D
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei> TextureStorage3DEXT; ///< Wrapper for glTextureStorage3DEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TextureStorage3DMultisample; ///< Wrapper for glTextureStorage3DMultisample
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean> TextureStorage3DMultisampleEXT; ///< Wrapper for glTextureStorage3DMultisampleEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLuint, glmixed::GLuint64> TextureStorageMem1DEXT; ///< Wrapper for glTextureStorageMem1DEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLuint, glmixed::GLuint64> TextureStorageMem2DEXT; ///< Wrapper for glTextureStorageMem2DEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean, glmixed::GLuint, glmixed::GLuint64> TextureStorageMem2DMultisampleEXT; ///< Wrapper for glTextureStorageMem2DMultisampleEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLuint, glmixed::GLuint64> TextureStorageMem3DEXT; ///< Wrapper for glTextureStorageMem3DEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLboolean, glmixed::GLuint, glmixed::GLuint64> TextureStorageMem3DMultisampleEXT; ///< Wrapper for glTextureStorageMem3DMultisampleEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::TextureStorageMaskAMD> TextureStorageSparseAMD; ///< Wrapper for glTextureStorageSparseAMD
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> TextureSubImage1D; ///< Wrapper for glTextureSubImage1D
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> TextureSubImage1DEXT; ///< Wrapper for glTextureSubImage1DEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> TextureSubImage2D; ///< Wrapper for glTextureSubImage2D
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> TextureSubImage2DEXT; ///< Wrapper for glTextureSubImage2DEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> TextureSubImage3D; ///< Wrapper for glTextureSubImage3D
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLsizei, glmixed::GLenum, glmixed::GLenum, const void *> TextureSubImage3DEXT; ///< Wrapper for glTextureSubImage3DEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> TextureView; ///< Wrapper for glTextureView
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> TextureViewEXT; ///< Wrapper for glTextureViewEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> TextureViewOES; ///< Wrapper for glTextureViewOES
    static Function<void, glmixed::GLenum, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum> TrackMatrixNV; ///< Wrapper for glTrackMatrixNV
    static Function<void, glmixed::GLsizei, const glmixed::GLint *, glmixed::GLenum> TransformFeedbackAttribsNV; ///< Wrapper for glTransformFeedbackAttribsNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> TransformFeedbackBufferBase; ///< Wrapper for glTransformFeedbackBufferBase
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizeiptr> TransformFeedbackBufferRange; ///< Wrapper for glTransformFeedbackBufferRange
    static Function<void, glmixed::GLsizei, const glmixed::GLint *, glmixed::GLsizei, const glmixed::GLint *, glmixed::GLenum> TransformFeedbackStreamAttribsNV; ///< Wrapper for glTransformFeedbackStreamAttribsNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLchar *const*, glmixed::GLenum> TransformFeedbackVaryings; ///< Wrapper for glTransformFeedbackVaryings
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLchar *const*, glmixed::GLenum> TransformFeedbackVaryingsEXT; ///< Wrapper for glTransformFeedbackVaryingsEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLint *, glmixed::GLenum> TransformFeedbackVaryingsNV; ///< Wrapper for glTransformFeedbackVaryingsNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, const glmixed::GLfloat *> TransformPathNV; ///< Wrapper for glTransformPathNV
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> Translated; ///< Wrapper for glTranslated
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Translatef; ///< Wrapper for glTranslatef
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> TranslatexOES; ///< Wrapper for glTranslatexOES
    static Function<void, glmixed::GLint, glmixed::GLdouble> Uniform1d; ///< Wrapper for glUniform1d
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLdouble *> Uniform1dv; ///< Wrapper for glUniform1dv
    static Function<void, glmixed::GLint, glmixed::GLfloat> Uniform1f; ///< Wrapper for glUniform1f
    static Function<void, glmixed::GLint, glmixed::GLfloat> Uniform1fARB; ///< Wrapper for glUniform1fARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLfloat *> Uniform1fv; ///< Wrapper for glUniform1fv
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLfloat *> Uniform1fvARB; ///< Wrapper for glUniform1fvARB
    static Function<void, glmixed::GLint, glmixed::GLint> Uniform1i; ///< Wrapper for glUniform1i
    static Function<void, glmixed::GLint, glmixed::GLint64> Uniform1i64ARB; ///< Wrapper for glUniform1i64ARB
    static Function<void, glmixed::GLint, glmixed::GLint64EXT> Uniform1i64NV; ///< Wrapper for glUniform1i64NV
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint64 *> Uniform1i64vARB; ///< Wrapper for glUniform1i64vARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint64EXT *> Uniform1i64vNV; ///< Wrapper for glUniform1i64vNV
    static Function<void, glmixed::GLint, glmixed::GLint> Uniform1iARB; ///< Wrapper for glUniform1iARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint *> Uniform1iv; ///< Wrapper for glUniform1iv
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint *> Uniform1ivARB; ///< Wrapper for glUniform1ivARB
    static Function<void, glmixed::GLint, glmixed::GLuint> Uniform1ui; ///< Wrapper for glUniform1ui
    static Function<void, glmixed::GLint, glmixed::GLuint64> Uniform1ui64ARB; ///< Wrapper for glUniform1ui64ARB
    static Function<void, glmixed::GLint, glmixed::GLuint64EXT> Uniform1ui64NV; ///< Wrapper for glUniform1ui64NV
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64 *> Uniform1ui64vARB; ///< Wrapper for glUniform1ui64vARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64EXT *> Uniform1ui64vNV; ///< Wrapper for glUniform1ui64vNV
    static Function<void, glmixed::GLint, glmixed::GLuint> Uniform1uiEXT; ///< Wrapper for glUniform1uiEXT
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint *> Uniform1uiv; ///< Wrapper for glUniform1uiv
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint *> Uniform1uivEXT; ///< Wrapper for glUniform1uivEXT
    static Function<void, glmixed::GLint, glmixed::GLdouble, glmixed::GLdouble> Uniform2d; ///< Wrapper for glUniform2d
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLdouble *> Uniform2dv; ///< Wrapper for glUniform2dv
    static Function<void, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat> Uniform2f; ///< Wrapper for glUniform2f
    static Function<void, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat> Uniform2fARB; ///< Wrapper for glUniform2fARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLfloat *> Uniform2fv; ///< Wrapper for glUniform2fv
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLfloat *> Uniform2fvARB; ///< Wrapper for glUniform2fvARB
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint> Uniform2i; ///< Wrapper for glUniform2i
    static Function<void, glmixed::GLint, glmixed::GLint64, glmixed::GLint64> Uniform2i64ARB; ///< Wrapper for glUniform2i64ARB
    static Function<void, glmixed::GLint, glmixed::GLint64EXT, glmixed::GLint64EXT> Uniform2i64NV; ///< Wrapper for glUniform2i64NV
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint64 *> Uniform2i64vARB; ///< Wrapper for glUniform2i64vARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint64EXT *> Uniform2i64vNV; ///< Wrapper for glUniform2i64vNV
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint> Uniform2iARB; ///< Wrapper for glUniform2iARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint *> Uniform2iv; ///< Wrapper for glUniform2iv
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint *> Uniform2ivARB; ///< Wrapper for glUniform2ivARB
    static Function<void, glmixed::GLint, glmixed::GLuint, glmixed::GLuint> Uniform2ui; ///< Wrapper for glUniform2ui
    static Function<void, glmixed::GLint, glmixed::GLuint64, glmixed::GLuint64> Uniform2ui64ARB; ///< Wrapper for glUniform2ui64ARB
    static Function<void, glmixed::GLint, glmixed::GLuint64EXT, glmixed::GLuint64EXT> Uniform2ui64NV; ///< Wrapper for glUniform2ui64NV
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64 *> Uniform2ui64vARB; ///< Wrapper for glUniform2ui64vARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64EXT *> Uniform2ui64vNV; ///< Wrapper for glUniform2ui64vNV
    static Function<void, glmixed::GLint, glmixed::GLuint, glmixed::GLuint> Uniform2uiEXT; ///< Wrapper for glUniform2uiEXT
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint *> Uniform2uiv; ///< Wrapper for glUniform2uiv
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint *> Uniform2uivEXT; ///< Wrapper for glUniform2uivEXT
    static Function<void, glmixed::GLint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> Uniform3d; ///< Wrapper for glUniform3d
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLdouble *> Uniform3dv; ///< Wrapper for glUniform3dv
    static Function<void, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Uniform3f; ///< Wrapper for glUniform3f
    static Function<void, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Uniform3fARB; ///< Wrapper for glUniform3fARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLfloat *> Uniform3fv; ///< Wrapper for glUniform3fv
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLfloat *> Uniform3fvARB; ///< Wrapper for glUniform3fvARB
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> Uniform3i; ///< Wrapper for glUniform3i
    static Function<void, glmixed::GLint, glmixed::GLint64, glmixed::GLint64, glmixed::GLint64> Uniform3i64ARB; ///< Wrapper for glUniform3i64ARB
    static Function<void, glmixed::GLint, glmixed::GLint64EXT, glmixed::GLint64EXT, glmixed::GLint64EXT> Uniform3i64NV; ///< Wrapper for glUniform3i64NV
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint64 *> Uniform3i64vARB; ///< Wrapper for glUniform3i64vARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint64EXT *> Uniform3i64vNV; ///< Wrapper for glUniform3i64vNV
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> Uniform3iARB; ///< Wrapper for glUniform3iARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint *> Uniform3iv; ///< Wrapper for glUniform3iv
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint *> Uniform3ivARB; ///< Wrapper for glUniform3ivARB
    static Function<void, glmixed::GLint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> Uniform3ui; ///< Wrapper for glUniform3ui
    static Function<void, glmixed::GLint, glmixed::GLuint64, glmixed::GLuint64, glmixed::GLuint64> Uniform3ui64ARB; ///< Wrapper for glUniform3ui64ARB
    static Function<void, glmixed::GLint, glmixed::GLuint64EXT, glmixed::GLuint64EXT, glmixed::GLuint64EXT> Uniform3ui64NV; ///< Wrapper for glUniform3ui64NV
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64 *> Uniform3ui64vARB; ///< Wrapper for glUniform3ui64vARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64EXT *> Uniform3ui64vNV; ///< Wrapper for glUniform3ui64vNV
    static Function<void, glmixed::GLint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> Uniform3uiEXT; ///< Wrapper for glUniform3uiEXT
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint *> Uniform3uiv; ///< Wrapper for glUniform3uiv
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint *> Uniform3uivEXT; ///< Wrapper for glUniform3uivEXT
    static Function<void, glmixed::GLint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> Uniform4d; ///< Wrapper for glUniform4d
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLdouble *> Uniform4dv; ///< Wrapper for glUniform4dv
    static Function<void, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Uniform4f; ///< Wrapper for glUniform4f
    static Function<void, glmixed::GLint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Uniform4fARB; ///< Wrapper for glUniform4fARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLfloat *> Uniform4fv; ///< Wrapper for glUniform4fv
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLfloat *> Uniform4fvARB; ///< Wrapper for glUniform4fvARB
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> Uniform4i; ///< Wrapper for glUniform4i
    static Function<void, glmixed::GLint, glmixed::GLint64, glmixed::GLint64, glmixed::GLint64, glmixed::GLint64> Uniform4i64ARB; ///< Wrapper for glUniform4i64ARB
    static Function<void, glmixed::GLint, glmixed::GLint64EXT, glmixed::GLint64EXT, glmixed::GLint64EXT, glmixed::GLint64EXT> Uniform4i64NV; ///< Wrapper for glUniform4i64NV
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint64 *> Uniform4i64vARB; ///< Wrapper for glUniform4i64vARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint64EXT *> Uniform4i64vNV; ///< Wrapper for glUniform4i64vNV
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> Uniform4iARB; ///< Wrapper for glUniform4iARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint *> Uniform4iv; ///< Wrapper for glUniform4iv
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLint *> Uniform4ivARB; ///< Wrapper for glUniform4ivARB
    static Function<void, glmixed::GLint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> Uniform4ui; ///< Wrapper for glUniform4ui
    static Function<void, glmixed::GLint, glmixed::GLuint64, glmixed::GLuint64, glmixed::GLuint64, glmixed::GLuint64> Uniform4ui64ARB; ///< Wrapper for glUniform4ui64ARB
    static Function<void, glmixed::GLint, glmixed::GLuint64EXT, glmixed::GLuint64EXT, glmixed::GLuint64EXT, glmixed::GLuint64EXT> Uniform4ui64NV; ///< Wrapper for glUniform4ui64NV
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64 *> Uniform4ui64vARB; ///< Wrapper for glUniform4ui64vARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64EXT *> Uniform4ui64vNV; ///< Wrapper for glUniform4ui64vNV
    static Function<void, glmixed::GLint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> Uniform4uiEXT; ///< Wrapper for glUniform4uiEXT
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint *> Uniform4uiv; ///< Wrapper for glUniform4uiv
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint *> Uniform4uivEXT; ///< Wrapper for glUniform4uivEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> UniformBlockBinding; ///< Wrapper for glUniformBlockBinding
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLuint> UniformBufferEXT; ///< Wrapper for glUniformBufferEXT
    static Function<void, glmixed::GLint, glmixed::GLuint64> UniformHandleui64ARB; ///< Wrapper for glUniformHandleui64ARB
    static Function<void, glmixed::GLint, glmixed::GLuint64> UniformHandleui64IMG; ///< Wrapper for glUniformHandleui64IMG
    static Function<void, glmixed::GLint, glmixed::GLuint64> UniformHandleui64NV; ///< Wrapper for glUniformHandleui64NV
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64 *> UniformHandleui64vARB; ///< Wrapper for glUniformHandleui64vARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64 *> UniformHandleui64vIMG; ///< Wrapper for glUniformHandleui64vIMG
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64 *> UniformHandleui64vNV; ///< Wrapper for glUniformHandleui64vNV
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> UniformMatrix2dv; ///< Wrapper for glUniformMatrix2dv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix2fv; ///< Wrapper for glUniformMatrix2fv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix2fvARB; ///< Wrapper for glUniformMatrix2fvARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> UniformMatrix2x3dv; ///< Wrapper for glUniformMatrix2x3dv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix2x3fv; ///< Wrapper for glUniformMatrix2x3fv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix2x3fvNV; ///< Wrapper for glUniformMatrix2x3fvNV
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> UniformMatrix2x4dv; ///< Wrapper for glUniformMatrix2x4dv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix2x4fv; ///< Wrapper for glUniformMatrix2x4fv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix2x4fvNV; ///< Wrapper for glUniformMatrix2x4fvNV
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> UniformMatrix3dv; ///< Wrapper for glUniformMatrix3dv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix3fv; ///< Wrapper for glUniformMatrix3fv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix3fvARB; ///< Wrapper for glUniformMatrix3fvARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> UniformMatrix3x2dv; ///< Wrapper for glUniformMatrix3x2dv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix3x2fv; ///< Wrapper for glUniformMatrix3x2fv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix3x2fvNV; ///< Wrapper for glUniformMatrix3x2fvNV
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> UniformMatrix3x4dv; ///< Wrapper for glUniformMatrix3x4dv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix3x4fv; ///< Wrapper for glUniformMatrix3x4fv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix3x4fvNV; ///< Wrapper for glUniformMatrix3x4fvNV
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> UniformMatrix4dv; ///< Wrapper for glUniformMatrix4dv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix4fv; ///< Wrapper for glUniformMatrix4fv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix4fvARB; ///< Wrapper for glUniformMatrix4fvARB
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> UniformMatrix4x2dv; ///< Wrapper for glUniformMatrix4x2dv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix4x2fv; ///< Wrapper for glUniformMatrix4x2fv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix4x2fvNV; ///< Wrapper for glUniformMatrix4x2fvNV
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLdouble *> UniformMatrix4x3dv; ///< Wrapper for glUniformMatrix4x3dv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix4x3fv; ///< Wrapper for glUniformMatrix4x3fv
    static Function<void, glmixed::GLint, glmixed::GLsizei, glmixed::GLboolean, const glmixed::GLfloat *> UniformMatrix4x3fvNV; ///< Wrapper for glUniformMatrix4x3fvNV
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLuint *> UniformSubroutinesuiv; ///< Wrapper for glUniformSubroutinesuiv
    static Function<void, glmixed::GLint, glmixed::GLuint64EXT> Uniformui64NV; ///< Wrapper for glUniformui64NV
    static Function<void, glmixed::GLint, glmixed::GLsizei, const glmixed::GLuint64EXT *> Uniformui64vNV; ///< Wrapper for glUniformui64vNV
    static Function<void> UnlockArraysEXT; ///< Wrapper for glUnlockArraysEXT
    static Function<glmixed::GLboolean, glmixed::GLenum> UnmapBuffer; ///< Wrapper for glUnmapBuffer
    static Function<glmixed::GLboolean, glmixed::GLenum> UnmapBufferARB; ///< Wrapper for glUnmapBufferARB
    static Function<glmixed::GLboolean, glmixed::GLenum> UnmapBufferOES; ///< Wrapper for glUnmapBufferOES
    static Function<glmixed::GLboolean, glmixed::GLuint> UnmapNamedBuffer; ///< Wrapper for glUnmapNamedBuffer
    static Function<glmixed::GLboolean, glmixed::GLuint> UnmapNamedBufferEXT; ///< Wrapper for glUnmapNamedBufferEXT
    static Function<void, glmixed::GLuint> UnmapObjectBufferATI; ///< Wrapper for glUnmapObjectBufferATI
    static Function<void, glmixed::GLuint, glmixed::GLint> UnmapTexture2DINTEL; ///< Wrapper for glUnmapTexture2DINTEL
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, const void *, glmixed::GLenum> UpdateObjectBufferATI; ///< Wrapper for glUpdateObjectBufferATI
    static Function<void, glmixed::GLbitfield> UploadGpuMaskNVX; ///< Wrapper for glUploadGpuMaskNVX
    static Function<void, glmixed::GLuint> UseProgram; ///< Wrapper for glUseProgram
    static Function<void, glmixed::GLhandleARB> UseProgramObjectARB; ///< Wrapper for glUseProgramObjectARB
    static Function<void, glmixed::GLuint, glmixed::UseProgramStageMask, glmixed::GLuint> UseProgramStages; ///< Wrapper for glUseProgramStages
    static Function<void, glmixed::GLuint, glmixed::UseProgramStageMask, glmixed::GLuint> UseProgramStagesEXT; ///< Wrapper for glUseProgramStagesEXT
    static Function<void, glmixed::GLenum, glmixed::GLuint> UseShaderProgramEXT; ///< Wrapper for glUseShaderProgramEXT
    static Function<void, glmixed::GLuint> ValidateProgram; ///< Wrapper for glValidateProgram
    static Function<void, glmixed::GLhandleARB> ValidateProgramARB; ///< Wrapper for glValidateProgramARB
    static Function<void, glmixed::GLuint> ValidateProgramPipeline; ///< Wrapper for glValidateProgramPipeline
    static Function<void, glmixed::GLuint> ValidateProgramPipelineEXT; ///< Wrapper for glValidateProgramPipelineEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLuint, glmixed::GLuint> VariantArrayObjectATI; ///< Wrapper for glVariantArrayObjectATI
    static Function<void, glmixed::GLuint, const glmixed::GLbyte *> VariantbvEXT; ///< Wrapper for glVariantbvEXT
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VariantdvEXT; ///< Wrapper for glVariantdvEXT
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> VariantfvEXT; ///< Wrapper for glVariantfvEXT
    static Function<void, glmixed::GLuint, const glmixed::GLint *> VariantivEXT; ///< Wrapper for glVariantivEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLuint, const void *> VariantPointerEXT; ///< Wrapper for glVariantPointerEXT
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VariantsvEXT; ///< Wrapper for glVariantsvEXT
    static Function<void, glmixed::GLuint, const glmixed::GLubyte *> VariantubvEXT; ///< Wrapper for glVariantubvEXT
    static Function<void, glmixed::GLuint, const glmixed::GLuint *> VariantuivEXT; ///< Wrapper for glVariantuivEXT
    static Function<void, glmixed::GLuint, const glmixed::GLushort *> VariantusvEXT; ///< Wrapper for glVariantusvEXT
    static Function<void> VDPAUFiniNV; ///< Wrapper for glVDPAUFiniNV
    static Function<void, glmixed::GLvdpauSurfaceNV, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei *, glmixed::GLint *> VDPAUGetSurfaceivNV; ///< Wrapper for glVDPAUGetSurfaceivNV
    static Function<void, const void *, const void *> VDPAUInitNV; ///< Wrapper for glVDPAUInitNV
    static Function<glmixed::GLboolean, glmixed::GLvdpauSurfaceNV> VDPAUIsSurfaceNV; ///< Wrapper for glVDPAUIsSurfaceNV
    static Function<void, glmixed::GLsizei, const glmixed::GLvdpauSurfaceNV *> VDPAUMapSurfacesNV; ///< Wrapper for glVDPAUMapSurfacesNV
    static Function<glmixed::GLvdpauSurfaceNV, const void *, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLuint *> VDPAURegisterOutputSurfaceNV; ///< Wrapper for glVDPAURegisterOutputSurfaceNV
    static Function<glmixed::GLvdpauSurfaceNV, const void *, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLuint *> VDPAURegisterVideoSurfaceNV; ///< Wrapper for glVDPAURegisterVideoSurfaceNV
    static Function<glmixed::GLvdpauSurfaceNV, const void *, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLuint *, glmixed::GLboolean> VDPAURegisterVideoSurfaceWithPictureStructureNV; ///< Wrapper for glVDPAURegisterVideoSurfaceWithPictureStructureNV
    static Function<void, glmixed::GLvdpauSurfaceNV, glmixed::GLenum> VDPAUSurfaceAccessNV; ///< Wrapper for glVDPAUSurfaceAccessNV
    static Function<void, glmixed::GLsizei, const glmixed::GLvdpauSurfaceNV *> VDPAUUnmapSurfacesNV; ///< Wrapper for glVDPAUUnmapSurfacesNV
    static Function<void, glmixed::GLvdpauSurfaceNV> VDPAUUnregisterSurfaceNV; ///< Wrapper for glVDPAUUnregisterSurfaceNV
    static Function<void, glmixed::GLbyte, glmixed::GLbyte> Vertex2bOES; ///< Wrapper for glVertex2bOES
    static Function<void, const glmixed::GLbyte *> Vertex2bvOES; ///< Wrapper for glVertex2bvOES
    static Function<void, glmixed::GLdouble, glmixed::GLdouble> Vertex2d; ///< Wrapper for glVertex2d
    static Function<void, const glmixed::GLdouble *> Vertex2dv; ///< Wrapper for glVertex2dv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat> Vertex2f; ///< Wrapper for glVertex2f
    static Function<void, const glmixed::GLfloat *> Vertex2fv; ///< Wrapper for glVertex2fv
    static Function<void, glmixed::GLhalfNV, glmixed::GLhalfNV> Vertex2hNV; ///< Wrapper for glVertex2hNV
    static Function<void, const glmixed::GLhalfNV *> Vertex2hvNV; ///< Wrapper for glVertex2hvNV
    static Function<void, glmixed::GLint, glmixed::GLint> Vertex2i; ///< Wrapper for glVertex2i
    static Function<void, const glmixed::GLint *> Vertex2iv; ///< Wrapper for glVertex2iv
    static Function<void, glmixed::GLshort, glmixed::GLshort> Vertex2s; ///< Wrapper for glVertex2s
    static Function<void, const glmixed::GLshort *> Vertex2sv; ///< Wrapper for glVertex2sv
    static Function<void, glmixed::GLfixed> Vertex2xOES; ///< Wrapper for glVertex2xOES
    static Function<void, const glmixed::GLfixed *> Vertex2xvOES; ///< Wrapper for glVertex2xvOES
    static Function<void, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte> Vertex3bOES; ///< Wrapper for glVertex3bOES
    static Function<void, const glmixed::GLbyte *> Vertex3bvOES; ///< Wrapper for glVertex3bvOES
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> Vertex3d; ///< Wrapper for glVertex3d
    static Function<void, const glmixed::GLdouble *> Vertex3dv; ///< Wrapper for glVertex3dv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Vertex3f; ///< Wrapper for glVertex3f
    static Function<void, const glmixed::GLfloat *> Vertex3fv; ///< Wrapper for glVertex3fv
    static Function<void, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV> Vertex3hNV; ///< Wrapper for glVertex3hNV
    static Function<void, const glmixed::GLhalfNV *> Vertex3hvNV; ///< Wrapper for glVertex3hvNV
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint> Vertex3i; ///< Wrapper for glVertex3i
    static Function<void, const glmixed::GLint *> Vertex3iv; ///< Wrapper for glVertex3iv
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> Vertex3s; ///< Wrapper for glVertex3s
    static Function<void, const glmixed::GLshort *> Vertex3sv; ///< Wrapper for glVertex3sv
    static Function<void, glmixed::GLfixed, glmixed::GLfixed> Vertex3xOES; ///< Wrapper for glVertex3xOES
    static Function<void, const glmixed::GLfixed *> Vertex3xvOES; ///< Wrapper for glVertex3xvOES
    static Function<void, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte, glmixed::GLbyte> Vertex4bOES; ///< Wrapper for glVertex4bOES
    static Function<void, const glmixed::GLbyte *> Vertex4bvOES; ///< Wrapper for glVertex4bvOES
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> Vertex4d; ///< Wrapper for glVertex4d
    static Function<void, const glmixed::GLdouble *> Vertex4dv; ///< Wrapper for glVertex4dv
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> Vertex4f; ///< Wrapper for glVertex4f
    static Function<void, const glmixed::GLfloat *> Vertex4fv; ///< Wrapper for glVertex4fv
    static Function<void, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV> Vertex4hNV; ///< Wrapper for glVertex4hNV
    static Function<void, const glmixed::GLhalfNV *> Vertex4hvNV; ///< Wrapper for glVertex4hvNV
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> Vertex4i; ///< Wrapper for glVertex4i
    static Function<void, const glmixed::GLint *> Vertex4iv; ///< Wrapper for glVertex4iv
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> Vertex4s; ///< Wrapper for glVertex4s
    static Function<void, const glmixed::GLshort *> Vertex4sv; ///< Wrapper for glVertex4sv
    static Function<void, glmixed::GLfixed, glmixed::GLfixed, glmixed::GLfixed> Vertex4xOES; ///< Wrapper for glVertex4xOES
    static Function<void, const glmixed::GLfixed *> Vertex4xvOES; ///< Wrapper for glVertex4xvOES
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> VertexArrayAttribBinding; ///< Wrapper for glVertexArrayAttribBinding
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLboolean, glmixed::GLuint> VertexArrayAttribFormat; ///< Wrapper for glVertexArrayAttribFormat
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLuint> VertexArrayAttribIFormat; ///< Wrapper for glVertexArrayAttribIFormat
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLuint> VertexArrayAttribLFormat; ///< Wrapper for glVertexArrayAttribLFormat
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> VertexArrayBindingDivisor; ///< Wrapper for glVertexArrayBindingDivisor
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizei> VertexArrayBindVertexBufferEXT; ///< Wrapper for glVertexArrayBindVertexBufferEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLintptr> VertexArrayColorOffsetEXT; ///< Wrapper for glVertexArrayColorOffsetEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, glmixed::GLintptr> VertexArrayEdgeFlagOffsetEXT; ///< Wrapper for glVertexArrayEdgeFlagOffsetEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint> VertexArrayElementBuffer; ///< Wrapper for glVertexArrayElementBuffer
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLintptr> VertexArrayFogCoordOffsetEXT; ///< Wrapper for glVertexArrayFogCoordOffsetEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLintptr> VertexArrayIndexOffsetEXT; ///< Wrapper for glVertexArrayIndexOffsetEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLintptr> VertexArrayMultiTexCoordOffsetEXT; ///< Wrapper for glVertexArrayMultiTexCoordOffsetEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLintptr> VertexArrayNormalOffsetEXT; ///< Wrapper for glVertexArrayNormalOffsetEXT
    static Function<void, glmixed::GLenum, glmixed::GLint> VertexArrayParameteriAPPLE; ///< Wrapper for glVertexArrayParameteriAPPLE
    static Function<void, glmixed::GLsizei, void *> VertexArrayRangeAPPLE; ///< Wrapper for glVertexArrayRangeAPPLE
    static Function<void, glmixed::GLsizei, const void *> VertexArrayRangeNV; ///< Wrapper for glVertexArrayRangeNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLintptr> VertexArraySecondaryColorOffsetEXT; ///< Wrapper for glVertexArraySecondaryColorOffsetEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLintptr> VertexArrayTexCoordOffsetEXT; ///< Wrapper for glVertexArrayTexCoordOffsetEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> VertexArrayVertexAttribBindingEXT; ///< Wrapper for glVertexArrayVertexAttribBindingEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> VertexArrayVertexAttribDivisorEXT; ///< Wrapper for glVertexArrayVertexAttribDivisorEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLboolean, glmixed::GLuint> VertexArrayVertexAttribFormatEXT; ///< Wrapper for glVertexArrayVertexAttribFormatEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLuint> VertexArrayVertexAttribIFormatEXT; ///< Wrapper for glVertexArrayVertexAttribIFormatEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLintptr> VertexArrayVertexAttribIOffsetEXT; ///< Wrapper for glVertexArrayVertexAttribIOffsetEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLuint> VertexArrayVertexAttribLFormatEXT; ///< Wrapper for glVertexArrayVertexAttribLFormatEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLintptr> VertexArrayVertexAttribLOffsetEXT; ///< Wrapper for glVertexArrayVertexAttribLOffsetEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLboolean, glmixed::GLsizei, glmixed::GLintptr> VertexArrayVertexAttribOffsetEXT; ///< Wrapper for glVertexArrayVertexAttribOffsetEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> VertexArrayVertexBindingDivisorEXT; ///< Wrapper for glVertexArrayVertexBindingDivisorEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLintptr, glmixed::GLsizei> VertexArrayVertexBuffer; ///< Wrapper for glVertexArrayVertexBuffer
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *, const glmixed::GLintptr *, const glmixed::GLsizei *> VertexArrayVertexBuffers; ///< Wrapper for glVertexArrayVertexBuffers
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLintptr> VertexArrayVertexOffsetEXT; ///< Wrapper for glVertexArrayVertexOffsetEXT
    static Function<void, glmixed::GLuint, glmixed::GLdouble> VertexAttrib1d; ///< Wrapper for glVertexAttrib1d
    static Function<void, glmixed::GLuint, glmixed::GLdouble> VertexAttrib1dARB; ///< Wrapper for glVertexAttrib1dARB
    static Function<void, glmixed::GLuint, glmixed::GLdouble> VertexAttrib1dNV; ///< Wrapper for glVertexAttrib1dNV
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttrib1dv; ///< Wrapper for glVertexAttrib1dv
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttrib1dvARB; ///< Wrapper for glVertexAttrib1dvARB
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttrib1dvNV; ///< Wrapper for glVertexAttrib1dvNV
    static Function<void, glmixed::GLuint, glmixed::GLfloat> VertexAttrib1f; ///< Wrapper for glVertexAttrib1f
    static Function<void, glmixed::GLuint, glmixed::GLfloat> VertexAttrib1fARB; ///< Wrapper for glVertexAttrib1fARB
    static Function<void, glmixed::GLuint, glmixed::GLfloat> VertexAttrib1fNV; ///< Wrapper for glVertexAttrib1fNV
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> VertexAttrib1fv; ///< Wrapper for glVertexAttrib1fv
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> VertexAttrib1fvARB; ///< Wrapper for glVertexAttrib1fvARB
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> VertexAttrib1fvNV; ///< Wrapper for glVertexAttrib1fvNV
    static Function<void, glmixed::GLuint, glmixed::GLhalfNV> VertexAttrib1hNV; ///< Wrapper for glVertexAttrib1hNV
    static Function<void, glmixed::GLuint, const glmixed::GLhalfNV *> VertexAttrib1hvNV; ///< Wrapper for glVertexAttrib1hvNV
    static Function<void, glmixed::GLuint, glmixed::GLshort> VertexAttrib1s; ///< Wrapper for glVertexAttrib1s
    static Function<void, glmixed::GLuint, glmixed::GLshort> VertexAttrib1sARB; ///< Wrapper for glVertexAttrib1sARB
    static Function<void, glmixed::GLuint, glmixed::GLshort> VertexAttrib1sNV; ///< Wrapper for glVertexAttrib1sNV
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VertexAttrib1sv; ///< Wrapper for glVertexAttrib1sv
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VertexAttrib1svARB; ///< Wrapper for glVertexAttrib1svARB
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VertexAttrib1svNV; ///< Wrapper for glVertexAttrib1svNV
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble> VertexAttrib2d; ///< Wrapper for glVertexAttrib2d
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble> VertexAttrib2dARB; ///< Wrapper for glVertexAttrib2dARB
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble> VertexAttrib2dNV; ///< Wrapper for glVertexAttrib2dNV
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttrib2dv; ///< Wrapper for glVertexAttrib2dv
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttrib2dvARB; ///< Wrapper for glVertexAttrib2dvARB
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttrib2dvNV; ///< Wrapper for glVertexAttrib2dvNV
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat> VertexAttrib2f; ///< Wrapper for glVertexAttrib2f
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat> VertexAttrib2fARB; ///< Wrapper for glVertexAttrib2fARB
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat> VertexAttrib2fNV; ///< Wrapper for glVertexAttrib2fNV
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> VertexAttrib2fv; ///< Wrapper for glVertexAttrib2fv
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> VertexAttrib2fvARB; ///< Wrapper for glVertexAttrib2fvARB
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> VertexAttrib2fvNV; ///< Wrapper for glVertexAttrib2fvNV
    static Function<void, glmixed::GLuint, glmixed::GLhalfNV, glmixed::GLhalfNV> VertexAttrib2hNV; ///< Wrapper for glVertexAttrib2hNV
    static Function<void, glmixed::GLuint, const glmixed::GLhalfNV *> VertexAttrib2hvNV; ///< Wrapper for glVertexAttrib2hvNV
    static Function<void, glmixed::GLuint, glmixed::GLshort, glmixed::GLshort> VertexAttrib2s; ///< Wrapper for glVertexAttrib2s
    static Function<void, glmixed::GLuint, glmixed::GLshort, glmixed::GLshort> VertexAttrib2sARB; ///< Wrapper for glVertexAttrib2sARB
    static Function<void, glmixed::GLuint, glmixed::GLshort, glmixed::GLshort> VertexAttrib2sNV; ///< Wrapper for glVertexAttrib2sNV
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VertexAttrib2sv; ///< Wrapper for glVertexAttrib2sv
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VertexAttrib2svARB; ///< Wrapper for glVertexAttrib2svARB
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VertexAttrib2svNV; ///< Wrapper for glVertexAttrib2svNV
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> VertexAttrib3d; ///< Wrapper for glVertexAttrib3d
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> VertexAttrib3dARB; ///< Wrapper for glVertexAttrib3dARB
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> VertexAttrib3dNV; ///< Wrapper for glVertexAttrib3dNV
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttrib3dv; ///< Wrapper for glVertexAttrib3dv
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttrib3dvARB; ///< Wrapper for glVertexAttrib3dvARB
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttrib3dvNV; ///< Wrapper for glVertexAttrib3dvNV
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> VertexAttrib3f; ///< Wrapper for glVertexAttrib3f
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> VertexAttrib3fARB; ///< Wrapper for glVertexAttrib3fARB
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> VertexAttrib3fNV; ///< Wrapper for glVertexAttrib3fNV
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> VertexAttrib3fv; ///< Wrapper for glVertexAttrib3fv
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> VertexAttrib3fvARB; ///< Wrapper for glVertexAttrib3fvARB
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> VertexAttrib3fvNV; ///< Wrapper for glVertexAttrib3fvNV
    static Function<void, glmixed::GLuint, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV> VertexAttrib3hNV; ///< Wrapper for glVertexAttrib3hNV
    static Function<void, glmixed::GLuint, const glmixed::GLhalfNV *> VertexAttrib3hvNV; ///< Wrapper for glVertexAttrib3hvNV
    static Function<void, glmixed::GLuint, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> VertexAttrib3s; ///< Wrapper for glVertexAttrib3s
    static Function<void, glmixed::GLuint, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> VertexAttrib3sARB; ///< Wrapper for glVertexAttrib3sARB
    static Function<void, glmixed::GLuint, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> VertexAttrib3sNV; ///< Wrapper for glVertexAttrib3sNV
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VertexAttrib3sv; ///< Wrapper for glVertexAttrib3sv
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VertexAttrib3svARB; ///< Wrapper for glVertexAttrib3svARB
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VertexAttrib3svNV; ///< Wrapper for glVertexAttrib3svNV
    static Function<void, glmixed::GLuint, const glmixed::GLbyte *> VertexAttrib4bv; ///< Wrapper for glVertexAttrib4bv
    static Function<void, glmixed::GLuint, const glmixed::GLbyte *> VertexAttrib4bvARB; ///< Wrapper for glVertexAttrib4bvARB
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> VertexAttrib4d; ///< Wrapper for glVertexAttrib4d
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> VertexAttrib4dARB; ///< Wrapper for glVertexAttrib4dARB
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> VertexAttrib4dNV; ///< Wrapper for glVertexAttrib4dNV
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttrib4dv; ///< Wrapper for glVertexAttrib4dv
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttrib4dvARB; ///< Wrapper for glVertexAttrib4dvARB
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttrib4dvNV; ///< Wrapper for glVertexAttrib4dvNV
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> VertexAttrib4f; ///< Wrapper for glVertexAttrib4f
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> VertexAttrib4fARB; ///< Wrapper for glVertexAttrib4fARB
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> VertexAttrib4fNV; ///< Wrapper for glVertexAttrib4fNV
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> VertexAttrib4fv; ///< Wrapper for glVertexAttrib4fv
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> VertexAttrib4fvARB; ///< Wrapper for glVertexAttrib4fvARB
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> VertexAttrib4fvNV; ///< Wrapper for glVertexAttrib4fvNV
    static Function<void, glmixed::GLuint, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV, glmixed::GLhalfNV> VertexAttrib4hNV; ///< Wrapper for glVertexAttrib4hNV
    static Function<void, glmixed::GLuint, const glmixed::GLhalfNV *> VertexAttrib4hvNV; ///< Wrapper for glVertexAttrib4hvNV
    static Function<void, glmixed::GLuint, const glmixed::GLint *> VertexAttrib4iv; ///< Wrapper for glVertexAttrib4iv
    static Function<void, glmixed::GLuint, const glmixed::GLint *> VertexAttrib4ivARB; ///< Wrapper for glVertexAttrib4ivARB
    static Function<void, glmixed::GLuint, const glmixed::GLbyte *> VertexAttrib4Nbv; ///< Wrapper for glVertexAttrib4Nbv
    static Function<void, glmixed::GLuint, const glmixed::GLbyte *> VertexAttrib4NbvARB; ///< Wrapper for glVertexAttrib4NbvARB
    static Function<void, glmixed::GLuint, const glmixed::GLint *> VertexAttrib4Niv; ///< Wrapper for glVertexAttrib4Niv
    static Function<void, glmixed::GLuint, const glmixed::GLint *> VertexAttrib4NivARB; ///< Wrapper for glVertexAttrib4NivARB
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VertexAttrib4Nsv; ///< Wrapper for glVertexAttrib4Nsv
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VertexAttrib4NsvARB; ///< Wrapper for glVertexAttrib4NsvARB
    static Function<void, glmixed::GLuint, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte> VertexAttrib4Nub; ///< Wrapper for glVertexAttrib4Nub
    static Function<void, glmixed::GLuint, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte> VertexAttrib4NubARB; ///< Wrapper for glVertexAttrib4NubARB
    static Function<void, glmixed::GLuint, const glmixed::GLubyte *> VertexAttrib4Nubv; ///< Wrapper for glVertexAttrib4Nubv
    static Function<void, glmixed::GLuint, const glmixed::GLubyte *> VertexAttrib4NubvARB; ///< Wrapper for glVertexAttrib4NubvARB
    static Function<void, glmixed::GLuint, const glmixed::GLuint *> VertexAttrib4Nuiv; ///< Wrapper for glVertexAttrib4Nuiv
    static Function<void, glmixed::GLuint, const glmixed::GLuint *> VertexAttrib4NuivARB; ///< Wrapper for glVertexAttrib4NuivARB
    static Function<void, glmixed::GLuint, const glmixed::GLushort *> VertexAttrib4Nusv; ///< Wrapper for glVertexAttrib4Nusv
    static Function<void, glmixed::GLuint, const glmixed::GLushort *> VertexAttrib4NusvARB; ///< Wrapper for glVertexAttrib4NusvARB
    static Function<void, glmixed::GLuint, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> VertexAttrib4s; ///< Wrapper for glVertexAttrib4s
    static Function<void, glmixed::GLuint, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> VertexAttrib4sARB; ///< Wrapper for glVertexAttrib4sARB
    static Function<void, glmixed::GLuint, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> VertexAttrib4sNV; ///< Wrapper for glVertexAttrib4sNV
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VertexAttrib4sv; ///< Wrapper for glVertexAttrib4sv
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VertexAttrib4svARB; ///< Wrapper for glVertexAttrib4svARB
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VertexAttrib4svNV; ///< Wrapper for glVertexAttrib4svNV
    static Function<void, glmixed::GLuint, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte, glmixed::GLubyte> VertexAttrib4ubNV; ///< Wrapper for glVertexAttrib4ubNV
    static Function<void, glmixed::GLuint, const glmixed::GLubyte *> VertexAttrib4ubv; ///< Wrapper for glVertexAttrib4ubv
    static Function<void, glmixed::GLuint, const glmixed::GLubyte *> VertexAttrib4ubvARB; ///< Wrapper for glVertexAttrib4ubvARB
    static Function<void, glmixed::GLuint, const glmixed::GLubyte *> VertexAttrib4ubvNV; ///< Wrapper for glVertexAttrib4ubvNV
    static Function<void, glmixed::GLuint, const glmixed::GLuint *> VertexAttrib4uiv; ///< Wrapper for glVertexAttrib4uiv
    static Function<void, glmixed::GLuint, const glmixed::GLuint *> VertexAttrib4uivARB; ///< Wrapper for glVertexAttrib4uivARB
    static Function<void, glmixed::GLuint, const glmixed::GLushort *> VertexAttrib4usv; ///< Wrapper for glVertexAttrib4usv
    static Function<void, glmixed::GLuint, const glmixed::GLushort *> VertexAttrib4usvARB; ///< Wrapper for glVertexAttrib4usvARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLboolean, glmixed::GLsizei, glmixed::GLuint, glmixed::GLuint> VertexAttribArrayObjectATI; ///< Wrapper for glVertexAttribArrayObjectATI
    static Function<void, glmixed::GLuint, glmixed::GLuint> VertexAttribBinding; ///< Wrapper for glVertexAttribBinding
    static Function<void, glmixed::GLuint, glmixed::GLuint> VertexAttribDivisor; ///< Wrapper for glVertexAttribDivisor
    static Function<void, glmixed::GLuint, glmixed::GLuint> VertexAttribDivisorANGLE; ///< Wrapper for glVertexAttribDivisorANGLE
    static Function<void, glmixed::GLuint, glmixed::GLuint> VertexAttribDivisorARB; ///< Wrapper for glVertexAttribDivisorARB
    static Function<void, glmixed::GLuint, glmixed::GLuint> VertexAttribDivisorEXT; ///< Wrapper for glVertexAttribDivisorEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint> VertexAttribDivisorNV; ///< Wrapper for glVertexAttribDivisorNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLboolean, glmixed::GLuint> VertexAttribFormat; ///< Wrapper for glVertexAttribFormat
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLboolean, glmixed::GLsizei> VertexAttribFormatNV; ///< Wrapper for glVertexAttribFormatNV
    static Function<void, glmixed::GLuint, glmixed::GLint> VertexAttribI1i; ///< Wrapper for glVertexAttribI1i
    static Function<void, glmixed::GLuint, glmixed::GLint> VertexAttribI1iEXT; ///< Wrapper for glVertexAttribI1iEXT
    static Function<void, glmixed::GLuint, const glmixed::GLint *> VertexAttribI1iv; ///< Wrapper for glVertexAttribI1iv
    static Function<void, glmixed::GLuint, const glmixed::GLint *> VertexAttribI1ivEXT; ///< Wrapper for glVertexAttribI1ivEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint> VertexAttribI1ui; ///< Wrapper for glVertexAttribI1ui
    static Function<void, glmixed::GLuint, glmixed::GLuint> VertexAttribI1uiEXT; ///< Wrapper for glVertexAttribI1uiEXT
    static Function<void, glmixed::GLuint, const glmixed::GLuint *> VertexAttribI1uiv; ///< Wrapper for glVertexAttribI1uiv
    static Function<void, glmixed::GLuint, const glmixed::GLuint *> VertexAttribI1uivEXT; ///< Wrapper for glVertexAttribI1uivEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint> VertexAttribI2i; ///< Wrapper for glVertexAttribI2i
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint> VertexAttribI2iEXT; ///< Wrapper for glVertexAttribI2iEXT
    static Function<void, glmixed::GLuint, const glmixed::GLint *> VertexAttribI2iv; ///< Wrapper for glVertexAttribI2iv
    static Function<void, glmixed::GLuint, const glmixed::GLint *> VertexAttribI2ivEXT; ///< Wrapper for glVertexAttribI2ivEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> VertexAttribI2ui; ///< Wrapper for glVertexAttribI2ui
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> VertexAttribI2uiEXT; ///< Wrapper for glVertexAttribI2uiEXT
    static Function<void, glmixed::GLuint, const glmixed::GLuint *> VertexAttribI2uiv; ///< Wrapper for glVertexAttribI2uiv
    static Function<void, glmixed::GLuint, const glmixed::GLuint *> VertexAttribI2uivEXT; ///< Wrapper for glVertexAttribI2uivEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint> VertexAttribI3i; ///< Wrapper for glVertexAttribI3i
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint> VertexAttribI3iEXT; ///< Wrapper for glVertexAttribI3iEXT
    static Function<void, glmixed::GLuint, const glmixed::GLint *> VertexAttribI3iv; ///< Wrapper for glVertexAttribI3iv
    static Function<void, glmixed::GLuint, const glmixed::GLint *> VertexAttribI3ivEXT; ///< Wrapper for glVertexAttribI3ivEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> VertexAttribI3ui; ///< Wrapper for glVertexAttribI3ui
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> VertexAttribI3uiEXT; ///< Wrapper for glVertexAttribI3uiEXT
    static Function<void, glmixed::GLuint, const glmixed::GLuint *> VertexAttribI3uiv; ///< Wrapper for glVertexAttribI3uiv
    static Function<void, glmixed::GLuint, const glmixed::GLuint *> VertexAttribI3uivEXT; ///< Wrapper for glVertexAttribI3uivEXT
    static Function<void, glmixed::GLuint, const glmixed::GLbyte *> VertexAttribI4bv; ///< Wrapper for glVertexAttribI4bv
    static Function<void, glmixed::GLuint, const glmixed::GLbyte *> VertexAttribI4bvEXT; ///< Wrapper for glVertexAttribI4bvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> VertexAttribI4i; ///< Wrapper for glVertexAttribI4i
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> VertexAttribI4iEXT; ///< Wrapper for glVertexAttribI4iEXT
    static Function<void, glmixed::GLuint, const glmixed::GLint *> VertexAttribI4iv; ///< Wrapper for glVertexAttribI4iv
    static Function<void, glmixed::GLuint, const glmixed::GLint *> VertexAttribI4ivEXT; ///< Wrapper for glVertexAttribI4ivEXT
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VertexAttribI4sv; ///< Wrapper for glVertexAttribI4sv
    static Function<void, glmixed::GLuint, const glmixed::GLshort *> VertexAttribI4svEXT; ///< Wrapper for glVertexAttribI4svEXT
    static Function<void, glmixed::GLuint, const glmixed::GLubyte *> VertexAttribI4ubv; ///< Wrapper for glVertexAttribI4ubv
    static Function<void, glmixed::GLuint, const glmixed::GLubyte *> VertexAttribI4ubvEXT; ///< Wrapper for glVertexAttribI4ubvEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> VertexAttribI4ui; ///< Wrapper for glVertexAttribI4ui
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint, glmixed::GLuint> VertexAttribI4uiEXT; ///< Wrapper for glVertexAttribI4uiEXT
    static Function<void, glmixed::GLuint, const glmixed::GLuint *> VertexAttribI4uiv; ///< Wrapper for glVertexAttribI4uiv
    static Function<void, glmixed::GLuint, const glmixed::GLuint *> VertexAttribI4uivEXT; ///< Wrapper for glVertexAttribI4uivEXT
    static Function<void, glmixed::GLuint, const glmixed::GLushort *> VertexAttribI4usv; ///< Wrapper for glVertexAttribI4usv
    static Function<void, glmixed::GLuint, const glmixed::GLushort *> VertexAttribI4usvEXT; ///< Wrapper for glVertexAttribI4usvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLuint> VertexAttribIFormat; ///< Wrapper for glVertexAttribIFormat
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei> VertexAttribIFormatNV; ///< Wrapper for glVertexAttribIFormatNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, const void *> VertexAttribIPointer; ///< Wrapper for glVertexAttribIPointer
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, const void *> VertexAttribIPointerEXT; ///< Wrapper for glVertexAttribIPointerEXT
    static Function<void, glmixed::GLuint, glmixed::GLdouble> VertexAttribL1d; ///< Wrapper for glVertexAttribL1d
    static Function<void, glmixed::GLuint, glmixed::GLdouble> VertexAttribL1dEXT; ///< Wrapper for glVertexAttribL1dEXT
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttribL1dv; ///< Wrapper for glVertexAttribL1dv
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttribL1dvEXT; ///< Wrapper for glVertexAttribL1dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint64EXT> VertexAttribL1i64NV; ///< Wrapper for glVertexAttribL1i64NV
    static Function<void, glmixed::GLuint, const glmixed::GLint64EXT *> VertexAttribL1i64vNV; ///< Wrapper for glVertexAttribL1i64vNV
    static Function<void, glmixed::GLuint, glmixed::GLuint64EXT> VertexAttribL1ui64ARB; ///< Wrapper for glVertexAttribL1ui64ARB
    static Function<void, glmixed::GLuint, glmixed::GLuint64EXT> VertexAttribL1ui64NV; ///< Wrapper for glVertexAttribL1ui64NV
    static Function<void, glmixed::GLuint, const glmixed::GLuint64EXT *> VertexAttribL1ui64vARB; ///< Wrapper for glVertexAttribL1ui64vARB
    static Function<void, glmixed::GLuint, const glmixed::GLuint64EXT *> VertexAttribL1ui64vNV; ///< Wrapper for glVertexAttribL1ui64vNV
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble> VertexAttribL2d; ///< Wrapper for glVertexAttribL2d
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble> VertexAttribL2dEXT; ///< Wrapper for glVertexAttribL2dEXT
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttribL2dv; ///< Wrapper for glVertexAttribL2dv
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttribL2dvEXT; ///< Wrapper for glVertexAttribL2dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint64EXT, glmixed::GLint64EXT> VertexAttribL2i64NV; ///< Wrapper for glVertexAttribL2i64NV
    static Function<void, glmixed::GLuint, const glmixed::GLint64EXT *> VertexAttribL2i64vNV; ///< Wrapper for glVertexAttribL2i64vNV
    static Function<void, glmixed::GLuint, glmixed::GLuint64EXT, glmixed::GLuint64EXT> VertexAttribL2ui64NV; ///< Wrapper for glVertexAttribL2ui64NV
    static Function<void, glmixed::GLuint, const glmixed::GLuint64EXT *> VertexAttribL2ui64vNV; ///< Wrapper for glVertexAttribL2ui64vNV
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> VertexAttribL3d; ///< Wrapper for glVertexAttribL3d
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> VertexAttribL3dEXT; ///< Wrapper for glVertexAttribL3dEXT
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttribL3dv; ///< Wrapper for glVertexAttribL3dv
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttribL3dvEXT; ///< Wrapper for glVertexAttribL3dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint64EXT, glmixed::GLint64EXT, glmixed::GLint64EXT> VertexAttribL3i64NV; ///< Wrapper for glVertexAttribL3i64NV
    static Function<void, glmixed::GLuint, const glmixed::GLint64EXT *> VertexAttribL3i64vNV; ///< Wrapper for glVertexAttribL3i64vNV
    static Function<void, glmixed::GLuint, glmixed::GLuint64EXT, glmixed::GLuint64EXT, glmixed::GLuint64EXT> VertexAttribL3ui64NV; ///< Wrapper for glVertexAttribL3ui64NV
    static Function<void, glmixed::GLuint, const glmixed::GLuint64EXT *> VertexAttribL3ui64vNV; ///< Wrapper for glVertexAttribL3ui64vNV
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> VertexAttribL4d; ///< Wrapper for glVertexAttribL4d
    static Function<void, glmixed::GLuint, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> VertexAttribL4dEXT; ///< Wrapper for glVertexAttribL4dEXT
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttribL4dv; ///< Wrapper for glVertexAttribL4dv
    static Function<void, glmixed::GLuint, const glmixed::GLdouble *> VertexAttribL4dvEXT; ///< Wrapper for glVertexAttribL4dvEXT
    static Function<void, glmixed::GLuint, glmixed::GLint64EXT, glmixed::GLint64EXT, glmixed::GLint64EXT, glmixed::GLint64EXT> VertexAttribL4i64NV; ///< Wrapper for glVertexAttribL4i64NV
    static Function<void, glmixed::GLuint, const glmixed::GLint64EXT *> VertexAttribL4i64vNV; ///< Wrapper for glVertexAttribL4i64vNV
    static Function<void, glmixed::GLuint, glmixed::GLuint64EXT, glmixed::GLuint64EXT, glmixed::GLuint64EXT, glmixed::GLuint64EXT> VertexAttribL4ui64NV; ///< Wrapper for glVertexAttribL4ui64NV
    static Function<void, glmixed::GLuint, const glmixed::GLuint64EXT *> VertexAttribL4ui64vNV; ///< Wrapper for glVertexAttribL4ui64vNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLuint> VertexAttribLFormat; ///< Wrapper for glVertexAttribLFormat
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei> VertexAttribLFormatNV; ///< Wrapper for glVertexAttribLFormatNV
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, const void *> VertexAttribLPointer; ///< Wrapper for glVertexAttribLPointer
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, const void *> VertexAttribLPointerEXT; ///< Wrapper for glVertexAttribLPointerEXT
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLboolean, glmixed::GLuint> VertexAttribP1ui; ///< Wrapper for glVertexAttribP1ui
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLboolean, const glmixed::GLuint *> VertexAttribP1uiv; ///< Wrapper for glVertexAttribP1uiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLboolean, glmixed::GLuint> VertexAttribP2ui; ///< Wrapper for glVertexAttribP2ui
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLboolean, const glmixed::GLuint *> VertexAttribP2uiv; ///< Wrapper for glVertexAttribP2uiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLboolean, glmixed::GLuint> VertexAttribP3ui; ///< Wrapper for glVertexAttribP3ui
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLboolean, const glmixed::GLuint *> VertexAttribP3uiv; ///< Wrapper for glVertexAttribP3uiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLboolean, glmixed::GLuint> VertexAttribP4ui; ///< Wrapper for glVertexAttribP4ui
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLboolean, const glmixed::GLuint *> VertexAttribP4uiv; ///< Wrapper for glVertexAttribP4uiv
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLint> VertexAttribParameteriAMD; ///< Wrapper for glVertexAttribParameteriAMD
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLboolean, glmixed::GLsizei, const void *> VertexAttribPointer; ///< Wrapper for glVertexAttribPointer
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLboolean, glmixed::GLsizei, const void *> VertexAttribPointerARB; ///< Wrapper for glVertexAttribPointerARB
    static Function<void, glmixed::GLuint, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, const void *> VertexAttribPointerNV; ///< Wrapper for glVertexAttribPointerNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLdouble *> VertexAttribs1dvNV; ///< Wrapper for glVertexAttribs1dvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> VertexAttribs1fvNV; ///< Wrapper for glVertexAttribs1fvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLhalfNV *> VertexAttribs1hvNV; ///< Wrapper for glVertexAttribs1hvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLshort *> VertexAttribs1svNV; ///< Wrapper for glVertexAttribs1svNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLdouble *> VertexAttribs2dvNV; ///< Wrapper for glVertexAttribs2dvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> VertexAttribs2fvNV; ///< Wrapper for glVertexAttribs2fvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLhalfNV *> VertexAttribs2hvNV; ///< Wrapper for glVertexAttribs2hvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLshort *> VertexAttribs2svNV; ///< Wrapper for glVertexAttribs2svNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLdouble *> VertexAttribs3dvNV; ///< Wrapper for glVertexAttribs3dvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> VertexAttribs3fvNV; ///< Wrapper for glVertexAttribs3fvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLhalfNV *> VertexAttribs3hvNV; ///< Wrapper for glVertexAttribs3hvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLshort *> VertexAttribs3svNV; ///< Wrapper for glVertexAttribs3svNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLdouble *> VertexAttribs4dvNV; ///< Wrapper for glVertexAttribs4dvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> VertexAttribs4fvNV; ///< Wrapper for glVertexAttribs4fvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLhalfNV *> VertexAttribs4hvNV; ///< Wrapper for glVertexAttribs4hvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLshort *> VertexAttribs4svNV; ///< Wrapper for glVertexAttribs4svNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLubyte *> VertexAttribs4ubvNV; ///< Wrapper for glVertexAttribs4ubvNV
    static Function<void, glmixed::GLuint, glmixed::GLuint> VertexBindingDivisor; ///< Wrapper for glVertexBindingDivisor
    static Function<void, glmixed::GLint> VertexBlendARB; ///< Wrapper for glVertexBlendARB
    static Function<void, glmixed::GLenum, glmixed::GLfloat> VertexBlendEnvfATI; ///< Wrapper for glVertexBlendEnvfATI
    static Function<void, glmixed::GLenum, glmixed::GLint> VertexBlendEnviATI; ///< Wrapper for glVertexBlendEnviATI
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei> VertexFormatNV; ///< Wrapper for glVertexFormatNV
    static Function<void, glmixed::GLenum, glmixed::GLuint> VertexP2ui; ///< Wrapper for glVertexP2ui
    static Function<void, glmixed::GLenum, const glmixed::GLuint *> VertexP2uiv; ///< Wrapper for glVertexP2uiv
    static Function<void, glmixed::GLenum, glmixed::GLuint> VertexP3ui; ///< Wrapper for glVertexP3ui
    static Function<void, glmixed::GLenum, const glmixed::GLuint *> VertexP3uiv; ///< Wrapper for glVertexP3uiv
    static Function<void, glmixed::GLenum, glmixed::GLuint> VertexP4ui; ///< Wrapper for glVertexP4ui
    static Function<void, glmixed::GLenum, const glmixed::GLuint *> VertexP4uiv; ///< Wrapper for glVertexP4uiv
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, const void *> VertexPointer; ///< Wrapper for glVertexPointer
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, glmixed::GLsizei, const void *> VertexPointerEXT; ///< Wrapper for glVertexPointerEXT
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLint, const void **, glmixed::GLint> VertexPointerListIBM; ///< Wrapper for glVertexPointerListIBM
    static Function<void, glmixed::GLint, glmixed::GLenum, const void **> VertexPointervINTEL; ///< Wrapper for glVertexPointervINTEL
    static Function<void, glmixed::GLenum, glmixed::GLdouble> VertexStream1dATI; ///< Wrapper for glVertexStream1dATI
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> VertexStream1dvATI; ///< Wrapper for glVertexStream1dvATI
    static Function<void, glmixed::GLenum, glmixed::GLfloat> VertexStream1fATI; ///< Wrapper for glVertexStream1fATI
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> VertexStream1fvATI; ///< Wrapper for glVertexStream1fvATI
    static Function<void, glmixed::GLenum, glmixed::GLint> VertexStream1iATI; ///< Wrapper for glVertexStream1iATI
    static Function<void, glmixed::GLenum, const glmixed::GLint *> VertexStream1ivATI; ///< Wrapper for glVertexStream1ivATI
    static Function<void, glmixed::GLenum, glmixed::GLshort> VertexStream1sATI; ///< Wrapper for glVertexStream1sATI
    static Function<void, glmixed::GLenum, const glmixed::GLshort *> VertexStream1svATI; ///< Wrapper for glVertexStream1svATI
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble> VertexStream2dATI; ///< Wrapper for glVertexStream2dATI
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> VertexStream2dvATI; ///< Wrapper for glVertexStream2dvATI
    static Function<void, glmixed::GLenum, glmixed::GLfloat, glmixed::GLfloat> VertexStream2fATI; ///< Wrapper for glVertexStream2fATI
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> VertexStream2fvATI; ///< Wrapper for glVertexStream2fvATI
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint> VertexStream2iATI; ///< Wrapper for glVertexStream2iATI
    static Function<void, glmixed::GLenum, const glmixed::GLint *> VertexStream2ivATI; ///< Wrapper for glVertexStream2ivATI
    static Function<void, glmixed::GLenum, glmixed::GLshort, glmixed::GLshort> VertexStream2sATI; ///< Wrapper for glVertexStream2sATI
    static Function<void, glmixed::GLenum, const glmixed::GLshort *> VertexStream2svATI; ///< Wrapper for glVertexStream2svATI
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> VertexStream3dATI; ///< Wrapper for glVertexStream3dATI
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> VertexStream3dvATI; ///< Wrapper for glVertexStream3dvATI
    static Function<void, glmixed::GLenum, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> VertexStream3fATI; ///< Wrapper for glVertexStream3fATI
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> VertexStream3fvATI; ///< Wrapper for glVertexStream3fvATI
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint> VertexStream3iATI; ///< Wrapper for glVertexStream3iATI
    static Function<void, glmixed::GLenum, const glmixed::GLint *> VertexStream3ivATI; ///< Wrapper for glVertexStream3ivATI
    static Function<void, glmixed::GLenum, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> VertexStream3sATI; ///< Wrapper for glVertexStream3sATI
    static Function<void, glmixed::GLenum, const glmixed::GLshort *> VertexStream3svATI; ///< Wrapper for glVertexStream3svATI
    static Function<void, glmixed::GLenum, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> VertexStream4dATI; ///< Wrapper for glVertexStream4dATI
    static Function<void, glmixed::GLenum, const glmixed::GLdouble *> VertexStream4dvATI; ///< Wrapper for glVertexStream4dvATI
    static Function<void, glmixed::GLenum, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> VertexStream4fATI; ///< Wrapper for glVertexStream4fATI
    static Function<void, glmixed::GLenum, const glmixed::GLfloat *> VertexStream4fvATI; ///< Wrapper for glVertexStream4fvATI
    static Function<void, glmixed::GLenum, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> VertexStream4iATI; ///< Wrapper for glVertexStream4iATI
    static Function<void, glmixed::GLenum, const glmixed::GLint *> VertexStream4ivATI; ///< Wrapper for glVertexStream4ivATI
    static Function<void, glmixed::GLenum, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> VertexStream4sATI; ///< Wrapper for glVertexStream4sATI
    static Function<void, glmixed::GLenum, const glmixed::GLshort *> VertexStream4svATI; ///< Wrapper for glVertexStream4svATI
    static Function<void, glmixed::GLfloat> VertexWeightfEXT; ///< Wrapper for glVertexWeightfEXT
    static Function<void, const glmixed::GLfloat *> VertexWeightfvEXT; ///< Wrapper for glVertexWeightfvEXT
    static Function<void, glmixed::GLhalfNV> VertexWeighthNV; ///< Wrapper for glVertexWeighthNV
    static Function<void, const glmixed::GLhalfNV *> VertexWeighthvNV; ///< Wrapper for glVertexWeighthvNV
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, const void *> VertexWeightPointerEXT; ///< Wrapper for glVertexWeightPointerEXT
    static Function<glmixed::GLenum, glmixed::GLuint, glmixed::GLuint *, glmixed::GLuint64EXT *> VideoCaptureNV; ///< Wrapper for glVideoCaptureNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, const glmixed::GLdouble *> VideoCaptureStreamParameterdvNV; ///< Wrapper for glVideoCaptureStreamParameterdvNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, const glmixed::GLfloat *> VideoCaptureStreamParameterfvNV; ///< Wrapper for glVideoCaptureStreamParameterfvNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::GLenum, const glmixed::GLint *> VideoCaptureStreamParameterivNV; ///< Wrapper for glVideoCaptureStreamParameterivNV
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLsizei, glmixed::GLsizei> Viewport; ///< Wrapper for glViewport
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> ViewportArrayv; ///< Wrapper for glViewportArrayv
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> ViewportArrayvNV; ///< Wrapper for glViewportArrayvNV
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLfloat *> ViewportArrayvOES; ///< Wrapper for glViewportArrayvOES
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ViewportIndexedf; ///< Wrapper for glViewportIndexedf
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ViewportIndexedfNV; ///< Wrapper for glViewportIndexedfNV
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> ViewportIndexedfOES; ///< Wrapper for glViewportIndexedfOES
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> ViewportIndexedfv; ///< Wrapper for glViewportIndexedfv
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> ViewportIndexedfvNV; ///< Wrapper for glViewportIndexedfvNV
    static Function<void, glmixed::GLuint, const glmixed::GLfloat *> ViewportIndexedfvOES; ///< Wrapper for glViewportIndexedfvOES
    static Function<void, glmixed::GLuint, glmixed::GLfloat, glmixed::GLfloat> ViewportPositionWScaleNV; ///< Wrapper for glViewportPositionWScaleNV
    static Function<void, glmixed::GLuint, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum, glmixed::GLenum> ViewportSwizzleNV; ///< Wrapper for glViewportSwizzleNV
    static Function<void, glmixed::GLuint, glmixed::GLuint, const glmixed::GLuint *, glmixed::GLuint, const glmixed::GLuint *, const glmixed::GLenum *> WaitSemaphoreEXT; ///< Wrapper for glWaitSemaphoreEXT
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *, const glmixed::GLuint64 *> WaitSemaphoreui64NVX; ///< Wrapper for glWaitSemaphoreui64NVX
    static Function<void, glmixed::GLsync, glmixed::GLbitfield, glmixed::GLuint64> WaitSync; ///< Wrapper for glWaitSync
    static Function<void, glmixed::GLsync, glmixed::GLbitfield, glmixed::GLuint64> WaitSyncAPPLE; ///< Wrapper for glWaitSyncAPPLE
    static Function<void, glmixed::GLuint64> WaitVkSemaphoreNV; ///< Wrapper for glWaitVkSemaphoreNV
    static Function<void, glmixed::GLint, const glmixed::GLbyte *> WeightbvARB; ///< Wrapper for glWeightbvARB
    static Function<void, glmixed::GLint, const glmixed::GLdouble *> WeightdvARB; ///< Wrapper for glWeightdvARB
    static Function<void, glmixed::GLint, const glmixed::GLfloat *> WeightfvARB; ///< Wrapper for glWeightfvARB
    static Function<void, glmixed::GLint, const glmixed::GLint *> WeightivARB; ///< Wrapper for glWeightivARB
    static Function<void, glmixed::GLuint, glmixed::GLsizei, const glmixed::GLuint *, const glmixed::GLfloat *> WeightPathsNV; ///< Wrapper for glWeightPathsNV
    static Function<void, glmixed::GLint, glmixed::GLenum, glmixed::GLsizei, const void *> WeightPointerARB; ///< Wrapper for glWeightPointerARB
    static Function<void, glmixed::GLint, const glmixed::GLshort *> WeightsvARB; ///< Wrapper for glWeightsvARB
    static Function<void, glmixed::GLint, const glmixed::GLubyte *> WeightubvARB; ///< Wrapper for glWeightubvARB
    static Function<void, glmixed::GLint, const glmixed::GLuint *> WeightuivARB; ///< Wrapper for glWeightuivARB
    static Function<void, glmixed::GLint, const glmixed::GLushort *> WeightusvARB; ///< Wrapper for glWeightusvARB
    static Function<void, glmixed::GLdouble, glmixed::GLdouble> WindowPos2d; ///< Wrapper for glWindowPos2d
    static Function<void, glmixed::GLdouble, glmixed::GLdouble> WindowPos2dARB; ///< Wrapper for glWindowPos2dARB
    static Function<void, glmixed::GLdouble, glmixed::GLdouble> WindowPos2dMESA; ///< Wrapper for glWindowPos2dMESA
    static Function<void, const glmixed::GLdouble *> WindowPos2dv; ///< Wrapper for glWindowPos2dv
    static Function<void, const glmixed::GLdouble *> WindowPos2dvARB; ///< Wrapper for glWindowPos2dvARB
    static Function<void, const glmixed::GLdouble *> WindowPos2dvMESA; ///< Wrapper for glWindowPos2dvMESA
    static Function<void, glmixed::GLfloat, glmixed::GLfloat> WindowPos2f; ///< Wrapper for glWindowPos2f
    static Function<void, glmixed::GLfloat, glmixed::GLfloat> WindowPos2fARB; ///< Wrapper for glWindowPos2fARB
    static Function<void, glmixed::GLfloat, glmixed::GLfloat> WindowPos2fMESA; ///< Wrapper for glWindowPos2fMESA
    static Function<void, const glmixed::GLfloat *> WindowPos2fv; ///< Wrapper for glWindowPos2fv
    static Function<void, const glmixed::GLfloat *> WindowPos2fvARB; ///< Wrapper for glWindowPos2fvARB
    static Function<void, const glmixed::GLfloat *> WindowPos2fvMESA; ///< Wrapper for glWindowPos2fvMESA
    static Function<void, glmixed::GLint, glmixed::GLint> WindowPos2i; ///< Wrapper for glWindowPos2i
    static Function<void, glmixed::GLint, glmixed::GLint> WindowPos2iARB; ///< Wrapper for glWindowPos2iARB
    static Function<void, glmixed::GLint, glmixed::GLint> WindowPos2iMESA; ///< Wrapper for glWindowPos2iMESA
    static Function<void, const glmixed::GLint *> WindowPos2iv; ///< Wrapper for glWindowPos2iv
    static Function<void, const glmixed::GLint *> WindowPos2ivARB; ///< Wrapper for glWindowPos2ivARB
    static Function<void, const glmixed::GLint *> WindowPos2ivMESA; ///< Wrapper for glWindowPos2ivMESA
    static Function<void, glmixed::GLshort, glmixed::GLshort> WindowPos2s; ///< Wrapper for glWindowPos2s
    static Function<void, glmixed::GLshort, glmixed::GLshort> WindowPos2sARB; ///< Wrapper for glWindowPos2sARB
    static Function<void, glmixed::GLshort, glmixed::GLshort> WindowPos2sMESA; ///< Wrapper for glWindowPos2sMESA
    static Function<void, const glmixed::GLshort *> WindowPos2sv; ///< Wrapper for glWindowPos2sv
    static Function<void, const glmixed::GLshort *> WindowPos2svARB; ///< Wrapper for glWindowPos2svARB
    static Function<void, const glmixed::GLshort *> WindowPos2svMESA; ///< Wrapper for glWindowPos2svMESA
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> WindowPos3d; ///< Wrapper for glWindowPos3d
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> WindowPos3dARB; ///< Wrapper for glWindowPos3dARB
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> WindowPos3dMESA; ///< Wrapper for glWindowPos3dMESA
    static Function<void, const glmixed::GLdouble *> WindowPos3dv; ///< Wrapper for glWindowPos3dv
    static Function<void, const glmixed::GLdouble *> WindowPos3dvARB; ///< Wrapper for glWindowPos3dvARB
    static Function<void, const glmixed::GLdouble *> WindowPos3dvMESA; ///< Wrapper for glWindowPos3dvMESA
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> WindowPos3f; ///< Wrapper for glWindowPos3f
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> WindowPos3fARB; ///< Wrapper for glWindowPos3fARB
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> WindowPos3fMESA; ///< Wrapper for glWindowPos3fMESA
    static Function<void, const glmixed::GLfloat *> WindowPos3fv; ///< Wrapper for glWindowPos3fv
    static Function<void, const glmixed::GLfloat *> WindowPos3fvARB; ///< Wrapper for glWindowPos3fvARB
    static Function<void, const glmixed::GLfloat *> WindowPos3fvMESA; ///< Wrapper for glWindowPos3fvMESA
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint> WindowPos3i; ///< Wrapper for glWindowPos3i
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint> WindowPos3iARB; ///< Wrapper for glWindowPos3iARB
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint> WindowPos3iMESA; ///< Wrapper for glWindowPos3iMESA
    static Function<void, const glmixed::GLint *> WindowPos3iv; ///< Wrapper for glWindowPos3iv
    static Function<void, const glmixed::GLint *> WindowPos3ivARB; ///< Wrapper for glWindowPos3ivARB
    static Function<void, const glmixed::GLint *> WindowPos3ivMESA; ///< Wrapper for glWindowPos3ivMESA
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> WindowPos3s; ///< Wrapper for glWindowPos3s
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> WindowPos3sARB; ///< Wrapper for glWindowPos3sARB
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> WindowPos3sMESA; ///< Wrapper for glWindowPos3sMESA
    static Function<void, const glmixed::GLshort *> WindowPos3sv; ///< Wrapper for glWindowPos3sv
    static Function<void, const glmixed::GLshort *> WindowPos3svARB; ///< Wrapper for glWindowPos3svARB
    static Function<void, const glmixed::GLshort *> WindowPos3svMESA; ///< Wrapper for glWindowPos3svMESA
    static Function<void, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble, glmixed::GLdouble> WindowPos4dMESA; ///< Wrapper for glWindowPos4dMESA
    static Function<void, const glmixed::GLdouble *> WindowPos4dvMESA; ///< Wrapper for glWindowPos4dvMESA
    static Function<void, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat, glmixed::GLfloat> WindowPos4fMESA; ///< Wrapper for glWindowPos4fMESA
    static Function<void, const glmixed::GLfloat *> WindowPos4fvMESA; ///< Wrapper for glWindowPos4fvMESA
    static Function<void, glmixed::GLint, glmixed::GLint, glmixed::GLint, glmixed::GLint> WindowPos4iMESA; ///< Wrapper for glWindowPos4iMESA
    static Function<void, const glmixed::GLint *> WindowPos4ivMESA; ///< Wrapper for glWindowPos4ivMESA
    static Function<void, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort, glmixed::GLshort> WindowPos4sMESA; ///< Wrapper for glWindowPos4sMESA
    static Function<void, const glmixed::GLshort *> WindowPos4svMESA; ///< Wrapper for glWindowPos4svMESA
    static Function<void, glmixed::GLenum, glmixed::GLsizei, const glmixed::GLint *> WindowRectanglesEXT; ///< Wrapper for glWindowRectanglesEXT
    static Function<void, glmixed::GLuint, glmixed::GLuint, glmixed::VertexShaderWriteMaskEXT, glmixed::VertexShaderWriteMaskEXT, glmixed::VertexShaderWriteMaskEXT, glmixed::VertexShaderWriteMaskEXT> WriteMaskEXT; ///< Wrapper for glWriteMaskEXT


protected:
    /**
    *  @brief
    *    Provide an additional State
    *
    *  @param[in] pos
    *    Index of new State
    */
    static void provideState(int pos);

    /**
    *  @brief
    *    Neglect a previously provided state
    *
    *  @param[in] pos
    *    Index of State to neglect
    */
    static void neglectState(int pos);

    /**
    *  @brief
    *    Set current State
    *
    *  @param[in] pos
    *    Index of State
    */
    static void setStatePos(int pos);


protected:
    static const array_t s_functions;                                       ///< The list of all build-in functions
    static int & s_maxPos();                                                ///< Maximum State index in use
    static std::vector<AbstractFunction *> & s_additionalFunctions();       ///< List of additional OpenGL fucntions
    static std::vector<ContextSwitchCallback> & s_contextSwitchCallbacks(); ///< List of callbacks for context switch
    static SimpleFunctionCallback & s_unresolvedCallback();                 ///< Callback for unresolved functions
    static FunctionCallback & s_beforeCallback();                           ///< Callback for before function call
    static FunctionCallback & s_afterCallback();                            ///< Callback for after function call
    static FunctionLogCallback & s_logCallback();                           ///< Callback for logging a function call
    static int & s_pos();                                                   ///< Position of current State
    static ContextHandle & s_context();                                     ///< Handle of current context
    static glmixedbinding::GetProcAddress & s_getProcAddress();                  ///< Current address of function resolution method
    static std_boost::recursive_mutex & s_mutex();                          ///< Mutex
    static std::unordered_map<ContextHandle, int> & s_bindings();           ///< Map (handle->position) of initialized contexts
    static glmixedbinding::GetProcAddress & s_firstGetProcAddress();             ///< First address of function resolution method
};


} // namespace glmixedbinding