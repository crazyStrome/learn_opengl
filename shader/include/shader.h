#pragma once

#include <glad/glad.h>
#include <string>
#include <glm/glm.hpp>

struct SharderSource
{
    std::string VertexShaderSource;
    std::string FragmentShaderSource;
};

class Shader
{
private:
    unsigned int ID;
    SharderSource ParseShaderSource(const std::string& sourcePath);
    unsigned int CompileShader(unsigned int type, const std::string& source);
public:
    Shader(const std::string& sourcePath);
    ~Shader();

    void Use();
    void SetBool(const std::string& name, bool value) const;
    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;
    void SetMat4(const std::string& name, const glm::mat4& trans) const;
    int GetUniformLocation(const std::string& name) const;
};