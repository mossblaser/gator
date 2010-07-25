"""
Based on example on:
http://gpwiki.org/index.php/C:How_to_set_up_your_SDL_Build_Environment#SCons
"""


import glob

# create build environment
env = Environment()

# determine compiler and linker flags for SDL
env.ParseConfig('sdl-config --cflags')
env.ParseConfig('sdl-config --libs')

# gather a list of source files

# add additional compiler flags
env.Append(CCFLAGS = ['-g', '-Wall'])
# add additional libraries to link against
#env.Append(LIBS = ['SDL_mixer', 'SDL_image'])
env.Append(LIBS = ['SDL_image', "SDL_gfx"])

env.Append(CPPPATH = ["."])

SOURCES = ["GatorUI.cpp",
           "GatorUI_OnInit.cpp",
           "GatorUI_OnEvent.cpp",
           "GatorUI_OnLoop.cpp",
           "GatorUI_OnRender.cpp",
           "GatorUI_OnCleanup.cpp",
           "GatorCanvas.cpp",
           "GatorCanvas_Draw.cpp",
           "GatorCanvas_DrawGrid.cpp",
           "GatorElement.cpp"]

# build target
env.Program(target = 'gator', source = SOURCES)
