set(HEADER_FILES
	include/GlassBird.h
	src/GlassBirdApplication.h
	src/Utility.h
	src/GlassBirdWindow.h
	src/WindowImpl.h
	src/codeGLFW/WindowGLFW.h
)


set(SOURCE_FILES
	src/GlassBirdApplication.cpp
	src/GlassBirdWindow.cpp
	src/codeGLFW/WindowGLFW.cpp

)

add_library(GlassBird SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(GlassBird 
	PUBLIC
		$<$<CONFIG:Debug>:GLASSBIRD_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:GLASSBIRD_DEBUG=1>
	PRIVATE 
		GLASSBIRD_LIB
		GLASSBIRD_GLFW_WINDOW
)

if(MSVC)
	target_compile_definitions(GlassBird PUBLIC GLASSBIRD_MS_COMPILER)
endif()

target_include_directories(GlassBird PRIVATE ../glfw/include)
target_include_directories(GlassBird PRIVATE ../GlassBird)

target_precompile_headers(GlassBird PRIVATE src/pch.h)

target_link_libraries(GlassBird glfw)