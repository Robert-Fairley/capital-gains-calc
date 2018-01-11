# Canadian Capital Gains Calculator

This is only a rough estimate of capital gains on a single investment where you can account for your total *Adjusted Cost Base*, *Proceeds*, and your *Marginal Tax Bracket*.

The purpose was to write an exercise in C and provide myself a quick path to a rough estimate of taxes on a given investment. 

---

#### WARNING
**Do not use this as an accurate calculator for filing your taxes.**

---

## Usage

Example:
```shell
$ capital_gains_calc 1000 7000 2
```

Help reference:

```shell
Usage: ./capital_gains_calc <adjusted-cost-base> <total-proceeds> <marginal-tax-bracket (number)>

Arguments
----------
adjusted-cost-base:     Total costs incurred with investment including fees.    (Number. Floating point.)
total-proceeds:         Total amount withdrawn from investments.                (Number. Floating point.)
maginal-tax-bracket:    Your Canadian tax bracket.                              (Number. 1-5)

 Marginal Tax Brackets 2016 (CAD):  
-----------------------------------
1. < $45,282 ................ 15.0%
2. $45,282 - $90,563 ........ 20.5%
3. $90,563 - $140,388 ....... 26.0%
4. $140,388 - $200,000 ...... 29.0%
5. > $200,000 ............... 33.0%
-----------------------------------

```

