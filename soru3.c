#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(TrieNode* root, const char* key) {
    TrieNode* curr = root;
    while (*key) {
        int index = *key - 'a';
        if (!curr->children[index])
            curr->children[index] = createNode();
        curr = curr->children[index];
        key++;
    }
    curr->isEndOfWord = 1;
}

int search(TrieNode* root, const char* key) {
    TrieNode* curr = root;
    while (*key) {
        int index = *key - 'a';
        if (!curr->children[index])
            return 0;
        curr = curr->children[index];
        key++;
    }
    return curr != NULL && curr->isEndOfWord;
}

int main() {
    TrieNode* root = createNode();
    insert(root, "elma");
    insert(root, "ev");
    insert(root, "okul");

    printf("Arama sonucu (ev): %s\n", search(root, "ev") ? "Bulundu" : "Bulunamadı");
    printf("Arama sonucu (araba): %s\n", search(root, "araba") ? "Bulundu" : "Bulunamadı");

    return 0;
}
