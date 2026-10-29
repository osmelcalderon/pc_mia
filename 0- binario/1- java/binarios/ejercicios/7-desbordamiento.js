/*https://www.similaranswer.es/como-se-puede-producir-el-desbordamiento/#que-causa-el-desbordamiento-aritmetico 

https://www.tektutorialshub.com/typescript/typescript-number/#number-data-type

* El desbordamiento indica que el resultado fue demasiado grande o demasiado 
   pequeño para caber en el tipo de datos original.

- Por qué ocurren los desbordamientos de enteros?
  En el nivel más básico, se produce un desbordamiento de enteros cuando el
  resultado de una operación aritmética necesita más bits que los que 
  tiene la variable de destino.  Por ejemplo, el número más grande que 
 puede almacenar en una  variable entera sin signo de 32 bits es 4.294.967.295.


- Se produce un desbordamiento de enteros cuando intenta almacenar
 dentro de una variable entera un valor que es mayor que el valor máximo
  que puede contener la variable.

- Las reglas para detectar el desbordamiento en una suma de complemento a dos son simples:

Si la suma de dos números positivos da un resultado negativo, la suma se ha desbordado.
Si la suma de dos números negativos da un resultado positivo, la suma se ha desbordado.
De lo contrario, la suma no se ha desbordado.










Método 1 
Puede haber desbordamiento solo si los signos de dos números son iguales y el signo de la suma es opuesto a los signos de los números. 

1) Calcular suma
2) Si ambos números son "positivos" y la suma es "negativa", devuelve -1
   Si ambos números son "negativos" y la suma es "positiva", devuelve -1
   
   De lo contrario, devuelve 0
*/


function addOvf(result, a, b)
{  
  // let decimal: Number = 6;
    let resultt = a + b;
    if(a > 0 && b > 0 && result < 0)
        return -1;
    if(a < 0 && b < 0 && result > 0)
        return -1;
    return 0;
}
 
    
    let res = 2147483646; // size of an Integer
    let x = Number.MAX_SAFE_INTEGER;
    let y = Number.MAX_SAFE_INTEGER;
    //let y = 11;
 
    console.log(addOvf(res, x, y));
    //console.log(Number.MAX_SAFE_INTEGER);
        

 
//console.log(Number.MAX_SAFE_INTEGER)    //9007199254740991
//console.log(Number.MIN_SAFE_INTEGER)    //-9007199254740991
 



//////////////////

/*
function addOvf(result, a, b) {
  if (a >= 0 && b >= 0 && a > Number.MAX_SAFE_INTEGER - b) {
    return -1;
  } else if (a < 0 && b < 0 && a < Number.MIN_SAFE_INTEGER - b) {
    return -1;
  } else {
    result[0] = a + b;
    return 0;
  }
}
 
let a = 0, b = 0;
let res = [0];
a = Number.MAX_SAFE_INTEGER;
b = 8192;
 
console.log(addOvf(res, a, b));
*/