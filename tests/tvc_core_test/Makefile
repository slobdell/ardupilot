CXX      := g++
CXXFLAGS := -std=c++14 -Wall -Werror -O0 -DTVC_STANDALONE_BUILD

# Production source files compiled directly — no copies, no drift.
PROD_MOTORS := ../../libraries/AP_Motors
PROD_CONFIG := ../../libraries/AP_CustomConfig

SRCS := test_main.cpp \
        $(PROD_MOTORS)/TVC_Core.cpp \
        $(PROD_MOTORS)/TVC_PID.cpp \
        $(PROD_MOTORS)/TVC_Filters.cpp \
        $(PROD_CONFIG)/AP_CustomConfig.cpp

# Include paths:
#   -I$(PROD_MOTORS)       lets production files include each other by name
#   -I../../libraries      resolves <AP_CustomConfig/...> bracket includes
INCLUDES := -I$(PROD_MOTORS) -I../../libraries

TARGET := tvc_core_test

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

run: $(TARGET)
	@./$(TARGET)

clean:
	rm -f $(TARGET)
