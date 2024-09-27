
#include "../Binding_pch.h"

#include <glmixedbinding/glmixed/functions.h>


namespace glmixed
{


void glDebugMessageCallback(GLDEBUGPROC callback, const void * userParam)
{
    return glmixedbinding::Binding::DebugMessageCallback(callback, userParam);
}

void glDebugMessageCallbackAMD(GLDEBUGPROCAMD callback, void * userParam)
{
    return glmixedbinding::Binding::DebugMessageCallbackAMD(callback, userParam);
}

void glDebugMessageCallbackARB(GLDEBUGPROCARB callback, const void * userParam)
{
    return glmixedbinding::Binding::DebugMessageCallbackARB(callback, userParam);
}

void glDebugMessageCallbackKHR(GLDEBUGPROCKHR callback, const void * userParam)
{
    return glmixedbinding::Binding::DebugMessageCallbackKHR(callback, userParam);
}

void glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled)
{
    return glmixedbinding::Binding::DebugMessageControl(source, type, severity, count, ids, enabled);
}

void glDebugMessageControlARB(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled)
{
    return glmixedbinding::Binding::DebugMessageControlARB(source, type, severity, count, ids, enabled);
}

void glDebugMessageControlKHR(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled)
{
    return glmixedbinding::Binding::DebugMessageControlKHR(source, type, severity, count, ids, enabled);
}

void glDebugMessageEnableAMD(GLenum category, GLenum severity, GLsizei count, const GLuint * ids, GLboolean enabled)
{
    return glmixedbinding::Binding::DebugMessageEnableAMD(category, severity, count, ids, enabled);
}

void glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf)
{
    return glmixedbinding::Binding::DebugMessageInsert(source, type, id, severity, length, buf);
}

void glDebugMessageInsertAMD(GLenum category, GLenum severity, GLuint id, GLsizei length, const GLchar * buf)
{
    return glmixedbinding::Binding::DebugMessageInsertAMD(category, severity, id, length, buf);
}

void glDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf)
{
    return glmixedbinding::Binding::DebugMessageInsertARB(source, type, id, severity, length, buf);
}

void glDebugMessageInsertKHR(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar * buf)
{
    return glmixedbinding::Binding::DebugMessageInsertKHR(source, type, id, severity, length, buf);
}

void glDeformationMap3dSGIX(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble * points)
{
    return glmixedbinding::Binding::DeformationMap3dSGIX(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points);
}

void glDeformationMap3fSGIX(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat * points)
{
    return glmixedbinding::Binding::DeformationMap3fSGIX(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points);
}

void glDeformSGIX(FfdMaskSGIX mask)
{
    return glmixedbinding::Binding::DeformSGIX(mask);
}

void glDeleteAsyncMarkersSGIX(GLuint marker, GLsizei range)
{
    return glmixedbinding::Binding::DeleteAsyncMarkersSGIX(marker, range);
}

void glDeleteBuffers(GLsizei n, const GLuint * buffers)
{
    return glmixedbinding::Binding::DeleteBuffers(n, buffers);
}

void glDeleteBuffersARB(GLsizei n, const GLuint * buffers)
{
    return glmixedbinding::Binding::DeleteBuffersARB(n, buffers);
}

void glDeleteCommandListsNV(GLsizei n, const GLuint * lists)
{
    return glmixedbinding::Binding::DeleteCommandListsNV(n, lists);
}

void glDeleteFencesAPPLE(GLsizei n, const GLuint * fences)
{
    return glmixedbinding::Binding::DeleteFencesAPPLE(n, fences);
}

void glDeleteFencesNV(GLsizei n, const GLuint * fences)
{
    return glmixedbinding::Binding::DeleteFencesNV(n, fences);
}

void glDeleteFragmentShaderATI(GLuint id)
{
    return glmixedbinding::Binding::DeleteFragmentShaderATI(id);
}

void glDeleteFramebuffers(GLsizei n, const GLuint * framebuffers)
{
    return glmixedbinding::Binding::DeleteFramebuffers(n, framebuffers);
}

void glDeleteFramebuffersEXT(GLsizei n, const GLuint * framebuffers)
{
    return glmixedbinding::Binding::DeleteFramebuffersEXT(n, framebuffers);
}

void glDeleteLists(GLuint list, GLsizei range)
{
    return glmixedbinding::Binding::DeleteLists(list, range);
}

