project('marsmap', ['c'])

add_global_arguments('-O', language: ['c'])

glfw = dependency('glfw3')
glew = dependency('glew')

include_src = include_directories('src')
include_extra = include_directories('include')

src = [
  'src/world/world.c',
  'src/world/chunk.c',
  'src/main.c',
  'src/event/input.c',
  'src/math/vector2.c',
  'src/math/matrix4.c',
  'src/math/vector3.c',
  'src/render/buffer.c',
  'src/render/array.c',
  'src/render/shader.c',
  'src/render/window.c',
  'src/entity/camera.c',
  'src/core/mars_map.c'
]

executable('marsmap', src, 
  include_directories: [include_src,include_extra],
  dependencies: [glfw, glew],
  link_args: ['-Wl,-lm']
)
