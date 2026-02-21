# rm -rf generated
# antlr4 -Dlanguage=Cpp -no-listener -visitor -o generated/ -package antlrcpptest TLexer.g4 TParser.g4
rm a.out
g++ -I /usr/include/antlr4-runtime/ -I ./generated/ main.cpp generated/*.cpp      -lantlr4-runtime  -Wall -Wextra --std=c++17

