

# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
#add_executable(vec2
 # vec2.cpp
  #)

add_executable(tests
  glew.c
  tests.cpp
  vec2.cpp
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )



