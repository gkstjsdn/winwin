#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(500, 500, "GLFW: Circle", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);


        glColor3f(1.0f, 0.0f, 0.0f);      
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1.0f, 0.0f);
        glVertex2f(0.9511f, 0.3090f);

        glColor3f(1.0f, 0.5f, 0.0f);  
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.9511f, 0.3090f);
        glVertex2f(0.8090f, 0.5878f);

         glColor3f(1.0f, 1.0f, 0.0f);  
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.8090f, 0.5878f);
        glVertex2f(0.5878f, 0.8090f);

        glColor3f(0.5f, 1.0f, 0.0f);    
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.5878f, 0.8090f);
        glVertex2f(0.3090f, 0.9511f);

        glColor3f(0.0f, 1.0f, 0.0f);   
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.3090f, 0.9511f);
        glVertex2f(0.0000f, 1.0f);

        glColor3f(0.0f, 1.0f, 0.5f);      
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0000f, 1.0f);
        glVertex2f(-0.3090f, 0.9511f);

        glColor3f(0.0f, 1.0f, 1.0f);      
        glVertex2f(0.0f, 0.0f);
        glVertex2f(-0.3090f, 0.9511f);
        glVertex2f(-0.5878f, 0.8090f);

        glColor3f(0.0f, 0.5f, 1.0f);     
        glVertex2f(0.0f, 0.0f);
        glVertex2f(-0.5878f, 0.8090f);
        glVertex2f(-0.8090f, 0.5878f);

        glColor3f(0.0f, 0.0f, 1.0f);       
        glVertex2f(0.0f, 0.0f);
        glVertex2f(-0.8090f, 0.5878f);
        glVertex2f(-0.9511f, 0.3090f);

        glColor3f(0.5f, 0.0f, 1.0f);     
        glVertex2f(0.0f, 0.0f);
        glVertex2f(-0.9511f, 0.3090f);
        glVertex2f(-1.0f, 0.0f);

        glColor3f(1.0f, 0.0f, 1.0f);    
        glVertex2f(0.0f, 0.0f);
        glVertex2f(-1.0f, 0.0f);
        glVertex2f(-0.9511f, -0.3090f);

 
        glColor3f(1.0f, 0.0f, 0.5f);   
        glVertex2f(0.0f, 0.0f);
        glVertex2f(-0.9511f, -0.3090f);
        glVertex2f(-0.8090f, -0.5878f);

        glColor3f(1.0f, 0.2f, 0.6f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(-0.8090f, -0.5878f);
        glVertex2f(-0.5878f, -0.8090f);

        glColor3f(1.0f, 0.4f, 0.4f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(-0.5878f, -0.8090f);
        glVertex2f(-0.3090f, -0.9511f);

        glColor3f(1.0f, 0.6f, 0.3f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(-0.3090f, -0.9511f);
        glVertex2f(0.0000f, -1.0f);

          glColor3f(1.0f, 0.8f, 0.2f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0000f, -1.0f);
        glVertex2f(0.3090f, -0.9511f);

         glColor3f(0.9f, 1.0f, 0.2f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.3090f, -0.9511f);
        glVertex2f(0.5878f, -0.8090f);

        glColor3f(0.7f, 1.0f, 0.3f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.5878f, -0.8090f);
        glVertex2f(0.8090f, -0.5878f);

        glColor3f(0.6f, 1.0f, 0.4f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.8090f, -0.5878f);
        glVertex2f(0.9511f, -0.3090f);

        glColor3f(0.8f, 0.6f, 1.0f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.9511f, -0.3090f);
        glVertex2f(1.0f, 0.0f);

        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}