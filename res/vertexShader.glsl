#version 460 core

layout(location=0) in vec3 position;
layout(location=1) in vec3 normal;

out vec4 transformedNormal;

uniform mat4 scaling;
uniform mat4 rotation;
uniform mat4 translation;
uniform mat4 cameraRotation;
uniform mat4 cameraTranslation;
uniform mat4 projection;

void main()
{
    gl_Position = projection * cameraRotation * cameraTranslation * translation * rotation * scaling * vec4(position, 1.0f);
    transformedNormal = cameraRotation * rotation * vec4(normal, 1.0f);
}
