USE_RASPIKE_ART=1

COPTS += 

SRCLANG := c++

mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

#APPL_CXXOBJS += 

APPL_LIBS += -lm -L $(mkfile_path) -lspike

#APPL_DIRS += $(mkfile_path)../spike-api-cpp/src

INCLUDES += -I $(mkfile_path)../spike-api-cpp/include
