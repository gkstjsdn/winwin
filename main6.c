#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <math.h>
#include <time.h>

#define PI 3.1415926535f

typedef struct {
    float x, y;
} Vec2;

typedef struct {
    Vec2 position;
    float rotation;
    Vec2 scale;
} Transform;

typedef struct {
    Transform transform;
    int segments;
} Circle;

typedef struct {
    Transform transform;
    int segments;
} Line;

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void drawDigit(int num, float offsetX) {

    float offsetY = -0.3f;

    float left = offsetX - 0.05f;
    float right = offsetX + 0.05f;
    float top = 0.15f + offsetY;
    float bottom = -0.15f + offsetY;
    float middle = 0.0f + offsetY;

    if (num == 0) {
        drawLine(left, top, right, top);
        drawLine(left, top, left, middle);
        drawLine(right, top, right, middle);
        drawLine(left, bottom, right, bottom);
        drawLine(left, bottom, left, middle);
        drawLine(right, bottom, right, middle);
    }
    else if (num == 1) {
        drawLine(right, top, right, middle);
        drawLine(right, bottom, right, middle);
    }
    else if (num == 2) {
        drawLine(left, top, right, top);
        drawLine(right, top, right, middle);
        drawLine(left, middle, right, middle);
        drawLine(left, middle, left, bottom);
        drawLine(left, bottom, right, bottom);
    }
    else if (num == 3) {
        drawLine(left, top, right, top);
        drawLine(right, top, right, middle);
        drawLine(left, middle, right, middle);
        drawLine(right, bottom, right, middle);
        drawLine(left, bottom, right, bottom);
    }
    else if (num == 4) {
        drawLine(left, top, left, middle);
        drawLine(right, top, right, bottom);
        drawLine(left, middle, right, middle);
    }
    else if (num == 5) {
        drawLine(left, top, right, top);
        drawLine(left, top, left, middle);
        drawLine(left, middle, right, middle);
        drawLine(right, bottom, right, middle);
        drawLine(left, bottom, right, bottom);
    }
    else if (num == 6) {
        drawLine(left, top, right, top);
        drawLine(left, top, left, bottom);
        drawLine(left, middle, right, middle);
        drawLine(right, bottom, right, middle);
        drawLine(left, bottom, right, bottom);
    }
    else if (num == 7) {
        drawLine(left, top, right, top);
        drawLine(right, top, right, middle);
        drawLine(right, middle, right, bottom);
    }
    else if (num == 8) {
        drawLine(left, top, right, top);
        drawLine(left, top, left, bottom);
        drawLine(right, top, right, bottom);
        drawLine(left, middle, right, middle);
        drawLine(left, bottom, right, bottom);
    }
    else if (num == 9) {
        drawLine(left, top, right, top);
        drawLine(left, top, left, middle);
        drawLine(right, top, right, bottom);
        drawLine(left, middle, right, middle);
        drawLine(left, bottom, right, bottom);
    }
}

void draw_circle(Circle* c) {
    glPushMatrix();
    glTranslatef(c->transform.position.x, c->transform.position.y, 0.0f);
    glRotatef(c->transform.rotation * (180.0f / PI), 0.0f, 0.0f, 1.0f);
    glScalef(c->transform.scale.x, c->transform.scale.y, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= c->segments; ++i) {
        float angle = 2.0f * PI * i / c->segments;
        glVertex2f(cosf(angle) * 0.5f, sinf(angle) * 0.5f);
    }
    glEnd();
    glPopMatrix();
}

void draw_line(Line* l) {
    glPushMatrix();
    glTranslatef(l->transform.position.x, l->transform.position.y, 0.0f);
    glRotatef(l->transform.rotation * (180.0f / PI), 0.0f, 0.0f, 1.0f);
    glScalef(l->transform.scale.x, l->transform.scale.y, 1.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
    glPopMatrix();
}

void draw_tick() {
    float base_radius = 0.5f;
    float x_scale = 1.0f;
    float y_scale = 1.3f;
    for (int i = 0; i < 60; ++i) {
        float angle = 2.0f * PI * i / 60.0f;
        float cos_a = cosf(angle);
        float sin_a = sinf(angle);
        float x1 = cos_a * base_radius * x_scale;
        float y1 = sin_a * base_radius * y_scale;
        float length = (i % 5 == 0) ? 0.07f : 0.03f;
        float x2 = cos_a * (base_radius - length) * x_scale;
        float y2 = sin_a * (base_radius - length) * y_scale;
        glLineWidth((i % 5 == 0) ? 2.5f : 1.0f);
        glBegin(GL_LINES);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL C Demo", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glOrtho(-1, 1, -1, 1, -1, 1);

    Circle cir2 = { {{-0.18f, 0.1f}, 0, {0.25f, 0.35f}}, 100 };
    Circle cir = { {{0.0f, 0.0f}, 0, {1.0f, 1.3f}}, 100 };

    Line hour = { {{0.0f, 0.0f}, 0, {0.07f, 0.5f}}, 0 };
    Line minute = { {{0.0f, 0.0f}, 0, {0.06f, 0.8f}}, 0 };
    Line second = { {{-0.18f, 0.1f}, 0, {0.001f, 0.25f}}, 0 };

    int digital_minute = 0;
    clock_t lastTime = clock();

    while (!glfwWindowShouldClose(window)) {
        float time = (float)glfwGetTime();
        float second_angle = -2.0f * PI * fmod(time / 30.0f, 1.0f);
        float minute_angle = -2.0f * PI * fmod(time / 60.0f, 1.0f);
        float hour_angle = -2.0f * PI * fmod(time / (60.0f * 12.0f), 1.0f);

        second.transform.rotation = second_angle;
        minute.transform.rotation = minute_angle;
        hour.transform.rotation = hour_angle;

        clock_t currentTime = clock();
        if ((currentTime - lastTime) >= CLOCKS_PER_SEC) {
            digital_minute++;
            if (digital_minute >= 60) digital_minute = 0;
            lastTime = currentTime;
        }

        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0f, 0.0f, 0.0f);
        draw_circle(&cir);

        glColor3f(.0f, 1.0f, 1.0f);
        draw_circle(&cir2);

        draw_line(&hour);
        draw_line(&minute);
        draw_line(&second);

        draw_tick();

        glColor3f(1.0f, 1.0f, 1.0f);
        drawDigit(digital_minute / 10, -0.08f);
        drawDigit(digital_minute % 10, 0.08f);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}