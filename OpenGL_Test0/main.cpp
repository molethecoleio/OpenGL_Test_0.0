//Then I heard the voice of the Lord saying "Whom shall I send? And who shall go for us?" And I said, "Here am I. send me!"
//Lord give me one more chance;
// #include <GL/glew.h> TODO: link this properly
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std; //why do so many people avoid this one line of code and write std 100 times in there project?

void init(GLFWwindow* window){}

void display(GLFWwindow* window, double currentTime)
{
    glClearColor(0, 1, 0, 1);// R,G,B,Alpha
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(void)
{
    if (!glfwInit()) //if the GLFWinit workie it returns true :)
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); //setting GLFW to version 4.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //width,height, title, isFullscreen, isResorceSharring; window is made a pointer because its much more efficent to just pass the address the the entire window object each cycle;
    GLFWwindow* window = glfwCreateWindow(1200, 800, "OpenGl Test0; Init(C01E);", NULL, NULL);
    glfwMakeContextCurrent(window); //linking GLFW to open GL

    //if(glewInit() != GLEW_OK) //if the GLEWinit workie it returns GLEW_OK :)
    //    exit(EXIT_FAILURE);
    
    glfwSwapInterval(1); //this is required for Vsync
    init(window);

    while (!glfwWindowShouldClose(window))
    {
        display(window, glfwGetTime());
        glfwSwapBuffers(window); //this is also required for Vsync
        glfwPollEvents(); // this handles window events like keys being pressed;
    }
    //clear the allocated memory like a good programmer do :)
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}