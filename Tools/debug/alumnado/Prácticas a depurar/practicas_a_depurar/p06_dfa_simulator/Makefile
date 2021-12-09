# Universidad de La Laguna (ULL)
# Escuela Superior de Ingenieria y Tecnologia (ESIT)
# Grado en Ingeniera Informatica
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Practica 6: Simulacion de DFA's (Autómatas Finitos Deterministas)
# @author Cristopher Manuel Afonso Mora
# Correo: alu0101402031@ull.edu.es
# @date 05/11/21
# 
# @file Makefile
# @brief programa que permite automatizar el proceso de compilación para 
#				 agilizar el desarrollo del código
# 
# @bug No hay bugs conocidos
# 
# Historial de Revisiones 
# 05/11/21 - Creacion (primera version) del codigo:
#            Cree el archivo, y tras crear todos los archivos que mi ejecutable
#            necesitara (vacios, pero creados), terminé este archivo, solo
#            tiene dos ordenes, y son "make main_dfa_simulator" y "make clean"
#            la primera compila el programa, y la segunda limpia de la carpeta
#            actual todos los archivos ".o" que existan
#

CC = g++
CFLAGS = -I -Weffc++ -Wall -g
DEPS = alphabet.h chain.h dfa.h set_status.h symbol.h trans_func.h
OBJ = main_dfa_simulator.o alphabet.o chain.o dfa.o set_status.o symbol.o trans_func.o

%.o: %.cc $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

main_dfa_simulator: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
		rm -rf *.o