void glDeleteMemoryObjectsEXT(GLsizei n, const GLuint * memoryObjects)
{
    return glmixedbinding::Binding::DeleteMemoryObjectsEXT(n, memoryObjects);
}

void glDeleteNamedStringARB(GLint namelen, const GLchar * name)
{
    return glmixedbinding::Binding::DeleteNamedStringARB(namelen, name);
}

void glDeleteNamesAMD(GLenum identifier, GLuint num, const GLuint * names)
{
    return glmixedbinding::Binding::DeleteNamesAMD(identifier, num, names);
}

void glDeleteObjectARB(GLhandleARB obj)
{
    return glmixedbinding::Binding::DeleteObjectARB(obj);
}

void glDeleteOcclusionQueriesNV(GLsizei n, const GLuint * ids)
{
    return glmixedbinding::Binding::DeleteOcclusionQueriesNV(n, ids);
}

void glDeletePathsNV(GLuint path, GLsizei range)
{
    return glmixedbinding::Binding::DeletePathsNV(path, range);
}

void glDeletePerfMonitorsAMD(GLsizei n, GLuint * monitors)
{
    return glmixedbinding::Binding::DeletePerfMonitorsAMD(n, monitors);
}

void glDeletePerfQueryINTEL(GLuint queryHandle)
{
    return glmixedbinding::Binding::DeletePerfQueryINTEL(queryHandle);
}

void glDeleteProgram(GLuint program)
{
    return glmixedbinding::Binding::DeleteProgram(program);
}

void glDeleteProgramPipelines(GLsizei n, const GLuint * pipelines)
{
    return glmixedbinding::Binding::DeleteProgramPipelines(n, pipelines);
}

void glDeleteProgramPipelinesEXT(GLsizei n, const GLuint * pipelines)
{
    return glmixedbinding::Binding::DeleteProgramPipelinesEXT(n, pipelines);
}

void glDeleteProgramsARB(GLsizei n, const GLuint * programs)
{
    return glmixedbinding::Binding::DeleteProgramsARB(n, programs);
}

void glDeleteProgramsNV(GLsizei n, const GLuint * programs)
{
    return glmixedbinding::Binding::DeleteProgramsNV(n, programs);
}

void glDeleteQueries(GLsizei n, const GLuint * ids)
{
    return glmixedbinding::Binding::DeleteQueries(n, ids);
}

void glDeleteQueriesARB(GLsizei n, const GLuint * ids)
{
    return glmixedbinding::Binding::DeleteQueriesARB(n, ids);
}

void glDeleteQueriesEXT(GLsizei n, const GLuint * ids)
{
    return glmixedbinding::Binding::DeleteQueriesEXT(n, ids);
}

void glDeleteQueryResourceTagNV(GLsizei n, const GLint * tagIds)
{
    return glmixedbinding::Binding::DeleteQueryResourceTagNV(n, tagIds);
}

void glDeleteRenderbuffers(GLsizei n, const GLuint * renderbuffers)
{
    return glmixedbinding::Binding::DeleteRenderbuffers(n, renderbuffers);
}

void glDeleteRenderbuffersEXT(GLsizei n, const GLuint * renderbuffers)
{
    return glmixedbinding::Binding::DeleteRenderbuffersEXT(n, renderbuffers);
}

void glDeleteSamplers(GLsizei count, const GLuint * samplers)
{
    return glmixedbinding::Binding::DeleteSamplers(count, samplers);
}

void glDeleteSemaphoresEXT(GLsizei n, const GLuint * semaphores)
{
    return glmixedbinding::Binding::DeleteSemaphoresEXT(n, semaphores);
}

void glDeleteShader(GLuint shader)
{
    return glmixedbinding::Binding::DeleteShader(shader);
}

void glDeleteStatesNV(GLsizei n, const GLuint * states)
{
    return glmixedbinding::Binding::DeleteStatesNV(n, states);
}

void glDeleteSync(GLsync sync)
{
    return glmixedbinding::Binding::DeleteSync(sync);
}

void glDeleteSyncAPPLE(GLsync sync)
{
    return glmixedbinding::Binding::DeleteSyncAPPLE(sync);
}

void glDeleteTextures(GLsizei n, const GLuint * textures)
{
    return glmixedbinding::Binding::DeleteTextures(n, textures);
}

void glDeleteTexturesEXT(GLsizei n, const GLuint * textures)
{
    return glmixedbinding::Binding::DeleteTexturesEXT(n, textures);
}

