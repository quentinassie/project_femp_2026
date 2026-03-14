include <ql/stochasticprocess.hpp>

namespace QuantLib {

    class ConstantBlackScholesProcess : public StochasticProcess1D {

        private:
    		Real S0_;
   		Rate r_;
    		Rate q_;
    		Volatility sigma_;

	public:
    		//Constructeur
		ConstantBlackScholesProcess(
        		Real S0;
        		Rate r;
        		Rate q;
        		Volatility sigma;
    		);

		//Destructeur
		~ConstantBlackScholesProcess();

		//Fonctions appelées par Monte-Carlo
    		Real drift(Time t, Real S) const;
    		
		Real diffusion(Time t, Real S) const;

    		Real evolve(Time t0, Real S0, Time dt, Real dw) const;
    };

}
