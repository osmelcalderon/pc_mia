
https://developer.mozilla.org/es/docs/Web/JavaScript/Guide/Expressions_and_Operators
https://www.include-poetry.com/Code/C++/Estructuras/Operaciones-con-bits/
https://es.khanacademy.org/computing/ap-computer-science-principles/x2d2f703b37b450a3:digital-information/x2d2f703b37b450a3:binary-numbers/v/the-binary-number-system
http://www.etnassoft.com/2012/06/06/operadores-bitwise-en-javascript/
	operadores binarios y unarios, y un operador ternario especial, el operador condicional. Un operador binario requiere dos operandos, uno antes del operando y otro después del operador:


comprobacion aritmetica
return [...'+-*/'].some(op => eval(`${A}${op}${B}`) === C)


//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////Operadores lógicos bit a bit (Bitwise)//////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

- Una operación bit a bit (o Bitwise): opera sobre números binarios a nivel de bits individuales. 
			Es una acción primitiva sustancialmente más rápida que las que se llevan a cabo sobre 
			el valor real de los operandos.


- Los Bitwise en Javascript: Son operadores de 32-bits, lo que significa que en el manejo de valores 
		  binarios, un número como 0101 se procesa internamente como 00000000000000000000000000000101. 
		  Sin embargo, todos los ceros de la izquierda pueden despreciarse ya que, como en el caso de 
		  los números decimales, no tienen ningún significado o valor.


Operador		             Uso						Descripción rápida
& (AND)						a & b				Devuelve 1 si ambos operandos son 1
| (OR)						a | b				Devuelve 1 donde uno o ambos operandos son 1
^ (XOR)						a ^ b				Devuelve 1 donde un operando, pero no ambos, es 1
~ (NOT)						~a					Invierte el	valor del operando
<< (desplaza  izquierda)	a << b				Desplaza a la izquierda un número especificado de bits.
>> (Desplaza  derecha)		a >> b				Desplaza a la derecha un número especificado de bits.
>>> (desplaza derecha 		a >>> b				Desplaza la derecha un número especificado de bits descartando los bits desplazados y sustituyéndolos por ceros.
     con acarreo)




Paridad de números binarios 
  - Los números binarios que representan números pares terminan en  .
  - Todo número binario finalizado en  corresponde a un decimal impar.


El complemento a 2 es una forma de representar números negativos en el sistema binario.
El complemento a dos de un número N , expresado en el sistema binario con n dígitos, se define como:
https://es.wikipedia.org/wiki/Complemento_a_dos#:~:text=El%20complemento%20a%202%20es,negativos%20en%20el%20sistema%20binario.&text=El%20complemento%20a%20dos%20de,n%20d%C3%ADgitos%2C%20se%20define%20como%3A&text=%2C%20siendo%20n%20el%20n%C3%BAmero%20de%20bits.

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//(AND a nivel de bits) cuando 1=1 true, el resto es false 
// ** Devuelve 1 si ambos operandos son 1
//Devuelve un uno en cada posición del bit para los que los bits correspondientes de ambos operandos son unos.
1 & 1 = 1
0 & 0 = 0
1 & 0 = 0

console.log(1  & 1 ); //  1
console.log(0 & 0 ); //  0
console.log(1  & 0 ); //  0
console.log(0  & 1 ); //  0

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//(OR a nivel de bits) INCLUSIVO
// ****Devuelve 1 donde uno o ambos operandos son 1
//Devuelve un cero en cada posición de bit para el cual los bits correspondientes de ambos operandos son ceros.

1 | 1 = 1
0 | 0 = 0
1 | 0 = 1
0 | 1 = 1

console.log(1 | 1 ); //  1
console.log(0 | 0 ); //  0
console.log(1 | 0 ); //  1
console.log(0 | 1 ); //  1


//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//(XOR a nivel de bits) EXCLUSIVO. cuando son iguales son 0, diferente son 1
// ** Devuelve 1 donde un operando, pero no ambos, es 1
//Devuelve un cero en cada posición de bit para la que los bits correspondientes son iguales. 
//[Devuelve uno en cada posición de bit para la que los bits correspondientes son diferentes].

1  ^ 1 = 0  
0  ^ 0 = 0
1  ^ 0 = 1
console.log(1  ^ 1 ); //  0
console.log(0 ^ 0 ); //  0
console.log(1  ^ 0 ); //  1
console.log(0  ^ 1 ); //  1


//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//https://www.techiedelight.com/es/bit-hacks-part-3-playing-rightmost-set-bit-number/

//NOT a nivel de bits
//Invierte los bits de su operando.
//es una operación unaria que realiza la negación lógica en cada bit, invirtiendo los bits del número,
// de tal manera que los ceros se convierten en 1 y viceversa:


~0; // -1
~-1; // 0
~1; // -2

console.log(~1 ); //  0
console.log(~0 ); //  1


Otra característica matemática de estos Bitwise la podemos observar en el operador NOT: 
aplicado a cualquier número x, se obtiene el resultado -(x + 1).Por ejemplo:

console.log( ~2 ); // -3
console.log( ~5 ); // -6
console.log( ~-5 ); // 4 => -( -5 + 1 ) => - (-4) => 4


					//NOT a nivel de bits



