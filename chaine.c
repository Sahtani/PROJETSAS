#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction de comparaison pour qsort
int compareStrings(const void *a, const void *b) {
    const char *stringA = (const char *)a;
    const char *stringB = (const char *)b;

    return strcmp(stringA, stringB);
}

int main() {
    const char *strings[] = {"banane", "pomme", "cerise", "abricot", "raisin"};
    int n = sizeof(strings) / sizeof(strings[0]);

    // Utilisez qsort pour trier le tableau de chaînes de caractères en utilisant la fonction de comparaison
    qsort(strings, n, sizeof(strings[0]), compareStrings);

    // Affichez le tableau de chaînes de caractères triées
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
