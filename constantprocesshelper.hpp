#ifndef CONSTANT_PROCESS_HELPER_HPP
#define CONSTANT_PROCESS_HELPER_HPP

#include <ql/stochasticprocess.hpp>
#include <ql/processes/blackscholesprocess.hpp>
#include "constantblackscholesprocess.hpp"

//Cette utilitaire sert à extraire S0, r, q, et σ pour chacun des trois moteurs Monte-Carlo (European, Asian, Lookback) sans duplication

ConstantBlackScholesProcess makeConstantProcess(
    const QuantLib::ext::shared_ptr<QuantLib::BlackScholesProcess>& process,
    QuantLib::Time maturity,
    QuantLib::Real strike
    
);

#endif