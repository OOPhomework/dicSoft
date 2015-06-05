#include <ctime>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
using namespace std;

int main() {
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << endl;

    srand(time(NULL));
    cout <<RAND_MAX<<endl;
    cout <<static_cast<int>(RAND_MAX)<<endl;
    for (int i = 0;i < 10;i++)
    {
        cout <<rand()<<endl;
        int _rand;
        _rand = rand() % 10 + 1;
    }

      int iSecret, iGuess;

  /* initialize random seed: */
  srand (time(NULL));

  /* generate secret number between 1 and 10: */
  iSecret = rand() % 10 + 1;

  do {
    //cout <<iSecret<<endl;
    printf ("Guess the number (1 to 10): ");
    scanf ("%d",&iGuess);
    if (iSecret<iGuess) puts ("The secret number is lower");
    else if (iSecret>iGuess) puts ("The secret number is higher");
  } while (iSecret!=iGuess);

  puts ("Congratulations!");
  return 0;
    return 0;
}
