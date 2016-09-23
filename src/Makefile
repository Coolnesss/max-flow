release:
	clang++ -std=c++11 -Ofast main.cpp edmondskarp.cpp
debug:
	clang++ -std=c++11 -g -O0 main.cpp edmondskarp.cpp
test:
	clang++ -std=c++11 -g ford_fulkerson.cpp edmondskarp.cpp ./test/*.cpp && ./a.out
performance:
	clang++ -std=c++11 -Ofast ford_fulkerson.cpp edmondskarp.cpp test/performance/speed.cpp && ./a.out