void glDeleteTransformFeedbacks(GLsizei n, const GLuint * ids)
{
    return glmixedbinding::Binding::DeleteTransformFeedbacks(n, ids);
}

void glDeleteTransformFeedbacksNV(GLsizei n, const GLuint * ids)
{
    return glmixedbinding::Binding::DeleteTransformFeedbacksNV(n, ids);
}

void glDeleteVertexArrays(GLsizei n, const GLuint * arrays)
{
    return glmixedbinding::Binding::DeleteVertexArrays(n, arrays);
}

void glDeleteVertexArraysAPPLE(GLsizei n, const GLuint * arrays)
{
    return glmixedbinding::Binding::DeleteVertexArraysAPPLE(n, arrays);
}

void glDeleteVertexArraysOES(GLsizei n, const GLuint * arrays)
{
    return glmixedbinding::Binding::DeleteVertexArraysOES(n, arrays);
}

void glDeleteVertexShaderEXT(GLuint id)
{
    return glmixedbinding::Binding::DeleteVertexShaderEXT(id);
}

void glDepthBoundsdNV(GLdouble zmin, GLdouble zmax)
{
    return glmixedbinding::Binding::DepthBoundsdNV(zmin, zmax);
}

void glDepthBoundsEXT(GLclampd zmin, GLclampd zmax)
{
    return glmixedbinding::Binding::DepthBoundsEXT(zmin, zmax);
}

void glDepthFunc(GLenum func)
{
    return glmixedbinding::Binding::DepthFunc(func);
}

void glDepthMask(GLboolean flag)
{
    return glmixedbinding::Binding::DepthMask(flag);
}

void glDepthRange(GLdouble n, GLdouble f)
{
    return glmixedbinding::Binding::DepthRange(n, f);
}

void glDepthRangeArraydvNV(GLuint first, GLsizei count, const GLdouble * v)
{
    return glmixedbinding::Binding::DepthRangeArraydvNV(first, count, v);
}

void glDepthRangeArrayfvNV(GLuint first, GLsizei count, const GLfloat * v)
{
    return glmixedbinding::Binding::DepthRangeArrayfvNV(first, count, v);
}

void glDepthRangeArrayfvOES(GLuint first, GLsizei count, const GLfloat * v)
{
    return glmixedbinding::Binding::DepthRangeArrayfvOES(first, count, v);
}

void glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble * v)
{
    return glmixedbinding::Binding::DepthRangeArrayv(first, count, v);
}

void glDepthRangedNV(GLdouble zNear, GLdouble zFar)
{
    return glmixedbinding::Binding::DepthRangedNV(zNear, zFar);
}

void glDepthRangef(GLfloat n, GLfloat f)
{
    return glmixedbinding::Binding::DepthRangef(n, f);
}

void glDepthRangefOES(GLclampf n, GLclampf f)
{
    return glmixedbinding::Binding::DepthRangefOES(n, f);
}

void glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f)
{
    return glmixedbinding::Binding::DepthRangeIndexed(index, n, f);
}

void glDepthRangeIndexeddNV(GLuint index, GLdouble n, GLdouble f)
{
    return glmixedbinding::Binding::DepthRangeIndexeddNV(index, n, f);
}

void glDepthRangeIndexedfNV(GLuint index, GLfloat n, GLfloat f)
{
    return glmixedbinding::Binding::DepthRangeIndexedfNV(index, n, f);
}

void glDepthRangeIndexedfOES(GLuint index, GLfloat n, GLfloat f)
{
    return glmixedbinding::Binding::DepthRangeIndexedfOES(index, n, f);
}

void glDepthRangexOES(GLfixed n, GLfixed f)
{
    return glmixedbinding::Binding::DepthRangexOES(n, f);
}

void glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj)
{
    return glmixedbinding::Binding::DetachObjectARB(containerObj, attachedObj);
}

void glDetachShader(GLuint program, GLuint shader)
{
    return glmixedbinding::Binding::DetachShader(program, shader);
}

void glDetailTexFuncSGIS(GLenum target, GLsizei n, const GLfloat * points)
{
    return glmixedbinding::Binding::DetailTexFuncSGIS(target, n, points);
}

void glDisable(GLenum cap)
{
    return glmixedbinding::Binding::Disable(cap);
}

void glDisableClientState(GLenum array)
{
    return glmixedbinding::Binding::DisableClientState(array);
}

