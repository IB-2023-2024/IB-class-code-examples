# Universidad de La Laguna (ULL)
# Escuela Superior de Ingenieria y Tecnología (ESIT)
# Grado de Ingenieria Informatica
# Asignatura: Computabilidad y Algoritmia 
# Curso: 2º
# Practica 5: Aotómatas Finitos y Reconocimiento de Patrones
# Autor: Cristopher Manuel Afonso Mora
# Correo: alu0101402031@ull.edu.es
# Fecha: 27/10/21 
# Archivo Makefile: Programa compilador.
#                   Contiene los comandos de la shell BASH necesarios para
#                   poder compilar el programa de forma automatica con solo
#                   una orden, ayuda a agilizar el desarrollo del codigo
#

CC = g++
CFLAGS = -I -Weffc++ -Wall -g
DEPS = alphabet_class.h dfa_dna_class.h set_status_class.h trans_func_class.h
OBJ = alphabet_class.o dfa_dna_class.o set_status_class.o trans_func_class.o main_dna_sequencer.o

%.o: %.cc $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

main_dna_sequencer: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)

clean: 
		rm -rf *.o
		rm -rf *.txt
