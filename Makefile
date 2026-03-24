all:
	@clang++ -std=c++17 src/*.cpp -I./SFML/include -L./SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -Wl,-rpath,./SFML/lib -o dist/main
	@clear
	@./dist/main