BUILD_DIR = build
APP = V6
EXT = 
SHELL := bash
MKDIR = mkdir -p
RUN = ./$(BUILD_DIR)/$(APP)$(EXT)
FLAGS = 

ifeq ($(OS),Windows_NT)
	EXT = .exe
	SHELL := cmd
	MKDIR = if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	RUN = .\$(BUILD_DIR)\$(APP)$(EXT)
	FLAGS = -G "MinGW Makefiles"
endif

all:
	@echo Compiling...
	@$(MKDIR)
	@cmake -S . -B $(BUILD_DIR) $(FLAGS)
	@cmake --build $(BUILD_DIR)
	@echo Running $(APP)...
	@$(RUN)
