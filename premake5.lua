workspace "learn_opengl"
    configurations {
        "Debug",
        "Release",
    }

outputdir = "%{cfg.buildcfg}"

IncludeDirs = {}
IncludeDirs["glfw"] = "%{wks.location}/vendor/glfw/include"
IncludeDirs["glad"] = "%{wks.location}/vendor/glad/include"


include "vendor/glfw"
include "vendor/glad"

include "hello_window"
include "hello_triangle"
include "shaders"

if _ACTION == "clean" then
    os.rmdir("./bin")
    os.rmdir("./bin-int")
end