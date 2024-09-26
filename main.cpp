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

    for (int j = 0; j < 3; j++) {
        sumaMagica += matriz[0][j];
    }

    for (int i = 1; i < 3; i++) {
        int sumaFila = 0;
        for (int j = 0; j < 3; j++) {
            sumaFila += matriz[i][j];
        }
        if (sumaFila != sumaMagica) return false;
    }

    for (int j = 0; j < 3; j++) {
        int sumaColumna = 0;
        for (int i = 0; i < 3; i++) {
            sumaColumna += matriz[i][j];
        }
        if (sumaColumna != sumaMagica) return false;
    }

    int sumaDiagonal1 = 0;
    for (int i = 0; i < 3; i++) {
        sumaDiagonal1 += matriz[i][i];
    }
    if (sumaDiagonal1 != sumaMagica) return false;

    int sumaDiagonal2 = 0;
    for (int i = 0; i < 3; i++) {
        sumaDiagonal2 += matriz[i][2 - i];
    }
    if (sumaDiagonal2 != sumaMagica) return false;

    return true;
}

const int FILAS1 = 7;
const int COLUMNAS1 = 8;

bool esEstrella(int matriz[FILAS1][COLUMNAS1], int i, int j) {
    // Condición para verificar si el elemento (i, j) es una estrella
    int suma = matriz[i][j] + matriz[i][j - 1] + matriz[i][j + 1]
               + matriz[i - 1][j] + matriz[i + 1][j];
    return (suma / 5.0) > 6;
}

int contarEstrellas(int matriz[FILAS1][COLUMNAS1]) {
    int cuentaEstrellas = 0;

    // Recorre la matriz sin tocar los bordes
    for (int i = 1; i < FILAS1 - 1; i++) {
        for (int j = 1; j < COLUMNAS1 - 1; j++) {
            if (esEstrella(matriz, i, j)) {
                cuentaEstrellas++;
            }
        }
    }

    return cuentaEstrellas;
}

const int N = 5;

// Función para imprimir una matriz
void imprimirMatriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Función para rotar la matriz 90 grados
void rotar90(int matriz[N][N], int rotada[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotada[j][N - i - 1] = matriz[i][j];
        }
    }
}

// Función para copiar una matriz
void copiarMatriz(int origen[N][N], int destino[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            destino[i][j] = origen[i][j];
        }
    }
}

bool interseccionRectangulos(int A[4], int B[4], int C[4]) {
    // Calculamos las coordenadas de la esquina superior izquierda del rectángulo de intersección
    int x_interseccion = max(A[0], B[0]);
    int y_interseccion = max(A[1], B[1]);

    // Calculamos las coordenadas de la esquina inferior derecha del rectángulo de intersección
    int x_final_interseccion = min(A[0] + A[2], B[0] + B[2]);
    int y_final_interseccion = min(A[1] + A[3], B[1] + B[3]);

    // Verificamos si hay una intersección válida (si las dimensiones son positivas)
    if (x_interseccion < x_final_interseccion && y_interseccion < y_final_interseccion) {
        // Llenamos el arreglo C con los datos de la intersección
        C[0] = x_interseccion;
        C[1] = y_interseccion;
        C[2] = x_final_interseccion - x_interseccion;  // Ancho
        C[3] = y_final_interseccion - y_interseccion;  // Alto
        return true;
    } else {
        // No hay intersección
        return false;
    }
}

// Función para calcular el factorial de un número
unsigned long long factorial(int num) {
    unsigned long long result = 1;
    for (int i = 2; i <= num; i++) {
        result *= i;
    }
    return result;
}

// Función para calcular las combinaciones C(2n, n)
unsigned long long combinaciones(int n) {
    unsigned long long num = factorial(2 * n);  // (2n)!
    unsigned long long denom = factorial(n) * factorial(n);  // (n!) * (n!)
    return num / denom;
}

int sumaDivisores(int n) {
    int suma = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            suma += i;
        }
    }
    return suma;
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
            const int tamaño = 200;
            char letras[tamaño];

            srand(static_cast<unsigned int>(time(nullptr)));
            for (int i=0; i<tamaño; i++){
                letras[i] = 'A' + rand() % 26;
            }

            cout<<"Arreglo de letras ";
            for (int i=0; i<tamaño; i++){
                cout<<letras[i];
            }
            cout<<endl;

            int repeteciones[26]= {0};

            for (int i=0; i<tamaño; i++){
                ++repeteciones[letras[i]-'A'];
            }

            for (int i=0; i<26; i++){
                if (repeteciones[i]>0){
                    cout<<static_cast<char>('A'+i)<<": "<<repeteciones[i]<<endl;
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
                cout << "Es un cuadrado magico." << endl;
            } else {
                cout << "No es un cuadrado magico." << endl;
            }
        }
        break;
        case 13:{
            int matriz[FILAS1][COLUMNAS1] = {
                {0, 3, 4, 0, 0, 0, 6, 8},
                {5, 13, 6, 0, 0, 0, 2, 3},
                {2, 6, 2, 7, 3, 0, 10, 0},
                {0, 0, 4, 15, 4, 1, 6, 0},
                {0, 0, 7, 12, 6, 9, 10, 4},
                {5, 0, 6, 10, 6, 4, 8, 0}
            };

            int estrellas = contarEstrellas(matriz);
            cout << "Numero de estrellas encontradas: " << estrellas << endl;
       }
        break;
        case 14:{
           int matriz[N][N];
           int rotada90[N][N], rotada180[N][N], rotada270[N][N];

           int contador = 1;
           for (int i = 0; i < N; i++) {
               for (int j = 0; j < N; j++) {
                   matriz[i][j] = contador++;
               }
           }

           cout << "Matriz original:" << endl;
           imprimirMatriz(matriz);

           rotar90(matriz, rotada90);
           cout << "Matriz 90 grados:" << endl;
           imprimirMatriz(rotada90);

           rotar90(rotada90, rotada180);
           cout << "Matriz 180 grados:" << endl;
           imprimirMatriz(rotada180);

           rotar90(rotada180, rotada270);
           cout << "Matriz 270 grados:" << endl;
           imprimirMatriz(rotada270);
        }
        break;
        case 15:{
            int A[4] = {0, 0, 8, 4};  // {x, y, ancho, alto}
            int B[4] = {5, 2, 6, 7};  // {x, y, ancho, alto}
            int C[4];

            if (interseccionRectangulos(A, B, C)) {
                cout << "La interseccion de los rectangulos es: {"
                     << C[0] << ", " << C[1] << ", " << C[2] << ", " << C[3] << "}" << endl;
            } else {
                cout << "Los rectangulos no tienen interseccion." << endl;
            }

        }
        break;
        case 16:{
            int n;

            cout << "Ingresa el tamano de la malla (n): ";
            cin >> n;

            unsigned long long caminos = combinaciones(n);

            cout << "Para una malla de " << n << "x" << n << " puntos hay " << caminos << " caminos." << endl;
        }
        break;
        case 17:{
            int limite;

            cout << "Ingresa un número: ";
            cin >> limite;

            int sumaAmigables = 0;

            for (int a = 1; a < limite; a++) {
                int b = sumaDivisores(a);
                if (a != b && b < limite && sumaDivisores(b) == a) {
                    sumaAmigables += a;
                }
            }

            cout << "El resultado de la suma es: " << sumaAmigables << endl;
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
