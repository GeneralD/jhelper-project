#include "../tasks/ARangeSwap.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>

namespace jhelper {

	struct Test {
		std::string input;
		std::string output;
		bool active;
		bool has_output;
	};

	bool check(std::string expected, std::string actual) {
		while(!expected.empty() && isspace(*--expected.end()))
			expected.erase(--expected.end());
		while(!actual.empty() && isspace(*--actual.end()))
			actual.erase(--actual.end());
		return expected == actual;
	}

} // namespace jhelper

signed main() {
	std::vector<jhelper::Test> tests = {
			{"8 1 3 5 7\n1 2 3 4 5 6 7 8\n", "5 6 7 4 1 2 3 8\n", true, true},{"5 2 3 4 5\n2 2 1 1 1\n", "2 1 1 2 1\n", true, true},{"2 1 1 2 2\n50 100\n", "100 50\n", true, true},{"10 2 4 7 9\n22 75 26 45 72 81 47 29 97 2\n", "22 47 29 97 72 81 75 26 45 2\n", true, true},
	};
	bool allOK = true;
	int testID = 0;
	std::cout << std::fixed;
	double maxTime = 0.0;
	std::cout << std::endl;
	for(const jhelper::Test& test: tests ) {
		std::cout << "\033[4m" << "Test #" << ++testID << "\033[m" << std::endl;
		std::cout << "Input: \n" << test.input << std::endl;
		if (test.has_output) {
			std::cout << "Expected output: \n" << test.output << std::endl;
		}
		else {
			std::cout << "Expected output: \n" << "N/A" << std::endl;
		}
		if (test.active) {
			std::stringstream in(test.input);
			std::ostringstream out;
			std::clock_t start = std::clock();
			ARangeSwap solver;
			solver.solve(in, out);
			 std::clock_t finish = std::clock();
			double currentTime = double(finish - start) / CLOCKS_PER_SEC;
			maxTime = std::max(currentTime, maxTime);
			std::cout << "Actual output: \n" << out.str() << std::endl;
			if (test.has_output) {
				bool result = jhelper::check(test.output, out.str());
				allOK = allOK && result;

				if (result) {
					std::cout << "Result: " << "\033[32m OK \033[m" << std::endl;
				}
				else {
					std::cout << "Result: " << "\033[31m WA \033[m" << std::endl;
				}
			}
			std::cout << "Time: " << currentTime << std::endl;
		}
		else {
			std::cout << "SKIPPED\n";
		}


		std::cout << std::endl;

	}
	if(allOK) {
		std::cout << "\033[32m" << "All OK" << "\033[m"<< std::endl;
	}
	else {
		std::cout << "\033[31m" << "Some cases failed" << "\033[m"<< std::endl;
	}
	std::cout << "Maximal time: " << maxTime << "s." << std::endl;
	return 0;
}