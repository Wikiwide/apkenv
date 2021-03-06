#ifdef APKENV_GLES2

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#define IN_GLES2_WRAPPERS
#include "gles2_wrappers.h"
#include <assert.h>

#ifdef APKENV_DEBUG
#  define WRAPPERS_DEBUG_PRINTF(...) printf("%d %s", pthread_self(), __VA_ARGS__)
#else
#  define WRAPPERS_DEBUG_PRINTF(...)
#endif

#include <pthread.h>
#include <dlfcn.h>

struct gles2_functions {
    void         (*glActiveTexture)(GLenum texture);
    void         (*glAttachShader)(GLuint program, GLuint shader);
    void         (*glBindAttribLocation)(GLuint program, GLuint index, const GLchar* name);
    void         (*glBindBuffer)(GLenum target, GLuint buffer);
    void         (*glBindFramebuffer)(GLenum target, GLuint framebuffer);
    void         (*glBindRenderbuffer)(GLenum target, GLuint renderbuffer);
    void         (*glBindTexture)(GLenum target, GLuint texture);
    void         (*glBlendColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
    void         (*glBlendEquation)( GLenum mode );
    void         (*glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha);
    void         (*glBlendFunc)(GLenum sfactor, GLenum dfactor);
    void         (*glBlendFuncSeparate)(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
    void         (*glBufferData)(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
    void         (*glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data);
    GLenum       (*glCheckFramebufferStatus)(GLenum target);
    void         (*glClear)(GLbitfield mask);
    void         (*glClearColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
    void         (*glClearDepthf)(GLclampf depth);
    void         (*glClearStencil)(GLint s);
    void         (*glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
    void         (*glCompileShader)(GLuint shader);
    void         (*glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid* data);
    void         (*glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid* data);
    void         (*glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
    void         (*glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
    GLuint       (*glCreateProgram)(void);
    GLuint       (*glCreateShader)(GLenum type);
    void         (*glCullFace)(GLenum mode);
    void         (*glDeleteBuffers)(GLsizei n, const GLuint* buffers);
    void         (*glDeleteFramebuffers)(GLsizei n, const GLuint* framebuffers);
    void         (*glDeleteProgram)(GLuint program);
    void         (*glDeleteRenderbuffers)(GLsizei n, const GLuint* renderbuffers);
    void         (*glDeleteShader)(GLuint shader);
    void         (*glDeleteTextures)(GLsizei n, const GLuint* textures);
    void         (*glDepthFunc)(GLenum func);
    void         (*glDepthMask)(GLboolean flag);
    void         (*glDepthRangef)(GLclampf zNear, GLclampf zFar);
    void         (*glDetachShader)(GLuint program, GLuint shader);
    void         (*glDisable)(GLenum cap);
    void         (*glDisableVertexAttribArray)(GLuint index);
    void         (*glDrawArrays)(GLenum mode, GLint first, GLsizei count);
    void         (*glDrawElements)(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices);
    void         (*glEnable)(GLenum cap);
    void         (*glEnableVertexAttribArray)(GLuint index);
    void         (*glFinish)(void);
    void         (*glFlush)(void);
    void         (*glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
    void         (*glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
    void         (*glFrontFace)(GLenum mode);
    void         (*glGenBuffers)(GLsizei n, GLuint* buffers);
    void         (*glGenerateMipmap)(GLenum target);
    void         (*glGenFramebuffers)(GLsizei n, GLuint* framebuffers);
    void         (*glGenRenderbuffers)(GLsizei n, GLuint* renderbuffers);
    void         (*glGenTextures)(GLsizei n, GLuint* textures);
    void         (*glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
    void         (*glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
    void         (*glGetAttachedShaders)(GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders);
    int          (*glGetAttribLocation)(GLuint program, const GLchar* name);
    void         (*glGetBooleanv)(GLenum pname, GLboolean* params);
    void         (*glGetBufferParameteriv)(GLenum target, GLenum pname, GLint* params);
    GLenum       (*glGetError)(void);
    void         (*glGetFloatv)(GLenum pname, GLfloat* params);
    void         (*glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint* params);
    void         (*glGetIntegerv)(GLenum pname, GLint* params);
    void         (*glGetProgramiv)(GLuint program, GLenum pname, GLint* params);
    void         (*glGetProgramInfoLog)(GLuint program, GLsizei bufsize, GLsizei* length, GLchar* infolog);
    void         (*glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint* params);
    void         (*glGetShaderiv)(GLuint shader, GLenum pname, GLint* params);
    void         (*glGetShaderInfoLog)(GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* infolog);
    void         (*glGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
    void         (*glGetShaderSource)(GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* source);
    const GLubyte* (*glGetString)(GLenum name);
    void         (*glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat* params);
    void         (*glGetTexParameteriv)(GLenum target, GLenum pname, GLint* params);
    void         (*glGetUniformfv)(GLuint program, GLint location, GLfloat* params);
    void         (*glGetUniformiv)(GLuint program, GLint location, GLint* params);
    int          (*glGetUniformLocation)(GLuint program, const GLchar* name);
    void         (*glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat* params);
    void         (*glGetVertexAttribiv)(GLuint index, GLenum pname, GLint* params);
    void         (*glGetVertexAttribPointerv)(GLuint index, GLenum pname, GLvoid** pointer);
    void         (*glHint)(GLenum target, GLenum mode);
    GLboolean    (*glIsBuffer)(GLuint buffer);
    GLboolean    (*glIsEnabled)(GLenum cap);
    GLboolean    (*glIsFramebuffer)(GLuint framebuffer);
    GLboolean    (*glIsProgram)(GLuint program);
    GLboolean    (*glIsRenderbuffer)(GLuint renderbuffer);
    GLboolean    (*glIsShader)(GLuint shader);
    GLboolean    (*glIsTexture)(GLuint texture);
    void         (*glLineWidth)(GLfloat width);
    void         (*glLinkProgram)(GLuint program);
    void         (*glPixelStorei)(GLenum pname, GLint param);
    void         (*glPolygonOffset)(GLfloat factor, GLfloat units);
    void         (*glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid* pixels);
    void         (*glReleaseShaderCompiler)(void);
    void         (*glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
    void         (*glSampleCoverage)(GLclampf value, GLboolean invert);
    void         (*glScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
    void         (*glShaderBinary)(GLsizei n, const GLuint* shaders, GLenum binaryformat, const GLvoid* binary, GLsizei length);
    void         (*glShaderSource)(GLuint shader, GLsizei count, const GLchar** string, const GLint* length);
    void         (*glStencilFunc)(GLenum func, GLint ref, GLuint mask);
    void         (*glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask);
    void         (*glStencilMask)(GLuint mask);
    void         (*glStencilMaskSeparate)(GLenum face, GLuint mask);
    void         (*glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
    void         (*glStencilOpSeparate)(GLenum face, GLenum fail, GLenum zfail, GLenum zpass);
    void         (*glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels);
    void         (*glTexParameterf)(GLenum target, GLenum pname, GLfloat param);
    void         (*glTexParameterfv)(GLenum target, GLenum pname, const GLfloat* params);
    void         (*glTexParameteri)(GLenum target, GLenum pname, GLint param);
    void         (*glTexParameteriv)(GLenum target, GLenum pname, const GLint* params);
    void         (*glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
    void         (*glUniform1f)(GLint location, GLfloat x);
    void         (*glUniform1fv)(GLint location, GLsizei count, const GLfloat* v);
    void         (*glUniform1i)(GLint location, GLint x);
    void         (*glUniform1iv)(GLint location, GLsizei count, const GLint* v);
    void         (*glUniform2f)(GLint location, GLfloat x, GLfloat y);
    void         (*glUniform2fv)(GLint location, GLsizei count, const GLfloat* v);
    void         (*glUniform2i)(GLint location, GLint x, GLint y);
    void         (*glUniform2iv)(GLint location, GLsizei count, const GLint* v);
    void         (*glUniform3f)(GLint location, GLfloat x, GLfloat y, GLfloat z);
    void         (*glUniform3fv)(GLint location, GLsizei count, const GLfloat* v);
    void         (*glUniform3i)(GLint location, GLint x, GLint y, GLint z);
    void         (*glUniform3iv)(GLint location, GLsizei count, const GLint* v);
    void         (*glUniform4f)(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void         (*glUniform4fv)(GLint location, GLsizei count, const GLfloat* v);
    void         (*glUniform4i)(GLint location, GLint x, GLint y, GLint z, GLint w);
    void         (*glUniform4iv)(GLint location, GLsizei count, const GLint* v);
    void         (*glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
    void         (*glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
    void         (*glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
    void         (*glUseProgram)(GLuint program);
    void         (*glValidateProgram)(GLuint program);
    void         (*glVertexAttrib1f)(GLuint indx, GLfloat x);
    void         (*glVertexAttrib1fv)(GLuint indx, const GLfloat* values);
    void         (*glVertexAttrib2f)(GLuint indx, GLfloat x, GLfloat y);
    void         (*glVertexAttrib2fv)(GLuint indx, const GLfloat* values);
    void         (*glVertexAttrib3f)(GLuint indx, GLfloat x, GLfloat y, GLfloat z);
    void         (*glVertexAttrib3fv)(GLuint indx, const GLfloat* values);
    void         (*glVertexAttrib4f)(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    void         (*glVertexAttrib4fv)(GLuint indx, const GLfloat* values);
    void         (*glVertexAttribPointer)(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* ptr);
    void         (*glViewport)(GLint x, GLint y, GLsizei width, GLsizei height);
};

static struct gles2_functions functions;

#define GET_FUNC(name) \
    functions.name = dlsym(h, #name)

void gles2_init(void)
{
    void *h = dlopen("libGLESv2.so", RTLD_LAZY);
    if (h == NULL) {
        h = dlopen("libGLESv2.so.2", RTLD_LAZY);
    }
    if (h == NULL) {
        fprintf(stderr, "libGLESv2.so missing, recompile without APKENV_GLES2\n");
        exit(1);
    }

    GET_FUNC(glActiveTexture);
    GET_FUNC(glAttachShader);
    GET_FUNC(glBindAttribLocation);
    GET_FUNC(glBindBuffer);
    GET_FUNC(glBindFramebuffer);
    GET_FUNC(glBindRenderbuffer);
    GET_FUNC(glBindTexture);
    GET_FUNC(glBlendColor);
    GET_FUNC(glBlendEquation);
    GET_FUNC(glBlendEquationSeparate);
    GET_FUNC(glBlendFunc);
    GET_FUNC(glBlendFuncSeparate);
    GET_FUNC(glBufferData);
    GET_FUNC(glBufferSubData);
    GET_FUNC(glCheckFramebufferStatus);
    GET_FUNC(glClear);
    GET_FUNC(glClearColor);
    GET_FUNC(glClearDepthf);
    GET_FUNC(glClearStencil);
    GET_FUNC(glColorMask);
    GET_FUNC(glCompileShader);
    GET_FUNC(glCompressedTexImage2D);
    GET_FUNC(glCompressedTexSubImage2D);
    GET_FUNC(glCopyTexImage2D);
    GET_FUNC(glCopyTexSubImage2D);
    GET_FUNC(glCreateProgram);
    GET_FUNC(glCreateShader);
    GET_FUNC(glCullFace);
    GET_FUNC(glDeleteBuffers);
    GET_FUNC(glDeleteFramebuffers);
    GET_FUNC(glDeleteProgram);
    GET_FUNC(glDeleteRenderbuffers);
    GET_FUNC(glDeleteShader);
    GET_FUNC(glDeleteTextures);
    GET_FUNC(glDepthFunc);
    GET_FUNC(glDepthMask);
    GET_FUNC(glDepthRangef);
    GET_FUNC(glDetachShader);
    GET_FUNC(glDisable);
    GET_FUNC(glDisableVertexAttribArray);
    GET_FUNC(glDrawArrays);
    GET_FUNC(glDrawElements);
    GET_FUNC(glEnable);
    GET_FUNC(glEnableVertexAttribArray);
    GET_FUNC(glFinish);
    GET_FUNC(glFlush);
    GET_FUNC(glFramebufferRenderbuffer);
    GET_FUNC(glFramebufferTexture2D);
    GET_FUNC(glFrontFace);
    GET_FUNC(glGenBuffers);
    GET_FUNC(glGenerateMipmap);
    GET_FUNC(glGenFramebuffers);
    GET_FUNC(glGenRenderbuffers);
    GET_FUNC(glGenTextures);
    GET_FUNC(glGetActiveAttrib);
    GET_FUNC(glGetActiveUniform);
    GET_FUNC(glGetAttachedShaders);
    GET_FUNC(glGetAttribLocation);
    GET_FUNC(glGetBooleanv);
    GET_FUNC(glGetBufferParameteriv);
    GET_FUNC(glGetError);
    GET_FUNC(glGetFloatv);
    GET_FUNC(glGetFramebufferAttachmentParameteriv);
    GET_FUNC(glGetIntegerv);
    GET_FUNC(glGetProgramiv);
    GET_FUNC(glGetProgramInfoLog);
    GET_FUNC(glGetRenderbufferParameteriv);
    GET_FUNC(glGetShaderiv);
    GET_FUNC(glGetShaderInfoLog);
    GET_FUNC(glGetShaderPrecisionFormat);
    GET_FUNC(glGetShaderSource);
    GET_FUNC(glGetString);
    GET_FUNC(glGetTexParameterfv);
    GET_FUNC(glGetTexParameteriv);
    GET_FUNC(glGetUniformfv);
    GET_FUNC(glGetUniformiv);
    GET_FUNC(glGetUniformLocation);
    GET_FUNC(glGetVertexAttribfv);
    GET_FUNC(glGetVertexAttribiv);
    GET_FUNC(glGetVertexAttribPointerv);
    GET_FUNC(glHint);
    GET_FUNC(glIsBuffer);
    GET_FUNC(glIsEnabled);
    GET_FUNC(glIsFramebuffer);
    GET_FUNC(glIsProgram);
    GET_FUNC(glIsRenderbuffer);
    GET_FUNC(glIsShader);
    GET_FUNC(glIsTexture);
    GET_FUNC(glLineWidth);
    GET_FUNC(glLinkProgram);
    GET_FUNC(glPixelStorei);
    GET_FUNC(glPolygonOffset);
    GET_FUNC(glReadPixels);
    GET_FUNC(glReleaseShaderCompiler);
    GET_FUNC(glRenderbufferStorage);
    GET_FUNC(glSampleCoverage);
    GET_FUNC(glScissor);
    GET_FUNC(glShaderBinary);
    GET_FUNC(glShaderSource);
    GET_FUNC(glStencilFunc);
    GET_FUNC(glStencilFuncSeparate);
    GET_FUNC(glStencilMask);
    GET_FUNC(glStencilMaskSeparate);
    GET_FUNC(glStencilOp);
    GET_FUNC(glStencilOpSeparate);
    GET_FUNC(glTexImage2D);
    GET_FUNC(glTexParameterf);
    GET_FUNC(glTexParameterfv);
    GET_FUNC(glTexParameteri);
    GET_FUNC(glTexParameteriv);
    GET_FUNC(glTexSubImage2D);
    GET_FUNC(glUniform1f);
    GET_FUNC(glUniform1fv);
    GET_FUNC(glUniform1i);
    GET_FUNC(glUniform1iv);
    GET_FUNC(glUniform2f);
    GET_FUNC(glUniform2fv);
    GET_FUNC(glUniform2i);
    GET_FUNC(glUniform2iv);
    GET_FUNC(glUniform3f);
    GET_FUNC(glUniform3fv);
    GET_FUNC(glUniform3i);
    GET_FUNC(glUniform3iv);
    GET_FUNC(glUniform4f);
    GET_FUNC(glUniform4fv);
    GET_FUNC(glUniform4i);
    GET_FUNC(glUniform4iv);
    GET_FUNC(glUniformMatrix2fv);
    GET_FUNC(glUniformMatrix3fv);
    GET_FUNC(glUniformMatrix4fv);
    GET_FUNC(glUseProgram);
    GET_FUNC(glValidateProgram);
    GET_FUNC(glVertexAttrib1f);
    GET_FUNC(glVertexAttrib1fv);
    GET_FUNC(glVertexAttrib2f);
    GET_FUNC(glVertexAttrib2fv);
    GET_FUNC(glVertexAttrib3f);
    GET_FUNC(glVertexAttrib3fv);
    GET_FUNC(glVertexAttrib4f);
    GET_FUNC(glVertexAttrib4fv);
    GET_FUNC(glVertexAttribPointer);
    GET_FUNC(glViewport);
}

void
my_gles2_glActiveTexture(GLenum texture)
{
    WRAPPERS_DEBUG_PRINTF("glActiveTexture()\n", texture);
    functions.glActiveTexture(texture);
}
void
my_gles2_glAttachShader(GLuint program, GLuint shader)
{
    WRAPPERS_DEBUG_PRINTF("glAttachShader()\n", program, shader);
    functions.glAttachShader(program, shader);
}
void
my_gles2_glBindAttribLocation(GLuint program, GLuint index, const char *name)
{
    WRAPPERS_DEBUG_PRINTF("glBindAttribLocation()\n", program, index, name);
    functions.glBindAttribLocation(program, index, name);
}
void
my_gles2_glBindBuffer(GLenum target, GLuint buffer)
{
    WRAPPERS_DEBUG_PRINTF("glBindBuffer()\n", target, buffer);
    functions.glBindBuffer(target, buffer);
}
void
my_gles2_glBindFramebuffer(GLenum target, GLuint framebuffer)
{
    WRAPPERS_DEBUG_PRINTF("glBindFramebuffer()\n", target, framebuffer);
    functions.glBindFramebuffer(target, framebuffer);
}
void
my_gles2_glBindRenderbuffer(GLenum target, GLuint renderbuffer)
{
    WRAPPERS_DEBUG_PRINTF("glBindRenderbuffer()\n", target, renderbuffer);
    functions.glBindRenderbuffer(target, renderbuffer);
}
void
my_gles2_glBindTexture(GLenum target, GLuint texture)
{
    WRAPPERS_DEBUG_PRINTF("glBindTexture()\n", target, texture);
    functions.glBindTexture(target, texture);
}
void
my_gles2_glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    WRAPPERS_DEBUG_PRINTF("glBlendColor()\n", red, green, blue, alpha);
    functions.glBlendColor(red, green, blue, alpha);
}
void
my_gles2_glBlendEquation(GLenum mode)
{
    WRAPPERS_DEBUG_PRINTF("glBlendEquation()\n", mode);
    functions.glBlendEquation(mode);
}
void
my_gles2_glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
    WRAPPERS_DEBUG_PRINTF("glBlendEquationSeparate()\n", modeRGB, modeAlpha);
    functions.glBlendEquationSeparate(modeRGB, modeAlpha);
}
void
my_gles2_glBlendFunc(GLenum sfactor, GLenum dfactor)
{
    WRAPPERS_DEBUG_PRINTF("glBlendFunc()\n", sfactor, dfactor);
    functions.glBlendFunc(sfactor, dfactor);
}
void
my_gles2_glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    WRAPPERS_DEBUG_PRINTF("glBlendFuncSeparate()\n", srcRGB, dstRGB, srcAlpha, dstAlpha);
    functions.glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
}
void
my_gles2_glBufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage)
{
    WRAPPERS_DEBUG_PRINTF("glBufferData()\n", target, size, data, usage);
    functions.glBufferData(target, size, data, usage);
}
void
my_gles2_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data)
{
    WRAPPERS_DEBUG_PRINTF("glBufferSubData()\n", target, offset, size, data);
    functions.glBufferSubData(target, offset, size, data);
}
GLenum
my_gles2_glCheckFramebufferStatus(GLenum target)
{
    WRAPPERS_DEBUG_PRINTF("glCheckFramebufferStatus()\n", target);
    return functions.glCheckFramebufferStatus(target);
}
void
my_gles2_glClear(GLbitfield mask)
{
    WRAPPERS_DEBUG_PRINTF("glClear()\n", mask);
    functions.glClear(mask);
}
void
my_gles2_glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
    WRAPPERS_DEBUG_PRINTF("glClearColor()\n", red, green, blue, alpha);
    functions.glClearColor(red, green, blue, alpha);
}
void
my_gles2_glClearDepthf(GLclampf depth)
{
    WRAPPERS_DEBUG_PRINTF("glClearDepthf()\n", depth);
    functions.glClearDepthf(depth);
}
void
my_gles2_glClearStencil(GLint s)
{
    WRAPPERS_DEBUG_PRINTF("glClearStencil()\n", s);
    functions.glClearStencil(s);
}
void
my_gles2_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
    WRAPPERS_DEBUG_PRINTF("glColorMask()\n", red, green, blue, alpha);
    functions.glColorMask(red, green, blue, alpha);
}
void
my_gles2_glCompileShader(GLuint shader)
{
    WRAPPERS_DEBUG_PRINTF("glCompileShader()\n", shader);
    functions.glCompileShader(shader);
}
void
my_gles2_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data)
{
    WRAPPERS_DEBUG_PRINTF("glCompressedTexImage2D()\n", target, level, internalformat, width, height, border, imageSize, data);
    functions.glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}
void
my_gles2_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data)
{
    WRAPPERS_DEBUG_PRINTF("glCompressedTexSubImage2D()\n", target, level, xoffset, yoffset, width, height, format, imageSize, data);
    functions.glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
void
my_gles2_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
    WRAPPERS_DEBUG_PRINTF("glCopyTexImage2D()\n", target, level, internalformat, x, y, width, height, border);
    functions.glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}
void
my_gles2_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
    WRAPPERS_DEBUG_PRINTF("glCopyTexSubImage2D()\n", target, level, xoffset, yoffset, x, y, width, height);
    functions.glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}
GLuint
my_gles2_glCreateProgram()
{
    WRAPPERS_DEBUG_PRINTF("glCreateProgram()\n");
    return functions.glCreateProgram();
}
GLuint
my_gles2_glCreateShader(GLenum type)
{
    WRAPPERS_DEBUG_PRINTF("glCreateShader()\n", type);
    return functions.glCreateShader(type);
}
void
my_gles2_glCullFace(GLenum mode)
{
    WRAPPERS_DEBUG_PRINTF("glCullFace()\n", mode);
    functions.glCullFace(mode);
}
void
my_gles2_glDeleteBuffers(GLsizei n, const GLuint *buffers)
{
    WRAPPERS_DEBUG_PRINTF("glDeleteBuffers()\n", n, buffers);
    functions.glDeleteBuffers(n, buffers);
}
void
my_gles2_glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers)
{
    WRAPPERS_DEBUG_PRINTF("glDeleteFramebuffers()\n", n, framebuffers);
    functions.glDeleteFramebuffers(n, framebuffers);
}
void
my_gles2_glDeleteProgram(GLuint program)
{
    WRAPPERS_DEBUG_PRINTF("glDeleteProgram()\n", program);
    functions.glDeleteProgram(program);
}
void
my_gles2_glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers)
{
    WRAPPERS_DEBUG_PRINTF("glDeleteRenderbuffers()\n", n, renderbuffers);
    functions.glDeleteRenderbuffers(n, renderbuffers);
}
void
my_gles2_glDeleteShader(GLuint shader)
{
    WRAPPERS_DEBUG_PRINTF("glDeleteShader()\n", shader);
    functions.glDeleteShader(shader);
}
void
my_gles2_glDeleteTextures(GLsizei n, const GLuint *textures)
{
    WRAPPERS_DEBUG_PRINTF("glDeleteTextures()\n", n, textures);
    functions.glDeleteTextures(n, textures);
}
void
my_gles2_glDepthFunc(GLenum func)
{
    WRAPPERS_DEBUG_PRINTF("glDepthFunc()\n", func);
    functions.glDepthFunc(func);
}
void
my_gles2_glDepthMask(GLboolean flag)
{
    WRAPPERS_DEBUG_PRINTF("glDepthMask()\n", flag);
    functions.glDepthMask(flag);
}
void
my_gles2_glDepthRangef(GLclampf zNear, GLclampf zFar)
{
    WRAPPERS_DEBUG_PRINTF("glDepthRangef()\n", zNear, zFar);
    functions.glDepthRangef(zNear, zFar);
}
void
my_gles2_glDetachShader(GLuint program, GLuint shader)
{
    WRAPPERS_DEBUG_PRINTF("glDetachShader()\n", program, shader);
    functions.glDetachShader(program, shader);
}
void
my_gles2_glDisable(GLenum cap)
{
    WRAPPERS_DEBUG_PRINTF("glDisable()\n", cap);
    functions.glDisable(cap);
}
void
my_gles2_glDisableVertexAttribArray(GLuint index)
{
    WRAPPERS_DEBUG_PRINTF("glDisableVertexAttribArray()\n", index);
    functions.glDisableVertexAttribArray(index);
}
void
my_gles2_glDrawArrays(GLenum mode, GLint first, GLsizei count)
{
    WRAPPERS_DEBUG_PRINTF("glDrawArrays()\n", mode, first, count);
    functions.glDrawArrays(mode, first, count);
}
void
my_gles2_glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices)
{
    WRAPPERS_DEBUG_PRINTF("glDrawElements()\n", mode, count, type, indices);
    functions.glDrawElements(mode, count, type, indices);
}
void
my_gles2_glEnable(GLenum cap)
{
    WRAPPERS_DEBUG_PRINTF("glEnable()\n", cap);
    functions.glEnable(cap);
}
void
my_gles2_glEnableVertexAttribArray(GLuint index)
{
    WRAPPERS_DEBUG_PRINTF("glEnableVertexAttribArray()\n", index);
    functions.glEnableVertexAttribArray(index);
}
void
my_gles2_glFinish()
{
    WRAPPERS_DEBUG_PRINTF("glFinish()\n");
    functions.glFinish();
}
void
my_gles2_glFlush()
{
    WRAPPERS_DEBUG_PRINTF("glFlush()\n");
    functions.glFlush();
}
void
my_gles2_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
    WRAPPERS_DEBUG_PRINTF("glFramebufferRenderbuffer()\n", target, attachment, renderbuffertarget, renderbuffer);
    functions.glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}
void
my_gles2_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    WRAPPERS_DEBUG_PRINTF("glFramebufferTexture2D()\n", target, attachment, textarget, texture, level);
    functions.glFramebufferTexture2D(target, attachment, textarget, texture, level);
}
void
my_gles2_glFrontFace(GLenum mode)
{
    WRAPPERS_DEBUG_PRINTF("glFrontFace()\n", mode);
    functions.glFrontFace(mode);
}
void
my_gles2_glGenBuffers(GLsizei n, GLuint *buffers)
{
    WRAPPERS_DEBUG_PRINTF("glGenBuffers()\n", n, buffers);
    functions.glGenBuffers(n, buffers);
}
void
my_gles2_glGenerateMipmap(GLenum target)
{
    WRAPPERS_DEBUG_PRINTF("glGenerateMipmap()\n", target);
    functions.glGenerateMipmap(target);
}
void
my_gles2_glGenFramebuffers(GLsizei n, GLuint *framebuffers)
{
    WRAPPERS_DEBUG_PRINTF("glGenFramebuffers()\n", n, framebuffers);
    functions.glGenFramebuffers(n, framebuffers);
}
void
my_gles2_glGenRenderbuffers(GLsizei n, GLuint *renderbuffers)
{
    WRAPPERS_DEBUG_PRINTF("glGenRenderbuffers()\n", n, renderbuffers);
    functions.glGenRenderbuffers(n, renderbuffers);
}
void
my_gles2_glGenTextures(GLsizei n, GLuint *textures)
{
    WRAPPERS_DEBUG_PRINTF("glGenTextures()\n", n, textures);
    functions.glGenTextures(n, textures);
}
void
my_gles2_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type, char *name)
{
    WRAPPERS_DEBUG_PRINTF("glGetActiveAttrib()\n", program, index, bufsize, length, size, type, name);
    functions.glGetActiveAttrib(program, index, bufsize, length, size, type, name);
}
void
my_gles2_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type, char *name)
{
    WRAPPERS_DEBUG_PRINTF("glGetActiveUniform()\n", program, index, bufsize, length, size, type, name);
    functions.glGetActiveUniform(program, index, bufsize, length, size, type, name);
}
void
my_gles2_glGetAttachedShaders(GLuint program, GLsizei maxcount, GLsizei *count, GLuint *shaders)
{
    WRAPPERS_DEBUG_PRINTF("glGetAttachedShaders()\n", program, maxcount, count, shaders);
    functions.glGetAttachedShaders(program, maxcount, count, shaders);
}
int
my_gles2_glGetAttribLocation(GLuint program, const char *name)
{
    WRAPPERS_DEBUG_PRINTF("glGetAttribLocation()\n", program, name);
    return functions.glGetAttribLocation(program, name);
}
void
my_gles2_glGetBooleanv(GLenum pname, GLboolean *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetBooleanv()\n", pname, params);
    functions.glGetBooleanv(pname, params);
}
void
my_gles2_glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetBufferParameteriv()\n", target, pname, params);
    functions.glGetBufferParameteriv(target, pname, params);
}
GLenum
my_gles2_glGetError()
{
    WRAPPERS_DEBUG_PRINTF("glGetError()\n");
    return functions.glGetError();
}
void
my_gles2_glGetFloatv(GLenum pname, GLfloat *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetFloatv()\n", pname, params);
    functions.glGetFloatv(pname, params);
}
void
my_gles2_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetFramebufferAttachmentParameteriv()\n", target, attachment, pname, params);
    functions.glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}
void
my_gles2_glGetIntegerv(GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetIntegerv()\n", pname, params);
    functions.glGetIntegerv(pname, params);
}
void
my_gles2_glGetProgramiv(GLuint program, GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetProgramiv()\n", program, pname, params);
    functions.glGetProgramiv(program, pname, params);
}
void
my_gles2_glGetProgramInfoLog(GLuint program, GLsizei bufsize, GLsizei *length, char *infolog)
{
    WRAPPERS_DEBUG_PRINTF("glGetProgramInfoLog()\n", program, bufsize, length, infolog);
    functions.glGetProgramInfoLog(program, bufsize, length, infolog);
}
void
my_gles2_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetRenderbufferParameteriv()\n", target, pname, params);
    functions.glGetRenderbufferParameteriv(target, pname, params);
}
void
my_gles2_glGetShaderiv(GLuint shader, GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetShaderiv()\n", shader, pname, params);
    functions.glGetShaderiv(shader, pname, params);
}
void
my_gles2_glGetShaderInfoLog(GLuint shader, GLsizei bufsize, GLsizei *length, char *infolog)
{
    WRAPPERS_DEBUG_PRINTF("glGetShaderInfoLog()\n", shader, bufsize, length, infolog);
    functions.glGetShaderInfoLog(shader, bufsize, length, infolog);
}
void
my_gles2_glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision)
{
    WRAPPERS_DEBUG_PRINTF("glGetShaderPrecisionFormat()\n", shadertype, precisiontype, range, precision);
    functions.glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}
void
my_gles2_glGetShaderSource(GLuint shader, GLsizei bufsize, GLsizei *length, char *source)
{
    WRAPPERS_DEBUG_PRINTF("glGetShaderSource()\n", shader, bufsize, length, source);
    functions.glGetShaderSource(shader, bufsize, length, source);
}
const GLubyte *
my_gles2_glGetString(GLenum name)
{
    WRAPPERS_DEBUG_PRINTF("glGetString()\n", name);
    return functions.glGetString(name);
}
void
my_gles2_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetTexParameterfv()\n", target, pname, params);
    functions.glGetTexParameterfv(target, pname, params);
}
void
my_gles2_glGetTexParameteriv(GLenum target, GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetTexParameteriv()\n", target, pname, params);
    functions.glGetTexParameteriv(target, pname, params);
}
void
my_gles2_glGetUniformfv(GLuint program, GLint location, GLfloat *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetUniformfv()\n", program, location, params);
    functions.glGetUniformfv(program, location, params);
}
void
my_gles2_glGetUniformiv(GLuint program, GLint location, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetUniformiv()\n", program, location, params);
    functions.glGetUniformiv(program, location, params);
}
int
my_gles2_glGetUniformLocation(GLuint program, const char *name)
{
    WRAPPERS_DEBUG_PRINTF("glGetUniformLocation()\n", program, name);
    return functions.glGetUniformLocation(program, name);
}
void
my_gles2_glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetVertexAttribfv()\n", index, pname, params);
    functions.glGetVertexAttribfv(index, pname, params);
}
void
my_gles2_glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetVertexAttribiv()\n", index, pname, params);
    functions.glGetVertexAttribiv(index, pname, params);
}
void
my_gles2_glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer)
{
    WRAPPERS_DEBUG_PRINTF("glGetVertexAttribPointerv()\n", index, pname, pointer);
    functions.glGetVertexAttribPointerv(index, pname, pointer);
}
void
my_gles2_glHint(GLenum target, GLenum mode)
{
    WRAPPERS_DEBUG_PRINTF("glHint()\n", target, mode);
    functions.glHint(target, mode);
}
GLboolean
my_gles2_glIsBuffer(GLuint buffer)
{
    WRAPPERS_DEBUG_PRINTF("glIsBuffer()\n", buffer);
    return functions.glIsBuffer(buffer);
}
GLboolean
my_gles2_glIsEnabled(GLenum cap)
{
    WRAPPERS_DEBUG_PRINTF("glIsEnabled()\n", cap);
    return functions.glIsEnabled(cap);
}
GLboolean
my_gles2_glIsFramebuffer(GLuint framebuffer)
{
    WRAPPERS_DEBUG_PRINTF("glIsFramebuffer()\n", framebuffer);
    return functions.glIsFramebuffer(framebuffer);
}
GLboolean
my_gles2_glIsProgram(GLuint program)
{
    WRAPPERS_DEBUG_PRINTF("glIsProgram()\n", program);
    return functions.glIsProgram(program);
}
GLboolean
my_gles2_glIsRenderbuffer(GLuint renderbuffer)
{
    WRAPPERS_DEBUG_PRINTF("glIsRenderbuffer()\n", renderbuffer);
    return functions.glIsRenderbuffer(renderbuffer);
}
GLboolean
my_gles2_glIsShader(GLuint shader)
{
    WRAPPERS_DEBUG_PRINTF("glIsShader()\n", shader);
    return functions.glIsShader(shader);
}
GLboolean
my_gles2_glIsTexture(GLuint texture)
{
    WRAPPERS_DEBUG_PRINTF("glIsTexture()\n", texture);
    return functions.glIsTexture(texture);
}
void
my_gles2_glLineWidth(GLfloat width)
{
    WRAPPERS_DEBUG_PRINTF("glLineWidth()\n", width);
    functions.glLineWidth(width);
}
void
my_gles2_glLinkProgram(GLuint program)
{
    WRAPPERS_DEBUG_PRINTF("glLinkProgram()\n", program);
    functions.glLinkProgram(program);
}
void
my_gles2_glPixelStorei(GLenum pname, GLint param)
{
    WRAPPERS_DEBUG_PRINTF("glPixelStorei()\n", pname, param);
    functions.glPixelStorei(pname, param);
}
void
my_gles2_glPolygonOffset(GLfloat factor, GLfloat units)
{
    WRAPPERS_DEBUG_PRINTF("glPolygonOffset()\n", factor, units);
    functions.glPolygonOffset(factor, units);
}
void
my_gles2_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels)
{
    WRAPPERS_DEBUG_PRINTF("glReadPixels()\n", x, y, width, height, format, type, pixels);
    functions.glReadPixels(x, y, width, height, format, type, pixels);
}
void
my_gles2_glReleaseShaderCompiler()
{
    WRAPPERS_DEBUG_PRINTF("glReleaseShaderCompiler()\n");
    functions.glReleaseShaderCompiler();
}
void
my_gles2_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
    WRAPPERS_DEBUG_PRINTF("glRenderbufferStorage()\n", target, internalformat, width, height);
    functions.glRenderbufferStorage(target, internalformat, width, height);
}
void
my_gles2_glSampleCoverage(GLclampf value, GLboolean invert)
{
    WRAPPERS_DEBUG_PRINTF("glSampleCoverage()\n", value, invert);
    functions.glSampleCoverage(value, invert);
}
void
my_gles2_glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
    WRAPPERS_DEBUG_PRINTF("glScissor()\n", x, y, width, height);
    functions.glScissor(x, y, width, height);
}
void
my_gles2_glShaderBinary(GLint n, const GLuint *shaders, GLenum binaryformat, const void *binary, GLint length)
{
    WRAPPERS_DEBUG_PRINTF("glShaderBinary()\n", n, shaders, binaryformat, binary, length);
    functions.glShaderBinary(n, shaders, binaryformat, binary, length);
}
void
my_gles2_glShaderSource(GLuint shader, GLsizei count, const char **string, const GLint *length)
{
    WRAPPERS_DEBUG_PRINTF("glShaderSource()\n", shader, count, string, length);
    functions.glShaderSource(shader, count, string, length);
}
void
my_gles2_glStencilFunc(GLenum func, GLint ref, GLuint mask)
{
    WRAPPERS_DEBUG_PRINTF("glStencilFunc()\n", func, ref, mask);
    functions.glStencilFunc(func, ref, mask);
}
void
my_gles2_glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
{
    WRAPPERS_DEBUG_PRINTF("glStencilFuncSeparate()\n", face, func, ref, mask);
    functions.glStencilFuncSeparate(face, func, ref, mask);
}
void
my_gles2_glStencilMask(GLuint mask)
{
    WRAPPERS_DEBUG_PRINTF("glStencilMask()\n", mask);
    functions.glStencilMask(mask);
}
void
my_gles2_glStencilMaskSeparate(GLenum face, GLuint mask)
{
    WRAPPERS_DEBUG_PRINTF("glStencilMaskSeparate()\n", face, mask);
    functions.glStencilMaskSeparate(face, mask);
}
void
my_gles2_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
    WRAPPERS_DEBUG_PRINTF("glStencilOp()\n", fail, zfail, zpass);
    functions.glStencilOp(fail, zfail, zpass);
}
void
my_gles2_glStencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass)
{
    WRAPPERS_DEBUG_PRINTF("glStencilOpSeparate()\n", face, fail, zfail, zpass);
    functions.glStencilOpSeparate(face, fail, zfail, zpass);
}
void
my_gles2_glTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels)
{
    WRAPPERS_DEBUG_PRINTF("glTexImage2D()\n", target, level, internalformat, width, height, border, format, type, pixels);
    functions.glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}
