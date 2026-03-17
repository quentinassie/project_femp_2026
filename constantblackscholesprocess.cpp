#include "constantblackscholesprocess.hpp"

using namespace QuantLib;

ConstantBlackScholesProcess::ConstantBlackScholesProcess(Real S0, Rate r, Rate q, Volatility sigma){
	S0_ = S0;
	r_ = r;
	q_ = q;
	sigma_ = sigma;
}

ConstantBlackScholesProcess::~ConstantBlackScholesProcess(){
	
}


Real ConstantBlackScholesProcess::x0() const {
	return S0_;
}


//derivée du modele
Real ConstantBlackScholesProcess::drift(Time t, Real S) const { 
	//S est le prix du sous-jacent au temps t

	return (r_ - q_) * S;
}

//partie aléatoire du modèle
Real ConstantBlackScholesProcess::diffusion(Time t, Real S) const {

	return sigma_ * S;
}

Real ConstantBlackScholesProcess::evolve(Time t0, Real X0, Time dt, Real dw) const{
	//X0 est le prix du sous-jacent au temps t0
	//dw est un tirage gaussien

	return X0 * exp((r_- q_ - 0.5 * sigma_* sigma_) * dt + sigma_* sqrt(dt) * dw) ; //resultat SDE BlackSholesModel
}

