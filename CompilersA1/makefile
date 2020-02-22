#Makefile for A1 for compilers
#Written by Joshua Bunt
TARGET_EXEC ?= a1.jar
ENTRY_POINT ?= main.class

JAVAC ?= javac
JFLEX ?= jflex
JFLAGS ?= -d $(BUILD_DIR)

MKDIR ?= mkdir -p

BUILD_DIR ?= build
SRC_DIR ?= ./src

SRCS := $(shell find $(SRC_DIR) -name *.java)
CLSS := $(SRCS:%.java=%.class)

default: Lexer.java LexerTag.java
	$(JAVAC) $(JFLAGS) $(SRC_DIR)/*.java

Lexer.java : src/sgml.flex 
	$(MKDIR) $(BUILD_DIR)
	$(JFLEX) $<

LexerTag.java: src/sgml-tag.flex
	$(MKDIR) $(BUILD_DIR)
	$(JFLEX) $<

.PHONY: clean

clean: 
	$(RM) -r $(BUILD_DIR)
	$(RM) $(SRC_DIR)/Lexer*