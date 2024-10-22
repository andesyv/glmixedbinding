
#pragma once

#include <glmixedbinding/glmixed/types.h>

#include <chrono>

#include "glutils.h"


class CubeScape
{
    using clock = std::chrono::system_clock;

public:
    CubeScape();
    ~CubeScape();

    void resize(int width, int height);
    void draw();

    void setNumCubes(int numCubes);
    int numCubes() const;

protected:
    bool m_initialized;

    glmixed::GLint a_vertex;
    glmixed::GLint u_transform;
    glmixed::GLint u_time;
    glmixed::GLint u_numcubes;
    glmixed::GLint u_terrain;
    glmixed::GLint u_patches;

    glmixed::GLuint m_vao;
    glmixed::GLuint m_indices;
    glmixed::GLuint m_vertices;

    glmixed::GLuint m_program;

    glmixed::GLuint m_textures[2];
    
    float m_a;
    int m_numcubes;

    mat4 m_view;
    mat4 m_projection;

    clock::time_point m_time;
};
