#ifndef CONSTANT_BLACK_SCHOLES_PROCESS_HPP
#define CONSTANT_BLACK_SCHOLES_PROCESS_HPP

#include <ql/stochasticprocess.hpp>
#include <ql/types.hpp>
#include <ql/termstructures/yield/flatforward.hpp>
#include <ql/termstructures/volatility/equityfx/blackconstantvol.hpp>
#include <ql/time/date.hpp>
#include <ql/quote.hpp>

namespace QuantLib{

	class ConstantBlackScholesProcess : public StochasticProcess1D {

		private:
			Real S0_;
			Rate r_;
			Rate q_;
			Volatility sigma_;

		public:
				//Constructeur
			ConstantBlackScholesProcess(
					Real S0,
					Rate r,
					Rate q,
					Volatility sigma
				);

			//Destructeur
			~ConstantBlackScholesProcess();


			//Fonctions appelées par Monte-Carlo
			Real x0() const override;

			Real drift(Time t, Real S) const override;
				
			Real diffusion(Time t, Real S) const override ;

			Real evolve(Time t0, Real S0, Time dt, Real dw) const override;

			DiscountFactor discount(Time t) const ;
		};
}

#endif
