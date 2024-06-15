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
  hello_window_config = debug
endif
ifeq ($(config),release)
  GLFW_config = release
  glad_config = release
  hello_window_config = release
endif

PROJECTS := GLFW glad hello_window

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

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

hello_window: GLFW glad
ifneq (,$(hello_window_config))
	@echo "==== Building hello_window ($(hello_window_config)) ===="
	@${MAKE} --no-print-directory -C hello_window -f Makefile config=$(hello_window_config)
endif

clean:
	@${MAKE} --no-print-directory -C vendor/glfw -f Makefile clean
	@${MAKE} --no-print-directory -C vendor/glad -f Makefile clean
	@${MAKE} --no-print-directory -C hello_window -f Makefile clean

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
	@echo "   hello_window"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"