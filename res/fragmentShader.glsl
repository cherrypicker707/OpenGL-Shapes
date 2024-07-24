#version 460 core

in vec4 transformedNormal;

out vec4 color;

void main()
{
    color = vec4(0.5 - 0.5 * transformedNormal.z, 0.5 - 0.5 * transformedNormal.z, 0.5 - 0.5 * transformedNormal.z, 1.0f);
}
