#include "usecase.cpp"

using namespace std;

template <typename D, typename K>
void simulate() {
  string fName = "binhex.txt";
  BST<D, K> *bst = create_bst<string, string>(fName);

  string bin;
  cout << "Enter a binary :\n";
  cin >> bin;
  cout << "Hexadecimal of " << bin << " is " << convert(bst, bin) << '\n';

  delete bst;

  BST<D, K> *tree = create_bst<string, string>(fName);
  if (convert(tree,"111010100101") != "EA5") {
    cout << "Wrong convert hexadecimal" <<endl;
  } 
  cout << "Testing complete" <<endl;
}

int main()
{
  
  simulate<string, string>();
  return 0;
}