#include "phonenumber.h" 
#include <string>

/**
 * @brief This `dummyUnitTestFunction` is used to perform basic unit testing over `display function`
 *
 * Although, I initially started out with using `GTest`(Google Test) for unit testing but due to improper cross platform 
 * issue that might be faced on using external library (other for instance was `CTest`), I decided to create a dummy 
 * function in order to perform basic unit testing, below code simply utilizes the power of template and passes
 * object parameter to the given function and thus run the insert and display function to evaluate if the output
 * by the two functions are same as expected output
 */
template <typename F>
bool dummyUnitTestFunction(map<string, bool> comparators, vector<string> inputs, string pattern, F &f) {
    map<string, bool> elements;
    map<string, bool>::iterator it;
    for(int i = 0; i < inputs.size(); i++){
        f.insert(inputs[i]);
    }
    elements = f.display(pattern);
    // if(elements.size() != comparators.size()) return false;
    for (it=comparators.begin(); it!=comparators.end(); ++it)
        if(!(elements.count(it->first) > 0)) return false;
    return true;
}

string checkOrFail(bool element) {
	if(element){
		return "Passed";
		// cout << "Passed" << endl;
	} else {
		return "Failed";
		// cout << "Failed" << endl;
	}
}

int main(){
	map<string, bool> comp, ele;
	vector<string> inp {"Chris", "Chris Hughes"};
	vector<string> wrng {"Hey"};
	comp["Chris"] = true;
	comp["Chris Hughes"] = true;
	ele["Aalekh"] = true;
	PhoneNumber phn;
	bool res;

	// This should pass the test
	res = dummyUnitTestFunction(comp, inp, "Chris", phn);
	cout << "Test Passes: " << checkOrFail(res) << endl;

	// This shouldn't pass the test
	res = dummyUnitTestFunction(comp, inp, "Byu", phn);
	cout << "Test Passed: " << checkOrFail(res) << endl;
	return 0;
}