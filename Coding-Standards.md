### Universidad de La Laguna
### Escuela Superior de Ingeniería y Tecnología
### Grado en Ingeniería Informática
### Informática Básica

# C++ C++ Coding Standards: Rules, Guidelines, & Best Practices

* Cree un nuevo proyecto (y directorio) para cada nuevo programa que escriba.
* Utilice al compilar la opción -std=c++17 de modo que sus programas (y sus prácticas de codificación) cumplen los estándares de C++ y funcionan en cualquier sistema.
* No deje que se acumulen los *warning*. Resuélvalos a medida que aparezcan (como si fueran errores). De lo contrario, una advertencia sobre un problema grave puede perderse entre advertencias sobre problemas no graves.
* Configure al máximo los niveles de aviso en las opciones del compilador, sobre todo cuando esté aprendiendo. Le ayudará a identificar posibles problemas.
* Active la opción de compilación "Tratar los avisos como errores" (`-Werror`). Esto le obligará a resolver todos los problemas que causen advertencias.
* Cuando trate errores de compilación en sus programas, resuelva siempre primero el primer error producido y luego vuelva a compilar.
* Escriba sus comentarios como si estuviera hablando con alguien que no tiene ni idea de lo que hace el código. No de por sentado que recordará por qué se tomaron determinadas decisiones.
* Aunque el lenguaje lo permita, evite definir múltiples variables del mismo tipo en una misma sentencia. En su lugar, defina cada variable en una sentencia separada en su propia línea.
* Inicialice las variables al crearlas.
* Siempre que sea posible, utilice llaves (*brace initialization*) para inicializar las variables.
* Existe cierto debate sobre si es necesario inicializar una variable inmediatamente antes de darle un valor proporcionado por el usuario a través de otra fuente (por ejemplo, `std::cin`), ya que el valor proporcionado por el usuario simplemente sobrescribirá el valor de inicialización. En línea con la recomendación anterior de que las variables deben ser siempre inicializadas, la mejor práctica es inicializar la variable primero.
* Prefiera `'\n'` a `std::endl` cuando envíe texto a la consola.
* Los programadores noveles a menudo tratan de escribir un programa entero de una sola vez, y luego se sienten abrumados cuando produce un montón de errores. Una mejor estrategia es añadir una parte cada vez, asegurarse de que compila y probarlo. Entonces, cuando tenga seguridad de que funciona, pase a la siguiente pieza.
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
* Defina sus variables locales tan cerca de su primer uso como sea razonable.
* Utilice prefijos de espacio de nombres explícitos (*namespace*) para acceder a identificadores definidos en un espacio de nombres.


#### Reglas de nombrado
* Nombre sus ficheros de código `algo.cc`, donde `algo` será un nombre significativo de su elección, y .cc es la extensión que indica que el fichero es un archivo fuente C++.
* Utilice la extensión `.h` cuando nombre sus ficheros de cabecera.
* Si un fichero de cabecera está emparejado con un fichero de código (por ejemplo, `add.h` con `add.cc`), ambos deben tener el mismo nombre base (`add`).
* Los ficheros fuente deben #incluir el fichero de cabecera emparejado (si existe).

#### Ficheros de cabecera (`*.h`)
* Por lo general, los ficheros de cabecera no deben contener definiciones de funciones y variables, para no infringir la regla de una definición. 
* Cada fichero debe `#incluir` explícitamente todos los ficheros de cabecera que necesite para compilar. 
* Cuando incluya un fichero de cabecera de la biblioteca estándar, utilice la versión sin la extensión `.h` si existe. 
Las cabeceras definidas por el usuario deben seguir utilizando la extensión `.h`.
* Para maximizar la posibilidad de que los includes que falten sean marcados por el compilador, ordene sus #includes como sigue:
1. El fichero de cabecera emparejado
2. Otras cabeceras de su proyecto
3. Cabeceras de librerías de terceros
4. Cabeceras de librerías estándar

Las cabeceras de cada grupo deben ordenarse alfabéticamente.

#### Parámetros de funciones
* Always const-qualify all pointers or references to input-only parameters.
* Mantenga los nombres de los parámetros en las declaraciones de las funciones.




Prefiera los guardianes de cabecera a #pragma once para obtener la máxima portabilidad.

Utilice una herramienta de análisis estático en sus programas para ayudar a encontrar áreas en las que su código no cumple con las mejores prácticas.

Para una máxima compatibilidad, no debería asumir que las variables son mayores que el tamaño mínimo especificado.

