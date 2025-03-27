#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 colorIn;
layout (location = 2) in vec2 texIn;

uniform float time;

out vec4 color;
out vec2 texCoord;


void main()
{
	// gl_Position = vec4(aPos.x + sin(time*aPos.x*1.5)/2, aPos.y-sin(time*aPos.y)/2*(aPos.x+.1), aPos.z, 1.0);
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);

	color = vec4(colorIn.x,colorIn.y,colorIn.z,1.0);
	texCoord = texIn;
}