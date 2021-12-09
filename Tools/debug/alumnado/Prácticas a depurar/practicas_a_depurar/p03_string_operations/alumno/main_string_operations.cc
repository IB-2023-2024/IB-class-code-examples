// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 3: Operaciones con cadenas y lenguajes
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.edu.es
// Fecha: 17/10/2021
//
// Archivo main_string_operations.cc: programa cliente.
// Contiene la funcion main del proyecto que usa las clases
// Symbol, Word, Alphabet y Language para poder realizar operaciones con
// lenguajes dados unos archivos de entrada, en estos archivos, se pondran en
// cada linea, primero los simbolos que describen al lenguaje, y luego la
// cadena a evaluar formada por esos simbolos, si quiere saber más detalles 
// sobre como usar el programa, ejecutelo así : 
// ./main_string_operations --help
//
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 17/10/2021 - Creacion (primera version) del codigo

#include "language_class.h"

//Mensaje de error si no se cumple con el numero de argumentos, que es 4
void ErrorMessage(const std::string& function_name) { 
  std::cerr << "\nWarning!, Faltan/Sobran argumentos para este programa";
  std::cerr << "\nPara más información sobre como funciona pruebe:";
  std::cerr << "\n'" << function_name << " --help'\n\n";
}

void ErrorOpcode() { 
  std::cerr << "\nOpCode invalido, intentelo de nuevo\n\n";
}

//Explica al usuario como usar el programa
void InfoMessage(const std::string& function_name) { 
  std::cout << "\nDescripcion:";
  std::cout << "\n" << function_name << " es un programa el cual recibe un";
  std::cout << "\nfichero de texto y devuelve como salida otro. La forma de";
  std::cout << "\nusar el programa es esta:\n\n";
  std::cout << "'" << function_name << " [input_file] [output_file] [opcode]'";
  std::cout << "\n\ninput_file: archivo de texto que le pasamos al programa";
  std::cout << "\noutput_file: nombre del archivo que se creara";
  std::cout << "\nopcode: número que identifica a la operacion a hacer\n";

  std::cout << "\nEspecificaciones del archivo input_file:";
  std::cout << "\nEl archivo input_file puede ser tan extenso como se desee,";
  std::cout << "\nlas lineas pueden ser tan largas como se desee, y cada";
  std::cout << "\nlinea debe contener minimo dos cadenas, la ultima cadena";
  std::cout << "\nde la fila se procesaria como parte de la clase 'aux_word' y";
  std::cout << "\nla primera como parte de la clase 'alphabet', si en una";
  std::cout << "\nlinea hay mas de dos cadenas, la ultima seria parte de";
  std::cout << "\nla clase 'word' y el resto serian simbolos de la clase";
  std::cout << "\n'alphabet'\n";

  std::cout << "\nDetalles de las operaciones:";
  std::cout << "\nOpCode '1' Longitud: Se escribe en output_file la longitud";
  std::cout << "\nde cada cadena de entrada (se cuentan sus simbolos)";
  std::cout << "\nOpCode '2' Inversa: Se escribe en el output_file la inversa";
  std::cout << "\nde cada cadena de entrada (se invierten sus simbolos)";
  std::cout << "\nOpCode '3' Prefijos: Se escribe en output_file el conjunto";
  std::cout << "\nde cadenas que son prefijos de la cadena de entrada";
  std::cout << "\nOpCode '4' Sufijos: Se escribe en output_file el conjunto";
  std::cout << "\nde cadenas que son sufijos de cada cadena de entrada\n";
  std::cout << "OpCode '5' Subcadenas: Se escribe en output_file el conjunto";
  std::cout << "\nde subcadenas para cada cadena de entrada\n\n";
}

