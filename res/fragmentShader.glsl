#version 460 core

in vec4 transformedNormal;

out vec4 color;

uniform vec3 objectColor;

void main()
{
    color = vec4(0.5 * objectColor.x - 0.5 * objectColor.x * transformedNormal.z, 0.5 * objectColor.y - 0.5 * objectColor.y * transformedNormal.z, 0.5 * objectColor.z - 0.5 * objectColor.z * transformedNormal.z, 1.0f);
}
