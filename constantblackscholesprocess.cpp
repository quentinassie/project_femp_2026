#include "constantblackscholesprocess.hpp"

using namespace QuantLib;

constantblackscholesprocess::ConstantBlackScholesProcess(Real S0, Rate r, Rate q, Volatility sigma){
	S0_ = S0;
	r_ = r;
	q_ = q;
	sigma_ = sigma;
}

constantblackscholesprocess::~ConstantBlackScholesProcess(){
	
}

Real drift(Time t, Real S) const{
	//S est le prix du sous-jacent au temps t

	return (r_ - q_) * S;
}

Real diffusion(Time t, Real S) const{
	//S est le prix du sous-jacent au temps t

	return sigma_ * S;
}

Real evolve(Time t0, Real S0, Time dt, Real dw) const{
	//S est le prix du sous-jacent au temps t0
	//dw est un tirage gaussien

	return S0 * exp((r_- q_ - 0.5*sigma_*sigma_)*dt + sigma_*sqrt(dt)*dw); 
}

 "constantblackscholesprocess.hpp"
