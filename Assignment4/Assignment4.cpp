#include <iostream>
using namespace std;


/* part 1
Receiving two inputs from main.
Determine if the lengths of those inputs are equal, if they are, enter the while loop.
Increment through the length of the string, determining if the characters in each string do not equal each other.
If this is true, increase count the mismatch.
Return a float, similarity score (length - mismatch) / length.
*/
float similarityScore(string sequence1, string sequence2)
{
    int i = 0;
    float mismatch1 = 0;
    float length = sequence1.length();

    if(sequence1.length() == sequence2.length())
    {
        while(i < length)
        {
            if(sequence1[i] != sequence2[i])
            {
                mismatch1++;
            }
            i++;
        }
            float similarity_score = (length - mismatch1) / length;
            return similarity_score;
    }
    else
        return 0;
}


/* part 2
Receive three inputs from the main function.
Initialize i = 0, while its less and the length of the genome, the while loop will execute.
Create a new variable which is equal to the function similarity score with the given parameters.
Use the function .substr to make the genome length the same length of sequence1, otherwise the similarityScore function will never enter the while loop
The similarity score function outputs a percentage, which is then compared the the third parameter, min score.
If the similarityScore percentage is greater or equal to the min_score increase the count.
Return count.
*/

int countMatches(string genome, string sequence1, float min_score)
{
    int i = 0;
    int count = 0;


    while(i <= genome.length() - sequence1.length()) // seq1 is subtracted so i does not count pass the genome length
    {
    float results = similarityScore(sequence1, genome.substr(i, sequence1.length()));

        if(results >= min_score)
        {
            count++;
        }
    i++;
    }
    return count;
}

/*part 3
Receive two inputs.
Initialize three variables to be compared later on.
While loop always initialize because i is always less than the genome length.
Make a variable equal to a the similarityScore function call, the function's parameters set the genome length equal to the sequence length, so the while loop in the similarityScore executes.
Create an inequality, comparing the current simulation score to the best score.
If the current sim_score is better than the best score, make the current sim_score the best score.
Increment i through genome length.
Return the best score.
*/

float findBestMatch(string genome, string seq)
{
    int i = 0;
    float best_score = 0;
    float sim_score = 0;

    while(i < genome.length())
    {
    sim_score = similarityScore(seq, genome.substr(i, seq.length()));

        if(sim_score > best_score)
        {
            best_score = sim_score;
        }
    i++;
    }
    return best_score;
}

/*part 4
Create three variables that hold the value for the scores.
These three variables call the findBestMatch function, using the matching parameters.
After the scores are determined, a series of if statements are used to see which score is the highest.
*/

int findBestGenome(string genome1, string genome2, string genome3, string seq)
{
    float score1 = 0;
    float score2 = 0;
    float score3 = 0;

    score1 = findBestMatch(genome1, seq);
    score2 = findBestMatch(genome2, seq);
    score3 = findBestMatch(genome3, seq);

    if((score1 > score2) && (score1 > score3))
    {
        return 1;
    }
    else if ((score2 > score1) && (score2 > score3))
    {
        return 2;
    }
    else if ((score3 > score1) && (score3 > score2))
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
