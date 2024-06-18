#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"

#include <iostream>
#include <math.h>
#include "stb_image_impl.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "camera.h"

static int ScreenWidth = 800;
static int ScreenHeight = 600;

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f),
    glm::vec3(0.0f, 0.0f, -1.0f),
    glm::vec3(0.0f, 1.0f, 0.0f)
);

float deltaTime = 0.0f;
float lastFrame = 0.0f;
unsigned int loadTexture(char const* path);

void GLFWErrorCallback(int error, const char* desc)
{
    std::cout << "GLFW Error" << error << " desc: " << desc << std::endl;
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera.OnKeyMoveEvent(MoveDirection::FORWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        camera.OnKeyMoveEvent(MoveDirection::BACKWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        camera.OnKeyMoveEvent(MoveDirection::LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        camera.OnKeyMoveEvent(MoveDirection::RIGHT, deltaTime);
    }
}

float lastX = (float)ScreenWidth / 2.0;
float lastY = (float)ScreenHeight / 2.0;
bool isFirst = true;

float yaw = -90.0f;
float pitch = 0.0f;
void mouseCallback(GLFWwindow* window, double xpos, double ypos)
{
    if (isFirst)
    {
        lastX = xpos;
        lastY = ypos;
        isFirst = false;
    }
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    camera.OnMouseMoveEvent(xoffset, yoffset);
}

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.OnMouseScrollEvent(yoffset);
}

int main()
{
    glfwSetErrorCallback(GLFWErrorCallback);
    if (!glfwInit())
    {
        std::cout << "GLFW init err\n";
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(ScreenWidth, ScreenHeight, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Max nr of vertex attr: " << nrAttributes << std::endl;

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetCursorPosCallback(window, mouseCallback);
    glfwSetScrollCallback(window, scrollCallback);

    float vertices[] = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
    };

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, 36 * 8 * sizeof(float), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    unsigned int lightVAO;
    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    unsigned int diffuseMap = loadTexture("res/pictures/container2.png");
    unsigned int specularMap = loadTexture("res/pictures/container2_specular.png");
    unsigned int ambientMap = loadTexture("res/pictures/matrix.jpg");

    {
        Shader cubeShader("res/shader_source/multiple_lights/cube.shader");
        Shader lightShader("res/shader_source/multiple_lights/light.shader");

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        glEnable(GL_DEPTH_TEST);

        glm::vec3 cubePositions[] = {
            glm::vec3(0.0f,  0.0f,  0.0f),
            glm::vec3(2.0f,  5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3(2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f,  3.0f, -7.5f),
            glm::vec3(1.3f, -2.0f, -2.5f),
            glm::vec3(1.5f,  2.0f, -2.5f),
            glm::vec3(1.5f,  0.2f, -1.5f),
            glm::vec3(-1.3f,  1.0f, -1.5f)
        };
        glm::vec3 pointLightPositions[] = {
            glm::vec3(0.7f,  0.2f,  2.0f),
            glm::vec3(2.3f, -3.3f, -4.0f),
            glm::vec3(-4.0f,  2.0f, -12.0f),
            glm::vec3(0.0f,  0.0f, -3.0f)
        };
        while (!glfwWindowShouldClose(window))
        {
            processInput(window);

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

            glm::mat4 view = camera.GetView();
            glm::mat4 projection(1.0f);
            projection = glm::perspective(glm::radians(camera.GetFov()), (float)ScreenWidth / ScreenHeight, 0.1f, 100.0f);

            float currentFrame = glfwGetTime();
            if (lastFrame == 0.0f)
                lastFrame = currentFrame;
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;

            //lightColor.x = sin(glfwGetTime() * 2.0f);
            //lightColor.y = sin(glfwGetTime() * 0.7f);
            //lightColor.z = sin(glfwGetTime() * 1.3f);

            cubeShader.Use();
            cubeShader.SetVec3("viewPos", camera.GetPosition());
            cubeShader.SetMat4("view", view);
            cubeShader.SetMat4("projection", projection);

            cubeShader.SetInt("material.diffuse", 0);
            cubeShader.SetInt("material.specular", 1);
            cubeShader.SetInt("material.ambient", 2);
            cubeShader.SetFloat("material.shininess", 32.0f);
            cubeShader.SetVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
            cubeShader.SetVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
            cubeShader.SetVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
            cubeShader.SetVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
            // point light 1
            cubeShader.SetVec3("pointLights[0].position", pointLightPositions[0]);
            cubeShader.SetVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
            cubeShader.SetVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
            cubeShader.SetVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
            cubeShader.SetFloat("pointLights[0].constant", 1.0f);
            cubeShader.SetFloat("pointLights[0].linear", 0.09f);
            cubeShader.SetFloat("pointLights[0].quadratic", 0.032f);
            // point light 2
            cubeShader.SetVec3("pointLights[1].position", pointLightPositions[1]);
            cubeShader.SetVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
            cubeShader.SetVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
            cubeShader.SetVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
            cubeShader.SetFloat("pointLights[1].constant", 1.0f);
            cubeShader.SetFloat("pointLights[1].linear", 0.09f);
            cubeShader.SetFloat("pointLights[1].quadratic", 0.032f);
            // point light 3
            cubeShader.SetVec3("pointLights[2].position", pointLightPositions[2]);
            cubeShader.SetVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
            cubeShader.SetVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
            cubeShader.SetVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
            cubeShader.SetFloat("pointLights[2].constant", 1.0f);
            cubeShader.SetFloat("pointLights[2].linear", 0.09f);
            cubeShader.SetFloat("pointLights[2].quadratic", 0.032f);
            // point light 4
            cubeShader.SetVec3("pointLights[3].position", pointLightPositions[3]);
            cubeShader.SetVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
            cubeShader.SetVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
            cubeShader.SetVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
            cubeShader.SetFloat("pointLights[3].constant", 1.0f);
            cubeShader.SetFloat("pointLights[3].linear", 0.09f);
            cubeShader.SetFloat("pointLights[3].quadratic", 0.032f);
            // spotLight
            cubeShader.SetVec3("spotLight.position", camera.GetPosition());
            cubeShader.SetVec3("spotLight.direction", camera.GetFront());
            cubeShader.SetVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
            cubeShader.SetVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
            cubeShader.SetVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
            cubeShader.SetFloat("spotLight.constant", 1.0f);
            cubeShader.SetFloat("spotLight.linear", 0.09f);
            cubeShader.SetFloat("spotLight.quadratic", 0.032f);
            cubeShader.SetFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
            cubeShader.SetFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, diffuseMap);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, specularMap);
            glActiveTexture(GL_TEXTURE2);
            glBindTexture(GL_TEXTURE_2D, ambientMap);
            glBindVertexArray(VAO);
            for (unsigned int i = 0; i < 10; ++i)
            {
                glm::mat4 model(1.0f);
                model = glm::translate(model, cubePositions[i]);
                float angle = 20.0f * i;
                model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
                cubeShader.SetMat4("model", model);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }

            lightShader.Use();
            lightShader.SetMat4("view", view);
            lightShader.SetMat4("projection", projection);
            glm::vec3 lightColor(1.0f);
            lightShader.SetVec3("lightColor", lightColor);
            glBindVertexArray(lightVAO);
            for (int i = 0; i < 4; i++)
            {
                glm::mat4 lightModel = glm::mat4(1.0f);
                lightModel = glm::translate(lightModel, pointLightPositions[i]);
                lightModel = glm::scale(lightModel, glm::vec3(0.2f));
                lightShader.SetMat4("model", lightModel);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
            glBindVertexArray(0);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
    glfwTerminate();

    return 0;
}

unsigned int loadTexture(char const* path)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}