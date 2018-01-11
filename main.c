#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "CRA.h"

int main(int argc, char **argv) {

    if (argc < 4) {
        fprintf(stderr, "Error: too few arguments.");
        usage(argv[0]);
        return -1;
    }

    char  *ptr;
    float acb      = strtof(argv[1], &ptr);
    float proceeds = strtof(argv[2], &ptr);
    int   tax_brkt = atoi(argv[3]);

    float  total_gain, taxable_gain, tax_rate, capital_gains_tax, net_gains;

    if (tax_brkt > 5 || tax_brkt < 1) {
        fprintf(stderr, "Error: You must choose a tax bracket between 1 and 5 inclusive. You entered: %s", argv[3]);
        usage(argv[0]);
        return -1;
    }

    assert(acb);
    assert(proceeds);
    assert(tax_brkt);

    tax_rate          = get_marginal_tax_rate(tax_brkt);
    total_gain        = get_total_gain(proceeds, acb);
    taxable_gain      = get_taxable_gain(total_gain, CAPITAL_GAINS_DIVISOR);
    capital_gains_tax = get_gains_tax(taxable_gain, tax_brkt);
    net_gains         = total_gain - capital_gains_tax;

    printf( "\r\n  CANADIAN CAPITAL GAINS TAX RESULTS\n--------------------------------------------------------\n"
            "Your capital gains tax on the proceeds\t$%.2f\n"
            "Where your gross gains were\t\t$%.2f\n"
            "With a marginal tax rate of\t\t%.1f%%\n"
            "Will be:\t\t\t\t$%.2f\n"
            " = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n"
            "This leaves you with a net gain of:\t$%.2f\n"
            "--------------------------------------------------------\r\n\n"
            , proceeds, total_gain, (tax_rate * 100), capital_gains_tax, net_gains
    );

    return 0;
}