inverso = 255-(valor) 
11111100

0 = 255
1 = 254
2 = 253

128 = 127
128 = 10000000
01111111

(00000001)₂ 
		  = (0 × 2⁷) + (0 × 2⁶) + (0 × 2⁵) + (0 × 2⁴) + (0 × 2³) + (0 × 2²) + (1 × 2¹) + (0 × 2⁰) 
		  = (2)₁₀
		  = 2

(11111110)₂ 
		  = (1 × 2⁷) + (1 × 2⁶) + (1 × 2⁵) + (1 × 2⁴) + (1 × 2³) + (1 × 2²) + (1 × 2¹) + (0 × 2⁰) 
		  =  128+64+32+16+8+4+2
		  =  254

//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////DESPLAZAMIENTOS LOGICOS DE BITS//////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//El desplazamiento lógico se usa para mover bits hacia la izquierda o hacia la derecha 
//para colocarlos en la posición adecuada. En programación, el primer operando representa 
//el binario que queremos modificar mientras que el segundo indica las posiciones a desplazar:

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

//   << (desplaza  izquierda)	a << b				
//  Desplaza a la izquierda un número especificado de bits. para colocarlos en la posición adecuada
// - El primer operando representa el binario que queremos modificar 
// - El segundo indica "las posiciones a desplazar":


binario_A_modificar << posición_A_desplazar = resultado
           00011100 <<        1             = 00111000

           00011100 <<        2             = 01110000	




//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

//>> (Desplaza  derecha)		a >> b			
//Desplaza a la derecha un número especificado de bits. para colocarlos en la posición adecuada
// - El primer operando representa el binario que queremos modificar 
// - El segundo indica "las posiciones a desplazar":

00011100 >> 1 = 00001110
00011100 >> 2 = 00000111

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

>>> (desplaza derecha 		a >>> b				Desplaza la derecha un número especificado de bits descartando los bits desplazados y sustituyéndolos por ceros.
     con acarreo. 
    "CON RELLENOS DE CEROS")

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

//convertir a binario
//https://lenguajejs.com/javascript/number/conversiones-numericas/


Cómo pasar un número decimal a binario
	(2).toString(2); // "10"
	(5).toString(2); // "101"
	(10).toString(2); // "1010"

Cómo pasar un número binario a decimal. 

	parseInt('10', 2); // 2
	parseInt('101', 2); // 5
	parseInt('1010', 2); // 10
	parseInt('00000000101', 2); // 5


Uso de los operadores Bitwise como ‘shortcuts o atajos’ matemáticos
 - obtener la parte entera de un número en coma flotante utilizando bien una comparación 
    ‘truncado’, o redondeo  similar al método nativo Math.floor(),

 		- Operador OR(|) a 0 
 		- Operador XOR(^) a 0 

12.65 | 0 // 12
13.000001 | 0 // 13
15.999999 | 0 // 15
 
12.65 ^ 0 // 12
13.000001 ^ 0 // 13
15.999999 ^ 0 // 15




//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
Operaciones comunes de bits
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////Encender un bit en una posición
Si queremos encender un bit (hacerlo 1) en alguna posición podemos aplicar un corrimiento 
a la izquierda de un 1 seguido por una operación OR. Por ejemplo, si queremos encender el bit 
x de un número a podemos hacer algo como sigue:

	a = a | (1 << x); // Encendemos el bit x de a


	00000001 << x = 00001000 //corriendo a la izquierda, donde x=3

////////////////////////Apagar un bit en una posición
Si queremos apagar un bit (hacerlo 0) en alguna posición podemos aplicar un corrimiento de un 
1 seguido por una operación NOT y una AND. Por ejemplo, si queremos apagar el bit x de un número 
a podemos hacer:
	a = a & ~(1 << x); // Apagamos el bit x de a

	00000001 << x = 00001000 //corriendo a la izquierda, donde x=3

	~(00001000) = 11110111


////////////////////////Invertir un bit
También podemos invertir el valor de un bit, apagarlo si está encendido y encenderlo si está apagado.
Esto se logra haciendo una operación XOR al corrimiento de un 1. Si queremos invertir el bit x de un
número a lo hacemos así:

a = a ^ (1 << x); // Invertimos el bit x de a


////////////////////////Revisar si un bit está encendido
Podemos saber si un bit x está encendido en una variable a aplicando un corrimiento de un 1 seguido
de una operación AND. Por ejemplo:

if (a & (1 << x)) // Si esto se cumple entonces el bit es 1

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
Trucos útiles con bits
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

Contar bits establecidos en un entero
	https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
	https://www.include-poetry.com/Code/C++/Estructuras/Operaciones-con-bits/


10 en binario es 00001010 
9 en binario es 00001001 
8 en binario es 00001000 
7 en binario es 00000111 

Así que si restamos un número por 1 y lo hacemos bit a bit y consigo mismo 
(n & (n-1)), desarmamos el bit establecido más a la derecha. 
Si hacemos n & (n-1) en un bucle y contamos el número de veces que se ejecuta el bucle, obtenemos el número de bits establecido. 
La belleza de esta solución es que la cantidad de veces que se repite es igual a la cantidad de bits establecidos en un entero dado. 




00001010 
00001001
00001000

n= 00001000
   00000111  	