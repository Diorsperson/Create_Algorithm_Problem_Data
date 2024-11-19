#include<bits/stdc++.h>
#include<random>
#include<chrono>
using namespace std;
typedef long long ll;
class CreateData {
public:
	template<typename T>
	void Create_input_file(int file_num, vector<T>& input) {
		string file_name = to_string(file_num) + ".in";
		this->fout.open(file_name, ios::out | ios::trunc);
		this->fout << input.size() << '\n';
		for (auto it : input) {
			this->fout << it << " ";
		}
		this->fout.close();
	}
	template<typename InputType, typename OutputType>
	void Create_output_file(int file_num, vector<InputType>& output, OutputType Function) {
		string file_name = to_string(file_num) + ".out";
		this->fout.open(file_name, ios::out | ios::trunc);
		auto res_arr = Function(output);
		for (auto it : res_arr)
			this->fout << it << " ";
		this->fout.close();
	}

public:
	ofstream fout;
};

class My_Random_generator {
public:
	My_Random_generator() {
		this->seed = chrono::system_clock::now().time_since_epoch().count();
		this->generator.seed(seed);
	}
	vector<int> get_random_int_nums(int start, int length, int count) {
		vector<int> random_int_nums;
		uniform_int_distribution<int> distribution(start, start + length);
		for (int i = 0; i < count; i++)
			random_int_nums.push_back(distribution(this->generator));
		return random_int_nums;

	}
public:
	unsigned seed;
	default_random_engine generator;
};

//具体题目的处理函数
void solve(){
	
}

int main() {
	CreateData createdata;
	My_Random_generator random_generator;
	for(int i = 21;i <= 21;i++){
		vector<int> input_origin, real_input;
		//产生数据
		int input_length = 0;
		cin >> input_length;
		for (int i = 1e6; i >= 1e6 - input_length; i--)real_input.push_back(i);


		auto randoms = random_generator.get_random_int_nums(0, input_length - 1, input_length / 2);

		for (int i = 0; i < randoms.size(); i++)
			swap(real_input[i], real_input[randoms[i]]);

		//生成文件
		createdata.Create_input_file(i, real_input);
		createdata.Create_output_file(i, real_input, solve);
	}

	return 0;
}
