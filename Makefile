all: main

CXX = clang++
override CXXFLAGS += -g -Wmost -Werror

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o \( -type f -name '*.cpp' -o -type f -name '*.cxx' \) -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o \( -type f -name '*.h' -o -type f -name '*.hxx' \) -print)

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -U_FORTIFY_SOURCE -O0 $(SRCS) -o "$@"

clean:
	rm -f main main-debug