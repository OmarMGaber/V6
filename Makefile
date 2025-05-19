BUILD_DIR = build
APP = V6
EXT = 
SHELL := bash
MK_BUILD_DIR = mkdir -p $(BUILD_DIR)
RUN = ./$(BUILD_DIR)/$(APP)$(EXT)
FLAGS = 

ifeq ($(OS),Windows_NT)
	EXT = .exe
	SHELL := cmd
	MK_BUILD_DIR = if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	RUN = .\$(BUILD_DIR)\$(APP)$(EXT)
	FLAGS = -G "MinGW Makefiles"
endif

all:
	@echo Compiling...
	@$(MK_BUILD_DIR) 
	@cmake -S . -B $(BUILD_DIR) $(FLAGS)
	@cmake --build $(BUILD_DIR)
	@echo Running $(APP)...
	@$(RUN)
