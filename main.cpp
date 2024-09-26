#include <iostream>

using namespace std;

bool compararCadenas(const char* cadena1, const char* cadena2) {
    int i = 0;
    while (cadena1[i] != '\0' && cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) {
            return false;
        }
        i++;
    }

    if (cadena1[i] == '\0' && cadena2[i] == '\0') {
        return true;
    }

    return false;
}

int convertirACadenaNumerica(const char* cadena) {
    int numero = 0;
    int i = 0;

    while (cadena[i] != '\0') {
        numero = numero * 10 + (cadena[i] - '0');
        i++;
    }

    return numero;
}

void convertirAEnteroACadena(int numero, char* cadena) {
    int i = 0, j = 0;
    int esNegativo = 0;

    if (numero < 0) {
        esNegativo = 1;
        numero = -numero;
    }

    do {
        cadena[i++] = (numero % 10) + '0';
        numero /= 10;
    } while (numero > 0);

    if (esNegativo) {
        cadena[i++] = '-';
    }

    cadena[i] = '\0';

    int longitud = i;
    for (j = 0; j < longitud / 2; j++) {
        char temp = cadena[j];
        cadena[j] = cadena[longitud - j - 1];
        cadena[longitud - j - 1] = temp;
    }
}

void convertirAMayusculas(char* cadena) {
    int i = 0;
    while (cadena[i] != '\0') {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] = cadena[i] - ('a' - 'A');
        }
        i++;
    }
}

void eliminarRepetidos(char* cadena) {
    char resultado[100];
    int index = 0;

    for (int i = 0; cadena[i] != '\0'; i++) {
        bool repetido = false;

        for (int j = 0; j < index; j++) {
            if (cadena[i] == resultado[j]) {
                repetido = true;
                break;
            }
        }

        if (!repetido) {
            resultado[index++] = cadena[i];
        }
    }

    resultado[index] = '\0';
    for (int i = 0; i <= index; i++) {
        cadena[i] = resultado[i];
    }
}

void separarNumerosYTexto(const char* cadena, char* texto, char* numeros) {
    int indexTexto = 0;
    int indexNumeros = 0;

    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= '0' && cadena[i] <= '9') {
            numeros[indexNumeros++] = cadena[i];
        } else {
            texto[indexTexto++] = cadena[i];
        }
    }

    texto[indexTexto] = '\0';
    numeros[indexNumeros] = '\0';
}

int cadenaAentero(char cadena[]){
    int i=0, n=0;
    while (cadena[i] != '\0'){
        n = 10*n + (cadena[i]- '0' );
        i++;
    }
    return n;
}


int romanoAArabigo(const char* romano) {
    int suma = 0;

    int valores[256] = {0};
    valores['I'] = 1;
    valores['V'] = 5;
    valores['X'] = 10;
    valores['L'] = 50;
    valores['C'] = 100;
    valores['D'] = 500;
    valores['M'] = 1000;

    for (int i = 0; romano[i] != '\0'; i++) {
        if (valores[romano[i]] < valores[romano[i + 1]]) {
            suma -= valores[romano[i]];
        } else {
            suma += valores[romano[i]];
        }
    }

    return suma;
}

const int FILAS = 15;
const int ASIENTOS = 20;

void inicializarSala(char sala[FILAS][ASIENTOS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < ASIENTOS; j++) {
            sala[i][j] = '-';
        }
    }
}

void mostrarSala(char sala[FILAS][ASIENTOS]) {
    cout << "   ";
    for (int i = 1; i <= ASIENTOS; i++) {
        cout << " " << i;
    }
    cout << endl;

    for (int i = 0; i < FILAS; i++) {
        cout << char('A' + i) << " | ";
        for (int j = 0; j < ASIENTOS; j++) {
            cout << sala[i][j] << " | ";
        }
        cout << endl;
    }
}

// Función para reservar un asiento
void reservarAsiento(char sala[FILAS][ASIENTOS], char fila, int numeroAsiento) {
    int filaIndex = fila - 'A';

    if (filaIndex >= 0 && filaIndex < FILAS && numeroAsiento >= 1 && numeroAsiento <= ASIENTOS) {
        if (sala[filaIndex][numeroAsiento - 1] == '-') {
            sala[filaIndex][numeroAsiento - 1] = '+';
            cout << "Asiento " << fila << numeroAsiento << " reservado." << endl;
        } else {
            cout << "Asiento " << fila << numeroAsiento << " ya esta reservado." << endl;
        }
    } else {
        cout << "Fila o numero de asiento no valido." << endl;
    }
}

// Función para cancelar una reserva
void cancelarReserva(char sala[FILAS][ASIENTOS], char fila, int numeroAsiento) {
    int filaIndex = fila - 'A';

    if (filaIndex >= 0 && filaIndex < FILAS && numeroAsiento >= 1 && numeroAsiento <= ASIENTOS) {
        if (sala[filaIndex][numeroAsiento - 1] == '+') {
            sala[filaIndex][numeroAsiento - 1] = '-';
            cout << "Asiento " << fila << numeroAsiento << " cancelado." << endl;
        } else {
            cout << "Asiento " << fila << numeroAsiento << " no esta reservado." << endl;
        }
    } else {
        cout << "Fila o número de asiento no valido." << endl;
    }
}

