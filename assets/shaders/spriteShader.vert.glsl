#version 460 core
layout (location = 0) in vec3 inputPos;
layout (location = 1) in vec4 inputColour;
layout (location = 2) in vec2 inputTexCoords;

out vec4 Colour;
out vec2 TexCoords;

uniform mat4 model;
uniform mat4 projection;

void main()
{
	gl_Position = projection * model * vec4(inputPos, 1.0); 

	Colour = inputColour;
	TexCoords = inputTexCoords;
}