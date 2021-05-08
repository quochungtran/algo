class Solution
{
public:
    string solveEquation(string equation)
    {
        size_t eqpos = equation.find('=');
        string leftExpr = equation.substr(0, eqpos);
        string rightExpr = equation.substr(eqpos + 1);
        int rconst, lconst;
        int rcoeff, lcoeff;

        parse(leftExpr, lconst, lcoeff);
        parse(rightExpr, rconst, rcoeff);
        //printf("Parsed expressions: %dx+%d = %dx+%d\n", lcoeff, lconst, rcoeff, rconst);

        if (lcoeff == rcoeff)
        {
            if (lconst == rconst)
                return "Infinite solutions";
            else
                return "No solution";
        }
        lcoeff -= rcoeff;
        rconst -= lconst;
        rconst /= lcoeff;
        return "x=" + to_string(rconst);
    }

    void parse(string &expr, int &constval, int &coeff)
    {
        int sign = 1;
        int value = 0;
        bool zero = false;
        coeff = constval = 0;

        for (auto c : expr)
        {
            switch (c)
            {
            case '+':
            case '-':
                value *= sign;
                constval += value;
                value = 0;
                sign = (c == '+') ? 1 : -1;
                zero = false;
                break;
            case '0' ... '9':
                value = (value * 10) + (c - '0');
                zero = (c == '0');
                break;
            case 'x':
                value = (value == 0 && !zero) ? 1 : value;
                value *= sign;
                coeff += value;
                value = 0;
                zero = false;
                break;
            default:
                exit(EXIT_FAILURE);
            }
        }
        if (value)
        {
            value *= sign;
            constval += value;
        }
    }
};