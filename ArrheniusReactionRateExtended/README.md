Пример того как должны быть реакции, для каждой реакции он свой берет, stage нужны для того, что функция от коэф избытка топлива высчитывалась для соответсвующей реакции(1 и 2 этап соответсвенно для 2-этапной модели)

/*
reactions
{
    r1
    {
        type     irreversibleArrheniusExtendedReaction;
        reaction "CH4^0.5 + 1.5O2^0.65 = CO + 2H2O";
        A               1867700000;
        beta     0;
        Ta       17863.3;
        stage    1;
        phi      1;
    }

    r2
    {
        type     reversibleArrheniusExtendedReaction;
        reaction "CO^1 + 0.5O2^0.5 = CO2";
        A               1408000;
        beta     0.7;
        Ta       6038.29;
        stage    2;
        phi      1;
    }


}
*/



