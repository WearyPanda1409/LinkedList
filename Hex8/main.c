#include <stdio.h>
#include <stdint.h>

void bits(uint16_t zahl)
{
    for (int i = 15; i >= 0; i--)
    {
        printf("%d", (zahl >> i) & 1);

        if (i == 8)
            printf(" ");
    }
}

int main(void)
{
    uint16_t A = 0;
    uint16_t B = 0;
    unsigned int wahl;
    unsigned int n;
    unsigned int temp;

    while (1)
    {
        printf("\nA Hex: %04X Bits: ", A);
        bits(A);

        printf("\nB Hex: %04X Bits: ", B);
        bits(B);

        printf("\n\n");
        printf("1  A eingeben (Hex)\n");
        printf("2  B eingeben (Hex)\n");
        printf("3  A = A + B\n");
        printf("4  A = A UND B\n");
        printf("5  A = A ODER B\n");
        printf("6  A = A XOR B\n");
        printf("7  A = NICHT A\n");
        printf("8  A nach links schieben\n");
        printf("9  A nach rechts schieben\n");
        printf("10 Ein Bit in A setzen\n");
        printf("11 Ein Bit in A loeschen\n");
        printf("12 Ein Bit in A umschalten\n");
        printf("13 Ein Bit in A pruefen\n");
        printf("0  Ende\n");

        printf("\nDeine Wahl: ");

        if (scanf("%u", &wahl) != 1)
        {
            printf("Falsche Eingabe!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (wahl)
        {
            case 0:
                printf("Programm beendet.\n");
                return 0;

            case 1:
                printf("A in Hex eingeben: ");

                if (scanf("%hx", &A) != 1)
                {
                    printf("Falsche Hexzahl!\n");
                    while (getchar() != '\n');
                }
                break;

            case 2:
                printf("B in Hex eingeben: ");

                if (scanf("%hx", &B) != 1)
                {
                    printf("Falsche Hexzahl!\n");
                    while (getchar() != '\n');
                }
                break;

            case 3:
                A = A + B;
                break;

            case 4:
                A = A & B;
                break;

            case 5:
                A = A | B;
                break;

            case 6:
                A = A ^ B;
                break;

            case 7:
                A = ~A;
                break;

            case 8:
                if (B > 15)
                {
                    printf("B muss zwischen 0 und 15 liegen!\n");
                    break;
                }

                A = A << B;
                break;

            case 9:
                if (B > 15)
                {
                    printf("B muss zwischen 0 und 15 liegen!\n");
                    break;
                }

                A = A >> B;
                break;

            case 10:
            case 11:
            case 12:
            case 13:
                printf("Bitnummer (0 bis 15): ");

                if (scanf("%u", &n) != 1)
                {
                    printf("Falsche Eingabe!\n");
                    while (getchar() != '\n');
                    break;
                }

                if (n > 15)
                {
                    printf("Bitnummer muss zwischen 0 und 15 liegen!\n");
                    break;
                }

                if (wahl == 10)
                {
                    A = A | (1u << n);
                }
                else if (wahl == 11)
                {
                    A = A & ~(1u << n);
                }
                else if (wahl == 12)
                {
                    A = A ^ (1u << n);
                }
                else
                {
                    temp = (A >> n) & 1u;
                    printf("Bit %u ist %u\n", n, temp);
                    break;
                }
                break;

            default:
                printf("Ungueltiger Menuepunkt!\n");
                continue;
        }

        if (wahl >= 3 && wahl <= 12 && wahl != 13)
        {
            printf("\nNeues A Hex: %04X\n", A);
            printf("Neues A Bit: ");
            bits(A);
            printf("\n");
        }
    }

    return 0;
}