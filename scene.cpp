#include <glad/gl.h>
#include "cube.h"

static GLuint vertexBuffer = 0;
static GLuint indexBuffer = 0;
static unsigned int n_indices = 0;

void PrepareScene()
{
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*teapot_n_vertices, &teapot_vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort)*teapot_n_indices, &teapot_indices[0], GL_STATIC_DRAW);

    n_indices = teapot_n_indices;

    // unbind OpenGL objects
    glBindBuffer(0, vertexBuffer);
    glBindBuffer(0, indexBuffer);
}

void RenderScene(bool bWireframe)
{
    glPushMatrix();

    // rotate the geometry
    static float alpha = 0.f;
    glRotatef(alpha, 0, 1, 1);

    if (bWireframe)
    {
        glColor3f(0.f, 0.f, 0.f);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else
    {
        glColor3f(.4f, .4f, .4f);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    glScalef(.2f, .2f, .2f);

    glEnableClientState(GL_VERTEX_ARRAY);

    // draw the geometry
    glBindVertexArray(vertexBuffer);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

    glDrawElements(GL_TRIANGLES, n_indices, GL_UNSIGNED_SHORT, (void *) 0);

    // unbind OpenGL objects
    glBindVertexArray(0);
    glBindBuffer(0, vertexBuffer);
    glBindBuffer(0, indexBuffer);

    glPopMatrix();

    // cleaning
    glDisableClientState(GL_VERTEX_ARRAY);
    alpha += 1;
}
