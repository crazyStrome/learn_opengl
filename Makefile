# GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  GLFW_config = debug
  glad_config = debug
  shader_config = debug
  hello_window_config = debug
  hello_triangle_src_config = debug
  hello_triangle_prac1_config = debug
  hello_triangle_prac2_config = debug
  hello_triangle_prac3_config = debug
  shaders_src_config = debug
  shaders_prac1_config = debug
  shaders_prac2_config = debug
  shaders_prac3_config = debug
  textures_src_config = debug
  textures_prac1_config = debug
  textures_prac2_config = debug
  textures_prac3_config = debug
  textures_prac4_config = debug
  transformations_src_config = debug
  transformations_prac1_config = debug
  transformations_prac2_config = debug
endif
ifeq ($(config),release)
  GLFW_config = release
  glad_config = release
  shader_config = release
  hello_window_config = release
  hello_triangle_src_config = release
  hello_triangle_prac1_config = release
  hello_triangle_prac2_config = release
  hello_triangle_prac3_config = release
  shaders_src_config = release
  shaders_prac1_config = release
  shaders_prac2_config = release
  shaders_prac3_config = release
  textures_src_config = release
  textures_prac1_config = release
  textures_prac2_config = release
  textures_prac3_config = release
  textures_prac4_config = release
  transformations_src_config = release
  transformations_prac1_config = release
  transformations_prac2_config = release
endif

PROJECTS := GLFW glad shader hello_window hello_triangle_src hello_triangle_prac1 hello_triangle_prac2 hello_triangle_prac3 shaders_src shaders_prac1 shaders_prac2 shaders_prac3 textures_src textures_prac1 textures_prac2 textures_prac3 textures_prac4 transformations_src transformations_prac1 transformations_prac2

.PHONY: all clean help $(PROJECTS) hello_triangle shaders textures transformations

all: $(PROJECTS)

hello_triangle: hello_triangle_prac1 hello_triangle_prac2 hello_triangle_prac3 hello_triangle_src

shaders: shaders_prac1 shaders_prac2 shaders_prac3 shaders_src

textures: textures_prac1 textures_prac2 textures_prac3 textures_prac4 textures_src

transformations: transformations_prac1 transformations_prac2 transformations_src

GLFW:
ifneq (,$(GLFW_config))
	@echo "==== Building GLFW ($(GLFW_config)) ===="
	@${MAKE} --no-print-directory -C vendor/glfw -f Makefile config=$(GLFW_config)
endif

glad:
ifneq (,$(glad_config))
	@echo "==== Building glad ($(glad_config)) ===="
	@${MAKE} --no-print-directory -C vendor/glad -f Makefile config=$(glad_config)
endif

shader: GLFW glad
ifneq (,$(shader_config))
	@echo "==== Building shader ($(shader_config)) ===="
	@${MAKE} --no-print-directory -C shader -f Makefile config=$(shader_config)
endif

hello_window: GLFW glad
ifneq (,$(hello_window_config))
	@echo "==== Building hello_window ($(hello_window_config)) ===="
	@${MAKE} --no-print-directory -C hello_window -f Makefile config=$(hello_window_config)
endif

hello_triangle_src: GLFW glad
ifneq (,$(hello_triangle_src_config))
	@echo "==== Building hello_triangle_src ($(hello_triangle_src_config)) ===="
	@${MAKE} --no-print-directory -C hello_triangle/src -f Makefile config=$(hello_triangle_src_config)
endif

hello_triangle_prac1: GLFW glad
ifneq (,$(hello_triangle_prac1_config))
	@echo "==== Building hello_triangle_prac1 ($(hello_triangle_prac1_config)) ===="
	@${MAKE} --no-print-directory -C hello_triangle/prac1 -f Makefile config=$(hello_triangle_prac1_config)
endif

hello_triangle_prac2: GLFW glad
ifneq (,$(hello_triangle_prac2_config))
	@echo "==== Building hello_triangle_prac2 ($(hello_triangle_prac2_config)) ===="
	@${MAKE} --no-print-directory -C hello_triangle/prac2 -f Makefile config=$(hello_triangle_prac2_config)
endif

hello_triangle_prac3: GLFW glad
ifneq (,$(hello_triangle_prac3_config))
	@echo "==== Building hello_triangle_prac3 ($(hello_triangle_prac3_config)) ===="
	@${MAKE} --no-print-directory -C hello_triangle/prac3 -f Makefile config=$(hello_triangle_prac3_config)
endif

shaders_src: GLFW glad shader
ifneq (,$(shaders_src_config))
	@echo "==== Building shaders_src ($(shaders_src_config)) ===="
	@${MAKE} --no-print-directory -C shaders/src -f Makefile config=$(shaders_src_config)
endif

shaders_prac1: GLFW glad shader
ifneq (,$(shaders_prac1_config))
	@echo "==== Building shaders_prac1 ($(shaders_prac1_config)) ===="
	@${MAKE} --no-print-directory -C shaders/prac1 -f Makefile config=$(shaders_prac1_config)
endif

