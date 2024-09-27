
#include "../Binding_pch.h"

#include <glmixedbinding/glmixed/functions.h>


namespace glmixed
{


GLuint glGenAsyncMarkersSGIX(GLsizei range)
{
    return glmixedbinding::Binding::GenAsyncMarkersSGIX(range);
}

void glGenBuffers(GLsizei n, GLuint * buffers)
{
    return glmixedbinding::Binding::GenBuffers(n, buffers);
}

void glGenBuffersARB(GLsizei n, GLuint * buffers)
{
    return glmixedbinding::Binding::GenBuffersARB(n, buffers);
}

void glGenerateMipmap(GLenum target)
{
    return glmixedbinding::Binding::GenerateMipmap(target);
}

void glGenerateMipmapEXT(GLenum target)
{
    return glmixedbinding::Binding::GenerateMipmapEXT(target);
}

void glGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target)
{
    return glmixedbinding::Binding::GenerateMultiTexMipmapEXT(texunit, target);
}

void glGenerateTextureMipmap(GLuint texture)
{
    return glmixedbinding::Binding::GenerateTextureMipmap(texture);
}

void glGenerateTextureMipmapEXT(GLuint texture, GLenum target)
{
    return glmixedbinding::Binding::GenerateTextureMipmapEXT(texture, target);
}

void glGenFencesAPPLE(GLsizei n, GLuint * fences)
{
    return glmixedbinding::Binding::GenFencesAPPLE(n, fences);
}

void glGenFencesNV(GLsizei n, GLuint * fences)
{
    return glmixedbinding::Binding::GenFencesNV(n, fences);
}

GLuint glGenFragmentShadersATI(GLuint range)
{
    return glmixedbinding::Binding::GenFragmentShadersATI(range);
}

void glGenFramebuffers(GLsizei n, GLuint * framebuffers)
{
    return glmixedbinding::Binding::GenFramebuffers(n, framebuffers);
}

void glGenFramebuffersEXT(GLsizei n, GLuint * framebuffers)
{
    return glmixedbinding::Binding::GenFramebuffersEXT(n, framebuffers);
}

GLuint glGenLists(GLsizei range)
{
    return glmixedbinding::Binding::GenLists(range);
}

void glGenNamesAMD(GLenum identifier, GLuint num, GLuint * names)
{
    return glmixedbinding::Binding::GenNamesAMD(identifier, num, names);
}

void glGenOcclusionQueriesNV(GLsizei n, GLuint * ids)
{
    return glmixedbinding::Binding::GenOcclusionQueriesNV(n, ids);
}

GLuint glGenPathsNV(GLsizei range)
{
    return glmixedbinding::Binding::GenPathsNV(range);
}

void glGenPerfMonitorsAMD(GLsizei n, GLuint * monitors)
{
    return glmixedbinding::Binding::GenPerfMonitorsAMD(n, monitors);
}

void glGenProgramPipelines(GLsizei n, GLuint * pipelines)
{
    return glmixedbinding::Binding::GenProgramPipelines(n, pipelines);
}

void glGenProgramPipelinesEXT(GLsizei n, GLuint * pipelines)
{
    return glmixedbinding::Binding::GenProgramPipelinesEXT(n, pipelines);
}

void glGenProgramsARB(GLsizei n, GLuint * programs)
{
    return glmixedbinding::Binding::GenProgramsARB(n, programs);
}

void glGenProgramsNV(GLsizei n, GLuint * programs)
{
    return glmixedbinding::Binding::GenProgramsNV(n, programs);
}

void glGenQueries(GLsizei n, GLuint * ids)
{
    return glmixedbinding::Binding::GenQueries(n, ids);
}

void glGenQueriesARB(GLsizei n, GLuint * ids)
{
    return glmixedbinding::Binding::GenQueriesARB(n, ids);
}

void glGenQueriesEXT(GLsizei n, GLuint * ids)
{
    return glmixedbinding::Binding::GenQueriesEXT(n, ids);
}

void glGenQueryResourceTagNV(GLsizei n, GLint * tagIds)
{
    return glmixedbinding::Binding::GenQueryResourceTagNV(n, tagIds);
}

void glGenRenderbuffers(GLsizei n, GLuint * renderbuffers)
{
    return glmixedbinding::Binding::GenRenderbuffers(n, renderbuffers);
}

void glGenRenderbuffersEXT(GLsizei n, GLuint * renderbuffers)
{
    return glmixedbinding::Binding::GenRenderbuffersEXT(n, renderbuffers);
}

void glGenSamplers(GLsizei count, GLuint * samplers)
{
    return glmixedbinding::Binding::GenSamplers(count, samplers);
}

void glGenSemaphoresEXT(GLsizei n, GLuint * semaphores)
{
    return glmixedbinding::Binding::GenSemaphoresEXT(n, semaphores);
}

GLuint glGenSymbolsEXT(GLenum datatype, GLenum storagetype, GLenum range, GLuint components)
{
    return glmixedbinding::Binding::GenSymbolsEXT(datatype, storagetype, range, components);
}

void glGenTextures(GLsizei n, GLuint * textures)
{
    return glmixedbinding::Binding::GenTextures(n, textures);
}

void glGenTexturesEXT(GLsizei n, GLuint * textures)
{
    return glmixedbinding::Binding::GenTexturesEXT(n, textures);
}

void glGenTransformFeedbacks(GLsizei n, GLuint * ids)
{
    return glmixedbinding::Binding::GenTransformFeedbacks(n, ids);
}

void glGenTransformFeedbacksNV(GLsizei n, GLuint * ids)
{
    return glmixedbinding::Binding::GenTransformFeedbacksNV(n, ids);
}

void glGenVertexArrays(GLsizei n, GLuint * arrays)
{
    return glmixedbinding::Binding::GenVertexArrays(n, arrays);
}

void glGenVertexArraysAPPLE(GLsizei n, GLuint * arrays)
{
    return glmixedbinding::Binding::GenVertexArraysAPPLE(n, arrays);
}

void glGenVertexArraysOES(GLsizei n, GLuint * arrays)
{
    return glmixedbinding::Binding::GenVertexArraysOES(n, arrays);
}

GLuint glGenVertexShadersEXT(GLuint range)
{
    return glmixedbinding::Binding::GenVertexShadersEXT(range);
}

void glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetActiveAtomicCounterBufferiv(program, bufferIndex, pname, params);
}

void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name)
{
    return glmixedbinding::Binding::GetActiveAttrib(program, index, bufSize, length, size, type, name);
}

void glGetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name)
{
    return glmixedbinding::Binding::GetActiveAttribARB(programObj, index, maxLength, length, size, type, name);
}

void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name)
{
    return glmixedbinding::Binding::GetActiveSubroutineName(program, shadertype, index, bufSize, length, name);
}

void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values)
{
    return glmixedbinding::Binding::GetActiveSubroutineUniformiv(program, shadertype, index, pname, values);
}

void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name)
{
    return glmixedbinding::Binding::GetActiveSubroutineUniformName(program, shadertype, index, bufSize, length, name);
}

void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name)
{
    return glmixedbinding::Binding::GetActiveUniform(program, index, bufSize, length, size, type, name);
}

void glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei * length, GLint * size, GLenum * type, GLcharARB * name)
{
    return glmixedbinding::Binding::GetActiveUniformARB(programObj, index, maxLength, length, size, type, name);
}

void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetActiveUniformBlockiv(program, uniformBlockIndex, pname, params);
}

void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName)
{
    return glmixedbinding::Binding::GetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}

void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName)
{
    return glmixedbinding::Binding::GetActiveUniformName(program, uniformIndex, bufSize, length, uniformName);
}

void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params);
}

void glGetActiveVaryingNV(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name)
{
    return glmixedbinding::Binding::GetActiveVaryingNV(program, index, bufSize, length, size, type, name);
}

void glGetArrayObjectfvATI(GLenum array, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetArrayObjectfvATI(array, pname, params);
}

void glGetArrayObjectivATI(GLenum array, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetArrayObjectivATI(array, pname, params);
}

void glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei * count, GLhandleARB * obj)
{
    return glmixedbinding::Binding::GetAttachedObjectsARB(containerObj, maxCount, count, obj);
}

void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders)
{
    return glmixedbinding::Binding::GetAttachedShaders(program, maxCount, count, shaders);
}

GLint glGetAttribLocation(GLuint program, const GLchar * name)
{
    return glmixedbinding::Binding::GetAttribLocation(program, name);
}

GLint glGetAttribLocationARB(GLhandleARB programObj, const GLcharARB * name)
{
    return glmixedbinding::Binding::GetAttribLocationARB(programObj, name);
}

void glGetBooleani_v(GLenum target, GLuint index, GLboolean * data)
{
    return glmixedbinding::Binding::GetBooleani_v(target, index, data);
}

void glGetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean * data)
{
    return glmixedbinding::Binding::GetBooleanIndexedvEXT(target, index, data);
}

void glGetBooleanv(GLenum pname, GLboolean * data)
{
    return glmixedbinding::Binding::GetBooleanv(pname, data);
}

void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 * params)
{
    return glmixedbinding::Binding::GetBufferParameteri64v(target, pname, params);
}

void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetBufferParameteriv(target, pname, params);
}

void glGetBufferParameterivARB(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetBufferParameterivARB(target, pname, params);
}

void glGetBufferParameterui64vNV(GLenum target, GLenum pname, GLuint64EXT * params)
{
    return glmixedbinding::Binding::GetBufferParameterui64vNV(target, pname, params);
}

void glGetBufferPointerv(GLenum target, GLenum pname, void ** params)
{
    return glmixedbinding::Binding::GetBufferPointerv(target, pname, params);
}

void glGetBufferPointervARB(GLenum target, GLenum pname, void ** params)
{
    return glmixedbinding::Binding::GetBufferPointervARB(target, pname, params);
}

void glGetBufferPointervOES(GLenum target, GLenum pname, void ** params)
{
    return glmixedbinding::Binding::GetBufferPointervOES(target, pname, params);
}

