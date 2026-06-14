CXX      := g++
CXXFLAGS := -std=c++14 -Wall -Werror -O0 \
            -DTVC_STANDALONE_BUILD \
            -DMIXER_STANDALONE_BUILD \
            -DAVATAR_DEBUG_LOG=0

# Production source files compiled directly — no copies, no drift.
PROD_MOTORS := ../../libraries/AP_Motors
PROD_CONFIG := ../../libraries/AP_CustomConfig

SRCS := test_main.cpp \
        $(PROD_MOTORS)/AP_Motors6DOF_AvatarMixer.cpp \
        $(PROD_MOTORS)/AP_Motors6DOF_BlimpMixer.cpp \
        $(PROD_MOTORS)/TVC_Core.cpp \
        $(PROD_MOTORS)/TVC_PID.cpp \
        $(PROD_MOTORS)/TVC_Filters.cpp \
        $(PROD_CONFIG)/AP_CustomConfig.cpp

# Include paths:
#   -I.                lets "AP_HAL/AP_HAL.h" resolve to our stub
#   -I$(PROD_MOTORS)   lets production files include each other by name
#   -I../../libraries  resolves <AP_CustomConfig/...> bracket includes
INCLUDES := -I. -I$(PROD_MOTORS) -I../../libraries

TARGET := mixer_test

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

run: $(TARGET)
	@./$(TARGET)

clean:
	rm -f $(TARGET)
