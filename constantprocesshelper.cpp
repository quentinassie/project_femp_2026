#include "constantprocesshelper.hpp"
#include <ql/termstructures/yield/zerocurve.hpp>

namespace QuantLib {

    
    ext::shared_ptr<ConstantBlackScholesProcess> makeConstantProcess(
        const QuantLib::ext::shared_ptr<QuantLib::GeneralizedBlackScholesProcess>& process,
        QuantLib::Time maturity,
        QuantLib::Real strike
    )


    {
    

        Real S0 = process->x0();

        Rate r = process->riskFreeRate()->zeroRate(maturity, Continuous).rate();

        // dividend might be empty
        Rate q = 0.0;
        if (!process->dividendYield().empty()) {
            q = process->dividendYield()->zeroRate(maturity, Continuous).rate();
        }

        Volatility sigma = process->blackVolatility()->blackVol(maturity, strike);

        return  ext::make_shared<ConstantBlackScholesProcess>(S0, r, q, sigma);
    }
}