void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void * data)
{
    return glmixedbinding::Binding::GetBufferSubData(target, offset, size, data);
}

void glGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, void * data)
{
    return glmixedbinding::Binding::GetBufferSubDataARB(target, offset, size, data);
}

void glGetClipPlane(GLenum plane, GLdouble * equation)
{
    return glmixedbinding::Binding::GetClipPlane(plane, equation);
}

void glGetClipPlanefOES(GLenum plane, GLfloat * equation)
{
    return glmixedbinding::Binding::GetClipPlanefOES(plane, equation);
}

void glGetClipPlanexOES(GLenum plane, GLfixed * equation)
{
    return glmixedbinding::Binding::GetClipPlanexOES(plane, equation);
}

void glGetColorTable(GLenum target, GLenum format, GLenum type, void * table)
{
    return glmixedbinding::Binding::GetColorTable(target, format, type, table);
}

void glGetColorTableEXT(GLenum target, GLenum format, GLenum type, void * data)
{
    return glmixedbinding::Binding::GetColorTableEXT(target, format, type, data);
}

void glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetColorTableParameterfv(target, pname, params);
}

void glGetColorTableParameterfvEXT(GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetColorTableParameterfvEXT(target, pname, params);
}

void glGetColorTableParameterfvSGI(GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetColorTableParameterfvSGI(target, pname, params);
}

void glGetColorTableParameteriv(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetColorTableParameteriv(target, pname, params);
}

void glGetColorTableParameterivEXT(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetColorTableParameterivEXT(target, pname, params);
}

void glGetColorTableParameterivSGI(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetColorTableParameterivSGI(target, pname, params);
}

void glGetColorTableSGI(GLenum target, GLenum format, GLenum type, void * table)
{
    return glmixedbinding::Binding::GetColorTableSGI(target, format, type, table);
}

void glGetCombinerInputParameterfvNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetCombinerInputParameterfvNV(stage, portion, variable, pname, params);
}

void glGetCombinerInputParameterivNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetCombinerInputParameterivNV(stage, portion, variable, pname, params);
}

void glGetCombinerOutputParameterfvNV(GLenum stage, GLenum portion, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetCombinerOutputParameterfvNV(stage, portion, pname, params);
}

void glGetCombinerOutputParameterivNV(GLenum stage, GLenum portion, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetCombinerOutputParameterivNV(stage, portion, pname, params);
}

void glGetCombinerStageParameterfvNV(GLenum stage, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetCombinerStageParameterfvNV(stage, pname, params);
}

GLuint glGetCommandHeaderNV(GLenum tokenID, GLuint size)
{
    return glmixedbinding::Binding::GetCommandHeaderNV(tokenID, size);
}

void glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint lod, void * img)
{
    return glmixedbinding::Binding::GetCompressedMultiTexImageEXT(texunit, target, lod, img);
}

void glGetCompressedTexImage(GLenum target, GLint level, void * img)
{
    return glmixedbinding::Binding::GetCompressedTexImage(target, level, img);
}

void glGetCompressedTexImageARB(GLenum target, GLint level, void * img)
{
    return glmixedbinding::Binding::GetCompressedTexImageARB(target, level, img);
}

void glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void * pixels)
{
    return glmixedbinding::Binding::GetCompressedTextureImage(texture, level, bufSize, pixels);
}

void glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint lod, void * img)
{
    return glmixedbinding::Binding::GetCompressedTextureImageEXT(texture, target, lod, img);
}

void glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels)
{
    return glmixedbinding::Binding::GetCompressedTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
}

void glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, void * image)
{
    return glmixedbinding::Binding::GetConvolutionFilter(target, format, type, image);
}

void glGetConvolutionFilterEXT(GLenum target, GLenum format, GLenum type, void * image)
{
    return glmixedbinding::Binding::GetConvolutionFilterEXT(target, format, type, image);
}

void glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetConvolutionParameterfv(target, pname, params);
}

void glGetConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetConvolutionParameterfvEXT(target, pname, params);
}

void glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetConvolutionParameteriv(target, pname, params);
}

void glGetConvolutionParameterivEXT(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetConvolutionParameterivEXT(target, pname, params);
}

void glGetConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed * params)
{
    return glmixedbinding::Binding::GetConvolutionParameterxvOES(target, pname, params);
}

void glGetCoverageModulationTableNV(GLsizei bufSize, GLfloat * v)
{
    return glmixedbinding::Binding::GetCoverageModulationTableNV(bufSize, v);
}

GLuint glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog)
{
    return glmixedbinding::Binding::GetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}

GLuint glGetDebugMessageLogAMD(GLuint count, GLsizei bufSize, GLenum * categories, GLenum * severities, GLuint * ids, GLsizei * lengths, GLchar * message)
{
    return glmixedbinding::Binding::GetDebugMessageLogAMD(count, bufSize, categories, severities, ids, lengths, message);
}

GLuint glGetDebugMessageLogARB(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog)
{
    return glmixedbinding::Binding::GetDebugMessageLogARB(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}

GLuint glGetDebugMessageLogKHR(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog)
{
    return glmixedbinding::Binding::GetDebugMessageLogKHR(count, bufSize, sources, types, ids, severities, lengths, messageLog);
}

void glGetDetailTexFuncSGIS(GLenum target, GLfloat * points)
{
    return glmixedbinding::Binding::GetDetailTexFuncSGIS(target, points);
}

void glGetDoublei_v(GLenum target, GLuint index, GLdouble * data)
{
    return glmixedbinding::Binding::GetDoublei_v(target, index, data);
}

void glGetDoublei_vEXT(GLenum pname, GLuint index, GLdouble * params)
{
    return glmixedbinding::Binding::GetDoublei_vEXT(pname, index, params);
}

void glGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble * data)
{
    return glmixedbinding::Binding::GetDoubleIndexedvEXT(target, index, data);
}

void glGetDoublev(GLenum pname, GLdouble * data)
{
    return glmixedbinding::Binding::GetDoublev(pname, data);
}

void glGetDriverControlsQCOM(GLint * num, GLsizei size, GLuint * driverControls)
{
    return glmixedbinding::Binding::GetDriverControlsQCOM(num, size, driverControls);
}

void glGetDriverControlStringQCOM(GLuint driverControl, GLsizei bufSize, GLsizei * length, GLchar * driverControlString)
{
    return glmixedbinding::Binding::GetDriverControlStringQCOM(driverControl, bufSize, length, driverControlString);
}

GLenum glGetError()
{
    return glmixedbinding::Binding::GetError();
}

void glGetFenceivNV(GLuint fence, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetFenceivNV(fence, pname, params);
}

void glGetFinalCombinerInputParameterfvNV(GLenum variable, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetFinalCombinerInputParameterfvNV(variable, pname, params);
}

void glGetFinalCombinerInputParameterivNV(GLenum variable, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetFinalCombinerInputParameterivNV(variable, pname, params);
}

void glGetFirstPerfQueryIdINTEL(GLuint * queryId)
{
    return glmixedbinding::Binding::GetFirstPerfQueryIdINTEL(queryId);
}

void glGetFixedvOES(GLenum pname, GLfixed * params)
{
    return glmixedbinding::Binding::GetFixedvOES(pname, params);
}

void glGetFloati_v(GLenum target, GLuint index, GLfloat * data)
{
    return glmixedbinding::Binding::GetFloati_v(target, index, data);
}

void glGetFloati_vEXT(GLenum pname, GLuint index, GLfloat * params)
{
    return glmixedbinding::Binding::GetFloati_vEXT(pname, index, params);
}

void glGetFloati_vNV(GLenum target, GLuint index, GLfloat * data)
{
    return glmixedbinding::Binding::GetFloati_vNV(target, index, data);
}

void glGetFloati_vOES(GLenum target, GLuint index, GLfloat * data)
{
    return glmixedbinding::Binding::GetFloati_vOES(target, index, data);
}

void glGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat * data)
{
    return glmixedbinding::Binding::GetFloatIndexedvEXT(target, index, data);
}

void glGetFloatv(GLenum pname, GLfloat * data)
{
    return glmixedbinding::Binding::GetFloatv(pname, data);
}

void glGetFogFuncSGIS(GLfloat * points)
{
    return glmixedbinding::Binding::GetFogFuncSGIS(points);
}

GLint glGetFragDataIndex(GLuint program, const GLchar * name)
{
    return glmixedbinding::Binding::GetFragDataIndex(program, name);
}

GLint glGetFragDataIndexEXT(GLuint program, const GLchar * name)
{
    return glmixedbinding::Binding::GetFragDataIndexEXT(program, name);
}

GLint glGetFragDataLocation(GLuint program, const GLchar * name)
{
    return glmixedbinding::Binding::GetFragDataLocation(program, name);
}

GLint glGetFragDataLocationEXT(GLuint program, const GLchar * name)
{
    return glmixedbinding::Binding::GetFragDataLocationEXT(program, name);
}

void glGetFragmentLightfvSGIX(GLenum light, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetFragmentLightfvSGIX(light, pname, params);
}

void glGetFragmentLightivSGIX(GLenum light, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetFragmentLightivSGIX(light, pname, params);
}

void glGetFragmentMaterialfvSGIX(GLenum face, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetFragmentMaterialfvSGIX(face, pname, params);
}

void glGetFragmentMaterialivSGIX(GLenum face, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetFragmentMaterialivSGIX(face, pname, params);
}

void glGetFragmentShadingRatesEXT(GLsizei samples, GLsizei maxCount, GLsizei * count, GLenum * shadingRates)
{
    return glmixedbinding::Binding::GetFragmentShadingRatesEXT(samples, maxCount, count, shadingRates);
}

void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}

void glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetFramebufferAttachmentParameterivEXT(target, attachment, pname, params);
}

