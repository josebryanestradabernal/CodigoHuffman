run: compile
	./bin/Huffman
compile:
	gcc -c "src/Huffman.c" -o "bin/Huffman.o"
	gcc "src/main.c" "bin/Huffman.o" -o "bin/Huffman"

clean:
	rm -rf bin/*.o
	rm "bin/Huffman"
