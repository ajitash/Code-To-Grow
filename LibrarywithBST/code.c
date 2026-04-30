#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE  100
#define MAX_AUTHOR 100
#define MAX_BOOK_CODE   20
#define MAX_GENRE  50

#define SORT_BY_TITLE 1
#define SORT_BY_BOOK_CODE  2

int sort_mode = SORT_BY_TITLE;

typedef struct Book {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char book_code[MAX_BOOK_CODE];
    char genre[MAX_GENRE];
    int  year;
    struct Book* left;
    struct Book* right;
} Book;

Book* root = NULL;

int compare_books(Book* a, Book* b) {
    if (sort_mode == SORT_BY_BOOK_CODE) {
        return strcmp(a->book_code, b->book_code);
    } else {
        char t1[MAX_TITLE], t2[MAX_TITLE];
        int i;
        for (i = 0; a->title[i]; i++) t1[i] = tolower(a->title[i]);
        t1[i] = '\0';
        for (i = 0; b->title[i]; i++) t2[i] = tolower(b->title[i]);
        t2[i] = '\0';
        return strcmp(t1, t2);
    }
}

Book* create_book(char* title, char* author, char* book_code, char* genre, int year) {
    Book* newbook = (Book*)malloc(sizeof(Book));
    if (newbook == NULL) {
        printf("ERROR: ran out of memory!\n");
        return NULL;
    }
    strcpy(newbook->title,  title);
    strcpy(newbook->author, author);
    strcpy(newbook->book_code,   book_code);
    strcpy(newbook->genre,  genre);
    newbook->year  = year;
    newbook->left  = NULL;
    newbook->right = NULL;
    return newbook;
}

Book* insert(Book* node, Book* newbook) {
    if (node == NULL) {
        return newbook;
    }

    int cmp = compare_books(newbook, node);

    if (cmp < 0) {
        node->left = insert(node->left, newbook);
    } else if (cmp > 0) {
        node->right = insert(node->right, newbook);
    } else {
        printf("  [!] A book with that %s already exists. Skipping.\n",
               (sort_mode == SORT_BY_BOOK_CODE) ? "book_code" : "title");
        free(newbook);
    }

    return node;
}

