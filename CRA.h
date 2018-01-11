#ifndef CAPITAL_GAINS_CALC_CRA_H
#define CAPITAL_GAINS_CALC_CRA_H

/* CRA Tax Year */
#define TAX_YEAR                2016

/* CRA Marginal Tax Brackets - 2016 */
/*      Bracket Description     %           Annual Income (CAD)   */
#define MARGINAL_BRACKET_1      0.15F     // $45,282 or less
#define MARGINAL_BRACKET_2      0.205F    // $45,282 to $90,563
#define MARGINAL_BRACKET_3      0.26F     // $90,563 to $140,388
#define MARGINAL_BRACKET_4      0.29F     // $140,388 to $200,000
#define MARGINAL_BRACKET_5      0.33F     // More than $200,000

/* CRA Taxable Capital Gains Divisor - 2016 */
#define CAPITAL_GAINS_DIVISOR   2.0F        // 50% of gains are taxable at the marginal rate

/* Functions */
void  usage                 ( const char *program );
float get_total_gain        ( const float total_proceeds, const float total_cost );
float get_taxable_gain      ( const float total_capital_gains, const float current_gains_divisor);
float get_marginal_tax_rate ( const int tax_rate_option);
float get_gains_tax         ( const float taxable_capital_gains, const int marginal_tax_rate );

#endif //CAPITAL_GAINS_CALC_CRA_H
