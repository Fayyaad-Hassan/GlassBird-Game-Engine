#include "pch.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "Utility.h"
#include "ImageOpenGL.h"

namespace GlassBird
{
	ImageOpenGL::ImageOpenGL(const std::string& filePath)
	{
		glGenTextures(1, &mTexture);
		glBindTexture(GL_TEXTURE_2D, mTexture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(filePath.c_str(), &mWidth, &mHeight, &nrChannels, 0);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			GLASSBIRD_ERROR("Failed to load texture" << std::endl);
		}
		stbi_image_free(data);
	}

	ImageOpenGL::ImageOpenGL(std::string&& filePath)
	{
		glGenTextures(1, &mTexture);
		glBindTexture(GL_TEXTURE_2D, mTexture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(filePath.c_str(), &mWidth, &mHeight, &nrChannels, 0);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			GLASSBIRD_ERROR("Failed to load texture" << std::endl);
		}
		stbi_image_free(data);
	}

	int ImageOpenGL::GetWidth() const
	{
		return mWidth;
	}

	int ImageOpenGL::GetHeight() const
	{
		return mHeight;
	}

	void ImageOpenGL::Bind() const
	{
		glBindTexture(GL_TEXTURE_2D, mTexture);
	}

	ImageOpenGL::~ImageOpenGL()
	{
		glDeleteTextures(1, &mTexture);
	}
}