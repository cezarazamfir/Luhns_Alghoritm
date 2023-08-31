#include <cs50.h>
#include <stdio.h>

void get_company(long credit);

int main(void)
{
    long credit_number = get_long("Input your credit card number: ");
    get_company(credit_number);
}

void get_company(long credit)
{
    long credit_number_copy = credit;
    bool de_inmultit = 0;
    int sum1 = 0;
    int sum2 = 0;

    while (credit > 0)
    {
        if (de_inmultit == 0)
        {
            sum1 += credit % 10;
            credit = credit / 10;
            de_inmultit = 1;
        }
        else
        {
            if (2 * (credit % 10) < 10)
            {
                sum2 += 2 * (credit % 10);
            }
            else
            {
                sum2 += (2 * (credit % 10)) % 10 + 2 * (credit % 10) / 10;
            }
            credit = credit / 10;
            de_inmultit = 0;
        }
    }

    int sum = sum1 + sum2;
    int counter = 2;

    if (sum % 10 == 0)
    {
        while (credit_number_copy > 100)
        {
            credit_number_copy = credit_number_copy / 10;
            counter ++;
        }

        if ((credit_number_copy >= 51 && credit_number_copy <=55) && counter == 16) printf("MASTERCARD\n");
        else if (credit_number_copy/10 == 4 && (counter == 13 || counter == 16)) printf("VISA\n");
        else if ((credit_number_copy == 34 || credit_number_copy == 37) && counter == 15) printf("AMEX\n");
        else printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
