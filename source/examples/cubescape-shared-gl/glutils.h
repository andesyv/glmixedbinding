
#pragma once

#include <glmixedbinding/gl32core/gl.h>

void compile_info(const gl32core::GLuint shader);
void link_info(const gl32core::GLuint program);

struct mat4
{
    mat4();

    inline glmixed::GLfloat & operator[](const int i) { return m[i]; }
    inline const glmixed::GLfloat & operator[](const int i) const { return m[i]; }

    static mat4 lookAt(glmixed::GLfloat eyex, glmixed::GLfloat eyey, glmixed::GLfloat eyez
        , glmixed::GLfloat centerx, glmixed::GLfloat centery, glmixed::GLfloat centerz, glmixed::GLfloat upx, glmixed::GLfloat upy, glmixed::GLfloat upz);

    static mat4 perspective(glmixed::GLfloat fovy, glmixed::GLfloat aspect, glmixed::GLfloat zNear, glmixed::GLfloat zFar);

    static mat4 translate(glmixed::GLfloat x, glmixed::GLfloat y, glmixed::GLfloat z);
    static mat4 scale(glmixed::GLfloat x, glmixed::GLfloat y, glmixed::GLfloat z);
    static mat4 rotate(glmixed::GLfloat angle, glmixed::GLfloat x, glmixed::GLfloat y, glmixed::GLfloat z);

    glmixed::GLfloat m[16];
};

mat4 operator*(const mat4 & a, const mat4 & b);

struct vec3
{
    vec3();
    vec3(glmixed::GLfloat x, glmixed::GLfloat y, glmixed::GLfloat z);

    inline glmixed::GLfloat & operator[](const int i) { return v[i]; }
    inline const glmixed::GLfloat & operator[](const int i) const { return v[i]; }

    vec3 & operator+(const vec3 & rhs);
    vec3 & operator-(const vec3 & rhs);
    vec3 & operator*(const vec3 & rhs);
    vec3 & operator/(const vec3 & rhs);

    glmixed::GLfloat length();
    void normalize();

    glmixed::GLfloat v[3];
};

vec3 crossp(const vec3 & a, const vec3 & b);
glmixed::GLfloat dotp(const vec3 & a, const vec3 & b);
