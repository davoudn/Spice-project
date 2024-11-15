# rm -rf generated
# antlr4 -Dlanguage=Cpp -no-listener -visitor -o generated/ -package antlrcpptest TLexer.g4 TParser.g4
rm a.out
g++ -I /usr/local/include/antlr4-runtime solve.cpp ../Parser/generated/*.cpp -L /usr/local/lib/libantlr4-runtime.* -Wall -Wextra --std=c++17

