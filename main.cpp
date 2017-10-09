#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char* argv[])
{
  vector<string> history;
  string input;

  cout << "[cmd]: " ;
  getline(cin, input);

  while(input != "exit")
  {
    if(input == "history")
    {
      for( int i=0; i < history.size(); i++/*auto x : history*/ )
      {
        cout << i << ": " << history[i] << endl;
      }
    }
    else
    {
      history.push_back(input);
    }

    if(fork()==0)
    {
      cout << "Running " << input << endl;
      exit(1);
    }

    cout << "[cmd]: " ;
    getline(cin, input);

  }

  return 0;
}