Prefiera los tipos abreviados que no utilizan el sufijo int ni el prefijo signed.
Utilice una lista de parámetros vacía en lugar de void para indicar que una función no tiene parámetros.

Prefiera los números con signo a los números sin signo para almacenar cantidades (incluso cantidades que no deben ser negativas) y operaciones matemáticas. Evite mezclar números con y sin signo.

Prefiera int cuando el tamaño del entero no importe (por ejemplo, el número siempre cabrá dentro del rango de un entero con signo de 2 bytes). Por ejemplo, si está pidiendo al usuario que introduzca su edad, o que cuente del 1 al 10, no importa si int tiene 16 o 32 bits (los números cabrán de cualquier forma). Esto cubrirá la gran mayoría de los casos con los que probablemente te encuentres.
Prefiera std::int#_t cuando almacene una cantidad que necesite un rango garantizado.
Prefiera std::uint#_t cuando manipule bits o cuando necesite un comportamiento envolvente bien definido.
Evite lo siguiente siempre que sea posible:
Tipos sin signo para contener cantidades
Los tipos enteros de ancho fijo de 8 bits
Los tipos de ancho fijo rápido y mínimo
Cualquier entero de ancho fijo específico del compilador -- por ejemplo, Visual Studio define __int8, __int16, etc...

Asegúrese siempre de que el tipo de sus literales coincide con el tipo de las variables a las que se asignan o que se utilizan para inicializar. De lo contrario, se producirá una conversión innecesaria, posiblemente con pérdida de precisión.

Prefiera double a float a menos que el espacio sea un bien escaso, ya que la falta de precisión en un float a menudo conducirá a imprecisiones.

Evite por completo la división por 0, incluso si su compilador la admite.

Ponga los caracteres independientes entre comillas simples (por ejemplo, 't' o '\n', no "t" o "\n"). De este modo, el compilador optimiza mejor.

Evite los literales con varios caracteres (por ejemplo, '56').

Coloque const antes del tipo (porque es más idiomático hacerlo).

No use const cuando pase por valor.

No utilice const cuando devuelva por valor.

Prefiera las variables constantes a las macros tipo objeto con texto de sustitución.

Cualquier variable que no deba modificarse después de la inicialización y cuyo inicializador se conozca en tiempo de compilación debe declararse como constexpr.
Cualquier variable que no deba modificarse tras la inicialización y cuyo inicializador no se conozca en tiempo de compilación debe declararse como const.

Prefiera el sufijo literal L (mayúsculas) a l (minúsculas).

Evite los números mágicos en su código (utilice variables constexpr en su lugar).

Si utiliza std::getline() para leer cadenas, utilice el manipulador de entrada std::cin >> std::ws para ignorar los espacios en blanco iniciales.

No pase std::string por valor, ya que hacer copias de std::string es costoso. Prefiera parámetros std::string_view.

Prefiera std::string_view a std::string cuando necesite una cadena de sólo lectura, especialmente para parámetros de funciones.

Utilice paréntesis para dejar claro cómo debe evaluarse una expresión no trivial (aunque sean técnicamente innecesarios).

Las expresiones con un único operador de asignación no necesitan tener el operando derecho de la asignación envuelto entre paréntesis.

Aparte de las reglas de precedencia y asociatividad de operadores, asuma que las partes de una expresión pueden evaluarse en cualquier orden. Asegúrese de que las expresiones que escribe no dependen del orden de evaluación de esas partes.

Prefiera la versión prefijada de los operadores de incremento y decremento, ya que generalmente son más eficaces y es menos probable que se encuentre con problemas extraños con ellos.

Evite utilizar el operador coma, excepto en los bucles for.

Ponga siempre entre paréntesis la parte condicional del operador condicional, y considere también la posibilidad de poner entre paréntesis el operador completo. ? :

Utilice el operador condicional sólo para condicionales sencillas en las que utilice el resultado y mejoren la legibilidad.

No añada == o != innecesarios a las condiciones. Dificultan la lectura sin aportar ningún valor adicional.

Si se pretende que NOT lógico opere sobre el resultado de otros operadores, los otros operadores y sus operandos deben ir entre paréntesis.

Cuando se mezclan los operadores lógicos AND y OR en una misma expresión, hay que poner explícitamente entre paréntesis cada operación para asegurarse de que se evalúan como se pretende.

La manipulación de bits es una de las pocas ocasiones en las que debe utilizar sin ambigüedad enteros sin signo (o std::bitset).

Para evitar sorpresas, utilice los operadores bit a bit con operandos sin signo o std::bitset.