void glDisableClientStateiEXT(GLenum array, GLuint index)
{
    return glmixedbinding::Binding::DisableClientStateiEXT(array, index);
}

void glDisableClientStateIndexedEXT(GLenum array, GLuint index)
{
    return glmixedbinding::Binding::DisableClientStateIndexedEXT(array, index);
}

void glDisableDriverControlQCOM(GLuint driverControl)
{
    return glmixedbinding::Binding::DisableDriverControlQCOM(driverControl);
}

void glDisablei(GLenum target, GLuint index)
{
    return glmixedbinding::Binding::Disablei(target, index);
}

void glDisableiEXT(GLenum target, GLuint index)
{
    return glmixedbinding::Binding::DisableiEXT(target, index);
}

void glDisableIndexedEXT(GLenum target, GLuint index)
{
    return glmixedbinding::Binding::DisableIndexedEXT(target, index);
}

void glDisableiNV(GLenum target, GLuint index)
{
    return glmixedbinding::Binding::DisableiNV(target, index);
}

void glDisableiOES(GLenum target, GLuint index)
{
    return glmixedbinding::Binding::DisableiOES(target, index);
}

void glDisableVariantClientStateEXT(GLuint id)
{
    return glmixedbinding::Binding::DisableVariantClientStateEXT(id);
}

void glDisableVertexArrayAttrib(GLuint vaobj, GLuint index)
{
    return glmixedbinding::Binding::DisableVertexArrayAttrib(vaobj, index);
}

void glDisableVertexArrayAttribEXT(GLuint vaobj, GLuint index)
{
    return glmixedbinding::Binding::DisableVertexArrayAttribEXT(vaobj, index);
}

void glDisableVertexArrayEXT(GLuint vaobj, GLenum array)
{
    return glmixedbinding::Binding::DisableVertexArrayEXT(vaobj, array);
}

void glDisableVertexAttribAPPLE(GLuint index, GLenum pname)
{
    return glmixedbinding::Binding::DisableVertexAttribAPPLE(index, pname);
}

void glDisableVertexAttribArray(GLuint index)
{
    return glmixedbinding::Binding::DisableVertexAttribArray(index);
}

void glDisableVertexAttribArrayARB(GLuint index)
{
    return glmixedbinding::Binding::DisableVertexAttribArrayARB(index);
}

void glDiscardFramebufferEXT(GLenum target, GLsizei numAttachments, const GLenum * attachments)
{
    return glmixedbinding::Binding::DiscardFramebufferEXT(target, numAttachments, attachments);
}

void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z)
{
    return glmixedbinding::Binding::DispatchCompute(num_groups_x, num_groups_y, num_groups_z);
}

void glDispatchComputeGroupSizeARB(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z)
{
    return glmixedbinding::Binding::DispatchComputeGroupSizeARB(num_groups_x, num_groups_y, num_groups_z, group_size_x, group_size_y, group_size_z);
}

void glDispatchComputeIndirect(GLintptr indirect)
{
    return glmixedbinding::Binding::DispatchComputeIndirect(indirect);
}

void glDrawArrays(GLenum mode, GLint first, GLsizei count)
{
    return glmixedbinding::Binding::DrawArrays(mode, first, count);
}

void glDrawArraysEXT(GLenum mode, GLint first, GLsizei count)
{
    return glmixedbinding::Binding::DrawArraysEXT(mode, first, count);
}

void glDrawArraysIndirect(GLenum mode, const void * indirect)
{
    return glmixedbinding::Binding::DrawArraysIndirect(mode, indirect);
}

void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount)
{
    return glmixedbinding::Binding::DrawArraysInstanced(mode, first, count, instancecount);
}

void glDrawArraysInstancedANGLE(GLenum mode, GLint first, GLsizei count, GLsizei primcount)
{
    return glmixedbinding::Binding::DrawArraysInstancedANGLE(mode, first, count, primcount);
}

void glDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount)
{
    return glmixedbinding::Binding::DrawArraysInstancedARB(mode, first, count, primcount);
}

void glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance)
{
    return glmixedbinding::Binding::DrawArraysInstancedBaseInstance(mode, first, count, instancecount, baseinstance);
}

void glDrawArraysInstancedBaseInstanceEXT(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance)
{
    return glmixedbinding::Binding::DrawArraysInstancedBaseInstanceEXT(mode, first, count, instancecount, baseinstance);
}

void glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount)
{
    return glmixedbinding::Binding::DrawArraysInstancedEXT(mode, start, count, primcount);
}

void glDrawArraysInstancedNV(GLenum mode, GLint first, GLsizei count, GLsizei primcount)
{
    return glmixedbinding::Binding::DrawArraysInstancedNV(mode, first, count, primcount);
}

void glDrawBuffer(GLenum buf)
{
    return glmixedbinding::Binding::DrawBuffer(buf);
}

void glDrawBuffers(GLsizei n, const GLenum * bufs)
{
    return glmixedbinding::Binding::DrawBuffers(n, bufs);
}

void glDrawBuffersARB(GLsizei n, const GLenum * bufs)
{
    return glmixedbinding::Binding::DrawBuffersARB(n, bufs);
}

void glDrawBuffersATI(GLsizei n, const GLenum * bufs)
{
    return glmixedbinding::Binding::DrawBuffersATI(n, bufs);
}

void glDrawBuffersEXT(GLsizei n, const GLenum * bufs)
{
    return glmixedbinding::Binding::DrawBuffersEXT(n, bufs);
}

void glDrawBuffersIndexedEXT(GLint n, const GLenum * location, const GLint * indices)
{
    return glmixedbinding::Binding::DrawBuffersIndexedEXT(n, location, indices);
}

void glDrawBuffersNV(GLsizei n, const GLenum * bufs)
{
    return glmixedbinding::Binding::DrawBuffersNV(n, bufs);
}

void glDrawCommandsAddressNV(GLenum primitiveMode, const GLuint64 * indirects, const GLsizei * sizes, GLuint count)
{
    return glmixedbinding::Binding::DrawCommandsAddressNV(primitiveMode, indirects, sizes, count);
}

void glDrawCommandsNV(GLenum primitiveMode, GLuint buffer, const GLintptr * indirects, const GLsizei * sizes, GLuint count)
{
    return glmixedbinding::Binding::DrawCommandsNV(primitiveMode, buffer, indirects, sizes, count);
}

void glDrawCommandsStatesAddressNV(const GLuint64 * indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count)
{
    return glmixedbinding::Binding::DrawCommandsStatesAddressNV(indirects, sizes, states, fbos, count);
}

void glDrawCommandsStatesNV(GLuint buffer, const GLintptr * indirects, const GLsizei * sizes, const GLuint * states, const GLuint * fbos, GLuint count)
{
    return glmixedbinding::Binding::DrawCommandsStatesNV(buffer, indirects, sizes, states, fbos, count);
}

void glDrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count)
{
    return glmixedbinding::Binding::DrawElementArrayAPPLE(mode, first, count);
}

void glDrawElementArrayATI(GLenum mode, GLsizei count)
{
    return glmixedbinding::Binding::DrawElementArrayATI(mode, count);
}

void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void * indices)
{
    return glmixedbinding::Binding::DrawElements(mode, count, type, indices);
}

void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex)
{
    return glmixedbinding::Binding::DrawElementsBaseVertex(mode, count, type, indices, basevertex);
}

void glDrawElementsBaseVertexEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex)
{
    return glmixedbinding::Binding::DrawElementsBaseVertexEXT(mode, count, type, indices, basevertex);
}

void glDrawElementsBaseVertexOES(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex)
{
    return glmixedbinding::Binding::DrawElementsBaseVertexOES(mode, count, type, indices, basevertex);
}

void glDrawElementsIndirect(GLenum mode, GLenum type, const void * indirect)
{
    return glmixedbinding::Binding::DrawElementsIndirect(mode, type, indirect);
}

void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount)
{
    return glmixedbinding::Binding::DrawElementsInstanced(mode, count, type, indices, instancecount);
}

void glDrawElementsInstancedANGLE(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount)
{
    return glmixedbinding::Binding::DrawElementsInstancedANGLE(mode, count, type, indices, primcount);
}

void glDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount)
{
    return glmixedbinding::Binding::DrawElementsInstancedARB(mode, count, type, indices, primcount);
}

void glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance)
{
    return glmixedbinding::Binding::DrawElementsInstancedBaseInstance(mode, count, type, indices, instancecount, baseinstance);
}

void glDrawElementsInstancedBaseInstanceEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance)
{
    return glmixedbinding::Binding::DrawElementsInstancedBaseInstanceEXT(mode, count, type, indices, instancecount, baseinstance);
}

void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex)
{
    return glmixedbinding::Binding::DrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex);
}

