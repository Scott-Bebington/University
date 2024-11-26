# Makefile for running Java commands

# File paths
OBJECTDB_JAR = $(CURDIR)/objectdb.jar
SOURCE_FILES = $(wildcard *.java)
CLASS_FILES = $(patsubst %.java, %.class, $(SOURCE_FILES))

# Targets
all: compile run clean

compile:
	javac -cp objectdb.jar *.java

run:
	java -cp ".:$(OBJECTDB_JAR)" Store

clean:
	rm *.class