Mantenga el nivel de anidamiento de sus funciones en 3 o menos. Si su función necesita más niveles de anidamiento, considere la posibilidad de refactorizarla en subfunciones.

Defina las variables en el ámbito más limitado posible. Evite crear nuevos bloques cuyo único propósito sea limitar el ámbito de las variables.

Considere el uso de un prefijo "g" o "g_" al nombrar variables globales no-const, para ayudar a diferenciarlas de las variables locales y los parámetros de función.

Evite la sombra de variables.

Utilice variables locales en lugar de globales siempre que sea posible.

Si necesitas constantes globales y tu compilador es compatible con C++17, prefiere definir variables globales constexpr inline en un fichero de cabecera.

Inicializa tus variables locales estáticas. Las variables locales estáticas sólo se inicializan la primera vez que se ejecuta el código, no en llamadas posteriores.

Evite las variables locales estáticas a menos que la variable nunca necesite ser reiniciada.

Prefiera los espacios de nombres explícitos a las sentencias using. Evite el uso de directivas siempre que sea posible. Las declaraciones de uso están bien para usarlas dentro de bloques.

No utilice la palabra clave inline para solicitar la expansión inline de sus funciones.

Evite el uso de la palabra clave inline para funciones a menos que tenga una razón específica y convincente para hacerlo.

Utilice un tipo de retorno constexpr para funciones que necesiten devolver una constante en tiempo de compilación.

Utilice consteval si tiene una función que debe ejecutarse en tiempo de compilación por alguna razón (por ejemplo, rendimiento).

Considere la posibilidad de poner las sentencias individuales asociadas a un if o else en bloques (sobre todo mientras está aprendiendo). Los desarrolladores de C++ más experimentados a veces ignoran esta práctica en favor de un espaciado vertical más ajustado.

Prefiera las sentencias switch a las cadenas if-else cuando pueda elegir.

Coloque el caso por defecto en último lugar en el bloque switch.

Cada conjunto de sentencias bajo una etiqueta debe terminar en una sentencia break o return. Esto incluye las sentencias bajo la última etiqueta en el switch.

Utilice el atributo [[fallthrough]] (junto con una sentencia null) para indicar un fallthrough intencionado.

Si define variables utilizadas en una sentencia case, hágalo en un bloque dentro del case.

Evite las sentencias goto (a menos que las alternativas sean significativamente peores para la legibilidad del código).

Prefiera while(true) para bucles infinitos intencionados.

Las variables de bucle deben ser de tipo int (con signo).

Prefiera los bucles while a los do-while en igualdad de condiciones.

Evite el operador!= cuando realice comparaciones numéricas en la condición del bucle for.

Definir múltiples variables (en la sentencia init) y utilizar el operador coma (en la expresión final) es aceptable dentro de una sentencia for.

Prefiera los bucles for a los bucles while cuando exista una variable de bucle obvia.
Prefiera los bucles while a los for cuando no haya una variable de bucle obvia.

Utilice break y continue cuando simplifiquen la lógica del bucle.

Utilice retornos anticipados cuando simplifiquen la lógica de su función.

Sólo use un halt si no hay una forma segura de retornar normalmente desde la función principal. Si no has desactiv

Escriba su programa en unidades pequeñas y bien definidas (funciones o clases), compile a menudo y pruebe su código sobre la marcha.

Procure que el código cubra el 100% de las ramas.

Pruebe diferentes categorías de valores de entrada para asegurarse de que su unidad los maneja correctamente.

Utilice aserciones para documentar casos que deberían ser lógicamente imposibles.

Utilice std::random_device para sembrar sus PRNGs (a menos que no esté implementado correctamente para su compilador/arquitectura de destino).

Sólo siembra un generador de números pseudoaleatorios una vez, y no lo vuelvas a sembrar.

Evite las conversiones de estrechamiento siempre que sea posible. Si necesita realizar una, utilice static_cast para que sea una conversión explícita.

Evite utilizar conversiones tipo C.

Utilice static_cast cuando necesite convertir un valor de un tipo a otro.

Nombra tus alias de tipo empezando con mayúscula y no uses un sufijo (a menos que tengas una razón específica para hacerlo de otra manera).

Prefiera los alias de tipo a los typedefs.

Use los alias de tipo con criterio, cuando proporcionen un beneficio claro para la legibilidad o el mantenimiento del código.

Utilice la deducción de tipos para sus variables, a menos que necesite comprometerse con un tipo específico.

Favorezca los tipos de retorno explícitos sobre la deducción de tipo de retorno de función para funciones normales.

