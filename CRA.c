#include <stdio.h>
#include <assert.h>
#include "CRA.h"

/**
 * usage:
 * @param program_name:     The name of the application running.
 *
 * Prints usage and help information for using the calculator. Lists the options available for
 * marginal tax rates of the associated year and their keys for use in the command line operation.
 *
 * @todo Convert listed income data into constants defined in header file so they can be universally adjusted for the
 * tax year when necessary.
 *
 */
void usage (const char *program_name)
{
    assert(program_name);

    printf("\r\nUsage: %s <adjusted-cost-base> <total-proceeds> <marginal-tax-bracket (number)>\n\n", program_name);

    printf("");

    printf("Arguments\n----------\n");
    printf("adjusted-cost-base:\tTotal costs incurred with investment including fees.\t(Number. Floating point.)\n");
    printf("total-proceeds:\t\tTotal amount withdrawn from investments.\t\t(Number. Floating point.)\n");
    printf("maginal-tax-bracket:\tYour Canadian tax bracket.\t\t\t\t(Number. 1-5)\n\n");

    printf(
            " Marginal Tax Brackets %i (CAD):  \n"
            "-----------------------------------\n"
            "1. < $45,282 ................ 15.0%%\n"
            "2. $45,282 - $90,563 ........ 20.5%%\n"
            "3. $90,563 - $140,388 ....... 26.0%%\n"
            "4. $140,388 - $200,000 ...... 29.0%%\n"
            "5. > $200,000 ............... 33.0%%\n"
            "-----------------------------------\r\n", TAX_YEAR
    );
}


/**
 * get_total_gain:
 * @param total_proceeds:        The total amount of money being withdrawn/realized
 * @param total_cost:            The total costs incurred in original purchase + fees/other
 * @return:                      The total amount of gains incurred.
 *
 * Calculates the total amount gained from the investment and withdrawal transaction.
 *
 */
float get_total_gain (const float total_proceeds, const float total_cost)
{
    float total_gain;

    assert(total_proceeds);
    assert(total_cost);

    total_gain = total_proceeds - total_cost;

    return total_gain;
}

/**
 * get_taxable_gain:
 * @param total_capital_gains:      The total amount of capital gains realized
 * @return:                         The total amount of taxable capital gains.
 *
 * Divides the total capital gains by the year's capital gains divisor and
 * returns the result.
 *
 */
float get_taxable_gain (const float total_capital_gains, const float current_gains_divisor)
{
    float taxable_gain;
    assert(total_capital_gains);

    taxable_gain = total_capital_gains / current_gains_divisor;

    return taxable_gain;
}

/**
 *
 * @param tax_rate_option
 * @return
 */
float get_marginal_tax_rate (const int tax_rate_option)
{
    float tax_rate;
    assert(tax_rate_option);

    switch(tax_rate_option) {
        case 1:
            tax_rate = MARGINAL_BRACKET_1;
            break;
        case 2:
            tax_rate = MARGINAL_BRACKET_2;
            break;
        case 3:
            tax_rate = MARGINAL_BRACKET_3;
            break;
        case 4:
            tax_rate = MARGINAL_BRACKET_4;
            break;
        case 5:
            tax_rate = MARGINAL_BRACKET_5;
            break;
        default:
            fprintf(stderr, "Error: invalid tax bracket selected.");
            return -1;
    }

    return tax_rate;
}

/**
 *
 * @param taxable_capital_gains
 * @param marginal_tax_rate
 * @return
 */
float get_gains_tax (const float taxable_capital_gains, const int marginal_tax_rate)
{
    float gains_tax, tax_rate;

    assert(taxable_capital_gains);
    assert(marginal_tax_rate);

    tax_rate = get_marginal_tax_rate(marginal_tax_rate);

    gains_tax = taxable_capital_gains * tax_rate;

    return gains_tax;
}