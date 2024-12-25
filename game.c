#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ASCII Art for choices
const char *rock = 
    "    _______\n"
    "---'   ____)\n"
    "      (_____)\n"
    "      (_____)\n"
    "      (____)\n"
    "---.__(___)\n";

const char *paper = 
    "    _______\n"
    "---'   ____)____\n"
    "          ______)\n"
    "          _______)\n"
    "         _______)\n"
    "---.__________)\n";

const char *scissors = 
    "    _______\n"
    "---'   ____)____\n"
    "          ______)\n"
    "       __________)\n"
    "      (____)\n"
    "---.__(___)\n";

// Function to display the rules
void print_rules() {
    printf("************ RULES *************\n");
    printf("1) You choose, and the computer chooses.\n");
    printf("2) Rock smashes Scissors -> Rock wins.\n");
    printf("3) Scissors cut Paper -> Scissors win.\n");
    printf("4) Paper covers Rock -> Paper wins.\n");
}

// Function to display the choice
void display_choice(const char *choice_name, const char *art) {
    printf("%s:\n%s\n", choice_name, art);
}

int main() {
    // Choices array
    const char *choices[] = {"rock", "paper", "scissors"};
    const char *arts[] = {rock, paper, scissors};

    char user_choice[10];
    int computer_choice;

    printf("Welcome to the Rock, Paper, Scissors game!\n");
    printf("Press Enter to continue or type 'help' for the rules: ");

    char intro[10];
    fgets(intro, sizeof(intro), stdin);
    intro[strcspn(intro, "\n")] = '\0'; // Remove trailing newline

    if (strcmp(intro, "help") == 0) {
        print_rules();
    }

    printf("Enter your choice (rock, paper, scissors): ");
    fgets(user_choice, sizeof(user_choice), stdin);
    user_choice[strcspn(user_choice, "\n")] = '\0'; // Remove trailing newline

    // Generate computer choice
    srand(time(0));
    computer_choice = rand() % 3; // Random number between 0 and 2

    printf("You chose:\n");
    if (strcmp(user_choice, "rock") == 0) {
        display_choice("Rock", rock);
    } else if (strcmp(user_choice, "paper") == 0) {
        display_choice("Paper", paper);
    } else if (strcmp(user_choice, "scissors") == 0) {
        display_choice("Scissors", scissors);
    } else {
        printf("Invalid choice! Please enter rock, paper, or scissors.\n");
        return 1; // Exit the program
    }

    printf("Computer chose:\n");
    display_choice(choices[computer_choice], arts[computer_choice]);

    // Determine the winner
    if (strcmp(user_choice, choices[computer_choice]) == 0) {
        printf("It's a tie!\n");
    } else if ((strcmp(user_choice, "rock") == 0 && strcmp(choices[computer_choice], "scissors") == 0) ||
               (strcmp(user_choice, "scissors") == 0 && strcmp(choices[computer_choice], "paper") == 0) ||
               (strcmp(user_choice, "paper") == 0 && strcmp(choices[computer_choice], "rock") == 0)) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }

    return 0;
}


