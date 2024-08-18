#define OPTIM_ENABLE_ARMA_WRAPPERS
#include "optim/optim.hpp"

inline double booth_fn(const arma::vec& vals_inp, arma::vec* grad_out, void* opt_data)
{
    double x_1 = vals_inp(0);
    double x_2 = vals_inp(1);

    double obj_val = std::pow(x_1 + 2*x_2 - 7.0,2) + std::pow(2*x_1 + x_2 - 5.0,2);

    if (grad_out) {
        (*grad_out)(0) = 10*x_1 + 8*x_2 -  2*(- 7.0) + 4*(x_2 - 5.0);
        (*grad_out)(1) = 2*(x_1 + 2*x_2 - 7.0)*2 + 2*(2*x_1 + x_2 - 5.0);
    }

    return obj_val;
}

int main()
{
    arma::vec x = arma::zeros(2,1); // initial values (0,0)

    bool success_2 = optim::bfgs(x, booth_fn, nullptr);

    if (success_2) {
        std::cout << "bfgs: Booth test completed successfully." << "\n";
    } else {
        std::cout << "bfgs: Booth test completed unsuccessfully." << "\n";
    }

    arma::cout << "bfgs: solution to Booth test:\n" << x << arma::endl;

    return 0;
}

