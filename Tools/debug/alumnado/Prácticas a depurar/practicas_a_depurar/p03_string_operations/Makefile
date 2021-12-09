# Universidad de La Laguna
# Escuela Superior de Ingenieria y Tecnologia
# Grado en Ingenieria Informatica
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Practica 3: Operaciones con cadenas y lenguajes
# Autor: Cristopher Manuel Afonso Mora
# Correo: alu0101402031@ull.es
# Fecha: 17/10/2021
# Archivo makefile: Programa compilador.
#         Contiene los comandos de la shell BASH necesarios para poder compilar
#         el programa de forma automatica con solo una orden, ayuda a agilizar
#         el desarrollo del código del programa
#
# Referencias:
#         Enlaces de interes

CC = g++
CFLAGS = -I -Weffc++ -Wall -g
DEPS = symbol_class.h word_class.h alphabet_class.h language_class.h 
OBJ = main_string_operations.o symbol_class.o word_class.o alphabet_class.o language_class.o  

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main_string_operations: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


clean:
	rm -rf *.o