int main(int argc, char* argv[]) {

  // Paso los argumenos a tipo string porque es más facil que trabajar con los
  // char* argv[]
  const std::string kNameProgram{argv[0]};

  // Si no se le pasa nada al programa, no hace nada, termina y envia mensaje
  // de error
  if(argc == 1) {
    ErrorMessage(kNameProgram);
    exit(EXIT_FAILURE);
  }

  // Dado que ya sabemos que minimo existe argv[1], no saltará error y podemos
  // inicializar el valor, si lo hacemos antes dara error de ejecucion
  const std::string kNameInput{argv[1]};
  
  //Se solicita conocer el modo de uso del programa
  if(("--help" == kNameInput)) {
    InfoMessage(kNameProgram);
    exit(EXIT_SUCCESS);
  }
  
  //Error al pasar parametros
  if(argc < 4 || argc > 4) { 
    ErrorMessage(kNameProgram);
    exit(EXIT_FAILURE);
  }

  const std::string kNameOutput{argv[2]};
  const std::string kOpCode{argv[3]};

  //OpCode mal puesto
  if(std::stoi(kOpCode) < 1 || std::stoi(kOpCode) > 9) { 
    ErrorOpcode();
    exit(EXIT_FAILURE);
  }

  std::string line = ""; //Variable donde guardamos las lineas del archivo
  std::ifstream input_file;
  std::ofstream output_file;

  input_file.open(kNameInput, std::fstream::in);
  output_file.open(kNameOutput, std::fstream::out);

  // Si hay errores al abrir el archivo de entrada o salida, se termina el 
  // programa con un mensaje de error
  if(input_file.fail()) {
    std::cerr << "\nError al leer el archivo " << kNameInput << ",";
    std::cerr << "\nIntentelo de nuevo\n\n";
    exit(EXIT_FAILURE);
  }

  if(output_file.fail()) {
    std::cerr << "\nError al abrir el archivo " << kNameOutput << ",";
    std::cerr << "\nIntentelo de nuevo\n\n";
    exit(EXIT_FAILURE);
  }

  //Aquí guardamos todo el archivo, dividido en lineas para trabajar mejor
  std::vector<std::string> set_of_lines;

  //Mientras no sea el final del archivo, itera
  while(!input_file.eof()) {
    std::string chain{""};
    
    //Leo toda la linea actual del archico y la guardo 
    getline(input_file, chain);
    set_of_lines.emplace_back(chain);
  }

  input_file.close(); //Cerramos el archivo para liberar memoria

  std::vector<Symbol> temp_user_word; //Variable solo usada en Opcode 6 y 7
  int power{-1}; // Variable solo usada en Opcode 8

  //En este for, por cada linea guardada, se crean un objeto Language, 
  //Se les aplica su opcode, se guarda el resultado en el archivo de salida
  //Y se repite el proceso hasta que no hay mas lineas
  for(size_t i{0}; i < set_of_lines.size(); ++i) {

    //Flujo de entrada de datos que me ayuda a dividirlos para clasificarlos
    std::istringstream actual_line(set_of_lines[i]);

    Language language(actual_line); //Sobre este objeto haremos los opcodes

    if((std::stoi(kOpCode) == 6 || std::stoi(kOpCode) == 7) && i == 0) {

      int number_of_symbols{0};
      std::string temp_chain{""};
        
      while(number_of_symbols < 1 || number_of_symbols > 5) {
        std::cout << "\n¿Cuantos simbolos va a tener la cadena que va a ";
        std::cout << "\nintroducir para su operacion?(min 1, max 5): ";
        std::cin >> number_of_symbols;
      }

      for(int i{0}; i < number_of_symbols; ++i) {
        if(number_of_symbols == 0) {
        std::cout << "\nIntroduzca el primer simbolo: ";
        std::cin >> temp_chain;
        }else {
          std::cout << "\nIntroduzca el siguiente simbolo: ";
          std::cin >> temp_chain;
        }

        Symbol temp_symbol(temp_chain);
        temp_user_word.emplace_back(temp_symbol);

      }
    }

    if((std::stoi(kOpCode) == 8 || std::stoi(kOpCode) == 9) && i == 0) {
      
      while(true) {
        std::cout << "\nIntroduzca la potencia n-ésima a la que quiere ";
        std::cout << "\nelevar su cadena(positivo menor a 21): ";
        std::cin >> power;
    
        if(power >= 0 && power <= 20){
          break;
        }
     
        std::cerr << "\nLo siento, debe ser un numero positivo menor ";
        std::cerr << "\na 21, intentelo de nuevo\n\n";
    
      }
    }

    switch(std::stoi(kOpCode)) {
      case 1:
        output_file << language.Opcode1Size() << '\n';
        break;

      case 2:
        output_file << language.Opcode2Inverse().ShowWord() << '\n';
        break;

      case 3:
        output_file << language.Opcode3Prefix() << '\n';
        break;

      case 4:
        output_file << language.Opcode4Postfix() << '\n';
        break;

      case 5:
        output_file << language.Opcode5Substr() << '\n';
        break;

      case 6:
        output_file << language.Opcode6ChainCmp(temp_user_word) << '\n';
        break;

      case 7:
        output_file << language.Opcode7ChainConcatenation(temp_user_word).ShowWord() << '\n';
        break;
      
      case 8:
        output_file << language.Opcode8Power(power).ShowWord() << '\n';
        break;

      case 9:
        output_file << language.Opcode9NewPower(power) << '\n';
        break;
      
      //Definido un default por si en el futuro se le hiciera un cambio al
      //programa y me despisto haciendo ajustes, estar prevenido
      default: 
        exit(EXIT_FAILURE);
    }
    
  }

  output_file.close(); //Cerramos el archivo que creamos o sobreescribimos, 
  // y así todos los cambios que le aplicamos se ejecutan y guardan
 
  return 0;
}