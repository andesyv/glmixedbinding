
#include "Binding_pch.h"


using namespace glmixed;


namespace glmixedbinding
{


Function<void, GLenum, GLfloat> Binding::Accum("glAccum");
Function<void, GLenum, GLfixed> Binding::AccumxOES("glAccumxOES");
Function<GLboolean, GLuint, GLuint64, GLuint> Binding::AcquireKeyedMutexWin32EXT("glAcquireKeyedMutexWin32EXT");
Function<void, GLuint> Binding::ActiveProgramEXT("glActiveProgramEXT");
Function<void, GLuint, GLuint> Binding::ActiveShaderProgram("glActiveShaderProgram");
Function<void, GLuint, GLuint> Binding::ActiveShaderProgramEXT("glActiveShaderProgramEXT");
Function<void, GLenum> Binding::ActiveStencilFaceEXT("glActiveStencilFaceEXT");
Function<void, GLenum> Binding::ActiveTexture("glActiveTexture");
Function<void, GLenum> Binding::ActiveTextureARB("glActiveTextureARB");
Function<void, GLuint, const GLchar *> Binding::ActiveVaryingNV("glActiveVaryingNV");
Function<void, GLenum, GLuint, FragmentShaderDestModMaskATI, GLuint, GLuint, FragmentShaderColorModMaskATI> Binding::AlphaFragmentOp1ATI("glAlphaFragmentOp1ATI");
Function<void, GLenum, GLuint, FragmentShaderDestModMaskATI, GLuint, GLuint, FragmentShaderColorModMaskATI, GLuint, GLuint, FragmentShaderColorModMaskATI> Binding::AlphaFragmentOp2ATI("glAlphaFragmentOp2ATI");
Function<void, GLenum, GLuint, FragmentShaderDestModMaskATI, GLuint, GLuint, FragmentShaderColorModMaskATI, GLuint, GLuint, FragmentShaderColorModMaskATI, GLuint, GLuint, FragmentShaderColorModMaskATI> Binding::AlphaFragmentOp3ATI("glAlphaFragmentOp3ATI");
Function<void, GLenum, GLfloat> Binding::AlphaFunc("glAlphaFunc");
Function<void, GLenum, GLclampf> Binding::AlphaFuncQCOM("glAlphaFuncQCOM");
Function<void, GLenum, GLfixed> Binding::AlphaFuncxOES("glAlphaFuncxOES");
Function<void, GLenum> Binding::AlphaToCoverageDitherControlNV("glAlphaToCoverageDitherControlNV");
Function<void> Binding::ApplyFramebufferAttachmentCMAAINTEL("glApplyFramebufferAttachmentCMAAINTEL");
Function<void, GLenum> Binding::ApplyTextureEXT("glApplyTextureEXT");
Function<GLboolean, GLsizei, const GLuint *, GLboolean *> Binding::AreProgramsResidentNV("glAreProgramsResidentNV");
Function<GLboolean, GLsizei, const GLuint *, GLboolean *> Binding::AreTexturesResident("glAreTexturesResident");
Function<GLboolean, GLsizei, const GLuint *, GLboolean *> Binding::AreTexturesResidentEXT("glAreTexturesResidentEXT");
Function<void, GLint> Binding::ArrayElement("glArrayElement");
Function<void, GLint> Binding::ArrayElementEXT("glArrayElementEXT");
Function<void, GLenum, GLint, GLenum, GLsizei, GLuint, GLuint> Binding::ArrayObjectATI("glArrayObjectATI");
Function<GLuint, GLsizei, const GLuint *, const GLuint64 *, GLuint, GLbitfield, GLuint, GLuint, GLintptr, GLintptr, GLsizeiptr, GLsizei, const GLuint *, const GLuint64 *> Binding::AsyncCopyBufferSubDataNVX("glAsyncCopyBufferSubDataNVX");
Function<GLuint, GLsizei, const GLuint *, const GLuint64 *, GLuint, GLbitfield, GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, const GLuint *, const GLuint64 *> Binding::AsyncCopyImageSubDataNVX("glAsyncCopyImageSubDataNVX");
Function<void, GLuint> Binding::AsyncMarkerSGIX("glAsyncMarkerSGIX");
Function<void, GLhandleARB, GLhandleARB> Binding::AttachObjectARB("glAttachObjectARB");
Function<void, GLuint, GLuint> Binding::AttachShader("glAttachShader");


} // namespace glmixedbinding