bool esCuadradoMagico(int matriz[3][3]) {
    int sumaMagica = 0;

    // Calcular la suma de la primera fila como referencia
    for (int j = 0; j < 3; j++) {
        sumaMagica += matriz[0][j];
    }

    // Verificar sumas de filas
    for (int i = 1; i < 3; i++) {
        int sumaFila = 0;
        for (int j = 0; j < 3; j++) {
            sumaFila += matriz[i][j];
        }
        if (sumaFila != sumaMagica) return false;
    }

    // Verificar sumas de columnas
    for (int j = 0; j < 3; j++) {
        int sumaColumna = 0;
        for (int i = 0; i < 3; i++) {
            sumaColumna += matriz[i][j];
        }
        if (sumaColumna != sumaMagica) return false;
    }

    // Verificar la diagonal principal
    int sumaDiagonal1 = 0;
    for (int i = 0; i < 3; i++) {
        sumaDiagonal1 += matriz[i][i];
    }
    if (sumaDiagonal1 != sumaMagica) return false;

    // Verificar la diagonal secundaria
    int sumaDiagonal2 = 0;
    for (int i = 0; i < 3; i++) {
        sumaDiagonal2 += matriz[i][2 - i];
    }
    if (sumaDiagonal2 != sumaMagica) return false;

    return true;
}

