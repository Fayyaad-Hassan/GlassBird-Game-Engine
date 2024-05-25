add_executable(Game Source.cpp MyGame.h MyGame.cpp)

include_directories("../GlassBird/include")

target_link_libraries(Game GlassBird)