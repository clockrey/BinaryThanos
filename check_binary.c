#include <stdio.h>
#include <stdbool.h>
#include <dirent.h> // For directory processing
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h> // For seeding the random number generator

bool is_binary_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb"); // Open the file in binary mode
    if (!file) {
        perror("Failed to open file");
        return false; // Can't determine if binary or not if the file can't be opened
    }

    unsigned char buffer[1024]; // Use a buffer to read chunks of the file
    size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
    while (bytes_read > 0) {
        for (size_t i = 0; i < bytes_read; ++i) {
            if (buffer[i] == '\0' || (buffer[i] < 32 && buffer[i] != '\n' && buffer[i] != '\r' && buffer[i] != '\t')) {
                fclose(file);
                return true;
            }
        }
        bytes_read = fread(buffer, 1, sizeof(buffer), file); // Continue reading the next chunk
    }

    fclose(file); // Always close the file
    return false; // File is not binary
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    srand((unsigned int)time(NULL)); // Seed the random number generator

    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("Failed to open directory");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip '.' and '..' entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[PATH_MAX];
        snprintf(full_path, sizeof(full_path), "%s/%s", argv[1], entry->d_name);

        if (is_binary_file(full_path)) {
            printf("Found binary file: %s\n", full_path);
            if (rand() % 2 == 0) { // 50% chance to proceed with deletion
                printf("Removing binary file: %s\n", full_path);
                if (remove(full_path) != 0) {
                    perror("Failed to remove file");
                }
            } else {
                printf("Keeping binary file: %s\n", full_path);
            }
        }
    }

    closedir(dir);
    return 0;
}
