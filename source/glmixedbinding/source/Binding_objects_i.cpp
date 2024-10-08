
#include "Binding_pch.h"


using namespace glmixed;


namespace glmixedbinding
{


Function<void, GLenum, const void *> Binding::IglooInterfaceSGIX("glIglooInterfaceSGIX");
Function<void, GLenum, GLenum, GLfloat> Binding::ImageTransformParameterfHP("glImageTransformParameterfHP");
Function<void, GLenum, GLenum, const GLfloat *> Binding::ImageTransformParameterfvHP("glImageTransformParameterfvHP");
Function<void, GLenum, GLenum, GLint> Binding::ImageTransformParameteriHP("glImageTransformParameteriHP");
Function<void, GLenum, GLenum, const GLint *> Binding::ImageTransformParameterivHP("glImageTransformParameterivHP");
Function<void, GLuint, GLuint64, GLenum, GLint> Binding::ImportMemoryFdEXT("glImportMemoryFdEXT");
Function<void, GLuint, GLuint64, GLenum, void *> Binding::ImportMemoryWin32HandleEXT("glImportMemoryWin32HandleEXT");
Function<void, GLuint, GLuint64, GLenum, const void *> Binding::ImportMemoryWin32NameEXT("glImportMemoryWin32NameEXT");
Function<void, GLuint, GLenum, GLint> Binding::ImportSemaphoreFdEXT("glImportSemaphoreFdEXT");
Function<void, GLuint, GLenum, void *> Binding::ImportSemaphoreWin32HandleEXT("glImportSemaphoreWin32HandleEXT");
Function<void, GLuint, GLenum, const void *> Binding::ImportSemaphoreWin32NameEXT("glImportSemaphoreWin32NameEXT");
Function<GLsync, GLenum, GLintptr, GLbitfield> Binding::ImportSyncEXT("glImportSyncEXT");
Function<void, GLdouble> Binding::Indexd("glIndexd");
Function<void, const GLdouble *> Binding::Indexdv("glIndexdv");
Function<void, GLfloat> Binding::Indexf("glIndexf");
Function<void, GLenum, GLsizei> Binding::IndexFormatNV("glIndexFormatNV");
Function<void, GLenum, GLclampf> Binding::IndexFuncEXT("glIndexFuncEXT");
Function<void, const GLfloat *> Binding::Indexfv("glIndexfv");
Function<void, GLint> Binding::Indexi("glIndexi");
Function<void, const GLint *> Binding::Indexiv("glIndexiv");
Function<void, GLuint> Binding::IndexMask("glIndexMask");
Function<void, GLenum, GLenum> Binding::IndexMaterialEXT("glIndexMaterialEXT");
Function<void, GLenum, GLsizei, const void *> Binding::IndexPointer("glIndexPointer");
Function<void, GLenum, GLsizei, GLsizei, const void *> Binding::IndexPointerEXT("glIndexPointerEXT");
Function<void, GLenum, GLint, const void **, GLint> Binding::IndexPointerListIBM("glIndexPointerListIBM");
Function<void, GLshort> Binding::Indexs("glIndexs");
Function<void, const GLshort *> Binding::Indexsv("glIndexsv");
Function<void, GLubyte> Binding::Indexub("glIndexub");
Function<void, const GLubyte *> Binding::Indexubv("glIndexubv");
Function<void, GLfixed> Binding::IndexxOES("glIndexxOES");
Function<void, const GLfixed *> Binding::IndexxvOES("glIndexxvOES");
Function<void> Binding::InitNames("glInitNames");
Function<void, GLuint, GLuint, GLuint> Binding::InsertComponentEXT("glInsertComponentEXT");
Function<void, GLsizei, const GLchar *> Binding::InsertEventMarkerEXT("glInsertEventMarkerEXT");
Function<void, GLsizei, GLint *> Binding::InstrumentsBufferSGIX("glInstrumentsBufferSGIX");
Function<void, GLenum, GLsizei, const void *> Binding::InterleavedArrays("glInterleavedArrays");
Function<void, GLuint, GLuint, GLuint, GLfloat> Binding::InterpolatePathsNV("glInterpolatePathsNV");
Function<void, GLuint> Binding::InvalidateBufferData("glInvalidateBufferData");
Function<void, GLuint, GLintptr, GLsizeiptr> Binding::InvalidateBufferSubData("glInvalidateBufferSubData");
Function<void, GLenum, GLsizei, const GLenum *> Binding::InvalidateFramebuffer("glInvalidateFramebuffer");
Function<void, GLuint, GLsizei, const GLenum *> Binding::InvalidateNamedFramebufferData("glInvalidateNamedFramebufferData");
Function<void, GLuint, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei> Binding::InvalidateNamedFramebufferSubData("glInvalidateNamedFramebufferSubData");
Function<void, GLenum, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei> Binding::InvalidateSubFramebuffer("glInvalidateSubFramebuffer");
Function<void, GLuint, GLint> Binding::InvalidateTexImage("glInvalidateTexImage");
Function<void, GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei> Binding::InvalidateTexSubImage("glInvalidateTexSubImage");
Function<GLboolean, GLuint> Binding::IsAsyncMarkerSGIX("glIsAsyncMarkerSGIX");
Function<GLboolean, GLuint> Binding::IsBuffer("glIsBuffer");
Function<GLboolean, GLuint> Binding::IsBufferARB("glIsBufferARB");
Function<GLboolean, GLenum> Binding::IsBufferResidentNV("glIsBufferResidentNV");
Function<GLboolean, GLuint> Binding::IsCommandListNV("glIsCommandListNV");
Function<GLboolean, GLenum> Binding::IsEnabled("glIsEnabled");
Function<GLboolean, GLenum, GLuint> Binding::IsEnabledi("glIsEnabledi");
Function<GLboolean, GLenum, GLuint> Binding::IsEnablediEXT("glIsEnablediEXT");
Function<GLboolean, GLenum, GLuint> Binding::IsEnabledIndexedEXT("glIsEnabledIndexedEXT");
Function<GLboolean, GLenum, GLuint> Binding::IsEnablediNV("glIsEnablediNV");
Function<GLboolean, GLenum, GLuint> Binding::IsEnablediOES("glIsEnablediOES");
Function<GLboolean, GLuint> Binding::IsFenceAPPLE("glIsFenceAPPLE");
Function<GLboolean, GLuint> Binding::IsFenceNV("glIsFenceNV");
Function<GLboolean, GLuint> Binding::IsFramebuffer("glIsFramebuffer");
Function<GLboolean, GLuint> Binding::IsFramebufferEXT("glIsFramebufferEXT");
Function<GLboolean, GLuint64> Binding::IsImageHandleResidentARB("glIsImageHandleResidentARB");
Function<GLboolean, GLuint64> Binding::IsImageHandleResidentNV("glIsImageHandleResidentNV");
Function<GLboolean, GLuint> Binding::IsList("glIsList");
Function<GLboolean, GLuint> Binding::IsMemoryObjectEXT("glIsMemoryObjectEXT");
Function<GLboolean, GLenum, GLuint> Binding::IsNameAMD("glIsNameAMD");
Function<GLboolean, GLuint> Binding::IsNamedBufferResidentNV("glIsNamedBufferResidentNV");
Function<GLboolean, GLint, const GLchar *> Binding::IsNamedStringARB("glIsNamedStringARB");
Function<GLboolean, GLuint> Binding::IsObjectBufferATI("glIsObjectBufferATI");
Function<GLboolean, GLuint> Binding::IsOcclusionQueryNV("glIsOcclusionQueryNV");
Function<GLboolean, GLuint> Binding::IsPathNV("glIsPathNV");
Function<GLboolean, GLuint, GLuint, GLfloat, GLfloat> Binding::IsPointInFillPathNV("glIsPointInFillPathNV");
Function<GLboolean, GLuint, GLfloat, GLfloat> Binding::IsPointInStrokePathNV("glIsPointInStrokePathNV");
Function<GLboolean, GLuint> Binding::IsProgram("glIsProgram");
Function<GLboolean, GLuint> Binding::IsProgramARB("glIsProgramARB");
Function<GLboolean, GLuint> Binding::IsProgramNV("glIsProgramNV");
Function<GLboolean, GLuint> Binding::IsProgramPipeline("glIsProgramPipeline");
Function<GLboolean, GLuint> Binding::IsProgramPipelineEXT("glIsProgramPipelineEXT");
Function<GLboolean, GLuint> Binding::IsQuery("glIsQuery");
Function<GLboolean, GLuint> Binding::IsQueryARB("glIsQueryARB");
Function<GLboolean, GLuint> Binding::IsQueryEXT("glIsQueryEXT");
Function<GLboolean, GLuint> Binding::IsRenderbuffer("glIsRenderbuffer");
Function<GLboolean, GLuint> Binding::IsRenderbufferEXT("glIsRenderbufferEXT");
Function<GLboolean, GLuint> Binding::IsSampler("glIsSampler");
Function<GLboolean, GLuint> Binding::IsSemaphoreEXT("glIsSemaphoreEXT");
Function<GLboolean, GLuint> Binding::IsShader("glIsShader");
Function<GLboolean, GLuint> Binding::IsStateNV("glIsStateNV");
Function<GLboolean, GLsync> Binding::IsSync("glIsSync");
Function<GLboolean, GLsync> Binding::IsSyncAPPLE("glIsSyncAPPLE");
Function<GLboolean, GLuint> Binding::IsTexture("glIsTexture");
Function<GLboolean, GLuint> Binding::IsTextureEXT("glIsTextureEXT");
Function<GLboolean, GLuint64> Binding::IsTextureHandleResidentARB("glIsTextureHandleResidentARB");
Function<GLboolean, GLuint64> Binding::IsTextureHandleResidentNV("glIsTextureHandleResidentNV");
Function<GLboolean, GLuint> Binding::IsTransformFeedback("glIsTransformFeedback");
Function<GLboolean, GLuint> Binding::IsTransformFeedbackNV("glIsTransformFeedbackNV");
Function<GLboolean, GLuint, GLenum> Binding::IsVariantEnabledEXT("glIsVariantEnabledEXT");
Function<GLboolean, GLuint> Binding::IsVertexArray("glIsVertexArray");
Function<GLboolean, GLuint> Binding::IsVertexArrayAPPLE("glIsVertexArrayAPPLE");
Function<GLboolean, GLuint> Binding::IsVertexArrayOES("glIsVertexArrayOES");
Function<GLboolean, GLuint, GLenum> Binding::IsVertexAttribEnabledAPPLE("glIsVertexAttribEnabledAPPLE");


} // namespace glmixedbinding