Utilice la sobrecarga de funciones para simplificar el programa.

Si la función tiene una declaración hacia adelante (especialmente una en un fichero de cabecera), ponga el argumento por defecto allí. En caso contrario, coloque el argumento por defecto en la definición de la función.

Utilice una sola letra mayúscula (empezando por T) para nombrar sus tipos de plantilla (por ejemplo, T, U, V, etc...)

Favorezca la sintaxis normal de llamada a función cuando utilice plantillas de función.

Utilice plantillas de funciones para escribir código genérico que pueda funcionar con una amplia variedad de tipos siempre que lo necesite.

Siéntase libre de utilizar plantillas de función abreviadas con un único parámetro automático, o cuando cada parámetro automático deba ser un tipo independiente (y su estándar de lenguaje sea C++20 o más reciente).

Cuando defina una referencia, coloque el ampersand junto al tipo (no junto al nombre de la variable de referencia).

Prefiera las referencias lvalue a const sobre las referencias lvalue a no-const a menos que necesite modificar el objeto referenciado.

Favorezca el paso por referencia const sobre el paso por referencia no-const a menos que tenga una razón específica para hacer lo contrario (por ejemplo, la función necesita cambiar el valor de un argumento).

Pase los tipos fundamentales por valor y los tipos de clase (o estructura) por referencia constante.

Prefiera el paso por valor para los objetos que son baratos de copiar, y el paso por referencia const para los objetos que son caros de copiar. Si no está seguro de si un objeto es barato o caro de copiar, prefiera el paso por referencia constante.

Al declarar un tipo de puntero, coloque el asterisco junto al nombre del tipo.

Inicialice siempre sus punteros.

Inicialice con valor sus punteros (para que sean punteros nulos) si no los está inicializando con la dirección de un objeto válido.

Utilice nullptr cuando necesite un literal de puntero nulo para inicializar, asignar o pasar un puntero nulo a una función.

Un puntero debe contener la dirección de un objeto válido, o ser establecido a nullptr. De esta forma, sólo tendremos que comprobar si un puntero es nulo, y podremos asumir que cualquier puntero no nulo es válido.

Preferir las referencias a los punteros a menos que se necesiten las capacidades adicionales que proporcionan los punteros.

Prefiera el paso por referencia al paso por dirección a menos que tenga una razón específica para usar el paso por dirección.

Evite devolver referencias a variables estáticas locales no-const.

Prefiera devolver por referencia a devolver por dirección a menos que la capacidad de devolver "ningún objeto" (usando nullptr) sea importante.

Si desea una referencia const, vuelva a aplicar el calificador const incluso cuando no sea estrictamente necesario, ya que deja clara su intención y ayuda a evitar errores.

Si desea un puntero const, vuelva a aplicar el calificador const incluso cuando no sea estrictamente necesario, ya que aclara su intención y ayuda a evitar errores.

Nombra los tipos definidos por el programa empezando con mayúscula y sin sufijo.

Un tipo definido por el programa utilizado en un solo fichero de código debe definirse en ese fichero de código lo más cerca posible del primer punto de uso.
Un tipo definido por el programa utilizado en varios ficheros de código debe definirse en un fichero de cabecera con el mismo nombre que el tipo definido por el programa y luego #incluirse en cada fichero de código según sea necesario.

Nombre sus tipos enumerados comenzando con una letra mayúscula. Nombre sus enumeradores comenzando con una letra minúscula.

Prefiera colocar sus enumeraciones dentro de una región de ámbito con nombre (como un espacio de nombres o una clase) para que los enumeradores no contaminen el espacio de nombres global.

Evite asignar valores explícitos a sus enumeradores a menos que tenga una razón de peso para hacerlo.

Especifique el tipo base de una enumeración sólo cuando sea necesario.

Prefiera las enumeraciones con ámbito a las enumeraciones sin ámbito a menos que haya una razón de peso para hacer lo contrario.

Prefiera la forma de lista con corchetes (no copia) al inicializar agregados.

Al añadir un nuevo miembro a un agregado, lo más seguro es añadirlo al final de la lista de definición para que los inicializadores de otros miembros no se desplacen.

Proporcione un valor por defecto para todos los miembros. Esto asegura que sus miembros serán inicializados incluso si la definición de la variable no incluye una lista de inicializadores.

Si no se van a proporcionar valores inicializadores explícitos para un agregado, prefiera la inicialización por valor (con un inicializador de llaves vacío) a la inicialización por defecto (sin llaves).

