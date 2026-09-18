SRCS = task_01.cpp task_02.cpp task_03.cpp task_04.cpp task_05.cpp task_06.cpp
BINS = $(SRCS:%.cpp=%)

.PHONY: all
all: $(BINS)

%: %.cpp
	g++ -o $@ $<

.PHONY: clean
clean:
	rm -rf $(BINS)
