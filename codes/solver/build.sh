# rm -rf generated
# antlr4 -Dlanguage=Cpp -no-listener -visitor -o generated/ -package antlrcpptest TLexer.g4 TParser.g4
rm a.out
g++  *.cpp  ./components/*.cpp ./parser/generated/*.cpp  -I . -I ./components -I /usr/include/antlr4-runtime -larmadillo -llapack -lblas  -lantlr4-runtime  -Wall -Wextra --std=c++20

