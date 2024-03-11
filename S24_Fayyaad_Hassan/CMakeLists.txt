add_executable(Game Source.cpp)

include_directories("../GlassBird/include")

target_link_libraries(Game GlassBird)