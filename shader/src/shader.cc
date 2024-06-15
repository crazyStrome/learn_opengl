#include "shader.h"

#include <fstream>
#include <sstream>
#include <iostream>


SharderSource Shader::ParseShaderSource(const std::string& sourcePath)
{
    std::ifstream stream(sourcePath);
    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };
    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
            {
                type = ShaderType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                type = ShaderType::FRAGMENT;
            }
        }
        else
        {
            ss[int(type)] << line << "\n";
        }
    }

    return SharderSource{ ss[0].str(), ss[1].str() };
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char info[512];
        glGetShaderInfoLog(id, 512, nullptr, info);
        std::cout << "Error: compile " << (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment") << " failed, " << info << std::endl;
    }
    return id;
}

Shader::Shader(const std::string& sourcePath)
{
    ID = glCreateProgram();
    glUseProgram(ID);

    SharderSource source = ParseShaderSource(sourcePath);
    unsigned int vertexShader = CompileShader(GL_VERTEX_SHADER, source.VertexShaderSource);
    unsigned int fragmentShader = CompileShader(GL_FRAGMENT_SHADER, source.FragmentShaderSource);

    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);

    glLinkProgram(ID);
    int success;
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        char info[512];
        glGetProgramInfoLog(ID, 512, nullptr, info);
        std::cout << "Error: link shader program failed, " << info << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
    glDeleteProgram(ID);
}

void Shader::Use()
{
    glUseProgram(ID);
}

void Shader::SetBool(const std::string& name, bool value) const
{
    glUniform1i(GetUniformLocation(name), (int)value);
}

void Shader::SetInt(const std::string& name, int value) const
{
    glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetFloat(const std::string& name, float value) const
{
    glUniform1f(GetUniformLocation(name), value);
}

int Shader::GetUniformLocation(const std::string& name) const
{
    int location = glGetUniformLocation(ID, name.c_str());
    if (location == -1)
    {
        std::cout << "Warn: cannot get uniform location of: " << name << std::endl;
    }
    return location;
}