void
my_gles2_glTexParameterf(GLenum target, GLenum pname, GLfloat param)
{
    WRAPPERS_DEBUG_PRINTF("glTexParameterf()\n", target, pname, param);
    functions.glTexParameterf(target, pname, param);
}
void
my_gles2_glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params)
{
    WRAPPERS_DEBUG_PRINTF("glTexParameterfv()\n", target, pname, params);
    functions.glTexParameterfv(target, pname, params);
}
void
my_gles2_glTexParameteri(GLenum target, GLenum pname, GLint param)
{
    WRAPPERS_DEBUG_PRINTF("glTexParameteri()\n", target, pname, param);
    functions.glTexParameteri(target, pname, param);
}
void
my_gles2_glTexParameteriv(GLenum target, GLenum pname, const GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glTexParameteriv()\n", target, pname, params);
    functions.glTexParameteriv(target, pname, params);
}
void
my_gles2_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels)
{
    WRAPPERS_DEBUG_PRINTF("glTexSubImage2D()\n", target, level, xoffset, yoffset, width, height, format, type, pixels);
    functions.glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}
void
my_gles2_glUniform1f(GLint location, GLfloat x)
{
    WRAPPERS_DEBUG_PRINTF("glUniform1f()\n", location, x);
    functions.glUniform1f(location, x);
}
void
my_gles2_glUniform1fv(GLint location, GLsizei count, const GLfloat *v)
{
    WRAPPERS_DEBUG_PRINTF("glUniform1fv()\n", location, count, v);
    functions.glUniform1fv(location, count, v);
}
void
my_gles2_glUniform1i(GLint location, GLint x)
{
    WRAPPERS_DEBUG_PRINTF("glUniform1i()\n", location, x);
    functions.glUniform1i(location, x);
}
void
my_gles2_glUniform1iv(GLint location, GLsizei count, const GLint *v)
{
    WRAPPERS_DEBUG_PRINTF("glUniform1iv()\n", location, count, v);
    functions.glUniform1iv(location, count, v);
}
void
my_gles2_glUniform2f(GLint location, GLfloat x, GLfloat y)
{
    WRAPPERS_DEBUG_PRINTF("glUniform2f()\n", location, x, y);
    functions.glUniform2f(location, x, y);
}
void
my_gles2_glUniform2fv(GLint location, GLsizei count, const GLfloat *v)
{
    WRAPPERS_DEBUG_PRINTF("glUniform2fv()\n", location, count, v);
    functions.glUniform2fv(location, count, v);
}
void
my_gles2_glUniform2i(GLint location, GLint x, GLint y)
{
    WRAPPERS_DEBUG_PRINTF("glUniform2i()\n", location, x, y);
    functions.glUniform2i(location, x, y);
}
void
my_gles2_glUniform2iv(GLint location, GLsizei count, const GLint *v)
{
    WRAPPERS_DEBUG_PRINTF("glUniform2iv()\n", location, count, v);
    functions.glUniform2iv(location, count, v);
}
void
my_gles2_glUniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z)
{
    WRAPPERS_DEBUG_PRINTF("glUniform3f()\n", location, x, y, z);
    functions.glUniform3f(location, x, y, z);
}
void
my_gles2_glUniform3fv(GLint location, GLsizei count, const GLfloat *v)
{
    WRAPPERS_DEBUG_PRINTF("glUniform3fv()\n", location, count, v);
    functions.glUniform3fv(location, count, v);
}
void
my_gles2_glUniform3i(GLint location, GLint x, GLint y, GLint z)
{
    WRAPPERS_DEBUG_PRINTF("glUniform3i()\n", location, x, y, z);
    functions.glUniform3i(location, x, y, z);
}
void
my_gles2_glUniform3iv(GLint location, GLsizei count, const GLint *v)
{
    WRAPPERS_DEBUG_PRINTF("glUniform3iv()\n", location, count, v);
    functions.glUniform3iv(location, count, v);
}
void
my_gles2_glUniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    WRAPPERS_DEBUG_PRINTF("glUniform4f()\n", location, x, y, z, w);
    functions.glUniform4f(location, x, y, z, w);
}
void
my_gles2_glUniform4fv(GLint location, GLsizei count, const GLfloat *v)
{
    WRAPPERS_DEBUG_PRINTF("glUniform4fv()\n", location, count, v);
    functions.glUniform4fv(location, count, v);
}
void
my_gles2_glUniform4i(GLint location, GLint x, GLint y, GLint z, GLint w)
{
    WRAPPERS_DEBUG_PRINTF("glUniform4i()\n", location, x, y, z, w);
    functions.glUniform4i(location, x, y, z, w);
}
void
my_gles2_glUniform4iv(GLint location, GLsizei count, const GLint *v)
{
    WRAPPERS_DEBUG_PRINTF("glUniform4iv()\n", location, count, v);
    functions.glUniform4iv(location, count, v);
}
void
my_gles2_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    WRAPPERS_DEBUG_PRINTF("glUniformMatrix2fv()\n", location, count, transpose, value);
    functions.glUniformMatrix2fv(location, count, transpose, value);
}
void
my_gles2_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    WRAPPERS_DEBUG_PRINTF("glUniformMatrix3fv()\n", location, count, transpose, value);
    functions.glUniformMatrix3fv(location, count, transpose, value);
}
void
my_gles2_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    WRAPPERS_DEBUG_PRINTF("glUniformMatrix4fv()\n", location, count, transpose, value);
    functions.glUniformMatrix4fv(location, count, transpose, value);
}
void
my_gles2_glUseProgram(GLuint program)
{
    WRAPPERS_DEBUG_PRINTF("glUseProgram()\n", program);
    functions.glUseProgram(program);
}
void
my_gles2_glValidateProgram(GLuint program)
{
    WRAPPERS_DEBUG_PRINTF("glValidateProgram()\n", program);
    functions.glValidateProgram(program);
}
void
my_gles2_glVertexAttrib1f(GLuint indx, GLfloat x)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttrib1f()\n", indx, x);
    functions.glVertexAttrib1f(indx, x);
}
void
my_gles2_glVertexAttrib1fv(GLuint indx, const GLfloat *values)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttrib1fv()\n", indx, values);
    functions.glVertexAttrib1fv(indx, values);
}
void
my_gles2_glVertexAttrib2f(GLuint indx, GLfloat x, GLfloat y)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttrib2f()\n", indx, x, y);
    functions.glVertexAttrib2f(indx, x, y);
}
void
my_gles2_glVertexAttrib2fv(GLuint indx, const GLfloat *values)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttrib2fv()\n", indx, values);
    functions.glVertexAttrib2fv(indx, values);
}
void
my_gles2_glVertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttrib3f()\n", indx, x, y, z);
    functions.glVertexAttrib3f(indx, x, y, z);
}
void
my_gles2_glVertexAttrib3fv(GLuint indx, const GLfloat *values)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttrib3fv()\n", indx, values);
    functions.glVertexAttrib3fv(indx, values);
}
void
my_gles2_glVertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttrib4f()\n", indx, x, y, z, w);
    functions.glVertexAttrib4f(indx, x, y, z, w);
}
void
my_gles2_glVertexAttrib4fv(GLuint indx, const GLfloat *values)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttrib4fv()\n", indx, values);
    functions.glVertexAttrib4fv(indx, values);
}
void
my_gles2_glVertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *ptr)
{
    WRAPPERS_DEBUG_PRINTF("glVertexAttribPointer()\n", indx, size, type, normalized, stride, ptr);
    functions.glVertexAttribPointer(indx, size, type, normalized, stride, ptr);
}
void
my_gles2_glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
    WRAPPERS_DEBUG_PRINTF("glViewport()\n", x, y, width, height);
    functions.glViewport(x, y, width, height);
}
void
my_gles2_glEGLImageTargetTexture2DOES(GLenum target, GLeglImageOES image)
{
    WRAPPERS_DEBUG_PRINTF("glEGLImageTargetTexture2DOES()\n", target, image);
    /* No CALL */ printf("UNIMPLEMENTED: glEGLImageTargetTexture2DOES\n");
}
void
my_gles2_glEGLImageTargetRenderbufferStorageOES(GLenum target, GLeglImageOES image)
{
    WRAPPERS_DEBUG_PRINTF("glEGLImageTargetRenderbufferStorageOES()\n", target, image);
    /* No CALL */ printf("UNIMPLEMENTED: glEGLImageTargetRenderbufferStorageOES\n");
}
void *
my_gles2_glMapBufferOES(GLenum target, GLenum access)
{
    WRAPPERS_DEBUG_PRINTF("glMapBufferOES()\n", target, access);
    /* No CALL */ printf("UNIMPLEMENTED: glMapBufferOES\n");
    return NULL;
}
GLboolean
my_gles2_glUnmapBufferOES(GLenum target)
{
    WRAPPERS_DEBUG_PRINTF("glUnmapBufferOES()\n", target);
    /* No CALL */ printf("UNIMPLEMENTED: glUnmapBufferOES\n");
    return GL_FALSE;
}
void
my_gles2_glGetBufferPointervOES(GLenum target, GLenum pname, void **params)
{
    WRAPPERS_DEBUG_PRINTF("glGetBufferPointervOES()\n", target, pname, params);
    /* No CALL */ printf("UNIMPLEMENTED: glGetBufferPointervOES\n");
}
void
my_gles2_glTexImage3DOES(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels)
{
    WRAPPERS_DEBUG_PRINTF("glTexImage3DOES()\n", target, level, internalformat, width, height, depth, border, format, type, pixels);
    /* No CALL */ printf("UNIMPLEMENTED: glTexImage3DOES\n");
}
void
my_gles2_glTexSubImage3DOES(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels)
{
    WRAPPERS_DEBUG_PRINTF("glTexSubImage3DOES()\n", target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
    /* No CALL */ printf("UNIMPLEMENTED: glTexSubImage3DOES\n");
}
void
my_gles2_glCopyTexSubImage3DOES(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
    WRAPPERS_DEBUG_PRINTF("glCopyTexSubImage3DOES()\n", target, level, xoffset, yoffset, zoffset, x, y, width, height);
    /* No CALL */ printf("UNIMPLEMENTED: glCopyTexSubImage3DOES\n");
}
void
my_gles2_glCompressedTexImage3DOES(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data)
{
    WRAPPERS_DEBUG_PRINTF("glCompressedTexImage3DOES()\n", target, level, internalformat, width, height, depth, border, imageSize, data);
    /* No CALL */ printf("UNIMPLEMENTED: glCompressedTexImage3DOES\n");
}
void
my_gles2_glCompressedTexSubImage3DOES(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data)
{
    WRAPPERS_DEBUG_PRINTF("glCompressedTexSubImage3DOES()\n", target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
    /* No CALL */ printf("UNIMPLEMENTED: glCompressedTexSubImage3DOES\n");
}
void
my_gles2_glFramebufferTexture3DOES(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)
{
    WRAPPERS_DEBUG_PRINTF("glFramebufferTexture3DOES()\n", target, attachment, textarget, texture, level, zoffset);
    /* No CALL */ printf("UNIMPLEMENTED: glFramebufferTexture3DOES\n");
}
void
my_gles2_glMultiDrawArraysEXT(GLenum mode, GLint *first, GLsizei *count, GLsizei primcount)
{
    WRAPPERS_DEBUG_PRINTF("glMultiDrawArraysEXT()\n", mode, first, count, primcount);
    /* No CALL */ printf("UNIMPLEMENTED: glMultiDrawArraysEXT\n");
}
void
my_gles2_glMultiDrawElementsEXT(GLenum mode, const GLsizei *count, GLenum type, const GLvoid **indices, GLsizei primcount)
{
    WRAPPERS_DEBUG_PRINTF("glMultiDrawElementsEXT()\n", mode, count, type, indices, primcount);
    /* No CALL */ printf("UNIMPLEMENTED: glMultiDrawElementsEXT\n");
}
void
my_gles2_glTexBindStreamIMG(GLint device, GLint deviceoffset)
{
    WRAPPERS_DEBUG_PRINTF("glTexBindStreamIMG()\n", device, deviceoffset);
    /* No CALL */ printf("UNIMPLEMENTED: glTexBindStreamIMG\n");
}
void
my_gles2_glGetTexStreamDeviceAttributeivIMG(GLint device, GLenum pname, GLint *params)
{
    WRAPPERS_DEBUG_PRINTF("glGetTexStreamDeviceAttributeivIMG()\n", device, pname, params);
    /* No CALL */ printf("UNIMPLEMENTED: glGetTexStreamDeviceAttributeivIMG\n");
}
const GLubyte *
my_gles2_glGetTexStreamDeviceNameIMG(GLint device)
{
    WRAPPERS_DEBUG_PRINTF("glGetTexStreamDeviceNameIMG()\n", device);
    /* No CALL */ printf("UNIMPLEMENTED: glGetTexStreamDeviceNameIMG\n");
    return NULL;
}
void
my_gles2_glGetProgramBinaryOES(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary)
{
    WRAPPERS_DEBUG_PRINTF("glGetProgramBinaryOES()\n", program, bufSize, length, binaryFormat, binary);
    /* No CALL */ printf("UNIMPLEMENTED: glGetProgramBinaryOES\n");
}
void
my_gles2_glProgramBinaryOES(GLuint program, GLenum binaryFormat, const void *binary, GLint length)
{
    WRAPPERS_DEBUG_PRINTF("glProgramBinaryOES()\n", program, binaryFormat, binary, length);
    /* No CALL */ printf("UNIMPLEMENTED: glProgramBinaryOES\n");
}
#endif /* APKENV_GLES2 */
