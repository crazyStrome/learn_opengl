#pragma once

#include <glm/glm.hpp>
#include <string>
#include <vector>

#include "shader.h"
#include "mesh.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Model
{
public:
    Model(const char* path)
    {
        loadModel(path);
    }
    void Draw(const Shader& shader);
private:
    std::vector<Mesh> m_Meshes;
    std::string m_Directory;

    std::vector<Texture> m_TexturesLoaded;

    void loadModel(const std::string& path);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);

    std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
        const std::string& typeName);
};