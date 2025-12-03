#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *FILE_PATH = "input.txt";
unsigned long long sum = 0;

int check_for_invalid_ids(const char *left_str, const char *right_str)
{
    unsigned long long left_int = strtoul(left_str, NULL, 10);
    unsigned long long right_int = strtoul(right_str, NULL, 10);

    printf("low range: %llu\nhigh range: %llu\n", left_int, right_int);

    for (unsigned long long current = left_int; current <= right_int; current++)
    {
        char buffer[64];
        sprintf(buffer, "%llu", current);
        int len = strlen(buffer);

        int is_invalid = 0;

     
        for (int pattern_len = 1; pattern_len <= len / 2; pattern_len++)
        {
           
            if (len % pattern_len != 0)
            {
                continue; 
            }


            char pattern[32];
            strncpy(pattern, buffer, pattern_len);
            pattern[pattern_len] = '\0';

            
            int matches = 1;
            for (int j = pattern_len; j < len; j += pattern_len)
            {
            
                if (strncmp(buffer + j, pattern, pattern_len) != 0)
                {
                    matches = 0;
                    break;
                }
            }

            if (matches)
            {
                is_invalid = 1;
                break; 
            }
        }
    

        if (is_invalid)
        {
            printf("id invalid: %s\n", buffer);
            sum += current;
        }

    }

    return 0;
}

int main()
{
    FILE *file = fopen(FILE_PATH, "r");
    if (file == NULL)
    {
        printf("[Error] Invalid file path");
        return 1;
    }

    char content[4096] = {0};
    if (fgets(content, sizeof(content), file) == NULL)
    {
        printf("[Error] Failed to read file\n");
        fclose(file);
        return 1;
    }

    char *ranges[100] = {0};
    int range_count = 0;

    char *token = strtok(content, ",");
    while (token != NULL && range_count < 10000)
    {
        ranges[range_count++] = token;
        token = strtok(NULL, ",");
    }

    for (int i = 0; i < range_count; i++)
    {

        char range_copy[1024];
        strncpy(range_copy, ranges[i], sizeof(range_copy) - 1);
        range_copy[sizeof(range_copy) - 1] = '\0';

        char *num1 = strtok(range_copy, "-");
        char *num2 = strtok(NULL, "-");

        if (num1 == NULL || num2 == NULL)
        {
            printf("Invalid range format: %s\n", ranges[i]);
            continue;
        }

        check_for_invalid_ids(num1, num2);
    }

    printf("sum: %llu\n", sum);
    fclose(file);
    return 0;
}