#version 340 core

uniform float time;

in vec4 color;

out vec4 FragColor;

void main ()
{
	FragColor = color;
}