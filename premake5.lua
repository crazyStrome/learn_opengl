workspace "learn_opengl"
    configurations {
        "Debug",
        "Release",
    }

outputdir = "%{cfg.buildcfg}"

IncludeDirs = {}
IncludeDirs["glfw"] = "%{wks.location}/vendor/glfw/include"
IncludeDirs["glad"] = "%{wks.location}/vendor/glad/include"
IncludeDirs["glm"] = "%{wks.location}/vendor/glm"
IncludeDirs["shader"] = "%{wks.location}/shader/include"
IncludeDirs["camera"] = "%{wks.location}/camera/include"
IncludeDirs["stb_image"] = "%{wks.location}/stb_image/include"

include "vendor/glfw"
include "vendor/glad"

include "shader"

include "hello_window"
include "hello_triangle"
include "shaders"
include "textures"
include "transformations"
include "coordinate_systems"
include "camera_sandbox"
include "colors"
include "basic_lighting"
include "materials"

if _ACTION == "clean" then
    os.rmdir("./bin")
    os.rmdir("./bin-int")
end