Book* find_min(Book* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

Book* search_by_title(Book* node, char* title) {
    if (node == NULL) return NULL;

    char t1[MAX_TITLE], t2[MAX_TITLE];
    int i;
    for (i = 0; title[i]; i++)      t1[i] = tolower(title[i]);
    t1[i] = '\0';
    for (i = 0; node->title[i]; i++) t2[i] = tolower(node->title[i]);
    t2[i] = '\0';

    int cmp = strcmp(t1, t2);

    if (cmp == 0)      return node;
    else if (cmp < 0)  return search_by_title(node->left,  title);
    else               return search_by_title(node->right, title);
}

Book* search_by_book_code(Book* node, char* book_code) {
    if (node == NULL) return NULL;

    int cmp = strcmp(book_code, node->book_code);

    if (cmp == 0)      return node;
    else if (cmp < 0)  return search_by_book_code(node->left,  book_code);
    else               return search_by_book_code(node->right, book_code);
}

Book* search_book_code_anywhere(Book* node, char* book_code) {
    if (node == NULL) return NULL;
    if (strcmp(node->book_code, book_code) == 0) return node;
    Book* found = search_book_code_anywhere(node->left,  book_code);
    if (found) return found;
    return search_book_code_anywhere(node->right, book_code);
}

Book* search_title_anywhere(Book* node, char* title) {
    if (node == NULL) return NULL;
    char t1[MAX_TITLE], t2[MAX_TITLE];
    int i;
    for (i = 0; title[i]; i++)      t1[i] = tolower(title[i]);
    t1[i] = '\0';
    for (i = 0; node->title[i]; i++) t2[i] = tolower(node->title[i]);
    t2[i] = '\0';
    if (strcmp(t1, t2) == 0) return node;
    Book* found = search_title_anywhere(node->left,  title);
    if (found) return found;
    return search_title_anywhere(node->right, title);
}

Book* delete_book(Book* node, char* title) {
    if (node == NULL) {
        printf("  [!] Book \"%s\" not found.\n", title);
        return NULL;
    }

    char t1[MAX_TITLE], t2[MAX_TITLE];
    int i;
    for (i = 0; title[i]; i++)      t1[i] = tolower(title[i]);
    t1[i] = '\0';
    for (i = 0; node->title[i]; i++) t2[i] = tolower(node->title[i]);
    t2[i] = '\0';

    int cmp = strcmp(t1, t2);

    if (cmp < 0) {
        node->left = delete_book(node->left, title);
    } else if (cmp > 0) {
        node->right = delete_book(node->right, title);
    } else {
        // found the node to delete
        printf("  [ok] Removed: \"%s\"\n", node->title);

        if (node->left == NULL) {
            // only right child (or no children)
            Book* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            // only left child
            Book* temp = node->left;
            free(node);
            return temp;
        } else {
            Book* successor = find_min(node->right);
            strcpy(node->title,  successor->title);
            strcpy(node->author, successor->author);
            strcpy(node->book_code,   successor->book_code);
            strcpy(node->genre,  successor->genre);
            node->year = successor->year;
            node->right = delete_book(node->right, successor->title);
        }
    }
    return node;
}

void print_book(Book* b) {
    printf("  +------------------------------------------+\n");
    printf("  | Title  : %-31s |\n", b->title);
    printf("  | Author : %-31s |\n", b->author);
    printf("  | Book Code : %-31s |\n", b->book_code);
    printf("  | Genre  : %-31s |\n", b->genre);
    printf("  | Year   : %-31d |\n", b->year);
    printf("  +------------------------------------------+\n");
}

int book_count = 0; // reset before calling inorder

void inorder(Book* node) {
    if (node == NULL) return;
    inorder(node->left);
    book_count++;
    printf("\n  [%d]\n", book_count);
    print_book(node);
    inorder(node->right);
}

int count_books(Book* node) {
    if (node == NULL) return 0;
    return 1 + count_books(node->left) + count_books(node->right);
}

int height(Book* node) {
    if (node == NULL) return 0;
    int lh = height(node->left);
    int rh = height(node->right);
    return 1 + (lh > rh ? lh : rh);
}

void find_min_book(Book* node) {
    if (node == NULL) {
        printf("  Library is empty!\n");
        return;
    }
    while (node->left != NULL) node = node->left;
    printf("\n  First book (%s):\n",
           sort_mode == SORT_BY_BOOK_CODE ? "by book_code" : "alphabetically");
    print_book(node);
}

void find_max_book(Book* node) {
    if (node == NULL) {
        printf("  Library is empty!\n");
        return;
    }
    while (node->right != NULL) node = node->right;
    printf("\n  Last book (%s):\n",
           sort_mode == SORT_BY_BOOK_CODE ? "by book_code" : "alphabetically");
    print_book(node);
}

void free_tree(Book* node) {
    if (node == NULL) return;
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

void read_line(char* buf, int maxlen) {
    fgets(buf, maxlen, stdin);
    int len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0'; // remove newline
    }
}

void load_sample_books() {
    // just manually insert a few sample books
    root = insert(root, create_book("The Hobbit",              "J.R.R. Tolkien",     "978-0547928227", "Fantasy",    1937));
    root = insert(root, create_book("1984",                    "George Orwell",       "978-0451524935", "Dystopian",  1949));
    root = insert(root, create_book("Dune",                    "Frank Herbert",       "978-0441013593", "Sci-Fi",     1965));
    root = insert(root, create_book("The Great Gatsby",        "F. Scott Fitzgerald", "978-0743273565", "Classic",    1925));
    root = insert(root, create_book("Atomic Habits",           "James Clear",         "978-0735211292", "Self-Help",  2018));
    root = insert(root, create_book("Harry Potter",            "J.K. Rowling",        "978-0439708180", "Fantasy",    1997));
    root = insert(root, create_book("Clean Code",              "Robert C. Martin",    "978-0132350884", "Tech",       2008));
    printf("  [ok] 7 sample books loaded!\n");
}

void print_banner() {
    printf("\n");
    printf("  ________________________________________\n");
    printf("  |                                       |\n");
    printf("  |      LIBRARY BOOK MANAGER (BST)       |\n");
    printf("  |      Sort: %-10s                 |\n",
           sort_mode == SORT_BY_BOOK_CODE ? "By Book Code" : "By Title");
    printf("  |      Books in library: %-3d            |\n", count_books(root));
    printf("  |      Tree height: %-3d                 |\n", height(root));
    printf("  |                                       |\n");
    printf("  ________________________________________\n");
}

void print_menu() {
    printf("\n");
    printf("  === MENU ===\n");
    printf("  1. Add a book\n");
    printf("  2. Remove a book (by title)\n");
    printf("  3. Search book by title\n");
    printf("  4. Search book by book_code\n");
    printf("  5. Show all books (in-order / alphabetical)\n");
    printf("  6. Show first book (min)\n");
    printf("  7. Show last book  (max)\n");
    printf("  8. Switch sort mode (Title <-> Book Code)\n");
    printf("  9. Load sample books\n");
    printf("  0. Exit\n");
    printf("\n  Your choice: ");
}

int main() {
    int choice;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char isbn[MAX_BOOK_CODE];
    char genre[MAX_GENRE];
    int  year;
    char input[10];

    printf("\n  Welcome to the Library Book Manager!\n");
    printf("  Using BST sorted by TITLE (default)\n");
    printf("  Tip: load sample books first from the menu!\n");

    while (1) {
        print_banner();
        print_menu();

        read_line(input, sizeof(input));
        choice = atoi(input);

        switch (choice) {

            case 1:
                printf("\n  --- Add New Book ---\n");
                printf("  Title  : "); read_line(title, MAX_TITLE);
                printf("  Author : "); read_line(author, MAX_AUTHOR);
                printf("  Book Code: "); read_line(isbn, MAX_BOOK_CODE);
                printf("  Genre  : "); read_line(genre, MAX_GENRE);
                printf("  Year   : ");
                read_line(input, sizeof(input));
                year = atoi(input);

                if (strlen(title) == 0 || strlen(isbn) == 0) {
                    printf("  [!] Title and Book Code cannot be empty!\n");
                } else {
                    Book* nb = create_book(title, author, isbn, genre, year);
                    if (nb != NULL) {
                        root = insert(root, nb);
                        printf("  [ok] Book added successfully!\n");
                    }
                }
                break;

            case 2:
                printf("\n  --- Remove Book ---\n");
                printf("  Enter title to remove: ");
                read_line(title, MAX_TITLE);
                if (strlen(title) == 0) {
                    printf("  [!] Title cannot be empty.\n");
                } else {
                    root = delete_book(root, title);
                }
                break;

            case 3:
                printf("\n  --- Search by Title ---\n");
                printf("  Enter title: ");
                read_line(title, MAX_TITLE);
                {
                    Book* found;
                    if (sort_mode == SORT_BY_TITLE) {
                        found = search_by_title(root, title);
                    } else {
                        // BST sorted by book_code so we do full scan
                        found = search_title_anywhere(root, title);
                    }
                    if (found) {
                        printf("\n  Found!\n");
                        print_book(found);
                    } else {
                        printf("  [!] Book \"%s\" not found.\n", title);
                    }
                }
                break;

            case 4:
                printf("\n  --- Search by Book Code ---\n");
                printf("  Enter Book Code: ");
                read_line(isbn, MAX_BOOK_CODE);
                {
                    Book* found;
                    if (sort_mode == SORT_BY_BOOK_CODE) {
                        found = search_by_book_code(root, isbn);
                    } else {
                        found = search_book_code_anywhere(root, isbn);
                    }
                    if (found) {
                        printf("\n  Found!\n");
                        print_book(found);
                    } else {
                        printf("  [!] Book Code \"%s\" not found.\n", isbn);
                    }
                }
                break;

            case 5:
                if (root == NULL) {
                    printf("\n  Library is empty! Add some books first.\n");
                } else {
                    printf("\n  --- All Books (In-Order Traversal) ---\n");
                    printf("  Sorted by: %s\n",
                           sort_mode == SORT_BY_BOOK_CODE ? "Book Code" : "Title (A-Z)");
                    book_count = 0;
                    inorder(root);
                    printf("\n  Total: %d book(s)\n", book_count);
                }
                break;

            case 6:
                find_min_book(root);
                break;

            case 7:
                find_max_book(root);
                break;

            case 8:
                printf("\n  --- Switch Sort Mode ---\n");
                if (sort_mode == SORT_BY_TITLE) {
                    sort_mode = SORT_BY_BOOK_CODE;
                    printf("  Switched to: Sort by Book Code\n");
                } else {
                    sort_mode = SORT_BY_TITLE;
                    printf("  Switched to: Sort by Title\n");
                }
                printf("  [!] NOTE: Rebuilding tree with new sort order...\n");
                {

                    int total = count_books(root);
                    if (total == 0) break;

                    Book** arr = (Book**)malloc(total * sizeof(Book*));
                    if (arr == NULL) { printf("  ERROR: malloc failed\n"); break; }


                    int idx = 0;

                    Book* stack[500];
                    int top = -1;
                    Book* curr = root;

                    while (curr != NULL || top >= 0) 
                    {
                        while (curr != NULL) 
                        {
                            stack[++top] = curr;
                            curr = curr->left;
                        }
                        curr = stack[top--];
                        arr[idx++] = curr;
                        curr = curr->right;
                    }

                    root = NULL;
                    for (int j = 0; j < idx; j++) 
                    {
                        arr[j]->left  = NULL;
                        arr[j]->right = NULL;
                        root = insert(root, arr[j]);
                    }

                    free(arr);
                    printf("  [ok] Tree rebuilt! %d books re-inserted.\n", total);
                }
                break;

            case 9:
                printf("\n  Loading sample books...\n");
                load_sample_books();
                break;

            case 0:
                printf("\n  Freeing memory...\n");
                free_tree(root);
                root = NULL;
                printf("  Goodbye! Thanks for using Library Manager.\n\n");
                return 0;

            default:
                printf("  [!] Invalid choice. Please enter 0-9.\n");
        }

        printf("\n  Press ENTER to continue...");
        getchar();
    }

    return 0;
}
