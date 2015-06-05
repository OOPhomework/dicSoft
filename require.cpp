#include <iostream>
#include <cstdlib>
using namespace std;

void clear_screen()
{
#ifdef WINDOWS
  std::system ( "CLS" );
#else
  // Assume POSIX
  std::system ( "clear" );
#endif
}