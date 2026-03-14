#include "constantprocesshelper.hpp"

ConstantBlackScholesProcess makeConstantProcess(
    const QuantLib::ext::shared_ptr<QuantLib::GeneralizedBlackScholesProcess>& process;
    QuantLib::Time maturity;
    QuantLib::Real strike;
)

{
    using namespace QuantLib;

    Real S0 = process->x0();

    Rate r = process->riskFreeRate()->zeroRate(maturity, Continuous);

    Rate q = process->dividendYield()->zeroRate(maturity, Continuous);

    Volatility sigma = process->blackVolatility()->blackVol(maturity, strike);

    return ConstantBlackScholesProcess(S0, r, q, sigma);
}