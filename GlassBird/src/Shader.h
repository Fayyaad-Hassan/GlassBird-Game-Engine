#pragma once

#include "pch.h"
#include "Utility.h"
#include "ShaderImplement.h"

namespace GlassBird
{
	class GLASSBIRD_API Shader
	{
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentFile);
		Shader(std::string&& vertexFile, std::string&& fragmentFile);

		void Bind();

		void SetUniform2Ints(const std::string& uniformName, int val1, int val2);
		void SetUniform2Ints(std::string&& uniformName, int val1, int val2);

	private:
		std::unique_ptr<ShaderImplement> mImplementation;
	};

}
