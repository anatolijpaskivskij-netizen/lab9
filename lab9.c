#include <stdio.h>
#include <string.h>
#include <ctype.h>

int has_double_letters(const char *word);
int count_words(const char *text);

int main() {
    char str[512] = "";
    int choice;
    do {
    printf("\n-- МЕНЮ --\n");
    printf("1. Введіть текст\n");
    printf("2. Видалити слова з подвоєними літерами (а)\n");
    printf("3. Підрахувати кількість слів у тексті (б)\n");
    printf("0. Вийти з програми\n");
    printf("Ваш вибір: ");
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
            printf("Помилка: Спочатку введіть текст у пункті 1.\n");
                } else {
                char temp[512];
                char result[512] = "";
                strcpy(temp, str);
                    
                char *token = strtok(temp, " ,.!?\t");
                while (token != NULL) {
                if (!has_double_letters(token)) {
                strcat(result, token);
                strcat(result, " ");
                }
                token = strtok(NULL, " ,.!?\t");
                }
                printf("Результат без подвоєнь: %s\n", result);
            }
            break;

        case 3:
            if (strlen(str) == 0) {
            printf("Помилка: Текст порожній!\n");
            } else {
            int total_words = count_words(str);
            printf("Кількість слів у тексті: %d\n", total_words);
            }
            break;

        case 0:
            printf("Завершення роботи.\n");
            break;

        default:
            printf("Невірний вибір, спробуйте ще раз.\n");
        }
    } while (choice != 0);

    return 0;
}

int has_double_letters(const char *word) {
    for (int i = 0; word[i] != '\0' && word[i+1] != '\0'; i++) {
        if (tolower(word[i]) == tolower(word[i+1]) && isalpha((unsigned char)word[i])) {
            return 1;
        }
    }
    return 0;
}

int count_words(const char *text) {
    char temp[512];
    int count = 0;
    strcpy(temp, text);
    
    char *token = strtok(temp, " ,.!?\t");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ,.!?\t");
    }
    return count;
}