set(HEADER_FILES
	include/GlassBird.h
	src/GlassBirdApplication.h
	src/Utility.h
	src/GlassBirdWindow.h
	src/WindowImpl.h
	src/codeGLFW/WindowGLFW.h
	src/Renderer.h
	src/RendererImplement.h
	src/codeOpenGL/RendererOpenGL.h
	src/Shader.h
	src/ShaderImplement.h
	src/codeOpenGL/ShaderOpenGL.h
	src/Image.h
	src/ImageImplement.h
	src/codeOpenGL/ImageOpenGL.h
	src/GlassBirdEvents.h
	src/GlassBirdKeys.h
	src/Unit.h
)


set(SOURCE_FILES
	src/GlassBirdApplication.cpp
	src/GlassBirdWindow.cpp
	src/codeGLFW/WindowGLFW.cpp
	src/Renderer.cpp
	src/codeOpenGL/RendererOpenGL.cpp
	src/Shader.cpp
	src/codeOpenGL/ShaderOpenGL.cpp
	src/Image.cpp
	src/codeOpenGL/ImageOpenGL.cpp
	src/GlassBirdEvents.cpp
	src/Unit.cpp
)

add_library(GlassBird SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(GlassBird 
	PUBLIC
		$<$<CONFIG:Debug>:GLASSBIRD_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:GLASSBIRD_DEBUG=1>
	PRIVATE 
		GLASSBIRD_LIB
		GLASSBIRD_GLFW_WINDOW
		GLASSBIRD_OPENGL
)

if(MSVC)
	target_compile_definitions(GlassBird PUBLIC GLASSBIRD_MS_COMPILER)
endif()

target_include_directories(GlassBird PRIVATE ../glfw/include)
target_include_directories(GlassBird PRIVATE ../GlassBird/src)
target_include_directories(GlassBird PRIVATE ../glad/include)
target_include_directories(GlassBird PRIVATE ../stbi)

target_precompile_headers(GlassBird PRIVATE src/pch.h)

target_link_libraries(GlassBird glfw)
target_link_libraries(GlassBird glad)
target_link_libraries(GlassBird stbi)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/GlassBird)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug/GlassBird)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release/GlassBird)