void glGetFramebufferParameterfvAMD(GLenum target, GLenum pname, GLuint numsamples, GLuint pixelindex, GLsizei size, GLfloat * values)
{
    return glmixedbinding::Binding::GetFramebufferParameterfvAMD(target, pname, numsamples, pixelindex, size, values);
}

void glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetFramebufferParameteriv(target, pname, params);
}

void glGetFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetFramebufferParameterivEXT(framebuffer, pname, params);
}

void glGetFramebufferParameterivMESA(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetFramebufferParameterivMESA(target, pname, params);
}

GLsizei glGetFramebufferPixelLocalStorageSizeEXT(GLuint target)
{
    return glmixedbinding::Binding::GetFramebufferPixelLocalStorageSizeEXT(target);
}

GLenum glGetGraphicsResetStatus()
{
    return glmixedbinding::Binding::GetGraphicsResetStatus();
}

GLenum glGetGraphicsResetStatusARB()
{
    return glmixedbinding::Binding::GetGraphicsResetStatusARB();
}

GLenum glGetGraphicsResetStatusEXT()
{
    return glmixedbinding::Binding::GetGraphicsResetStatusEXT();
}

GLenum glGetGraphicsResetStatusKHR()
{
    return glmixedbinding::Binding::GetGraphicsResetStatusKHR();
}

GLhandleARB glGetHandleARB(GLenum pname)
{
    return glmixedbinding::Binding::GetHandleARB(pname);
}

void glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values)
{
    return glmixedbinding::Binding::GetHistogram(target, reset, format, type, values);
}

void glGetHistogramEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values)
{
    return glmixedbinding::Binding::GetHistogramEXT(target, reset, format, type, values);
}

void glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetHistogramParameterfv(target, pname, params);
}

void glGetHistogramParameterfvEXT(GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetHistogramParameterfvEXT(target, pname, params);
}

void glGetHistogramParameteriv(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetHistogramParameteriv(target, pname, params);
}

void glGetHistogramParameterivEXT(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetHistogramParameterivEXT(target, pname, params);
}

void glGetHistogramParameterxvOES(GLenum target, GLenum pname, GLfixed * params)
{
    return glmixedbinding::Binding::GetHistogramParameterxvOES(target, pname, params);
}

GLuint64 glGetImageHandleARB(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format)
{
    return glmixedbinding::Binding::GetImageHandleARB(texture, level, layered, layer, format);
}

GLuint64 glGetImageHandleNV(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format)
{
    return glmixedbinding::Binding::GetImageHandleNV(texture, level, layered, layer, format);
}

void glGetImageTransformParameterfvHP(GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetImageTransformParameterfvHP(target, pname, params);
}

void glGetImageTransformParameterivHP(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetImageTransformParameterivHP(target, pname, params);
}

void glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * infoLog)
{
    return glmixedbinding::Binding::GetInfoLogARB(obj, maxLength, length, infoLog);
}

GLint glGetInstrumentsSGIX()
{
    return glmixedbinding::Binding::GetInstrumentsSGIX();
}

void glGetInteger64i_v(GLenum target, GLuint index, GLint64 * data)
{
    return glmixedbinding::Binding::GetInteger64i_v(target, index, data);
}

void glGetInteger64v(GLenum pname, GLint64 * data)
{
    return glmixedbinding::Binding::GetInteger64v(pname, data);
}

void glGetInteger64vAPPLE(GLenum pname, GLint64 * params)
{
    return glmixedbinding::Binding::GetInteger64vAPPLE(pname, params);
}

void glGetInteger64vEXT(GLenum pname, GLint64 * data)
{
    return glmixedbinding::Binding::GetInteger64vEXT(pname, data);
}

void glGetIntegeri_v(GLenum target, GLuint index, GLint * data)
{
    return glmixedbinding::Binding::GetIntegeri_v(target, index, data);
}

void glGetIntegeri_vEXT(GLenum target, GLuint index, GLint * data)
{
    return glmixedbinding::Binding::GetIntegeri_vEXT(target, index, data);
}

void glGetIntegerIndexedvEXT(GLenum target, GLuint index, GLint * data)
{
    return glmixedbinding::Binding::GetIntegerIndexedvEXT(target, index, data);
}

void glGetIntegerui64i_vNV(GLenum value, GLuint index, GLuint64EXT * result)
{
    return glmixedbinding::Binding::GetIntegerui64i_vNV(value, index, result);
}

void glGetIntegerui64vNV(GLenum value, GLuint64EXT * result)
{
    return glmixedbinding::Binding::GetIntegerui64vNV(value, result);
}

void glGetIntegerv(GLenum pname, GLint * data)
{
    return glmixedbinding::Binding::GetIntegerv(pname, data);
}

void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 * params)
{
    return glmixedbinding::Binding::GetInternalformati64v(target, internalformat, pname, count, params);
}

void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint * params)
{
    return glmixedbinding::Binding::GetInternalformativ(target, internalformat, pname, count, params);
}

void glGetInternalformatSampleivNV(GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei count, GLint * params)
{
    return glmixedbinding::Binding::GetInternalformatSampleivNV(target, internalformat, samples, pname, count, params);
}

void glGetInvariantBooleanvEXT(GLuint id, GLenum value, GLboolean * data)
{
    return glmixedbinding::Binding::GetInvariantBooleanvEXT(id, value, data);
}

void glGetInvariantFloatvEXT(GLuint id, GLenum value, GLfloat * data)
{
    return glmixedbinding::Binding::GetInvariantFloatvEXT(id, value, data);
}

void glGetInvariantIntegervEXT(GLuint id, GLenum value, GLint * data)
{
    return glmixedbinding::Binding::GetInvariantIntegervEXT(id, value, data);
}

void glGetLightfv(GLenum light, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetLightfv(light, pname, params);
}

void glGetLightiv(GLenum light, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetLightiv(light, pname, params);
}

void glGetLightxOES(GLenum light, GLenum pname, GLfixed * params)
{
    return glmixedbinding::Binding::GetLightxOES(light, pname, params);
}

void glGetLightxvOES(GLenum light, GLenum pname, GLfixed * params)
{
    return glmixedbinding::Binding::GetLightxvOES(light, pname, params);
}

void glGetListParameterfvSGIX(GLuint list, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetListParameterfvSGIX(list, pname, params);
}

void glGetListParameterivSGIX(GLuint list, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetListParameterivSGIX(list, pname, params);
}

void glGetLocalConstantBooleanvEXT(GLuint id, GLenum value, GLboolean * data)
{
    return glmixedbinding::Binding::GetLocalConstantBooleanvEXT(id, value, data);
}

void glGetLocalConstantFloatvEXT(GLuint id, GLenum value, GLfloat * data)
{
    return glmixedbinding::Binding::GetLocalConstantFloatvEXT(id, value, data);
}

void glGetLocalConstantIntegervEXT(GLuint id, GLenum value, GLint * data)
{
    return glmixedbinding::Binding::GetLocalConstantIntegervEXT(id, value, data);
}

void glGetMapAttribParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetMapAttribParameterfvNV(target, index, pname, params);
}

void glGetMapAttribParameterivNV(GLenum target, GLuint index, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetMapAttribParameterivNV(target, index, pname, params);
}

void glGetMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, void * points)
{
    return glmixedbinding::Binding::GetMapControlPointsNV(target, index, type, ustride, vstride, packed, points);
}

void glGetMapdv(GLenum target, GLenum query, GLdouble * v)
{
    return glmixedbinding::Binding::GetMapdv(target, query, v);
}

void glGetMapfv(GLenum target, GLenum query, GLfloat * v)
{
    return glmixedbinding::Binding::GetMapfv(target, query, v);
}

void glGetMapiv(GLenum target, GLenum query, GLint * v)
{
    return glmixedbinding::Binding::GetMapiv(target, query, v);
}

void glGetMapParameterfvNV(GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetMapParameterfvNV(target, pname, params);
}

void glGetMapParameterivNV(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetMapParameterivNV(target, pname, params);
}

void glGetMapxvOES(GLenum target, GLenum query, GLfixed * v)
{
    return glmixedbinding::Binding::GetMapxvOES(target, query, v);
}

void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetMaterialfv(face, pname, params);
}

void glGetMaterialiv(GLenum face, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetMaterialiv(face, pname, params);
}

void glGetMaterialxOES(GLenum face, GLenum pname, GLfixed param)
{
    return glmixedbinding::Binding::GetMaterialxOES(face, pname, param);
}

void glGetMaterialxvOES(GLenum face, GLenum pname, GLfixed * params)
{
    return glmixedbinding::Binding::GetMaterialxvOES(face, pname, params);
}

void glGetMemoryObjectDetachedResourcesuivNV(GLuint memory, GLenum pname, GLint first, GLsizei count, GLuint * params)
{
    return glmixedbinding::Binding::GetMemoryObjectDetachedResourcesuivNV(memory, pname, first, count, params);
}

void glGetMemoryObjectParameterivEXT(GLuint memoryObject, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetMemoryObjectParameterivEXT(memoryObject, pname, params);
}

void glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values)
{
    return glmixedbinding::Binding::GetMinmax(target, reset, format, type, values);
}

void glGetMinmaxEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, void * values)
{
    return glmixedbinding::Binding::GetMinmaxEXT(target, reset, format, type, values);
}

void glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetMinmaxParameterfv(target, pname, params);
}

void glGetMinmaxParameterfvEXT(GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetMinmaxParameterfvEXT(target, pname, params);
}

void glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetMinmaxParameteriv(target, pname, params);
}

void glGetMinmaxParameterivEXT(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetMinmaxParameterivEXT(target, pname, params);
}

void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat * val)
{
    return glmixedbinding::Binding::GetMultisamplefv(pname, index, val);
}

void glGetMultisamplefvNV(GLenum pname, GLuint index, GLfloat * val)
{
    return glmixedbinding::Binding::GetMultisamplefvNV(pname, index, val);
}

void glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetMultiTexEnvfvEXT(texunit, target, pname, params);
}

void glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetMultiTexEnvivEXT(texunit, target, pname, params);
}

void glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble * params)
{
    return glmixedbinding::Binding::GetMultiTexGendvEXT(texunit, coord, pname, params);
}

void glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetMultiTexGenfvEXT(texunit, coord, pname, params);
}

void glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetMultiTexGenivEXT(texunit, coord, pname, params);
}

void glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void * pixels)
{
    return glmixedbinding::Binding::GetMultiTexImageEXT(texunit, target, level, format, type, pixels);
}

void glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetMultiTexLevelParameterfvEXT(texunit, target, level, pname, params);
}

void glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetMultiTexLevelParameterivEXT(texunit, target, level, pname, params);
}

void glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetMultiTexParameterfvEXT(texunit, target, pname, params);
}

void glGetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetMultiTexParameterIivEXT(texunit, target, pname, params);
}

void glGetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::GetMultiTexParameterIuivEXT(texunit, target, pname, params);
}

void glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetMultiTexParameterivEXT(texunit, target, pname, params);
}

void glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 * params)
{
    return glmixedbinding::Binding::GetNamedBufferParameteri64v(buffer, pname, params);
}

void glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetNamedBufferParameteriv(buffer, pname, params);
}

void glGetNamedBufferParameterivEXT(GLuint buffer, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetNamedBufferParameterivEXT(buffer, pname, params);
}

void glGetNamedBufferParameterui64vNV(GLuint buffer, GLenum pname, GLuint64EXT * params)
{
    return glmixedbinding::Binding::GetNamedBufferParameterui64vNV(buffer, pname, params);
}

void glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void ** params)
{
    return glmixedbinding::Binding::GetNamedBufferPointerv(buffer, pname, params);
}

void glGetNamedBufferPointervEXT(GLuint buffer, GLenum pname, void ** params)
{
    return glmixedbinding::Binding::GetNamedBufferPointervEXT(buffer, pname, params);
}

void glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data)
{
    return glmixedbinding::Binding::GetNamedBufferSubData(buffer, offset, size, data);
}

void glGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data)
{
    return glmixedbinding::Binding::GetNamedBufferSubDataEXT(buffer, offset, size, data);
}

void glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetNamedFramebufferAttachmentParameteriv(framebuffer, attachment, pname, params);
}

void glGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetNamedFramebufferAttachmentParameterivEXT(framebuffer, attachment, pname, params);
}

void glGetNamedFramebufferParameterfvAMD(GLuint framebuffer, GLenum pname, GLuint numsamples, GLuint pixelindex, GLsizei size, GLfloat * values)
{
    return glmixedbinding::Binding::GetNamedFramebufferParameterfvAMD(framebuffer, pname, numsamples, pixelindex, size, values);
}

void glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint * param)
{
    return glmixedbinding::Binding::GetNamedFramebufferParameteriv(framebuffer, pname, param);
}

void glGetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetNamedFramebufferParameterivEXT(framebuffer, pname, params);
}

void glGetNamedProgramivEXT(GLuint program, GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetNamedProgramivEXT(program, target, pname, params);
}

void glGetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble * params)
{
    return glmixedbinding::Binding::GetNamedProgramLocalParameterdvEXT(program, target, index, params);
}

void glGetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat * params)
{
    return glmixedbinding::Binding::GetNamedProgramLocalParameterfvEXT(program, target, index, params);
}

void glGetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint * params)
{
    return glmixedbinding::Binding::GetNamedProgramLocalParameterIivEXT(program, target, index, params);
}

void glGetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint * params)
{
    return glmixedbinding::Binding::GetNamedProgramLocalParameterIuivEXT(program, target, index, params);
}

void glGetNamedProgramStringEXT(GLuint program, GLenum target, GLenum pname, void * string)
{
    return glmixedbinding::Binding::GetNamedProgramStringEXT(program, target, pname, string);
}

void glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetNamedRenderbufferParameteriv(renderbuffer, pname, params);
}

void glGetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetNamedRenderbufferParameterivEXT(renderbuffer, pname, params);
}

void glGetNamedStringARB(GLint namelen, const GLchar * name, GLsizei bufSize, GLint * stringlen, GLchar * string)
{
    return glmixedbinding::Binding::GetNamedStringARB(namelen, name, bufSize, stringlen, string);
}

void glGetNamedStringivARB(GLint namelen, const GLchar * name, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetNamedStringivARB(namelen, name, pname, params);
}

void glGetnColorTable(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * table)
{
    return glmixedbinding::Binding::GetnColorTable(target, format, type, bufSize, table);
}

void glGetnColorTableARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * table)
{
    return glmixedbinding::Binding::GetnColorTableARB(target, format, type, bufSize, table);
}

void glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void * pixels)
{
    return glmixedbinding::Binding::GetnCompressedTexImage(target, lod, bufSize, pixels);
}

void glGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, void * img)
{
    return glmixedbinding::Binding::GetnCompressedTexImageARB(target, lod, bufSize, img);
}

void glGetnConvolutionFilter(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * image)
{
    return glmixedbinding::Binding::GetnConvolutionFilter(target, format, type, bufSize, image);
}

void glGetnConvolutionFilterARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * image)
{
    return glmixedbinding::Binding::GetnConvolutionFilterARB(target, format, type, bufSize, image);
}

void glGetNextPerfQueryIdINTEL(GLuint queryId, GLuint * nextQueryId)
{
    return glmixedbinding::Binding::GetNextPerfQueryIdINTEL(queryId, nextQueryId);
}

void glGetnHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values)
{
    return glmixedbinding::Binding::GetnHistogram(target, reset, format, type, bufSize, values);
}

void glGetnHistogramARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values)
{
    return glmixedbinding::Binding::GetnHistogramARB(target, reset, format, type, bufSize, values);
}

void glGetnMapdv(GLenum target, GLenum query, GLsizei bufSize, GLdouble * v)
{
    return glmixedbinding::Binding::GetnMapdv(target, query, bufSize, v);
}

void glGetnMapdvARB(GLenum target, GLenum query, GLsizei bufSize, GLdouble * v)
{
    return glmixedbinding::Binding::GetnMapdvARB(target, query, bufSize, v);
}

void glGetnMapfv(GLenum target, GLenum query, GLsizei bufSize, GLfloat * v)
{
    return glmixedbinding::Binding::GetnMapfv(target, query, bufSize, v);
}

void glGetnMapfvARB(GLenum target, GLenum query, GLsizei bufSize, GLfloat * v)
{
    return glmixedbinding::Binding::GetnMapfvARB(target, query, bufSize, v);
}

void glGetnMapiv(GLenum target, GLenum query, GLsizei bufSize, GLint * v)
{
    return glmixedbinding::Binding::GetnMapiv(target, query, bufSize, v);
}

void glGetnMapivARB(GLenum target, GLenum query, GLsizei bufSize, GLint * v)
{
    return glmixedbinding::Binding::GetnMapivARB(target, query, bufSize, v);
}

void glGetnMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values)
{
    return glmixedbinding::Binding::GetnMinmax(target, reset, format, type, bufSize, values);
}

void glGetnMinmaxARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values)
{
    return glmixedbinding::Binding::GetnMinmaxARB(target, reset, format, type, bufSize, values);
}

void glGetnPixelMapfv(GLenum map, GLsizei bufSize, GLfloat * values)
{
    return glmixedbinding::Binding::GetnPixelMapfv(map, bufSize, values);
}

void glGetnPixelMapfvARB(GLenum map, GLsizei bufSize, GLfloat * values)
{
    return glmixedbinding::Binding::GetnPixelMapfvARB(map, bufSize, values);
}

void glGetnPixelMapuiv(GLenum map, GLsizei bufSize, GLuint * values)
{
    return glmixedbinding::Binding::GetnPixelMapuiv(map, bufSize, values);
}

void glGetnPixelMapuivARB(GLenum map, GLsizei bufSize, GLuint * values)
{
    return glmixedbinding::Binding::GetnPixelMapuivARB(map, bufSize, values);
}

void glGetnPixelMapusv(GLenum map, GLsizei bufSize, GLushort * values)
{
    return glmixedbinding::Binding::GetnPixelMapusv(map, bufSize, values);
}

void glGetnPixelMapusvARB(GLenum map, GLsizei bufSize, GLushort * values)
{
    return glmixedbinding::Binding::GetnPixelMapusvARB(map, bufSize, values);
}

void glGetnPolygonStipple(GLsizei bufSize, GLubyte * pattern)
{
    return glmixedbinding::Binding::GetnPolygonStipple(bufSize, pattern);
}

void glGetnPolygonStippleARB(GLsizei bufSize, GLubyte * pattern)
{
    return glmixedbinding::Binding::GetnPolygonStippleARB(bufSize, pattern);
}

void glGetnSeparableFilter(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void * row, GLsizei columnBufSize, void * column, void * span)
{
    return glmixedbinding::Binding::GetnSeparableFilter(target, format, type, rowBufSize, row, columnBufSize, column, span);
}

void glGetnSeparableFilterARB(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void * row, GLsizei columnBufSize, void * column, void * span)
{
    return glmixedbinding::Binding::GetnSeparableFilterARB(target, format, type, rowBufSize, row, columnBufSize, column, span);
}

void glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels)
{
    return glmixedbinding::Binding::GetnTexImage(target, level, format, type, bufSize, pixels);
}

void glGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * img)
{
    return glmixedbinding::Binding::GetnTexImageARB(target, level, format, type, bufSize, img);
}

void glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble * params)
{
    return glmixedbinding::Binding::GetnUniformdv(program, location, bufSize, params);
}

void glGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble * params)
{
    return glmixedbinding::Binding::GetnUniformdvARB(program, location, bufSize, params);
}

void glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat * params)
{
    return glmixedbinding::Binding::GetnUniformfv(program, location, bufSize, params);
}

void glGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat * params)
{
    return glmixedbinding::Binding::GetnUniformfvARB(program, location, bufSize, params);
}

