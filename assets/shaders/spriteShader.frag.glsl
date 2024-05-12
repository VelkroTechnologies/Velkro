#version 460 core
out vec4 FragColor;
  
in vec4 Colour;
in vec2 TexCoords;

uniform sampler2D Texture;

void main()
{ 
	FragColor = Colour * texture(Texture, TexCoords);
}