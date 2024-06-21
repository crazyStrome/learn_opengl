workspace "learn_opengl"
    configurations {
        "Debug",
        "Release",
    }

outputdir = "%{cfg.buildcfg}"

IncludeDirs = {}
IncludeDirs["glfw"] = "%{wks.location}/vendor/glfw/include"
IncludeDirs["glad"] = "%{wks.location}/vendor/glad/include"
IncludeDirs["assimp"] = "%{wks.location}/vendor/assimp/include"
IncludeDirs["glm"] = "%{wks.location}/vendor/glm"
IncludeDirs["shader"] = "%{wks.location}/shader/include"
IncludeDirs["mesh"] = "%{wks.location}/mesh/include"
IncludeDirs["model"] = "%{wks.location}/model/include"
IncludeDirs["camera"] = "%{wks.location}/camera/include"
IncludeDirs["stb_image"] = "%{wks.location}/stb_image/include"

LinkDirs = {}
LinkDirs["assimp"] = "%{wks.location}/vendor/assimp/lib"

include "vendor/glfw"
include "vendor/glad"

include "shader"
include "mesh"
include "model"

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
include "lighting_maps"
include "light_casters"
include "multiple_lights"
include "test_model"
include "depth_testing"

if _ACTION == "clean" then
    os.rmdir("./bin")
    os.rmdir("./bin-int")
end