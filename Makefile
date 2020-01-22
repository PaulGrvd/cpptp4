# makefile du dossier IF-3-POO2-TP3, permet de compiler en exécutable les fichiers de l'application

CFLAGS= -DNDEBUG -Wall -ansi -g -pedantic -std=c++11 #-Werror #-DMAP # variables
COMP = g++
EDL = g++
RMFLAGS = -f
EDLFLAGS = -g
LIBS = -lm # librairies
ECHO = echo
RM = @rm
CLEAN = clean

SRCS = main.cpp Logs.cpp Donnees.cpp  # les fichiers sources .cpp à compiler
OBJS = $(SRCS:.c=.o)
EXE = main # les exécutables
	
main: main.o Logs.o Donnees.o
	$(ECHO) "Edl de $@"
	$(EDL) $(EDLFLAGS) -o $@ $^

%.o: %.cpp %.h
	$(ECHO) "Compil de $<"
	$(COMP) $(CFLAGS) -c $< -o $@

all: $(OBJS)

.PHONY: $(CLEAN) # ne correspond pas à un nom de fichier

cleano:
	$(RM) *.o
clean:
	$(RM) *.o $(EXE)
