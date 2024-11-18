#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class CreateData {
public:
	template<typename T>
	void Create_input_file(int file_num, vector<T>& input) {
		string file_name = to_string(file_num) + ".in";
		this->fout.open(file_name, ios::out | ios::trunc);
		for (auto it : input) {
			this->fout << it << " ";
		}
		this->fout.close();
	}
	template<typename InputType,typename OutputType>
	void Create_output_file(int file_num, vector<InputType>& output,OutputType Function) {
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

void solve(){

}

int main() {
	CreateData createdata;
	vector<int> input;
    //产生数据
	for (int i = 1e5; i >= 1; i--)input.push_back(i);

    //生成文件
	createdata.Create_input_file(21, input);
	createdata.Create_output_file(21, input, solve);

	return 0;
}
