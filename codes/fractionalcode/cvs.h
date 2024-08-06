#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

using data_t = std::vector<std::vector<std::string>>;
template <typename T>
using numericdata_t = std::vector<std::vector<T>>
class cvs_generic {
public:
	cvs_generic(std::string _filename);
	void read_header();
	void read_data();
	data_t get_cols_data(std::vector<std::string> cols);
	
private:
	fstream cvsstream;
	data_t data, filtered_data;
	std::map<std::string,int> colmap;
};


class cvs_neware : public cvs_generic {
	cvs_neware(std::string _filename):cvs_generic(_filename){}

	data_t filter(std::string StepType, int StartCycleIndex, int EndCycleIndex);

	template <typename T>
	numericdata_t<T> cols_data_to<T>(std::vector<std::string> cols);
};