Cuando utilice un puntero para acceder al valor de un miembro, utilice el operador de selección de miembro desde puntero (->) en lugar del operador de selección de miembro (.).

Inicialice explícitamente sus matrices (incluso cuando el tipo de elemento sea autoinicializable).

Utilice std::string o std::string_view (próxima lección) en lugar de cadenas estilo C.

Prefiera std::string_view sobre std::string y cadenas estilo-C cuando sólo necesite acceso de sólo lectura a una cadena (a menos que no pueda garantizar que la cadena que está viendo permanecerá viva durante el tiempo de vida de std::string_view, en cuyo caso debería preferir std::string).

Prefiera pasar cadenas usando std::string_view (por valor) en lugar de const std::string&, a menos que su función llame a otras funciones que requieran cadenas estilo C o parámetros std::string.

Favorecer la sintaxis de puntero (*) sobre la sintaxis de array ([]) para parámetros de función de array.

Establezca los punteros eliminados como nullptr a menos que salgan del ámbito inmediatamente después.

En las declaraciones de elementos de bucles for-each, si sus elementos son tipos no fundamentales, utilice referencias o referencias const por razones de rendimiento.

Pase siempre std::array por referencia o referencia const.

A menos que se especifique lo contrario, no asuma que los algoritmos de la biblioteca estándar se ejecutarán en una secuencia particular. std::for_each, std::copy, std::copy_backward, std::move, y std::move_backward tienen garantías secuenciales.

Favorece el uso de funciones de la biblioteca de algoritmos en lugar de escribir tu propia funcionalidad para hacer lo mismo.

Generalmente favorece la iteración sobre la recursión, excepto cuando la recursión realmente tiene sentido.

Sólo inicialice variables en la captura si su valor es corto y su tipo es obvio. De lo contrario, es mejor definir la variable fuera de la lambda y capturarla.

Intenta evitar las lambdas mutables. Las lambdas no mutables son más fáciles de entender y no sufren los problemas anteriores, así como otros más peligrosos que surgen cuando añades la ejecución paralela.

Nombra tus clases empezando con mayúscula.

Utilice la palabra clave struct para estructuras de sólo datos. Utilice la palabra clave class para objetos que tengan tanto datos como funciones.

Haga privadas las variables miembro, y públicas las funciones miembro, a menos que tenga una buena razón para no hacerlo.

Los getters deben devolver por valor o referencia constante.

Favorezca la inicialización brace para inicializar objetos de clase.

Si tiene constructores en su clase y necesita un constructor por defecto que no haga nada (por ejemplo, porque todos sus miembros se inicializan utilizando inicialización de miembros no estática), utilice = default.

Inicializa siempre todas las variables miembro de tus objetos.

Utilice listas de inicialización de miembros para inicializar las variables miembro de su clase en lugar de asignaciones.

Si tienes varios constructores con la misma funcionalidad, utiliza constructores delegados para evitar duplicar código.

Haz que cualquier función miembro que no modifique el estado del objeto de la clase sea const, para que pueda ser llamada por objetos const.
Acceda a los miembros estáticos por el nombre de la clase (utilizando el operador de resolución de ámbito) en lugar de a través de un objeto de la clase (utilizando el operador de selección de miembros).

Al sobrecargar operadores, es mejor mantener la función de los operadores lo más cerca posible de la intención original de los operadores.

Si el significado de un operador sobrecargado no es claro e intuitivo, utilice en su lugar una función con nombre.

Prefiera sobrecargar los operadores como funciones normales en lugar de friends si es posible hacerlo sin añadir funciones adicionales.

Defina únicamente operadores sobrecargados que tengan un sentido intuitivo para su clase.

Evita usar inicialización de copia, y usa inicialización uniforme en su lugar.

Considere la posibilidad de hacer explícitos los constructores y las funciones miembro de conversión definidas por el usuario para evitar errores de conversión implícitos.

Implemente el tipo de relación más simple que satisfaga las necesidades de su programa, no lo que parezca correcto en la vida real.

Si proporciona construcción de listas, es una buena idea proporcionar también asignación de listas.

Prefiera los miembros privados a los protegidos.

Utilice la herencia pública a menos que tenga una razón específica para hacer lo contrario.

Evite la herencia múltiple a menos que las alternativas conduzcan a una mayor complejidad.

Nunca llame a funciones virtuales desde constructores o destructores.

Utilice la palabra clave virtual en las funciones virtuales de una clase base. Utilice el especificador override (pero no la palabra clave virtual) en funciones override en clases derivadas.

