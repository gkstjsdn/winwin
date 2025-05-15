#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <math.h>

#define PI 3.1415926535f

typedef struct
{
    float x, y;
} Vec2;

typedef struct
{
    Vec2 position;
    float rotation;   
    Vec2 scale;
} Transform;

typedef struct
{
    Transform transform;
    int segments;
} Circle;

typedef struct
{
    Transform transform;
    int segments;
} Outline;

void draw_circle(Circle* c)
{
    glPushMatrix();

    glTranslatef(c->transform.position.x, c->transform.position.y, 0.0f);
    glRotatef(c->transform.rotation * (180.0f / PI), 0.0f, 0.0f, 1.0f);
    glScalef(c->transform.scale.x, c->transform.scale.y, 1.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);

    for (int i = 0; i <= c->segments; ++i)
    {
        float angle = 2.0f * PI * i / c->segments;
        glVertex2f(cosf(angle) * 0.5f, sinf(angle) * 0.5f);
    }

    glEnd();

    glPopMatrix();
}

void draw_outline(Outline* o)
{
    glPushMatrix();

    glTranslatef(o->transform.position.x, o->transform.position.y, 0.0f);
    glRotatef(o->transform.rotation * (180.0f / PI), 0.0f, 0.0f, 1.0f);
    glScalef(o->transform.scale.x, o->transform.scale.y, 1.0f);

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= o->segments; ++i)
    {
        float angle = 2.0f * PI * i / o->segments;
        glVertex2f(cosf(angle) * 0.5f, sinf(angle) * 0.5f);
    }
    glEnd();

    glPopMatrix();
}

int main() {
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(537, 445, "OpenGL Circle", NULL, NULL);
    if (!window) 
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glOrtho(-1, 1, -1, 1, -1, 1);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    Circle face = { {{0.0f, 0.0f}, 0, {1.6015f, 1.7348f}}, 100 };

    Outline face_outline = { face.transform, 100 };

    Circle Leyes = { {{-0.6687f, 0.2022f}, 0, {0.1154f, 0.1438f}}, 100 };

    Circle Reyes = { {{0.5933f, 0.1730f}, 0, {0.1192f, 0.1348f}}, 100 };

    Circle Lmouth = { {{-0.1361f, -0.2966f}, 0, {0.3314f, 0.3416f}}, 100 };

    Circle Rmouth = { {{0.1691f, -0.2966f}, 0, {0.3314f, 0.3416f}}, 100 };

    Circle nose = { {{0.0239f, -0.1000f}, 0, {0.2459f, 0.2472f}}, 100 };

 

    while (!glfwWindowShouldClose(window)) 
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.0f, 0.4392f, 0.7529f);
        draw_circle(&face);

        draw_outline(&face_outline);

        glColor3f(0.0f, 0.0f, 0.0f);
        draw_circle(&Leyes);

        glColor3f(0.0f, 0.0f, 0.0f);
        draw_circle(&Reyes);

        glColor3f(1.0f, 1.0f, 1.0f);
        draw_circle(&Lmouth);

        glColor3f(1.0f, 1.0f, 1.0f);
        draw_circle(&Rmouth);

        glColor3f(0.0f, 0.0f, 0.0f);
        draw_circle(&nose);



        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(2.0f);

        glBegin(GL_LINES);
        glVertex2f(-0.1920f, -0.1991f);
        glVertex2f(-0.4242f, -0.1236f);

        glVertex2f(-0.1993f, -0.2899f);
        glVertex2f(-0.4242f, -0.3089f);

        glVertex2f(-0.1770f, -0.3539f);
        glVertex2f(-0.4169f, -0.4371f);
       
        glVertex2f(0.2063f, -0.2135f);
        glVertex2f(0.4365f, -0.1236f);

        glVertex2f(0.2069f, -0.2999f);
        glVertex2f(0.4545f, -0.2999f);

        glVertex2f(0.1996f, -0.3742f);
        glVertex2f(0.4471f, -0.4371f);

 
        glEnd();


        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwTerminate();
    return 0;
}