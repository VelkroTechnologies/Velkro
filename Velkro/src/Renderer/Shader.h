#pragma once

#include <glad/glad.h>

#include <fstream>

#include "../Log.h"

namespace Velkro::Renderer
{
	class Shader
	{
	public:
		Shader()
		{
		}
		Shader(uint32_t ID)
			: m_ID(ID)
		{			
		}

		~Shader()
		{
		}

		static Shader LoadGLSLFile(std::string vertexPath, std::string fragmentPath)
		{
			// Read vertexFile and fragmentFile and store the strings
			std::string vertexCode = ReadFile(vertexPath);
			std::string fragmentCode = ReadFile(fragmentPath);

			// Convert the shader source strings into character arrays
			const char* vertexSource = vertexCode.c_str();
			const char* fragmentSource = fragmentCode.c_str();

			// Create Vertex Shader Object and get its reference
			GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
			// Attach Vertex Shader source to the Vertex Shader Object
			glShaderSource(vertexShader, 1, &vertexSource, NULL);
			// Compile the Vertex Shader into machine code
			glCompileShader(vertexShader);
			// Checks if Shader compiled succesfully
			CompileErrors(vertexShader, GL_VERTEX_SHADER);

			// Create Fragment Shader Object and get its reference
			GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
			// Attach Fragment Shader source to the Fragment Shader Object
			glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
			// Compile the Vertex Shader into machine code
			glCompileShader(fragmentShader);
			// Checks if Shader compiled succesfully
			CompileErrors(fragmentShader, GL_FRAGMENT_SHADER);
			
			// Create Shader Program Object and get its reference
			uint32_t ID = glCreateProgram();
			// Attach the Vertex and Fragment Shaders to the Shader Program
			glAttachShader(ID, vertexShader);
			glAttachShader(ID, fragmentShader);
			// Wrap-up/Link all the shaders together into the Shader Program
			glLinkProgram(ID);
			// Checks if Shaders linked succesfully
			CompileErrors(ID, GL_PROGRAM);

			// Delete the now useless Vertex and Fragment Shader objects
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			return Shader(ID);
		}

		// Activates the Shader Program
		void Bind()
		{
			glUseProgram(m_ID);
		}
		void UnBind()
		{
			glUseProgram(0);
		}

		// Checks if the different Shaders have compiled properly
		static void CompileErrors(uint32_t shader, GLenum type)
		{
			// Stores status of compilation
			GLint hasCompiled;
			// Character array to store error message in
			char infoLog[1024];
			if (type != GL_PROGRAM)
			{
				glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
				if (hasCompiled == GL_FALSE)
				{
					glGetShaderInfoLog(shader, 1024, NULL, infoLog);

					if (type == GL_VERTEX_SHADER)
					{
						VLK_ERROR("Shader: Compilation error for Fragment shader. Info: \"%s\"", infoLog);
					}
					else if (type == GL_FRAGMENT_SHADER)
					{
						VLK_ERROR("Shader: Compilation error for Vertex shader. Info: \"%s\"", infoLog);
					}					
				}
			}
			else
			{
				glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
				if (hasCompiled == GL_FALSE)
				{
					glGetProgramInfoLog(shader, 1024, NULL, infoLog);
					VLK_ERROR("Shader: Compilation error for shader program. Info: \"%s\"", infoLog);
				}
			}
		}

		uint32_t GetID()
		{
			return m_ID;
		}

		void Destroy()
		{
			glDeleteProgram(m_ID);
		}
	
	private:
		uint32_t m_ID;

		static std::string ReadFile(std::string filepath)
		{
			std::ifstream in(filepath, std::ios::binary);
			if (in)
			{
				std::string contents;
				in.seekg(0, std::ios::end);
				contents.resize(in.tellg());
				in.seekg(0, std::ios::beg);
				in.read(&contents[0], contents.size());
				in.close();
				return(contents);
			}
			else
			{
				VLK_FATAL("Shader: Cannot read file! File path: %s", filepath.c_str());
				throw(errno);
			}
		}
	};
}