#include <stdio.h>
#include <string.h>
#include <ctype.h>

int has_double_letters(const char *word);

int main() {
    char str[512] = "";
    int choice;
    do{
    printf("\n--МЕНЮ--\n");
    printf("1.Введіть текст\n");
    printf("2.Видалити слова з подвоєними літерами\n");
    printf("3.Підраховує кількість слів у тексті\n");
    printf("0.Вийти з програми\n");
    printf("Вваш вибір:");
    if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

    while (getchar() != '\n');

    switch (choice) {
    case 1:
        printf("Введіть текст: ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';
        printf("Рядок збережено.\n");
        break;

    case 2:
        if (strlen(str) == 0) {
        printf("Помилка: Спочатку введіть текст у (пункті 1).\n");
            } else {
            char temp[512];
            char result[512] = "";
            strcpy(temp, str);
                    
            printf("Результат: ");
            char *token = strtok(temp, " ,.!?\t");
            while (token != NULL) {
                if (!has_double_letters(token)) {
                    strcat(result, token);
                    strcat(result, " ");
                }
                token = strtok(NULL, " ,.!?\t");
            }
            printf("%s\n", result);
        }
        break;

    case 3:
        if (strlen(str) == 0) {
            printf("Помилка: Текст порожній!\n");
            } else {
            char temp[512];
            int count = 0;
            strcpy(temp, str);
                    
            char *token = strtok(temp, " ,.!?\t");
            while (token != NULL) {
                count++;
                token = strtok(NULL, " ,.!?\t");
            }
            printf("Кількість слів у тексті: %d\n", count);
        }
        break;

    case 0:
        printf("Завершення роботи\n");
        break;

    default:
        printf("Невірний вибір, спробуйте ще раз.\n");
        }
    } while (choice != 0);

    return 0;
}
int has_double_letters(const char *word) {
    for (int i = 0; word[i] != '\0' && word[i+1] != '\0'; i++) {
        if (tolower(word[i]) == tolower(word[i+1]) && isalpha(word[i])) {
            return 1;
        }
    }
    return 0;
}