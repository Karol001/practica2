const int denominaciones[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
int cantidad[10];
String cadenaOriginal;
char opcion;

void setup() {
    Serial.begin(9600);
    mostrarMenu();
}

void loop() {
    if (Serial.available() > 0) {
        opcion = Serial.read();
        Serial.println(opcion);

        switch (opcion) {
            case '1':
                combinacionBilletes();
                break;
            case '2':
                convertirCadena();
                break;
            case '3':
                convertirRomano();
                break;
            case '4':
                numerosAmigables();
                break;
            default:
                Serial.println("Opcion invalida. Intente de nuevo.");
                mostrarMenu();
                break;
        }
    }
}

void mostrarMenu() {
    Serial.println("Menu de opciones:");
    Serial.println("1. Programa para determinar la combinacion de billetes y monedas para una cantidad de dinero.");
    Serial.println("2. Cambiador de letras minusculas a mayusculas.");
    Serial.println("3. Conversor de Numeros Romanos a Arabigos.");
    Serial.println("4. Suma de numeros amigables.");
    Serial.println("Ingrese una opcion: ");
}

void combinacionBilletes() {
    Serial.println("Ingrese la cantidad de dinero:");
    while (Serial.available() == 0) {
    }

    long cantidadDinero = Serial.parseInt();
    if (cantidadDinero > 0) {
        Serial.print("Cantidad ingresada: ");
        Serial.println(cantidadDinero);

        long resto = cantidadDinero;

        for (int i = 0; i < 10; i++) {
            cantidad[i] = resto / denominaciones[i];
            resto %= denominaciones[i];
        }

        Serial.println("Distribucion de billetes y monedas:");
        for (int i = 0; i < 10; i++) {
            Serial.print(denominaciones[i]);
            Serial.print(": ");
            Serial.println(cantidad[i]);
        }

        if (resto > 0) {
            Serial.print("Faltante: ");
            Serial.println(resto);
        } else {
            Serial.println("Faltante: 0");
        }
    } else {
        Serial.println("Por favor, ingrese una cantidad valida.");
    }

    delay(2000);
    mostrarMenu();
}

void convertirCadena() {
    Serial.println("Ingrese una cadena:");

    while (Serial.available() == 0) {
    }

    cadenaOriginal = Serial.readString();
    Serial.print("Original: ");
    Serial.println(cadenaOriginal);

    String cadenaMayuscula = "";
    for (int i = 0; i < cadenaOriginal.length(); i++) {
        char c = cadenaOriginal[i];
        if (c >= 'a' && c <= 'z') {
            cadenaMayuscula += (char)(c - 32);
        } else {
            cadenaMayuscula += c;
        }
    }

    Serial.print("En mayuscula: ");
    Serial.println(cadenaMayuscula);

    delay(2000);
    mostrarMenu();
}

int valorRomano(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

void convertirRomano() {
    Serial.println("Ingrese un numero romano:");
    
    while (Serial.available() == 0) {
    }

    String numeroRomano = Serial.readString();
    int resultado = 0;
    int longitud = numeroRomano.length();

    for (int i = 0; i < longitud; i++) {
        int valorActual = valorRomano(numeroRomano[i]);
        int valorSiguiente = (i + 1 < longitud) ? valorRomano(numeroRomano[i + 1]) : 0;

        if (valorActual < valorSiguiente) {
            resultado -= valorActual;
        } else {
            resultado += valorActual;
        }
    }

    Serial.print("El numero ingresado fue: ");
    Serial.println(numeroRomano);
    Serial.print("Que corresponde a: ");
    Serial.println(resultado);

    delay(2000);
    mostrarMenu();
}

int sumaDivisores(int n) {
    int suma = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            suma += i;
        }
    }
    return suma;
}

void numerosAmigables() {
    Serial.println("Ingrese un numero:");

    while (Serial.available() == 0) {
    }

    int numero = Serial.parseInt();
    int sumaAmigables = 0;

    for (int a = 1; a < numero; a++) {
        int b = sumaDivisores(a);
        if (b > a && sumaDivisores(b) == a) {
            sumaAmigables += a + b;
        }
    }

    Serial.print("El resultado de la suma es: ");
    Serial.println(sumaAmigables);

    delay(2000);
    mostrarMenu();
}