void glGetnUniformfvEXT(GLuint program, GLint location, GLsizei bufSize, GLfloat * params)
{
    return glmixedbinding::Binding::GetnUniformfvEXT(program, location, bufSize, params);
}

void glGetnUniformfvKHR(GLuint program, GLint location, GLsizei bufSize, GLfloat * params)
{
    return glmixedbinding::Binding::GetnUniformfvKHR(program, location, bufSize, params);
}

void glGetnUniformi64vARB(GLuint program, GLint location, GLsizei bufSize, GLint64 * params)
{
    return glmixedbinding::Binding::GetnUniformi64vARB(program, location, bufSize, params);
}

void glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint * params)
{
    return glmixedbinding::Binding::GetnUniformiv(program, location, bufSize, params);
}

void glGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint * params)
{
    return glmixedbinding::Binding::GetnUniformivARB(program, location, bufSize, params);
}

void glGetnUniformivEXT(GLuint program, GLint location, GLsizei bufSize, GLint * params)
{
    return glmixedbinding::Binding::GetnUniformivEXT(program, location, bufSize, params);
}

void glGetnUniformivKHR(GLuint program, GLint location, GLsizei bufSize, GLint * params)
{
    return glmixedbinding::Binding::GetnUniformivKHR(program, location, bufSize, params);
}

void glGetnUniformui64vARB(GLuint program, GLint location, GLsizei bufSize, GLuint64 * params)
{
    return glmixedbinding::Binding::GetnUniformui64vARB(program, location, bufSize, params);
}

void glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint * params)
{
    return glmixedbinding::Binding::GetnUniformuiv(program, location, bufSize, params);
}

void glGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint * params)
{
    return glmixedbinding::Binding::GetnUniformuivARB(program, location, bufSize, params);
}

void glGetnUniformuivKHR(GLuint program, GLint location, GLsizei bufSize, GLuint * params)
{
    return glmixedbinding::Binding::GetnUniformuivKHR(program, location, bufSize, params);
}

void glGetObjectBufferfvATI(GLuint buffer, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetObjectBufferfvATI(buffer, pname, params);
}

void glGetObjectBufferivATI(GLuint buffer, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetObjectBufferivATI(buffer, pname, params);
}

void glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label)
{
    return glmixedbinding::Binding::GetObjectLabel(identifier, name, bufSize, length, label);
}

void glGetObjectLabelEXT(GLenum type, GLuint object, GLsizei bufSize, GLsizei * length, GLchar * label)
{
    return glmixedbinding::Binding::GetObjectLabelEXT(type, object, bufSize, length, label);
}

void glGetObjectLabelKHR(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label)
{
    return glmixedbinding::Binding::GetObjectLabelKHR(identifier, name, bufSize, length, label);
}

void glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetObjectParameterfvARB(obj, pname, params);
}

void glGetObjectParameterivAPPLE(GLenum objectType, GLuint name, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetObjectParameterivAPPLE(objectType, name, pname, params);
}

void glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetObjectParameterivARB(obj, pname, params);
}

void glGetObjectPtrLabel(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label)
{
    return glmixedbinding::Binding::GetObjectPtrLabel(ptr, bufSize, length, label);
}

void glGetObjectPtrLabelKHR(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label)
{
    return glmixedbinding::Binding::GetObjectPtrLabelKHR(ptr, bufSize, length, label);
}

void glGetOcclusionQueryivNV(GLuint id, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetOcclusionQueryivNV(id, pname, params);
}

void glGetOcclusionQueryuivNV(GLuint id, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::GetOcclusionQueryuivNV(id, pname, params);
}

void glGetPathColorGenfvNV(GLenum color, GLenum pname, GLfloat * value)
{
    return glmixedbinding::Binding::GetPathColorGenfvNV(color, pname, value);
}

void glGetPathColorGenivNV(GLenum color, GLenum pname, GLint * value)
{
    return glmixedbinding::Binding::GetPathColorGenivNV(color, pname, value);
}

void glGetPathCommandsNV(GLuint path, GLubyte * commands)
{
    return glmixedbinding::Binding::GetPathCommandsNV(path, commands);
}

void glGetPathCoordsNV(GLuint path, GLfloat * coords)
{
    return glmixedbinding::Binding::GetPathCoordsNV(path, coords);
}

void glGetPathDashArrayNV(GLuint path, GLfloat * dashArray)
{
    return glmixedbinding::Binding::GetPathDashArrayNV(path, dashArray);
}

GLfloat glGetPathLengthNV(GLuint path, GLsizei startSegment, GLsizei numSegments)
{
    return glmixedbinding::Binding::GetPathLengthNV(path, startSegment, numSegments);
}

void glGetPathMetricRangeNV(PathMetricMask metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat * metrics)
{
    return glmixedbinding::Binding::GetPathMetricRangeNV(metricQueryMask, firstPathName, numPaths, stride, metrics);
}

void glGetPathMetricsNV(PathMetricMask metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLsizei stride, GLfloat * metrics)
{
    return glmixedbinding::Binding::GetPathMetricsNV(metricQueryMask, numPaths, pathNameType, paths, pathBase, stride, metrics);
}

void glGetPathParameterfvNV(GLuint path, GLenum pname, GLfloat * value)
{
    return glmixedbinding::Binding::GetPathParameterfvNV(path, pname, value);
}

void glGetPathParameterivNV(GLuint path, GLenum pname, GLint * value)
{
    return glmixedbinding::Binding::GetPathParameterivNV(path, pname, value);
}

void glGetPathSpacingNV(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void * paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat * returnedSpacing)
{
    return glmixedbinding::Binding::GetPathSpacingNV(pathListMode, numPaths, pathNameType, paths, pathBase, advanceScale, kerningScale, transformType, returnedSpacing);
}

void glGetPathTexGenfvNV(GLenum texCoordSet, GLenum pname, GLfloat * value)
{
    return glmixedbinding::Binding::GetPathTexGenfvNV(texCoordSet, pname, value);
}

void glGetPathTexGenivNV(GLenum texCoordSet, GLenum pname, GLint * value)
{
    return glmixedbinding::Binding::GetPathTexGenivNV(texCoordSet, pname, value);
}

void glGetPerfCounterInfoINTEL(GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar * counterName, GLuint counterDescLength, GLchar * counterDesc, GLuint * counterOffset, GLuint * counterDataSize, GLuint * counterTypeEnum, GLuint * counterDataTypeEnum, GLuint64 * rawCounterMaxValue)
{
    return glmixedbinding::Binding::GetPerfCounterInfoINTEL(queryId, counterId, counterNameLength, counterName, counterDescLength, counterDesc, counterOffset, counterDataSize, counterTypeEnum, counterDataTypeEnum, rawCounterMaxValue);
}

void glGetPerfMonitorCounterDataAMD(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint * data, GLint * bytesWritten)
{
    return glmixedbinding::Binding::GetPerfMonitorCounterDataAMD(monitor, pname, dataSize, data, bytesWritten);
}

void glGetPerfMonitorCounterInfoAMD(GLuint group, GLuint counter, GLenum pname, void * data)
{
    return glmixedbinding::Binding::GetPerfMonitorCounterInfoAMD(group, counter, pname, data);
}

void glGetPerfMonitorCountersAMD(GLuint group, GLint * numCounters, GLint * maxActiveCounters, GLsizei counterSize, GLuint * counters)
{
    return glmixedbinding::Binding::GetPerfMonitorCountersAMD(group, numCounters, maxActiveCounters, counterSize, counters);
}

void glGetPerfMonitorCounterStringAMD(GLuint group, GLuint counter, GLsizei bufSize, GLsizei * length, GLchar * counterString)
{
    return glmixedbinding::Binding::GetPerfMonitorCounterStringAMD(group, counter, bufSize, length, counterString);
}

void glGetPerfMonitorGroupsAMD(GLint * numGroups, GLsizei groupsSize, GLuint * groups)
{
    return glmixedbinding::Binding::GetPerfMonitorGroupsAMD(numGroups, groupsSize, groups);
}

void glGetPerfMonitorGroupStringAMD(GLuint group, GLsizei bufSize, GLsizei * length, GLchar * groupString)
{
    return glmixedbinding::Binding::GetPerfMonitorGroupStringAMD(group, bufSize, length, groupString);
}

void glGetPerfQueryDataINTEL(GLuint queryHandle, GLuint flags, GLsizei dataSize, void * data, GLuint * bytesWritten)
{
    return glmixedbinding::Binding::GetPerfQueryDataINTEL(queryHandle, flags, dataSize, data, bytesWritten);
}

void glGetPerfQueryIdByNameINTEL(GLchar * queryName, GLuint * queryId)
{
    return glmixedbinding::Binding::GetPerfQueryIdByNameINTEL(queryName, queryId);
}

void glGetPerfQueryInfoINTEL(GLuint queryId, GLuint queryNameLength, GLchar * queryName, GLuint * dataSize, GLuint * noCounters, GLuint * noInstances, PerformanceQueryCapsMaskINTEL capsMask)
{
    return glmixedbinding::Binding::GetPerfQueryInfoINTEL(queryId, queryNameLength, queryName, dataSize, noCounters, noInstances, capsMask);
}

void glGetPixelMapfv(GLenum map, GLfloat * values)
{
    return glmixedbinding::Binding::GetPixelMapfv(map, values);
}

void glGetPixelMapuiv(GLenum map, GLuint * values)
{
    return glmixedbinding::Binding::GetPixelMapuiv(map, values);
}

void glGetPixelMapusv(GLenum map, GLushort * values)
{
    return glmixedbinding::Binding::GetPixelMapusv(map, values);
}

void glGetPixelMapxv(GLenum map, GLint size, GLfixed * values)
{
    return glmixedbinding::Binding::GetPixelMapxv(map, size, values);
}

void glGetPixelTexGenParameterfvSGIS(GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetPixelTexGenParameterfvSGIS(pname, params);
}

