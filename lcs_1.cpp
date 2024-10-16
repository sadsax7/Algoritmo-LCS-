#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Para usar transform y tolower

using namespace std;

int LCS(string A, string B) {
    int m = A.length();
    int n = B.length();

    // Crear una tabla dp de tamaño (m+1) x (n+1) con todos ceros
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Llenar la tabla usando programación dinámica
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                int arriba = dp[i - 1][j];
                int izquierda = dp[i][j - 1];

                if (arriba >= izquierda)
                {
                    dp[i][j] = arriba;
                } else {
                    dp[i][j] = izquierda;
                }                
            }
        }
    }
    

    // imprimir la tabla dp[m+1][n1]
    cout << "Tabla DP:" << endl << endl;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // La longitud de la LCS esta en dp[m][n]
    cout << "dp[m][n]: " << dp[m][n] << " ---> subsecuencia mas larga entre: " << endl << A << " y " << B << endl;


    // Encontrar cual es la cadena mas larga BACKTRACKING
    int i = m; 
    int j = n;
    string lcs = "";

    while (i > 0 && j > 0)
    {
        if (A[i - 1] == B[j - 1])
        {
            lcs = A[i - 1] + lcs;
            i --;
            j --;
        } else if (dp[i - 1][j] >= dp[i][j - 1])
        {
            i --;
        } else {
            j--;
        }
    }
    
    cout << "SubCadena mas larga entre " << A << " y " << B << ": " << lcs << endl; 

    return 0;
}

int main() {
    // Definir variables para las dos cadenas
    string str1, str2;

    // Solicitar al usuario que ingrese las dos cadenas
    cout << "Ingresa la primera cadena: " << endl;
    cin >> str1;  // Leer la primera cadena
    cout << "Ingresa la segunda cadena: " << endl;
    cin >> str2;  // Leer la segunda cadena

    // Convertir ambas cadenas a minúsculas
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    cout << "cadena 1:" << str1 << endl;
    cout << "cadena 2:" << str1 << endl;

    
    // Llamar a la función LCS para obtener la longitud de la subsecuencia común más larga
    int sub_cadena = LCS(str1, str2);

    return 0;
}
