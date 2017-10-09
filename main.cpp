#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char* argv[])
{
  vector<string> history;
  string input;
  std::chrono::duration<double> time;

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
    else if(input == "ptime")
    {
      cout << "Time spent executing child processes: " << time.count() << " seconds" << endl;
    }
    else
    {
      bool error(false);
      if (input[0] == "^")
      {
        input = input.substr(2);
        int index = stoi(input);
        if(input < history.length())
        {
          input = history[i];
        }
        else
        {
          cout << "Error: Command " << input << " not in history."
          error = true;
        }
      }

      if(!error)
      {

        history.push_back(input);
        
        pid = fork();
        
        if(pid)
        {
          std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
          wait(NULL);
          std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
          
          time += end - start;
          
        }
        else 
        {
          vector<string> newinputs;
          int first=0;
          
          for(int i = 0; i < input.length(); i++)
          {
            if(input[i] == " ")
            {
              if(input[first] != " ")
              {
                vector.push_back(input.substr(first, i-1))
              }
              if(input[i+1] != " ")
              {
                first = i+1;
              }
            }
          }
          
          char ** newargv = new char*[newinputs.length()+1];

          for(int i = 0; i < newinputs.length(); i++)
          {
            newargv[i] = new char[newinputs[i].length+1];
            strcpy(newargv[i], newinputs[i]);
          }
          newargv[newinputs.length()] = NULL; 
          
          execvp(argv[0], argv);
//          cout << "Running " << input << endl;
          
        }
      }
    }
      
    cout << "[cmd]: " ;
    getline(cin, input);

  }

  return 0;
}