shaders_prac2: GLFW glad shader
ifneq (,$(shaders_prac2_config))
	@echo "==== Building shaders_prac2 ($(shaders_prac2_config)) ===="
	@${MAKE} --no-print-directory -C shaders/prac2 -f Makefile config=$(shaders_prac2_config)
endif

shaders_prac3: GLFW glad shader
ifneq (,$(shaders_prac3_config))
	@echo "==== Building shaders_prac3 ($(shaders_prac3_config)) ===="
	@${MAKE} --no-print-directory -C shaders/prac3 -f Makefile config=$(shaders_prac3_config)
endif

textures_src: GLFW glad shader
ifneq (,$(textures_src_config))
	@echo "==== Building textures_src ($(textures_src_config)) ===="
	@${MAKE} --no-print-directory -C textures/src -f Makefile config=$(textures_src_config)
endif

textures_prac1: GLFW glad shader
ifneq (,$(textures_prac1_config))
	@echo "==== Building textures_prac1 ($(textures_prac1_config)) ===="
	@${MAKE} --no-print-directory -C textures/prac1 -f Makefile config=$(textures_prac1_config)
endif

textures_prac2: GLFW glad shader
ifneq (,$(textures_prac2_config))
	@echo "==== Building textures_prac2 ($(textures_prac2_config)) ===="
	@${MAKE} --no-print-directory -C textures/prac2 -f Makefile config=$(textures_prac2_config)
endif

textures_prac3: GLFW glad shader
ifneq (,$(textures_prac3_config))
	@echo "==== Building textures_prac3 ($(textures_prac3_config)) ===="
	@${MAKE} --no-print-directory -C textures/prac3 -f Makefile config=$(textures_prac3_config)
endif

textures_prac4: GLFW glad shader
ifneq (,$(textures_prac4_config))
	@echo "==== Building textures_prac4 ($(textures_prac4_config)) ===="
	@${MAKE} --no-print-directory -C textures/prac4 -f Makefile config=$(textures_prac4_config)
endif

transformations_src: GLFW glad shader
ifneq (,$(transformations_src_config))
	@echo "==== Building transformations_src ($(transformations_src_config)) ===="
	@${MAKE} --no-print-directory -C transformations/src -f Makefile config=$(transformations_src_config)
endif

transformations_prac1: GLFW glad shader
ifneq (,$(transformations_prac1_config))
	@echo "==== Building transformations_prac1 ($(transformations_prac1_config)) ===="
	@${MAKE} --no-print-directory -C transformations/prac1 -f Makefile config=$(transformations_prac1_config)
endif

transformations_prac2: GLFW glad shader
ifneq (,$(transformations_prac2_config))
	@echo "==== Building transformations_prac2 ($(transformations_prac2_config)) ===="
	@${MAKE} --no-print-directory -C transformations/prac2 -f Makefile config=$(transformations_prac2_config)
endif

clean:
	@${MAKE} --no-print-directory -C vendor/glfw -f Makefile clean
	@${MAKE} --no-print-directory -C vendor/glad -f Makefile clean
	@${MAKE} --no-print-directory -C shader -f Makefile clean
	@${MAKE} --no-print-directory -C hello_window -f Makefile clean
	@${MAKE} --no-print-directory -C hello_triangle/src -f Makefile clean
	@${MAKE} --no-print-directory -C hello_triangle/prac1 -f Makefile clean
	@${MAKE} --no-print-directory -C hello_triangle/prac2 -f Makefile clean
	@${MAKE} --no-print-directory -C hello_triangle/prac3 -f Makefile clean
	@${MAKE} --no-print-directory -C shaders/src -f Makefile clean
	@${MAKE} --no-print-directory -C shaders/prac1 -f Makefile clean
	@${MAKE} --no-print-directory -C shaders/prac2 -f Makefile clean
	@${MAKE} --no-print-directory -C shaders/prac3 -f Makefile clean
	@${MAKE} --no-print-directory -C textures/src -f Makefile clean
	@${MAKE} --no-print-directory -C textures/prac1 -f Makefile clean
	@${MAKE} --no-print-directory -C textures/prac2 -f Makefile clean
	@${MAKE} --no-print-directory -C textures/prac3 -f Makefile clean
	@${MAKE} --no-print-directory -C textures/prac4 -f Makefile clean
	@${MAKE} --no-print-directory -C transformations/src -f Makefile clean
	@${MAKE} --no-print-directory -C transformations/prac1 -f Makefile clean
	@${MAKE} --no-print-directory -C transformations/prac2 -f Makefile clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   GLFW"
	@echo "   glad"
	@echo "   shader"
	@echo "   hello_window"
	@echo "   hello_triangle_src"
	@echo "   hello_triangle_prac1"
	@echo "   hello_triangle_prac2"
	@echo "   hello_triangle_prac3"
	@echo "   shaders_src"
	@echo "   shaders_prac1"
	@echo "   shaders_prac2"
	@echo "   shaders_prac3"
	@echo "   textures_src"
	@echo "   textures_prac1"
	@echo "   textures_prac2"
	@echo "   textures_prac3"
	@echo "   textures_prac4"
	@echo "   transformations_src"
	@echo "   transformations_prac1"
	@echo "   transformations_prac2"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"