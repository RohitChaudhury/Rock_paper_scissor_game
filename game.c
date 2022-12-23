#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long game(char *player, char *comp)
{
    // returns 1 if player wins , -1 if computer wins and 0 fr draw;
    if (*player == *comp)
    {
        return 0;
    }
    else if (*player == 'r' && *comp == 'p')
    {
        return -1;
    }
    else if (*player == 'r' && *comp == 's')
    {
        return 1;
    }
    else if (*player == 'p' && *comp == 'r')
    {
        return 1;
    }
    else if (*player == 'p' && *comp == 's')
    {
        return -1;
    }
    else if (*player == 's' && *comp == 'r')
    {
        return -1;
    }
    else if (*player == 's' && *comp == 'p')
    {
        return 1;
    }
    else
    {
        printf("Ur input is invalid.....please check and play again.\n");
    }
}

int main()
{
    char comp, player;
    int number;
    int p_points = 0, r_points = 0;

    printf("This is a rock, paper & scissors game......the popular game we used to play in our schools:\n---------------------------------------------------\n");
    printf("Here rock means 'r' , paper means 'p' and scissors means 's' ...and the one who scores 5 points first wins the game\n\n");
    for (int i = 0; i < 100; i++)
    {
        srand(time(0));
        number = rand() % 100 + 1;
        if (number < 33 && number > 0)
        {
            comp = 'r';
        }
        else if (number <= 66 && number >= 33)
        {
            comp = 's';
        }
        else if (number > 66)
        {
            comp = 'p';
        }
        printf("Enter 'r' for rock , 'p' for paper and 's' for scissors against bott: ");
        scanf("%c", &player);
        fflush(stdin);
        int result = game(&player, &comp);
        if (result == 0)
        {
            printf("The bott choosed '%c'..\nIts a draw round the round!!\n", comp);
        }
        else if (result == -1)
        {
            printf("The bott choosed '%c'..\nBot win the round!!\n", comp);
            r_points++;
            printf("Bott got one point\n");
        }
        else if (result == 1)
        {
            printf("The bott choosed '%c'..\nYouu win the round!!", comp);
            p_points++;
            printf("Youu got one point\n");
        }
        if (p_points == 5 || r_points == 5)
        {
            break;
        }
    }
    printf("\n\nGame over!!\n\n");
    if (r_points == 5)
    {
        printf("youu scored %d and bott scored %d\n", p_points, r_points);
        printf("Bott won the game\n");
        printf("Better luck next time\n");
    }
    else if (p_points == 5)
    {
        printf("youu scored %d and bott scored %d\n", p_points, r_points);
        printf("Youu won the game\n");
        printf("Hurrahhh!!\n");
    }

    return 0;
}