"""
Based on example on:
http://gpwiki.org/index.php/C:How_to_set_up_your_SDL_Build_Environment#SCons
"""


from glob import glob

# create build environment
env = Environment()

# determine compiler and linker flags for SDL
env.ParseConfig('sdl-config --cflags')
env.ParseConfig('sdl-config --libs')

# add additional compiler flags
env.Append(CCFLAGS = ['-g', '-Wall'])
# add additional libraries to link against
#env.Append(LIBS = ['SDL_mixer', 'SDL_image'])
env.Append(LIBS = ['SDL_image', "SDL_gfx"])

env.Append(CPPPATH = ["."])

SOURCES = ([]
           + glob("sdl/*.cpp")
           + glob("sdl/*/*.cpp")
           + glob("ui/*/*.cpp")
          )

# build target
env.Program(target = 'gator', source = SOURCES)
