#pragma once
#include "pch.h"
#include "../ImageImplement.h"

namespace GlassBird
{
	class ImageOpenGL : public ImageImplement
	{
	public:
		ImageOpenGL(const std::string& filePath);
		ImageOpenGL(std::string&& filePath);

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Bind() const override;

		~ImageOpenGL();

	private:
		unsigned int mTexture{ 0 };
		int mWidth{ 0 };
		int mHeight{ 0 };

	};
}
