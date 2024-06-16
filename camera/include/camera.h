#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

enum class MoveDirection
{
    FORWARD, BACKWARD, LEFT, RIGHT,
};

const float DefaultYaw = -90.0f;

const float MaxPith = 89.0f;
const float MinPith = -89.0f;
const float DefaultPitch = 0.0f;

const float MaxFov = 60.0f;
const float Defaultfov = 45.0f;
const float MinFov = 1.0f;

const float DefaultSensitity = 0.1f;

const float DefaultCameraSpeed = 2.5f;

std::ostream& operator<<(std::ostream& out, const glm::mat4& data);

class Camera
{
private:
    glm::vec3 m_CameraPos;
    glm::vec3 m_CameraFront;
    glm::vec3 m_CameraUp;

    float m_Pitch;
    float m_Yaw;
    float m_Fov;

    float m_Sensitity;
    float m_CameraSpeed;
public:
    Camera(const glm::vec3& pos = glm::vec3(0.0f, 0.0f, 0.3f),
        const glm::vec3& front = glm::vec3(0.0f, 0.0f, -1.0f),
        const glm::vec3& up = glm::vec3(1.0f, 0.0f, 0.0f),
        float yaw = DefaultYaw,
        float pitch = DefaultPitch,
        float fov = Defaultfov,
        float sensitity = DefaultSensitity,
        float speed = DefaultCameraSpeed
    )
        : m_CameraPos(pos), m_CameraFront(front), m_CameraUp(up),
        m_Yaw(yaw), m_Pitch(pitch), m_Fov(fov), m_Sensitity(sensitity),
        m_CameraSpeed(speed)
    {
    }
    void OnKeyMoveEvent(MoveDirection direction, float deltaTime)
    {
        float distance = m_CameraSpeed * deltaTime;
        switch (direction)
        {
        case MoveDirection::FORWARD:
        m_CameraPos += distance * m_CameraFront;
        break;
        case MoveDirection::BACKWARD:
        m_CameraPos -= distance * m_CameraFront;
        break;
        case MoveDirection::LEFT:
        m_CameraPos -= glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * distance;
        break;
        case MoveDirection::RIGHT:
        m_CameraPos += glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * distance;
        break;
        }
    }

    void OnMouseMoveEvent(float xoffset, float yoffset)
    {
        xoffset *= m_Sensitity;
        yoffset *= m_Sensitity;

        m_Yaw += xoffset;
        m_Pitch += yoffset;
        if (m_Pitch > MaxPith)
        {
            m_Pitch = MaxPith;
        }
        if (m_Pitch < MinPith)
        {
            m_Pitch = MinPith;
        }

        glm::vec3 front;
        front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
        front.y = sin(glm::radians(m_Pitch));
        front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
        m_CameraFront = glm::normalize(front);
    }

    float GetFov() const { return m_Fov; }

    void OnMouseScrollEvent(float yoffset)
    {
        m_Fov -= yoffset;
        if (m_Fov < MinFov)
        {
            m_Fov = MinFov;
        }
        if (m_Fov > MaxFov)
        {
            m_Fov = MaxFov;
        }
    }

    glm::mat4 GetView() const
    {
        return glm::lookAt(m_CameraPos, m_CameraPos + m_CameraFront, m_CameraUp);
    }
};

std::ostream& operator<<(std::ostream& out, const glm::mat4& data)
{
    out << "[";
    for (int i = 0; i < 4; i++)
    {
        out << "{";
        for (int j = 0; j < 4; j++)
        {
            out << data[i][j] << " ";
        }
        out << "}" << std::endl;
    }
    out << "]";
    return out;
}
