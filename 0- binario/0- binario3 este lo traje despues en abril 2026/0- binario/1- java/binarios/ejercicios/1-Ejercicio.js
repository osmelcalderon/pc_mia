/*
trucos para jugar con bits
  https://graphics.stanford.edu/~seander/bithacks.html#OperationCounting
  https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
  

  "hacks de bits" o "manipulación de bits"
https://www.techiedelight.com/es/bit-hacks-part-1-basic/
https://www.techiedelight.com/es/bit-hacks-part-2-playing-kth-bit/
https://www.techiedelight.com/es/bit-hacks-part-3-playing-rightmost-set-bit-number/
https://www.techiedelight.com/es/bit-hacks-part-4-playing-letters-english-alphabet/
https://www.techiedelight.com/es/bit-hacks-part-5-find-absolute-value-integer-without-branching/

Serie de increíbles trucos de "manipulación de bits" que todo programador debería conocer.

*/

////////////////////////////////////////////////////////////
////////////////////PAR O IMPAR////////////////////////////////////////
////////////////////////////////////////////////////////////

/*
  1. Comprueba si un entero es par o impar
			
			(n & 1) = (0 | 1)

Este es probablemente uno de los hacks de bits más simples y más utilizados. 
La expresion n & 1 devuelve el valor 1 o 0 dependiendo de si n es par o impar.

  par: el binario termina en 0
impar: el binario termina en 1


00010100    &                   (n = 20)
00000001                        (1)
~~~~~~~~
00000000
 
 
00010101    &                   (n = 21)
00000001                        (1)
~~~~~~~~
00000001

*/

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
son pares e impares, negativos y positivos

/*
 2. Detectar si dos números enteros tienen signos opuestos o no
*/ 


https://javascript.espaciolatino.com/javascript/operadores-binarios.htm


//////////////////////////////////////////
Cual es la diferencia de un número con su antecesor?


 n-1: 
 	- tendrá todos los bits invertidos después del bit establecido más a la derecha
    de n (incluido el bit establecido más a la derecha). 
	- tendrá todos los bits iguales antes del bit establecido más a la derecha de n 

		ejemplo:
			11111111       255
			11111110       254
			11111101       253


Cual es la diferencia de un número con su predecesor?


 n+1: 
	- tendrá todos los bits iguales antes del bit "NO establecido" más a la derecha de n
 	- tendrá todos los bits invertidos después del bit "NO establecido" más a la derecha
    de n (incluido el bit "NO establecido" más a la derecha). 

		ejemplo:
			11111111       255
			11111110       254
			11111101       253



00010000  & (n = 16, solo un bit establecido)
00001111       (n-1 = 15)
~~~~~~~~
00000000


00010100 & (n = 20)
00010011     (n-1 = 19)
~~~~~~~~
00010000


00010100 ^
00010000
~~~~~~~~
00000100

n ^ (n & (n-1))