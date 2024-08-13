#include <string>
#include <armadillo>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

double to_seconds(std::string time){
	    std::istringstream streeam(time);
		std::vector<double> tmp;
		double x{0.0};
        for (std::string l2; std::getline(streeam, l2, ':');){
			tmp.push_back( std::stof(l2) );
		}
		if (tmp.size()==3){
           x = tmp[0]*3600 + tmp[1] * 60 + tmp[2];
		}
		return x;
}

struct mapped_data {
	std::vector<std::vector<std::string>> data;
	std::map<std::string, int> colmap;
	std::vector<std::string> operator() (std::string col_name){
		std::vector<std::string> tmp;
		for (auto x: data){
		    tmp.push_back(x[colmap[col_name]]);
		}
		return tmp;
	}
    std::vector<std::string> operator() (int row ){
		return data[row];
	}
	std::string operator() (int row ,std::string colname){
		return data[row][colmap[colname]];
	}
	std::vector<std::vector<std::string>>& get_data(){
		return data;
	}
	int size(){
		return data.size();
	}

};

using data_t = mapped_data;  
using numericdata_t = std::vector<arma::vec>;
//
struct cvs_generic {
public:
	cvs_generic(std::string _filename){
		cvsfile_stream = std::fstream(_filename);
   		read_data();
	}
	void read_data(){
	// reading header
    std::string header;
    std::getline(cvsfile_stream, header);
    std::istringstream cvsstreeam(header);
	int c = 0;
    for ( std::string l2; std::getline(cvsstreeam, l2, ',');){
            data.colmap[l2] = c;
			c++;
    }
	// reading the rest
	std::string data_line;
	while (std::getline(cvsfile_stream, data_line)){
		   std::istringstream cvsstreeam(data_line);
		   std::vector<std::string> tmp;
		    for ( std::string l2; std::getline(cvsstreeam, l2, ',');){
                tmp.push_back(l2);
     		}
			data.get_data().push_back(tmp);
	}
	//for (auto x: data.colmap){
	//	std::cout << x.first << " " << x.second << "\n";

	//}
	}
protected:
	std::fstream cvsfile_stream;
	data_t data;
};


struct cvsread_neware : public cvs_generic {
	cvsread_neware(std::string _filename):cvs_generic(_filename){}
// here we need Time and Voltage only.
	numericdata_t filter(std::string StepType, int StartCycleIndex, int DataPoints){
        std::vector<std::vector<double>> tmp(2, std::vector<double>());
        int c=0;
		for (int i{0}; i < data.size(); i++){
        	if ( (data(i,"Step Type") == StepType) && (std::stoi(data(i,"Cycle Index")) == StartCycleIndex) && (c <  DataPoints) ){
				
			//	std::cout << c << "\n";
            	tmp[0].push_back( to_seconds(data(i,"Time"))) ;
     			tmp[1].push_back( std::stof (data(i,"Voltage(V)")));
				c++;
	    	}
		}
	    numericdata_t tmp2;
    	//tmp2.push_back({1.0,2.0});
        for (auto x: tmp){
            tmp2.push_back(x);
    	}
		return tmp2;
	}
};

