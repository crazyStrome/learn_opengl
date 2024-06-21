#pragma once

#include <glm/glm.hpp>
#include <string>
#include <vector>

#include "shader.h"
#include <assimp/types.h>

struct Vertex
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture
{
    unsigned int id;
    std::string type;
    aiString path;
};

class Mesh {
private:
    unsigned int m_VAO, m_VBO, m_EBO;
    void setupMesh();
    std::vector<Vertex> m_Vertices;
    std::vector<unsigned int> m_Indices;
    std::vector<Texture> m_Textures;
public:

    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, const std::vector<Texture>& textures);
    void Draw(const Shader& shader);
};