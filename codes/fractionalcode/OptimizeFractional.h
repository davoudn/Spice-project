


struct opt{
    //
  //  static Faradic _Faradic;
  //  static Ohmic   _Ohmic;
    //
    static void init(std::string _file, std::string StepType, int CycleIndex, int DataPoints, int _NSubsteps){
          opt_data = new FitData(  _file,   StepType,   CycleIndex,   DataPoints,   _NSubsteps);
    }
    //
 static double ObjectiveFunc(const arma::vec& p, arma::vec* grad_out, void* _data) {
     double _A = p[0], _B = p[1], _C = p[2], _Alpha = p[3]; // faradic params
     double _R = p[4];

     Faradic _Faradic(_A, _B, _C, _Alpha, opt_data->H, opt_data->NSteps, opt_data->V0, std::string("Faradic"));
     Ohmic   _Ohmic  (_R, _C    , _Alpha, opt_data->H, opt_data->NSteps, opt_data->V0, std::string("Ohmic"));
     //std::cout << opt_data->V0 << " " << opt_data->NSteps << " " << opt_data->H << "\n" ;
     //Ohmic ohmic(1.0,1.0,0.5, 0.01, 1000, opt_data->V0);

     _Faradic.Solve();
     _Ohmic.Solve();

     auto _FaradicResult = _Faradic.GetResults(opt_data->NSubsteps);
     auto _OhmicResult   =   _Ohmic.GetResults(opt_data->NSubsteps);

     for (int i{0}; i< _FaradicResult->n_rows; i++){
        std::cout << (*_FaradicResult)(i) << " " <<  (*_OhmicResult)(i) << " " << opt_data->V(i) << "\n";
     }
     auto tmp = *_FaradicResult - opt_data->V;
     double obj_val = arma::norm(tmp);
     //
     return obj_val;
}

static int Optimmize(){
        // initial values:
    arma::vec x = arma::ones(6,1);
    //
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    bool success = optim::bfgs(x, ObjectiveFunc,nullptr);

    std::chrono::time_point<std::chrono::system_clock> end   = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;

    if (success) {
        std::cout << "de: ObjectiveFunc test completed successfully.\n"
                << "elapsed time: " << elapsed_seconds.count() << "s\n";
    } else {
        std::cout << "de: ObjectiveFunc test completed unsuccessfully." << std::endl;
    }

    arma::cout << "\nde: solution to ObjectiveFunc test:\n" << x << arma::endl;

    return 0;
 }
};
