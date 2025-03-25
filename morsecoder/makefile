.SILENT:
all:
	# compile the images from mermaid markdown
	# (cd tex && mmdc -i *.md -o o.png -t dark)
	(cd tex && tectonic writeup.tex)
	g++ -Wall ./src/*.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -g -o morsecoder
	./morsecoder