void glGetPixelTexGenParameterivSGIS(GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetPixelTexGenParameterivSGIS(pname, params);
}

void glGetPixelTransformParameterfvEXT(GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetPixelTransformParameterfvEXT(target, pname, params);
}

void glGetPixelTransformParameterivEXT(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetPixelTransformParameterivEXT(target, pname, params);
}

void glGetPointeri_vEXT(GLenum pname, GLuint index, void ** params)
{
    return glmixedbinding::Binding::GetPointeri_vEXT(pname, index, params);
}

void glGetPointerIndexedvEXT(GLenum target, GLuint index, void ** data)
{
    return glmixedbinding::Binding::GetPointerIndexedvEXT(target, index, data);
}

void glGetPointerv(GLenum pname, void ** params)
{
    return glmixedbinding::Binding::GetPointerv(pname, params);
}

void glGetPointervEXT(GLenum pname, void ** params)
{
    return glmixedbinding::Binding::GetPointervEXT(pname, params);
}

void glGetPointervKHR(GLenum pname, void ** params)
{
    return glmixedbinding::Binding::GetPointervKHR(pname, params);
}

void glGetPolygonStipple(GLubyte * mask)
{
    return glmixedbinding::Binding::GetPolygonStipple(mask);
}

void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary)
{
    return glmixedbinding::Binding::GetProgramBinary(program, bufSize, length, binaryFormat, binary);
}

void glGetProgramBinaryOES(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary)
{
    return glmixedbinding::Binding::GetProgramBinaryOES(program, bufSize, length, binaryFormat, binary);
}

void glGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble * params)
{
    return glmixedbinding::Binding::GetProgramEnvParameterdvARB(target, index, params);
}

void glGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat * params)
{
    return glmixedbinding::Binding::GetProgramEnvParameterfvARB(target, index, params);
}

void glGetProgramEnvParameterIivNV(GLenum target, GLuint index, GLint * params)
{
    return glmixedbinding::Binding::GetProgramEnvParameterIivNV(target, index, params);
}

void glGetProgramEnvParameterIuivNV(GLenum target, GLuint index, GLuint * params)
{
    return glmixedbinding::Binding::GetProgramEnvParameterIuivNV(target, index, params);
}

void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog)
{
    return glmixedbinding::Binding::GetProgramInfoLog(program, bufSize, length, infoLog);
}

void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetProgramInterfaceiv(program, programInterface, pname, params);
}

void glGetProgramiv(GLuint program, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetProgramiv(program, pname, params);
}

void glGetProgramivARB(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetProgramivARB(target, pname, params);
}

void glGetProgramivNV(GLuint id, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetProgramivNV(id, pname, params);
}

void glGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble * params)
{
    return glmixedbinding::Binding::GetProgramLocalParameterdvARB(target, index, params);
}

void glGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat * params)
{
    return glmixedbinding::Binding::GetProgramLocalParameterfvARB(target, index, params);
}

void glGetProgramLocalParameterIivNV(GLenum target, GLuint index, GLint * params)
{
    return glmixedbinding::Binding::GetProgramLocalParameterIivNV(target, index, params);
}

void glGetProgramLocalParameterIuivNV(GLenum target, GLuint index, GLuint * params)
{
    return glmixedbinding::Binding::GetProgramLocalParameterIuivNV(target, index, params);
}

void glGetProgramNamedParameterdvNV(GLuint id, GLsizei len, const GLubyte * name, GLdouble * params)
{
    return glmixedbinding::Binding::GetProgramNamedParameterdvNV(id, len, name, params);
}

void glGetProgramNamedParameterfvNV(GLuint id, GLsizei len, const GLubyte * name, GLfloat * params)
{
    return glmixedbinding::Binding::GetProgramNamedParameterfvNV(id, len, name, params);
}

void glGetProgramParameterdvNV(GLenum target, GLuint index, GLenum pname, GLdouble * params)
{
    return glmixedbinding::Binding::GetProgramParameterdvNV(target, index, pname, params);
}

void glGetProgramParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetProgramParameterfvNV(target, index, pname, params);
}

void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog)
{
    return glmixedbinding::Binding::GetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog);
}

void glGetProgramPipelineInfoLogEXT(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog)
{
    return glmixedbinding::Binding::GetProgramPipelineInfoLogEXT(pipeline, bufSize, length, infoLog);
}

void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetProgramPipelineiv(pipeline, pname, params);
}

void glGetProgramPipelineivEXT(GLuint pipeline, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetProgramPipelineivEXT(pipeline, pname, params);
}

void glGetProgramResourcefvNV(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei count, GLsizei * length, GLfloat * params)
{
    return glmixedbinding::Binding::GetProgramResourcefvNV(program, programInterface, index, propCount, props, count, length, params);
}

GLuint glGetProgramResourceIndex(GLuint program, GLenum programInterface, const GLchar * name)
{
    return glmixedbinding::Binding::GetProgramResourceIndex(program, programInterface, name);
}

void glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei count, GLsizei * length, GLint * params)
{
    return glmixedbinding::Binding::GetProgramResourceiv(program, programInterface, index, propCount, props, count, length, params);
}

GLint glGetProgramResourceLocation(GLuint program, GLenum programInterface, const GLchar * name)
{
    return glmixedbinding::Binding::GetProgramResourceLocation(program, programInterface, name);
}

GLint glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, const GLchar * name)
{
    return glmixedbinding::Binding::GetProgramResourceLocationIndex(program, programInterface, name);
}

GLint glGetProgramResourceLocationIndexEXT(GLuint program, GLenum programInterface, const GLchar * name)
{
    return glmixedbinding::Binding::GetProgramResourceLocationIndexEXT(program, programInterface, name);
}

void glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name)
{
    return glmixedbinding::Binding::GetProgramResourceName(program, programInterface, index, bufSize, length, name);
}

void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint * values)
{
    return glmixedbinding::Binding::GetProgramStageiv(program, shadertype, pname, values);
}

void glGetProgramStringARB(GLenum target, GLenum pname, void * string)
{
    return glmixedbinding::Binding::GetProgramStringARB(target, pname, string);
}

void glGetProgramStringNV(GLuint id, GLenum pname, GLubyte * program)
{
    return glmixedbinding::Binding::GetProgramStringNV(id, pname, program);
}

void glGetProgramSubroutineParameteruivNV(GLenum target, GLuint index, GLuint * param)
{
    return glmixedbinding::Binding::GetProgramSubroutineParameteruivNV(target, index, param);
}

void glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset)
{
    return glmixedbinding::Binding::GetQueryBufferObjecti64v(id, buffer, pname, offset);
}

void glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset)
{
    return glmixedbinding::Binding::GetQueryBufferObjectiv(id, buffer, pname, offset);
}

void glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset)
{
    return glmixedbinding::Binding::GetQueryBufferObjectui64v(id, buffer, pname, offset);
}

void glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset)
{
    return glmixedbinding::Binding::GetQueryBufferObjectuiv(id, buffer, pname, offset);
}

void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetQueryIndexediv(target, index, pname, params);
}

void glGetQueryiv(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetQueryiv(target, pname, params);
}

void glGetQueryivARB(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetQueryivARB(target, pname, params);
}

void glGetQueryivEXT(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetQueryivEXT(target, pname, params);
}

void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 * params)
{
    return glmixedbinding::Binding::GetQueryObjecti64v(id, pname, params);
}

void glGetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64 * params)
{
    return glmixedbinding::Binding::GetQueryObjecti64vEXT(id, pname, params);
}

void glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetQueryObjectiv(id, pname, params);
}

void glGetQueryObjectivARB(GLuint id, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetQueryObjectivARB(id, pname, params);
}

void glGetQueryObjectivEXT(GLuint id, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetQueryObjectivEXT(id, pname, params);
}

void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 * params)
{
    return glmixedbinding::Binding::GetQueryObjectui64v(id, pname, params);
}

void glGetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64 * params)
{
    return glmixedbinding::Binding::GetQueryObjectui64vEXT(id, pname, params);
}

void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::GetQueryObjectuiv(id, pname, params);
}

void glGetQueryObjectuivARB(GLuint id, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::GetQueryObjectuivARB(id, pname, params);
}

void glGetQueryObjectuivEXT(GLuint id, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::GetQueryObjectuivEXT(id, pname, params);
}

void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetRenderbufferParameteriv(target, pname, params);
}

void glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetRenderbufferParameterivEXT(target, pname, params);
}

void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetSamplerParameterfv(sampler, pname, params);
}

void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetSamplerParameterIiv(sampler, pname, params);
}

void glGetSamplerParameterIivEXT(GLuint sampler, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetSamplerParameterIivEXT(sampler, pname, params);
}

void glGetSamplerParameterIivOES(GLuint sampler, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetSamplerParameterIivOES(sampler, pname, params);
}

void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::GetSamplerParameterIuiv(sampler, pname, params);
}

void glGetSamplerParameterIuivEXT(GLuint sampler, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::GetSamplerParameterIuivEXT(sampler, pname, params);
}

void glGetSamplerParameterIuivOES(GLuint sampler, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::GetSamplerParameterIuivOES(sampler, pname, params);
}

void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetSamplerParameteriv(sampler, pname, params);
}

void glGetSemaphoreParameterivNV(GLuint semaphore, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetSemaphoreParameterivNV(semaphore, pname, params);
}

void glGetSemaphoreParameterui64vEXT(GLuint semaphore, GLenum pname, GLuint64 * params)
{
    return glmixedbinding::Binding::GetSemaphoreParameterui64vEXT(semaphore, pname, params);
}

void glGetSeparableFilter(GLenum target, GLenum format, GLenum type, void * row, void * column, void * span)
{
    return glmixedbinding::Binding::GetSeparableFilter(target, format, type, row, column, span);
}

void glGetSeparableFilterEXT(GLenum target, GLenum format, GLenum type, void * row, void * column, void * span)
{
    return glmixedbinding::Binding::GetSeparableFilterEXT(target, format, type, row, column, span);
}