int main() {
    int opcion;

    do {
        cout << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Programa para determinar la combinacion de billetes y monedas para una cantidad de dinero." << endl;
        cout << "2. Ingresar un arreglo de letras y contar su frecuencia." << endl;
        cout << "3. Comparar 2 cadenas." << endl;
        cout << "4. Funcion para Convertir una Cadena Numerica a Entero." << endl;
        cout << "5. Conversion de Entero a Cadena con Referencias." << endl;
        cout << "6. Cambiador de letras minusculas a mayusculas." << endl;
        cout << "7. Eliminador de caracteres repetidos." << endl;
        cout << "8. Separador de numeros y caracteres." << endl;
        cout << "9. Suma de Numeros de N Cifras." << endl;
        cout << "10. Conversor de Numeros Romanos a Arabigos." << endl;
        cout << "11. Reservas de Asientos de Cine." << endl;
        cout << "12. Verificador de Cuadrados Magicos." << endl;
        cout << "13. Análisis de matriz de Galaxias." << endl;
        cout << "14. Rotaciones de matriz." << endl;
        cout << "15. Interseccion de Rectangulos." << endl;
        cout << "16. Caminos en una malla." << endl;
        cout << "17. Suma de numeros amigables." << endl;
        cout << "18. Permutaciones lexicograficas." << endl;

        cout << "19. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        cin.ignore();

        switch(opcion) {
        case 1: {
            int denominaciones[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
            int cantidad[10];

            int cantidadDinero;

            cout << "Ingrese la cantidad de dinero: ";
            cin >> cantidadDinero;

            int resto = cantidadDinero;

            for (int i = 0; i < 10; i++) {
                cantidad[i] = resto / denominaciones[i];
                resto %= denominaciones[i];
            }

            for (int i = 0; i < 10; i++) {
                cout << denominaciones[i] << ": " << cantidad[i] << endl;
            }

            if (resto > 0) {
                cout << "Faltante: " << resto << endl;
            } else {
                cout << "Faltante: 0" << endl;
            }
        }
        break;
        case 2: {
            const int TAMANIO = 200;
            char letras[TAMANIO];
            int contador[26] = {0}; // Arreglo para contar la cantidad de cada letra

            int seed = 12345;

            auto rand_num = [&seed]() {
                seed = (seed * 1103515245 + 12345) & 0x7FFFFFFF; // Generador de números pseudoaleatorios simple
                return (seed % 26);
            };

            for (int i = 0; i < TAMANIO; i++) {
                letras[i] = 'A' + rand_num(); // Genera una letra aleatoria entre 'A' y 'Z'
                contador[letras[i] - 'A']++;  // Incrementa el contador de la letra correspondiente
            }

            // Imprimir el arreglo de letras
            for (int i = 0; i < TAMANIO; i++) {
                cout << letras[i];
            }
            cout << endl;

            // Imprimir la cantidad de repeticiones de cada letra
            for (int i = 0; i < 26; i++) {
                if (contador[i] > 0) {
                    cout << char('A' + i) << ": " << contador[i] << endl;
                }
            }
        }
        break;
        case 3:{
            char cadena1[100], cadena2[100];

            cout << "Ingrese la primera cadena: ";
            cin.getline(cadena1, 100);

            cout << "Ingrese la segunda cadena: ";
            cin.getline(cadena2, 100);

            if (compararCadenas(cadena1, cadena2)) {
                cout << "Las cadenas son iguales." << endl;
            } else {
                cout << "Las cadenas son diferentes." << endl;
            }
        }
        break;
        case 4:{
            char cadena[100];

            cout << "Ingrese una cadena de caracteres numericos: ";
            cin.getline(cadena, 100);

            int numeroConvertido = convertirACadenaNumerica(cadena);
            cout << "El numero convertido es: " << numeroConvertido << endl;
        }
        break;
        case 5:{
            int numero;
            char cadena[100];

            cout << "Ingrese un numero entero: ";
            cin >> numero;

            convertirAEnteroACadena(numero, cadena);

            cout << "El numero convertido a cadena es: " << cadena << endl;
        }
        break;
        case 6:{
            char cadena[100];

            cout << "Ingrese una cadena: ";
            cin.getline(cadena, 100);

            cout << "Original: " << cadena << endl;

            convertirAMayusculas(cadena);

            cout << "En mayuscula: " << cadena << endl;

        }
        break;
        case 7:{
            char cadena[100];

            cout << "Ingrese una cadena: ";
            cin.getline(cadena, 100);

            cout << "Original: " << cadena << endl;

            eliminarRepetidos(cadena);

            cout << "Sin repetidos: " << cadena << endl;

        }
        break;
        case 8:{
            char cadena[100];
            char texto[100];
            char numeros[100];

            cout << "Ingrese una cadena: ";
            cin.getline(cadena, 100);

            cout << "Original: " << cadena << endl;

            separarNumerosYTexto(cadena, texto, numeros);

            cout << "Texto: " << texto << ". Numero: " << numeros << "." << endl;
        }
        break;
        case 9:{
            {
                int n;
                cout<<"ingrese un numero n: ";
                cin>>n;

                char cadena[100];
                cout<<"ingrese una cadena de caracteres numericos: ";
                cin>>cadena;

                cout<<"Original: "<<cadena<<endl;

                int cadena_longitud = 0;
                while (cadena[cadena_longitud] != '\0'){
                    cadena_longitud++;
                }

                while (cadena_longitud % n != 0 ){
                    for (int i = cadena_longitud; i>0; i--){
                        cadena[i]= cadena[i-1];
                    }
                    cadena[0] = '0';
                    cadena_longitud++;
                }

                int suma = 0;
                cout<<"Suma: ";
                for (int i=0; i<cadena_longitud; i += n ){
                    char subcadena [10];
                    for (int j = 0; j<n; j++){
                        subcadena[j] = cadena[i + j];
                    }
                    int numero = cadenaAentero(subcadena);
                    suma += numero;
                    if (numero == 0 && i>0 ){
                        cout<<"0";
                    }
                    else
                        cout<<numero;
                    if (i<cadena_longitud - n)
                        cout<<"+";
                }
                cout<<" = "<<suma<<endl;
            }

        }
        break;
        case 10:{
            char romano[100];
            cout << "Ingrese un numero en romano: ";
            cin >> romano;

            int resultado = romanoAArabigo(romano);

            cout << "El numero ingresado fue: " << romano << " Que corresponde a: " << resultado << "." << endl;
        }
        break;
        case 11:{
            char sala[FILAS][ASIENTOS];
            inicializarSala(sala); // Inicializamos la sala

            int opcion;
            char fila;
            int numeroAsiento;

            while (true) {
                cout << "\nMenu:" << endl;
                cout << "1. Mostrar sala" << endl;
                cout << "2. Reservar asiento" << endl;
                cout << "3. Cancelar reserva" << endl;
                cout << "4. Salir" << endl;

                cout << "Elige una opcion: ";
                cin >> opcion;

                switch (opcion) {
                case 1:
                    mostrarSala(sala);
                    break;
                case 2:
                    cout << "Ingresa la fila (A-O): ";
                    cin >> fila;
                    cout << "Ingresa el numero de asiento (1-20): ";
                    cin >> numeroAsiento;
                    reservarAsiento(sala, fila, numeroAsiento);
                    break;
                case 3:
                    cout << "Ingresa la fila (A-O): ";
                    cin >> fila;
                    cout << "Ingresa el numero de asiento (1-20): ";
                    cin >> numeroAsiento;
                    cancelarReserva(sala, fila, numeroAsiento);
                    break;
                case 4:
                    cout << "Saliendo del programa." << endl;
                    return 0;
                default:
                    cout << "Opción no valida. Por favor intenta de nuevo." << endl;
                    break;
                }
            }

        }
        break;
        case 12:{
            int matriz[3][3];

            cout << "Ingresa los valores de la matriz 3x3:" << endl;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cin >> matriz[i][j];
                }
            }

            cout << "La matriz ingresada es:" << endl;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << matriz[i][j] << " ";
                }
                cout << endl;
            }

            if (esCuadradoMagico(matriz)) {
                cout << "Es un cuadrado mágico." << endl;
            } else {
                cout << "No es un cuadrado mágico." << endl;
            }
        }
        break;
        case 13:{

        }
        break;
        case 14:{

        }
        break;
        case 15:{

        }
        break;
        case 16:{

        }
        break;
        case 17:{

        }
        break;
        case 18:{

        }
        break;
        case 19:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
        }
    } while(opcion != 19);

    return 0;
}
