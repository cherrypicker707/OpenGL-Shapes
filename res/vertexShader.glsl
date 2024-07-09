#version 460 core

layout(location=0) in vec3 position;
layout(location=1) in vec3 normal;

uniform mat4 scaling;
uniform mat4 rotation;
uniform mat4 translation;
uniform mat4 camera;
uniform mat4 projection;

void main()
{
    gl_Position = projection * camera * translation * rotation * scaling * vec4(position, 1.0f);
}
