#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    struct node *prev;
    int id;
    char *song;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;
node *current = NULL;

/* Create and insert a song at the end */
void insert(int id, const char *s) {
    node *t = (node *) malloc(sizeof(node));
    if (!t) {
        printf("Memory allocation failed!\n");
        return;
    }

    t->id = id;
    t->song = strdup(s); // allocate and copy string safely

    if (head == NULL) {
        head = tail = t;
        t->next = t->prev = t; // circular link
        current = t;
    } else {
        t->prev = tail;
        t->next = head;
        tail->next = t;
        head->prev = t;
        tail = t;
    }
}

/* Display all songs in playlist */
void displayPlaylist() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    node *p = head;
    printf("Playlist: ");
    do {
        printf("[%d] %s  ", p->id, p->song);
        p = p->next;
    } while (p != head);
    printf("\n");
}

/* Play next song */
void nextsong() {
    if (current == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    current = current->next;
    printf("Now playing: %s\n", current->song);
}

/* Play previous song */
void prevsong() {
    if (current == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    current = current->prev;
    printf("Now playing: %s\n", current->song);
}

/* Delete a song by id */
void deletesong(int id) {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    node *p = head;

    do {
        if (p->id == id) {
            if (p == head && p == tail) {
                free(p->song);
                free(p);
                head = tail = current = NULL;
                printf("Playlist is now empty.\n");
                return;
            }

            if (p == head)
                head = head->next;
            if (p == tail)
                tail = tail->prev;

            p->prev->next = p->next;
            p->next->prev = p->prev;

            if (current == p)
                current = p->next;

            printf("Deleted song: %s\n", p->song);
            free(p->song);
            free(p);
            return;
        }
        p = p->next;
    } while (p != head);

    printf("Song with id %d not found.\n", id);
}

/* 🌀 Shuffle feature */
void shuffle() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    // Count songs
    int count = 0;
    node *p = head;
    do {
        count++;
        p = p->next;
    } while (p != head);

    if (count == 1) {
        printf("Only one song in playlist: %s\n", current->song);
        return;
    }

    // Random index between 0 and count-1
    srand(time(NULL)); // seed random generator
    int randomIndex = rand() % count;

    // Move pointer to that random song
    p = head;
    for (int i = 0; i < randomIndex; i++)
        p = p->next;

    current = p;
    printf("🎵 Shuffled! Now playing: %s\n", current->song);
}

int main(void) {
    insert(1, "Machayenge 4");
    insert(2, "In Da Club");
    insert(3, "Believer");
    insert(4, "Bones");
    insert(5, "Industry Baby");

    displayPlaylist();

    nextsong();
    nextsong();
    prevsong();

    shuffle();
    shuffle();
    shuffle();

    deletesong(3);
    displayPlaylist();

    shuffle();
}
