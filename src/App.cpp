#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;
int main(void) {
  GLFWwindow *window;
  if (!glfwInit())
    return -1;
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  if (glewInit() != GLEW_OK) {
    std::cout << "Error" << std::endl;
  };
  cout << glGetString(GL_VERSION) << endl;
  // vertex(x,y)-> vertrex can contain all of the things like tangents,alignment many things and that make the vertex generaly the points are called vertex position, vertex attributes -> position(x,y,z),allignment...
  float positions[6] = { -0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f }; //vertex of the postion means the point of the geometry to draw
  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);// data is binded 
  // after the data is binded the we can create `glBufferData` 
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW); //actual buffer that we storing the values and getting the pointers
  glEnableVertexAttribArray(0); // to enable
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0); //(const void*)8
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    // glBegin(GL_TRIANGLES);
    // glVertex2f(-0.5f, -0.5f);
    // glVertex2f(0.0f, 0.5f);
    // glVertex2f(0.5f, -0.5f);
    // glEnd();
    /*
     so basically the data is goint to store in the GPU bufer and
     shader(a program that runs on the GPU) for geometry we use a
     vertex buffer(it is a buffer of memory in the GPU)
    */
    glDrawArrays(GL_TRIANGLES, 0, 3);
    /*
    1. stride->size of each vertex(it going to point it out the buffer range suppose the it is 32 bits so it knows after 32 bits the next the vertex will start)
    2. pointer -> offset of the attributes(means for the position the offdet will be zero[12 bits]-textture co-ordinate[12 bits]-vertex Norn[20 bits])
    */
    /*
    mostly we are going to work with the - 1. vertex shader and 2. fragment shader
    other - 3. geometry shader 4.compute shader
    */
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