void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance)
{
    return glmixedbinding::Binding::DrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, instancecount, basevertex, baseinstance);
}

void glDrawElementsInstancedBaseVertexBaseInstanceEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance)
{
    return glmixedbinding::Binding::DrawElementsInstancedBaseVertexBaseInstanceEXT(mode, count, type, indices, instancecount, basevertex, baseinstance);
}

void glDrawElementsInstancedBaseVertexEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex)
{
    return glmixedbinding::Binding::DrawElementsInstancedBaseVertexEXT(mode, count, type, indices, instancecount, basevertex);
}

void glDrawElementsInstancedBaseVertexOES(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex)
{
    return glmixedbinding::Binding::DrawElementsInstancedBaseVertexOES(mode, count, type, indices, instancecount, basevertex);
}

void glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount)
{
    return glmixedbinding::Binding::DrawElementsInstancedEXT(mode, count, type, indices, primcount);
}

void glDrawElementsInstancedNV(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei primcount)
{
    return glmixedbinding::Binding::DrawElementsInstancedNV(mode, count, type, indices, primcount);
}

void glDrawMeshArraysSUN(GLenum mode, GLint first, GLsizei count, GLsizei width)
{
    return glmixedbinding::Binding::DrawMeshArraysSUN(mode, first, count, width);
}

void glDrawMeshTasksIndirectNV(GLintptr indirect)
{
    return glmixedbinding::Binding::DrawMeshTasksIndirectNV(indirect);
}

void glDrawMeshTasksNV(GLuint first, GLuint count)
{
    return glmixedbinding::Binding::DrawMeshTasksNV(first, count);
}

void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels)
{
    return glmixedbinding::Binding::DrawPixels(width, height, format, type, pixels);
}

void glDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count)
{
    return glmixedbinding::Binding::DrawRangeElementArrayAPPLE(mode, start, end, first, count);
}

void glDrawRangeElementArrayATI(GLenum mode, GLuint start, GLuint end, GLsizei count)
{
    return glmixedbinding::Binding::DrawRangeElementArrayATI(mode, start, end, count);
}

void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices)
{
    return glmixedbinding::Binding::DrawRangeElements(mode, start, end, count, type, indices);
}

void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex)
{
    return glmixedbinding::Binding::DrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex);
}

void glDrawRangeElementsBaseVertexEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex)
{
    return glmixedbinding::Binding::DrawRangeElementsBaseVertexEXT(mode, start, end, count, type, indices, basevertex);
}

void glDrawRangeElementsBaseVertexOES(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex)
{
    return glmixedbinding::Binding::DrawRangeElementsBaseVertexOES(mode, start, end, count, type, indices, basevertex);
}

void glDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices)
{
    return glmixedbinding::Binding::DrawRangeElementsEXT(mode, start, end, count, type, indices);
}

void glDrawTextureNV(GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1)
{
    return glmixedbinding::Binding::DrawTextureNV(texture, sampler, x0, y0, x1, y1, z, s0, t0, s1, t1);
}

void glDrawTransformFeedback(GLenum mode, GLuint id)
{
    return glmixedbinding::Binding::DrawTransformFeedback(mode, id);
}

void glDrawTransformFeedbackEXT(GLenum mode, GLuint id)
{
    return glmixedbinding::Binding::DrawTransformFeedbackEXT(mode, id);
}

void glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount)
{
    return glmixedbinding::Binding::DrawTransformFeedbackInstanced(mode, id, instancecount);
}

void glDrawTransformFeedbackInstancedEXT(GLenum mode, GLuint id, GLsizei instancecount)
{
    return glmixedbinding::Binding::DrawTransformFeedbackInstancedEXT(mode, id, instancecount);
}

void glDrawTransformFeedbackNV(GLenum mode, GLuint id)
{
    return glmixedbinding::Binding::DrawTransformFeedbackNV(mode, id);
}

void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream)
{
    return glmixedbinding::Binding::DrawTransformFeedbackStream(mode, id, stream);
}

void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount)
{
    return glmixedbinding::Binding::DrawTransformFeedbackStreamInstanced(mode, id, stream, instancecount);
}

void glDrawVkImageNV(GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1)
{
    return glmixedbinding::Binding::DrawVkImageNV(vkImage, sampler, x0, y0, x1, y1, z, s0, t0, s1, t1);
}


} // namespace glmixed