void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog)
{
    return glmixedbinding::Binding::GetShaderInfoLog(shader, bufSize, length, infoLog);
}

void glGetShaderiv(GLuint shader, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetShaderiv(shader, pname, params);
}

void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision)
{
    return glmixedbinding::Binding::GetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}

void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source)
{
    return glmixedbinding::Binding::GetShaderSource(shader, bufSize, length, source);
}

void glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei * length, GLcharARB * source)
{
    return glmixedbinding::Binding::GetShaderSourceARB(obj, maxLength, length, source);
}

void glGetShadingRateImagePaletteNV(GLuint viewport, GLuint entry, GLenum * rate)
{
    return glmixedbinding::Binding::GetShadingRateImagePaletteNV(viewport, entry, rate);
}

void glGetShadingRateSampleLocationivNV(GLenum rate, GLuint samples, GLuint index, GLint * location)
{
    return glmixedbinding::Binding::GetShadingRateSampleLocationivNV(rate, samples, index, location);
}

void glGetSharpenTexFuncSGIS(GLenum target, GLfloat * points)
{
    return glmixedbinding::Binding::GetSharpenTexFuncSGIS(target, points);
}

GLushort glGetStageIndexNV(GLenum shadertype)
{
    return glmixedbinding::Binding::GetStageIndexNV(shadertype);
}

const GLubyte * glGetString(GLenum name)
{
    return glmixedbinding::Binding::GetString(name);
}

const GLubyte * glGetStringi(GLenum name, GLuint index)
{
    return glmixedbinding::Binding::GetStringi(name, index);
}

GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar * name)
{
    return glmixedbinding::Binding::GetSubroutineIndex(program, shadertype, name);
}

GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar * name)
{
    return glmixedbinding::Binding::GetSubroutineUniformLocation(program, shadertype, name);
}

void glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei * length, GLint * values)
{
    return glmixedbinding::Binding::GetSynciv(sync, pname, count, length, values);
}

void glGetSyncivAPPLE(GLsync sync, GLenum pname, GLsizei count, GLsizei * length, GLint * values)
{
    return glmixedbinding::Binding::GetSyncivAPPLE(sync, pname, count, length, values);
}

void glGetTexBumpParameterfvATI(GLenum pname, GLfloat * param)
{
    return glmixedbinding::Binding::GetTexBumpParameterfvATI(pname, param);
}

void glGetTexBumpParameterivATI(GLenum pname, GLint * param)
{
    return glmixedbinding::Binding::GetTexBumpParameterivATI(pname, param);
}

void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetTexEnvfv(target, pname, params);
}

void glGetTexEnviv(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetTexEnviv(target, pname, params);
}

void glGetTexEnvxvOES(GLenum target, GLenum pname, GLfixed * params)
{
    return glmixedbinding::Binding::GetTexEnvxvOES(target, pname, params);
}

void glGetTexFilterFuncSGIS(GLenum target, GLenum filter, GLfloat * weights)
{
    return glmixedbinding::Binding::GetTexFilterFuncSGIS(target, filter, weights);
}

void glGetTexGendv(GLenum coord, GLenum pname, GLdouble * params)
{
    return glmixedbinding::Binding::GetTexGendv(coord, pname, params);
}

void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetTexGenfv(coord, pname, params);
}

void glGetTexGeniv(GLenum coord, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetTexGeniv(coord, pname, params);
}

void glGetTexGenxvOES(GLenum coord, GLenum pname, GLfixed * params)
{
    return glmixedbinding::Binding::GetTexGenxvOES(coord, pname, params);
}

void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void * pixels)
{
    return glmixedbinding::Binding::GetTexImage(target, level, format, type, pixels);
}

void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetTexLevelParameterfv(target, level, pname, params);
}

void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetTexLevelParameteriv(target, level, pname, params);
}

void glGetTexLevelParameterxvOES(GLenum target, GLint level, GLenum pname, GLfixed * params)
{
    return glmixedbinding::Binding::GetTexLevelParameterxvOES(target, level, pname, params);
}

void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetTexParameterfv(target, pname, params);
}

void glGetTexParameterIiv(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetTexParameterIiv(target, pname, params);
}

void glGetTexParameterIivEXT(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetTexParameterIivEXT(target, pname, params);
}

void glGetTexParameterIivOES(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetTexParameterIivOES(target, pname, params);
}

void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::GetTexParameterIuiv(target, pname, params);
}

void glGetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::GetTexParameterIuivEXT(target, pname, params);
}

void glGetTexParameterIuivOES(GLenum target, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::GetTexParameterIuivOES(target, pname, params);
}

void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetTexParameteriv(target, pname, params);
}

void glGetTexParameterPointervAPPLE(GLenum target, GLenum pname, void ** params)
{
    return glmixedbinding::Binding::GetTexParameterPointervAPPLE(target, pname, params);
}

void glGetTexParameterxvOES(GLenum target, GLenum pname, GLfixed * params)
{
    return glmixedbinding::Binding::GetTexParameterxvOES(target, pname, params);
}

GLuint64 glGetTextureHandleARB(GLuint texture)
{
    return glmixedbinding::Binding::GetTextureHandleARB(texture);
}

GLuint64 glGetTextureHandleIMG(GLuint texture)
{
    return glmixedbinding::Binding::GetTextureHandleIMG(texture);
}

GLuint64 glGetTextureHandleNV(GLuint texture)
{
    return glmixedbinding::Binding::GetTextureHandleNV(texture);
}

void glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels)
{
    return glmixedbinding::Binding::GetTextureImage(texture, level, format, type, bufSize, pixels);
}

void glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void * pixels)
{
    return glmixedbinding::Binding::GetTextureImageEXT(texture, target, level, format, type, pixels);
}

void glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetTextureLevelParameterfv(texture, level, pname, params);
}

void glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetTextureLevelParameterfvEXT(texture, target, level, pname, params);
}

void glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetTextureLevelParameteriv(texture, level, pname, params);
}

void glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetTextureLevelParameterivEXT(texture, target, level, pname, params);
}

void glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetTextureParameterfv(texture, pname, params);
}

void glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetTextureParameterfvEXT(texture, target, pname, params);
}

void glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetTextureParameterIiv(texture, pname, params);
}

void glGetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetTextureParameterIivEXT(texture, target, pname, params);
}

void glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::GetTextureParameterIuiv(texture, pname, params);
}

void glGetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::GetTextureParameterIuivEXT(texture, target, pname, params);
}

void glGetTextureParameteriv(GLuint texture, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetTextureParameteriv(texture, pname, params);
}

void glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetTextureParameterivEXT(texture, target, pname, params);
}

GLuint64 glGetTextureSamplerHandleARB(GLuint texture, GLuint sampler)
{
    return glmixedbinding::Binding::GetTextureSamplerHandleARB(texture, sampler);
}

GLuint64 glGetTextureSamplerHandleIMG(GLuint texture, GLuint sampler)
{
    return glmixedbinding::Binding::GetTextureSamplerHandleIMG(texture, sampler);
}

GLuint64 glGetTextureSamplerHandleNV(GLuint texture, GLuint sampler)
{
    return glmixedbinding::Binding::GetTextureSamplerHandleNV(texture, sampler);
}

void glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void * pixels)
{
    return glmixedbinding::Binding::GetTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels);
}

void glGetTrackMatrixivNV(GLenum target, GLuint address, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetTrackMatrixivNV(target, address, pname, params);
}

void glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64 * param)
{
    return glmixedbinding::Binding::GetTransformFeedbacki64_v(xfb, pname, index, param);
}

void glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint * param)
{
    return glmixedbinding::Binding::GetTransformFeedbacki_v(xfb, pname, index, param);
}

void glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint * param)
{
    return glmixedbinding::Binding::GetTransformFeedbackiv(xfb, pname, param);
}

void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name)
{
    return glmixedbinding::Binding::GetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
}

void glGetTransformFeedbackVaryingEXT(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name)
{
    return glmixedbinding::Binding::GetTransformFeedbackVaryingEXT(program, index, bufSize, length, size, type, name);
}

void glGetTransformFeedbackVaryingNV(GLuint program, GLuint index, GLint * location)
{
    return glmixedbinding::Binding::GetTransformFeedbackVaryingNV(program, index, location);
}

void glGetTranslatedShaderSourceANGLE(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source)
{
    return glmixedbinding::Binding::GetTranslatedShaderSourceANGLE(shader, bufSize, length, source);
}

GLuint glGetUniformBlockIndex(GLuint program, const GLchar * uniformBlockName)
{
    return glmixedbinding::Binding::GetUniformBlockIndex(program, uniformBlockName);
}

GLint glGetUniformBufferSizeEXT(GLuint program, GLint location)
{
    return glmixedbinding::Binding::GetUniformBufferSizeEXT(program, location);
}

void glGetUniformdv(GLuint program, GLint location, GLdouble * params)
{
    return glmixedbinding::Binding::GetUniformdv(program, location, params);
}

void glGetUniformfv(GLuint program, GLint location, GLfloat * params)
{
    return glmixedbinding::Binding::GetUniformfv(program, location, params);
}

void glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat * params)
{
    return glmixedbinding::Binding::GetUniformfvARB(programObj, location, params);
}

void glGetUniformi64vARB(GLuint program, GLint location, GLint64 * params)
{
    return glmixedbinding::Binding::GetUniformi64vARB(program, location, params);
}

void glGetUniformi64vNV(GLuint program, GLint location, GLint64EXT * params)
{
    return glmixedbinding::Binding::GetUniformi64vNV(program, location, params);
}

void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices)
{
    return glmixedbinding::Binding::GetUniformIndices(program, uniformCount, uniformNames, uniformIndices);
}

void glGetUniformiv(GLuint program, GLint location, GLint * params)
{
    return glmixedbinding::Binding::GetUniformiv(program, location, params);
}

