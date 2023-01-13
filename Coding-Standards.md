### Universidad de La Laguna
### Escuela Superior de Ingeniería y Tecnología
### Grado en Ingeniería Informática
### Informática Básica

# C++ C++ Coding Standards: Rules, Guidelines, & Best Practices

#### Buenas prácticas de carácter general
* **Cree un nuevo proyecto (y directorio) para cada nuevo programa que escriba.**
* Utilice al compilar la opción -std=c++17 de modo que sus programas (y sus prácticas de codificación) cumplen los estándares de C++ y funcionan en cualquier sistema.
* No deje que se acumulen los *warning*. Resuélvalos a medida que aparezcan (como si fueran errores). De lo contrario, una advertencia sobre un problema grave puede perderse entre advertencias sobre problemas no graves.
* Configure al máximo los niveles de aviso en las opciones del compilador, sobre todo cuando esté aprendiendo. Le ayudará a identificar posibles problemas.
* Active la opción de compilación "Tratar los avisos como errores" (`-Werror`). Esto le obligará a resolver todos los problemas que causen advertencias.
* Cuando trate errores de compilación en sus programas, resuelva siempre primero el primer error producido y luego vuelva a compilar.
* **Escriba sus comentarios como si estuviera hablando con alguien que no tiene ni idea de lo que hace el código. No de por sentado que recordará por qué se tomaron determinadas decisiones.**
* Aunque el lenguaje lo permita, evite definir múltiples variables del mismo tipo en una misma sentencia. En su lugar, defina cada variable en una sentencia separada en su propia línea.
* **Inicialice las variables al crearlas.**
* **Siempre que sea posible, utilice llaves (*brace initialization*) para inicializar las variables.**
* Existe cierto debate sobre si es necesario inicializar una variable inmediatamente antes de darle un valor proporcionado por el usuario a través de otra fuente (por ejemplo, `std::cin`), ya que el valor proporcionado por el usuario simplemente sobrescribirá el valor de inicialización. En línea con la recomendación anterior de que las variables deben ser siempre inicializadas, la mejor práctica es inicializar la variable primero.
* Prefiera `'\n'` a `std::endl` cuando envíe texto a la consola.
* **Los programadores noveles a menudo tratan de escribir un programa entero de una sola vez, y luego se sienten abrumados cuando produce un montón de errores. Una mejor estrategia es añadir una parte cada vez, asegurarse de que compila y probarlo. Entonces, cuando tenga seguridad de que funciona, pase a la siguiente pieza.**
* **Escriba su programa en unidades pequeñas y bien definidas (funciones o clases), compile a menudo y pruebe su código sobre la marcha.**
* Su función `main()`debe devolver el valor 
[`EXIT_SUCCESS`](https://en.cppreference.com/w/cpp/utility/program/EXIT_status)
(`<cstdlib>`) si el programa se ejecuta normalmente
  y `EXIT_FAILURE` en caso contrario.
* Asegúrese de que sus funciones con tipos de retorno no vacíos (no *void*) devuelven un valor en todos los casos.  No devolver un valor de una función de retorno de valor causará un comportamiento indefinido.
* Siga la regla DRY: *Don't Repeat Yourself*. 
Si necesita hacer algo más de una vez, considere cómo modificar su código para eliminar tanta redundancia como sea posible. 
Las variables pueden usarse para almacenar los resultados de cálculos que necesitan usarse más de una vez (para no tener que repetir el cálculo). 
Las funciones pueden usarse para definir una secuencia de sentencias que se necesita ejecutar más de una vez. 
Los bucles pueden usarse para ejecutar una sentencia más de una vez.
* **Defina sus variables locales tan cerca de su primer uso como sea razonable.**
* **Utilice prefijos de espacio de nombres explícitos (*namespace*) para acceder a identificadores definidos en un espacio de nombres.**
* Inicialice sus variables locales estáticas. Las variables locales estáticas sólo se inicializan la primera vez que se ejecuta el código, no en llamadas posteriores.
* Evite las variables locales estáticas a menos que la variable nunca necesite ser reiniciada.
* Prefiera los espacios de nombres explícitos a las sentencias `using`. 
Evite el uso de directivas siempre que sea posible. 
* Pruebe (*testing*) diferentes categorías de valores de entrada para asegurarse de que su unidad los maneja correctamente.
* **Utilice aserciones para documentar casos que deberían ser lógicamente imposibles.**
* Utilice `std::random_device` para sembrar sus PRNGs.
* Siembre un generador de números pseudoaleatorios solo una vez, y no lo vuelva a sembrar.
* Evite las conversiones de estrechamiento siempre que sea posible. Si necesita realizar una, utilice static_cast para que sea una conversión explícita.
* **Utilice `static_cast` cuando necesite convertir un valor de un tipo a otro.**
* Prefiera los alias de tipo a los typedefs.
* Utilice la deducción de tipos para sus variables (`auto`), a menos que necesite comprometerse con un tipo específico.
* Favorezca los tipos de retorno explícitos sobre la deducción de tipo de retorno de función para funciones normales.
* **Cuando defina una referencia, coloque el ampersand junto al tipo (no junto al nombre de la variable de referencia).**
* **Preferir las referencias a los punteros a menos que se necesiten las capacidades adicionales que proporcionan los punteros.**
* Un tipo definido por el usuario y utilizado en un solo fichero de código debe definirse en ese fichero de código lo más cerca posible del primer punto de uso.
* Un tipo definido por el usuario y utilizado en varios ficheros de código debe definirse en un fichero de cabecera con el mismo nombre que el tipo definido por el programa y luego `#incluirse` en cada fichero de código según sea necesario.
* **Favorezca el uso de funciones de la librería estándar de algoritmos en lugar de escribir su propia funcionalidad para hacer lo mismo.**
* Generalmente favorezca la iteración sobre la recursión, excepto cuando la recursión realmente tenga sentido.

#### Reglas de nombrado
* **Nombre sus ficheros de código `algo.cc`, donde `algo` será un nombre significativo de su elección, y .cc es la extensión que indica que el fichero es un archivo fuente C++.**
* **Utilice la extensión `.h` cuando nombre sus ficheros de cabecera.**
* Si un fichero de cabecera está emparejado con un fichero de código (por ejemplo, `add.h` con `add.cc`), ambos deben tener el mismo nombre base (`add`).
* Los ficheros fuente deben #incluir el fichero de cabecera emparejado (si existe).
* Nombre los tipos definidos por el usuario empezando con mayúscula y sin sufijo.
* **Nombre sus clases empezando con mayúscula.**

#### Ficheros de cabecera (`*.h`)
* **Por lo general, los ficheros de cabecera no deben contener definiciones de funciones y variables, sino solo declaraciones.**
* Cada fichero debe `#incluir` explícitamente todos los ficheros de cabecera que necesite para compilar. 
* **Cuando incluya un fichero de cabecera de la biblioteca estándar, utilice la versión sin la extensión `.h` si existe. 
Las cabeceras definidas por el usuario deben seguir utilizando la extensión `.h`.**
* Para maximizar la posibilidad de que los includes que falten sean marcados por el compilador, ordene sus #includes como sigue:
1. El fichero de cabecera emparejado
2. Otras cabeceras de su proyecto
3. Cabeceras de librerías de terceros
4. Cabeceras de librerías estándar

Las cabeceras de cada grupo deben ordenarse alfabéticamente.
* Prefiera los guardianes de cabecera (*header guards*) a `#pragma once` para maximizar la portabilidad de su código.

#### Tipos de Datos
* **Prefiera `double` a `float`, ya que la falta de precisión en un `float` a menudo conducirá a
imprecisiones.**
* Prefiera los números con signo a los números sin signo para almacenar cantidades (incluso cantidades que no deben ser negativas) y operaciones matemáticas. 
Evite mezclar números con y sin signo.
* Prefiera `int` cuando el tamaño del entero no importe (por ejemplo, el número siempre cabrá dentro del rango de un entero con signo de 2 bytes). 
Por ejemplo, si está pidiendo al usuario que introduzca su edad, o que cuente del 1 al 10, no importa si `int` tiene 16 o 32 bits (los números cabrán de cualquier forma). 
Esto cubrirá la gran mayoría de los casos con los que probablemente se encuentre.
* Asegúrese siempre de que el tipo de sus literales coincide con el tipo de las variables a las que se asignan o que se utilizan para inicializar. 
De lo contrario, se producirá una conversión innecesaria, posiblemente con pérdida de precisión.

#### Constantes
* Cualquier variable que no deba modificarse después de la inicialización y cuyo inicializador se conozca en tiempo de compilación debe declararse como `constexpr`.
* Cualquier variable que no deba modificarse tras la inicialización y cuyo inicializador no se conozca en tiempo de compilación debe declararse como const.
* **Evite los números mágicos en su código (utilice variables `constexpr` en su lugar).**

#### Expresiones
* **Utilice paréntesis para dejar claro cómo debe evaluarse una expresión no trivial (aunque sean técnicamente innecesarios).**
* Aparte de las reglas de precedencia y asociatividad de operadores, asuma que las partes de una expresión pueden evaluarse en cualquier orden. 
Asegúrese de que las expresiones que escribe no dependen del orden de evaluación de esas partes.
* **Prefiera la versión prefijada de los operadores de incremento y decremento, ya que generalmente son más eficaces y es menos probable que se encuentre con problemas extraños con ellos.**
* Ponga siempre entre paréntesis la parte condicional del operador condicional, y considere también la posibilidad de poner entre paréntesis el operador completo. `? :`
* Utilice el operador condicional sólo para condicionales sencillas en las que utilice el resultado y mejoren la legibilidad.
* No añada `==` o `!=` innecesarios a las condiciones. Dificultan la lectura sin aportar ningún valor adicional.
* Cuando se mezclan los operadores lógicos AND y OR en una misma expresión, hay que poner explícitamente entre paréntesis cada operación para asegurarse de que se evalúan como se pretende.

#### Sentencias
* **Considere la posibilidad de poner las sentencias individuales asociadas a un if o else en bloques (sobre todo mientras está aprendiendo).
Los desarrolladores de C++ más experimentados a veces ignoran esta práctica en favor de un espaciado vertical más ajustado.**
* **Prefiera las sentencias `switch` a las cadenas `if-else` cuando pueda elegir.**
* **Coloque siempre el caso por defecto (`default`) en último lugar en el bloque `switch`**.
* Cada conjunto de sentencias bajo una etiqueta debe terminar en una sentencia `break` o `return`. 
Esto incluye las sentencias bajo la última etiqueta en el switch.
* Si define variables utilizadas en una sentencia `case`, hágalo en un bloque dentro del `case`.
* Evite las sentencias `goto`.
* Prefiera while(true) para bucles infinitos intencionados.
* Las variables de bucle deben ser de tipo `int` (con signo).
* Prefiera los bucles `while` a los `do-while` en igualdad de condiciones.
* Evite el operador `!= ` cuando realice comparaciones numéricas en la condición de un bucle  `for `.
* Definir múltiples variables (en la sentencia init) y utilizar el operador coma (en la expresión final) es aceptable dentro de una sentencia for.
* **Prefiera los bucles `for` a los bucles `while` cuando exista una variable de bucle obvia.**
* Utilice break y continue cuando simplifiquen la lógica del bucle.
* Utilice retornos anticipados cuando simplifiquen la lógica de su función.
* En las declaraciones de elementos de bucles `for-each`, si sus elementos son tipos no fundamentales, utilice referencias o referencias `const` por razones de rendimiento.

#### Funciones
* Mantenga el nivel de anidamiento de sus funciones en 3 o menos. 
Si su función necesita más niveles de anidamiento, considere la posibilidad de refactorizarla en subfunciones.
* **Defina las variables en el ámbito más limitado posible.**
* **Utilice variables locales en lugar de globales siempre que sea posible.**
* Si necesita constantes globales, prefiera definir variables globales `constexpr` inline en un fichero de cabecera.
* Evite el uso de `inline` para funciones a menos que tenga una razón específica y convincente para hacerlo.
* Utilice un tipo de retorno `constexpr` para funciones que necesiten devolver una constante en tiempo de compilación.
* Utilice la sobrecarga de funciones para simplificar el programa.
* Si la función tiene una declaración hacia adelante (*forward*) (especialmente una en un fichero de cabecera), ponga el argumento por defecto allí. 
En caso contrario, coloque el argumento por defecto en la definición de la función.
* Evite devolver referencias a variables estáticas locales no-`const`.

#### Parámetros de funciones
* **Pase siempre `std::array` por referencia o referencia `const`.**
* **Cualifique `const` todas las referencias que correspondan a parámetros solo de entrada a una función.**
* Mantenga los nombres de los parámetros en las declaraciones de las funciones.
* Utilice una lista de parámetros vacía en lugar de `void` para indicar que una función no tiene parámetros.
* No pase `std::string` por valor, ya que hacer copias de std::string es costoso. Prefiera parámetros std::string_view.
* Prefiera `std::string_view` a `std::string` cuando necesite una cadena de sólo lectura, especialmente para parámetros de funciones.
* **Favorezca el paso por referencia const sobre el paso por referencia no-const a menos que tenga una razón específica para hacer lo contrario (por ejemplo, la función necesita cambiar el valor de un argumento).**
* **Pase los tipos fundamentales por valor y los tipos de clase (o estructura) por referencia constante.**
* **Prefiera el paso por valor para los objetos que son baratos de copiar, y el paso por referencia `const` para los objetos que son caros de copiar.
Si no está seguro de si un objeto es barato o caro de copiar, prefiera el paso por referencia constante.**
* Prefiera el paso por referencia al paso por dirección a menos que tenga una razón específica para usar el paso por dirección.

#### Enumeraciones
* Nombre sus tipos enumerados comenzando con una letra mayúscula. Nombre sus enumeradores comenzando con una letra minúscula.
* Prefiera colocar sus enumeraciones dentro de una región de ámbito con nombre (como un espacio de nombres o una clase) para que los enumeradores no contaminen el espacio de nombres global.
* Evite asignar valores explícitos a sus enumeradores a menos que tenga una razón de peso para hacerlo.
* Especifique el tipo base de una enumeración sólo cuando sea necesario.
* Prefiera las enumeraciones con ámbito a las enumeraciones sin ámbito a menos que haya una razón de peso para hacer lo contrario.

#### `std::string`
* **Utilice `std::string` o `std::string_view` en lugar de cadenas estilo C.**
* Prefiera std::string_view sobre std::string y cadenas estilo-C cuando sólo necesite acceso de sólo lectura a una cadena (a menos que no pueda garantizar que la cadena que está viendo permanecerá viva durante el tiempo de vida de std::string_view, en cuyo caso debería preferir std::string).
* Prefiera pasar cadenas usando std::string_view (por valor) en lugar de const std::string&, a menos que su función llame a otras funciones que requieran cadenas estilo C o parámetros std::string.

#### Clases
* **Proporcione un valor por defecto para todos los miembros (atributos de una clase).
Esto asegura que sus miembros serán inicializados incluso si la definición del objeto no incluye una lista de inicializadores.**
* Si no se van a proporcionar valores inicializadores explícitos para un agregado, prefiera la inicialización por valor (con un inicializador de llaves vacío) a la inicialización por defecto (sin llaves).
* **Utilice la palabra reservada `struct` para estructuras de sólo datos. 
Utilice la palabra reservada `class` para objetos que tengan tanto datos como funciones.**
* **Haga privadas las variables miembro, y públicas las funciones miembro, a menos que tenga una buena razón para no hacerlo.**
* Los getters deben devolver por valor o referencia constante.
* **Favorezca la inicialización uniforme (*brace initialization*) para inicializar objetos.**
* **Si tiene constructores en su clase y necesita un constructor por defecto que no haga nada (por ejemplo, porque todos sus miembros se inicializan utilizando inicialización de miembros no estática), utilice `= default`.**
* **Inicialice siempre todas las variables miembro de tus objetos.**
* **Utilice listas de inicialización de miembros para inicializar las variables miembro de su clase en lugar de asignaciones.**
* **Haga que cualquier función miembro que no modifique el estado del objeto de la clase sea `const`, para que pueda ser llamada por objetos `const`.**
* Acceda a los miembros estáticos por el nombre de la clase (utilizando el operador de resolución de ámbito) en lugar de a través de un objeto de la clase (utilizando el operador de selección de miembros).
* Al sobrecargar operadores, es mejor mantener la función de los operadores lo más cerca posible de la intención original de los operadores.
* Si el significado de un operador sobrecargado no es claro e intuitivo, utilice en su lugar una función con nombre.
* Prefiera sobrecargar los operadores como funciones normales en lugar de friends si es posible hacerlo sin añadir funciones adicionales.
* Defina únicamente operadores sobrecargados que tengan un sentido intuitivo para su clase.
* Evita usar inicialización de copia, y usa inicialización uniforme en su lugar.
* Implemente el tipo de relación más simple que satisfaga las necesidades de su programa, no lo que parezca correcto en la vida real.
* Prefiera los miembros privados a los protegidos.
* Utilice la herencia pública a menos que tenga una razón específica para hacer lo contrario.
* Evite la herencia múltiple a menos que las alternativas conduzcan a una mayor complejidad.

#### Referencias
* [C++ Coding Standards: 101 Rules, Guidelines, and Best
Practices](https://learning.oreilly.com/library/view/c-coding-standards/0321113586/)
* [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
* [LLVM Coding Standards](https://llvm.org/docs/CodingStandards.html)
* [C++ Programming Style Guidelines](https://geosoft.no/development/cppstyle.html)
* [A comparison of common C++ style guides](https://github.com/motine/cppstylelineup)



