#version 330 core

uniform float time;
uniform sampler2D texture1;

in vec4 color;
in vec2 texCoord;

out vec4 FragColor;

void main ()
{
	FragColor = texture(texture1, texCoord);
}