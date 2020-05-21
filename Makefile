CXX       := /usr/bin/clang++
CXX_FLAGS := -std=c++14 -g

out_dir     := out
src_dir     := src
test_dir := test
includes := include
test_files := $(wildcard $(test_dir)/*_test.cpp)
test_exes := $(test_files:$(test_dir)/%.cpp=$(out_dir)/%)

executable  := main

gtest_dir := third-parties/gtest
gtest_include := $(gtest_dir)/include
gtest_libraries := $(gtest_dir)/lib

all: $(out_dir)/$(executable) $(test_exes)

$(out_dir)/$(executable): $(src_dir)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(includes) $^ -o $@

$(out_dir)/%_test:  $(test_dir)/%_test.cpp $(src_dir)/%.cpp
	$(CXX) $(CXX_FLAGS) -I$(gtest_include) -I$(includes) -L$(gtest_libraries) -lgtest -lpthread $^ -o $@

clean:
	-rm -rf $(out_dir)/*