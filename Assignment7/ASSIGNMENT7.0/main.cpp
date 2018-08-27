#include <iostream>
#include <fstream>
#include "SpellChecker.h"
#include "WordCounts.h"
using namespace std;

int main()
{
//     SpellChecker object("english");
//     object.readCorrectedWords("MISSPELLED.txt");
//     object.readValidWords("VALID_WORDS_3000.txt");
//     cout << object.language << endl;
//     cout << object.validWords[100] << endl;
//     cout << object.misspelledWords[100] << endl;
//     cout << object.correctedWords[100] << endl;
//     cout << object.lowerNopunct("!@Tho*ma$$s# Payne@@ !dog!! cat!") << endl;
// /*
//     string dog[4];
//     object.Split("dog dog dog dog", dog);
//     for(int i = 0; i < 4; i++)
//     {
//         cout << dog[i] << " ";
//     }
// */
//     object.setStartMarker('~');
//     object.setEndMarker('~');
//     cout << object.repair("!acommadate! amature fdaszda") << endl;


//    // cout << object.getEndMarker() << endl;
//    // cout << object.getStartMarker() << endl;



    WordCounts object1;
      // object1.tallyWords("hi hi hi hi hi hi");
      object1.tallyWords("hi");
      object1.tallyWords("yes");
      object1.tallyWords("bye");

      object1.tallyWords("hello hello hello ");
    //object1.tallyWords("bye bye");
   //object1.tallyWords("Hello hello my name Is PAYNE");
      //object1.tallyWords("Hello hello my name Is ");
      //object1.tallyWords("Hello hello hi my");
    for(int i = 0; i < object1.arraySize; i++)
    {
        cout << object1.actualWords[i] << ": ";
        cout << object1.trackWords[i] << endl;
    }


     //   cout << object1.getTally("hello") << endl;

   /* object1.resetTally();
    for(int j = 0; j < object1.arraySize; j++)
    {
        cout << object1.trackWords[j];
        //cout << '.' << " ";
    }
    */
    string maxWords[20];
    int maxCount[20];
    int n = 5;
    object1.mostTimes(maxWords, maxCount, n);

    return 0;

}
