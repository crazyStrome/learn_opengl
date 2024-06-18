#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec3 Normal;
out vec3 FragPos;
out vec2 TexCoords;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main()
{
   gl_Position = projection * view * model* vec4(aPos.x, aPos.y, aPos.z, 1.0);
   Normal = aNormal;
   FragPos = vec3(model * vec4(aPos, 1.0));
   TexCoords = aTexCoords;
}

#shader fragment
#version 330 core
struct Material {
    sampler2D ambient;
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};
uniform Material material;

struct Light {
    vec3 position;
    vec3 direction;
    float cutOff;
    float outCutOff;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    
    float constant;
    float linear;
    float quadratic;
};
uniform Light light;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;
uniform vec3 viewPos;

uniform float matrixMove;
out vec4 FragColor;

void main()
{
    float distance = length(light.position - FragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    // 环境光
    vec3 ambient = light.ambient * texture(material.ambient, vec2(TexCoords.x, TexCoords.y+matrixMove)).rgb;
    ambient *= attenuation;
    
    // 漫反射   
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * (diff * texture(material.diffuse, TexCoords).rgb);
    diffuse *= attenuation;

    // 镜面反射
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
    specular *= attenuation;

    float theta = dot(lightDir, normalize(-light.direction));
    float epsilon = light.cutOff - light.outCutOff;
    float intensity = clamp((theta - light.outCutOff) / epsilon, 0.0, 1.0);
    if (theta > light.outCutOff)
    {
        vec3 result = ambient + diffuse + specular;
        result *= intensity;
        FragColor = vec4(result, 1.0);
    } else 
    {
        FragColor = vec4(ambient, 1.0f);
    }
}

