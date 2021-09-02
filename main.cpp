/*
 * Draw triangle using Vulkan APIs
 * Author : Sourabh Goel
 * Date   : 3 September 2021
 */

//GLFW will include its own definitions and automatically load the Vulkan header
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>    // Error-handling library
#include <cstdlib>      // Provides the EXIT_SUCCESS and EXIT_FAILURE macros

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class HelloTriangleApplication {
public:
    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    GLFWwindow* window;

    void initWindow() {
        // Initialize the GLFW library
        glfwInit();

        // Not create an OpenGL context with a subsequent call
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        // Disable resizing of the window
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        // Create an actual window
        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan Window", nullptr, nullptr);

    }

    void initVulkan() {

    }

    void mainLoop() {
        // Checks for events like pressing the X button until the window has been closed by the user
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
        }
    }

    void cleanup() {
        // Destroying and terminating GLFW
        glfwDestroyWindow(window);
        glfwTerminate();
    }
};

int main() {
    HelloTriangleApplication app;

    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}