void glGetUniformivARB(GLhandleARB programObj, GLint location, GLint * params)
{
    return glmixedbinding::Binding::GetUniformivARB(programObj, location, params);
}

GLint glGetUniformLocation(GLuint program, const GLchar * name)
{
    return glmixedbinding::Binding::GetUniformLocation(program, name);
}

GLint glGetUniformLocationARB(GLhandleARB programObj, const GLcharARB * name)
{
    return glmixedbinding::Binding::GetUniformLocationARB(programObj, name);
}

GLintptr glGetUniformOffsetEXT(GLuint program, GLint location)
{
    return glmixedbinding::Binding::GetUniformOffsetEXT(program, location);
}

void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint * params)
{
    return glmixedbinding::Binding::GetUniformSubroutineuiv(shadertype, location, params);
}

void glGetUniformui64vARB(GLuint program, GLint location, GLuint64 * params)
{
    return glmixedbinding::Binding::GetUniformui64vARB(program, location, params);
}

void glGetUniformui64vNV(GLuint program, GLint location, GLuint64EXT * params)
{
    return glmixedbinding::Binding::GetUniformui64vNV(program, location, params);
}

void glGetUniformuiv(GLuint program, GLint location, GLuint * params)
{
    return glmixedbinding::Binding::GetUniformuiv(program, location, params);
}

void glGetUniformuivEXT(GLuint program, GLint location, GLuint * params)
{
    return glmixedbinding::Binding::GetUniformuivEXT(program, location, params);
}

void glGetUnsignedBytei_vEXT(GLenum target, GLuint index, GLubyte * data)
{
    return glmixedbinding::Binding::GetUnsignedBytei_vEXT(target, index, data);
}

void glGetUnsignedBytevEXT(GLenum pname, GLubyte * data)
{
    return glmixedbinding::Binding::GetUnsignedBytevEXT(pname, data);
}

void glGetVariantArrayObjectfvATI(GLuint id, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetVariantArrayObjectfvATI(id, pname, params);
}

void glGetVariantArrayObjectivATI(GLuint id, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetVariantArrayObjectivATI(id, pname, params);
}

void glGetVariantBooleanvEXT(GLuint id, GLenum value, GLboolean * data)
{
    return glmixedbinding::Binding::GetVariantBooleanvEXT(id, value, data);
}

void glGetVariantFloatvEXT(GLuint id, GLenum value, GLfloat * data)
{
    return glmixedbinding::Binding::GetVariantFloatvEXT(id, value, data);
}

void glGetVariantIntegervEXT(GLuint id, GLenum value, GLint * data)
{
    return glmixedbinding::Binding::GetVariantIntegervEXT(id, value, data);
}

void glGetVariantPointervEXT(GLuint id, GLenum value, void ** data)
{
    return glmixedbinding::Binding::GetVariantPointervEXT(id, value, data);
}

GLint glGetVaryingLocationNV(GLuint program, const GLchar * name)
{
    return glmixedbinding::Binding::GetVaryingLocationNV(program, name);
}

void glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64 * param)
{
    return glmixedbinding::Binding::GetVertexArrayIndexed64iv(vaobj, index, pname, param);
}

void glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint * param)
{
    return glmixedbinding::Binding::GetVertexArrayIndexediv(vaobj, index, pname, param);
}

void glGetVertexArrayIntegeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLint * param)
{
    return glmixedbinding::Binding::GetVertexArrayIntegeri_vEXT(vaobj, index, pname, param);
}

void glGetVertexArrayIntegervEXT(GLuint vaobj, GLenum pname, GLint * param)
{
    return glmixedbinding::Binding::GetVertexArrayIntegervEXT(vaobj, pname, param);
}

void glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint * param)
{
    return glmixedbinding::Binding::GetVertexArrayiv(vaobj, pname, param);
}

void glGetVertexArrayPointeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, void ** param)
{
    return glmixedbinding::Binding::GetVertexArrayPointeri_vEXT(vaobj, index, pname, param);
}

void glGetVertexArrayPointervEXT(GLuint vaobj, GLenum pname, void ** param)
{
    return glmixedbinding::Binding::GetVertexArrayPointervEXT(vaobj, pname, param);
}

void glGetVertexAttribArrayObjectfvATI(GLuint index, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetVertexAttribArrayObjectfvATI(index, pname, params);
}

void glGetVertexAttribArrayObjectivATI(GLuint index, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetVertexAttribArrayObjectivATI(index, pname, params);
}

void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble * params)
{
    return glmixedbinding::Binding::GetVertexAttribdv(index, pname, params);
}

void glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble * params)
{
    return glmixedbinding::Binding::GetVertexAttribdvARB(index, pname, params);
}

void glGetVertexAttribdvNV(GLuint index, GLenum pname, GLdouble * params)
{
    return glmixedbinding::Binding::GetVertexAttribdvNV(index, pname, params);
}

void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetVertexAttribfv(index, pname, params);
}

void glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetVertexAttribfvARB(index, pname, params);
}

void glGetVertexAttribfvNV(GLuint index, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetVertexAttribfvNV(index, pname, params);
}

void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetVertexAttribIiv(index, pname, params);
}

void glGetVertexAttribIivEXT(GLuint index, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetVertexAttribIivEXT(index, pname, params);
}

void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::GetVertexAttribIuiv(index, pname, params);
}

void glGetVertexAttribIuivEXT(GLuint index, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::GetVertexAttribIuivEXT(index, pname, params);
}

void glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetVertexAttribiv(index, pname, params);
}

void glGetVertexAttribivARB(GLuint index, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetVertexAttribivARB(index, pname, params);
}

void glGetVertexAttribivNV(GLuint index, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetVertexAttribivNV(index, pname, params);
}

void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble * params)
{
    return glmixedbinding::Binding::GetVertexAttribLdv(index, pname, params);
}

void glGetVertexAttribLdvEXT(GLuint index, GLenum pname, GLdouble * params)
{
    return glmixedbinding::Binding::GetVertexAttribLdvEXT(index, pname, params);
}

void glGetVertexAttribLi64vNV(GLuint index, GLenum pname, GLint64EXT * params)
{
    return glmixedbinding::Binding::GetVertexAttribLi64vNV(index, pname, params);
}

void glGetVertexAttribLui64vARB(GLuint index, GLenum pname, GLuint64EXT * params)
{
    return glmixedbinding::Binding::GetVertexAttribLui64vARB(index, pname, params);
}

void glGetVertexAttribLui64vNV(GLuint index, GLenum pname, GLuint64EXT * params)
{
    return glmixedbinding::Binding::GetVertexAttribLui64vNV(index, pname, params);
}

void glGetVertexAttribPointerv(GLuint index, GLenum pname, void ** pointer)
{
    return glmixedbinding::Binding::GetVertexAttribPointerv(index, pname, pointer);
}

void glGetVertexAttribPointervARB(GLuint index, GLenum pname, void ** pointer)
{
    return glmixedbinding::Binding::GetVertexAttribPointervARB(index, pname, pointer);
}

void glGetVertexAttribPointervNV(GLuint index, GLenum pname, void ** pointer)
{
    return glmixedbinding::Binding::GetVertexAttribPointervNV(index, pname, pointer);
}

void glGetVideoCaptureivNV(GLuint video_capture_slot, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetVideoCaptureivNV(video_capture_slot, pname, params);
}

void glGetVideoCaptureStreamdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble * params)
{
    return glmixedbinding::Binding::GetVideoCaptureStreamdvNV(video_capture_slot, stream, pname, params);
}

void glGetVideoCaptureStreamfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat * params)
{
    return glmixedbinding::Binding::GetVideoCaptureStreamfvNV(video_capture_slot, stream, pname, params);
}

void glGetVideoCaptureStreamivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetVideoCaptureStreamivNV(video_capture_slot, stream, pname, params);
}

void glGetVideoi64vNV(GLuint video_slot, GLenum pname, GLint64EXT * params)
{
    return glmixedbinding::Binding::GetVideoi64vNV(video_slot, pname, params);
}

void glGetVideoivNV(GLuint video_slot, GLenum pname, GLint * params)
{
    return glmixedbinding::Binding::GetVideoivNV(video_slot, pname, params);
}

void glGetVideoui64vNV(GLuint video_slot, GLenum pname, GLuint64EXT * params)
{
    return glmixedbinding::Binding::GetVideoui64vNV(video_slot, pname, params);
}

void glGetVideouivNV(GLuint video_slot, GLenum pname, GLuint * params)
{
    return glmixedbinding::Binding::GetVideouivNV(video_slot, pname, params);
}

GLVULKANPROCNV glGetVkProcAddrNV(const GLchar * name)
{
    return glmixedbinding::Binding::GetVkProcAddrNV(name);
}

void glGlobalAlphaFactorbSUN(GLbyte factor)
{
    return glmixedbinding::Binding::GlobalAlphaFactorbSUN(factor);
}

void glGlobalAlphaFactordSUN(GLdouble factor)
{
    return glmixedbinding::Binding::GlobalAlphaFactordSUN(factor);
}

void glGlobalAlphaFactorfSUN(GLfloat factor)
{
    return glmixedbinding::Binding::GlobalAlphaFactorfSUN(factor);
}

void glGlobalAlphaFactoriSUN(GLint factor)
{
    return glmixedbinding::Binding::GlobalAlphaFactoriSUN(factor);
}

void glGlobalAlphaFactorsSUN(GLshort factor)
{
    return glmixedbinding::Binding::GlobalAlphaFactorsSUN(factor);
}

void glGlobalAlphaFactorubSUN(GLubyte factor)
{
    return glmixedbinding::Binding::GlobalAlphaFactorubSUN(factor);
}

void glGlobalAlphaFactoruiSUN(GLuint factor)
{
    return glmixedbinding::Binding::GlobalAlphaFactoruiSUN(factor);
}

void glGlobalAlphaFactorusSUN(GLushort factor)
{
    return glmixedbinding::Binding::GlobalAlphaFactorusSUN(factor);
}


} // namespace glmixed