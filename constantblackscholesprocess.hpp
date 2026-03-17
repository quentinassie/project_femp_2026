#include <ql/stochasticprocess.hpp>

using namespace QuantLib;

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
    };
