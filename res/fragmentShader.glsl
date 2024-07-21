#version 460 core

in vec4 transformedNormal;

out vec4 color;

void main()
{
    color = vec4(-transformedNormal.z, -transformedNormal.z, -transformedNormal.z, 1.0f);
}
