#version 460 core

layout(location=0) in vec3 position;
layout(location=1) in vec3 normal;

out vec4 transformedNormal;

uniform mat4 scaling;
uniform mat4 rotation;
uniform mat4 translation;
uniform mat4 camera;
uniform mat4 cameraNormal;
uniform mat4 projection;

void main()
{
    mat4 transform = translation * rotation * scaling;
    gl_Position = projection * camera * transform * vec4(position, 1.0f);

    transformedNormal = cameraNormal * rotation * vec4(normal, 1.0f);
}
